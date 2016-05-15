// SEUOJ 
// a+b

#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    
    int m,n;
    int answer=0;
    int start=0, end=0;
    int flag1=0, flag2=-1;
    for(int i=0; i<T; i++)
    {
        scanf("%d\n%d", &m , &n );
        double *p = new double[n];
        end=n-1;
        
        for(int j=0; j<n; j++)
        {
            scanf("%lf", &p[j]);
        }
        
        while(start<=n-1&&end>=0)
        {
            if(p[start]+p[end] == m && end>=0 && start<=n-1)
            {
                answer++;
                start++;
                continue;
            }
            
            if(p[start]+p[end] < m && start<=n-1)
            {
                start++;
                continue;
            }
            
            if(p[start]+p[end] > m && end>=0)
            {
                end--;
                if(p[start]+p[end] >= m && end>=0 && start<=n-1)
                {
                    for(int j=1; j<=start; j++)
                    {
                    if(p[start-j]+p[end] == m)
                        answer++;
                    else break;
                    }
                }
                continue;
            }
        }
        
        printf("%d\n", answer);
        answer=0;
        start=0;
        end=0;
        delete p;
    }
    return 0;
}
