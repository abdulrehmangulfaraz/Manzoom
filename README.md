# Manzoom - A Literary Management System

## Overview
Manzoom is a **Literary Management System** inspired by Rekhta, developed in **C++**, and designed to combine the beauty of literature with the efficiency of technology. It enables users to explore, manage, and contribute to a collection of Urdu poetry while providing role-based access for Readers, Poets, and Administrators.

## Features
### 1. Normal User
- **Random Poetry Display**: Enjoy a new poetry snippet on every login.
- **Search and Navigation**: Easily search for poets, poetry, and favorite verses.
- **Profile Management**: Update your name and credentials effortlessly.

### 2. Poet
- **Poetry Submission**: Submit your work to the system for review and approval.
- **Role-Specific Access**: Focus on contributions without viewing approval counts.

### 3. Administrator (Hidden)
- **Predefined Account**: Access the admin role by entering `10` in the main menu and using the password `1`.
- **Manage Users and Submissions**: Oversee system operations, approve poetry, and handle data integrity.

## Technical Details
- **Language**: C++
- **Data Structures**: Implemented using Binary Search Trees (BSTs), Linked Lists, and Hash Maps.
- **File-Based Persistence**: Ensures data remains intact even after the system shuts down.
- **Directory Structure**: Organized for logical storage and retrieval of user, poet, and poetry data.
- **Login System**: A user-friendly interface that asks for account type upon startup.

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/abdulrehmangulfaraz/manzoom.git
   ```
2. Navigate to the project directory:
   ```bash
   cd manzoom
   ```
3. Compile and run the program using your preferred C++ compiler.
   ```bash
   g++ -o Manzoom main.cpp
   ./Manzoom
   ```
4. Follow the on-screen instructions to log in or sign up as a Normal User, Poet, or Administrator.

## Admin Access
The **Administrator** role is hidden and requires a specific entry to access:
- Enter `10` in the first menu.
- Use the password: `AbdulRehman`.

## Contribution
We welcome contributions to improve this project. Feel free to fork the repository, make changes, and submit a pull request. Make sure your contributions align with the project goals and maintain code quality.

## Acknowledgments
- Inspired by Rekhta for its dedication to Urdu literature.
- Grateful for the collaboration and support in bringing this project to life.

## Contact
For questions or feedback, please reach out via [LinkedIn](https://www.linkedin.com/in/abdulrehman-gulfaraz) or create an issue in the repository.

## 📄 License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and distribute it with proper credit.

---
Thank you for exploring **Manzoom**! Together, let’s celebrate the beauty of Urdu literature. 🥀

