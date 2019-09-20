#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int c, m, x;
    for (int i = 0; i < n; ++i) {
        cin >> c >> m >> x;
        if (c > m) {
            x += c - m;
            c = m;
        } else {
            x += m - c;
            m = c;
        }
        if(m > x){
            cout << x + ((m-x) *2)/3 << '\n';
        }else
            cout << m << '\n';
    }
}