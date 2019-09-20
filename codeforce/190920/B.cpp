#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((j + i) % 2 == 0) cout << 'W';
            else cout << 'B';
        }
        cout << '\n';
    }
}