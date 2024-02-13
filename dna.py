import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: dna.py dataSet.csv sequence.txt")
    # TODO: Read database file into a variable
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        # print(reader.fieldnames)
        for row in reader:
            rows.append(row)
        # print(rows)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as sequence:
        dna = sequence.readline()
        # print(dna)
    # TODO: Find longest match of each STR in DNA sequence
    longestSTR = {}
    for column in reader.fieldnames:
        if column != 'name':
            longestSTR[column] = str(longest_match(dna, column))
    # print(longestSTR)
    # TODO: Check database for matching profiles
    match = False
    for person in rows:
        person['matchCount'] = 0
        for key in longestSTR.keys():
            if longestSTR[key] == person[key]:
                person['matchCount'] += 1
    for person in rows:
        if person['matchCount'] == len(longestSTR):
            culprit = person['name']
            match = True

    if match == True:
        print(culprit)
    else:
        print("No Match")

    return


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
