#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // declaring variables
    long n;
    long t;
    int checksum;
    int count = 0;

    // getting credit card number input
    n = get_long("Number: ");

    // calculating number's lenght && checksum
    t = n;
    while (t > 0)
    {
        count++;

        // checking if this is an other number
        if (count == 2 || count == 4 || count == 6 || count == 8 || count == 10 || count == 12 || count == 14 || count == 16)
        {

            // checking if other number mutiplied by 2 equals a double digit number
            if ((t % 10) * 2 > 9)
            {
                checksum = checksum + ((((t % 10) * 2) / 10) + (((t % 10) * 2) % 10));
            }
            else
            {
                checksum = checksum + ((t % 10) * 2);
            }
        }

        // if it's not a other number, then:
        else
        {
            checksum = checksum + (t % 10);
        }
        t = t / 10;
    }

    //validating checksum
    if (checksum % 10 > 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // checking if it's an AMEX card
        if (count == 15)
        {
            if (n / 10000000000000 == 34 || n / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                n = n / 10000000000000;
                printf("%ld", n);
                printf("INVALID\n");
            }
        }

        // checking if it's a MASTERCARD || VISA card
        if (count == 16)
        {
            if (n / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                if (n / 100000000000000 == 51 || n / 100000000000000 == 52 || n / 100000000000000 == 53 || n / 100000000000000 == 54
                    || n / 100000000000000 == 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }


        }

        // checking if it's a VISA card
        if (count == 13)
        {
            if (n / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        if (count < 13 || count > 16 || count == 14)
        {
            printf("INVALID\n");
        }
    }
}