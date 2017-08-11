#include <stdio.h>
#include <cs50.h>
#include <math.h>



int main(void) {
    
    int const quarter = 25;
    int const dime = 10;
    int const nickel = 5;
    int const penny = 1;
    
    
    float cash;
    int cents;
    int coins = 0;
    
    printf("So how much do You owe ?");
    
    do {
    cash = GetDouble();
    if (cash < 0) {
        printf("Try again: ");
        }
    }
    while (cash < 0);
    
    cents = round(cash * 100);


    if (cents >= quarter) {
        
        coins += cents/quarter;
        cents = cents % quarter;
    }
    
    if (cents >= dime) {
        
        coins += cents/dime;
        cents = cents % dime;
    }
    
    if (cents >= nickel) {
        
        coins += cents/nickel;
        cents = cents % nickel;
    }
    
    if (cents >= penny) {
        
        coins += cents/penny;
        cents = cents % penny;
    }
    
    printf("%i\n",coins);
}
