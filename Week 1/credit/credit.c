#include <cs50.h>
#include <stdio.h>
#include <math.h>

int last_digit(long num);
long trim(long num, int amount);
int len(long num);
int get_digit(long num, int digit);

string get_card_type(long card);
bool is_valid(long card);
int add_digits(int num);

int main(void)
{
    // Get the user's card
    long card;
    int card_len;
    do
    {
        card = get_long("What is your credit card number? ");
        card_len = len(card);
    }
    while (card == 0);


    // Check if it is a valid card
    bool valid = is_valid(card);

    // If it isn't, print INVALID and return
    if (!valid)
    {
        printf("INVALID\n");
        return 0;
    }

    // If it is valid, print the type of card
    printf("%s\n", get_card_type(card));
}

// Get the last digit of the number
int last_digit(long num)
{
    return num % 10;
}

// Get the number without the last <amount> digits
long trim(long num, int amount)
{
    return num / (pow(10, amount));
}

// Get a specific digit in a number
int get_digit(long num, int digit)
{
    return last_digit(trim(num, len(num) - digit));
}

// Get the length of a number
int len(long num)
{
    int l = 0;
    while (num != 0)
    {
        l++;
        num = num / 10;
    }

    return l;
}

// Get the type of card
string get_card_type(long card)
{
    // First number
    long fn = trim(card, len(card) - 1);

    if (fn == 4)
    {
        return "VISA";
    }
    else
    {
        // First 2 numbers
        long sn = trim(card, len(card) - 2);

        if (sn == 34 || sn == 37)
        {
            return "AMEX";
        }
        else if (sn >= 51 && sn <= 55)
        {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
}

// Use Luhn's Algorithm to determine if the card is valid or not
bool is_valid(long card)
{
    int card_len = len(card);

    if (card_len < 13 || card_len > 16)
    {
        return false;
    }


    int other_total = 0;
    for (int i = len(card) - 1; i > 0; i -= 2)
    {
        int digit = get_digit(card, i);
        other_total += add_digits(digit * 2);
    }

    for (int i = len(card); i > 0; i -= 2)
    {
        other_total += get_digit(card, i);
    }

    if (last_digit(other_total) == 0)
    {
        return true;
    }

    return false;
}

// Add all digits in a number
int add_digits(int num)
{
    int sum = 0;
    for (int i = 0; i <= len(num); i++)
    {
        sum += get_digit(num, i);
    }

    return sum;
}