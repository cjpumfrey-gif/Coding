import csv
import sys


def main():
    # Check for correct number of command-line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a list of dictionaries
    database = []
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    # Extract STRs from the database header
    str_names = reader.fieldnames[1:]  # skip "name"

    # Read DNA sequence file into a string
    with open(sys.argv[2], "r") as file:
        dna_sequence = file.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for STR in str_names:
        str_counts[STR] = longest_match(dna_sequence, STR)

    # Check database for matching profile
    for person in database:
        match = True
        for STR in str_names:
            if int(person[STR]) != str_counts[STR]:
                match = False
                break
        if match:
            print(person["name"])
            return

    # If no match found
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of the longest run of subsequence in sequence."""

    longest_run = 0
    subseq_length = len(subsequence)
    seq_length = len(sequence)

    # Check each position in sequence for most consecutive runs of subsequence
    for i in range(seq_length):
        count = 0

        # Check for a subsequence match in a "window" of sequence
        while True:
            start = i + count * subseq_length
            end = start + subseq_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    return longest_run



if __name__ == "__main__":
    main()
