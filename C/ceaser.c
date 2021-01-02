#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc == 2) 
        //checks if there is a command line argument 
    {
        int digit = 0;
        //variable is being used to check if the command line argument is an integer
        for (int i = 0; i < strlen(argv[1]); i++) 
        {
            if (!isdigit(argv[1][i])) 
            {
                digit = 1;
                //if one of the characters in the command line argument are not digits, the variable is set to 1
                //if all of the characters are digits, then the the variable "digit" will stay 0
            }
        }
        
        if (digit == 0)
            //if the variable "digit" remains zero, all the characters are digits
        {
            int key = atoi(argv[1]);
            if (key >= 1)
                //checking if all digits are positive
            {
                printf("Sucess\n %s\n", argv[1]);
                string plaintext = get_string("plaintext: ");
                //asks the user for the plaintext
                printf("ciphertext: ");
                //starts to print out the ciphertext
            
                for (int n = 0; n < strlen(plaintext); n++)
                {
                    if (plaintext[n] >= 'a' && plaintext[n] <= 'z')
                    {
                        printf("%c", (((plaintext[n] - 'a') + key) % 26) + 'a');
                        //for all lowercase letters
                    }
                    else if (plaintext[n] >= 'A' && plaintext[n] <= 'Z')
                    {
                        printf("%c", (((plaintext[n] - 'A') + key) % 26) + 'A');
                        //for all uppercase letters
                    }
                    else
                    {
                        printf("%c", plaintext[n]);
                        //for all non alphebetical characters, they will remain the same
                    }
                }
                printf("\n");
                return 0;
                //exits the program once this is done
            }
            else if (key < 1)
            {
                printf("./cesar key\n");
                return 1;
                //prints the error message if negaitve number is inputted
            } 
        }
        else 
        {
            printf("./caesar key\n");
            return 1;
            //prints the error message if the command line arguement was not fully integeral
            
        }
    }
    else 
    {
        printf("./cesar key\n");
        return 1;
        //prints the error message if more than one command line argument is inputted or if no command line argument was inputted
    }
    
}
