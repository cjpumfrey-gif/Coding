#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // prompt user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Cents owed: ");
    }
    while (cents < 0);

    int coin_count = 0;
    // calculate how many quarters customer shoud get if any
    int quarters = cents / 25;
    coin_count += quarters;
    cents = cents % 25;

    // calculate how many dimes you should give customer
    // subtract value from cents
    int dimes = cents / 10;
    coin_count += dimes;
    cents = cents % 10;

    // calculate nickels to customer
    // subtract
    int nickels = cents / 5;
    coin_count += nickels;
    cents = cents % 5;

    // calculate how many pennnies
    // subtract
    int pennies = cents;
    coin_count += pennies;

    printf("%d\n", coin_count);
}
