#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readStudents()
{
    system("clear || cls");
    system("figlet All Students");
    FILE *file = fopen("student.txt", "r");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    char name[50];
    char matric[50];
    char program[50];
    int year;

    while (fscanf(file, "%s\n%s\n%s\n%d\n\n", name, matric, program, &year) == 4)
    {
        printf("Name: %s\nMatric: %s\nProgram: %s\nYear: %d\n\n", name, matric, program, year);
    }
    getchar();

    fclose(file);
}

void readStudentByMatric(const char *matricNumber)
{
    system("clear || cls");
    system("figlet Profile");
    FILE *file = fopen("student.txt", "r");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    char name[50];
    char matric[50];
    char program[50];
    int year;

    while (fscanf(file, "%s\n%s\n%s\n%d\n\n", name, matric, program, &year) == 4)
    {
        if (strcmp(matric, matricNumber) == 0)
        {
            printf("Name: %s\nMatric: %s\nProgram: %s\nYear: %d\n\n", name, matric, program, year);
            break;
        }
    }
    getchar();

    fclose(file);
}