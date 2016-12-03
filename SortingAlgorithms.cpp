#include <iostream>
using namespace std;

template <class T>
void insertionSort(T arr[], int n) {
    int i,j;
    T store;
    for(i = 1; i<n; i++){
        store = arr[i];
        j = i;
        while(j > 0) {
            if(arr[j-1] < store) break;
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = store;
    }
}


template <class T>
void quickSort(T *arr, int n) {
    if (n <= 1) return;
    T piv = arr[n-1];
    T temp;
    int i;
    int j = 0;
    for(i = 0; i < n-1; i++) {
        if (arr[i] < piv) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    temp = arr[j];
    arr[j] = piv;
    arr[n-1] = temp;
    quickSort(arr, j-1);
    quickSort((arr+j+1), n-j);
}


int main() {
    int arr[] = {1,3,99,7,1,2,4};
    insertionSort(arr, 7);
    for(int a : arr){
        cout << a << "\n";
    }
}

