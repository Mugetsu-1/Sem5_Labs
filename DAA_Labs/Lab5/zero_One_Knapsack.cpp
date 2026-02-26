#include <iostream>
using namespace std;

long long steps = 0;

int max(int a, int b) {
    steps++;
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[100][100];

    for (int i = 0; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            steps++;
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[100], val[100];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        steps++;
        cin >> wt[i];
    }

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        steps++;
        cin >> val[i];
    }

    cout << "Enter capacity: ";
    cin >> W;

    int result = knapsack(W, wt, val, n);

    cout << "Maximum Profit: " << result << endl;
    cout << "Total Steps: " << steps << endl;

    return 0;
}