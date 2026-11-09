# Employee Management System

A console-based **Employee Management System** built in **C** that provides complete CRUD operations with permanent binary file storage.

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

---

## 📋 Overview

This project demonstrates core C programming concepts including **Structures**, **Functions**, and **File Handling**. It allows users to manage employee records efficiently through a simple menu-driven interface.

**Key Features:**
- Add new employees with auto-generated unique IDs
- Display all employee records in a clean table format
- Search employees by ID or Name (case-insensitive)
- Update existing employee details
- Delete employee records safely
- Permanent storage using binary files (`employees.dat`)

---

## 🎯 Objectives

- Develop a menu-driven Employee Management System in C
- Implement Add, Update, Delete, and Search operations
- Store data permanently using binary file handling
- Demonstrate Structures, Functions, and File I/O in C

---

## 🛠️ System Requirements

| Component       | Recommended              | Minimum              |
|-----------------|--------------------------|----------------------|
| Operating System| Windows 11 / Linux / macOS | Any modern OS       |
| Compiler        | GCC / MinGW / Dev-C++    | Any C99-compatible compiler |
| Language        | C (ANSI C / C99)         | C                    |
| RAM             | 8 GB                     | 2 GB or higher       |

---

## 📁 Project Structure

```
Employee-Management-System/
├── main.c                 # Main source code
├── employees.dat          # Binary data file (created at runtime)
└── README.md              # This file
```

---

## 🏗️ Data Structure

```c
struct Employee {
    int id;
    char name[50];
    char dept[50];
    float salary;
};
```

All records are stored in the binary file: **`employees.dat`**

---

## 🚀 Modules

| Module              | Description                                      |
|---------------------|--------------------------------------------------|
| **Add Employee**    | Adds a new employee with auto-generated ID       |
| **Display All**     | Shows all employee records in table format       |
| **Search by ID**    | Finds an employee using unique Employee ID       |
| **Search by Name**  | Case-insensitive search by employee name         |
| **Update Employee** | Modifies existing employee details               |
| **Delete Employee** | Removes an employee record from the file         |

---

## ✨ Implementation Highlights

- **Auto-increment Employee ID** — Automatically assigns the next available ID
- **Binary File Storage** — Uses `fwrite()` / `fread()` for permanent storage
- **In-place Update** — Uses `fseek()` to update records directly
- **Safe Delete** — Copies remaining records to a temporary file
- **Case-insensitive Search** — Name search works regardless of case

---

## 💻 How to Compile & Run

### Using GCC (Linux / macOS / Windows with MinGW)

```bash
gcc main.c -o employee_management
./employee_management
```

### Using Dev-C++
1. Open `main.c` in Dev-C++
2. Go to **Execute → Compile & Run** (or press `F11`)

---

## 🧪 Testing

| Test No. | Test Case              | Expected Result       | Status |
|----------|------------------------|-----------------------|--------|
| 01       | Add new employee       | Record saved          | ✅ Pass |
| 02       | Display all employees  | All records listed    | ✅ Pass |
| 03       | Search by valid ID     | Details shown         | ✅ Pass |
| 04       | Search by invalid ID   | Not found message     | ✅ Pass |
| 05       | Update record          | Data updated          | ✅ Pass |
| 06       | Delete record          | Record removed        | ✅ Pass |

---

## ✅ Advantages

- Simple and intuitive menu-driven interface
- Permanent binary file storage (no external database required)
- Fast search by both ID and Name
- Lightweight and efficient

## ⚠️ Limitations

- Console-based (no Graphical User Interface)
- No login / authentication system
- Limited employee fields (ID, Name, Department, Salary)

---

## 🔮 Future Scope

- Add a Graphical User Interface (GUI)
- Implement login and authentication
- Add more fields (Date of Joining, Contact, Designation, etc.)
- Migrate to a database (SQLite / MySQL)
- Export data to CSV / PDF

---

## 🎓 Academic Details

| Detail              | Information                                      |
|---------------------|--------------------------------------------------|
| **Submitted By**    | Himanshu Gupta                                   |
| **Branch**          | Computer Science & Engineering                   |
| **Course**          | C-Codex                                          |
| **Guided By**       | SHRA Technology                                  |
| **Academic Year**   | 2025 – 2026                                      |
| **Institution**     | Government Polytechnic Adampur, Tarabganj, Gonda  |

---