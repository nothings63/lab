#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n, head, totalSeek = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    sort(requests, n);

    int left = 0, right = 0;
    while (right < n && requests[right] < head)
        right++;
    left = right - 1;

    printf("Seek sequence is: ");
    while (left >= 0 || right < n) {
        if (right >= n || (left >= 0 && abs(requests[left] - head) <= abs(requests[right] - head))) {
            totalSeek += abs(requests[left] - head);
            head = requests[left--];
        } else {
            totalSeek += abs(requests[right] - head);
            head = requests[right++];
        }
        printf("%d ", head);
    }
    printf("\nTotal seek time: %d\n", totalSeek);

    return 0;
}
