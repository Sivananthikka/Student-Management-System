#include <stdio.h>

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[50];
    char department[50];
    int age;
    float marks1;
    float marks2;
    float marks3;
};

/* Function Prototypes */
float calculateAverage(struct Student student);
char calculateGrade(float average);
int getValidID();
int getValidAge();
float getValidMarks();
int isDuplicateID(struct Student students[], int count, int id);
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void studentStatistics(struct Student students[], int count);
void saveStudents(struct Student students[], int count);
void loadStudents(struct Student students[], int *count);

/* Calculate Student Average */
float calculateAverage(struct Student student)
{
    return (student.marks1 + student.marks2 + student.marks3) / 3;
}

/* Calculate Student Grade */
char calculateGrade(float average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

/* Get Valid Student ID */
int getValidID()
{
    int id;

    do
    {
        scanf("%d", &id);

        if (id <= 0)
        {
            printf("Invalid ID. Enter a positive ID: ");
        }

    } while (id <= 0);

    return id;
}

/* Get Valid Age */
int getValidAge()
{
    int age;

    do
    {
        scanf("%d", &age);

        if (age < 1 || age > 100)
        {
            printf("Invalid age. Enter age between 1 and 100: ");
        }

    } while (age < 1 || age > 100);

    return age;
}

/* Get Valid Marks */
float getValidMarks()
{
    float marks;

    do
    {
        scanf("%f", &marks);

        if (marks < 0 || marks > 100)
        {
            printf("Invalid marks. Enter marks between 0 and 100: ");
        }

    } while (marks < 0 || marks > 100);

    return marks;
}

/* Check if Student ID already exists */
int isDuplicateID(struct Student students[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}

/* Add Student */
void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    printf("Enter Student ID: ");
    students[*count].id = getValidID();

    while (isDuplicateID(students, *count, students[*count].id))
    {
        printf("Student ID already exists!\n");
        printf("Enter a different Student ID: ");
        students[*count].id = getValidID();
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", students[*count].department);

    printf("Enter Age: ");
    students[*count].age = getValidAge();

    printf("Enter marks for Subject 1: ");
    students[*count].marks1 = getValidMarks();

    printf("Enter marks for Subject 2: ");
    students[*count].marks2 = getValidMarks();

    printf("Enter marks for Subject 3: ");
    students[*count].marks3 = getValidMarks();

    (*count)++;

    printf("\nStudent added successfully!\n");
}

/* Display Students */
void displayStudents(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\n========== STUDENT LIST ==========\n");

    for (int i = 0; i < count; i++)
    {
        float average = calculateAverage(students[i]);
        char grade = calculateGrade(average);

        printf("\nStudent %d\n", i + 1);
        printf("ID         : %d\n", students[i].id);
        printf("Name       : %s\n", students[i].name);
        printf("Department : %s\n", students[i].department);
        printf("Age        : %d\n", students[i].age);
        printf("Subject 1  : %.2f\n", students[i].marks1);
        printf("Subject 2  : %.2f\n", students[i].marks2);
        printf("Subject 3  : %.2f\n", students[i].marks3);
        printf("Average    : %.2f\n", average);
        printf("Grade      : %c\n", grade);
    }

    printf("\n==================================\n");
}

/* Search Student */
void searchStudent(struct Student students[], int count)
{
    int id;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\nEnter Student ID to search: ");
    id = getValidID();

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            float average = calculateAverage(students[i]);
            char grade = calculateGrade(average);

            printf("\n--- Student Found ---\n");
            printf("Student ID : %d\n", students[i].id);
            printf("Name       : %s\n", students[i].name);
            printf("Department : %s\n", students[i].department);
            printf("Age        : %d\n", students[i].age);
            printf("Subject 1  : %.2f\n", students[i].marks1);
            printf("Subject 2  : %.2f\n", students[i].marks2);
            printf("Subject 3  : %.2f\n", students[i].marks3);
            printf("Average    : %.2f\n", average);
            printf("Grade      : %c\n", grade);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

/* Update Student */
void updateStudent(struct Student students[], int count)
{
    int id;
    int found = 0;

    if (count == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\nEnter Student ID to update: ");
    id = getValidID();

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\n--- Update Student ---\n");

            printf("Enter New Student Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Department: ");
            scanf(" %[^\n]", students[i].department);

            printf("Enter New Age: ");
            students[i].age = getValidAge();

            printf("Enter New marks for Subject 1: ");
            students[i].marks1 = getValidMarks();

            printf("Enter New marks for Subject 2: ");
            students[i].marks2 = getValidMarks();

            printf("Enter New marks for Subject 3: ");
            students[i].marks3 = getValidMarks();

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

/* Delete Student */
void deleteStudent(struct Student students[], int *count)
{
    int id;
    int found = 0;
    char confirmation;

    if (*count == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    printf("\nEnter Student ID to delete: ");
    id = getValidID();

    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found:\n");
            printf("Name       : %s\n", students[i].name);
            printf("Department : %s\n", students[i].department);

            printf("\nAre you sure you want to delete this student? (y/n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y' || confirmation == 'Y')
            {
                for (int j = i; j < *count - 1; j++)
                {
                    students[j] = students[j + 1];
                }

                (*count)--;

                printf("\nStudent deleted successfully!\n");
            }
            else
            {
                printf("\nDeletion cancelled.\n");
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

/* Student Statistics */
void studentStatistics(struct Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo students available.\n");
        return;
    }

    float totalAverage = 0;
    float highestAverage = 0;
    float lowestAverage = 0;
    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 0; i < count; i++)
    {
        float average = calculateAverage(students[i]);

        totalAverage = totalAverage + average;

        if (i == 0)
        {
            highestAverage = average;
            lowestAverage = average;
        }
        else
        {
            if (average > highestAverage)
            {
                highestAverage = average;
                highestIndex = i;
            }

            if (average < lowestAverage)
            {
                lowestAverage = average;
                lowestIndex = i;
            }
        }
    }

    printf("\n========== STUDENT STATISTICS ==========\n");
    printf("Total Students  : %d\n", count);
    printf("Class Average   : %.2f\n", totalAverage / count);

    printf("\nHighest Average  : %.2f\n", highestAverage);
    printf("Student Name     : %s\n", students[highestIndex].name);
    printf("Student ID       : %d\n", students[highestIndex].id);

    printf("\nLowest Average   : %.2f\n", lowestAverage);
    printf("Student Name     : %s\n", students[lowestIndex].name);
    printf("Student ID       : %d\n", students[lowestIndex].id);

    printf("\n========================================\n");
}

/* Save Students to File */
void saveStudents(struct Student students[], int count)
{
    FILE *file;

    file = fopen("students.dat", "wb");

    if (file == NULL)
    {
        printf("\nError: Unable to save student data.\n");
        return;
    }

    fwrite(students, sizeof(struct Student), count, file);

    fclose(file);

    printf("\nStudent data saved successfully!\n");
}

/* Load Students from File */
void loadStudents(struct Student students[], int *count)
{
    FILE *file;

    file = fopen("students.dat", "rb");

    if (file == NULL)
    {
        *count = 0;
        return;
    }

    *count = fread(students, sizeof(struct Student), MAX_STUDENTS, file);

    fclose(file);

    printf("\n%d student(s) loaded successfully!\n", *count);
}

/* Main Function */
int main()
{
    int choice;
    struct Student students[MAX_STUDENTS];
    int count = 0;

    loadStudents(students, &count);

    do
    {
        printf("\n====================================\n");
        printf("      STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Student Statistics\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                saveStudents(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                saveStudents(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                saveStudents(students, count);
                break;

            case 6:
                studentStatistics(students, count);
                break;

            case 7:
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
