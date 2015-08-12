//codejam

#include <stdio.h>

int main()
{
    //输入输出重定向
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    //读取案例数
    int T;
    scanf("%d",&T);
    
    int D;
    int min=0;
    
    for(int i=0; i<T; i++)  //T次循环
    {
        scanf("%d",&D);
        int *d= new int[D];
        for(int j=0; j<D; j++)
            scanf("%d",&d[j]);
        
        if(D=1)
        {
            if(d[0]==1)     min=1;
            else if(d[0]%2==0)      min=d[0]/2+1;   //d[0]偶
            else if(d[0]%2==1)      min=(d[0]+1)/2+1;   //d[0]奇
        }
        
        
        
        
        
        
        printf("Case #%d: %d\n", i+1, min);
        minute=0;
    }
    
    return 0;
}