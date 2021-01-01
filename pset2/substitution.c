#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool isunique(string text);
bool ischars(string text);
void decoding(string plaintext, string key);

int main(int args, string argv[])
{   
    // If the program is executed without any command-line arguments
    // or with more than one command-line argument
    if (!argv[1] || argv[2])
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // the key is invalid (as by not containing 26 characters, 
    // containing any character that is not an alphabetic character, 
    // or not containing each letter exactly once)
    else if (strlen(argv[1]) != 26 || (ischars(argv[1]) == false))
    {
        
        printf("Key must contain 26 alphabetic characters.\n");
        return 1;
    }
    else if (isunique(argv[1]) == false)
    {
        printf("Key must contain 26 unique characters.\n");
        return 1;
    }
    // if everything is right
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        decoding(plaintext, argv[1]);
        printf("\n");
        return 0;
    }
    
}

void decoding(string plaintext, string key)
{   
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    long n = strlen(plaintext);
    // do not forger about the case
    for (int i = 0; i < n; i++) 
    {
        if (isalpha(plaintext[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (plaintext[i] == tolower(alpha[j]))
                {
                    printf("%c", tolower(key[j]));
                }
                else if (plaintext[i] == toupper(alpha[j]))
                {
                    printf("%c", toupper(key[j]));
                }
            }   
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}

// if the character is unique
bool isunique(string text)
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 1 + i; j < 26; j++)
        {
            if (toupper(text[i]) == toupper(text[j]))
            {
                return false;
            }
        }
    }
    return true;
}

// if the character is an alphabetic one
bool ischars(string text)
{   
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(text[i]) == false)
        {
            return false;
        }
    }
    return true;
}