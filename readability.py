from cs50 import get_string

string = get_string("Text: ")
alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
letters = 0
words = 0
sentences = 0
other = 0

for i in string:
    if i == " " or i == None or i == 0 or i == "\n":
        words += 1
    elif i == "." or i == "?" or i == "!":
        sentences += 1
    elif i in alphabet:
        letters += 1
words += 1
l = letters / (words / 100)
s = sentences / (words / 100)
index = round((0.0588 * l) - (0.296 * s) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
