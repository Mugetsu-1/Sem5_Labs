#include <iostream>
using namespace std;

long steps = 0;

void heapify(int arr[], int n, int i) {
    steps++;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        steps++;
        if (arr[l] > arr[largest])
            largest = l;
    }

    if (r < n) {
        steps++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        steps++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        steps++;
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        steps++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        steps++;
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        steps++;
        cout << arr[i] << " ";
    }

    cout << "\nTotal Steps:" << steps << endl;
    return 0;
}
