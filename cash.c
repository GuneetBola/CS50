#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
     float dollar;
     int cents;
     int coins = 0;

     do
// the do while loop here asks the user for the amount of change owed. It proceeds to change the value into cents and rounds it.
     {
          float dollar = get_float("Change owed: \n$");
          cents = round(dollar * 100);
     }
     while (cents <= 0);

// the next loop checks to see if the "cents" value is greater than 25 (a quarter) so that it can add one more coin into the count
     while (cents >= 25)
     {
          cents = (cents - 25);
          coins++;
     }

// the next loop checks to see if the "cents" value is greater than 10 (a dime) so that it can add one more coin into the count
     while (cents >= 10)
     {
          cents = (cents - 10);
          coins++;
     }

// the next loop checks to see if the "cents" value is greater than 5 (a nickel) so that it can add one more coin into the count
     while (cents >= 5)
     {
          cents = (cents - 5);
          coins++;
     }

// the next loop checks to see if the "cents" value is greater than 1 (a penny) so that it can add one more coin into the count
     while (cents >= 1)
     {
          cents = (cents - 1);
          coins++;
     }

     printf("%i \n", coins);
}