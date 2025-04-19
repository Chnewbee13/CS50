from cs50 import get_string


def main():

    # get input text from user
    text = get_string("Text: ")

    # count the number of words, sentences and letters in the text
    characters = len(text)
    letters = count_letters(text, characters)
    words = count_words(text, characters)
    sentences = count_sentences(text, characters)

    # calculate average number of letters per 100 words
    avg_letters = (letters/words) * 100

    # calculate average numer of sentences per 100 words
    avg_sentences = (sentences/words) * 100

    # calculate reading age using Coleman-Liau index: 0.0588 * L - 0.296 * S - 15.8
    reading_age = round(((0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8))

    # output reading age
    if (1 < reading_age < 16):
        print("Grade:", reading_age)

    elif reading_age < 1:
        print("Before Grade 1")

    else:
        print("Grade 16+")

# count_letters function


def count_letters(text, characters):

    letters = 0

    for x in range(characters):
        if text[x].isalpha():
            letters += 1

    return letters


# count_words function
def count_words(text, characters):

    words = 0

    for x in range(characters):
        if text[x].isspace() and not (text[x - 1].isspace()):
            words += 1

    if text[characters - 1].isspace():
        return words

    else:
        return (words + 1)


# count_sentences function
def count_sentences(text, characters):

    sentences = 0

    for x in range(characters):
        if text[x].isspace() and ((text[x - 1] == ".") or (text[x - 1] == "?") or (text[x - 1] == "!")):
            sentences += 1

    if text[characters - 1].isspace():
        return sentences

    else:
        return (sentences + 1)


main()
