from cs50 import get_float
from math import floor


def main():
    # Ask user for the amount of change owed
    while True:
        change = get_float("Enter the change owed: ")
        if (change > 0):
            break
    # Turn the dollar value into cents
    cents = floor(change * 100)

    # Calculate the number of each coinage value
    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = (((cents % 25) % 10) % 5)

    print("You can pay your change in " + str(quarters + dimes + nickels + pennies) + " coins")


if __name__ == "__main__":
    main()

