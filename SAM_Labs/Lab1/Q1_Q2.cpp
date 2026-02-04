#include <iostream>
using namespace std;

int main() {
    // Given values
    int days = 6;
    int hoursPerDay = 9;
    int calls = 1620;

    
    int totalMinutes = days * hoursPerDay * 60;
    double arrivalRate = (double)calls / totalMinutes;   // λ = calls / minutes
    double interArrivalTime = 1 / arrivalRate;            // 1 / λ

    cout << "Mean arrival rate (calls per minute): " << arrivalRate << endl;
    cout << "Mean inter-arrival time (minutes): " << interArrivalTime << endl;

    return 0;
}
