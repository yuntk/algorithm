#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(string s) {
	int answer = 0;
	string a = "";
	string b = "";
	vector<int> result;
	for (int i = 1; i < s.length() / 2 + 1; ++i) {
		a = "";
		b = "";
		int count = 0;
		if (s.length() == 1) return 1;
		vector<pair<int, string>> list;

		for (int j = 0; j < s.length(); j += i) {
			
				a = s.substr(j, i);
				if (a == "") break;
	
			
			//cout << "a:" << a << " ";
				if (j + i >= s.length()) {
					if (count == 0)list.push_back(make_pair(1, a));
					else list.push_back(make_pair(count + 1, a));
					//cout << count << "catch\n";
					break;
				}
				b = s.substr(j + i, i);


			
			if (b == "\n") {
				if (count == 0)list.push_back(make_pair(1, a));
				else list.push_back(make_pair(count + 1, a));
				//cout << count << "n\n";
				break;
			}
			if (b == "") {
				if (count == 0)list.push_back(make_pair(1, a));
				else list.push_back(make_pair(count + 1, a));
				//cout << count << "빈\n";
				break;
			}
			if (a == b) {
				count++;
				//cout << count << "같음\n";
			}
			else {
				if (count == 0)list.push_back(make_pair(1, a));
				else list.push_back(make_pair(count + 1, a));
				count = 0;
				//cout << count << "다름\n";
			}
		}
		count = 0;
		for (auto p : list) {
			if (p.first == 1) {
				count += p.second.length();
			}
			else {
				int len = 0;
				do {
					p.first = int(p.first / 10);
					len++;
				} while (p.first > 0);
				count = count + len + p.second.length();
			}
		}
		result.push_back(count);
		
	}
	try
	{
		sort(result.begin(), result.end());
	}
	catch (const std::exception&)
	{
		answer = 0;
	}
	

	try
	{
		if (result.empty()) {
			return 1;
		}
		answer = result[0];
	}
	catch (const std::exception&)
	{
		answer = 0;
	}
	return answer;
}