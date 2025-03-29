#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int priority; // Priority
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
    int remaining_time; // Remaining time
};

void calculateTimes(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    int min_priority_index = -1;

    while (completed < n) {
        min_priority_index = -1;

        // Find the process with the highest priority at current time
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (min_priority_index == -1 || processes[i].priority < processes[min_priority_index].priority) {
                    min_priority_index = i;
                }
            }
        }

        // If no process is available, move to next time unit
        if (min_priority_index == -1) {
            current_time++;
            continue;
        }

        // Execute the process with highest priority for one time unit
        processes[min_priority_index].remaining_time--;
        current_time++;

        // If the process is completed
        if (processes[min_priority_index].remaining_time == 0) {
            completed++;
            processes[min_priority_index].completion_time = current_time;
            processes[min_priority_index].turnaround_time = processes[min_priority_index].completion_time - processes[min_priority_index].arrival_time;
            processes[min_priority_index].waiting_time = processes[min_priority_index].turnaround_time - processes[min_priority_index].burst_time;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);

        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n);

    // Calculate average turnaround time and average waiting time
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
