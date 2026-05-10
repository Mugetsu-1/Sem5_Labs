#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    // Data
    double values[] = {
        0.50, 0.11, 0.23, 0.76, 0.44, 0.82, 0.19, 0.55, 0.33, 0.91,
        0.02, 0.67, 0.48, 0.12, 0.59, 0.31, 0.88, 0.05, 0.74, 0.26
    };
    vector<double> R(values, values + sizeof(values) / sizeof(values[0]));
    
    int i = 4, m = 2, N = 20;
    int M = (N - i) / m - 1;
    
    cout << "Program 2: Autocorrelation Test (i=4, m=2)\n";
    cout << "M = " << M << endl;
    
    // Calculate ρ̂ᵢₘ
    double sum = 0;
    for(int k = 0; k <= M; k++) {
        int pos1 = i + k*m - 1;
        int pos2 = i + (k+1)*m - 1;
        sum += R[pos1] * R[pos2];
    }
    
    double rho = (sum / (M + 1) - 0.25) * (12 / (M + 1));
    double sigma = sqrt(13 * M + 7) / (12 * (M + 1));
    double Z0 = rho / sigma;
    
    cout << "RHO = " << rho << endl;
    cout << "Sigma = " << sigma << endl;
    cout << "Z0 = " << Z0 << endl;
    
    if(abs(Z0) < 1.96)
        cout << "H0 not rejected. Numbers are independent.\n";
    else
        cout << "H0 rejected. Numbers are dependent.\n";
    
    return 0;
}
