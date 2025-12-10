import subprocess
import tkinter as tk

# URLs for Google Workspace apps
urls = {
    'Docs': "https://docs.google.com/document/u/0/",
    'Sheets': "https://sheets.google.com/spreadsheets/u/0/",
    'Drive': "https://drive.google.com/drive/u/0/",
    'Calendar': "https://calendar.google.com/calendar/u/0/r",
    'Mail': "https://mail.google.com/mail/u/0/"
}

def open_app(url):
    # Launch as a Chrome app window (change to 'msedge' or 'vivaldi' if desired)
    subprocess.Popen(['start', 'vivaldi', '--app=' + url], shell=True)

root = tk.Tk()
root.title("Google Workspace Launcher")

# Create a button for each app
for name, url in urls.items():
    btn = tk.Button(root, text=name, width=20, command=lambda url=url: open_app(url))
    btn.pack(pady=5)

root.mainloop()

