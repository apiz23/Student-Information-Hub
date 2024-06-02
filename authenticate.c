#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int authenticate(const char *matric, const char *password)
{

    if (strcmp(matric, "admin") == 0 && strcmp(password, "12345") == 0)
    {
        return 2;
    }

    FILE *file = fopen("./files/auth.txt", "r");
    if (!file)
    {
        perror("Unable to open auth file");
        return 0;
    }

    char file_matric[50];
    char file_password[50];
    while (fgets(file_matric, sizeof(file_matric), file) && fgets(file_password, sizeof(file_password), file))
    {
        file_matric[strcspn(file_matric, "\n")] = 0;
        file_password[strcspn(file_password, "\n")] = 0;

        if (strcmp(matric, file_matric) == 0 && strcmp(password, file_password) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int addUser(const char *new_matric, const char *new_password)
{
    system("clear || cls\nfiglet Registration User");
    FILE *file = fopen("./files/auth.txt", "a");

    if (!file)
    {
        perror("Unable to open auth file");
        return 0;
    }

    fprintf(file, "%s\n%s\n", new_matric, new_password);
    fclose(file);
    return 1;
}