#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: \n");

    //get letters

    float letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)

        if (isalpha(text[i]))
        {
            letters++;
        }

    //get spaces

    float spaces = 0;

    for (int j = 0, n = strlen(text); j < n; j++)

        if (isspace(text[j]))
        {
            spaces++;
        }

    //get words

    float words = spaces + 1;

    //get sentences

    float sentences = 0;

    for (int k = 0, n = strlen(text); k < n; k++)

        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            sentences++;
        }

    //Coleman-Liau index

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);

    //Print grade

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.f\n", index);
    }
)
