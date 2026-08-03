# Lab 7: Virtual Functions and RTTI

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Description

This lab report focuses on virtual functions and RTTI in C++. It explains how virtual functions support runtime polymorphism and how RTTI helps identify the actual type of an object during program execution. The lab also covers abstract classes, pure virtual functions, virtual destructors, `typeid`, `dynamic_cast`, and virtual inheritance.

---

## Objectives

1. To understand the need for virtual functions in C++.
2. To demonstrate runtime polymorphism using base class pointers.
3. To implement abstract classes using pure virtual functions.
4. To understand the use of virtual destructors.
5. To use RTTI with `typeid` and `dynamic_cast`.
6. To understand virtual inheritance and the diamond problem.

---

## Software Required

* C++ Compiler (GCC / MinGW)
* Visual Studio Code
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Virtual Function

A virtual function is a member function declared in a base class using the keyword `virtual`. It allows the derived class version of a function to be called through a base class pointer.

Without a virtual function, the function call depends on the pointer type. With a virtual function, the function call depends on the actual object type at runtime.

---

### 2. Runtime Polymorphism

Runtime polymorphism means that the function to be executed is decided during program execution. It is achieved using virtual functions and base class pointers.

---

### 3. Abstract Class

An abstract class is a class that contains at least one pure virtual function. It cannot be used to create objects directly.

Example:

```cpp
virtual float area() = 0;
```

---

### 4. Pure Virtual Function

A pure virtual function is a function that has no body in the base class. The derived class must define it.

---

### 5. Virtual Destructor

A virtual destructor ensures that the destructor of the derived class is called properly when an object is deleted using a base class pointer.

If the destructor is not virtual, only the base class destructor may be called, which can cause improper cleanup.

---

### 6. RTTI

RTTI stands for Run-Time Type Information. It is used to identify the actual type of an object during program execution.

The two common RTTI tools are:

* `typeid`
* `dynamic_cast`

---

### 7. typeid

The `typeid` operator gives the actual runtime type of an object.

Example:

```cpp
typeid(*ptr).name();
```

---

### 8. dynamic_cast

`dynamic_cast` is used to safely convert a base class pointer into a derived class pointer. If the conversion fails, it returns `NULL`.

---

### 9. Virtual Inheritance

Virtual inheritance is used to solve the diamond problem. It ensures that only one shared copy of a common base class is inherited.

---

## Lab Implementation Tasks

### Task 1: Need for Virtual Function

A base class `Animal` and derived classes `Dog` and `Cat` were created. The program first showed behavior without using the `virtual` keyword. Then the same program was tested using the `virtual` keyword.

It was observed that without `virtual`, the base class function was called. With `virtual`, the derived class function was called.

**Figure 1:** Program and output snapshot of virtual function behavior.

---

### Task 2: Abstract Shape Class

An abstract class `Shape` was created with pure virtual functions `area()` and `perimeter()`. Derived classes `Circle`, `Rectangle`, and `Triangle` implemented these functions.

A `Shape` pointer was used to call the `display()` function for each derived class object.

**Figure 2:** Program and output snapshot of abstract class and pure virtual functions.

---

### Task 3: Virtual Destructor and RTTI

A base class `Vehicle` and derived classes `Car` and `Truck` were created. Virtual destructors were used to ensure proper cleanup.

The `typeid` operator was used to print runtime type information, and `dynamic_cast` was used to safely access derived class members.

**Figure 3:** Program and output snapshot of RTTI and virtual destructor.

---

## Assignment Programs

### Assignment 1: Virtual Base Class and Diamond Problem

A virtual base class `Device` was created. Classes `Printer` and `Scanner` inherited from `Device`, and class `Photocopier` inherited from both.

Virtual inheritance was used so that `Photocopier` had only one copy of `Device`.

**Figure 4:** Program and output snapshot of virtual inheritance.

---

### Assignment 2: Employee Payroll System

An abstract class `Employee` was created with pure virtual functions `calculateSalary()` and `display()`.

Classes `FullTimeEmployee`, `PartTimeEmployee`, and `Contractor` implemented their own salary calculation methods.

**Figure 5:** Program and output snapshot of employee payroll system.

---

### Assignment 3: Media File System

An abstract class `MediaFile` was created. Classes `AudioFile`, `VideoFile`, and `ImageFile` inherited from it.

RTTI was used to identify the actual file type and access specific information such as bitrate and resolution.

**Figure 6:** Program and output snapshot of media file system using RTTI.

---

## Observation

After performing this lab, it was observed that virtual functions allow the correct derived class function to be called through a base class pointer. Abstract classes help define a common structure for derived classes.

It was also observed that virtual destructors are important when deleting derived objects through base class pointers. RTTI helps identify object types during runtime, and `dynamic_cast` safely converts base class pointers to derived class pointers.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The output showed the difference between virtual and non-virtual functions. The abstract class program showed that objects of abstract classes cannot be created directly. The RTTI program correctly identified object types and accessed derived class-specific data safely.

---

## Discussion

Virtual functions are important for runtime polymorphism. They make programs more flexible because the same base class pointer can call different derived class functions.

RTTI is useful when the program needs to know the actual object type during runtime. Virtual destructors are necessary to avoid incomplete destruction of derived objects.

Virtual inheritance is useful in hybrid inheritance because it solves the diamond problem by avoiding duplicate copies of a common base class.

---

## Result

The programs based on virtual functions, abstract classes, virtual destructors, RTTI, `typeid`, `dynamic_cast`, and virtual inheritance were successfully implemented.

---

## Conclusion

In this lab, virtual functions and RTTI in C++ were studied and implemented. The concepts of runtime polymorphism, abstract classes, pure virtual functions, virtual destructors, `typeid`, `dynamic_cast`, and virtual inheritance were clearly understood.

The objectives of the lab were achieved successfully.

---

## References

[1] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.

[2] B. Stroustrup, *The C++ Programming Language*, Addison-Wesley.

[3] HCOE, *Object-Oriented Programming Lab Materials*, 2081.
