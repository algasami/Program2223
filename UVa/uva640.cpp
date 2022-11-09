//
// Created by algasami on 2022/11/8.
//

// UVA 640

#include <bits/stdc++.h>

#define MaxN 1000000

using namespace std;
typedef unsigned int uint;

uint gen_map[MaxN] = {0};

uint get_sum(uint num) {
    if (num < 10) return num;
    return (num % 10) + get_sum(num / 10);
}

void get_sequence(uint i) {
    while (i <= MaxN) {
        uint next = i + get_sum(i);
        if (next >= MaxN || gen_map[next] != next) return;
        gen_map[next] = i;
        i = next;
    }
}

int main() {
    for (uint i = 1; i <= MaxN; i++) {
        gen_map[i] = i;
    }
    for (uint i = 1; i <= MaxN; i++) {
        get_sequence(i);
    }
    for (uint i = 1; i <= MaxN; i++) {
        if (gen_map[i] == i) printf("%d\n", i);
    }
    return 0;
}