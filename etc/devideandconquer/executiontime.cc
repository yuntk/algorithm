#include <iostream>
#include <time.h>

const int kNumber = 100000;
const int kLoop = 10;

using namespace std;
int RecSum(int num) {
	if(num == 1) return 1;
	return num + RecSum(num - 1);
}

int FastSum(int n) {
	if(n == 1) return 1;
	if(n % 2 ==1) return FastSum(n-1) + n;
	return 2*FastSum(n/2) + (n/2)*(n/2);
}

int main() {

	double everage = 0;
	for(int i = 0; i < kLoop; i++) {
		int prev = clock();
		int sum = 0;
		for(int j = 1; j <= kNumber; j++) {
			sum += j;
		}
		cout << i << " times " << sum << endl;
		everage += clock() - prev;
	}
	cout << "everage for runtime is " << everage/10 << endl;

	everage = 0;
	for(int i = 0; i < kLoop; i++) {
		int prev = clock();
		int sum = RecSum(kNumber);
		cout << i << " times " << sum << endl;
		everage += clock() - prev;
	}
	cout << "everage bruteRecursiveCall runtime is " << everage/10 << endl;

	everage = 0;
	for(int i = 0; i < kLoop; i++) {
		int prev = clock();
		int sum = FastSum(kNumber);
		cout << i << " times " << sum << endl;
		everage += clock() - prev;
	}
	cout << "everage Devide& Conquer runtime is " << everage/10 << endl;
}
		
