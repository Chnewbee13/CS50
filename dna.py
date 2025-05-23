import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) < 3:
        print("Usage: python dna.py DNAdatabase.csv DNAsequence.txt")
        sys.exit[1]

    # Read database file into a variable

    DNA_database = []

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            DNA_database.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        DNA_sequence = file.read()

    # get STRs (fieldnames) from DNA_database and save into a new list
    list_of_STRs = list(reader.fieldnames)[1:]

    # Search DNA_sequence for each STR subsequence from DNA_database, and save output into a new dict
    STR_count = {}
    for STR_subsequence in list_of_STRs:
        STR_count[STR_subsequence] = longest_match(DNA_sequence, STR_subsequence)

    # Compare output of STR_count to values for each person in DNA_database
    for person in DNA_database:
        matches = 0
        for STR_subsequence in list_of_STRs:
            if STR_count[STR_subsequence] == int(person[STR_subsequence]):
                matches += 1

        if matches == len(list_of_STRs):
            sys.exit(person["name"])

    sys.exit("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
