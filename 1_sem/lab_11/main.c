#include <stdio.h>
#include <assert.h>

int count = 0;
int asc;

typedef enum {
    state0,
    state1,
} state;

int isSpace(char a){
    if (a == ' ') return 1;
    return 0;
}

int isRubbish(char a) {
    asc = (int) a;
    if (asc < 'a' || asc > 'z') {
        return 1;
    } else {
        return 0;
    }
}

int isEnd(char a) {
    asc = (int) a;
    if (asc + count + 3 > 'z') {
        return asc + count + 3;
    } else {
        return 0;
    }
}

char codeCaesar(char a) {
    asc = (int) a;
    int flag = isEnd(a);
    if (flag == 0) {
        return (char) (asc + count + 3);
    } else {
        return (char)  ('a' - 1 + (flag - 'z'));
    }
}

void testIsRubbish() {
    assert(isRubbish('\n') ==  1);
    assert(isRubbish('a') == 0);
}

void testCodeCaesar() {
    assert(codeCaesar('a') == 'd');
    assert(codeCaesar('z') == 'c');
}

void testIsEnd() {
    assert(isEnd('a') == 0);
    assert(isEnd('z') != 0);
}

void testAll() {
    testCodeCaesar();
    testIsEnd();
    testIsRubbish();
}

int main() {
    testAll();

    state currentState;
    currentState = state0;
    char c;
    count = 0;

    while ((c = getchar()) != EOF) {

        if (c == '\n') {
            break;
        }

        switch (currentState) {
            case state0:

                if (count == 'z' - 'a' - 3){
                    count = 0;
                }

                if (isRubbish(c)) {
                    count = 0;
                    printf("%c", ' ');
                    currentState = state0;
                } else {
                    currentState = state1;
                    count++;
                }
                break;
        }
        if (currentState == state1) {
            printf("%c", codeCaesar(c));
            currentState = state0;
        }
    }
    return 0;
}
