#include <stdio.h>
#include <string.h>

struct Student {
    char id[50];
    char name[50];
    float gpa;
};

void bubbleSortByName(struct Student arr[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByGpa(struct Student arr[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].gpa> arr[j + 1].gpa) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayStudents(struct Student arr[], int n) {
    printf("ID\t\tName\t\tGpa\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t\t%.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}

int searchById(struct Student arr[], int n, const char *id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            return i; 
        }
    }
    return -1; 
}

int searchByName(struct Student arr[], int n, const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    struct Student students[] = {
        {"bit230371", "Duy", 3.5},
        {"bit230001", "Khanh", 3.7},
        {"bit230230", "Giang", 3.0},
        {"bit230345", "Ly", 3.8},
        {"bit230370", "Quyen", 4.0}
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    printf("Danh sach sinh vien truoc khi sap xep:\n");
    
    displayStudents(students, numStudents);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    
	bubbleSortByName(students, numStudents);
    displayStudents(students, numStudents);

    printf("\nDanh sach sinh vien sau khi sap xep theo diem so:\n");
    
    bubbleSortByGpa(students, numStudents);
    displayStudents(students, numStudents);
    
	printf("\n");
	printf("Sinh vien muon tim co ID:");
    char searchId[30];
    gets(searchId);
    int foundId = searchById(students, numStudents, searchId);
    if (foundId != -1) {
        printf("\nSinh vien co ID %s la : %s\n", searchId, students[foundId].name);
    } else {
        printf("\nKhong tim thay sinh vien co ID : %d\n", searchId);
    }
    return 0;
}

