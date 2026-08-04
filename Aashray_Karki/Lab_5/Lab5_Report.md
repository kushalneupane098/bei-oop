# Lab 5: Operator Overloading in C++

---

## Lab Details

* **Course:** Object-Oriented Programming (OOP)
* **Institution:** HCOE (2081)
* **Student:** Aashray Karki
* **Roll No.:** HCE082BEI001

---

## Description

This lab report focuses on operator overloading in C++. It demonstrates how existing operators such as `+`, `-`, `==`, `++`, `*`, `<<`, and `>>` can be redefined for user-defined classes. The lab also covers unary and binary operators, friend functions, stream operators, and type conversion between basic data types and class objects.

---

## Objectives

1. To understand the concept and purpose of operator overloading in C++.
2. To overload unary and binary operators using member functions.
3. To overload operators using friend functions.
4. To overload input and output stream operators.
5. To understand type conversion between basic data types and class objects.
6. To apply operator overloading to different real-world programming problems.

---

## Software Required

* C++ Compiler (GCC / MinGW)
* Visual Studio Code (VS Code)
* Terminal / Command Prompt

---

## Core Concepts and Theory

### 1. Operator Overloading

Operator overloading is a feature of C++ that allows existing operators to work with user-defined data types. It gives a special meaning to an operator according to the class in which it is used.

For example, the `+` operator normally adds numbers, but it can also be overloaded to add two complex numbers, matrices, vectors, or distances.

---

### 2. Syntax of Operator Overloading

The general syntax of an overloaded operator function is:

```cpp
returnType operator symbol(parameters);
```

For example:

```cpp
Complex operator+(const Complex& c);
```

This function overloads the `+` operator for objects of the `Complex` class.

---

### 3. Unary Operator Overloading

A unary operator works on only one operand. Some examples of unary operators are:

* Unary minus `-`
* Increment `++`
* Decrement `--`
* Logical NOT `!`

A unary operator can be overloaded as a member function because it operates on the current object.

Example:

```cpp
Distance operator-() const;
```

---

### 4. Binary Operator Overloading

A binary operator works on two operands. Some examples are:

* Addition `+`
* Subtraction `-`
* Multiplication `*`
* Equality `==`

A binary operator can be overloaded using either a member function or a friend function.

Example:

```cpp
Complex operator+(const Complex& c) const;
```

---

### 5. Prefix and Postfix Increment

The prefix and postfix forms of the increment operator are overloaded differently.

```cpp
Distance& operator++();     // Prefix increment
Distance operator++(int);   // Postfix increment
```

The unused integer parameter in the postfix version helps the compiler distinguish it from the prefix version.

---

### 6. Friend Function

A friend function is not a member of a class, but it can access the private and protected members of that class.

Friend functions are useful when both operands of an operator need equal access to the private data of a class.

Example:

```cpp
friend bool operator==(const Complex& c1, const Complex& c2);
```

---

### 7. Stream Operator Overloading

The input operator `>>` and output operator `<<` can be overloaded so that class objects can be read and displayed directly using `cin` and `cout`.

Example:

```cpp
friend istream& operator>>(istream& input, Complex& c);
friend ostream& operator<<(ostream& output, const Complex& c);
```

---

### 8. Type Conversion

C++ supports conversion between basic data types and class objects.

#### Basic Type to Class Type

A single-parameter constructor can convert a basic value into a class object.

```cpp
Celsius(float temperature);
```

#### Class Type to Basic Type

A conversion operator can convert an object into a basic data type.

```cpp
operator float() const;
```

#### Class Type to Class Type

A conversion constructor or conversion operator can convert an object of one class into an object of another class.

---

## Lab Implementation Tasks

### Task 1: Complex Number Operator Overloading

A class named `Complex` was created with private members `real` and `imag`. The `+` and `-` operators were overloaded as member functions to add and subtract two complex numbers.

The `==` operator was overloaded as a friend function to compare two complex numbers. The input and output operators `>>` and `<<` were also overloaded so that complex numbers could be entered and displayed directly.

**Figure 1:** Program and output snapshot of Complex number operator overloading.

---

### Task 2: Distance Operator Overloading

A class named `Distance` was created with private members `feet` and `inches`. The unary minus operator was overloaded to negate the distance.

The prefix and postfix `++` operators were overloaded to increase the distance by one inch. The multiplication operator `*` was overloaded as a friend function for both `Distance * int` and `int * Distance`.

**Figure 2:** Program and output snapshot of Distance operator overloading.

---

### Task 3: Celsius and Fahrenheit Conversion

Two classes, `Celsius` and `Fahrenheit`, were created to demonstrate type conversion.

A conversion constructor converted a float value into a `Celsius` object. A conversion operator converted a `Celsius` object back into a float value.

Conversion between Celsius and Fahrenheit objects was also demonstrated using the relation:

```text
F = C × 9/5 + 32
```

The output operator `<<` was overloaded for both classes to display temperature values.

**Figure 3:** Program and output snapshot of Celsius and Fahrenheit conversion.

---

## Assignment Programs

### Assignment 1: Matrix2x2 Operator Overloading

A class named `Matrix2x2` was created with a private two-dimensional integer array.

The `+` operator was overloaded for matrix addition, the `*` operator was overloaded for matrix multiplication, and the unary `-` operator was overloaded to negate all matrix elements.

The `==`, `<<`, and `>>` operators were also overloaded for comparison, display, and input.

**Figure 4:** Program and output snapshot of Matrix2x2 operator overloading.

---

### Assignment 2: Fraction Operator Overloading

A class named `Fraction` was created with private members `numerator` and `denominator`.

The arithmetic operators `+`, `-`, `*`, and `/` were overloaded to perform fraction calculations. The relational operators `<`, `>`, and `==` were overloaded for comparison.

The class also demonstrated conversion between fraction objects and decimal values.

**Figure 5:** Program and output snapshot of Fraction operator overloading.

---

### Assignment 3: Vector3D Operator Overloading

A class named `Vector3D` was created with private members `x`, `y`, and `z`.

The `+` and `-` operators were overloaded for vector addition and subtraction. The unary minus operator was overloaded to reverse the direction of a vector.

The multiplication operator was overloaded for dot product and scalar multiplication. A conversion operator was used to calculate the magnitude of a vector.

**Figure 6:** Program and output snapshot of Vector3D operator overloading.

---

## Observation

After performing this lab, it was observed that operator overloading makes operations on class objects simpler and more natural.

Objects could be added, subtracted, compared, incremented, multiplied, entered, and displayed using familiar operator symbols.

It was also observed that member functions are suitable when the left operand is an object of the same class. Friend functions are useful when both operands need equal access to private data or when the left operand is not a class object.

---

## Result Analysis

All programs were successfully written, compiled, and executed.

The overloaded operators produced the expected results for complex numbers, distances, matrices, fractions, and vectors.

The stream operators allowed objects to be read and displayed directly using `cin` and `cout`. The conversion constructors and conversion operators successfully converted values between basic data types and class objects.

---

## Discussion

Operator overloading improves the readability of C++ programs by allowing user-defined objects to behave like built-in data types.

For example, adding two complex objects using:

```cpp
c1 + c2
```

is easier to understand than calling a separate function such as:

```cpp
addComplex(c1, c2)
```

However, operators should only be overloaded when their meaning remains clear and logical. Incorrect use of operator overloading may make a program difficult to understand.

It is also important to use `const` references where possible to avoid unnecessary copying and prevent accidental modification of objects.

---

## Result

The programs related to unary, binary, stream, comparison, and conversion operator overloading were successfully implemented.

The behavior of member operator functions, friend operator functions, and type conversion was clearly understood.

---

## Conclusion

In this lab, operator overloading in C++ was studied and implemented using different classes.

Unary and binary operators, friend functions, stream operators, comparison operators, and conversion operators were successfully demonstrated.

The objectives of the lab were achieved. Operator overloading made class objects easier to use and helped produce more readable and organized C++ programs.

---

## References

[1] E. Balagurusamy, *Object-Oriented Programming with C++*, McGraw Hill Education.

[2] B. Stroustrup, *The C++ Programming Language*, Addison-Wesley.

[3] HCOE, *Object-Oriented Programming Lab Materials*, 2081.
