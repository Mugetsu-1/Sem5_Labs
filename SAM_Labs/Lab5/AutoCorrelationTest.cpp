#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, lag;
    cout << "Enter number of observations: ";
    cin >> n;

    vector<double> x(n);
    cout << "Enter observations:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter lag value: ";
    cin >> lag;

    if (lag <= 0 || lag >= n) {
        cout << "Invalid lag.\n";
        return 0;
    }

    double mean = 0.0;
    for (int i = 0; i < n; i++) {
        mean += x[i];
    }
    mean /= n;

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < n - lag; i++) {
        numerator += (x[i] - mean) * (x[i + lag] - mean);
    }

    for (int i = 0; i < n; i++) {
        denominator += (x[i] - mean) * (x[i] - mean);
    }

    double r = numerator / denominator;

    cout << fixed << setprecision(4);
    cout << "Autocorrelation coefficient r(" << lag << ") = " << r << "\n";

    if (r > 0) {
        cout << "Positive autocorrelation.\n";
    } else if (r < 0) {
        cout << "Negative autocorrelation.\n";
    } else {
        cout << "No autocorrelation.\n";
    }

    return 0;
}
