#  Academic Console Manager

A simple, console-based academic management system written in C++. Designed to help beginners understand basic file handling, data structures, and procedural programming logic. Ideal for students or educators looking for a lightweight, non-database solution to manage academic entities like students, teachers, and subjects.

---

##  Description

This project simulates a basic academic data manager using plain text and CSV files. It features a menu-driven interface where users can:
- View or add students and teachers
- Store subject-specific information in separate files
- Interact with a basic, local file-based data system
- 
##  Features

- Console-based user interface
- Manages:
  - Students (via `student.csv`)
  - Teachers (via `teacher.csv`)
  - Courses (via empty `.txt` files named after subjects)
- File-based data storage (no external databases)
- Basic menu-driven structure
  
 **Target Users**:  
Students learning file handling and C++ basics, academic hobby projects, or educational demos.


##  Folder Structure
    ```bash
      Console-Based-Academic-Management-System/
      ├── main.cpp # Main application logic
      ├── data/ # Data files
      │ ├── student.csv
      │ ├── teacher.csv
      │ ├── AI.txt
      │ ├── AOA.txt
      │ ├── DIP.txt
      │ ├── DL.txt
      │ ├── ITC.txt
      │ ├── oop.txt
      │ ├── PF.txt
      │ ├── RM.txt
      │ ├── SRC.txt
      ├── docs/ # Documentation
      │ └── IT.pdf # System architecture diagram
      └── README.md

## How to Use the Data Files
- student.csv: Store and manage student information.
- teacher.csv: Store and manage teacher information.
- Subject files like AI.txt, AOA.txt, etc. are used to represent different courses.
- These files are all located in the data/ directory and are loaded or updated by the program during runtime.
- 
## Screenshot / Diagram
You can view the architecture and workflow of the application in the PDF diagram named as IT.
