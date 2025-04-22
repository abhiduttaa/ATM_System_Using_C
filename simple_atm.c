#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CORRECT_PIN 1234

float balance = 1000.00; // Starting balance

void showMenu() {
    printf("\n--- ATM Menu ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void checkBalance() {
    printf("Your current balance is: R.S:%.2f\n", balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ₹");
    scanf("%f", &amount);
    if (amount > 0) {
        balance += amount;
        printf("R.S:%.2f deposited successfully!\n", amount);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ₹");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("R.S:%.2f withdrawn successfully!\n", amount);
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

int main() {
    int pin, choice;

    printf("Welcome to Simple ATM\n");
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &pin);

    if (pin != CORRECT_PIN) {
        printf("Incorrect PIN! Access denied.\n");
        return 1;
    }

    do {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: checkBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: printf("Thank you! Goodbye.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
