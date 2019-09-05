#include <iostream>
#include <stdio.h>
using namespace std;
int blue[1001],red[1001],green[1001];
int n;
int main(){
    cin >> n;
    int r,g,b;
    red[0] = 0;
    green[0] = 0;
    blue[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d %d %d",&r,&g,&b);
        red[i] = (green[i-1] > blue[i-1] ? blue[i-1] : green[i-1]) + r;
        green[i] = (red[i-1] > blue[i-1] ? blue[i-1] : red[i-1]) + g;
        blue[i] = (red[i-1] > green[i-1] ? green[i-1] : red[i-1]) + b;
    }
    if(red[n] > green[n])
        cout << (green[n] > blue[n] ? blue[n] : green[n]);
    else
        cout << (red[n] > blue[n] ? blue[n] : red[n]);
    return 0;
}