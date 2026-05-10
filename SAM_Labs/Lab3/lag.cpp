#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    // Data
    double values[] = {
        0.08, 0.12, 0.95, 0.34, 0.11, 0.56, 0.77, 0.21, 0.04, 0.66,
        0.43, 0.19, 0.82, 0.55, 0.27, 0.03, 0.99, 0.41, 0.15, 0.60,
        0.88, 0.32, 0.14, 0.71, 0.22
    };
    vector<double> R(values, values + sizeof(values) / sizeof(values[0]));
    
    int i = 1, m = 5, N = 25;
    int M = (N - i) / m - 1;
    
    cout << "Program 1: Autocorrelation Test (i=1, m=5)\n";
    cout << "M = " << M << endl;
    
    // Calculate ρ̂ᵢₘ
    double sum = 0;
    for(int k = 0; k <= M; k++) {
        int pos1 = i + k*m - 1;     // -1 for 0-based index
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
