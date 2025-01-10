#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a process
struct Process {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
};

// Function to simulate First Come First Serve (FCFS) scheduling
void fcfs(vector<Process>& processes) {
    int currentTime = 0;
    cout << "FCFS Scheduling:" << endl;
    for (const auto& process : processes) {
        currentTime = max(currentTime, process.arrival);
        cout << "Process " << process.id << " starts at time " << currentTime << endl;
        currentTime += process.burst;
        cout << "Process " << process.id << " finishes at time " << currentTime << endl;
    }
}
