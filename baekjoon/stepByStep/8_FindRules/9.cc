//카잉 달력
//https://www.acmicpc.net/problem/6064
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int M,N,x,y,tmp;
    bool find = false;
    for(int i = 0; i < n; ++i){
        cin >> M >> N >> x >> y;
        find = false;
        tmp = lcm(M,N)/M +1;
        for(int j = 0; j <= tmp; ++j){
            if(((M*j+x-1) % N) + 1 == y){
                cout << (M*j+x) << "\n";
                find = true;
                break;
            }
        }
        if(!find) cout << -1 << "\n";
    }
}