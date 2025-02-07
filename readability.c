#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_characters(string text);
int count_letters(string text);
int count_sentences(string text, int characters);
int count_words(string text, int characters);

int main(void)
{
    // get input text from user
    string text = get_string("Text: ");

    // count the number of words, sentences and letters in the text
    int characters = count_characters(text);
    int letters = count_letters(text);
    int words = count_words(text, characters);
    int sentences = count_sentences(text, characters);

    // calculate average number of letters per 100 words
    float avg_letters = (((float) letters / (float) words) * 100);

    // calculate average numer of sentences per 100 words
    float avg_sentences = (((float) sentences / (float) words) * 100);

    // calculate reading age using Coleman-Liau index: 0.0588 * L - 0.296 * S - 15.8
    int reading_age = round(((0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8));

    // output reading age
    if ((1 < reading_age) && (reading_age < 16))
    {
        printf("Grade %d\n", reading_age);
    }

    else if (reading_age < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade 16+\n");
    }
}

// count functions
int count_characters(string text)
{
    int n = 0;
    while (text[n] != '\0')
    {
        n++;
    }
    return n;
}

int count_letters(string text)
{
    int n = 0;
    int l = 0;
    while (text[n] != '\0')
    {
        if (isalpha(text[n]))
        {
            n++;
            l++;
        }
        else
        {
            n++;
        }
    }
    return l;
}

int count_words(string text, int characters)
{
    int n = 0;
    int w = 0;
    while (n <= (characters))
    {
        if ((isblank(text[n]) || (text[n] == '\0')) && (!isblank(text[n - 1])))
        {
            n++;
            w++;
        }
        else
        {
            n++;
        }
    }
    return w;
}

int count_sentences(string text, int characters)
{
    int n = 0;
    int s = 0;
    while (n <= (characters + 1))
    {
        if ((isblank(text[n]) || (text[n] == '\0')) &&
            ((text[n - 1] == '.') || (text[n - 1] == '?') || (text[n - 1] == '!')))
        {
            n++;
            s++;
        }
        else
        {
            n++;
        }
    }
    return s;
}
