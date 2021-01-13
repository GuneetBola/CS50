## needs to have four command line arguements

import sys
from csv import reader, DictReader

inputs=sys.argv

# Check if the user entered three inputs, if not outputs an error.
if len(inputs) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# Opens the database file (filled with names and corresponding DNAs) and reads through it.
with open(inputs[1]) as database:
    people = reader(database)
    for row in people:
        sequencesList = row
        sequencesList = sequencesList[1:]
        break

#now, to use in the rest of the code, this list will be converted into a dictionary so that the DNA sequences are the
#  keys and the correspoding values are the longest repeitions of the sequence.

sequencesDict = {} #starting with an empty dictionary

# adding all the dna sequences gotten from the database to the dictionary.
for dna in sequencesList:
    sequencesDict[dna] = 1


#Open the dna text file and add it to a variable called dnas
with open(inputs[2]) as txtfile:
    dnas = reader(txtfile)
    for row in dnas:
        rowList = row

dnaList = rowList[0]


for item in sequencesDict.keys():
    counter = 0
    index = 0
    listofValues = []
    maximum = 0
    for index in range(len(dnaList)):
        while counter > 0:
            counter = counter - 1
            continue

        if item == dnaList[index: (index + len(item))]:
            while dnaList[index: (index + len(item))] == dnaList[(index - len(item)): index]:
                counter = counter + 1
                index = index + len(item)

            if maximum<counter:
                maximum=counter

    # finds the maximum value in the list of values collected and adds that into the dictionary. Checks if it is empty first.
    sequencesDict[item] += maximum


#Now that we have gotten the max for each sequence in the txt file with the DNA sequence, we will check for matches


with open(inputs[1]) as data:
    peopledatabase = DictReader(data)
    for row in peopledatabase:
        numofMatches = 0
        numofDNA = len(sequencesDict.keys())

        for oneDNA in sequencesDict:
            num = int(row[oneDNA])
            if sequencesDict[oneDNA] == num:
                numofMatches = numofMatches + 1

        if numofMatches == numofDNA:
            print (row['name'])
            exit()

    print ("No Match")








