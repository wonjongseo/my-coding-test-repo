#include <iostream>
#include <string.h>
#include <stack>
using namespace std;




int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    stack<int> S;
    int n ;
    cin >> n ;

    while (n--) {
        string cod;
        cin >> cod;

        if (cod == "push") {
            int num ;
            cin >> num ;
            S.push(num);
        } else if (cod == "pop") {
            if(S.empty()) printf("-1\n");
            else{
                printf("%d\n", S.top());
                S.pop();
            }
        }
        else if(cod=="size"){
            printf("%d\n", S.size());
        } else if (cod == "empty") {
            if (S.empty()) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        } else {
            if (S.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n",S.top());
            }
        }
    }
}