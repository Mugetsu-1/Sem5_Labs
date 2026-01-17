#include <iostream>
#include <cstdlib>   
#include <ctime>    
using namespace std;

void showArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int quickLoops = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        quickLoops++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSortHelper(int arr[], int low, int high) {
    if(low < high) {
        quickLoops++;
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi-1);
        quickSortHelper(arr, pi+1, high);
    }
}

void quickSort(int arr[], int n) {
    int tempArr[100];
    for(int i = 0; i < n; i++) tempArr[i] = arr[i];
    quickLoops = 0;

    quickSortHelper(tempArr, 0, n-1);

    cout << "Quick Sort - Loops: " << quickLoops << endl;
    cout << "Sorted: ";
    showArray(tempArr, n);
}


int randQuickLoops = 0;

int randomizedPartition(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        randQuickLoops++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void randomizedQuickSortHelper(int arr[], int low, int high) {
    if(low < high) {
        randQuickLoops++;
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSortHelper(arr, low, pi-1);
        randomizedQuickSortHelper(arr, pi+1, high);
    }
}

void randomizedQuickSort(int arr[], int n) {
    int tempArr[100];
    for(int i = 0; i < n; i++) tempArr[i] = arr[i];
    randQuickLoops = 0;

    srand((unsigned int)time(0)); // seed random
    randomizedQuickSortHelper(tempArr, 0, n-1);

    cout << "Randomized Quick Sort - Loops: " << randQuickLoops << endl;
    cout << "Sorted: ";
    showArray(tempArr, n);
}


int mergeLoops = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];

    for(int i = 0; i < n1; i++) L[i] = arr[l+i];
    for(int j = 0; j < n2; j++) R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        mergeLoops++;
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) {
        arr[k++] = L[i++];
    }
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSortHelper(int arr[], int l, int r) {
    if(l < r) {
        mergeLoops++;
        int m = l + (r-l)/2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int n) {
    int tempArr[100];
    for(int i = 0; i < n; i++) tempArr[i] = arr[i];
    mergeLoops = 0;

    mergeSortHelper(tempArr, 0, n-1);

    cout << "Merge Sort - Loops: " << mergeLoops << endl;
    cout << "Sorted: ";
    showArray(tempArr, n);
}


int main() {
    int arr[100];
    int n;

    cout << "Enter number of elements (max 100): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    showArray(arr, n);
    cout << endl;

    quickSort(arr, n);
    cout << endl;

    randomizedQuickSort(arr, n);
    cout << endl;

    mergeSort(arr, n);

    return 0;
}
