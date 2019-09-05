#include <iostream>

using namespace std;
int n;
long long resultFir;
long long resultSec;

int main(){
	cin >> n;
	if (n == 0) cout << 0;
	if (n == 1) cout << 1;
	else{
		resultFir = 0;
		resultSec = 1;
		for (int i = 1; i < n; ++i){
			if (resultFir > resultSec) resultSec = resultFir + resultSec;
			else resultFir = resultFir + resultSec;
		}
		cout << ((resultFir > resultSec) ? resultFir : resultSec);
	}
}
