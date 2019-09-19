#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char a;
    int o = 0, N = 0, e = 0, z = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == 'n') N++;
        if (a == 'z') z++;
    }

    for (int i = 0; i < N; ++i) cout << "1 ";
    for (int i = 0; i < z; ++i) cout << "0 ";

}