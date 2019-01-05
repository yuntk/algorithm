#include <iostream>

using namespace std;

bool board[3072][6144];

int drawstar(int ysp, int xsp, int n){
    if(n != 3) {
        drawstar(ysp,xsp,n/2);
        drawstar(n/2+ysp, xsp - n/2, n/2);
        drawstar(n/2+ysp, xsp + n/2, n/2);
    }else{
        board[ysp][xsp-1] = true;
        board[ysp+1][xsp-2] = true;
        board[ysp+1][xsp] = true;
        for(int i = 0; i < 5; i++){
            board[ysp+2][xsp-3+i] = true;
        }
    }
}
int main(){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n+i; j++) board[i][j] = false;
    }
    drawstar(0,n,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n*2; j++){
            if(board[i][j]) printf("%c",'*');
            else printf("%c",' ');
        }
        printf("\n");
    }

}

/*
ex) input : 24
output : 
                       *
                      * *
                     *****
                    *     *
                   * *   * *
                  ***** *****
                 *           *
                * *         * *
               *****       *****
              *     *     *     *
             * *   * *   * *   * *
            ***** ***** ***** *****
           *                       *
          * *                     * *
         *****                   *****
        *     *                 *     *
       * *   * *               * *   * *
      ***** *****             ***** *****
     *           *           *           *
    * *         * *         * *         * *
   *****       *****       *****       *****
  *     *     *     *     *     *     *     *
 * *   * *   * *   * *   * *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****
*/