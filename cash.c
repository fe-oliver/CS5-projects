#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents, quarters, dimes, nickels, pennies, coins;
    cents = get_cents();

    quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}



















int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 25;
    do
    {
        cents = cents / quarters;
    }
    while (cents < 0);
    return cents;
}

int calculate_dimes(int cents)
{
    int dimes = 10;
    do
    {
        cents = cents / dimes;
    }
    while (cents < 0);
    return cents;
}

int calculate_nickels(int cents)
{
    int nickels = 5;
    do
    {
        cents = cents / nickels;
    }
    while (cents < 0);
    return cents;
}

int calculate_pennies(int cents)
{
    int pennies = 1;
    do
    {
        cents = cents / pennies;
    }
    while (cents < 0);
    return cents;
}
