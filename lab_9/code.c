#include <stdio.h>

// Variant 24

int sign(int a) {
    if (a > 0) return 1;
    if (a == 0) return 0;
    return -1;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int max(int a, int b) {
    if (a < b) return b;
    return a;
}

int abs(int b) {
    if (b < 0) b *= -1;
    return b;
}

int EvkMod(int a, int b) {
    int r = a - b * (a/b);
    if (r < 0) r += abs(b);
    return r;
}

int EvkDiv(int a, int b) {
    int r = EvkMod(a, b);
    return (a - r) / b;
}

int CheckPoint(int ax, int ay, int bx, int by, int cx, int cy, int px, int py) {
    int a = (ax-px)*(by-ay)-(bx-ax)*(ay-py);
    int b = (bx-px)*(cy-by)-(cx-bx)*(by-py);
    int c = (cx-px)*(ay-cy)-(ax-cx)*(cy-py);
    int as = sign(a), bs = sign(b), cs = sign(c);
    return (!a || !b || !c) || (as == bs && as == cs && bs == cs);
}

int main() {
    const int i0=20, j0=0, l0=11, ax=-10, ay=0, bx=0, by=10, cx=-10, cy=20;
    int i = i0, j = j0, l = l0, k = 0, i_next, j_next;
    for (;k <= 50;k++){
        i_next = EvkMod((i-k)*max(j, l) + (j-k)*min(i, l) + (l-k)*max(i,j), 23);
        j_next = EvkMod(-((i-k)*min(j, l) + (j-k)*max(i, l) + (l-k)*min(i,j)), 27);
        l = abs(i+j-l-k)*sign(i-j+l-k);
        i = i_next;
        j = j_next;
        if (CheckPoint(ax, ay, bx, by, cx, cy, i, j)) break;
    }
    if (k <= 50) printf("The point hit the area in the step %d", k);
    else printf("The point didn't hit the area");
    printf("\nEnd time of the movement - %d. Coordinates of the end point - (%d, %d). The value of dynamic parameter - %d\n", k, i, j, l);
    return 0;
}
