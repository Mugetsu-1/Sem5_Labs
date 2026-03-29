#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter number of observations: ";
    cin >> n;

    vector<double> x(n);
    cout << "Enter observations (between 0 and 1):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    double dPlus = 0.0, dMinus = 0.0;
    for (int i = 0; i < n; i++) {
        double fi = (i + 1) / (double)n;
        double fiPrev = i / (double)n;
        dPlus = max(dPlus, fi - x[i]);
        dMinus = max(dMinus, x[i] - fiPrev);
    }

    double d = max(dPlus, dMinus);
    double critical = 1.36 / sqrt((double)n); // alpha = 0.05

    cout << fixed << setprecision(4);
    cout << "D+ = " << dPlus << "\n";
    cout << "D- = " << dMinus << "\n";
    cout << "D  = " << d << "\n";
    cout << "Critical value (alpha = 0.05) = " << critical << "\n";

    if (d < critical) {
        cout << "Accept H0: Data follows Uniform(0,1).\n";
    } else {
        cout << "Reject H0: Data does not follow Uniform(0,1).\n";
    }

    return 0;
}
