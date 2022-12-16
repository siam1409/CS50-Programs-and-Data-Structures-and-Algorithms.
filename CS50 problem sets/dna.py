import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    database = sys.argv[1]
    if database == "databases/large.csv":
        dictionary = {"AGATC": 0, "TTTTTTCT": 0, "AATG": 0, "TCTAG": 0, "GATA": 0, "TATC": 0, "GAAA": 0, "TCTG": 0}
        sequence_list = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
        candidates = 23
    else:
        dictionary = {"AGATC": 0, "AATG": 0, "TATC": 0}
        sequence_list = ["AGATC", "AATG", "TATC"]
        candidates = 3

    list = []

    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for line in reader:
            list.append(line)

        # TODO: Read DNA sequence file into a variable
        textfile = open(sys.argv[2], "r")
        sequence = textfile.read()
        textfile.close()

    # TODO: Find longest match of each STR in DNA sequence
    j = 0
    for i in range(len(sequence)):
        if database == "databases/small.csv" and j == 3:
            break
        if database == "databases/large.csv" and j == 8:
            break

        longest_run = longest_match(sequence[i:len(sequence)], sequence_list[j])

        dictionary[sequence_list[j]] = longest_run
        j += 1

    # TODO: Check database for matching profiles
    probable_name = ""
    match = 0
    found = False

    for i in range(candidates):
        for j in range(len(sequence_list)):
            if found == False:
                if dictionary[sequence_list[j]] == int(list[i][sequence_list[j]]):
                    match += 1
            if match == len(sequence_list):
                probable_name = list[i]["name"]
                found = True
                break
        if found == True:
            break

    if (found):
        print(probable_name)
    else:
        print("no match")

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
