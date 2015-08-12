//Diamond
//SEUOJ

#include <stdio.h>

int main()
{
    int r;
    scanf("%d", &r);
    
    for(int i=0; i<r; i++)
    {
        for(int m=0; m<r-i-1; m++)
        {
            printf(" ");
        }
        
        for(int n=0; n<2*i+1; n++)
        {
            printf("*");
        }
        
        for(int m=0; m<r-i-1; m++)
        {
            printf(" ");
        }

        printf("\n");
    }
    
    for(int i=0; i<r-1; i++)
    {
        for(int m=0; m<=i; m++)
        {
            printf(" ");
        }
        
        for(int n=0; n<2*(r-i-2)+1; n++)
        {
            printf("*");
        }
        
        for(int m=0; m<=i; m++)
        {
            printf(" ");
        }
        
        printf("\n");
    }
    return 0;
}