#include "../header/gymmanager.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <climits>

bool guestMode = false;
int budget;
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*Vvökvösdkvödskvmdskmvsmdsdkvms
vökfvöskdvö*/
int saveUser(const User* user, const char* filename) {
    FILE* file = fopen(filename, "ab");
    fwrite(user, sizeof(User), 1, file);
    fclose(file);
    return 1;
}

int authenticateUser(const char* username, const char* password, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }
    User user;
    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            fclose(file);
            return 1;
        }
    }
}

bool userAuthentication2() {
    clearScreen();
    const char* filename = "Users.bin";
    User user1 = { "Ahmet Bera Celik", "qwerty" };
    saveUser(&user1, filename);
    User user2 = { "Enes Koy", "123456" };
    saveUser(&user2, filename);
    User user3 = { "Ugur Coruh", "asdasd" };
    saveUser(&user3, filename);

    int choice;
    int right_to_try = 3;
    char temp_username[50];
    char temp_password[50];


    while (true) {
        clearScreen();
        printf("+---------------------------+\n");
        printf("|  LOGIN AND REGISTER MENU  |\n");
        printf("+---------------------------+\n");
        printf("| 1. Login                  |\n");
        printf("| 2. Register               |\n");
        printf("| 3. Guest Mode             |\n");
        printf("| 4. Exit Program           |\n");
        printf("+---------------------------+\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Please enter your username: ");
            fgets(temp_username, 50, stdin);
            temp_username[strcspn(temp_username, "\n")] = 0;

            printf("Please enter your password: ");
            fgets(temp_password, 50, stdin);
            temp_password[strcspn(temp_password, "\n")] = 0;

            printf("Please enter your budget: ");
            scanf("%d", &budget);

            getchar();

            if (authenticateUser(temp_username, temp_password, filename) == 1) {
                printf("Welcome %s\n", temp_username);

                getchar();

                return true;
            }
            else {
                printf("You entered wrong username or password. Please try again.\n");
                right_to_try--;
                if (right_to_try == 0) {
                    printf("You have run out of login attempts. See you...\n");
                    getchar();
                    return false;
                }
            }
            getchar();
            break;

        case 2:
            printf("Please enter your username: ");
            fgets(temp_username, 50, stdin);
            temp_username[strcspn(temp_username, "\n")] = 0;

            printf("Please enter your password: ");
            fgets(temp_password, 50, stdin);
            temp_password[strcspn(temp_password, "\n")] = 0;

            User newUser;
            strcpy(newUser.username, temp_username);
            strcpy(newUser.password, temp_password);
            saveUser(&newUser, filename);
            clearScreen();
            printf("User registered successfully.\nWelcome %s\n", temp_username);
            printf("Your budget is 100 tl.");
            budget = 100;
            getchar();
            return true;

        case 3:
            guestMode = true;
            return true;

        case 4:
            printf("Exiting program...Press enter!\n");
            getchar();
            return false;

        default:
            printf("Invalid option, please try again.\n");
            getchar();
        }
    }
}