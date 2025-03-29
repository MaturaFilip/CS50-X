from cs50 import get_string
import re

def main():
    card = get_string("Number: ")
    identify_card(card)


def check_sum(card_number):
    sum = 0
    for i in range(len(card_number)-2, -1, -2):
        x = int(card_number[i]) * 2
        if x > 9:
            sum += (x % 10 + 1)
        else:
            sum += x
    for i in range(len(card_number)-1, -1, -2):
        sum += int(card_number[i])

    return sum


def is_valid(number):
    return number % 10 == 0


def identify_card(card_num):
    sum = check_sum(card_num)
    valid = is_valid(sum)

    if valid:
        if re.search(r"^(37|34)[0-9]{13}$", card_num):
            print("AMEX")
        elif  re.search(r"^4(\d{15}|\d{12})$", card_num):
            print("VISA")
        elif re.search(r"^5[12345]\d{14}", card_num):
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
