import java.util.Scanner;

import static java.lang.Math.min;

public class Main {

    public static int check(int y,int x,char[][] board){
        int wStart = 0;
        int bStart = 0;
        for(int i = y; i < y+8; i+=2){
            for(int j = x; j < x+8; j+=2){
                if(board[i][j] != 'W') wStart++;
                if(board[i][j+1] != 'B') wStart++;
                if(board[i+1][j] != 'B') wStart++;
                if(board[i+1][j+1] != 'W') wStart++;
                if(board[i][j] != 'B') bStart++;
                if(board[i][j+1] != 'W') bStart++;
                if(board[i+1][j] != 'W') bStart++;
                if(board[i+1][j+1] != 'B') bStart++;
            }
        }
        return min(wStart,bStart);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m;
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        char board[][] = new char[n][m];
        for(int i = 0; i < n; ++i){
            board[i] = sc.nextLine().toCharArray();
        }
        int result = 100000;
        for(int y = 0; y <= n-8; ++y){
            for(int x = 0; x <= m-8; ++x){
                result = min(check(y,x, board),result);
            }
        }
        System.out.println(result);
    }
}
