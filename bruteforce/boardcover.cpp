#include <iostream>
#include <vector>

const int coverType[4][3][2] = {
    { { 0, 0 }, { 0, 1 }, { 1, 0 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

bool set(int y, int x, int type, std::vector< std::vector<char> >& board, char mark){
    if(mark == '#'){
        bool isok = true;
        for(int i = 0; i < 3; i++){
            int posy = y+coverType[type][i][0];
            int posx = x+coverType[type][i][1];
            //check the board's border
            if( posy >= 0 && posy < board.size() && posx >= 0 && posx < board[0].size() ) {
                if(board[posy][posx] == '#') {
                    isok = false;
                    break;
                }
            } else {
                isok = false;
                break;
            }
        }
        //marking the board with '#'
        if( isok ){
            for(int i = 0; i < 3; i++){
                board[y+coverType[type][i][0]][x+coverType[type][i][1]] = '#';
            }
            return true;
        } else return false;
    } else {
        //marking the board with '.'
        //check fo debug
        int error = -1;
        for(int i = 0; i < 3; i++){
            int posy = y+coverType[type][i][0];
            int posx = x+coverType[type][i][1];
            if( posy >= 0 && posy < board.size() && posx >= 0 && posx < board[0].size() ) {
                if(board[posy][posx] == '.') {
                    error = 1;
                }
            } else {
                error = 2;
            }
        }
        if(error>0){
            std::cout << "error " << error;
            return -1;
        }
        for(int i = 0; i < 3; i++){
            board[y+coverType[type][i][0]][x+coverType[type][i][1]] = '.';
        }
    }
}

int cover(std::vector< std::vector<char> >& board ) {
    //search first  most left-upper pos
    int y = -1, x = -1;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == '.'){
                y = i;
                x = j;
                i = 99999;
                break;
            }
        }
    }

    //All positions are properly covered
    if(y == -1) return 1;
    
    int ret = 0;
    for(int i=0; i < 4; i++){
        if(set(y,x,i,board,'#')){
            ret += cover(board);
            set(y,x,i,board,'.');
        }
    }
    return ret;
}

int main(){
    
    int execute;
    int row,col;
    std::vector< std::vector<char> > board;

    std::cin >> execute;
    for(int i=0;i<execute;i++){
        
        //get input
        std::cin >> row >> col;
        board.clear();
        board.resize(row, std::vector<char>(col,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                std::cin >> board[i][j];
            }
        }

        //board is full or the number of '.' is not a multiple of three
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == '.') count++;
            }
        }
        if(count == 0 || count%3 !=0){
            std::cout << 0 << std::endl;
            continue;
        }

        //execution
        std::cout << cover(board) << std::endl;

    }//end excution case
    
}