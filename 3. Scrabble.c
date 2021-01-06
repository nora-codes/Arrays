#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Calculate and print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Get length of word
    int length = strlen(word);
    // Check code: printf("Length of word %s: %i\n", word, length);

    // Set counter for score
    int word_score = 0;

    for (int x = 0; x < length; x++)
    {
        // Get letter of word
        int letter = word[x];
        // Check code: printf("letter %c | ASCII %i | ", letter, letter);

        // Declare conversion function
        int conversion;

        // Check letter is alphabetical
        if (isalpha(letter))
        {
            // Get points for lower case letters
            if (islower(letter))
            {
                // Convert ASCII to POINTS array position
                conversion = (letter - 97);
                // Check code: printf("array position %i | ", conversion);
            }

            // Get points for upper case letters
            if (isupper(letter))
            {
                // Convert ASCII to POINTS array position
                conversion = (letter - 65);
                // Check code: printf("array position %i | ", conversion);
            }

            // Log points for letter
            int letter_score = POINTS[conversion];
            // Check code: printf("%i points | ", letter_score);

            // Add letter score to total word score
            word_score = word_score + letter_score;
            // Check code: printf("word score count = %i\n", word_score);
        }
        // else
        // Check code: printf("Not a character: 0 points\n");
    }
    // Return total word score
    // Check code: printf("\nTotal word score: %i\n\n", word_score);
    return word_score;
}
