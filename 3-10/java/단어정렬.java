import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class 단어정렬 {
    public static void main(String[] args) {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in))
        
        int N = Integer.parseInt(br.readLine());

        String [] arr = new String[N];

        for(int i = 0 ; i< N ; i++){
            arr[i] = br.readLine();
        }
        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length() == o2.length())
                    return o1.compareTo(o2);
                
                    return o1.length() - o2.length();
                
            }
        });
        StringBuilder sb = new StringBuilder();
        sb.append(arr[0]).append('\n');


        for(int i = 1;  i< N  ;i++){
            if(!arr[i].equals(arr[i-1])){
                sb.append(arr[i]).append('\n');
            }
        }

        System.out.println(sb);
    }
}