#include <iostream>

const int kSwitch = 10;
const int kClock = 16;
const int kFail = 99999;
const char kLinkedClock[kSwitch][kClock+1] = {
    "XXX.............",
    "...X...X.X.X....",
    "....X.....X...XX",
    "X...XXXX........",
    "......XXX.X.X...",
    "X.X...........XX",
    "...X..........XX",
    "....XX.X......XX",
    ".XXXXX..........",
    "...XXX...X...X.."
};

bool IsAligned(int clocks[]){
    for (int i = 0; i < kClock; i++) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

int PushSwitch(int* clock,int switch_number) {
    for (int i = 0; i < kClock; i++)    {
        if (kLinkedClock[switch_number][i] == 'X') {
            clock[i] += 3;
            if (clock[i] == 15) clock[i] = 3;
        }
    }
}

int TryAllCase(int* clocks, int switch_number) {
    if (switch_number == kSwitch) {
        if (IsAligned(clocks)) {
            return 0;
        } else {
            return kFail;
        }
    }
    int min_rotation = kFail;
    for (switch_number; switch_number < kSwitch; switch_number++) {
        for (int k = 0; k < 4; k++) {
            min_rotation = std::min(min_rotation , k+TryAllCase(clocks, switch_number+1));
            PushSwitch(clocks, switch_number);
        }
    }
    return min_rotation;
}

int main(){
    int repeat_num = 0;
    
    std::cin >> repeat_num;
    int input_clocks[repeat_num][kClock];

    for (int i = 0; i < repeat_num; i++) {
        for (int j = 0; j < kClock; j++) {
            std::cin >> input_clocks[i][j];
        }

        //base case : all clocks are already alignd
        if (IsAligned(input_clocks[i])) return 0;

        //All cases are tried, Each switch 1,2,3,4... and rotation 0,1,2,3 times
        std::cout << TryAllCase(input_clocks[i], 0) << std::endl;

    }

}