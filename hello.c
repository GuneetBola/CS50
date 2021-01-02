#include <stdio.h>
#include <cs50.h>
//This program should execute hello world and then prompt the user for their name and be able to repond with hello attached with the user's name.
int main(void)
{
    printf("hello world\n");
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}