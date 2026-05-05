# Student Registration System

## Overview
The **Student Registration System** is a command-line application designed to manage student records efficiently. It allows users to register new students, view the entire directory, search for specific student by their unique ID, edit the specific student information, and remove records from the system. 

The purpose of this project is to demonstrate the practical application of dynamic memory management and fundamental data structures and algorithms in the C programming language.

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

**Data Structures Implemented**

The system utilizes four core data structures to manage information and memory effectively:

1.  **Linked List (Singly Linked List)**: The primary structure used to store student records via `struct Student`. It allows for dynamic memory allocation, enabling the registry to grow or shrink as needed.
2.  **Array (Character Arrays/Strings)**: Used within each node to store specific student attributes such as `studentId`, `name`, `course`, and `major`.
3.  **Stack (Local Variable Storage)**: Local variables within the `main` function (like `choice`, `id`, and the `head` pointer) are stored in stack memory for fast, scope-based access.

---

**Algorithms**

The system implements 3 distinct algorithms to manage the lifecycle of student data:

1.  **Linear Search (By ID)**: Iterates through the list until the target ID is found or the end is reached ($O(N)$ complexity).
2.  **Data Swapping**: An in-place mutation algorithm used to exchange data between two nodes during sorting.
3. **Bubble Sort**: A sorting algorithm that compares adjacent nodes and swaps data if they are out of order based on ID.

---

# Features

*   **Color-coded Interface**: Uses ANSI escape sequences (RED, GREEN, YELLOW, etc.) for a visually organized terminal experience.
*   **Comprehensive Student Management**: Supports adding, displaying, finding, editing, and deleting student records.
*   **Error Handling**: Includes checks for invalid menu choices and failed memory allocations.
