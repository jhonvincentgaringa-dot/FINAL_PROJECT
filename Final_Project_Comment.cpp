#include <stdio.h> // This is for Input and Output functions (printf, scanf, fgets)
#include <stdlib.h> // This is for Memory Management and Program exit (malloc, free, exit)
#include <string.h> // This is for String manipulation functions (strcpy, strcspn)
#include <ctype.h>  // Added for isdigit() validation

// line 7-14 for American National Standards Institute (ANSI) Escape Sequences for Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// DATA STRUCTURE 1: Linked List (Singly Linked List)
// Lines 18-24 define the structure and the pointer to the next node
struct Student {
    char studentId[20]; // DATA STRUCTURE 2: Array
    char name[100]; // DATA STRUCTURE 2: Array
    char course[100]; // DATA STRUCTURE 2: Array
    char major[50]; // DATA STRUCTURE 2: Array
    struct Student *next;
};

// line 27-34 Function declarations
struct Student *createStudent(const char *id, const char *name, const char *course, const char *major);
void addStudent(struct Student **head, const char *id, const char *name, const char *course, const char *major);
void displayStudents(struct Student *head);
struct Student *findStudent(struct Student *head, const char *id);
void deleteStudent(struct Student **head, const char *id);
void editStudent(struct Student *head, const char *id);
int isNumeric(const char *str);
int hasNumber(const char *str);

int main() {
    
    // DATA STRUCTURE 3: Stack
    // Lines 41-45 Local variables stored on the Stack memory
    struct Student *head = NULL; // DATA STRUCTURE 4: Pointer
    int choice;
    char id[20];
    char name[100];
    char course[100];
    char major[50];

    do {
        printf(CYAN "-----------------------------------\n" RESET);
        printf(BOLD YELLOW "            WELCOME TO\n" RESET);
        printf(BOLD YELLOW "      Student Registry System\n" RESET);
        printf(CYAN "-----------------------------------\n" RESET);
        printf("\n--- Student Registration System ---\n");
        printf("1. " GREEN "Add Student\n" RESET);
        printf("2. " GREEN "Display All Students\n" RESET);
        printf("3. " GREEN "Find Student by ID\n" RESET);
        printf("4. " GREEN "Edit Student by ID\n" RESET);
        printf("5. " RED "Delete Student by ID\n" RESET);
        printf("6. Exit\n");
        printf(BOLD "Please enter your choice from 1 to 6: " RESET);
        
        // line 62-67 for error handling
        if (scanf("%d", &choice) != 1) {
            printf(RED "Invalid choice. Please try again.\n" RESET);
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            
            // lines 74-103 for the student registration
            case 1:
                printf(YELLOW "Enter student ID (example 000000): " RESET);
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;

                if (!isNumeric(id)) {
                    printf(RED "Error: ID must contain numbers only.\n" RESET);
                    break;
                }

                printf(YELLOW "Enter student name (Last Name, First Name MI.): " RESET);
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                if (hasNumber(name)) {
                    printf(RED "Error: Name must not contain numbers.\n" RESET);
                    break;
                }

                printf(YELLOW "Enter your course: " RESET);
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = 0;

                printf(YELLOW "Enter your major (if no major N/A): " RESET);
                fgets(major, sizeof(major), stdin);
                major[strcspn(major, "\n")] = 0;

                addStudent(&head, id, name, course, major);
                printf(GREEN BOLD "Student added successfully!\n" RESET);
                break;

            case 2:
                // lines 107-108 for displaying the student registered 
                displayStudents(head);
                break;

            case 3:
                {
                    // lines 113-128 for finding student details
                    printf(YELLOW "Enter student ID to find: " RESET);
                    fgets(id, sizeof(id), stdin);
                    id[strcspn(id, "\n")] = 0;

                    struct Student *found = findStudent(head, id);
                    if (found != NULL) {
                        printf(BOLD GREEN "\nStudent Found:\n" RESET);
                        printf(YELLOW BOLD "ID: " RESET "%s\n", found->studentId);
                        printf(YELLOW BOLD "Name: " RESET "%s\n", found->name);
                        printf(YELLOW BOLD "Course: " RESET "%s\n", found->course);
                        printf(YELLOW BOLD "Major: " RESET "%s\n", found->major);
                    } else {
                        printf(RED "Student with ID %s not found.\n" RESET, id);
                    }
                }
                break;

            case 4:
                // line 131-136 for editing student details
                printf(YELLOW "Enter student ID to edit: " RESET);
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;
                editStudent(head, id);
                break;

            case 5:
                // line 140-144 for deleting student registered
                printf(YELLOW "Enter student ID to delete: " RESET);
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;
                deleteStudent(&head, id);
                break;

            case 6:
                // lines 148-149 for exiting
                printf(MAGENTA "Exiting system. Goodbye!\n" RESET);
                break;

            default:
                printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    } while (choice != 6);
    
    struct Student *current = head;
    struct Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

// ALGORITHM 1: Validation (Input Checking)
// line 168-176 Function to check if a string contains any numeric digits
int isNumeric(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

// ALGORITHM 1: Validation (Input Checking)
// line 180-186 Function to check if a string contains any numeric digits
int hasNumber(const char *str) {
    while (*str) {
        if (isdigit((unsigned char)*str)) return 1;
        str++;
    }
    return 0;
}

struct Student *createStudent(const char *id, const char *name, const char *course, const char *major) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf(RED "Memory allocation failed!\n" RESET);
        exit(1);
    }
    strcpy(newStudent->studentId, id);
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    strcpy(newStudent->major, major);
    newStudent->next = NULL;
    return newStudent;
}

//ALGORITHM 2: Insertion (Append to Tail)
// line 203-215 for adding student
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

// ALGORITHM 3: Graph Traversal (Linear traversal of a Linked List)
// Lines 220-233 visit every node in the list
// for displaying the student information
void displayStudents(struct Student *head) {
    if (head == NULL) {
        printf(RED "No students registered yet.\n" RESET);
        return;
    }
    printf(CYAN "\n--- List of Students ---\n" RESET);
    struct Student *current = head;
    while (current != NULL) {
        printf(YELLOW BOLD "ID: " RESET "%s | " YELLOW BOLD "Name: " RESET "%s\n", current->studentId, current->name);
        printf(YELLOW BOLD "Course: " RESET "%s | " YELLOW BOLD "Major: " RESET "%s\n", current->course, current->major);
        printf(CYAN "-------------------------\n" RESET);
        current = current->next;
    }
}

// ALGORITHM 4: Searching (Linear Search)
// Lines 238-247 iterate through the list until the target ID is found
// for finding student id
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

// line 249-283 for edit existing student data
void editStudent(struct Student *head, const char *id) {
    struct Student *target = findStudent(head, id);
    
    if (target == NULL) {
        printf(RED "Student with ID %s not found.\n" RESET, id);
        return;
    }

    char newName[100], newCourse[100], newMajor[50];

    printf(CYAN "Editing Student: %s\n" RESET, target->name);

    printf(YELLOW "Enter new name: " RESET);
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0;
    if (hasNumber(newName)) {
        printf(RED "Update failed: Name cannot contain numbers.\n" RESET);
        return;
    }

    printf(YELLOW "Enter new course: " RESET);
    fgets(newCourse, sizeof(newCourse), stdin);
    newCourse[strcspn(newCourse, "\n")] = 0;

    printf(YELLOW "Enter new major (if no major N/A): " RESET);
    fgets(newMajor, sizeof(newMajor), stdin);
    newMajor[strcspn(newMajor, "\n")] = 0;

    strcpy(target->name, newName);
    strcpy(target->course, newCourse);
    strcpy(target->major, newMajor);

    printf(GREEN BOLD "Student information updated successfully!\n" RESET);
}

// ALGORITHM 5: Deletion (Node Removal)
// line 287-311 for deleting student data
void deleteStudent(struct Student **head, const char *id) {
    struct Student *current = *head;
    struct Student *prev = NULL;

    if (current != NULL && strcmp(current->studentId, id) == 0) {
        *head = current->next;
        free(current);
        printf(RED "Student with ID %s deleted successfully.\n" RESET, id);
        return;
    }

    while (current != NULL && strcmp(current->studentId, id) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf(RED "Student with ID %s not found.\n" RESET, id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf(RED "Student with ID %s deleted successfully.\n" RESET, id);
}
