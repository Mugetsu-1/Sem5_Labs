#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter number of 3-digit groups: ";
    cin >> n;

    vector<int> groups(n);
    cout << "Enter each group (000 to 999):\n";
    for (int i = 0; i < n; i++) {
        cin >> groups[i];
    }

    int allSame = 0, onePair = 0, allDiff = 0;

    for (int num : groups) {
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;

        if (a == b && b == c) {
            allSame++;
        } else if (a == b || b == c || a == c) {
            onePair++;
        } else {
            allDiff++;
        }
    }

    double eAllSame = 0.01 * n;
    double eOnePair = 0.27 * n;
    double eAllDiff = 0.72 * n;

    double chi = 0.0;
    chi += (allSame - eAllSame) * (allSame - eAllSame) / eAllSame;
    chi += (onePair - eOnePair) * (onePair - eOnePair) / eOnePair;
    chi += (allDiff - eAllDiff) * (allDiff - eAllDiff) / eAllDiff;

    double critical = 5.991; // df=2, alpha=0.05

    cout << fixed << setprecision(4);
    cout << "Observed -> All same: " << allSame << ", One pair: " << onePair << ", All different: " << allDiff << "\n";
    cout << "Chi-square value = " << chi << "\n";
    cout << "Critical value (df=2, alpha=0.05) = " << critical << "\n";

    if (chi < critical) {
        cout << "Accept H0: Sequence passes poker test.\n";
    } else {
        cout << "Reject H0: Sequence fails poker test.\n";
    }

    return 0;
}
