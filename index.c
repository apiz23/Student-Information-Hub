#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "authenticate.h"
#include "student.h"
#include "course.h"

char userMatric[12];

int inputVal(int input, int startRange, int endRange)
{
    return (input >= startRange && input <= endRange) ? 0 : 1;
}

int menu(int type)
{
    int choice = 0, stop = 1;

    do
    {
        loadStudentData();
        loadCourses();
        if (type == 1)
        {
            do
            {
                printf("\n1. View Profile\n2. View Courses\n3. Add Course\n4. Remove Course\n5. Generate Profile & Courses list\nPlease choose a number between 1-5 only: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    readStudentByMatric(userMatric);
                    break;
                case 2:
                    system("clear || cls");
                    system("figlet List Courses");
                    readCourseBasedMatric(userMatric);
                    break;
                case 3:
                    addCourseStd(userMatric);
                    break;
                case 4:
                    system("clear || cls");
                    system("figlet Delete Course");
                    deleteCourseStd(userMatric);
                    break;
                case 5:
                    system("clear || cls");
                    system("figlet Report");
                    generateReportStd(userMatric);
                    generateReportCourses(userMatric);
                    break;
                default:
                    break;
                }
            } while (inputVal(choice, 1, 5));
        }
        else
        {
            do
            {

                printf("\n1. View Student\n2. View Courses\n3. Add Courses\n4. Delete Courses\n5. Generate Report\nPlease choose a number between 1-5 only: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    readStudents();
                    break;
                case 2:
                    system("clear || cls");
                    system("figlet List Courses");
                    readCourses();
                    break;
                case 3:
                    char newSubject[30];
                    system("clear || cls");
                    system("figlet New Course");
                    printf("Enter new subject: ");
                    scanf("%s", &newSubject);
                    appendCourse(newSubject);
                    break;
                case 4:
                    system("clear || cls");
                    system("figlet Delete Course");
                    deleteCourse(userMatric);
                    break;
                case 5:
                    system("clear || cls");
                    system("figlet Report Student");
                    generateStdReportAdmin();
                    generateCourseReportAdmin();
                    break;
                default:
                    break;
                }
            } while (inputVal(choice, 1, 5));
        }

        printf("\nDo you want to EXIT system (1: Yes, 0: No): ");
        scanf("%d", &stop);

        system("clear || cls");
    } while (stop == 0);
    return 0;
}

int main()
{
    system("clear || cls");
    char matric[50], password[50], new_matric[50], new_password[50];
    system("figlet Student Management Hub");
    printf("No Matric: ");
    scanf("%s", &matric);
    printf("Password: ");
    scanf("%s", &password);

    const int typeLogin = authenticate(matric, password);

    if (typeLogin)
    {
        system("clear || cls");
        strcpy(userMatric, matric);
        menu(typeLogin);
    }
    else
    {
        printf("Invalid no matric or password.\n");
    }

    return 0;
}