#include <iostream>

using namespace std;
int divSum(int n) {
    if (n == 1)
        return 1;
    if (n % 2 == 1)
        return divSum(n - 1) + n;
    else
        return divSum(n / 2)*2 + (n / 2)*(n / 2);
}

int main(){
    int n;
    int res = 0;
    cin >> n;
    
    cout << divSum(n)%2;
}