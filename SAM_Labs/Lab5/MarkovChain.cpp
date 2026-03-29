#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<double> multiply(const vector<double>& state, const vector<vector<double>>& p) {
    int n = (int)state.size();
    vector<double> next(n, 0.0);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            next[j] += state[i] * p[i][j];
        }
    }

    return next;
}

int main() {
    int n;
    cout << "Enter number of states: ";
    cin >> n;

    vector<vector<double>> p(n, vector<double>(n));
    cout << "Enter transition matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    vector<double> state(n);
    cout << "Enter initial state probabilities:\n";
    for (int i = 0; i < n; i++) {
        cin >> state[i];
    }

    int steps;
    cout << "Enter number of steps: ";
    cin >> steps;

    for (int s = 0; s < steps; s++) {
        state = multiply(state, p);
    }

    cout << fixed << setprecision(4);
    cout << "State probabilities after " << steps << " step(s):\n";
    for (int i = 0; i < n; i++) {
        cout << "State " << i << ": " << state[i] << "\n";
    }

    return 0;
}
