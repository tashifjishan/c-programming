#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ----------- Function Declarations -----------
void createFile();
void writeFile();
void appendFile();
void readFile();
void renameFile();
void copyFile();
void deleteFile();
void searchInFile();
void fileSize();
void checkExists();
void listFiles();


int main() {
    int choice;

    while (1) {
        printf("\n========== FILE OPERATIONS MENU ==========\n");
        printf("1. Create File\n");
        printf("2. Write to File (overwrite)\n");
        printf("3. Append to File\n");
        printf("4. Read File\n");
        printf("5. Search Text in File\n");
        printf("6. Copy File\n");
        printf("7. Rename File\n");
        printf("8. Delete File\n");
        printf("9. Check if File Exists\n");
        printf("10. Get File Size\n");
        printf("11. List Files (Windows only)\n");
        printf("12. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline

        switch (choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: appendFile(); break;
            case 4: readFile(); break;
            case 5: searchInFile(); break;
            case 6: copyFile(); break;
            case 7: renameFile(); break;
            case 8: deleteFile(); break;
            case 9: checkExists(); break;
            case 10: fileSize(); break;
            case 11: listFiles(); break;
            case 12: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}



// ---------------- CREATE FILE ----------------
void createFile() {
    char filename[100];
    printf("\nEnter filename to create: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error creating file!\n");
        return;
    }

    printf("File created successfully.\n");
    fclose(fp);
}



// ---------------- WRITE TO FILE ----------------
void writeFile() {
    char filename[100], text[500];

    printf("\nEnter filename: ");
    scanf("%s", filename);
    getchar();

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to write (end with ~):\n");
    int c;
    while ((c = getchar()) != '~')
        fputc(c, fp);

    fclose(fp);
    printf("File written successfully.\n");
}



// ---------------- APPEND TO FILE ----------------
void appendFile() {
    char filename[100];

    printf("\nEnter filename: ");
    scanf("%s", filename);
    getchar();

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to append (end with ~):\n");
    int c;
    while ((c = getchar()) != '~')
        fputc(c, fp);

    fclose(fp);
    printf("Text appended successfully.\n");
}



// ---------------- READ FILE ----------------
void readFile() {
    char filename[100];
    printf("\nEnter filename to read: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- FILE CONTENT ---\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
}



// ---------------- SEARCH TEXT INSIDE FILE ----------------
void searchInFile() {
    char filename[100], word[50];
    printf("\nEnter filename: ");
    scanf("%s", filename);
    printf("Enter word to search: ");
    scanf("%s", word);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    char buffer[1000];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, word)) {
            printf("Found: %s", buffer);
            found = 1;
        }
    }

    if (!found)
        printf("Word not found!\n");

    fclose(fp);
}



// ---------------- COPY FILE ----------------
void copyFile() {
    char src[100], dest[100];
    printf("\nEnter source filename: ");
    scanf("%s", src);
    printf("Enter destination filename: ");
    scanf("%s", dest);

    FILE *fs = fopen(src, "r");
    if (!fs) {
        printf("Source file not found!\n");
        return;
    }

    FILE *fd = fopen(dest, "w");

    char ch;
    while ((ch = fgetc(fs)) != EOF)
        fputc(ch, fd);

    fclose(fs);
    fclose(fd);

    printf("File copied successfully.\n");
}



// ---------------- RENAME FILE ----------------
void renameFile() {
    char oldname[100], newname[100];
    printf("\nEnter current filename: ");
    scanf("%s", oldname);
    printf("Enter new filename: ");
    scanf("%s", newname);

    if (rename(oldname, newname) == 0)
        printf("File renamed successfully.\n");
    else
        printf("Error renaming file!\n");
}



// ---------------- DELETE FILE ----------------
void deleteFile() {
    char filename[100];
    printf("\nEnter filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
        printf("File deleted successfully.\n");
    else
        printf("Error deleting file!\n");
}



// ---------------- CHECK IF FILE EXISTS ----------------
void checkExists() {
    char filename[100];
    printf("\nEnter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp) {
        printf("File exists.\n");
        fclose(fp);
    } else {
        printf("File does NOT exist.\n");
    }
}



// ---------------- FILE SIZE ----------------
void fileSize() {
    char filename[100];
    printf("\nEnter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);

    printf("File size: %ld bytes\n", size);
}



// ---------------- LIST FILES (Windows only) ----------------
void listFiles() {
#ifdef _WIN32
    system("dir");
#else
    printf("This feature works on Windows only.\n");
#endif
}
