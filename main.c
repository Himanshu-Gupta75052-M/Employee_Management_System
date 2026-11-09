#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define file "employees.dat"
#define NAME 50
#define DEPT 50

struct Employee {
    int id;
    char name[NAME];
    char dept[DEPT];
    float salary;
};

// Function prototypes
void addEmployee();
void displayAll();
void searchById();
void searchByName();
void updateEmployee();
void deleteEmployee();
void menu();
int getNextId();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n\n=================================================================================\n");
        printf("                          EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("=================================================================================\n");
        printf("	1. Add Employee\t\t\t");
        printf("2. Display All Employees\n");
        printf("	3. Search by Employee ID\t");
        printf("4. Search by Name\n");
        printf("	5. Update Employee\t\t");
        printf("6. Delete Employee\n");
        printf("	7. Exit\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchById(); break;
            case 4: searchByName(); break;
            case 5: updateEmployee(); break;
            case 6: deleteEmployee(); break;
            case 7: 
                printf("\nThank you for using Employee Management System!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int getNextId() {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) return 01;

    struct Employee emp;
    int maxId = 00;
    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id > maxId) maxId = emp.id;
    }
    fclose(fp);
    return maxId + 1;
}

void addEmployee() {
    FILE *fp = fopen(file, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Employee emp;
    emp.id = getNextId();

    printf("\n--- Add New Employee ---\n");
    printf("Employee ID (auto): %d\n", emp.id);

    printf("Enter Name: ");
    fgets(emp.name, NAME, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Department: ");
    fgets(emp.dept, DEPT, stdin);
    emp.dept[strcspn(emp.dept, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    getchar();

    fwrite(&emp, sizeof(emp), 1, fp);
    fclose(fp);

    printf("\nEmployee added successfully!\n");
}

void displayAll() {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    struct Employee emp;
    int count = 0;

    printf("\n%-8s %-25s %-35s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        printf("%-8d %-25s %-35s %-12.2f\n", emp.id, emp.name, emp.dept, emp.salary);
        count++;
    }
    fclose(fp);

    if (count == 0)
        printf("No employees found.\n");
    else
        printf("\nTotal Employees: %d\n", count);
}

void searchById() {
    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Employee emp;
    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == id) {
            printf("\n--- Employee Found ---\n");
            printf("\n%-8s %-25s %-35s %-12s\n", "ID", "Name", "Department", "Salary");
            printf("---------------------------------------------------------------------------------\n");
            printf("%-8d %-25s %-35s %-12.2f\n", emp.id, emp.name, emp.dept, emp.salary);
            // 
            // printf("ID         : %d\n", emp.id);
            // printf("Name       : %s\n", emp.name);
            // printf("Department : %s\n", emp.dept);
            // printf("Salary     : %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Employee with ID %d not found!\n", id);
}

void searchByName() {                  // case-insensitive
    char name[NAME];
    int found = 0;

    printf("\nEnter Name to search: ");
    fgets(name, NAME, stdin);
    name[strcspn(name, "\n")] = 0;

    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Employee emp;
    printf("\n                          --- Employee Details ---\n");
    printf("\n%-8s %-25s %-35s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (strcasecmp(emp.name, name) == 0) {  
            printf("%-8d %-25s %-35s %-12.2f\n", emp.id, emp.name, emp.dept, emp.salary);
            found = 1;
        }
    }
    fclose(fp);

    if (!found)
        printf("No employee found with name \"%s\"\n", name);
}

void updateEmployee() {
    int id, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(file, "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct Employee emp;
    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == id) {
            printf("\nCurrent Details:\n");
            printf("Name       : %s\n", emp.name);
            printf("Department : %s\n", emp.dept);
            printf("Salary     : %.2f\n", emp.salary);

            printf("\nEnter New Name: ");
            fgets(emp.name, NAME, stdin);
            emp.name[strcspn(emp.name, "\n")] = 0;

            printf("Enter New Department: ");
            fgets(emp.dept, DEPT, stdin);
            emp.dept[strcspn(emp.dept, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);
            getchar();

            fseek(fp, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);
            found = 1;
            printf("\nEmployee updated successfully!\n");
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Employee with ID %d not found!\n", id);
}

void deleteEmployee() {
    int id, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    getchar();

    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    struct Employee emp;
    while (fread(&emp, sizeof(emp), 1, fp) == 1) {
        if (emp.id == id) {
            found = 1;
            printf("\nDeleting Employee:\n");
            printf("ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
                   emp.id, emp.name, emp.dept, emp.salary);
        } else {
            fwrite(&emp, sizeof(emp), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(file);
        rename("temp.dat", file);
        printf("Employee deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Employee with ID %d not found!\n", id);
    }
}