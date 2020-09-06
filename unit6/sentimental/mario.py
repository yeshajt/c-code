from cs50 import get_int


def main():
    # Asks for the height
    while True:
        height = get_int("height ")
        if height >= 0 and height <= 23:
            break

    # Sets variable names for the spaces and hashes
    spaces = " "
    hashes = "#"

    # Prints out number of spaces and number of hashes based on the line
    for i in range(1, height + 1):
        number_hashes = i
        number_spaces = height - number_hashes

        print(spaces * number_spaces, end="")
        print(hashes * number_hashes, end="")
        print("  ", end="")
        print(hashes * number_hashes)


if __name__ == "__main__":
    main()

