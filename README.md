# Student Registration System

## Overview
The **Student Registration System** is a command-line application designed to manage student records efficiently. It allows users to register new students, view the entire directory, search for specific individuals by their unique ID, and remove records from the system. 

The purpose of this project is to demonstrate the practical application of dynamic memory management and fundamental data structures in the C programming language.

---

## Data Structures and Algorithms

### Data Structures
1.  **Singly Linked List**: The primary container for student records. It allows for dynamic memory allocation, enabling the system to grow as more students are added without needing a predefined size.
2.  **Arrays**: Used within the `Student` struct to store fixed-length string data for names and majors.
3.  **Stack**: Utilized for local variable management and function call control within the `main` execution loop.

### Algorithms
1.  **Linear Traversal (List Display)**: Iterates through every node in the linked list to print student details to the console.
2.  **Linear Search**: A search algorithm that traverses the list sequentially to find a student matching a specific ID.
3.  **Node Deletion**: An algorithm that re-links pointers to remove a specific node from the sequence while preventing memory leaks using `free()`.

---

## How to Compile and Run

### Prerequisites
* A C compiler (such as `gcc`, `clang`, or `MinGW`).

### Compilation
Open your terminal or command prompt and navigate to the project folder. Run the following command:

```bash
gcc main.c -o student_system
