/*
Program recreates the concatenate, append, and replace
string functions in the C standard string library.
*/

#include<stdio.h>
#include<string.h>

// initializes the functions
char* concatenate(char[], char[], char*);
char* append(char[], char[]);
char* repl(char[], char[]);

int main(void)
{
    // character arrays to keep track of user-entered strings
    char str0[30];
    char str1[30];
    // create the pointer to the resulting string for concatenate
    char result[60];
    char* blank = result;

    // reading information from the user through stdin
    // asks the user for 2 strings to concatenate using the
    // specified concatenate function
    printf("please enter 2 strings to concatenate separated by a newline\n");
    printf("(keep string lengths under 30 characters):\n");
    gets(str0);
    gets(str1);

    // printing information to the user through stdout
    // print the original user entered strings
    printf("your strings are: \"%s\" AND \"%s\"\n", str0, str1);
    // print the user entered strings back after concatenate method
    printf("your strings concatenated is: %s\n", concatenate(str0, str1, blank));
    // print the user entered strings back after append method
    printf("your strings after append are: S1 = %s AND S2 = %s\n", append(str0, str1), str1);
    // print the user entered strings back after repl method
    printf("your strings after replace are: S1 = %s AND S2 = %s\n", repl(str0, str1), str1);

    return 0;
}

// concatenates the given strings and returns the result via
// the pointer to the empty string
char* concatenate(char str0[], char str1[], char* blank) {
    // counter keeps track of the characters read so far
    int counter = 0;
    // add all of the characters from the first string
    while(*str0 != '\0') {
        *(blank + counter) = *str0;
        counter++;
        str0++;
    }
    // add all of the characters from the second string
    while(*str1 != '\0') {
        *(blank + counter) = *str1;
        counter++;
        str1++;
    }
    // end the string by adding the null terminator
    *(blank + counter) = '\0';
    return blank;
}

// appends the second string to the first and returns the result
// via the pointer to the first string
char* append(char str0[], char str1[]) {
    // counter keeps track of the characters read so far
    int counter = 0;
    // increment the counter for the first string length (keep unchanged)
    while(*(str0 + counter) != '\0') {
        counter++;
    }
    // temp keeps track of the characters read of the second string
    int temp = 0;
    // add all of the characters from the second string to the first
    while(*(str1 + temp) != '\0') {
        *(str0 + counter) = *(str1 + temp);
        counter++;
        temp++;
    }
    // end the string by adding the null terminator
    *(str0 + counter) = '\0';
    return str0;
}

// replaces the first string with the second string
char* repl(char str0[], char str1[]) {
    // counter keeps track of the characters read so far
    int counter = 0;
    // replace all characters from the second string to the first
    while(*(str1 + counter) != '\0') {
        *(str0 + counter) = *(str1 + counter);
        counter++;
    }
    // end the string by adding the null terminator
    *(str0 + counter) = '\0';
    return str0;
}
