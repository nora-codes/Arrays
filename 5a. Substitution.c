#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_alphabetic(string alpha);
int check_repeat(string repeat);
string encipher(string text, string code);

// ---------------------------------------------------------------------------------------------------------------------------

// 1. Get the key

int main(int argc, string argv[])
{

// 2. Validate the key
//    If key is invalid - print error message
//    Then return from main a value of 1
//    Print "Usage: ./substitution key"

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

// 2a. Check key length
//     If key is invalid
//     Print "Key must contain 26 characters."

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 alphabetic characters.\n");
        return 1;
    }

// 2b. Check for non-alphabetic characters
//     Use check_aplhabetic function
//     If key is invalid
//     Print "Key must only contain alphabetic characters."

    else if (check_alphabetic(argv[1]) != 26)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

// 2c. Check for repeated characters (case-insensitive)
//     Use check_repeat function
//     If key is invalid
//     Print "Key must not contain repeated characters."

    else if (check_repeat(argv[1]) > 26)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

// 3. Get plaintext
//    Print "plaintext: "

    string plaintext = get_string("plaintext: ");

// 4. Encipher
//    Use encipher function

    string output = encipher(plaintext, argv[1]);

// 5. Print ciphertext
//    Print "ciphertext: "

    printf("ciphertext: %s\n", output);

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------

// Function to check for all alphabetic characters

int check_alphabetic(string alpha)
{
    int alpha_counter = 0;

    for (int x = 0; x < 26; x++)
    {
        if (isalpha(alpha[x]))
        {
            alpha_counter = alpha_counter + 1;
        }
    }

    return alpha_counter;
}

// ---------------------------------------------------------------------------------------------------------------------------

// Function to check for repeated characters

int check_repeat(string repeat)
{
    int repeat_counter = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (repeat[i] == repeat[j] || repeat[i] == (repeat[j] - 32) || repeat[i] == (repeat[j] + 32))
            {
                repeat_counter = repeat_counter + 1;
            }
        }
    }
    return repeat_counter;
}

// ---------------------------------------------------------------------------------------------------------------------------

// Function to calculate cipher

// 4a. Determine what each character maps to
// 4b. Preserve case
// 4c. Leave non-alphabetic characters as-is

string encipher(string text, string code)
{
    int plaintext_length = strlen(text);
    string ciphertext = text;

    for (int x = 0; x < plaintext_length; x++)
    {
        if (isalpha(text[x]))
        {
            if (islower(text[x]))
            {
                int y = text[x] - 97;
                ciphertext[x] = code[y];

                if (isupper(ciphertext[x]))
                {
                    ciphertext[x] = ciphertext[x] + 32;
                }
            }

            else if (isupper(text[x]))
            {
                int y = text[x] - 65;
                ciphertext[x] = code[y];

                if (islower(ciphertext[x]))
                {
                    ciphertext[x] = ciphertext[x] - 32;
                }
            }
        }

        else
        {
            ciphertext[x] = text[x];
        }
    }

    return ciphertext;
}
