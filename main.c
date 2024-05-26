#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int authenticate(const char *username, const char *password);

int main()
{
    system("figlet Student Management Hub");
    printf("1. Login\n2. New User\nPlease enter input: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        char username[50], password[50];
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        if (authenticate(username, password))
        {
            system("clear || cls");
            printf("Login successful!\n");
        }
        else
        {
            printf("Invalid username or password.\n");
        }
    }
    else if (choice == 2)
    {
        printf("New user registration not implemented yet.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}

int authenticate(const char *username, const char *password)
{
    FILE *file = fopen("auth.txt", "r");
    if (!file)
    {
        perror("Unable to open auth file");
        return 0;
    }

    char file_username[50];
    char file_password[50];
    int line = 0;
    while (fgets(file_username, sizeof(file_username), file) && fgets(file_password, sizeof(file_password), file))
    {
        file_username[strcspn(file_username, "\n")] = 0;
        file_password[strcspn(file_password, "\n")] = 0;

        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
