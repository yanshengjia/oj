//SEUOJ
//Which day?

#include <stdio.h>

bool leapyear(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0) return true;
            else  return false;
        }
        else return true;
    }
    else return false;
}

int main()
{
    int year, month, day;
    int commonYear[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leapYear[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    
    while(scanf("%d %d %d", &year, &month, &day)!=EOF)
    {
        if(month>12 || month<1 || day>31 || day<1)
        {
            printf("Illegal\n");
            continue;
        }
        
        if(!leapyear(year)) //common year
        {
            if(day > commonYear[month-1])
            {
                printf("Illegal\n");
                continue;
            }
            
            int temp=month;
            for(int i=0; i<month-1; i++)
            {
                sum+=commonYear[i];
            }
            
            sum+=day;
            printf("%d\n", sum);
            sum=0;
            
        }
        
        if(leapyear(year))  //leap year
        {
            if(day > leapYear[month-1])
            {
                printf("Illegal\n");
                continue;
            }
            
            int temp=month;
            for(int i=0; i<month-1; i++)
            {
                sum+=leapYear[i];
            }
            
            sum+=day;
            printf("%d\n", sum);
            sum=0;
        }
    }
    
    return 0;
}