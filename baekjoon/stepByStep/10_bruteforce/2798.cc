//https://www.acmicpc.net/problem/2798

#include <iostream>

using namespace std;


int n, m, diff =2147483647;
int result = 0;
void dfs(int arr[], int pos, int remain_pick, int sum)
{
	if (remain_pick == 0)
	{
		auto const n_diff = m-sum;
		if (n_diff < 0) return;
		if (n_diff < diff){
			diff = n_diff;
			result = sum;
		}
		return;
	}
	for (auto i = pos; i < n; ++i)
	{
		dfs(arr, i + 1, remain_pick - 1, sum + arr[i]);
	}
}

int main()
{
	
	cin >> n >> m;
	int arr[100];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	dfs(arr, 0, 3, 0);
	cout << result;
}