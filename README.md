# Student Registration System

## Overview
The **Student Registration System** is a command-line application designed to manage student records efficiently. It allows users to register new students, view the entire directory, search for specific individuals by their unique ID, and remove records from the system. 

The purpose of this project is to demonstrate the practical application of dynamic memory management and fundamental data structures in the C programming language.

---

### Variable and Data type

| Variable | Data Type | Description |
| :--- | :--- | :--- |
| `studentId` | `int` | A unique integer identifier for the student. |
| `name[100]` | `char` (Array) | A character array (string) storing the student's name. |
| `major[50]` | `char` (Array) | A character array (string) storing the student's major. |
| `*next` | `struct Student*` | A self-referential pointer used to link to the next record in the list. |

---

## Data Structures and Algorithms

Data Structures Implemented

The system utilizes four core data structures to manage information and memory effectively:

1.  **Linked List (Singly Linked List)**: The primary structure used to store student records via `struct Student`. It allows for dynamic memory allocation, enabling the registry to grow or shrink as needed.
2.  **Array (Character Arrays/Strings)**: Used within each node to store specific student attributes such as `studentId`, `name`, `course`, and `major`.
3.  **Stack (Local Variable Storage)**: Local variables within the `main` function (like `choice`, `id`, and the `head` pointer) are stored in stack memory for fast, scope-based access.
4.  **Pointer (Head Reference)**: A critical pointer (`struct Student *head`) is used to maintain the reference to the start of the linked list, allowing the program to traverse the data.

---

Algorithms

The following five algorithmic patterns drive the system's functionality:

*   **Validation (Input Checking)**: Functions like `isNumeric()` and `hasNumber()` ensure data integrity by verifying that IDs contain only digits and names contain no numbers before processing.
*   **Insertion (Append to Tail)**: When adding a new student, the system traverses to the end of the linked list and attaches a new node.
*   **Linear Traversal (Displaying/Cleaning)**: Used to print the entire list of students and to safely free memory (cleaning) when exiting the program.
*   **Searching (Linear Search)**: To find or edit a specific record, the system iterates through the list comparing the target ID against each node's `studentId`.
*   **Deletion (Node Removal)**: This algorithm locates a specific node, unlinks it from the list by updating the previous node's `next` pointer, and frees the memory.

---

# Features

*   **Color-coded Interface**: Uses ANSI escape sequences (RED, GREEN, YELLOW, etc.) for a visually organized terminal experience.
*   **Comprehensive Student Management**: Supports adding, displaying, finding, editing, and deleting student records.
*   **Error Handling**: Includes checks for invalid menu choices and failed memory allocations.
