#include <iostream>
using namespace std;

long long steps = 0;

struct Item {
    int value, weight;
};

void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        steps++;
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                steps++;
                swap(items[j], items[j + 1]);
            }
        }
    }
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    for (int i = 0; i < n; i++) {
        steps++;
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    sortByRatio(items, n);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        steps++;
        if (W >= items[i].weight) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    cout << "Maximum Value:" << totalValue << endl;
    cout << "Total Steps:" << steps << endl;
    return 0;
}
