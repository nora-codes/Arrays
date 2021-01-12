#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check user input for encryption

    if (argc == 2)
    {
        //convert user input to integer:
        int x = atoi(argv[1]);

        //check for integers

        for (int i = 0; i < argc - 1; i++)
        {
            for (int j = 0, n = strlen(argv[1]); j < n; j++)
            {
                if isdigit(argv[1][j])
                {

                    //get plaintext from user

                    string s = get_string("plaintext: ");
                    printf("ciphertext: ");

                    //convert plaintest with encryption

                    for (int k = 0, m = strlen(s); k < m; k++)
                    {
                        if isalpha(s[k])
                        {
                            //for lower case
                            if islower(s[k])
                            {
                                //convert to new number system
                                char c = (s[k] - 97 + x);

                                //if number sits outside alphabet range
                                if (c > 25)
                                {
                                    char d = ((c % 26) + 97);
                                    printf("%c", d);
                                }

                                //if number sits within alphabet range
                                else
                                {
                                    printf("%c", s[k] + x);
                                }
                            }

                            //for upper case
                            if isupper(s[k])
                            {
                                //convert to new number system
                                char c = (s[k] - 65 + x);

                                //if number sits outside alphabet range
                                if (c > 25)
                                {
                                    char d = ((c % 26) + 65);
                                    printf("%c", d);
                                }

                                //if number sits within alphabet range
                                else
                                {
                                    printf("%c", s[k] + x);
                                }
                            }
                        }

                        // print any non-alpha characters
                        else
                        {
                            printf("%c", s[k]);
                        }
                    }

                    //print new line
                    printf("\n");
                    return 0;
                }

                //if encryption input is not a number
                //return error
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    //if command line argument has more or less than 2 inputs
    //print error

    printf("Usage: ./caesar key\n");
    return 1;
}
