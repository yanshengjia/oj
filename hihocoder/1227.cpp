//ACM-ICPC国际大学生程序设计竞赛北京赛区(2015)网络赛
//题目1：The Cats' Feeding Spots
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    double t1=x1-x2;
    double t2=y1-y2;
    double juli = sqrt(pow(t1, 2)+ pow(t2,2));
    return juli;
}


int main()
{
    int T;
    scanf("%d",&T);
    
    int M, N;
    double x[105], y[105];
    
    double answer;
    int flag;
    int flag2=1;
    
    //T cases
    for(int i=0; i<T; i++)
    {
        //cout<<"Case:"<<i<<endl;
        scanf("%d %d", &M, &N);
        
        //input
        for(int j=0; j<M; j++)
        {
            scanf("%lf %lf", &x[j], &y[j]);
        }
        
        answer=1000000;
        flag=-1;
        
        //M core point
        for(int k=0; k<M; k++)
        {
            
            double X=x[k];
            double Y=y[k];
            //cout<<"Core point:"<<X<<" "<<Y<<endl;
            
            for(double d=1.0; d<2850.0; d+=1.0)
            {
                flag2=1;
                //cout<<"d:"<<d<<endl;
                int t=0;
                for(int p=0; p<M; p++)
                {
                    if(distance(X,Y,x[p],y[p])==d)
                    {
                        flag2=-1;
                        break;
                    }
                    
                    if(distance(X,Y,x[p],y[p])<d)
                        t++;
                }
                
                if(flag2==-1)   continue;
                
                //cout<<"t:"<<t<<endl;
                
                if(t==N)
                {
                    flag=1;
                    if(d<answer)
                        answer=d;
                    
                    break;
                }
                else if(t>N)
                    break;
                
                
            }
            //cout<<"flag:"<<flag<<endl;
            //cout<<"answer:"<<answer<<endl;
            
        }
        
        int result;
        result = (int)answer;
        if(flag==-1)    result=-1;
        
        printf("%d\n", result);
    }
    
    
    return 0;
}