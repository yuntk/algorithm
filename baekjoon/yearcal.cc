#include <iostream>

using namespace std;

int E, S, M;

int main(void){
    int result;
    int year = 1;

    cin >> E >> S >> M;
    while(1){
        if ((year - E) % 15 || (year - S) % 28 || (year - M) % 19);
        else{
            result = year;
            break;
        }
        year++;
    }
    cout << result << endl;
}