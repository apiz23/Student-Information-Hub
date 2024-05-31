#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char courses[20][50];
int courseChoose = 0;

void readCourses()
{
    FILE *file = fopen("courses.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < 20)
    {
        printf("%d. %s", i + 1, line);
        line[strcspn(line, "\n")] = '\0';
        strcpy(courses[i], line);
        i++;
    }
}

void readCourseBasedMatric(const char *matricNumber)
{
    FILE *file = fopen("courseStd.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    char currentMatric[50] = "";
    int found = 0;

    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, matricNumber) == 0)
        {
            found = 1;
            strcpy(currentMatric, line);
            continue;
        }
        if (found && line[0] != '\0')
        {
            printf("%d. %s\n", i + 1, line);
            i++;
        }
        if (line[0] == '\0' && strcmp(currentMatric, matricNumber) == 0)
        {
            break;
        }
    }

    fclose(file);
}

void appendCourse(const char *course)
{
    FILE *file = fopen("courses.txt", "a");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "%s\n", course);
    fclose(file);
}

void deleteCourse()
{
    readCourses();
    printf("\nEnter the number corresponding to the subject to delete: ");
    scanf("%d", &courseChoose);
    getchar();

    if (courseChoose < 1 || courseChoose > 20)
    {
        printf("Invalid selection.\n");
        return;
    }

    FILE *file = fopen("courses.txt", "w");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }
    fclose(file);

    file = fopen("courses.txt", "a");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < 20; ++i)
    {
        if (i != courseChoose - 1 && courses[i][0] != '\0')
            fprintf(file, "%s\n", courses[i]);
    }
}

void addCourseStd(const char *matricNumber)
{
    system("clear || cls");
    FILE *file = fopen("courseStd.tmp", "w");
    FILE *originalFile = fopen("courseStd.txt", "r");
    if (file == NULL || originalFile == NULL)
    {
        printf("Error opening file.\n");
        if (file)
            fclose(file);
        if (originalFile)
            fclose(originalFile);
        return;
    }

    system("figlet Available Courses");
    readCourses();

    puts("");

    system("figlet Your Courses");
    readCourseBasedMatric(matricNumber);
    printf("Enter No to add the course: ");
    scanf("%d", &courseChoose);

    if (courseChoose < 1 || courseChoose > 20 || courses[courseChoose - 1][0] == '\0')
    {
        printf("Invalid course number.\n");
        fclose(file);
        fclose(originalFile);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), originalFile) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, matricNumber) == 0)
        {
            found = 1;
        }

        if (found && (line[0] == '\0' || feof(originalFile)))
        {
            fprintf(file, "%s\n", courses[courseChoose - 1]);
            found = 0;
        }
        fprintf(file, "%s\n", line);
    }

    if (found)
    {
        fprintf(file, "%s\n", courses[courseChoose - 1]);
    }

    fclose(file);
    fclose(originalFile);

    remove("courseStd.txt");
    rename("courseStd.tmp", "courseStd.txt");
}

void deleteCourseStd(const char *matricNumber)
{
    int courseNumber;
    system("figlet Delete Course");
    readCourseBasedMatric(matricNumber);
    printf("Enter the number of the subject to delete: ");
    scanf("%d", &courseNumber);

    FILE *file = fopen("courseStd.tmp", "w");
    FILE *originalFile = fopen("courseStd.txt", "r");
    if (file == NULL || originalFile == NULL)
    {
        printf("Error opening file.\n");
        if (file)
            fclose(file);
        if (originalFile)
            fclose(originalFile);
        return;
    }

    char line[100];
    int found = 0;
    int courseCount = 0;
    while (fgets(line, sizeof(line), originalFile) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, matricNumber) == 0)
        {
            found = 1;
            courseCount = 0;
        }
        if (found && line[0] != '\0' && strcmp(line, matricNumber) != 0)
        {
            courseCount++;
            if (courseCount == courseNumber)
            {
                continue;
            }
        }
        if (line[0] == '\0' && found)
        {
            found = 0;
        }
        fprintf(file, "%s\n", line);
    }

    fclose(file);
    fclose(originalFile);

    remove("courseStd.txt");
    rename("courseStd.tmp", "courseStd.txt");
}