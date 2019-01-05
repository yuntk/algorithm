#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 2;
        return 0;
    }
    for(int i = 1; i < 100000; i++){
        if(i*i >= n){
            if(n - (i-1)*(i-1) <= (i-1)) cout << (i-1)*2 + 1;
            else cout << (i-1)*2 + 2;
            return 0;
        }
    }
}