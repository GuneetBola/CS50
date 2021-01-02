#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int rows;
    
    do
    {
        rows = get_int("Height: \n");
    }
    while (1 > rows || rows > 8);
    
    for (int i = 1; i <= rows; i++) 
        // this for loop will loop for the number of rows 
    {
        for (int dots = rows - (1 + i); dots >= 0; dots--)
            // this for loop is to add spaces, so that the pyramid is right-aligned
        {
            printf(" ");
        }
        for (int n = 1; n <= i; n++)
            // this for loop will loop for the number of hastags needed in each row
        {
            printf("#");
        }
        
        printf("\n");
    }
}