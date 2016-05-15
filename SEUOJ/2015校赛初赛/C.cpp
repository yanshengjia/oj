// SEUOJ
// Too young

#include <stdio.h>

int main()
{
    int n;
    int q;
    int l,r;
    int min;
    
    while((scanf("%d",&n))!=0)
    {
        int *age = new int[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d", &age[i]);
        }
        
        scanf("%d", &q);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d", &l, &r);
            l--;
            r--;
            min=age[r];
            for(int j=l; j<r; j++)
                if(age[j]<min)  min=age[j];
            printf("%d\n", min);
        }
    }
    return 0;
}