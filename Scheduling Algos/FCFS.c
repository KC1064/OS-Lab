#include <stdio.h>

void main() {
    float abt[100], process[100], at[100], bt[100], wt[100], tat[100];
    int i, j, n;
    float avg_wt = 0;
    float avg_tat = 0;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time and burst time for P_%d: ", i + 1);
        scanf("%f %f", &at[i], &bt[i]);
    }

    // Sort processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival times
                float temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process IDs
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    printf("P_ID\tAT\tBT\n");
    for(i = 0; i < n; i++) {
        printf("P_%.0f\t%.2f\t%.2f\n", process[i], at[i], bt[i]);
    }

    wt[0] = 0;
    abt[0] = at[0] + bt[0];
    tat[0] = bt[0];

    for(i = 1; i < n; i++) {
        if (abt[i - 1] < at[i]) {
            abt[i] = at[i] + bt[i];
        } else {
            abt[i] = abt[i - 1] + bt[i];
        }
        tat[i] = abt[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for(i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    if(n > 0) {
        avg_wt /= n;
        avg_tat /= n;
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turn Around Time: %.2f\n", avg_tat);
}

