from cs50 import get_string


def main():

    number = get_string("Number: ")
    length = len(number)
    if length != 13 or length != 15 or length != 16:
        print("INVALID")

    valid = False
    mults = []
    nonmults = []
    sum_mults = 0
    sum_nonmults = 0
    tot = 0
    for i in range(-1, -(length+1), -2):
        nonmults.append(number[i])

    for i in range(-2, -(length+1), -2):
        mults.append(number[i])

    for i in mults:
        num = 2 * int(i)
        if num > 9:
            sum_mults = sum_mults + int(str(num)[0]) + int(str(num)[1])
        else:
            sum_mults += num

    for i in nonmults:
        sum_nonmults += int(i)

    tot = sum_mults + sum_nonmults

    if tot % 10 == 0:
        valid = True
    first = number[0]
    second = number[1]
    if valid and length == 15 and first == '3' and (second == '4' or second == '7'):
        print("AMEX")

    elif valid and length == 16 and first == '5' and (second == '1' or second == '2' or second == '3' or second == '4' or second == '5'):
        print("MASTERCARD")

    elif valid and first == '4' and (length == 13 or length == 16):
        print("VISA")
    else:
        print("INVALID")


main()
