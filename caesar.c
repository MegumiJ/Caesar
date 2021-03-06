/*********************************
 * caesar.c
 * 
 * Megumi Jinushi
 * megumij@hawaii.edu
 * 
 * Encipher the texts user inputs
 * Useage: ./caesar key_integer
 *********************************/
# include <string.h>
# include <stdio.h> 
# include <stdlib.h> 
# include <cs50.h>
# include <ctype.h>

// Take the key and plain text
int main(int argc, string argv[]) 
{
    // validate command-line input
    // Check if the # of artuments are 2
    if (argc != 2)
    {
        printf("Try again. Did you type in the key?\n");
        return 1;
    }
    
    // Check if argv[1] == key is a positive integer
    string num = argv[1];
    int key = atoi(num);

    if (key <= 0)
    {
        printf("Please type in a positive integer.\n");
        return 1;
    }
    
    // Standardize the distance for shift if greater than 26
    else if (key > 26)
    {
        key = key % 26;
    }
    
    // Get plain text
    string text = GetString();
   
    // Encipher
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        int letter = text[i]; 
        int cipher = letter + key;
        
        if (islower(letter)) //in the case of lower letters
        {
            if (cipher <= 'z') // if ciphered letter doesn't exceed 'z' print that
            {
                printf("%c", cipher);
            }
            
            else // if ciphered letter exceeds 'z' go back to 'a,' then add the rest of the distance that needs to be shifted
            {                            
                cipher = (cipher % 'z') + ('a' - 1); 
                printf("%c", cipher);
            }
        }
        
        else if (isupper(letter)) // in the case of upper letters
        {
            if (cipher <= 'Z')
            {
                printf("%c", cipher);
            }
            
            else
            {          
                cipher = ((letter + key) % 'Z') + ('A' - 1);
                printf("%c", cipher);
            }
        }
        
        else // in the case of spaces or the symbols other than alphabetic letters, print as it is.
        {
            printf("%c", letter);
        }
    }
    
    printf("\n");
    
 }
 
