#include <stdio.h>  // This is for Input and Output functions (printf, scanf, fgets)
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

// DATA STRUCTURE 1: Singly Linked List (Node Definition)
// Lines 18-25 define the structure and the pointer to the next node
struct Student {
    // DATA STRUCTURE 2: 1D Character Arrays (Strings)
    char studentId[20];
    char name[100];
    char course[100];
    char major[50];
    struct Student *next; // Pointer to the next node in the Linked List
};

// line 28-40 Function declarations
struct Student *createStudent(const char *id, const char *name, const char *course, const char *major);
void addStudent(struct Student **head, const char *id, const char *name, const char *course, const char *major);
void displayStudents(struct Student *head);
struct Student *findStudent(struct Student *head, const char *id);
void deleteStudent(struct Student **head, const char *id);
void editStudent(struct Student *head, const char *id);
int isNumeric(const char *str);
int hasNumber(const char *str);
void swapStudentData(struct Student *a, struct Student *b);

// Sorting Function Declarations
void bubbleSortStudents(struct Student *head);
void selectionSortByName(struct Student *head);

int main() {
    // DATA STRUCTURE 3: Stack (Memory Allocation)
    // line 45-50 for the following local variables and pointers are allocated on the Call Stack.
    struct Student *head = NULL;
    int choice;
    char id[20]; // DATA STRUCTURE 2: Array
    char name[100]; // DATA STRUCTURE 2: Array
    char course[100]; // DATA STRUCTURE 2: Array
    char major[50]; // DATA STRUCTURE 2: Array

    do {
        printf(CYAN "-----------------------------------\n" RESET);
        printf(BOLD YELLOW "            WELCOME TO\n" RESET);
        printf(BOLD YELLOW "       Student Registration System\n" RESET);
        printf(CYAN "-----------------------------------\n" RESET);
        printf("1. " GREEN "Add Student\n" RESET);
        printf("2. " GREEN "Display All Students\n" RESET);
        printf("3. " GREEN "Find Student by ID\n" RESET);
        printf("4. " GREEN "Edit Student by ID\n" RESET);
        printf("5. " BLUE "Sort Students by ID\n" RESET);
        printf("6. " BLUE "Sort Students by Name\n" RESET);
        printf("7. " RED "Delete Student by ID\n" RESET);
        printf("8. Exit\n");
        printf(BOLD "Please enter your choice from 1 to 8: " RESET);

        // Input validation to prevent infinite loops on character input
        // line 69-75 for error handling
        if (scanf("%d", &choice) != 1) {
            printf(RED "Invalid choice. Please try again.\n" RESET);
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        while (getchar() != '\n');

        if (choice >= 3 && choice <= 7 && head == NULL) {
            printf(RED "No students registered yet.\n" RESET);
            continue;
        }

        switch (choice) {
            // lines 86-114 for the student registration
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
            // lines 118-119 for displaying the student registered
            displayStudents(head);
            break;

        case 3:
        {
            // lines 124-140 for finding student details
            printf(YELLOW "Enter student ID to find: " RESET);
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = 0;

            // Execute ALGORITHM 4: Linear Search
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
            // line 144-148 for editing student details
            printf(YELLOW "Enter student ID to edit: " RESET);
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = 0;
            editStudent(head, id);
            break;

        case 5:
            // line 152-154 for student sorted by id
            bubbleSortStudents(head);
            printf(GREEN BOLD "Students sorted successfully by ID!\n" RESET);
            break;

        case 6:
            // line 158-160 for student sorted by name
            selectionSortByName(head);
            printf(GREEN BOLD "Students sorted successfully by Name!\n" RESET);
            break;

        case 7:
            // line 164-168 for deleting student registered
            printf(YELLOW "Enter student ID to delete: " RESET);
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = 0;
            deleteStudent(&head, id);
            break;

        case 8:
            // lines 172-173 for exiting
            printf(MAGENTA "Exiting system. Goodbye!\n" RESET);
            break;

        default:
            printf(RED "Invalid choice. Please try again.\n" RESET);
        }
    } while (choice != 8);

    // ALGORITHM 1: Linked List Memory Deallocation (Traversal and Free)
    struct Student *current = head;
    struct Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

// ALGORITHM 2: String Traversal and Validation
// line 194-201 Function to check if a string contains any numeric digits
int isNumeric(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

// ALGORITHM 2: String Traversal and Validation
// line 205-211 Function to check if a string contains any numeric digits
int hasNumber(const char *str) {
    while (*str) {
        if (isdigit((unsigned char)*str)) return 1;
        str++;
    }
    return 0;
}

// ALGORITHM 3: Dynamic Memory Allocation for Linked List Node
// line 215-227 for the student registration 
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

// ALGORITHM 4: Linked List Insertion (Append to Tail)
// line 231-242 for adding student
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

// ALGORITHM 5: Linked List Traversal
// Lines 247-260 visit every node in the list
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

// ALGORITHM 6: Linear Search (O(N) time complexity)
// Lines 265-274 iterate through the list until the target ID is found
// for finding student id
struct Student *findStudent(struct Student *head, const char *id) {
    struct Student *current = head;
    while (current != NULL) {
        if (strcmp(current->studentId, id) == 0) {
            return current; // Match found
        }
        current = current->next;
    }
    return NULL; // No match found
}

// ALGORITHM  7: Linear Search + Data Mutation
// line 278-311 for edit existing student data
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

// ALGORITHM 8: Linked List Node Deletion
// line 315-343 for deleting student data
void deleteStudent(struct Student **head, const char *id) {
    struct Student *current = *head;
    struct Student *prev = NULL;

    // Case 1: Head node itself holds the ID to be deleted
    if (current != NULL && strcmp(current->studentId, id) == 0) {
        *head = current->next;
        free(current);
        printf(RED "Student with ID %s deleted successfully.\n" RESET, id);
        return;
    }

    // Case 2: Search for the node, keeping track of the previous node
    while (current != NULL && strcmp(current->studentId, id) != 0) {
        prev = current;
        current = current->next;
    }

    // If ID was not present in linked list
    if (current == NULL) {
        printf(RED "Student with ID %s not found.\n" RESET, id);
        return;
    }

    // Unlink the node and free memory
    prev->next = current->next;
    free(current);
    printf(RED "Student with ID %s deleted successfully.\n" RESET, id);
}

// ALGORITHM 9: Data Swapping (In-place mutation)
//line 347-364 for swaping student data
void swapStudentData(struct Student *a, struct Student *b) {
    char tempId[20], tempName[100], tempCourse[100], tempMajor[50];

    strcpy(tempId, a->studentId);
    strcpy(tempName, a->name);
    strcpy(tempCourse, a->course);
    strcpy(tempMajor, a->major);

    strcpy(a->studentId, b->studentId);
    strcpy(a->name, b->name);
    strcpy(a->course, b->course);
    strcpy(a->major, b->major);

    strcpy(b->studentId, tempId);
    strcpy(b->name, tempName);
    strcpy(b->course, tempCourse);
    strcpy(b->major, tempMajor);
}

// ALGORITHM 10: Bubble Sort
// Time Complexity: O(N^2)
// Compares adjacent nodes and swaps their data if they are in the wrong order.
// line 370-391 for sorting by id
void bubbleSortStudents(struct Student *head) {
    int swapped;
    struct Student *ptr1;
    struct Student *lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            // Compare IDs alphabetically/lexicographically
            if (atoi(ptr1->studentId) > atoi(ptr1->next->studentId)) {
                swapStudentData(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Optimize by not checking the sorted elements at the end
    } while (swapped);
}

// ALGORITHM 11: Selection Sort
// Time Complexity: O(N^2)
// Divides list into sorted and unsorted portions. Finds the minimum element
// in the unsorted portion and swaps it into the correct position.
// line 398-420 for sorting by name
void selectionSortByName(struct Student *head) {
    struct Student *temp = head;

    // Traverse the Linked List
    while (temp != NULL) {
        struct Student *min = temp;
        struct Student *r = temp->next;

        // Traverse the unsorted list to find the minimum (alphabetically first name)
        while (r != NULL) {
            if (strcmp(min->name, r->name) > 0) {
                min = r;
            }
            r = r->next;
        }

        // Swap data if minimum is not the current element
        if (min != temp) {
            swapStudentData(temp, min);
        }
        temp = temp->next;
    }
}
