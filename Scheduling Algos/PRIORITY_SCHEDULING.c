#include <stdio.h>

int main() {
    int at[20], bt[20], rt[20], p[20], pr[20], wt[20], tat[20], ct[20];
    int i, j, n, time, remain, smallest;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    remain = n;
    
    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time, Burst Time and Priority for Process P[%d]:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
        rt[i] = bt[i]; // Remaining time is initially the burst time
    }

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival times
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap priorities
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap remaining times
                temp = rt[i];
                rt[i] = rt[j];
                rt[j] = temp;

                // Swap process IDs
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    pr[19] = 10000; // A large number to represent the lowest priority

    for (time = 0, remain = 0; remain != n; time++) {
        smallest = 19;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && pr[i] < pr[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }

        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            ct[smallest] = time + 1;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            total_wt += wt[smallest];
            total_tat += tat[smallest];
        }
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nProcess\t    Arrival Time    Burst Time    Priority    Waiting Time    Turnaround Time");
    for (i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}

