# Student Management Hub

Student Management Hub is a console-based application developed in C. It provides functionality for user authentication, student management, and course management. The application demonstrates the use of file handling, input validation, and basic CRUD operations.

## Features

1. **Input Validation**
    - Ensures that user inputs are valid and within expected ranges.
    - Prompts the user to re-enter data if the input is invalid.

2. **Menu**
    - Displays a user-friendly menu for navigating through different features of the application.
    - Options include Login, New User Registration, and various student and course management operations.

3. **Login**
    - Users can log in using a username and password.
    - Credentials are validated against a stored text file.
    - Clears the screen and grants access upon successful login.

4. **Database - Files**
    - Stores user credentials, student details, and course details in text files.
    - Reads and writes data to files for persistence.

5. **CRUD Operations**
    - **Students**
        - Create: Add new student records.
        - Read: View student details.
        - Update: Modify existing student records.
        - Delete: Remove student records.
    - **Courses**
        - Create: Add new course records.
        - Read: View course details.
        - Update: Modify existing course records.
        - Delete: Remove course records.
    - **Additional Operations**
        - Calculate and display fees (bayo yuran).

6. **Reports**
    - Generate reports on the total number of students and courses.
    - Display other relevant statistics.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Basic knowledge of C programming

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/student-management-hub.git
    ```
2. Navigate to the project directory:
    ```bash
    cd student-management-hub
    ```
3. Compile the project:
    ```bash
    gcc -o app main.c
    ```

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open an issue for any bugs or feature requests.

## License

This project is licensed under the MIT License.

## Acknowledgements

- Special thanks to the developers and contributors who have helped in creating this project.
- Thank you for using Student Management Hub!

Hafiz
