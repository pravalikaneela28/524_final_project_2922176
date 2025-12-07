/*
Merge Sort Implementation in C
Author: Pravalika Neela
CSU ID: 2922716

Scenario:
- Each "server" has its own log file.
- Each log entry is a timestamp (integer).
- We read timestamps from multiple servers, combine them
  into a single array, and then sort them using Merge Sort
  to simulate merging log files from different servers.
*/

#include <stdio.h>
#include <stdlib.h>

/* Merge two sorted halves: a[l..m] and a[m+1..r] */
void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

/* Recursive Merge Sort on a[l..r] */
void merge_sort(int *a, int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int num_servers;

    printf("=== Merge Sort Log Merger (C) ===\n");
    printf("Enter number of servers (log files): ");
    if (scanf("%d", &num_servers) != 1 || num_servers <= 0) {
        printf("Invalid number of servers.\n");
        return 0;
    }

    int total_entries = 0;

    /* First pass: ask how many entries each server has */
    int *entries_per_server = malloc(num_servers * sizeof(int));
    if (entries_per_server == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for (int s = 0; s < num_servers; s++) {
        printf("\nServer %d:\n", s + 1);
        printf("  Enter number of log entries for this server: ");
        if (scanf("%d", &entries_per_server[s]) != 1 || entries_per_server[s] < 0) {
            printf("Invalid entry count.\n");
            free(entries_per_server);
            return 0;
        }
        total_entries += entries_per_server[s];
    }

    /* Allocate combined array for all timestamps */
    int *timestamps = malloc(total_entries * sizeof(int));
    if (timestamps == NULL) {
        printf("Memory allocation failed.\n");
        free(entries_per_server);
        return 0;
    }

    /* Second pass: read all timestamps */
    int index = 0;
    for (int s = 0; s < num_servers; s++) {
        if (entries_per_server[s] == 0) continue;

        printf("  Enter %d timestamps for server %d (space-separated): ",
               entries_per_server[s], s + 1);

        for (int i = 0; i < entries_per_server[s]; i++) {
            scanf("%d", &timestamps[index++]);
        }
    }

    printf("\nCombined timestamps from all servers (unsorted):\n");
    for (int i = 0; i < total_entries; i++) {
        printf("%d ", timestamps[i]);
    }
    printf("\n");

    /* Sort all timestamps together using Merge Sort */
    merge_sort(timestamps, 0, total_entries - 1);

    printf("\nMerged & sorted timestamps (across all servers):\n");
    for (int i = 0; i < total_entries; i++) {
        printf("%d ", timestamps[i]);
    }
    printf("\n");

    free(entries_per_server);
    free(timestamps);
    return 0;
}