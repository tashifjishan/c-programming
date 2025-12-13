#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

struct Student {
    int id;
    char name[50];
    float marks;
};


// ---------------- ADD RECORD ----------------
void addRecord() {
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("Unable to open file!\n");
        return;
    }

    struct Student s;
    printf("\nEnter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.id, s.name, s.marks);
    fclose(fp);
    printf("\nRecord added successfully!\n");
}


// ---------------- VIEW ALL RECORDS ----------------
void viewRecords() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    struct Student s;
    printf("\n--- STUDENT RECORDS ---\n");

    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks) != EOF) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
}


// ---------------- SEARCH RECORD ----------------
void searchRecord() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    int id;
    struct Student s;
    int found = 0;

    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks) != EOF) {
        if (s.id == id) {
            printf("\nRecord found:\n");
            printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found!\n");
    }

    fclose(fp);
}


// ---------------- UPDATE RECORD ----------------
void updateRecord() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("\nError opening file!\n");
        return;
    }

    int id;
    struct Student s;
    int found = 0;

    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks) != EOF) {
        if (s.id == id) {
            found = 1;
            printf("\nEnter new Name: ");
            scanf("%s", s.name);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);
        }
        fprintf(temp, "%d %s %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nRecord updated successfully!\n");
    else
        printf("\nRecord not found!\n");
}


// ---------------- DELETE RECORD ----------------
void deleteRecord() {
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("\nError opening file!\n");
        return;
    }

    int id;
    struct Student s;
    int found = 0;

    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f", &s.id, s.name, &s.marks) != EOF) {
        if (s.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fprintf(temp, "%d %s %.2f\n", s.id, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nRecord not found!\n");
}


// ---------------- MENU ----------------
int main() {
    int choice;

    while (1) {
        printf("\n====== STUDENT RECORD SYSTEM (TEXT FILES) ======\n");
        printf("1. Add Record\n");
        printf("2. View All Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
