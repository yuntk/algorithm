#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    
    int tmp = 0;
    int sum = 0;
    for(int i = 0; i < 5; ++i){
        cin >> tmp;
        sum += tmp < 40 ? 40 : tmp;
    }
    cout << sum/5;
}