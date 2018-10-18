#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    std::sort(citations.begin(), citations.end());
    int HIndex = 0;
    for(int i = 0; i < citations.size(); i++) {
        if(citations[citations.size()-1-i] <= i) break;
        else HIndex = i+1;
    }
    int answer = HIndex;
    return answer;
}

int main(){
    int testNum = 0;
    int caseNum = 0;
    vector<int> caseVector(0);
    int tmp = 0;

    cin >> testNum;
    for(int i = 0; i < testNum; i++) {
        cin >> caseNum;
        caseVector.resize(caseNum);
        for(int i = 0; i<caseNum; i++) {
            cin >> tmp;
            caseVector.push_back(tmp);
        }
        std::cout << solution(caseVector) << endl;
    }
}