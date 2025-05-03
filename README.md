# C++ Polymorphism & Inheritance - Book Management Example

This project demonstrates fundamental object-oriented programming (OOP) concepts in C++, focusing on **inheritance**, **polymorphism**, and **abstract classes**. It uses a simple book management system to show how these concepts work in practice.

## ?? Features

- Base class: `Book`
- Derived classes: `FictionBook`, `AcademicBook`
- A `Librarian` class with access to private/protected members using `friend`
- Use of:
  - `virtual` functions and `override`
  - Polymorphic behavior with base class pointers
  - `dynamic_cast` for calling derived-class-specific methods

## ?? Technologies

- Language: C++
- Concepts: OOP, inheritance, polymorphism, virtual functions, friend classes

## ?? Example Output

```cpp
FictionBook Title: Suç ve Ceza
FictionBook Author: Dostoyevski
Genre: Kurgu
AcademicBook Title: Reader at work 1
AcademicBook Author: METU
Field: Dil
librarian name is: Özkan
Title is updated
Privet Details:
Title: Sýrça Köþk
Author: Dostoyevski
Year: 1995
Year is updated.
