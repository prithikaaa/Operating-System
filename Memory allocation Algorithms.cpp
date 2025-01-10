#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a memory block
struct MemoryBlock {
    int id;             // Process ID using this block
    int size;           // Size of the memory block
    bool allocated;     // Flag to indicate if the block is allocated
};

// Function to simulate First Fit memory allocation algorithm
void firstFit(vector<MemoryBlock>& memory, int pid, int size) {
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size) {
            memory[i].id = pid;
            memory[i].allocated = true;
            break;
        }
    }
}

// Function to simulate Best Fit memory allocation algorithm
void bestFit(vector<MemoryBlock>& memory, int pid, int size) {
    int bestFitIndex = -1;
    int minRemainingSize = INT8_MAX;
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size) {
            int remainingSize = memory[i].size - size;
            if (remainingSize < minRemainingSize) {
                bestFitIndex = i;
                minRemainingSize = remainingSize;
            }
        }
    }
    if (bestFitIndex != -1) {
        memory[bestFitIndex].id = pid;
        memory[bestFitIndex].allocated = true;
    }
}

// Function to simulate Worst Fit memory allocation algorithm
void worstFit(vector<MemoryBlock>& memory, int pid, int size) {
    int worstFitIndex = -1;
    int maxRemainingSize = INT8_MIN;
    for (int i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= size) {
            int remainingSize = memory[i].size - size;
            if (remainingSize > maxRemainingSize) {
                worstFitIndex = i;
                maxRemainingSize = remainingSize;
            }
        }
    }
    if (worstFitIndex != -1) {
        memory[worstFitIndex].id = pid;
        memory[worstFitIndex].allocated = true;
    }
}

// Function to print the memory blocks and their allocation status
void printMemory(vector<MemoryBlock>& memory) {
    cout << "Memory Block\tSize\tAllocated\tProcess ID" << endl;
    for (int i = 0; i < memory.size(); ++i) {
        cout << i << "\t\t" << memory[i].size << "\t" 
             << (memory[i].allocated ? "Yes" : "No") << "\t\t" 
             << (memory[i].allocated ? to_string(memory[i].id) : "") << endl;
    }
    cout << endl;
}

int main() {
    int memorySize, numProcesses;
    cout << "Enter memory size: ";
    cin >> memorySize;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<MemoryBlock> memory(memorySize, {0, 0, false});

    for (int i = 1; i <= numProcesses; ++i) {
        int size;
        cout << "Enter size of process " << i << ": ";
        cin >> size;
        cout << "Allocating process " << i << " using First Fit algorithm" << endl;
        firstFit(memory, i, size);
        printMemory(memory);
        cout << "Allocating process " << i << " using Best Fit algorithm" << endl;
        bestFit(memory, i, size);
        printMemory(memory);
        cout << "Allocating process " << i << " using Worst Fit algorithm" << endl;
        worstFit(memory, i, size);
        printMemory(memory);
    }

    return 0;
}
