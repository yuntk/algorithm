#include <iostream>
#include <string.h>

using namespace std;


class Size{
public:
	int weight;
	int height;
	Size()
	{
		weight = 0;
		height = 0;
	}
	
	bool operator> (const Size& p){
		if (weight > p.weight && height > p.height) return true;
		if (weight < p.weight && height < p.height) return false;
		return false;
	}
};


int main()
{
	int n;
	cin >> n;
	Size Size_arr[50];
	int order[50];
	memset(order, 0, sizeof(order));
	for (int i = 0; i < n; ++i)
	{
		cin >> Size_arr[i].weight >> Size_arr[i].height;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (Size_arr[j] > Size_arr[i]) order[i]++;
		}
		order[i]++;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << order[i] << ' ';
	}
	
}