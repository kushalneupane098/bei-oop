# Lab 9: Template and Exception Handling

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Description

This lab report focuses on templates and exception handling in C++. It includes function templates, class templates, stack implementation using templates, user-defined exceptions, multiple catch blocks, and re-throwing of exceptions.

---

## Objectives

1. To understand generic programming using templates.
2. To implement function templates in C++.
3. To implement class templates in C++.
4. To create a stack using a class template.
5. To understand exception handling using `try`, `catch`, and `throw`.
6. To implement user-defined exception classes.
7. To use multiple catch blocks.
8. To demonstrate re-throwing of exceptions.

---

## Software Required

* C++ Compiler (GCC / MinGW)
* Visual Studio Code
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Templates

Templates are used for generic programming in C++. They allow functions and classes to work with different data types without rewriting the same code again and again.

Templates improve code reusability and reduce duplication.

---

### 2. Function Template

A function template allows a single function to work with different data types.

Example:

```cpp
template <class T>
T max3(T a, T b, T c) {
    // code
}
```

In this lab, a function template was used to find the maximum of three values.

---

### 3. Class Template

A class template allows a class to work with different data types.

Example:

```cpp
template <class T>
class Stack {
    // code
};
```

In this lab, a stack was created using a class template so that it could store integers and strings.

---

### 4. Stack

A stack is a linear data structure that follows the LIFO principle.

LIFO means Last In First Out. The element inserted last is removed first.

Common stack operations are:

* `push()` to insert data
* `pop()` to remove data
* `display()` to display stack elements

---

### 5. Exception Handling

Exception handling is used to handle runtime errors in a controlled way.

The main keywords used in exception handling are:

* `try`
* `catch`
* `throw`

---

### 6. User-Defined Exception

A user-defined exception is created by defining a class for a specific error condition.

In this lab, separate exception classes were created for division by zero and negative denominator.

---

### 7. Multiple Catch Blocks

Multiple catch blocks are used to handle different types of exceptions separately.

Example:

```cpp
catch (DivideByZeroException e) {
    // handle division by zero
}
catch (NegativeDenominatorException e) {
    // handle negative denominator
}
catch (...) {
    // handle unknown exception
}
```

---

### 8. Re-throwing Exception

Re-throwing means catching an exception in one function and throwing it again to another function for further handling.

Example:

```cpp
catch (...) {
    throw;
}
```

---

## Lab Implementation Tasks

### Task 1: Function Template for Maximum of Three Values

A function template `max3()` was written to find the maximum of three values. The function was tested using integer, float, and character data types.

**Figure 1:** Program and output snapshot of function template.

---

### Task 2: Stack Class Template

A class template `Stack` was created with `push()`, `pop()`, and `display()` functions.

One stack of integers and one stack of strings were created. Exception handling was used to handle stack overflow and stack underflow.

**Figure 2:** Program and output snapshot of stack class template.

---

### Task 3: Multiple Catch Blocks

A program was written to perform division of two numbers. User-defined exception classes were created for division by zero and negative denominator.

Multiple catch blocks were used to handle different errors separately.

**Figure 3:** Program and output snapshot of multiple catch blocks.

---

### Task 4: Re-throwing Exception

A function `compute()` was written to catch divide-by-zero exception locally and then re-throw it to the main function.

The exception was first caught inside `compute()` and then again caught in `main()`.

**Figure 4:** Program and output snapshot of re-throwing exception.

---

## Observation

After performing this lab, it was observed that templates help write generic and reusable code. The same function or class can work with different data types.

It was also observed that exception handling helps prevent abnormal program termination. User-defined exceptions make error handling clearer and more meaningful.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The function template correctly found the maximum value for different data types. The stack template worked for both integers and strings.

The exception handling programs successfully handled division by zero, negative denominator, stack overflow, stack underflow, and re-thrown exceptions.

---

## Discussion

Templates are useful when the same logic is required for different data types. Instead of writing separate functions or classes for `int`, `float`, `char`, or `string`, templates allow one generic code structure.

Exception handling is important for writing safe and reliable programs. It separates error-handling code from normal logic and allows errors to be handled properly without crashing the program.

---

## Result

The programs based on templates and exception handling were successfully implemented. Function templates, class templates, user-defined exceptions, multiple catch blocks, and re-throwing of exceptions were clearly understood.

---

## Conclusion

In this lab, templates and exception handling in C++ were studied and implemented. Function templates and class templates helped create reusable code, while exception handling helped manage runtime errors safely.

The objectives of the lab were achieved successfully.

---

## References

[1] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.

[2] B. Stroustrup, *The C++ Programming Language*, Addison-Wesley.

[3] HCOE, *Object-Oriented Programming Lab Materials*, 2081.
