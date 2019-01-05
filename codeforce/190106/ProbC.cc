#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    char arr[200] = {' ',};
    int star=0,candy=0,letter=0,total=0,require_length=0;
    for(int i = 0; i < 200; i++){
        scanf("%c",&arr[i]);
        if(arr[i] == '\n') break;
        total++;
        if(arr[i] == '*')star++;
        else if(arr[i] == '?')candy++;
        else letter++;
    }
    
    cin >> require_length;
    if(require_length <= letter){
        if(letter - require_length <= star + candy){
            int count = letter - require_length;
            for(int i = 0; i < total - 1; i++){
                if(count == 0){
                    if(arr[i] != '*' && arr[i] != '?') cout << arr[i];
                }else{
                    if(arr[i+1] == '*' || arr[i+1] == '?') count--;
                    else if(arr[i] != '*' && arr[i] != '?') cout << arr[i];
                }
                
            }
            if(arr[total-1] != '*' && arr[total-1] != '?') cout << arr[total-1];
        }else{
            cout << "Impossible";
            return 0;
        }
    }else{
        if(star > 0){
            int count = require_length - letter;
            for(int i = 0; i < total - 1; i++){
                if(count == 0){
                    if(arr[i] != '*' && arr[i] != '?') cout << arr[i];
                }else{
                    if(arr[i+1] == '*') {
                        count++;
                        while(count > 0){
                            cout << arr[i];
                            count--;
                        }
                    }else if(arr[i] != '*' && arr[i] != '?') cout << arr[i];
                }
                
            }
            if(arr[total-1] != '*' && arr[total-1] != '?') cout << arr[total-1];

        }else{
            cout << "Impossible";
            return 0;
        }
    }
}