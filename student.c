#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char matric[50];
    char program[50];
    int year;
} Student;

Student students[20];
int studentCount = 0;

void loadStudentData()
{
    FILE *file = fopen("./files/student.txt", "r");
    if (!file)
    {
        printf("Error opening file\n");
        return;
    }

    studentCount = 0;
    while (fscanf(file, "%49s\n%49s\n%49s\n%d\n\n", students[studentCount].name, students[studentCount].matric, students[studentCount].program, &students[studentCount].year) == 4)
    {
        studentCount++;
        if (studentCount >= 20)
        {
            break;
        }
    }

    fclose(file);
}

void readStudents()
{
    system("clear || cls");
    system("figlet All Students");

    for (int i = 0; i < studentCount; i++)
    {
        printf("Name: %s\nMatric: %s\nProgram: %s\nYear: %d\n\n", students[i].name, students[i].matric, students[i].program, students[i].year);
    }
    getchar();
}

void readStudentByMatric(const char *matricNumber)
{
    system("clear || cls");
    system("figlet Profile");

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].matric, matricNumber) == 0)
        {
            printf("Name: %s\nMatric: %s\nProgram: %s\nYear: %d\n\n", students[i].name, students[i].matric, students[i].program, students[i].year);
            break;
        }
    }
    getchar();
}

void generateReportStd(const char *matricNumber)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].matric, matricNumber) == 0)
        {
            printf("-----------------------------------------\n| Name: %-20s\t\t|\n| Matric: %-20s\t\t|\n| Program: %-20s\t\t|\n| Year: %-20d\t\t|\n-----------------------------------------\n", students[i].name, students[i].matric, students[i].program, students[i].year);
            break;
        }
    }
}

void generateStdReportAdmin()
{
    int totalStudents = 0;
    int courseCounts[3] = {0, 0, 0};
    int yearCounts[3] = {0, 0, 0};

    for (int i = 0; i < studentCount; i++)
    {
        totalStudents++;
        if (strcmp(students[i].program, "BIP") == 0)
        {
            courseCounts[0]++;
        }
        else if (strcmp(students[i].program, "BIW") == 0)
        {
            courseCounts[1]++;
        }
        else if (strcmp(students[i].program, "BIT") == 0)
        {
            courseCounts[2]++;
        }

        if (students[i].year == 1)
        {
            yearCounts[0]++;
        }
        else if (students[i].year == 2)
        {
            yearCounts[1]++;
        }
        else if (students[i].year == 3)
        {
            yearCounts[2]++;
        }
    }

    printf("Total number of students: %d\n", totalStudents);
    printf("Number of students in each course:\n");
    printf("BIP: %d\n", courseCounts[0]);
    printf("BIW: %d\n", courseCounts[1]);
    printf("BIT: %d\n", courseCounts[2]);

    printf("Number of students in each year:\n");
    printf("Year 1: %d\n", yearCounts[0]);
    printf("Year 2: %d\n", yearCounts[1]);
    printf("Year 3: %d\n", yearCounts[2]);
}

void addStudent()
{
    char details[6][50];

    printf("Enter your name: ");
    scanf("%49s", details[0]);

    printf("Enter your matric number: ");
    scanf("%10s", details[1]);

    printf("Enter your username: ");
    scanf("%49s", details[2]);

    printf("Enter your password: ");
    scanf("%49s", details[3]);

    printf("Enter your program: ");
    scanf("%49s", details[4]);

    printf("Enter your year: ");
    scanf("%s", details[5]);

    FILE *studentFile = fopen("./files/student.txt", "a");
    if (studentFile == NULL)
    {
        printf("Error opening student.txt file!\n");
        return;
    }

    fprintf(studentFile, "\n%s\n%s\n%s\n%s", details[0], details[1], details[4], details[5]);
    fclose(studentFile);

    FILE *authFile = fopen("./files/auth.txt", "a");
    if (authFile == NULL)
    {
        printf("Error opening auth.txt file!\n");
        return;
    }

    fprintf(authFile, "\n%s\n%s", details[2], details[3]);
    fclose(authFile);
}
