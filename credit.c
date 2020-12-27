#include <stdio.h>
#include <cs50.h>

void type_num(long num);


int main(void)
{
    long num = get_long("Number: ");
    type_num(num);
}

// function, that implements Luhn's algorithm
bool luhns_algorithm(long num)
{   
    int sum_no_m = 0;
    int sum_m = 0;
    int interim;
    while (num != 0)
    {
        sum_no_m += num % 10;
        // products’ digits
        interim = ((num % 100) / 10) * 2;
        for (int i = 0; i < 2; i++)
        {   
            // adding those products’ digits
            sum_m += interim % 10;
            interim /= 10;
        }
        // remove numbers, that have already been added
        num /= 100;
    }
    sum_m += sum_no_m;
    return true;
}


// check for card's type and validate 
void type_num(long num)
{
    int index;
    if (luhns_algorithm(num)) 
    {
        if (num / 10000000000000 == 0 || num / 10000000000000000 == 0)
        {
            index = num / 100000000000000;
            // MASTERCARD
            if (index >= 51 & index <= 55)
            {
                printf("MASTERCARD\n");   
            }
            // VISA
            else if (index >= 40 & index <= 49)
            {   
                printf("VISA\n");
            }
            else if (index == 0)
            {
                index = num / 1000000000000;
                if (index == 4)
                {   
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                index = num / 10000000000000;
                if (index == 34 || index == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}