#include <iostream>

using namespace std;

int n,t;
long long arr[101];

int main() {
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i < 101; ++i) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cout << arr[t] << "\n";
	}
}