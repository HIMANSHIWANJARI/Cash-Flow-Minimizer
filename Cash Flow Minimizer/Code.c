#include <stdio.h>
#include <string.h>

#define MAX_PARTICIPANTS 100
#define MAX_NAME_LENGTH 50

// Function to find the index of the minimum value in arr[]
int getMin(int arr[], int n) {
    int minInd = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[minInd]) {
            minInd = i;
        }
    }
    return minInd;
}

// Function to find the index of the maximum value in arr[]
int getMax(int arr[], int n) {
    int maxInd = 0;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[maxInd]) {
            maxInd = i;
        }
    }
    return maxInd;
}

// Function to return the minimum of two values
int minOf2(int x, int y) {
    return (x < y) ? x : y;
}

// Function to minimize cash flow among participants
void minCashFlow(int graph[][MAX_PARTICIPANTS], int n, char names[][MAX_NAME_LENGTH]) {
    int amount[MAX_PARTICIPANTS] = {0};
    int p, i;

    // Calculate the net amount to be paid to each person
    for (p = 0; p < n; p++) {
        for (i = 0; i < n; i++) {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }

    while (1) {
        int mxCredit = getMax(amount, n);
        int mxDebit = getMin(amount, n);

        if (amount[mxCredit] == 0 && amount[mxDebit] == 0) {
            break;
        }

        int min = minOf2(-amount[mxDebit], amount[mxCredit]);
        amount[mxCredit] -= min;
        amount[mxDebit] += min;

        printf("%s pays %d to %s\n", names[mxDebit], min, names[mxCredit]);
    }
}

int main() {
    int n;
    char names[MAX_PARTICIPANTS][MAX_NAME_LENGTH];
    int graph[MAX_PARTICIPANTS][MAX_PARTICIPANTS];
    int i, j;

    printf("Enter the number of participants (up to %d): ", MAX_PARTICIPANTS);
    scanf("%d", &n);

    if (n < 2 || n > MAX_PARTICIPANTS) {
        printf("Invalid number of participants.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the name of participant %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("Enter the transaction amounts:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("%s owes %s: ", names[i], names[j]);
                scanf("%d", &graph[i][j]);
            } else {
                graph[i][j] = 0;
            }
        }
    }

    printf("Optimizing cash flow:\n");
    minCashFlow(graph, n, names);

    return 0;
}
