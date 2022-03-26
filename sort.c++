// 

#include <queue>
#include <iostream>

using namespace std;

void quickSort(int arr[], int start, int end){
    if ( start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;

    while (left < right) {

        while(left <= end && arr[left] <= arr[pivot])
            left++;
        while(right > start && arr[right] >= arr[pivot])
            right--;
        if(left > right)
            swap(arr[pivot], arr[right]);
        else
            swap(arr[left], arr[right]);
    }

    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}


void insertedSort(int arr[], int size){
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void coefficentSort(int arr[], int size){
    int MAX_VALUE = 9;
    int count[MAX_VALUE + 1];

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for (int i = 0; i <= MAX_VALUE; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("%d ", i);
        }
    }
}





void selectedSort(int  arr[], int size){
    for (int i = 1; i < size; i++) {
        for (int j = i; j >  0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else break;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}


int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[8] = {7, 4, 1,3, 5, 2, 8, 6};
    selectedSort(arr, 8);

    int arr2[8] = {7, 4, 1,3, 5, 2, 8, 6};
    insertedSort(arr2, 8);

    int arr3[8] = {7, 4, 1,3, 5, 2, 8, 6};

    quickSort(arr3, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");


}