#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 85
#define MAX_USERNAME_LENGTH 17
#define MAX_PASSWORD_LENGTH 17

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userC = 0;

int registerUser() {
    if (userC >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return 0;
    }

    User newUser;

    printf("Enter username : ");
    scanf("%s", newUser.username);

    for (int i = 0; i < userC; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return 0;
        }
    }

    printf("Enter password : ");
    scanf("%s", newUser.password);

    users[userC++] = newUser;

    printf("Registration successful for user: %s\n", newUser.username);
    return 1;
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userC; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful for user: %s\n", username);
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;

    do {
        printf("******************************\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Logout\n");
        printf("******************************\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Logout is done...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}