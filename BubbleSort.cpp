#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/* Bubble Sort Function */
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

/* Insertion Sort Function */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int choice;
    cout << "Enter 1 for Bubble Sort or 2 for Insertion Sort: ";
    cin >> choice;

    int n = 10000;   // dataset size
    int* arr = new int[n];

    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start, end;

    if (choice == 1) {
        cout << "\nPerforming Bubble Sort...\n";
        start = clock();
        bubbleSort(arr, n);
        end = clock();
    }
    else if (choice == 2) {
        cout << "\nPerforming Insertion Sort...\n";
        start = clock();
        insertionSort(arr, n);
        end = clock();
    }
    else {
        cout << "Invalid choice!";
        delete[] arr;
        return 0;
    }

    // Calculate CPU execution time
    double cpu_time = double(end - start) / CLOCKS_PER_SEC;

    // Display first 10 sorted elements
    cout << "\nFirst 10 elements of the sorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nCPU Execution Time: " << cpu_time << " seconds\n";

    delete[] arr;   // free memory
    return 0;
}
