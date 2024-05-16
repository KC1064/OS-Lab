#include <stdio.h>

int main() {
    int i, n, time, remain, flag = 0, tq;
    int at[20], bt[20], rt[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process Number %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\t| Turnaround Time | Waiting Time\n");
    printf("-----------------------------------------\n");

    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            tat[i] = time - at[i];
            wt[i] = tat[i] - bt[i];
            printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, tat[i], wt[i]);
            total_wt += wt[i];
            total_tat += tat[i];
            flag = 0;
        }

        if (at[(i + 1) % n] <= time) {
            i = (i + 1) % n;
        } else {
            for (int k = 1; k < n; k++) {
                if (at[(i + k) % n] <= time) {
                    i = (i + k) % n;
                    break;
                }
            }
            if (rt[i] > 0) {
                time++;
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}

