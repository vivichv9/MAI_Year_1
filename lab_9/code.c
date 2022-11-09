#include <stdio.h>

int sign(int a) {
    if (a < 0) {
        return -1;
    } else if (a == 0) {
        return 0;
    } else {
        return 1;
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a < 0 ? a *= -1 : a;
}

int CheckPoint(int ax, int ay, int bx, int by, int cx, int cy, int px, int py) {
    int a = (ax-px)*(by-ay)-(bx-ax)*(ay-py);
    int b = (bx-px)*(cy-by)-(cx-bx)*(by-py);
    int c = (cx-px)*(ay-cy)-(ax-cx)*(cy-py);
    int as = sign(a), bs = sign(b), cs = sign(c);
    return (!a || !b || !c) || (as == bs && as == cs && bs == cs);
}

int main() {
    const int i0 = -8, j0 = -5,l0 = 12, ax = 10,ay = 0, bx = 0,by = 10,cx = -10, cy = 20;

    int i = i0, j = j0, l = l0, k = 0, n = 0;

    for (n = 0; n < 50; n++) {
        i = ((i * i) / (abs(j - l) + k + 1) - (j * j) / (abs(i - l) + k + 1)) % 30;
        j = sign(l) * min(i, j) - sign(j) * max(i, l) + k;
        l = ((i - j) * (j - l) * (l - i)) % 20;
        if (CheckPoint(ax, ay, bx, by, cx, cy, i, j)) break;
    }
    if (k <= 50) {
        printf("Точка попала в окрестность за %d шагов", n);
    } else {
        printf("Точка не попала в окресность");
    }
    printf("\nКонец движения точки - %d. Координаты конечной точки - (%d, %d). Значение динамического параметра - %d\n", n, i, j, l);

    return 0;
}
