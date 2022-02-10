#include <iostream>
#include <vector>
using namespace std;
vector<int> wanted;
int N , M;
vector<int> products;

bool findProduct(int start, int end ,int wantedProduct){
    int mid = (start +end )/ 2;

    if(start > end) return false; //>=?

    if(products[mid] == wantedProduct)
        return true;
    else if(products[mid] > wantedProduct)
        return findProduct(start, mid - 1, wantedProduct);

    return findProduct(mid + 1, end, wantedProduct);
}

int main(){
    cin >> N;

    for(int i = 0 ;i<N ; i++){
        int tmp ;
        cin >> tmp;
        products.push_back(tmp);
    }
    cin >> M;
    for(int i = 0 ;i<M ; i++){
        int tmp ;
        cin >> tmp;
        wanted.push_back(tmp);
    }

    for(int i = 0 ;i<M ; i++){
        if(findProduct(0,N-1,wanted[i]))
            cout << "YES ";

        else
            cout << "NO ";
    }





}

/*
 5
 8 3 7 9 2
 3
 5 7 9
 */