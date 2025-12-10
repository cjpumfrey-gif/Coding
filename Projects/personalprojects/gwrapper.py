import subprocess

urls = {
    'docs': "https://docs.google.com/document/u/0/",
    'sheets': "https://sheets.google.com/spreadsheets/u/0/",
    'drive': "https://drive.google.com/drive/u/0/",
    'calendar': "https://calendar.google.com/calendar/u/0/r",
    'mail': "https://mail.google.com/mail/u/0/"
}

choice = input("Enter which Google app to open (docs, sheets, drive, calendar, mail): ").strip().lower()
if choice in urls:
    subprocess.Popen(['start', 'chrome', '--app=' + urls[choice]], shell=True)
else:
    print("Invalid choice.")
