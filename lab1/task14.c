#include <stdio.h>


void towers(int n, char current, char target, char temp) {
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", current, target);
        return;
    }
    towers(n-1, current, temp, target);
    printf("\n Move disk %d from rod %c to rod %c", n, current, target);
    towers(n-1, temp, target, current);
}

int main() {
    int n;
    printf("Input a number :\n");
    scanf("%d", &n);

    char rods[] = {'A', 'B', 'C'};

    towers(n, rods[0], rods[1], rods[2]);

    return 0;
}