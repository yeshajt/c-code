import cs50
import sys


def main():
    # Ensure that arguments exist and are of the right type
    while True:
        if (len(sys.argv) != 2):
            print("Usage: python caesar.py key")
            sys.exit(1)
        else:
            plaintext = cs50.get_string("Plaintext: ")
            key = int(sys.argv[1])
            break

    # Sends each letter to the converter function
    ciphertext = ""
    for i in plaintext:
        if i.isalpha():
            value = ciphertext_converter(i, key)
            ciphertext += value
        else:
            ciphertext += i
    print("ciphertext: " + ciphertext)


# Converter function first checks case then converts
def ciphertext_converter(character, key):
    if character.isupper():
        return chr(((ord(character) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(character) - 97 + key) % 26) + 97)


if __name__ == "__main__":
    main()