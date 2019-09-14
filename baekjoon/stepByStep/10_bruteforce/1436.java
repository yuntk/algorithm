import java.util.Scanner;

class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i = 666; i < 10000000; ++i) {//메모리를 너무 많이 사용함, int로 비교하는게 더 유리
            if (String.valueOf(i).contains("666".intern())) n--;
            if (n == 0) {
                System.out.println(i);
                break;
            }
        }
        return;
    }
}
