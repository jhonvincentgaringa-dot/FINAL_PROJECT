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

Variable,Data Type,Scope/Context,Description
studentId,int,struct Student,A unique integer used to identify each student record.
name,char[100],struct Student,A character array (string) that stores the student's full name.
major,char[50],struct Student,A character array (string) that stores the student's academic major.
*next,struct Student*,struct Student,A self-referential pointer that stores the memory address of the next node in the list.
*head,struct Student*,main(),"The ""entry point"" pointer that tracks the very first student in the linked list."
choice,int,main(),Stores the user's numeric input for menu navigation.
id,int,Local (various),"Temporary storage for IDs entered during addition, searching, or deletion."
name,char[100],main(),A temporary buffer used to capture user text input before it is copied to the heap.
major,char[50],main(),A temporary buffer used to capture major input before it is copied to the heap.
**head,struct Student**,Functions,"A pointer-to-a-pointer, allowing functions to modify the original head in main."
*current,struct Student*,Traversal,"An iterator pointer used to ""walk"" through the list without losing the start position."
*prev,struct Student*,deleteStudent,Tracks the node immediately preceding the target to bridge the gap after deletion.
*newStudent,struct Student*,createStudent,Stores the memory address returned by malloc for a newly allocated record.
