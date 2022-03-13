#include<iostream>
#include<algorithm>

        using namespace std;
        int T;
        void solution() {
            int total = 0;
            int max = -1;
            for (int i = 1; i <= 10; i++) {
                int in, out;
                scanf("%d %d", &out, &in);

                total -= out;
                total += in;

                if (total > max) {
                    max = total;
                }
            }

            printf("%d\n", max);
        }


        int main(){

            solution();

            return 0;

        }