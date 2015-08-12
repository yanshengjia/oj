//POJ   #2386
//Lake Counting

#include <iostream>
using namespace std;

char field[101][101];
int N, M, result=0;

void dfs( int x, int y )
{
    field[x][y]='.'; //将'W'替换为'.'，扫描水洼并替换成陆地直到扫不到
    
    for(int dx=-1; dx<=1; dx++)
    {
        for(int dy=-1; dy<=1; dy++)
        {
            //基点为（i, j）, 向 x 方向移动 dy，向 y 方向移动 dy，移动到新点（nx, ny）
            int nx = x+dx, ny = y+dy;
            //判断新点是否合法以及新点是否有积水
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&field[nx][ny]=='W')
                dfs(nx, ny);
        }
    }
}


int main()
{
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>field[i][j];
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(field[i][j] == 'W')
            {   //从有 W 的地方开始 dfs
                dfs(i,j);
                result++;
            }
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}