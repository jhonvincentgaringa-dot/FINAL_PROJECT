#include <stdio.h> // This is for Input and Output functions (printf, scanf, fgets)
#include <stdlib.h> // This is for Memory Management and Program exit (malloc, free, exit)
#include <string.h> // This is for String manipulation functions (strcpy, strcspn)
#include <ctype.h>  // Added for isdigit() validation

// DATA STRUCTURE 1: Linked List (Singly Linked List)
// Lines 8-13 define the structure and the pointer to the next node
struct Student {
    char studentId[20]; // DATA STRUCTURE 2: Array
    char name[100]; // DATA STRUCTURE 2: Array
    char course[100]; // DATA STRUCTURE 2: Array
    char major[50]; // DATA STRUCTURE 2: Array
    struct Student *next;
};

// Function declarations
struct Student *createStudent(const char *id, const char *name, const char *course, const char *major);
void addStudent(struct Student **head, const char *id, const char *name, const char *course, const char *major);
void displayStudents(struct Student *head);
struct Student *findStudent(struct Student *head, const char *id);
void deleteStudent(struct Student **head, const char *id);
int isNumeric(const char *str);

int main() {
    
    // DATA STRUCTURE 3: Stack
    // Lines 28-33 Local variables stored on the Stack memory
    struct Student *head = NULL;
    int choice;
    char id[20];
    char name[100];
    char course[100];
    char major[50];

    do {
        printf("\n--- Student Registration System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter student ID (example 000000): ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;

                if (!isNumeric(id)) {
                    printf("Error: ID must contain numbers only.\n");
                    break;
                }

                printf("Enter student name (Last Name, First Name MI.): ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter your course: ");
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = 0;

                printf("Enter your major (if no major N/A): ");
                fgets(major, sizeof(major), stdin);
                major[strcspn(major, "\n")] = 0;

                addStudent(&head, id, name, course, major);
                printf("Student added successfully!\n");
                break;

            case 2:
                displayStudents(head);
                break;

            case 3:
                {
                    printf("Enter student ID to find: ");
                    fgets(id, sizeof(id), stdin);
                    id[strcspn(id, "\n")] = 0;

                    struct Student *found = findStudent(head, id);
                    if (found != NULL) {
                        printf("\nStudent Found:\n");
                        printf("ID: %s\n", found->studentId);
                        printf("Name: %s\n", found->name);
                        printf("Course: %s\n", found->course);
                        printf("Major: %s\n", found->major);
                    } else {
                        printf("Student with ID %s not found.\n", id);
                    }
                }
                break;

            case 4:
                printf("Enter student ID to delete: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;
                deleteStudent(&head, id);
                break;

            case 5:
                printf("Exiting system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    struct Student *current = head;
    struct Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

int isNumeric(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

struct Student *createStudent(const char *id, const char *name, const char *course, const char *major) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newStudent->studentId, id);
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    strcpy(newStudent->major, major);
    newStudent->next = NULL;
    return newStudent;
}

void addStudent(struct Student **head, const char *id, const char *name, const char *course, const char *major) {
    struct Student *newStudent = createStudent(id, name, course, major);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// ALGORITHM 1: Graph Traversal (Linear traversal of a Linked List)
// Lines 166-181 visit every node in the list
void displayStudents(struct Student *head) {
    if (head == NULL) {
        printf("No students registered yet.\n");
        return;
    }
    printf("\n--- List of Students ---\n");
    struct Student *current = head;
    while (current != NULL) {
        printf("ID: %s\n", current->studentId);
        printf("Name: %s\n", current->name);
        printf("Course: %s\n", current->course);
        printf("Major: %s\n", current->major);
        printf("-------------------------\n");
        current = current->next;
    }
}

// ALGORITHM 2: Searching (Linear Search)
// Lines 185-194 iterate through the list until the target ID is found
struct Student *findStudent(struct Student *head, const char *id) {
    struct Student *current = head;
    while (current != NULL) {
        if (strcmp(current->studentId, id) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteStudent(struct Student **head, const char *id) {
    struct Student *current = *head;
    struct Student *prev = NULL;

    if (current != NULL && strcmp(current->studentId, id) == 0) {
        *head = current->next;
        free(current);
        printf("Student with ID %s deleted successfully.\n", id);
        return;
    }

    while (current != NULL && strcmp(current->studentId, id) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %s not found.\n", id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student with ID %s deleted successfully.\n", id);
}
