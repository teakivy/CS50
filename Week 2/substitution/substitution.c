#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

char KEY_LIST[26];

bool is_key(string key);
bool key_contains(char ch);
char substitute(char ch);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_key(argv[1]))
    {
        printf("Usage: ./caeser <key>\n");
        return 1;
    }

    // Get input
    string pt = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Print the rotated key
    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        printf("%c", substitute(pt[i]));
    }

    // Formatting
    printf("\n");
}

// Check if a string is a valid substitution key
bool is_key(string key)
{
    // If not 26 chars, not a key
    int key_len = strlen(key);
    if (key_len != 26)
    {
        return false;
    }

    for (int i = 0; i < key_len; i++)
    {
        char ch = toupper(key[i]);
        if (!isalpha(ch) || key_contains(ch))
        {
            return false;
        }

        KEY_LIST[i] = ch;
    }

    return true;
}

// Check if the key list contains a char already
bool key_contains(char ch)
{
    for (int i = 0; i < 26; i++)
    {
        if (KEY_LIST[i] == ch)
        {
            return true;
        }
    }

    return false;
}

// Get the substitute for a char via KEY_LIST
char substitute(char ch)
{
    if (!isalpha(ch))
    {
        return ch;
    }
    bool is_upper = isupper(ch);

    int pos = (int) ch;

    // Reset position to 0 for a, 1 for b, etc
    if (is_upper)
    {
        pos -= 65;
    }
    else
    {
        pos -= 97;
    }

    // Replace with the correct char
    ch = KEY_LIST[pos];

    // If it was lowercase, make it lowercase
    if (!is_upper)
    {
        ch = tolower(ch);
    }

    return ch;
}