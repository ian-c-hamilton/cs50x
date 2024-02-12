from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break
    row = 1
    hashes = 1
    spaces = height - row
    while hashes <= height:
        print_spaces(spaces)
        print_hashes(hashes)
        print("  ", end="")
        print_hashes(hashes)
        print()
        row += 1
        hashes += 1
        spaces -= 1


def print_spaces(n):
    for i in range(n):
        print(" ", end="")


def print_hashes(n):
    for i in range(n):
        print("#", end="")


main()
