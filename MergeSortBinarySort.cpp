#include <iostream>
using namespace std;

/* Function Declarations */
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int binarySearch(int arr[], int n, int key);

/* Main Function */
int main() {
    int n, key, result;
    int arr[100];

    // Accept number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Accept array elements
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call Merge Sort
    mergeSort(arr, 0, n - 1);

    // Display sorted array
    cout << "\nSorted Array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Accept key to search
    cout << "\n\nEnter element to search: ";
    cin >> key;

    // Call Binary Search
    result = binarySearch(arr, n, key);

    if(result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

/* Merge Sort Function */
void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);        // Left half
        mergeSort(arr, mid + 1, high);   // Right half

        merge(arr, low, mid, high);      // Merge both halves
    }
}

/* Merge Function */
void merge(int arr[], int low, int mid, int high) {
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

/* Binary Search Function */
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}