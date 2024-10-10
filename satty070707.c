#include <stdio.h>

#define NUM_ACCOUNTS 3

// Function prototypes
void displayMenu();
void deposit(float accounts[], int accountIndex);
void withdraw(float accounts[], int accountIndex);
void checkBalance(float accounts[], int accountIndex);

int main() {
    float accounts[NUM_ACCOUNTS] = {0.0, 0.0, 0.0};
    int choice, accountIndex;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Choose account (1-3): ");
            scanf("%d", &accountIndex);
            accountIndex--;

    
            if (accountIndex < 0 || accountIndex >= NUM_ACCOUNTS) {
                printf("Invalid account number. Please try again.\n");
                continue;
            }
        }

        switch (choice) {
            case 1:
                deposit(accounts, accountIndex);
                break;
            case 2:
                withdraw(accounts, accountIndex);
                break;
            case 3:
                checkBalance(accounts, accountIndex);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Banking Menu ---\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
}

void deposit(float accounts[], int accountIndex) {
    float amount;
    printf("Enter amount to deposit into account %d: ", accountIndex + 1);
    scanf("%f", &amount);
    
    if (amount > 0) {
        accounts[accountIndex] += amount;
        printf("Successfully deposited $%.2f into account %d.\n", amount, accountIndex + 1);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(float accounts[], int accountIndex) {
    float amount;
    printf("Enter amount to withdraw from account %d: ", accountIndex + 1);
    scanf("%f", &amount);

    if (amount > 0 && amount <= accounts[accountIndex]) {
        accounts[accountIndex] -= amount;
        printf("Successfully withdrew $%.2f from account %d.\n", amount, accountIndex + 1);
    } else {
        printf("Invalid withdrawal amount or insufficient balance.\n");
    }
}

void checkBalance(float accounts[], int accountIndex) {
    printf("The balance in account %d is $%.2f.\n", accountIndex + 1, accounts[accountIndex]);
}