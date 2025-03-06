# Hospital-Management-System

## Overview
This project is a **Hospital Management System** implemented in C++ using **Object-Oriented Programming (OOP)** principles. It allows managing hospital departments, employees (doctors and nurses), patients, and research centers.

## Features
- **Department Management:** Add, remove, and list hospital departments.
- **Staff Management:** Add doctors and nurses, associate them with departments.
- **Patient Management:** Add and track patient visits, assign them to departments.
- **Research Center:** Add researchers and associate them with medical articles.
- **Interactive Console Interface:** Provides a menu-driven experience for managing the hospital system.

## Technologies Used
- **C++** with OOP (Classes, Inheritance, Polymorphism)
- **Dynamic Memory Allocation** (`new[]`, `delete[]`)
- **Operator Overloading** (`operator=`, `operator<<`)
- **Encapsulation & Data Structures**
- **File Handling (Future Implementation)**

## Project Structure
```
📂 Hospital Management System
├── 📜 main.cpp              # Entry point - main menu interface
├── 📜 hospital.h/.cpp       # Core hospital functionalities
├── 📜 department.h/.cpp     # Hospital department management
├── 📜 employee.h/.cpp       # Employee base class
├── 📜 doctor.h/.cpp         # Doctor class (inherits from Employee)
├── 📜 nurse.h/.cpp          # Nurse class (inherits from Employee)
├── 📜 patient.h/.cpp        # Patient management
├── 📜 person.h/.cpp         # Base class for people in the system
├── 📜 article.h/.cpp        # Research article management
├── 📜 researcher.h/.cpp     # Researcher entity
├── 📜 researchCenter.h/.cpp # Research center management
├── 📜 researcherDoctor.h/.cpp # Doctor-Researcher hybrid class
├── 📜 Project3.vcxproj      # Visual Studio project file
├── 📜 Project3.vcxproj.filters # Visual Studio project filter
├── 📜 README.md             # Project documentation
```

## Installation & Usage
### Compilation
To compile the project, use a C++ compiler such as `g++`:
```bash
 g++ -o hospital_management main.cpp hospital.cpp department.cpp employee.cpp doctor.cpp nurse.cpp patient.cpp person.cpp article.cpp researcher.cpp researchCenter.cpp researcherDoctor.cpp -std=c++11
```

### Running the Program
After compiling, execute:
```bash
 ./hospital_management
```

### Example Usage
1. Add a new department (e.g., "Cardiology").
2. Register doctors and nurses to the department.
3. Add patients and assign them to departments.
4. Search for a patient by ID.
5. View all hospital employees.

## Future Improvements
- **File Handling:** Save and load hospital data from files.
- **GUI Interface:** Implement a graphical interface.
- **Database Integration:** Store patient and staff data in a SQL database.

## Author
**[Your Name]** - Developed as part of a university project.

## License
This project is released under the MIT License.

