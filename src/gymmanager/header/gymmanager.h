/**
 * @file gymmanager.h
 * 
 * @brief Provides functions for math. utilities
 */

#ifndef GYMMANAGER_H
#define GYMMANAGER_H

typedef struct {
    char username[50];
    char password[50];
} User;

int saveUser(const User* user, const char* filename);

int authenticateUser(const char* username, const char* password, const char* filename);

bool userAuthentication2();

#endif // GYMMANAGER_H