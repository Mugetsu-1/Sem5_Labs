#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void show(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void copyArr(int s[], int d[], int n) {
    for(int i = 0; i < n; i++) d[i] = s[i];
}
void selectionSort(int a[], int n) {
    int t[100], loops = 0;
    copyArr(a, t, n);

    for(int i = 0; i < n-1; i++) {
        loops++;
        int m = i;
        for(int j = i+1; j < n; j++) {
            loops++;
            if(t[j] < t[m]) m = j;
        }
        swap(t[i], t[m]);
    }

    cout << "Selection Sort - Loops: " << loops << "\nSorted: ";
    show(t, n);
}
void bubbleSort(int a[], int n) {
    int t[100], loops = 0;
    copyArr(a, t, n);

    for(int i = 0; i < n-1; i++) {
        loops++;
        for(int j = 0; j < n-i-1; j++) {
            loops++;
            if(t[j] > t[j+1]) swap(t[j], t[j+1]);
        }
    }

    cout << "Bubble Sort - Loops: " << loops << "\nSorted: ";
    show(t, n);
}
void insertionSort(int a[], int n) {
    int t[100], loops = 0;
    copyArr(a, t, n);

    for(int i = 1; i < n; i++) {
        loops++;
        int k = t[i], j = i - 1;
        while(j >= 0 && t[j] > k) {
            loops++;
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = k;
    }

    cout << "Insertion Sort - Loops: " << loops << "\nSorted: ";
    show(t, n);
}
void minMax(int a[], int n) {
    int mn = a[0], mx = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < mn) mn = a[i];
        if(a[i] > mx) mx = a[i];
    }
    cout << "Min: " << mn << "  Max: " << mx << endl;
}
Node* insert(Node* r, int v) {
    if(!r) return new Node{v, NULL, NULL};
    if(v < r->data) r->left = insert(r->left, v);
    else r->right = insert(r->right, v);
    return r;
}

void inorder(Node* r, int t[], int &i) {
    if(!r) return;
    inorder(r->left, t, i);
    t[i++] = r->data;
    inorder(r->right, t, i);
}

void bstSort(int a[], int n) {
    Node* r = NULL;
    for(int i = 0; i < n; i++) r = insert(r, a[i]);

    int t[100], i = 0;
    inorder(r, t, i);

    cout << "BST Sort\nSorted: ";
    show(t, n);
}
int main() {
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << "\nOriginal: ";
    show(a, n);
    cout << endl;

    selectionSort(a, n); cout << endl;
    bubbleSort(a, n);    cout << endl;
    insertionSort(a, n); cout << endl;
    minMax(a, n);        cout << endl;
    bstSort(a, n);

    return 0;
}
