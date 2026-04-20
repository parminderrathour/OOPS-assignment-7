# 📘 Object-Oriented Programming — Assignment 7

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/Subject-OOP-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Questions-13-orange?style=for-the-badge" />
</p>

---

## 👤 Student Details

| Field          | Details                           |
| -------------- | --------------------------------- |
| **Name**       | Parminder Rathour                 |
| **Subject**    | Object-Oriented Programming (OOP) |
| **Assignment** | Assignment 7                      |
| **Language**   | C++                               |

---

## 📋 Table of Contents

* [About](#about)
* [Questions Covered](#questions-covered)
* [Concepts Used](#concepts-used)
* [How to Run](#how-to-run)
* [File Structure](#file-structure)

---

## 📖 About

This repository contains the solution to **Assignment 7** of the Object-Oriented Programming course.
This assignment focuses on **Polymorphism, Virtual Functions, Operator Overloading, and Type Conversion** in C++.

It demonstrates both **compile-time and runtime polymorphism**, advanced operator overloading techniques, and conversion between data types and objects using constructors and operator functions.

---

## ✅ Questions Covered

| Q#  | Topic                            | Description                                                                                             |
| --- | -------------------------------- | ------------------------------------------------------------------------------------------------------- |
| Q1  | Runtime Polymorphism             | Base class pointer (`Polygon`) calling derived classes (`Rectangle`, `Triangle`) using virtual function |
| Q2  | Abstract Class (Shape)           | Pure virtual functions for `area()` and `display()` implemented by Circle, Rectangle, Triangle          |
| Q3  | Function Overloading             | Area calculation for different triangle types using same function name                                  |
| Q4  | Abstract Class (Student)         | Base class `Student` with derived classes Engineering, Medicine, Science                                |
| Q5  | Operator Overloading (+)         | Add two `Time` objects with proper carry handling                                                       |
| Q6  | Operator Overloading (==, +)     | Custom `STRING` class for comparison and concatenation                                                  |
| Q7  | Operator Overloading (*)         | Matrix multiplication using friend function                                                             |
| Q8  | Operator Overloading ([])        | Safe array with bounds checking                                                                         |
| Q9  | Operator Overloading ()          | Object behaving like a function with multiple arguments                                                 |
| Q10 | Operator Overloading (>>, <<)    | Input/output stream operators for `Student` class                                                       |
| Q11 | Type Conversion (Basic → Object) | Convert float to class using constructor                                                                |
| Q12 | Type Conversion (Object → Basic) | Convert object to float using conversion operator                                                       |
| Q13 | Type Conversion (UDT → UDT)      | Convert Polar coordinates to Cartesian                                                                  |

---

## 🧠 Concepts Used

* **Runtime Polymorphism** — using base class pointers and virtual functions
* **Pure Virtual Functions** — creating abstract classes
* **Function Overloading** — same function name with different parameters
* **Operator Overloading** — redefining operators like `+`, `==`, `*`, `[]`, `()`
* **Friend Functions** — accessing private members for operator overloading
* **Dynamic Binding** — function call resolved at runtime
* **Type Conversion**

  * Basic → Object (constructor)
  * Object → Basic (conversion operator)
  * Object → Object (conversion constructor)
* **Real-world Modeling** — shapes, students, time, matrices, coordinates

---

## ▶️ How to Run

1. **Clone this repository:**

   ```bash
   git clone https://github.com/parminderrathour/OOPS-assignment-7.git
   cd OOPS-assignment-7
   ```

2. **Compile the file using g++:**

   ```bash
   g++ parminder_ass7.cpp -o output
   ```

3. **Run the output:**

   ```bash
   ./output
   ```

> 💡 Only one `main()` function is active at a time.
> To run other questions, comment/uncomment the respective code blocks.

---

## 📁 File Structure

```
OOPS-assignment-7/
│
├── parminder_ass7.cpp     # Main C++ file with all 13 solutions
└── README.md              # Project documentation (this file)
```

---

## 🛠️ Tools & Environment

* **Language:** C++
* **Compiler:** GCC / G++
* **IDE:** VS Code / Code::Blocks / Dev-C++

---

<p align="center">Made with ❤️ by Parminder Rathour</p>
