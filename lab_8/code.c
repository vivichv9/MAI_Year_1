#include <stdio.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {

    int count, digit1, digit2, sum, razn = 1000000;

    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%d%d", &digit1, &digit2);
        sum += max(digit1, digit2);
        if (max(digit1, digit2) - min(digit1, digit2) % 3 && max(digit1, digit2) - min(digit1, digit2) != 0) {
            razn = min(max(digit1, digit2) - min(digit1, digit2), razn);
        }
    }
    if (sum % 3 == 0) {
        printf("%d", sum - razn);
    } else {
        printf("%d", sum);
    }
    return 0;
}
