//https://www.acmicpc.net/step

#include <iostream>

using namespace std;


int n;
int sum;

int each_num_sum(int i)
{

	int sum = 0;
	while (true)
	{
		if (i == 0) return sum;
		sum += i - (i / 10) * 10;
		i = i / 10;
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		sum = i + each_num_sum(i);
		if (n == sum)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}