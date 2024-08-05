#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                printf("Process %d of size %d allocated to block %d\n", i + 1, processSize[i], j + 1);
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = 5, n = 4;
    firstFit(blockSize, m, processSize, n);
    return 0;
}
