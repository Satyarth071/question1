#include <stdio.h>

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    int decimalValue;
    printf("Enter a decimal value: ");
    scanf("%d", &decimalValue);
    
    printf("Decimal: %d\n", decimalValue);
    
    printf("Binary: ");
    decimalToBinary(decimalValue);
    printf("\n");
    
    printf("Octal: %o\n", decimalValue);
    
    printf("Hexadecimal: %X\n", decimalValue);

    return 0;
}
