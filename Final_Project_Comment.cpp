#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DATA STRUCTURE 1: Linked List (Singly Linked List)
// Lines 7-12 define the structure and the pointer to the next node
struct Student {
    int studentId;
    char name[100]; // DATA STRUCTURE 2: Array
    char major[50]; // DATA STRUCTURE 2: Array
    struct Student *next; 
};

struct Student *createStudent(int id, const char *name, const char *major);
void addStudent(struct Student **head, int id, const char *name, const char *major);
void displayStudents(struct Student *head);
struct Student *findStudent(struct Student *head, int id);
void deleteStudent(struct Student **head, int id);

int main() {
    // DATA STRUCTURE 3: Stack
    // Lines 23-27 Local variables stored on the Stack memory
    struct Student *head = NULL;
    int choice;
    int id;
    char name[100];
    char major[50];

    do {
        printf("\n--- Student Registration System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &id);
                while (getchar() != '\n');

                printf("Enter student name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter student major: ");
                fgets(major, sizeof(major), stdin);
                major[strcspn(major, "\n")] = 0;

                addStudent(&head, id, name, major);
                printf("Student added successfully!\n");
                break;

            case 2:
                displayStudents(head);
                break;

            case 3: {
                printf("Enter student ID to find: ");
                scanf("%d", &id);
                while (getchar() != '\n');

                struct Student *found = findStudent(head, id);
                if (found != NULL) {
                    printf("\nStudent Found:\n");
                    printf("ID: %d\n", found->studentId);
                    printf("Name: %s\n", found->name);
                    printf("Major: %s\n", found->major);
                } else {
                    printf("Student with ID %d not found.\n", id);
                }
                break;
            }

            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                while (getchar() != '\n');
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

struct Student *createStudent(int id, const char *name, const char *major) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newStudent->studentId = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->major, major);
    newStudent->next = NULL;
    return newStudent;
}

void addStudent(struct Student **head, int id, const char *name, const char *major) {
    struct Student *newStudent = createStudent(id, name, major);
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
// Lines 135-146 visit every node in the list
void displayStudents(struct Student *head) {
    if (head == NULL) {
        printf("No students registered yet.\n");
        return;
    }
    printf("\n--- List of Students ---\n");
    struct Student *current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Major: %s\n", current->studentId, current->name, current->major);
        current = current->next;
    }
}

// ALGORITHM 2: Searching (Linear Search)
// Lines 150-159 iterate through the list until the target ID is found
struct Student *findStudent(struct Student *head, int id) {
    struct Student *current = head;
    while (current != NULL) {
        if (current->studentId == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteStudent(struct Student **head, int id) {
    struct Student *current = *head;
    struct Student *prev = NULL;

    if (current != NULL && current->studentId == id) {
        *head = current->next;
        free(current);         
        printf("Student with ID %d deleted successfully.\n", id);
        return;
    }

    while (current != NULL && current->studentId != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student with ID %d deleted successfully.\n", id);
}
