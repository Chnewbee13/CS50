from cs50 import get_int


def main():
    c = get_int("Card number: ")

    # checksum
    sum = checksum(c)
    if (sum % 10) != 0:
        print("INVALID")

    else:
        # convert to string
        str_c = str(c)

        # check if VISA
        if (len(str_c) == 16 or len(str_c) == 13) and str_c[0] == "4":
            print("VISA")

        # check if AMEX
        elif len(str_c) == 15 and (str_c[:2] == "34" or str_c[:2] == "37"):
            print("AMEX")

        # check if MASTERCARD
        elif len(str_c) == 16 and (str_c[:2] == "51" or str_c[:2] == "52" or str_c[:2] == "53" or str_c[:2] == "54" or str_c[:2] == "55"):
            print("MASTERCARD")

        # else return invalid
        else:
            print("INVALID")


def checksum(n):
    x = n
    sum = 0
    while x > 0:
        digit1 = int(x) % 10
        x = int(x / 10)
        sum = sum + digit1

        digit2 = int(x) % 10
        x = int(x / 10)
        digit2 = digit2 * 2
        digit2a = digit2 % 10
        digit2b = int(digit2 / 10)
        sum = sum + digit2a + digit2b

    return sum


main()
