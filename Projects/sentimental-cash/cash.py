
# Calculate the minimum number of coins needed for change

while True:
    try:
        change = float(input("Change owed: "))
        if change >= 0:
            break
    except ValueError:
        pass

# Convert dollars to cents and round to avoid floating-point imprecision
cents = round(change * 100)

# Initialize coin counter
coins = 0

coins += cents // 25
cents %= 25

coins += cents // 10
cents %= 10

coins += cents // 5
cents %= 5


coins += cents


print(coins)
