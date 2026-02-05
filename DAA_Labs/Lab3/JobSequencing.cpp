#include <iostream>
using namespace std;

long long steps = 0;

struct Job {
    char id;
    int deadline;
    int profit;
};

void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        steps++;
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            if (jobs[j].profit < jobs[j + 1].profit) {
                steps++;
                swap(jobs[j], jobs[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[100];

    for (int i = 0; i < n; i++) {
        steps++;
        cout << "Enter Job ID, Deadline, Profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sortJobs(jobs, n);

    int slot[100] = {0};
    char result[100];

    for (int i = 0; i < n; i++) {
        steps++;
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            steps++;
            if (!slot[j]) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "Job Sequence: ";
    for (int i = 0; i < n; i++) {
        steps++;
        if (slot[i])
            cout << result[i] << " ";
    }

    cout << "\nTotal Steps:" << steps << endl;
    return 0;
}
