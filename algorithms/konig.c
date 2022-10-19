//
// Created by algasami on 2022/10/19.
//
#include <stdio.h>
#include <string.h>

#define SIZE 100001
int possibleConnection[SIZE][SIZE], path[SIZE], seen[SIZE];
int xSize, ySize;

// 將x_i連結至y_j
int match(int currentNode) {
    for (int q = 1; q <= ySize; q++) {
        if (possibleConnection[currentNode][q] && seen[q] == 0) {
            seen[q] = 1; // 代表在這一個節點循環時，標記已尋找的y_j節點

            // match(path[q])在seen[q]=1後代表著除了現在的解以外，
            // 目前佔據q的x_i有另解，故可將節點佔有。
            if (path[q] == 0 || match(path[q])) {
                path[q] = currentNode;
                return q;
            }
        }
    }
    return 0;
}

int konig() {
    int edge = 0;
    for (int p = 1; p <= xSize; p++) {
        memset(seen, 0, sizeof(int) * SIZE);
        int q = match(p);
        if (q) {
            printf("%d->%d\n", p, q);
            edge++;
        }
    }
    return edge;
}

int main() {
    int k;
    scanf("%d", &xSize);
    scanf("%d", &ySize);
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        possibleConnection[x][y] = 1;
    }
    printf("%d least edges", konig());
    return 0;
}

/*
 3 3 4
 1 1
 1 2
 2 3
 3 1
 */