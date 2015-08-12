//SEUOJ  #54

#include <iostream>
using namespace std;

void sumofRow(int array[][4])
{
    for(int i=0; i<3; i++)
    {
        int temp;
        temp = array[i][0]+array[i][1]+array[i][2]+array[i][3];
        array[i][0]=temp;
    }
    
}



int main()
{
    int a[3][4];
    for( int i=0; i<3; i++)
    {
        for( int j=0; j<4; j++)
            cin>>a[i][j];
    }
    
    sumofRow(a);
    
    cout<<a[0][0]<<" "<<a[1][0]<<" "<<a[2][0];
    
    return 0;
}