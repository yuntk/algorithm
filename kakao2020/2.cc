#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


bool isBalance(string w) {
	int left = 0;
	int right = 0;
	for (char a : w) {
		if (a == '(') left++;
		else if(a == ')') right++;
		
	}
	return left == right;
}

bool isRight(string w) {
	int count = 0;
	for (char a : w) {
		if (count < 0) return false;
		if (a == '(') count++;
		if (a == ')') count--;
	}
	return true;
}

pair<string, string> splitTwoBlance(string w) {
	for (int i = 2; i <= w.length(); i += 2) {
		if (isBalance(w.substr(0, i))) {
			return make_pair(w.substr(0, i), w.substr(i));
		}
	}
}

string change(string w) {
	string tmp = "";
	for (char a : w) {
		if (a == '(') tmp += ")";
		else if (a == ')') tmp += "(";
	}
	return tmp;
}
string makeRight(string p) {
	if (p == "")return "";
	pair<string, string> uv = splitTwoBlance(p);
	if (isRight(uv.first)) {
		return uv.first + makeRight(uv.second);
	}
	else {
		string tmp = "(" + makeRight(uv.second) + ")" + change(uv.first.substr(1, uv.first.length() - 2));
		return tmp;
	}
}

string solution(string p) {
	
	return makeRight(p);
}

//int main() {
//	string in = ")(";
//	
//	string ans = solution(in);
//	cout << ans;
//	
//	//for (auto a:ans) cout << a << "\n";
//}