#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Process structure to hold process details
struct Process {
    int id;             // Process ID
    int arrivalTime;    // Arrival time of the process
    int burstTime;      // Burst time of the process
    int remainingTime;  // Remaining burst time of the process
};

// Function to perform Round Robin scheduling
void roundRobinScheduling(vector<Process>& processes, int quantum) {
    queue<Process> readyQueue;  // Queue to store processes ready to execute
    int currentTime = 0;        // Current time
    int totalProcesses = processes.size();
    int completedProcesses = 0;

    while (completedProcesses < totalProcesses) {
        // Adding processes to ready queue that arrive by current time
        for (Process& p : processes) {
            if (p.arrivalTime <= currentTime && p.remainingTime > 0) {
                readyQueue.push(p);
            }
        }

        // If ready queue is empty, jump to next arrival time
        if (readyQueue.empty()) {
            currentTime++;
            continue;
        }

        // Process the front process in ready queue
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        // Execute the process for the given quantum or remaining time, whichever is smaller
        int executionTime = min(quantum, currentProcess.remainingTime);
        currentProcess.remainingTime -= executionTime;
        currentTime += executionTime;

        // Check if the process is completed
        if (currentProcess.remainingTime <= 0) {
            completedProcesses++;
            cout << "Process " << currentProcess.id << " completed at time " << currentTime << endl;
        } else {
            // If not completed, push it back to the ready queue
            readyQueue.push(currentProcess);
        }
    }
}

int main() {
    // Example processes
    vector<Process> processes = {
        {1, 0, 4, 4},
        {2, 1, 5, 5},
        {3, 2, 2, 2},
        {4, 3, 1, 1}
    };

    int quantum = 2; // Quantum for round robin scheduling

    cout << "Round Robin CPU Scheduling\n";
    cout << "---------------------------\n";
    cout << "Quantum: " << quantum << endl;

    // Perform Round Robin scheduling
    roundRobinScheduling(processes, quantum);

    return 0;
}
