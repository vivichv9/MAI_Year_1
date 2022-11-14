#include <stdio.h>
#include <assert.h>

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

void test_min() {
    int x = 5;
    int y = 3;
    assert(min(x, y) == 3);

    x = 0;
    y = 20;
    assert(min(x, y) == 0);
}


int main() {
    test_min();

    int count, digit1, digit2, sum, razn = 1000000;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d%d", &digit1, &digit2);
        sum += max(digit1, digit2);
        if ((max(digit1, digit2) - min(digit1, digit2)) % 3 != 0) {
            razn = min(max(digit1, digit2) - min(digit1, digit2), razn);
        }
    }
    if (count != 0 && sum % 3 == 0) {
        printf("%d", sum - razn);
    } else if (count != 0 && sum % 3 != 0){
        printf("%d", sum);
    } else if (count == 0) {
        printf("%d", 0);
    }
    return 0;
}
