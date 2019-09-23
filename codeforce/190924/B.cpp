#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (k == 0)break;

        if (i == 0) {
            if (n == 1) s[0] = '0';
            else {
                if (s[0] != '1') {
                    s[0] = '1';
                    --k;
                }
            }
        } else {
            if (s[i] != '0') {
                s[i] = '0';
                --k;
            }
        }
    }

    cout << s;
}