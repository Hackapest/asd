#include <stdio.h>


int nsk(int a, int b) {
    static int res = 0;
    res = res + b;
    if ((res % a == 0) && (res % b == 0)) {
        return res;
    }
    else {
        return nsk(a, b);
    }
}

int main() {

    int a;
    int b;
    int res;

    printf("Input two numbers :\n");
    scanf("%d%d", &a, &b);

    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    if (a == b) {
        printf("result is %d", a);
    }

    if (a > b) {
        res = nsk(b, a);
        printf("result is %d", res);
    }
    else {
        res = nsk(a, b);
        printf("result is %d", res);
    }

    return 0;
}