#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    cin >> n;
    int numbers[12];
    for (int i = 0; i < n; ++i) {
        cin >> k;
        memset(numbers, 0, sizeof(numbers));
        for (int j = 0; j < k; ++j) {
            cin >> tmp;
            for (int l = 0; l < 12; ++l) {
                if (tmp == (1 << l)) ++numbers[l];
            }
        }
        for (int l = 0; l < 11; ++l) {
            numbers[l + 1] += numbers[l] / 2;
        }
        if (numbers[11] >= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}