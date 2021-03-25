#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt","r");
 
    char s[100];
    while( fscanf(fp, "%s", s) != EOF )
    {
        printf("\n%s", s);
    }
    fclose(fp);
}