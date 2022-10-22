//
// Created by algasami on 10/22/2022.
//
#include <stdio.h>
#include <math.h>

int main() {
    // 1.
    printf("1.\n");
    for (int i = 0; i < 5; i++)
        printf("*");
    printf("\n");

    // 2.
    printf("2.\n");
    for (int i = 0; i < 5; i++)
        printf("*\n");

    // 3.
    printf("3.\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++)
            printf("*");
        printf("\n");
    }

    // 4.
    printf("4.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x <= y; x++)
            printf("*");
        printf("\n");
    }

    // 5.
    printf("5.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < y; x++)
            printf(" ");
        for (int x = 0; x < 5 - y; x++)
            printf("*");
        printf("\n");
    }

    // 6.
    printf("6.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 4 - y; x++)
            printf(" ");
        printf("*\n");
    }

    // 7.
    printf("7.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < y; x++)
            printf(" ");
        printf("*\n");
    }

    // 8.
    printf("8.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 4 - y; x++)
            printf(" ");
        for (int x = 0; x <= y; x++)
            printf("*");
        printf("\n");
    }

    // 9.
    printf("9.\n");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < y; x++)
            printf(" ");
        for (int x = 0; x <= 4 - y; x++)
            printf("*");
        printf("\n");
    }

    // 10.
    printf("10.\n");
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 5 - abs(4 - y); x++)
            printf("*");
        printf("\n");
    }

    // 11.
    printf("11.\n");
    for (int y = 0; y < 9; y++) {
        int n = abs(4 - y);
        for (int x = 0; x < n; x++)
            printf(" ");
        for (int x = 0; x < 5 - n; x++)
            printf("*");
        printf("\n");
    }

    // 12.
    printf("12.\n");
    for (int y = 0; y < 7; y++) {
        int n = abs(3 - y);
        for (int x = 0; x < n; x++)
            printf(" ");
        for (int x = 0; x < (4 - n) * 2 - 1; x++)
            printf("*");
        printf("\n");
    }

    // 13.
    printf("13.\n");
    printf("   *\n");
    for (int y = 0; y < 5; y++) {
        int n = abs(2 - y);
        for (int x = 0; x < n; x++)
            printf(" ");
        printf("*");
        for (int x = 0; x < (3 - n) * 2 - 1; x++)
            printf(" ");
        printf("*\n");
    }
    printf("   *\n");

    // 14.
    printf("14.\n");
    for (int y = 0; y < 7; y++) {
        int n = abs(3 - y);
        int r = (4 - n) * 2 - 1;
        for (int x = 0; x < n; x++)
            printf(" ");
        for (int x = 0; x < r; x++)
            printf("%d", r / 2 + 1 - abs(x - r / 2));
        printf("\n");
    }

    return 0;
}