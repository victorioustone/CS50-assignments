#include <stdio.h>
// #include <cs50.h>

int main(void)
{   
    int n;
    // cheching the number (it has to be 1<=x<=8)
    do 
    {
        printf("Height: ");
        scanf("%d", &n);
        // or
        // n = get_int("");
    }
    while (n < 1 || n > 8);
    // divided the pyramid into two parts. 
    // counter1 if for the step
    int counter1 = n - 1;
    // counter2 is for the length of pyramid
    int counter2 = n * 2 + 2;
    // each level
    for (int i = 0; i < n; i++)
    {
        // each block
        for (int j = 0; j < counter2; j++)
        {
            // left side
            if (j == counter1 || (j <= n - 1 && j > counter1))
            {
                printf("#");
            }
            // right side
            else if (j == counter2 - counter1 - 1 || (j >= counter2 - n && j < counter2 - counter1 - 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        // for adding one more block for each sides
        counter1--;
        printf("\n");
    }
}
