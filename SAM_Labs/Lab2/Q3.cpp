#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    double values[] = {0.35, 0.77, 0.12, 0.33, 0.88, 0.45, 0.19, 0.25, 0.91, 0.54};
    vector<double> data(values, values + sizeof(values) / sizeof(values[0]));
    size_t N = data.size();
    double D = 0.0;

    sort(data.begin(), data.end());

    for(size_t i = 0; i < N; i++) {
        double Fn = static_cast<double>(i + 1) / static_cast<double>(N);
        double F = data[i];
        double Dplus = Fn - F;
        double Dminus = F - static_cast<double>(i) / static_cast<double>(N);
        D = max(D, max(Dplus, Dminus));
    }

    double Dcritical = 0.41; // given for alpha=0.05, N=10

    cout << "Calculated D = " << D << endl;
    cout << "Critical D = " << Dcritical << endl;

    if(D > Dcritical)
        cout << "Reject null hypothesis (not independent/uniform)" << endl;
    else
        cout << "Fail to reject null hypothesis (independent/uniform)" << endl;

    return 0;
}
