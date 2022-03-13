#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    int start, end ;
    scanf("%d %d", &start, &end);
    // 1 2 2 3 3 3 4 4 4 4
    int cnt = 0;
    int result = 0;
    for(int i = 1 ; i <= 1001; i++){
        for (int j = 1; j <= i; j++) {
            cnt++;
            if (cnt >= start && cnt <= end) {
                result += i;
            }
        }
    }
    cout << result <<endl;

}


