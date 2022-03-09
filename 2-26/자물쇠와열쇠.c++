#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate_90_degree(vector<vector<int>> key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> new_vector(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_vector[j][n - i - 1] = key[i][j];
        }
    }

    return new_vector;
}

bool check(vector<vector<int>> lock){
    int n = lock.size() / 3;
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            if (lock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock){
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> new_lock(n * 3, vector<int>(n * 3));

    for(int i = 0 ; i< n; i++){
        for (int j = 0; j < n; j++) {
            new_lock[n + i][n + j] = lock[i][j];
        }
    }

    for (int rotate = 0; rotate < 4; rotate++) {
        key=  rotate_90_degree(key);

        for(int x = 0 ; x < n * 2 ; x++){
            for (int y = 0; y < n * 2; y++) {

                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] += key[i][j];
                    }
                }
                if(check(new_lock)){
                    return true;
                }
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;


}
int main(){
    bool is = solution(
            {
                    {0, 0, 0},
                    {1, 0, 0},
                    {0, 1, 1}
            },
            {
                    {1, 1, 1},
                    {1, 1, 0},
                    {1, 0, 1}
            });

    if(is){
        printf("true");

    }
    else{
        printf("false");
    }

}
