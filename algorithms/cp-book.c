//
// Created by algasami on 2022/12/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long recursiveBinPow(long long base, long long power) {
    if (base == 0) {
        return 0;
    }
    long long result = recursiveBinPow(base, power / 2);
    if (power % 2) {
        return result * result * power;
    } else {
        return result * result;
    }
}

/*
 * base = 2 (10)
 * power = 3 (11)
 * result = 8(1000)
 */
long long binPow(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (base & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }
    return result;
}

int id[52];

char *poker[] = {
        "Spade 黑桃",
        "Heart 紅心",
        "Diamond 方塊",
        "Club 梅花"
};
// J = 11 Q = 12 K = 13
char *points[] = {
};

void printCard(int index) {
    int val = id[index];
    printf("%s\t", poker[val / 13]);
    if (val % 13 > 10) {
        printf("%c\n", (val % 13) - 11 + 'J');
        return;
    }
    printf("%d\n", val % 13 + 1);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 52; i++) {
        id[i] = i;
    }
    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52;
        int tmp = id[randomIndex];
        id[randomIndex] = id[i];
        id[i] = tmp;
    }
    for (int i = 0; i < 52; i++) {
        if (!((i) % 13)) {
            printf("----玩家Person %d----\n", (i / 13) + 1);
        }
        printCard(i);
    }
    // printf("%lld", binPow(2, 3));
    return 0;
}