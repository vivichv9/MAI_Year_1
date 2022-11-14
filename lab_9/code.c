#include <stdio.h>

int sign(int a) {
    if (a > 0) return 1;
    if (a == 0) return 0;
    return -1;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int abs(int b) {
    return b < 0 ?  b *= -1 : b;
}

int Mod(int a, int b) {
    int r = a - b * (a/b);
    return r < 0 ?  r += abs(b) : r;
}

/*
(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)Ы
 */

int CheckPoint(int ax, int ay, int bx, int by, int cx, int cy, int px, int py) {
    int a = (ax-px)*(by-ay)-(bx-ax)*(ay-py);
    int b = (bx-px)*(cy-by)-(cx-bx)*(by-py);
    int c = (cx-px)*(ay-cy)-(ax-cx)*(cy-py);
    int as = sign(a), bs = sign(b), cs = sign(c);
    return (!a || !b || !c) || (as == bs && as == cs && bs == cs);
}

int main() {
    const int i0=-8, j0=-5, l0=12, ax=-10, ay=0, bx=0, by=10, cx=-10, cy=20;
    int i = i0, j = j0, l = l0, k = 0, i_n, j_n;
    for (;k <= 50;k++) {
        i_n = Mod((i * i) / (abs(j - l) + k + 1) - (j * j) / (abs(i - l) + k + 1), 30);
        j_n = sign(l) * min(i, j) - sign(j) * max(i, l) + k;
        l = Mod((i - j) * (j - l) * (l - i), 20);
        i = i_n;
        j = j_n;
        if (CheckPoint(ax, ay, bx, by, cx, cy, i, j)) break;
    }
    if (k <= 50) printf("The point hit the area in the step %d", k);
    else printf("The point didn't hit the area");
    printf("\nEnd time of the movement - %d. Coordinates of the end point - (%d, %d). The value of dynamic parameter - %d\n", k, i, j, l);
    return 0;
}
