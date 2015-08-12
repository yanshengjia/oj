//SEUOJ

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    long long int sum=0;
    string str;
    int sigh=1;
    int a[6];
    for(int n=0;n<6; n++)
        a[n]=0;
    int flag=0;
    
    while(getline(cin,str))
    {
        int length = str.size();
        for(int i=0; i<length-1; i++)
        {
            if(str[i]==' ')
            {
                int temp=0;
                for(int j=0; j<flag; j++)
                    temp+=(a[j] * pow(10,(double)flag-j-1));
                sum+=sigh*temp;
                sigh=1;
                flag=0;
            }
            else if(str[i]=='-') sigh=-1;
            else
            {
                a[flag]=str[i]-48;
                flag++;
            }
        }
    
        a[flag]=str[length-1]-48;
        flag++;
        int y=0;
        for(int j=0; j<flag; j++)
        y+=(a[j] * pow(10,(double)flag-j-1));
        sum+=sigh*y;
        sigh=1;
        flag=0;
        
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
