#include<stdio.h>
int main() {
    int c;
    int counterone = 0;
    int counterzero = 0;
    printf("Enter an integer\n");
    scanf("%d",&c);
    while(c != 0)
    {
        if ((c & 1) == 1)
        {
            counterone += 1;
        }
        else counterzero += 1;
        c = c >> 1;
    }
    printf("Number of 1 bits: %d\n", counterone);
    printf("Number of 0 bits: %d\n", counterzero);
}