#include <iostream>
#include <string.h>
using namespace std;

int front = 0;
int back = 0;
int n ;
int Q[10001];

bool isEmpty(){
    return front % n == back;
}
bool isFull(){
    return (front + 1) % n == back;
}

void enqueue(int num){
    if (isFull()) {
        return;
    }
    front = (front + 1) % n;
    Q[front] = num;
}

int dequeue() {
    if(isEmpty()){
        printf("underflow");
        return - 1;
    }
    back = (back + 1) % n;
    int returnV = Q[back];
    return returnV;
}



int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);


    cin >> n;

    while (n--) {
        string c;
        cin >> c;
        if (c == "push") {
            int num ;
            cin >> num;
            enqueue(num);
        } else if (c == "pop") {
            printf("%d\n",dequeue());
        } else if (c == "size") {
            printf("%d\n", abs(back - front));
        }
        else if (c == "empty") {
            if(isEmpty()){
                printf("1\n");
            }
            else
                printf("0\n");
        }
        else if (c == "front") {
            printf("%d\n", Q[back+1]);
        }
        else if (c == "back") {
            printf("%d\n", Q[front+1]);

        }

    }


}