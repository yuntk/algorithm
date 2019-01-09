#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    string tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        int count = 0;
        int sum = 0;
        for(int j = 0; j < tmp.length(); j++){
            if(tmp[j] == 'O'){
                count++;
                sum += count;
            }else{
                count = 0;
            }
        }
        cout << sum << "\n";
    }
}