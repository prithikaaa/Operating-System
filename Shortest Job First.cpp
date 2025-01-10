void sjf(vector<Process>& processes) {
    auto compare = [](const Process& p1, const Process& p2) {
        return p1.burst > p2.burst;
    };
    priority_queue<Process, vector<Process>, decltype(compare)> pq(compare);
    int currentTime = 0;
    cout << "SJF Scheduling:" << endl;
    size_t index = 0;
    while (!pq.empty() || index < processes.size()) {
        while (index < processes.size() && processes[index].arrival <= currentTime) {
            pq.push(processes[index]);
            index++;
        }
        if (!pq.empty()) {
            Process next = pq.top();
            pq.pop();
            currentTime += next.burst;
            cout << "Process " << next.id << " starts at time " << currentTime - next.burst << endl;
            cout << "Process " << next.id << " finishes at time " << currentTime << endl;
        } else {
            currentTime = processes[index].arrival;
        }
    }
}
