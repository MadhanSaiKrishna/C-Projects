# **Employee Database** 

You are tasked with developing a simple employee database system in C. The program should be capable of performing the following operations:

 -  **Add Employee**:
    Prompt the user to enter the employee’s details (Employee ID, Name, Position, and Salary).
    Add the employee to the database.

-  **Display Employees**:
    Display a list of all employees in the database, including their details.

-   **Search Employee**:
    Prompt the user to enter an Employee ID.
    Display the details of the employee with the given ID if found; otherwise, show a message indicating that the employee was not found.

-   **Update Salary**:
    Prompt the user to enter an Employee ID.
    If the employee is found, allow the user to update the salary for that employee.

 -  **Delete Employee**:
    Prompt the user to enter an Employee ID.
    If the employee is found, remove the employee from the database.

  - **Exit**:
    Terminate the program.

**Requirements**:

  -  Use structures to represent an employee’s details.
  -  Implement dynamic memory allocation for storing employee records.
  -  Use functions to modularize the code (e.g., separate functions for adding, displaying, searching, updating, and deleting employees).

Example run of the program

``` 
Employee Database Management System

1. Add Employee
2. Display Employees
3. Search Employee
4. Update Salary
5. Delete Employee
6. Exit

Enter your choice: 1
Enter Employee ID: 101
Enter Name: John Doe
Enter Position: Software Engineer
Enter Salary: 60000

Employee added successfully!

Enter your choice: 2
Employee List:

ID    Name               Position               Salary
-----------------------------------------------------
101   John Doe           Software Engineer      60000

Enter your choice: 3
Enter Employee ID to search: 101

Employee Found!

ID    Name               Position               Salary
-----------------------------------------------------
101   John Doe           Software Engineer      60000

Enter your choice: 4
Enter Employee ID to update salary: 101
Enter new salary: 65000

Salary updated successfully!

Enter your choice: 5
Enter Employee ID to delete: 101

Employee deleted successfully!

Enter your choice: 2
Employee List: (empty)

Enter your choice: 6
Exiting the program...

```


