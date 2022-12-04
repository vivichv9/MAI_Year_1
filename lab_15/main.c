#include <stdio.h>

enum {maxn = 100};

void swap(int* a, int* b){
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int main(){
    int m[maxn][maxn];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        if (i == n-i-1){
            continue;
        } else {
            swap(&m[i][i], &m[i][n-i-1]);
        }

    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", m[i][j]);
        }
        putchar('\n');
    }
}
