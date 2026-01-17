#include <iostream>
using namespace std;

void showArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    int loops = 0;
    int tempArr[100];
    for(int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        loops++;
        int minPos = i;
        
        for(int j = i+1; j < n; j++) {
            loops++;
            if(tempArr[j] < tempArr[minPos]) {
                minPos = j;
            }
        }
        
        if(minPos != i) {
            int temp = tempArr[i];
            tempArr[i] = tempArr[minPos];
            tempArr[minPos] = temp;
        }
    }
    
    cout << "Selection Sort - Loops: " << loops << endl;
    cout << "Sorted: ";
    showArray(tempArr, n);
}

void bubbleSort(int arr[], int n) {
    int loops = 0;
    int tempArr[100];
    for(int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        loops++;
        for(int j = 0; j < n-i-1; j++) {
            loops++;
            if(tempArr[j] > tempArr[j+1]) {
                int temp = tempArr[j];
                tempArr[j] = tempArr[j+1];
                tempArr[j+1] = temp;
            }
        }
    }
    
    cout << "Bubble Sort - Loops: " << loops << endl;
    cout << "Sorted: ";
    showArray(tempArr, n);
}

void insertionSort(int arr[], int n) {
    int loops = 0;
    int tempArr[100];
    for(int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    
    for(int i = 1; i < n; i++) {
        loops++;
        int key = tempArr[i];
        int j = i-1;
        
        while(j >= 0 && tempArr[j] > key) {
            loops++;
            tempArr[j+1] = tempArr[j];
            j--;
        }
        tempArr[j+1] = key;
    }
    
    cout << "Insertion Sort - Loops: " << loops << endl;
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
    
    selectionSort(arr, n);
    cout << endl;
    
    bubbleSort(arr, n);
    cout << endl;
    
    insertionSort(arr, n);
    
    return 0;
}
