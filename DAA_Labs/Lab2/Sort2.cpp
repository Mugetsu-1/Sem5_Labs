#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void copyArr(int src[], int dest[], int n) {
    for(int i = 0; i < n; i++) dest[i] = src[i];
}

int quickLoops;

int partition(int a[], int l, int h) {
    int pivot = a[h], i = l - 1;
    for(int j = l; j < h; j++) {
        quickLoops++;
        if(a[j] < pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i+1], a[h]);
    return i+1;
}

int randomPartition(int a[], int l, int h) {
    int r = l + rand() % (h - l + 1);
    swap(a[r], a[h]);
    return partition(a, l, h);
}

void quickSortHelper(int a[], int l, int h, bool random) {
    if(l < h) {
        quickLoops++;
        int p = random ? randomPartition(a, l, h)
                       : partition(a, l, h);
        quickSortHelper(a, l, p-1, random);
        quickSortHelper(a, p+1, h, random);
    }
}

void runQuickSort(int a[], int n) {
    int t[100];

    
    copyArr(a, t, n);
    quickLoops = 0;
    quickSortHelper(t, 0, n-1, false);
    cout << "Quick Sort\nLoops: " << quickLoops << "\nSorted: ";
    print(t, n);
    cout << endl;

    // Randomized
    copyArr(a, t, n);
    quickLoops = 0;
    srand(time(0));
    quickSortHelper(t, 0, n-1, true);
    cout << "Randomized Quick Sort\nLoops: " << quickLoops << "\nSorted: ";
    print(t, n);
    cout << endl;
}

int mergeLoops;

void merge(int a[], int l, int m, int r) {
    int L[100], R[100];
    int n1 = m - l + 1, n2 = r - m;

    for(int i = 0; i < n1; i++) L[i] = a[l+i];
    for(int j = 0; j < n2; j++) R[j] = a[m+1+j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        mergeLoops++;
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSortHelper(int a[], int l, int r) {
    if(l < r) {
        mergeLoops++;
        int m = (l + r) / 2;
        mergeSortHelper(a, l, m);
        mergeSortHelper(a, m+1, r);
        merge(a, l, m, r);
    }
}

void runMergeSort(int a[], int n) {
    int t[100];
    copyArr(a, t, n);
    mergeLoops = 0;

    mergeSortHelper(t, 0, n-1);

    cout << "Merge Sort\nLoops: " << mergeLoops << "\nSorted: ";
    print(t, n);
}
int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << "\nOriginal Array: ";
    print(a, n);
    cout << endl;

    runQuickSort(a, n);
    runMergeSort(a, n);

    return 0;
}
