#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Course {
    char name[50];
    char code[10];
    char instructor[50];
};

struct Student {
    char name[50];
    int rollNumber;
    struct Course enrolledCourses[5];
    int numCoursesEnrolled;
};

void addStudent() {
    struct Student newStudent;
    FILE *fp = fopen("students.dat", "ab");
    
    printf("Enter student name: ");
    scanf(" %[^\n]s", newStudent.name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    
    printf("Enter number of courses to enroll (max %d): ", 5);
    scanf("%d", &newStudent.numCoursesEnrolled);
    
    for(int i = 0; i < newStudent.numCoursesEnrolled; i++) {
        printf("\nCourse %d:\n", i+1);
        printf("Enter course name: ");
        scanf(" %[^\n]s", newStudent.enrolledCourses[i].name);
        printf("Enter course code: ");
        scanf(" %[^\n]s", newStudent.enrolledCourses[i].code);
        printf("Enter instructor name: ");
        scanf(" %[^\n]s", newStudent.enrolledCourses[i].instructor);
    }
    
    fwrite(&newStudent, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void displayStudentCourses() {
    int rollNumber;
    struct Student student;
    FILE *fp = fopen("students.dat", "rb");
    int found = 0;
    
    printf("Enter student roll number: ");
    scanf("%d", &rollNumber);
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        if(student.rollNumber == rollNumber) {
            printf("\nStudent: %s (Roll No: %d)\n", student.name, student.rollNumber);
            printf("Enrolled Courses:\n");
            for(int i = 0; i < student.numCoursesEnrolled; i++) {
                printf("%d. %s (%s) - Instructor: %s\n", 
                    i+1, 
                    student.enrolledCourses[i].name,
                    student.enrolledCourses[i].code,
                    student.enrolledCourses[i].instructor);
            }
            found = 1;
            break;
        }
    }
    
    if(!found) printf("Student not found!\n");
    fclose(fp);
}

void generateEnrollmentReport() {
    struct Student student;
    FILE *fp = fopen("students.dat", "rb");
    struct {
        char code[10];
        int count;
    } courseStats[100];
    int numCourses = 0;
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        for(int i = 0; i < student.numCoursesEnrolled; i++) {
            int found = 0;
            for(int j = 0; j < numCourses; j++) {
                if(strcmp(courseStats[j].code, student.enrolledCourses[i].code) == 0) {
                    courseStats[j].count++;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                strcpy(courseStats[numCourses].code, student.enrolledCourses[i].code);
                courseStats[numCourses].count = 1;
                numCourses++;
            }
        }
    }
    
    printf("\nEnrollment Report:\n");
    for(int i = 0; i < numCourses; i++) {
        printf("Course Code: %s - Students Enrolled: %d\n", 
            courseStats[i].code, courseStats[i].count);
    }
    
    fclose(fp);
}

void modifyEnrollment() {
    int rollNumber;
    struct Student student;
    FILE *fp = fopen("students.dat", "rb+");
    int found = 0;
    
    printf("Enter student roll number: ");
    scanf("%d", &rollNumber);
    
    while(fread(&student, sizeof(struct Student), 1, fp)) {
        if(student.rollNumber == rollNumber) {
            printf("Enter new number of courses (max %d): ", 5);
            scanf("%d", &student.numCoursesEnrolled);
            
            for(int i = 0; i < student.numCoursesEnrolled; i++) {
                printf("\nCourse %d:\n", i+1);
                printf("Enter course name: ");
                scanf(" %[^\n]s", student.enrolledCourses[i].name);
                printf("Enter course code: ");
                scanf(" %[^\n]s", student.enrolledCourses[i].code);
                printf("Enter instructor name: ");
                scanf(" %[^\n]s", student.enrolledCourses[i].instructor);
            }
            
            fseek(fp, -sizeof(struct Student), SEEK_CUR);
            fwrite(&student, sizeof(struct Student), 1, fp);
            found = 1;
            printf("Enrollment modified successfully!\n");
            break;
        }
    }
    
    if(!found) printf("Student not found!\n");
    fclose(fp);
}
int main() {
    int choice;
    
    do {
        printf("\nStudent Course Enrollment System\n");
        printf("1. Add New Student\n");
        printf("2. Display Student's Courses\n");
        printf("3. Generate Enrollment Report\n");
        printf("4. Modify Course Enrollment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudentCourses();
                break;
            case 3:
                generateEnrollmentReport();
                break;
            case 4:
                modifyEnrollment();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    

}
