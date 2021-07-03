#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Prototype declaration of all the functions used 
int count_sentences(string text);
int count_words(string text);
int count_letters(string text);

int main(void)
{
    // Prompt the user for some text of his own
    string text = get_string("Text: ");
    
    // Count the number of sentences in the string
    int sentences = count_sentences(text);
    
    // Count the number of words in the string
    int words = count_words(text) + 1;
    
    // Count the number of letters in the string
    int letters = count_letters(text);
    
    // // Count the average number of letters and sentences per 100 words in the string
    float L = 100 * ((float)letters / words);
    float S = 100 * ((float)sentences / words);
    
    // Calculate the index of the text by using Coleman-Liau index algorithm 
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // Print the index numbr i.e grade of the text as 
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
    // Exit status of the function
    return 0;
}


int count_sentences(string text)
{
    int sentences = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    
    return sentences;
}

int count_words(string text)
{
    int word = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    
    return word;
}

int count_letters(string text)
{
    int letters = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    
    return letters;
}
