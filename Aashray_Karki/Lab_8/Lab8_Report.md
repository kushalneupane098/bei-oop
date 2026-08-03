# Lab 8: Stream Computations

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Description

This lab report focuses on stream computation and file handling in C++. It includes text file handling, binary file handling, object reading and writing, file copying, file modification, random access files, update operations, and delete operations.

---

## Objectives

1. To understand stream computation in C++.
2. To perform file input and output operations.
3. To copy data from one file to another.
4. To store object data in binary files.
5. To read and display records from files.
6. To modify records using file pointers.
7. To perform random access file operations.
8. To implement update and delete operations in file-based programs.

---

## Software Required

* C++ Compiler (GCC / MinGW)
* Visual Studio Code
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Stream Computation

In C++, streams are used for input and output operations. A stream represents the flow of data between a program and an input/output device or file.

Common stream objects are:

* `cin` for input
* `cout` for output
* `cerr` for error output
* `clog` for log output

---

### 2. File Handling

File handling is used to store data permanently in files. C++ provides the `<fstream>` header file for file operations.

The main file stream classes are:

* `ifstream` for reading from files
* `ofstream` for writing to files
* `fstream` for both reading and writing

---

### 3. Text File Handling

Text files store data in readable character form. In this lab, one program copied the content of one file into another file while converting lowercase letters into uppercase letters.

---

### 4. Binary File Handling

Binary files store data in memory format. They are useful for storing objects and records.

Example:

```cpp
file.write((char*)&object, sizeof(object));
file.read((char*)&object, sizeof(object));
```

---

### 5. File Pointers

File pointers help move to a specific position in a file.

Important file pointer functions are:

* `seekg()` to move the get pointer
* `seekp()` to move the put pointer
* `tellg()` to get the position of the get pointer
* `tellp()` to get the position of the put pointer

---

### 6. Random Access File

A random access file allows direct access to records stored in a file. It is useful in applications such as banking systems, student record systems, and inventory systems.

---

### 7. Record Modification

A record can be modified by searching for the required record and moving the file pointer back to that record position using `seekp()`.

---

### 8. Delete Operation

In file handling, deletion can be performed by marking a record as inactive. This is called logical deletion.

---

## Lab Implementation Tasks

### Task 5: File Copy with Uppercase Conversion

A program was written to copy the content of one file into another file. During copying, lowercase letters were converted into uppercase letters.

**Figure 1:** Program and output snapshot of file copy with uppercase conversion.

---

### Task 6: Department Store Product Records

A program was written to store information of five products in a binary file. The product details were then read from the file and displayed on the console.

The total number of records was calculated using the file pointer position divided by the size of the object.

**Figure 2:** Program and output snapshot of product file handling.

---

### Task 7: Student Record Modification

A program was written to store information of ten students in a file. The program searched for a student using roll number and modified the student's information.

**Figure 3:** Program and output snapshot of student record modification.

---

### Task 8: Random Access Account Processing

A program was written to add and display bank account records using a random access file. The account record contained account number, first name, last name, and total balance.

**Figure 4:** Program and output snapshot of random access account processing.

---

### Task 9: Update and Delete Account Records

The account processing program was extended to support update and delete operations. The update operation modified an existing account record, while the delete operation marked the record as inactive.

**Figure 5:** Program and output snapshot of update and delete operations.

---

## Observation

After performing this lab, it was observed that file handling allows data to be stored permanently. Text files are useful for readable data, while binary files are useful for storing objects and records.

It was also observed that file pointers are important for modifying existing records in a file. Random access files make it possible to read, write, update, and delete specific records efficiently.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The file copy program correctly converted lowercase letters into uppercase letters. Product records and student records were successfully written and read from files.

The account management programs successfully performed add, display, update, and delete operations using binary files.

---

## Discussion

Stream computation is an important part of C++ programming because it allows communication between the program and external files.

File handling is useful in real-life applications such as banking systems, student record systems, and inventory management systems. Binary files make object storage easier, while file pointer functions help in updating and modifying records.

Proper use of `seekg()`, `seekp()`, `tellg()`, and `sizeof()` is necessary to avoid incorrect file operations.

---

## Result

The programs related to stream computation and file handling were successfully implemented. Text file handling, binary file handling, record modification, random access, update, and delete operations were clearly understood.

---

## Conclusion

In this lab, stream computation and file handling in C++ were studied and implemented. The lab helped to understand how data can be stored permanently and managed using file streams.

The objectives of the lab were achieved successfully.

---

## References

[1] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.

[2] B. Stroustrup, *The C++ Programming Language*, Addison-Wesley.

[3] HCOE, *Object-Oriented Programming Lab Materials*, 2081.
