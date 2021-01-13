from cs50 import get_string

L = 0
S = 0
sentences = 0
words = 1
letters = 0
grade = 0
index = 0
phrase = get_string("Text: ")

for i in range(len(phrase)):

    focus = phrase[i]

    if phrase[i] == "." or phrase[i] == "!" or phrase[i] == "?":
        sentences = sentences + 1

    if focus.isalpha() == True:
        letters = letters + 1

    if focus.isspace():
        words = words + 1


L = (letters / words) * 100

S = (sentences / words) * 100

index = (0.0588 * L) - (0.296 * S) - 15.8

grade = round(index)

if grade < 1:
    print ("Before Grade 1")

elif grade >= 1 and grade < 16:
    print(f"Grade {grade}")

elif grade >= 16:
    print("Grade 16+")
