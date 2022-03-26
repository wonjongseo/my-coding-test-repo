#include <iostream>
#include <string.h>
using namespace std;

int Index;
int arr[10001];


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n ;
    cin >> n ;

    while (n--) {
        string cod;
        cin >> cod;

        if (cod == "push") {
            int num ;
            cin >> num ;
            arr[++Index] = num;
        } else if (cod == "pop") {
            if (Index == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n",arr[Index--]);
            }
        }
        else if(cod=="size"){
            printf("%d\n", Index);
        } else if (cod == "empty") {
            if (Index == 0) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        } else {
            if (Index == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n",arr[Index]);
            }
        }
    }
}