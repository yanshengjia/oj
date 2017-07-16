#include <iostream>
using namespace std;

long long int extgcd(long long int a, long long int b, long long int& x, long long int& y)
{
    long long int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}

long long int mod_inv(long long int a, long long int m){
    long long int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main() {
    long long int a, b, bi, p, x, y;
    cin>>a>>b>>p;

    bi = mod_inv(b, p);

    cout<<(a * bi) % p;
    return 0;
}