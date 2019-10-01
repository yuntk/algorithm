//
// Created by tk on 19. 10. 1..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, n;
    long long sum, tmp;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        sum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            sum += tmp;
        }
        if (sum % n == 0) cout << sum / n << endl;
        else cout << sum / n + 1 << endl;

    }

}
