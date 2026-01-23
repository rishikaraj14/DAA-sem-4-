#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int choice;
    cout << "Enter 1 for Bubble Sort and 2 for Insertion Sort: ";
    cin >> choice;

    int n = 10000;
    int* arr = new int[n];

    srand(time(0));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10000;
    }

    clock_t start, end;

    if(choice == 1){
        start = clock();
        bubbleSort(arr, n);
        end = clock();
    }
    else if(choice == 2){
        start = clock();
        insertionSort(arr, n);
        end = clock();
    }
    else{
        cout << "Invalid choice!";
        return 0;
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << " seconds" << endl;

    delete[] arr;
    return 0;
}