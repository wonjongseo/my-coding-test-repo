import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution_인구이동 {

    static int dx[] ={-1,0,1,0};
    static int dy[] = {0,1,0,-1};

    static int N,L,R = 0;
    static int sum = 0;
    static int num = 0;
    static boolean goStop = true;

    public static void main(String[] args) {
        BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));


        String str = br.readLine();
        String[] strArr = str.split(" ");
        N = Integer.parseInt(strArr[0]);
        L = Integer.parseInt(strArr[1]);
        R = Integer.parseInt(strArr[2]);

        int map[][] = new int[N][N];

        for (int i = 0 ; i< map.length;i++){
            String str1 = br.readLine();
            String[] strArr1 = str1.split(" ");
            for(int j = 0 ; j<map[i].length ; j++){
        
                map[i][j] = Integer.parseInt(strArr1[j]);
            }
        }
        int ans = 0;


        while(true){
            goStop = true;
            int[][] check = new int[N][N];
            int sticker =1;
            for(int i = 0 ; i< map.length ; i++){
                for(int j = 0 ; j< map[0].length ;j++){
                    if(check[i][j] == 0){
                        search(map, check ,i , j, sticker);
                        
                }
            }
        }

    }
    private static void search(int[][] map,  int[][]check , int x, int y ,int sticker) {
        check[x][y] = sticker;
        sum += map[x][y];
        num ++;

        for(int i = 0 ; i< 4; i++){
            int nx  = x + dx[i];
            int ny = y + dy[i];

            if(-1 < nx && nx < N && ny < N && ny < -1 && check[nx][ny] ==0){
                int gap = Math.abs(map[x][y] - map[nx][ny]);

                if(L<=gap && gap<=R){
                    search(map,check,nx,ny, sticker);
                }
            }
        }
        
    }
}