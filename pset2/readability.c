#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void grade(string text);
float letters_per_100_words();
float sentences_per_100_words();
long counting_letters(string text);
long counting_words(string text);
long counting_sentences(string text);

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        string text = get_string("Text: ");
        grade(text);
    }
}

// define the grade
void grade(string text)
{   
    long letters = counting_letters(text);
    long words = counting_words(text);
    long sentences = counting_sentences(text);
    float L = letters_per_100_words(letters, words);
    float S = sentences_per_100_words(sentences, words);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {   
        printf("Grade %.0f \n", round(index));
    }
}

//count the average number of letters per 100 words in the text
float letters_per_100_words(long letters, long words) 
{
    return ((float) letters * 100) / (float) words;
}

// count the average number of sentences per 100 words in the text
float sentences_per_100_words(long sentences, long words)
{
    return ((float)sentences * 100) / (float) words;
}

// count letters and return the number of them
long counting_letters(string text)
{
    long letters = 0;
    for (long i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    printf("%li letter(s)\n", letters);
    return letters;
}

// count words and return the number of them
// count spaces (and add one more in the end)
long counting_words(string text)
{
    long words = 0;
    for (long i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            words ++;
        }
    }
    words ++;
    printf("%li word(s)\n", words);
    return words;
}

// count sentences  and return the number of them
// count "!", "?" and "."
long counting_sentences(string text)
{
    long sentences = 0;
    for (long i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences ++;
        }
    }
    printf("%li sentence(s)\n", sentences);
    return sentences;
}



