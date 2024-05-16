#include <stdio.h>

void main() {
    int at[20], bt[20], p[20], wt[20], tat[20], ct[20];
    int i, j, n, temp;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1; // Process number
    }

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival times
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process IDs
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate completion times and sort by burst time as they arrive
    int time = 0;
    for (i = 0; i < n; i++) {
        int shortest = i;
        for (j = i + 1; j < n && at[j] <= time; j++) {
            if (bt[j] < bt[shortest]) {
                shortest = j;
            }
        }

        // Swap the shortest job with the current job
        if (shortest != i) {
            // Swap arrival times
            temp = at[i];
            at[i] = at[shortest];
            at[shortest] = temp;

            // Swap burst times
            temp = bt[i];
            bt[i] = bt[shortest];
            bt[shortest] = temp;

            // Swap process IDs
            temp = p[i];
            p[i] = p[shortest];
            p[shortest] = temp;
        }

        if (time < at[i]) {
            time = at[i];
        }
        time += bt[i];
        ct[i] = time;
    }

    // Calculate waiting times and turnaround times
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProcess_id\tArrival_time\tBurst_time\tWaiting_time\tTurnaround_time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
}

