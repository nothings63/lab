#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void scanDiskScheduling(int requests[], int n, int head, int diskSize, int direction) {
    int distance = 0;
    int curTrack;
    int seekSequence[MAX];
    int visited[MAX] = {0};
    int totalSeekCount = 0;
    int index = 0;

    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Find the closest track in the direction
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            index = i;
            break;
        }
    }

    if (direction == 1) { // Move towards the end
        for (int i = index; i < n; i++) {
            curTrack = requests[i];
            seekSequence[distance++] = curTrack;
            totalSeekCount += abs(curTrack - head);
            head = curTrack;
        }
        head = diskSize - 1;
        totalSeekCount += abs(head - seekSequence[distance - 1]);
        for (int i = index - 1; i >= 0; i--) {
            curTrack = requests[i];
            seekSequence[distance++] = curTrack;
            totalSeekCount += abs(curTrack - head);
            head = curTrack;
        }
    } else { // Move towards the beginning
        for (int i = index - 1; i >= 0; i--) {
            curTrack = requests[i];
            seekSequence[distance++] = curTrack;
            totalSeekCount += abs(curTrack - head);
            head = curTrack;
        }
        head = 0;
        totalSeekCount += abs(head - seekSequence[distance - 1]);
        for (int i = index; i < n; i++) {
            curTrack = requests[i];
            seekSequence[distance++] = curTrack;
            totalSeekCount += abs(curTrack - head);
            head = curTrack;
        }
    }

    printf("Total number of seek operations: %d\n", totalSeekCount);
    printf("Seek Sequence is:\n");
    for (int i = 0; i < distance; i++) {
        printf("%d ", seekSequence[i]);
    }
    printf("\n");
}

int main() {
    int n, head, diskSize, direction;
    int requests[MAX];

    printf("Enter the size of the disk: ");
    scanf("%d", &diskSize);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (1 for end, 0 for beginning): ");
    scanf("%d", &direction);

    scanDiskScheduling(requests, n, head, diskSize, direction);

    return 0;
}
