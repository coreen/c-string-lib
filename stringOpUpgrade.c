/*
Program upgrades the string handling capabilities by developing some of
the string manipulation tools available in other programming languages,
such as BASIC. Designing a new portion of the C string library.
*/

#include<stdio.h>
#include<string.h>

// initializes the functions
void stringInit(char*);
void stringInitValue(char*, char);
char atPut(char*, int, char);
char atGet(char*, int, char);
void atRemove(char*, int);
char* subString(char*, char*);
int length(char*);
void show(char*);

int main(void)
{
    // testing all the string functions created

    // temp variable to test initialization functions
    char temp[30];

    stringInit(temp);
    stringInitValue(temp, 'a');

    // test variable to test rest of functions
    char test[] = "test";

    printf("Overwrote %c in position 0 of \"test\"\n\n", atPut(test, 0, 'b'));
    printf("Got the specified value: %c\n\n", atGet(test, 2, 'a'));
    atRemove(test, 1);

    // additional variables to test substring function
    char subY[] = "st";
    char subNo[] = "hello";

    printf("The substring \"st\" is returned for valid substring: %s\n",
           subString(test, subY));
    printf("The null pointer is returned for substring not found: %s\n\n",
           subString(test, subNo));
    printf("The length of \"hello\" should be 5, function returns: %i\n\n",
           length(subNo));
    show(subY);

    return 0;
}

// initialize the string to a default value
void stringInit(char* strPtr) {
    // initializes the pointer to NULL, good value to guarantee
    // to point to nothing
    strPtr = NULL;
    printf("after initialization = %s\n\n", strPtr);
}

// initialize the string to the value aCharString
void stringInitValue(char* strPtr, char aCharString) {
    // adds the specified character to the string
    *strPtr = aCharString;
    // end the string by adding the null terminator
    *(strPtr + 1) = '\0';
    printf("after initialize value = %s\n\n", strPtr);
}

// put aValue at string index anIndex, uses overwrite semantics
char atPut(char* strPtr, int anIndex, char aValue) {
    // counter keeps track of the characters read so far
    int counter = 0;
    // temp holds the value overwrote by the function
    char temp = NULL;
    // run through all the characters in the string
    while(*(strPtr + counter) != '\0') {
        // overwrites the specified index with the specfied value
        if(counter == anIndex) {
            temp = *(strPtr + anIndex);
            *(strPtr + anIndex) = aValue;
        }
        counter++;
    }
    // end the string by adding the null terminator
    *(strPtr + counter) = '\0';
    printf("after put specified value at index, have: %s\n", strPtr);
    return temp;
}

// return the character at string index anIndex
char atGet(char* strPtr, int anIndex, char aValue) {
    // don't really know why aValue needs to be passed in...
    return *(strPtr + anIndex);
}

// remove the character at string index anIndex, the string
// length reduces by one
void atRemove(char* strPtr, int anIndex) {
    // counter keeps track of the characters read so far
    int counter = 0;
    // run through all the characters in the string until
    // the specified character to remove
    while(counter != anIndex) {
        counter++;
    }
    // temp keeps track of the characters read after the
    // character to be removed
    int temp = counter;
    // skip over the character to be removed
    counter++;
    // continue to the end of the string
    while(*(strPtr + counter) != '\0') {
        *(strPtr + temp) = *(strPtr + counter);
        temp++;
        counter++;
    }
    // reduce the string length by one
    counter--;
    // end the string by adding the null terminator
    *(strPtr + counter) = '\0';
    printf("after removed specified value at index %i, have: %s\n\n", anIndex, strPtr);
}

// return a pointer to the first occurrence of the string pointed
// to by aSubstringPtr or NULL if the substring is not found
char* subString(char* strPtr, char* aSubstringPtr) {
    // equivalent to string method: strstr(strPtr, aSubstringPtr);

    // return the strPtr if the substring is null
    if (*aSubstringPtr == '\0') {
        return strPtr;
    }
    // counter keeps track of the characters read so far
    char *counter = strPtr;
    // run through the string, looking for the substring
    while (*counter != '\0') {
        // create a pointer to the start of a potential substring
        char *current = counter;
        // create a temp variable to run through the substring
        char *temp = aSubstringPtr;
        // keep running through the string as long as the characters are the same
        // and you have not reached the end of either one
        while (*counter != '\0' && *temp != '\0' && *counter == *temp) {
            counter++;
            temp++;
        }
        // the substring exists if the substring is null after the above operation
        if (*temp == '\0') {
            return current;
        }
        counter = current + 1;
    }
    return NULL;
}

// return the length of the string
int length (char* strPtr) {
    // equivalent to string method: strlen(strPtr);

    // counter keeps track of the characters read so far
    int counter = 0;
    // run through all the characters in the string
    while(*(strPtr + counter) != '\0') {
        counter++;
    }
    return counter;
}

// display the string
void show(char* strPtr) {
    // prints the string to stdout
    printf("your string is: %s\n", strPtr);
}
