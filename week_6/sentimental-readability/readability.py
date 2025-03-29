from cs50 import get_string
import re

def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Compute the Coleman-Liau index
    idx = round(0.0588 * (letters / words * 100) -
                0.296 * (sentences / words * 100) - 15.8, 0)

    if idx >= 1 and idx <= 16:
        print(f"Grade {int(idx)}")
    elif idx > 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")

def count_letters(text):
    sum = 0

    for i in range(0, len(text)):
        if text[i].isalpha():
            sum += 1
    return sum

def count_words(text):
    sum = 0

    for i in range(0, len(text)):
        if text[i] == " ":
            sum += 1
    return sum + 1

def count_sentences(text):
    sum = 0

    for i in range(0, len(text)):
        if text[i] in ["!", ".", "?"]:
            sum += 1
    return sum

if __name__ == "__main__":
    main()
