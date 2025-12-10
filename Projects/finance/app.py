import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd



# Configure application
app = Flask(__name__)

# after importing usd from helpers.py
app.jinja_env.filters["usd"] = usd

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure session to use filesystem
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

    rows = db.execute(
        "SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol",
        user_id
    )

    portfolio = []
    total_value = cash

    for row in rows:
        if row["shares"] <= 0:
            continue
        stock = lookup(row["symbol"])
        price = float(stock["price"])
        total = price * row["shares"]
        total_value += total
        portfolio.append({
            "symbol": row["symbol"],
            "name": stock["name"],
            "shares": row["shares"],
            "price": usd(price),
            "total": usd(total)
        })

    return render_template("index.html", portfolio=portfolio, cash=usd(cash), total=usd(total_value))

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username or not password or not confirmation:
            return apology("must provide username and password", 400)
        if password != confirmation:
            return apology("passwords do not match", 400)
        if db.execute("SELECT * FROM users WHERE username = ?", username):
            return apology("username already exists", 400)

        hash_pw = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_pw)

        user_id = db.execute("SELECT id FROM users WHERE username = ?", username)[0]["id"]
        session["user_id"] = user_id
        return redirect("/")
    else:
        return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    session.clear()
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        if not username or not password:
            return apology("must provide username and password", 400)

        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology("invalid username or password", 400)

        session["user_id"] = rows[0]["id"]
        return redirect("/")
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""
    session.clear()
    return redirect("/")

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)

        # Ensure price is float
        stock["price"] = float(stock["price"])
        return render_template("quoted.html", stock=stock)
    else:
        return render_template("quote.html")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return apology("must provide symbol", 400)
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)

        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except:
            return apology("shares must be a positive integer", 400)

        user_id = session["user_id"]
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        price = float(stock["price"])
        cost = price * shares
        if cost > cash:
            return apology("can't afford", 400)

        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", cost, user_id)
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, type) VALUES (?, ?, ?, ?, 'buy')",
            user_id, symbol, shares, price
        )

        return redirect("/")
    else:
        return render_template("buy.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]
    rows = db.execute("SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    symbols = [row["symbol"] for row in rows if row["shares"] > 0]

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return apology("must provide symbol", 400)
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)

        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except:
            return apology("shares must be a positive integer", 400)

        owned = db.execute(
            "SELECT SUM(shares) as shares FROM transactions WHERE user_id = ? AND symbol = ?",
            user_id, symbol
        )[0]["shares"]

        if shares > owned:
            return apology("too many shares", 400)

        price = float(stock["price"])
        revenue = price * shares
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", revenue, user_id)
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price, type) VALUES (?, ?, ?, ?, 'sell')",
            user_id, symbol, -shares, price
        )

        return redirect("/")
    else:
        return render_template("sell.html", symbols=symbols)

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    rows = db.execute("SELECT * FROM transactions WHERE user_id = ? ORDER BY id DESC", user_id)

    for row in rows:
        row["price"] = usd(float(row["price"]))

    return render_template("history.html", transactions=rows)
