//Fly me to the Alpha Centauri
//https://www.acmicpc.net/problem/1011
//1 1
//11 2
//121 4
//1221 6
//12321 9
//123321 12
//1234321 16

#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    unsigned int n;
    cin >> n;
    unsigned int x,y;
    unsigned int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        x = y-x;
        sum = 0;
        for(int j = 1; j < 100000; ++j){
            sum += j;
            if(x <= sum){
                cout << j*2 -1 << endl;
                break;
            }
            sum += j;
            if(x <= sum){
                cout << j*2 << endl;
                break;
            }
        }
    }
}