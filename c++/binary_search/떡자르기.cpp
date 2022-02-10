
#include <iostream>
#include <vector>
using namespace std;
int N,M;

int total;
int level;

/*
 * 파라메트릭 서치,
 * 최적화문제를 결정문제로 바꿈.
 * 원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제.에 주로 사용
 * 범위 내에 조건을 만족하는 가장 큰 값을 찾으라.
 */

vector<int> dduck;
int cutting(int index, int start , int end){
    if (start >= end) return -1;




}

int main(){
   cin >> N >> M;
   int max_dduck = -1;
   for(int i = 0 ; i< N; i++){
       int tmp;
       cin >> tmp;
       dduck.push_back(tmp);
       if (tmp > max_dduck) {
           max_dduck = tmp;
       }
   }


    int start = 0;
   int end = max_dduck;
    int result = 0;
    while (start <= max_dduck) {
        total = 0;

        int mid = (start + end) / 2;

        for(int i = 0 ; i< N ; i++){
            if(dduck[i] > mid){
                total += dduck[i] -mid;
            }
        }
        if(total == M) break;

        else if(total < M) {
            end = mid -1;
        }

        else if(total > M)
            start = mid +1;

    }
}

/*
 5
 8 3 7 9 2
 3
 5 7 9
 */