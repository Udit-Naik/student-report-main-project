[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=c%2B%2B)](https://isocpp.org)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](./LICENSE)
[![Version](https://img.shields.io/badge/Version-1.0.0-brightgreen?style=flat-square)](#)
[![Status](https://img.shields.io/badge/Status-Completed-success?style=flat-square)](#)

# 🎓 STUDENT REPORT MANAGEMENT SYSTEM (C++)

A **C++ console-based project** built for managing student academic records with role-based access.  
This system provides separate dashboards for **Admin**, **Faculty**, and **Student**, ensuring secure and organized record handling.

---

## 🏠 HOME PAGE

When the program starts, the following menu appears:

========== HOME PAGE ==========

1️⃣ Login as Admin
2️⃣ Login as Faculty
3️⃣ Login as Student
4️⃣ Exit System

Each user logs in with valid credentials and is redirected to their respective dashboard.

---

## 👑 ADMIN PANEL

### 🔐 Login:
- **ID:** admin  
- **Password:** *****  

Once logged in, the Admin can manage both faculty and student records.

### 🧭 Admin Menu:

1. ⚙️ **View & Publish Result**  
   ➤ Display all student results and publish/unpublish them.

2. ➕ **Add New Student**  
   ➤ Register a new student into the system.

3. 📋 **View Existing Student Record**  
   ➤ View the list of all registered students.

4. ✏️ **Modify Existing Student Record**  
   ➤ Edit or update student information.

5. 📊 **Upload Student Marks**  
   ➤ Input marks and calculate overall performance.

6. 🔍 **View Specific Student Marks**  
   ➤ Search a student by roll number to view results.

7. ❌ **Delete Student Record**  
   ➤ Permanently remove a student record.

8. 👩‍🏫 **Add New Faculty**  
   ➤ Register a new faculty member.

9. 📚 **View Existing Faculty**  
   ➤ Display all faculty profiles.

10. 📝 **Modify Faculty Record**  
    ➤ Update faculty information.

11. 🗑️ **Delete Faculty Record**  
    ➤ Delete faculty record from the database.

12. 🚪 **Log Out**  
    ➤ Return to the home screen.

---

## 👨‍🏫 FACULTY PANEL

### 🔐 Login:
Faculty logs in using:
- **Faculty ID:** (e.g., 101)  
- **Password:** ****  

### 🧭 Faculty Menu:

1. 👤 **View Profile**  
   ➤ Display personal faculty details.

2. 👩‍🎓 **View Student Records**  
   ➤ Access all student information.

3. 📈 **Upload Student Marks**  
   ➤ Enter marks for assigned students.

4. 🔍 **View Specific Student Marks**  
   ➤ Search and view student results.

5. 💬 **View Student Queries**  
   ➤ Check all queries submitted by students.

6. 📨 **Reply to Query**  
   ➤ Send responses to student questions.

7. 🚪 **Log Out**  
   ➤ Return to the home page.

---

## 👨‍🎓 STUDENT PANEL

### 🔐 Login:
Student logs in with:
- **Roll No:** (e.g., 1001)  
- **Password:** ******  

### 🧭 Student Menu:

1. 👤 **View Profile**  
   ➤ See personal details.

2. 💬 **Send Query to Faculty**  
   ➤ Ask questions or clarifications.

3. 📩 **View My Queries**  
   ➤ Check responses from faculty.

4. 📜 **View Result**  
   ➤ View published marks and performance.

5. 🚪 **Log Out**  
   ➤ Return to main menu.

---

## 🧠 SYSTEM FUNCTIONALITY OVERVIEW

✔️ **Role-Based Authentication** (Admin, Faculty, Student)  
✔️ **CRUD Operations** for student and faculty management  
✔️ **Marks Upload & Result Publishing**  
✔️ **Secure Query System** (Student ↔ Faculty)  
✔️ **File Handling** for permanent data storage  
✔️ **Modular Menu System** for easy navigation  

---

## ⚙️ TECHNOLOGY USED

| Component | Description |
|------------|--------------|
| 💻 Language | C++ |
| 📂 Data Storage | File Handling (Text Files) |
| 🧠 Architecture | Object-Oriented Programming |
| 🔒 Security | Role-based Login Authentication |
| 🧰 Interface | Console-based UI |

---

## 📋 SAMPLE EXECUTION


---

## 💡 FEATURES SUMMARY

- 🧑‍💼 Admin manages faculty & students  
- 👨‍🏫 Faculty can upload marks & reply to queries  
- 👨‍🎓 Students can view results & send queries  
- 💾 All data stored using file handling  
- 🧱 Developed using **C++ OOP principles**

---

## 🚀 HOW TO RUN

1️⃣ Clone the repository:
```bash
git clone https://github.com/Udit-Naik/student-report-main-project.git
