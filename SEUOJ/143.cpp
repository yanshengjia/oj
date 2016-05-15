// SEUOJ
// 极其简单的签到题

#include <iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    long long int t;
    long long int r = 0;

    while(cin>>t)
    {
        r += t;
        char c = cin.get();
        if(c == '\n')
        {
            cout<<r<<endl;
            r = 0;
        }
    }

    return 0;
}
