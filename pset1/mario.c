#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int columnh;
    printf("Input the column height(not greater than 23): ");

    do
    {
        columnh = get_int();
        if (columnh > 23 || columnh < 0)
        {
            printf("Try again!: ");
        }
    }
    while (columnh > 23 || columnh < 0);

    int i;
    int j;
    int k;

    for (i = 0; i < columnh; i++)
    {
        for (k = 0; k < (columnh-i) - 1; k++)
        {
        printf(" ");
        }

        for (j = 0; j < i + 2; j++)
        {
        printf("#");
        }
    printf("\n");
    }
}