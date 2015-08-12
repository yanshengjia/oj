//SEUOJ  #59

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x[10000], y[10000], z[10000];
    double a,b,c;
    int N, Q;
    double min, max;
    
    cin>>N>>Q;
    for(int i=1; i<=N; i++)
        cin>>x[i]>>y[i]>>z[i];
    
    for(int j=1; j<=Q; j++)
    {
        cin>>a>>b>>c;
        min=fabs(a-x[1])+fabs(b-y[1])+fabs(c-z[1]);
        max=min;
        
        for(int p=2; p<=N; p++)
        {
            double temp;
            temp=fabs(a-x[p])+fabs(b-y[p])+fabs(c-z[p]);
            if(temp<min)    min=temp;
            if(temp>max)    max=temp;
        }

        cout<<min<<" "<<max<<endl;
    }
    
    return 0;
}