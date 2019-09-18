#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    long n;
    cin >> n;
    long a = sqrt(n);
    while(n % a){
        --a;
    }
    cout << n/a - a;

}
