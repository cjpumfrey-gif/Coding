-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the crime report for the theft on Humphrey Street on July 28, 2024
SELECT *
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2024
  AND street = 'Humphrey Street';


-- Get interviews conducted on the same day that mention the theft
SELECT *
FROM interviews
WHERE month = 7 AND day = 28 AND year = 2024
  AND transcript LIKE '%thief%';


-- Cars leaving the bakery parking lot within 10 minutes of the theft
SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10
  AND minute BETWEEN 15 AND 25;


SELECT *
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10
      AND minute BETWEEN 15 AND 25
);


-- ATM withdrawals from Leggett Street ATM on the morning of July 28
SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
  AND month = 7 AND day = 28
  AND transaction_type = 'withdraw';


SELECT people.name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.atm_location = 'Leggett Street'
  AND atm_transactions.month = 7 AND atm_transactions.day = 28
  AND atm_transactions.transaction_type = 'withdraw';


-- Find the earliest flight on July 29, 2024
SELECT flights.id, flights.hour, flights.minute, airports.city AS destination_city
FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE flights.origin_airport_id = (
    SELECT id FROM airports WHERE city = 'Fiftyville'
)
AND flights.month = 7 AND flights.day = 29
ORDER BY flights.hour, flights.minute
LIMIT 1;


-- Find all passengers on the earliest flight out
SELECT people.name, people.passport_number
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = [flight_id_from_above];


-- Find calls made by the thief on July 28
SELECT *
FROM phone_calls
WHERE month = 7 AND day = 28
  AND caller = (SELECT phone_number FROM people WHERE name = '[thief_name]')
  AND duration < 60;


SELECT name
FROM people
WHERE phone_number = '[receiver_number]';
