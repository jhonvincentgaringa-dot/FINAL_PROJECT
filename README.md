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

The system utilizes 3 core data structures to manage information and memory effectively:

1.  **Linked List (Singly Linked List)**: The primary structure used to store student records via `struct Student`. It allows for dynamic memory allocation, enabling the registry to grow or shrink as needed.
2.  **Array (Character Arrays/Strings)**: Used within each node to store specific student attributes such as `studentId`, `name`, `course`, and `major`.
3.  **Stack (Linked List Implementation)**: It is primarily designed to support the 'Undo Delete' feature which temporarily hold deleted students. It allows the student data to be pushed back into the main list if the user made a mistake.
   
---

**Algorithms**

The system implements 3 distinct algorithms to manage the lifecycle of student data:

1. **Linear Search**: Iterates through the list until the target ID is found or the end is reached ($O(N)$ complexity). 
2. **Bubble Sort**: A sorting algorithm that compares adjacent nodes and swaps data if they are out of order based on ID.
3. **Selection Sort**: The list alphabetically by name by repeatedly finding the minimum element in the unsorted portion and moving it to the front.

---

# Features

*   **Color-coded Interface**: Uses ANSI escape sequences (RED, GREEN, YELLOW, etc.) for a visually organized terminal experience.
*   **Comprehensive Student Management**: Supports adding, displaying, finding, editing, sorting by id, sorting by name, deleting student records, and undo delete student.
*   **Error Handling**: Includes checks for invalid menu choices and failed memory allocations.

---

# Academic Integrity and AI Use

* **AI Tools Used**: ChatGPT, Google Gemini
* **Prompt Used**: fix the bug in the code.
* **How it was implemented**: fixing bug in the code.
