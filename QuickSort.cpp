#include <iostream>
#include <ctime>
using namespace std;

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // FIXED: input instead of cout
    }

    clock_t start = clock();

    quicksort(a, 0, n - 1);

    clock_t end = clock();

    cout << "\nArray after sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n\nExecution Time: " << time_taken << " seconds";

    return 0;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}