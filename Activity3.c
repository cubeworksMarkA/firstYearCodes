#include <stdio.h>

int main() {
    int num;

    printf("Enter a number from -100 to 100:");
    scanf("%d", &num);
if (num < -100 || num > 100) {
    printf("Out of Bounce");
}
    else if (num == 0) {
        printf("0 is neither even nor odd");
    }
    else {
        if (num % 2 == 0) {
            printf("Number %d is even", num);
        }
        else {
            printf("Number %d is odd", num);
        }
    }
return 0;

}