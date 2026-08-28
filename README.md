# Library Catalog and Account Management System

A C++ library management application for organizing a book catalog, searching for books, and managing borrowing and return operations.

The application uses custom data structures and algorithms to organize catalog data and provide efficient access to book records. Catalog and account information is stored through local text files so that data can be retained between sessions.

## Features

* View and manage a library book catalog
* Search the catalog for books by title
* Borrow and return books
* Track books associated with library users
* Load and save catalog data using text files
* Sort catalog records for organized retrieval
* Generate identifiers from book information using hashing

## Data Structures and Algorithms

The system implements several core data structures and algorithms rather than relying entirely on built in containers and sorting utilities.

### Linked List

Catalog records can be stored and manipulated through a custom linked list implementation.

### Merge Sort

Merge sort is used to organize catalog data before it is transferred into the search structure.

### Binary Search Tree

Sorted catalog information is incorporated into a binary search tree to support structured storage, traversal, insertion, searching, and deletion.

### Hashing

Book information is converted into numeric identifiers through a hashing function used by the catalog system.

## Application

The command line interface provides the main library operations:

1. View the book catalog
2. Search for a book
3. Borrow a book
4. Return a book
5. Exit the application

Catalog and client records are read from and written to local text files.

## Built With

* C++
* Object oriented programming
* Linked lists
* Binary search trees
* Merge sort
* Hashing
* File I/O

## Repository Structure

`LibrarySystem.cpp`
Contains the main library application and command line interface.

`catalog.txt`
Stores book catalog data used by the application.

`Client.txt`
Stores client and borrowing information.

`linListTxtTest.cpp`
Linked list and file handling implementation/testing.

`sortedLinListToBST.cpp`
Contains logic for transferring sorted linked list data into a binary search tree.

`bstOutline.cpp`
Binary search tree implementation and supporting operations.

## Running the Application

Clone the repository:

```bash
git clone https://github.com/SamN123/Library-Catalog-and-Account-Management.git
```

Move into the project directory:

```bash
cd Library-Catalog-and-Account-Management
```

Compile the application with a C++ compiler. For example:

```bash
g++ LibrarySystem.cpp -o library
```

Run the executable:

```bash
./library
```

## Purpose

This project explores how common data structures can be combined in a larger C++ application rather than implemented only as isolated examples. The library system provides a practical use case for sorting, searching, persistent file storage, and managing relationships between books and users.
