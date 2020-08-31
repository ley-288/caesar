#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_valid_key(string s);         //assign new function here, so computer knows what its looking for, in this case a number check, string.

int main(int argc, string argv[])       //or char? //tells the computer we will have to store arrays. arrays can store both ints and strings.
{
    if (argc != 2 || !check_valid_key(argv[1]))      //need to create a function here. if the argc 'input command count' is NOT 2 digits OR contains a number..
    {                                               //which we ask computer to check is a valid string with argv 1, meaning the second 'user input'.
        printf("Usage: ./caesar key\n");             //then print this
        return 1;                                    //and return
    }
    int key = atoi(argv[1]);        //use atoi to convert a number string into an actual number. So this is askin computer to take the argv 1 which should be the key no.
                                    //..and count the number, so that it can be used by the program to count the other strings. the plaintext.
    string plaintext = get_string("plaintext: ");       //prompt for text.

    printf("ciphertext: ");                             //so now we print the cryptic text, and set the parameters to do so.
    for (int i = 0, len = strlen(plaintext); i < len; i++) //create integer for index, start at 0, use strlen to count letters in text in (p)..
    {                           //this gives index. if index less than len of word, move to next individual letter until no letters remain. Ie, count letter one by one.
        char c = plaintext[i];              //assign character as individual letter [index] of plaintext input
        if (isalpha(c))                     //run a loop through isalpha tosetect upper or lower case.
        {
            char m = 'A';                    //if modified character 'm' is Uppercase, stay uppercase.
            if (islower(c))                 //however if... run a loop through islower to detect lowercase characters
               m = 'a';                      //modified letter is lowercase
            printf("%c", (c - m + key) % 26 + m);           //print this character, with formula..
        }                                       //(character minus the modified character + the key number) divide remainder of 26, + modified character.
        else                                    //using A as example if A = 1 //(1-1+1) % 0+1 = 1. so we add 1 to A, A becomes 2. 2 is B. A becomes B! voila.
            printf("%c", c);                    //or else print as is.
    }
    printf("\n");                               //print what strlen detects.
}

bool check_valid_key(string s)                      //our boolean for the number check.
{
    for (int i = 0, len = strlen(s); i < len; i++) //index starts 0, lenth = strlen count; i less than length. i+i. (basically, count 1 by 1.)
        if (!isdigit(s[i]))                         //if string[index 'digit'] is NOT a digit..
            return false;    //..false
    return true;                                    //or else true. if it, then true.
}

//isalpha //detect letters from numbers
//strlen
//ASCII ci = (pi + k) % 26 //formula //breakdown values. convert from ASCII to alphabetical index.

//convert back

//(printf("c%\n", Character, c+[x])  //print encrypted message.
