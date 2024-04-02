#include <iostream>
#include <vector>
using namespace std;

struct process {
    string name;
    int brusttime;
    int waitingtime;
    int turnaroundtime;
};

int main() {
    int numprocesses;
    cout << "Enter the number of processes: ";
    cin >> numprocesses;

    vector<process> processes(numprocesses);

    for (int i = 0; i < numprocesses; i++) {
        cout << "Enter burst time for process " << (i + 1) << ": ";
        cin >> processes[i].brusttime;
        processes[i].name = "p" + to_string(i + 1);
        processes[i].waitingtime = 0;
        processes[i].turnaroundtime = 0;
    }

    for (int i = 1; i < numprocesses; i++) {
        processes[i].waitingtime = processes[i - 1].waitingtime + processes[i - 1].brusttime;
        processes[i].turnaroundtime = processes[i].waitingtime + processes[i].brusttime;
    }

    double avgwaitingtime = 0, avgturnaroundtime = 0;
    for (int i = 0; i < numprocesses; i++) {
        avgwaitingtime += processes[i].waitingtime;
        avgturnaroundtime += processes[i].turnaroundtime;
    }

    avgwaitingtime /= numprocesses;
    avgturnaroundtime /= numprocesses;

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numprocesses; i++) {
        cout << processes[i].name << "\t" << processes[i].brusttime << "\t\t"
             << processes[i].waitingtime << "\t\t" << processes[i].turnaroundtime << "\n";
    }

    cout << "\nAverage Waiting Time: " << avgwaitingtime << "\n";
    cout << "Average Turnaround Time: " << avgturnaroundtime << "\n";

    return 0;
}