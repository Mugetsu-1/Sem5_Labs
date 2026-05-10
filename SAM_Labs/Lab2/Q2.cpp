#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    double values[] = {0.54, 0.73, 0.98, 0.11, 0.68};
    vector<double> data(values, values + sizeof(values) / sizeof(values[0]));
    size_t N = data.size();
    double D = 0.0;

    sort(data.begin(), data.end());

    for(size_t i = 0; i < N; i++) {
        double Fn = (double)(i+1) / (double)(N);
        double F = data[i];
        double Dplus = Fn - F;
        double Dminus = F - (double)i / (double)(N);
        D = max(D, max(Dplus, Dminus));
    }

    double Dcritical = 0.565; // given for alpha=0.05, N=5

    cout << "Calculated D = " << D << endl;
    cout << "Critical D = " << Dcritical << endl;

    if(D > Dcritical)
        cout << "Reject null hypothesis (not uniform)" << endl;
    else
        cout << "Fail to reject null hypothesis (uniform)" << endl;

    return 0;
}
