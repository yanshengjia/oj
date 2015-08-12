//codejam

#include <stdio.h>

int main()
{
    //输入输出重定向
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T;  //案例数
    scanf("%d",&T);
    
    int x=0, y=0;
    int N;
    
    for(int i=0; i<T; i++)  //T次循环处理 T 个案例
    {
        scanf("%d", &N);
        int *a = new int[N];
        
        for(int m=0; m<N; m++)
        {
            scanf("%d",&a[m]);
        }
        
        //A
        for(int m=0; m<N-1; m++)
        {
            if(a[m]>a[m+1])
                x+=(a[m]-a[m+1]);
        }
        
        //B
        for(int m=0; m<N-2; m++)
        {
            y+=a[m];
        }
        
        y+=(a[N-2]-a[N-1]);
        
        printf("Case #%d: %d %d\n", i+1, x, y);
        x=0;
        y=0;
    }
    
    return 0;
}
