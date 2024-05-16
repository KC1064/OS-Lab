#include <stdio.h>
#include <limits.h>

void main() {
    int at[20], bt[20], rt[20], wt[20], tat[20], p[20];
    int i, j, n, time, smallest;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;
    int end_time, remain;
    int flag = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Remaining time is initially burst time
        p[i] = i + 1; // Process number
    }

    printf("\nProcess_id\tArrival_time\tBurst_time\tWaiting_time\tTurnaround_time\n");

    for(time = 0; remain != 0;) {
        smallest = n;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && (smallest == n || rt[i] < rt[smallest])) {
                smallest = i;
            }
        }

        if(smallest == n) {
            time++;
            continue;
        }

        rt[smallest]--;

        if(rt[smallest] == 0) {
            remain--;
            end_time = time + 1;
            wt[smallest] = end_time - at[smallest] - bt[smallest];
            tat[smallest] = end_time - at[smallest];

            printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[smallest], at[smallest], bt[smallest], wt[smallest], tat[smallest]);

            total_wt += wt[smallest];
            total_tat += tat[smallest];
        }
        time++;
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
}
