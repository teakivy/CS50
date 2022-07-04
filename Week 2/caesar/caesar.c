#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char ch, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caeser <key>\n");
        return 1;
    }

    // Convert the string argv[1] to an int
    int key = atoi(argv[1]);

    // Get input
    string pt = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Print the rotated key
    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        printf("%c", rotate(pt[i], key));
    }

    // Formatting
    printf("\n");
}

// Check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If the char isnt a digit, return false
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

// Rotate a char by key amount
char rotate(char ch, int key)
{
    // If it is not alphanumeric, return itself
    if (!isalpha(ch))
    {
        return ch;
    }

    bool is_upper = isupper(ch);

    int pos = (int) ch;

    // Set the pos to 0 for a, 1 for b, etc
    if (is_upper)
    {
        pos -= 65;
    }
    else
    {
        pos -= 97;
    }

    // Add the key and rotate
    pos = (pos + key) % 26;

    // Set the value back to its reference point
    if (is_upper)
    {
        pos += 65;
    }
    else
    {
        pos += 97;
    }

    // Return the character
    return (char) pos;
}