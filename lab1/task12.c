#include <stdio.h>
#include <stdbool.h>

/* Рекурсивно визначити, чи є задане число ступенем двійки. */

bool is_power_of_two(int *n) {
    if (*n == 0) {
        return true;
    }
    else if (*n == 1){
        return false;
    }
    else {
        *n = *n - 2;
        return is_power_of_two(n);
    }
}

int makePositive(int *n) {
    if (*n < 0) {
        *n = -*n;
    }
}

int main() {
    int n;
    printf("Input a number :\n");
    scanf("%d", &n);
    makePositive(&n);
    bool result = is_power_of_two(&n);
    printf("%d\n", result);
    return 0;
}