#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //variables needed at the start of the program
    int word = 1 ;    
    int letter = 0;
    int sentence = 0;
    //ask for input 
    string input = get_string("Input: ");
    
    int length = strlen(input);
    //the for loop is used to repeatedly check each character (char)
    for (int i = 0; i < length; i++)
    {
        char c = input[i];
        char c1 = input [i + 1];
        //checking for spaces to check for the number of words
        if (isspace(c))
        {
            word++;
        }
        //checking for number of letters
        if (isalpha(c))
        {
            letter++;
        }
        //checking for punctuation to indicate number of sentences
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence++;
        }
    }
    //calculate the variables L and S using the information found above^
    float L = ((float)letter / word) * 100;
    float S = ((float)sentence / word) * 100;
 
    //final calculation for grade level using the Coleman-Liau index
    float grade = (0.0588 * L) - (0.296 * S) - 15.8;
    
    if (grade >= 1 && grade <= 16) //printing for if grade level is between 1-16
    {
        printf("Grade %.f\n", grade);
    }
    else if (grade < 1) //printing for if grade level is below grade 1
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n"); //printing for if grade level is more than 16
    }

}

