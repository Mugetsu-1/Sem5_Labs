#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int k;
    cout << "Enter number of classes: ";
    cin >> k;

    vector<double> observed(k);
    cout << "Enter observed frequencies:\n";

    double total = 0.0;
    for (int i = 0; i < k; i++) {
        cin >> observed[i];
        total += observed[i];
    }

    double expected = total / k; // uniform expected frequency

    double chi = 0.0;
    for (int i = 0; i < k; i++) {
        chi += (observed[i] - expected) * (observed[i] - expected) / expected;
    }

    cout << fixed << setprecision(4);
    cout << "Chi-square value = " << chi << "\n";
    cout << "Degrees of freedom = " << (k - 1) << "\n";
    cout << "Compare with chi-square table at your chosen alpha (e.g., 0.05).\n";

    return 0;
}
