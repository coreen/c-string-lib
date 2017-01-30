/*
Reads text until EOF is read, counting the words.
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // value variable holds the user entered character in numerical form
    int value = 0;
    // number variable keeps track of the number of words entered
    int number = 0;

    // reading information from the user through stdin
    // loop until read the EOF character, counting the number of words
    // entered by the user
    printf ("Enter a sequence of words (EOF to exit): ");
    value = getchar();
    while (value != EOF)
    {
        if (isspace(value))
        {
            number++;
        }
        value = getchar();
    }

    // printing information to the user through stdout
    // print the total number of words that the user has entered
    printf("Your entered %i words.", number);

    return 0;
}
