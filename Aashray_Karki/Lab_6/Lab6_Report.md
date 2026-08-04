# Lab 6: Inheritance in C++

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Description

This lab report focuses on inheritance in C++. It explains how one class can acquire the properties and functions of another class. The lab includes single inheritance, multilevel inheritance, multiple inheritance, hierarchical inheritance, and hybrid inheritance. It also demonstrates constructor and destructor ordering and the use of virtual inheritance to solve the diamond problem.

---

## Objectives

1. To understand the concept of inheritance in C++.
2. To implement single inheritance using base and derived classes.
3. To demonstrate multilevel inheritance using multiple class levels.
4. To implement multiple inheritance using more than one base class.
5. To understand hierarchical inheritance using a common base class.
6. To study hybrid inheritance and the use of virtual inheritance.
7. To observe constructor and destructor execution order in inheritance.

---

## Software Required

* C++ Compiler (GCC / MinGW)
* Visual Studio Code (VS Code)
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Inheritance

Inheritance is an important feature of Object-Oriented Programming. It allows one class to use the data members and member functions of another class.

The class whose properties are inherited is called the base class, and the class that inherits those properties is called the derived class.

Inheritance improves code reusability, reduces duplication, and makes the program more organized.

---

### 2. Syntax of Inheritance

The general syntax of inheritance in C++ is:

```cpp
class DerivedClass : accessSpecifier BaseClass {
    // members of derived class
};
```

Example:

```cpp
class Student : public Person {
    // members of Student class
};
```

---

### 3. Single Inheritance

Single inheritance occurs when one derived class inherits from one base class.

In this lab, the class `Student` inherited from the class `Person`. The derived class reused the name and age details from the base class and added roll number and GPA.

---

### 4. Multilevel Inheritance

Multilevel inheritance occurs when a class is derived from another derived class.

In this lab, the class `Vehicle` was used as the base class, `Car` was derived from `Vehicle`, and `ElectricCar` was derived from `Car`.

This showed how data can be passed from one level of inheritance to another.

---

### 5. Multiple Inheritance

Multiple inheritance occurs when one class inherits from more than one base class.

In this lab, the class `Professor` inherited from both `Teacher` and `Researcher`. This allowed the professor object to access details from both parent classes.

---

### 6. Hierarchical Inheritance

Hierarchical inheritance occurs when multiple derived classes inherit from a single base class.

In this lab, the class `Shape` was used as a common base class, and `Circle`, `Rectangle`, and `Triangle` were derived from it.

Each derived class implemented its own area calculation.

---

### 7. Pure Virtual Function

A pure virtual function is a function that has no body in the base class and must be implemented in the derived class.

Example:

```cpp
virtual float area() = 0;
```

A class containing a pure virtual function becomes an abstract class.

---

### 8. Hybrid Inheritance

Hybrid inheritance is a combination of two or more types of inheritance.

In this lab, the class `Bat` inherited from both `Mammal` and `Bird`, while both `Mammal` and `Bird` inherited from `Animal`.

This created a diamond problem, which was solved using virtual inheritance.

---

### 9. Virtual Inheritance

Virtual inheritance is used to avoid duplicate copies of a base class in hybrid inheritance.

In this lab, `Mammal` and `Bird` inherited virtually from `Animal`, so the `Bat` class had only one shared copy of the `Animal` class.

---

### 10. Constructor and Destructor Order

In inheritance, constructors are called from base class to derived class. Destructors are called in the reverse order, from derived class to base class.

For example, in multilevel inheritance:

```text
Constructor order: A → B → C
Destructor order: C → B → A
```

---

## Lab Implementation Tasks

### Task 1: Single Inheritance

A base class `Person` was created with private members `name` and `age`. A derived class `Student` was created using public inheritance. The `Student` class added `rollNo` and `gpa`.

The `display()` function was overridden in the derived class to show all details.

**Figure 1:** Program and output snapshot of single inheritance.

---

### Task 2: Multilevel Inheritance

A base class `Vehicle` was created with members `make` and `year`. A class `Car` was derived from `Vehicle`, and a class `ElectricCar` was derived from `Car`.

Each class used a parameterized constructor and a display function to show its own data and inherited data.

**Figure 2:** Program and output snapshot of multilevel inheritance.

---

### Task 3: Multiple Inheritance

Two base classes, `Teacher` and `Researcher`, were created. The class `Professor` inherited from both classes.

The program showed how a derived class can access features from more than one base class.

**Figure 3:** Program and output snapshot of multiple inheritance.

---

## Assignment Programs

### Assignment 1: Hierarchical Inheritance

A base class `Shape` was created with a pure virtual function `area()`. Three derived classes, `Circle`, `Rectangle`, and `Triangle`, inherited from `Shape`.

Each derived class calculated area using its own formula.

**Figure 4:** Program and output snapshot of hierarchical inheritance.

---

### Assignment 2: Constructor and Destructor Order

Classes `A`, `B`, and `C` were used to demonstrate multilevel inheritance. Constructors and destructors were used to print messages showing their execution order.

It was observed that constructors are called from base to derived class, while destructors are called from derived to base class.

**Figure 5:** Program and output snapshot of constructor and destructor ordering.

---

### Assignment 3: Hybrid Inheritance

The base class `Animal` was created, and two classes `Mammal` and `Bird` inherited from it using virtual inheritance. The class `Bat` inherited from both `Mammal` and `Bird`.

Virtual inheritance was used to solve the diamond problem and avoid duplicate copies of the `Animal` class.

**Figure 6:** Program and output snapshot of hybrid inheritance.

---

## Observation

After performing this lab, it was observed that inheritance helps reduce code repetition and improves reusability. Derived classes can use the data and functions of base classes according to the access specifier used.

It was also observed that constructor execution starts from the base class and moves toward the derived class. Destructor execution occurs in the opposite order.

Virtual inheritance was useful in hybrid inheritance because it avoided ambiguity caused by multiple copies of the same base class.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The single inheritance program showed how a derived class can reuse base class data. The multilevel inheritance program showed inheritance through multiple class levels. The multiple inheritance program showed how one class can inherit from two parent classes.

The hierarchical inheritance program demonstrated the use of a pure virtual function. The constructor and destructor program clearly showed the order of execution. The hybrid inheritance program successfully solved the diamond problem using virtual inheritance.

---

## Discussion

Inheritance is one of the most important concepts of Object-Oriented Programming. It makes programs easier to maintain because common properties can be written in a base class and reused by derived classes.

Single inheritance is simple and useful for basic relationships. Multilevel inheritance is useful when classes are arranged in a chain. Multiple inheritance allows a class to combine properties from more than one parent class, but it must be used carefully to avoid ambiguity.

Hybrid inheritance may create the diamond problem when a derived class receives two copies of the same base class. This problem can be solved using virtual inheritance.

---

## Result

The programs based on single, multilevel, multiple, hierarchical, and hybrid inheritance were successfully implemented in C++. Constructor and destructor order was also observed clearly.

---

## Conclusion

In this lab, different types of inheritance in C++ were studied and implemented. The concepts of base class, derived class, access through inheritance, pure virtual function, constructor and destructor order, and virtual inheritance were understood.

The objectives of the lab were achieved successfully. This lab helped improve understanding of code reusability and class relationships in Object-Oriented Programming.

---

## References

[1] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.

[2] B. Stroustrup, *The C++ Programming Language*, Addison-Wesley.

[3] HCOE, *Object-Oriented Programming Lab Materials*, 2081.
