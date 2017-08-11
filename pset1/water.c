#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("How long was your shower? (in minutes):\n");
    int showertime = GetInt();
    printf("You've showered for %i minutes\n", showertime);
    int bottles = showertime * 12;
    printf("You've used up %i bottles of water!\n", bottles);
}