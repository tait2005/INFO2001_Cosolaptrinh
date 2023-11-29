#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100 

struct Employee {
    char Id[30];
    char name[50];
    char position[50];
    float wage;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0; 

void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        printf("Nhap thong tin cho nhan vien moi:\n");
        printf("Ma nhan vien: ");
        getchar();
        gets(newEmployee.Id);
        printf("Ten nhan vien: ");
        gets(newEmployee.name);
        printf("Chuc vu: ");
        gets(newEmployee.position);
        printf("Luong: ");
        scanf("%f", &newEmployee.wage);

        employees[employeeCount++] = newEmployee;
        printf("Da them nhan vien moi.\n");
    } else {
        printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
    }
}

void deleteEmployee(const char *Id) {
	struct Employee newEmployee;
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].Id == Id) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Da xoa nhan vien co ma nhan vien: %s\n",newEmployee.Id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nhan vien co ma nhan vien: %s\n",newEmployee.Id);
    }
}

void displayEmployees() {
    printf("Danh sach nhan vien:\n");
    printf("MaNV\t\tTen\t\tChucVu\t\tLuong\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%s\t%s\t%s\t%.2f\n", employees[i].Id, employees[i].name,
               employees[i].position, employees[i].wage);
    }
}

void sortEmployeesByName() {
    struct Employee temp;
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep nhan vien theo ten.\n");
}

int main() {
    int choice;
    do{
        printf("\nMENU:\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien theo ten\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                if (employeeCount > 0) {
                    char Id[30];
                    printf("Nhap ma nhan vien can xoa: ");
                    getchar();
                    gets(Id);
                    deleteEmployee(Id);
                } else {
                    printf("Danh sach nhan vien rong. Khong co nhan vien de xoa.\n");
                }
                break;
            case 3:
                if (employeeCount > 0) {
                    displayEmployees();
                } else {
                    printf("Danh sach nhan vien rong.\n");
                }
                break;
            case 4:
                if (employeeCount > 0) {
                    sortEmployeesByName();
                } else {
                    printf("Danh sach nhan vien rong.\n");
                }
                break;
            case 5:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
            }
        } while (choice !=5);
    return 0;
}

  


