#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_TASKS 20

struct student {
    char name[50];
    char email[50];
    char password[21];
    char tasks[MAX_TASKS][100];
    int currentTaskIndex;
};

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    struct student students[MAX_STUDENTS];
    int tail = 0;
    int currentUser = -1; // -1 means no one logged in

    while (1) {
        char command[20];
        printf(">> ");
        fgets(command, sizeof(command), stdin);
        removeNewline(command);

        /* SIGNUP */
        if (strcmp(command, "signup") == 0) {
            if (tail >= MAX_STUDENTS) {
                printf("User limit reached!\n");
                continue;
            }

            struct student newStudent = {0};

            printf("Name: ");
            fgets(newStudent.name, sizeof(newStudent.name), stdin);
            removeNewline(newStudent.name);

            printf("Email: ");
            fgets(newStudent.email, sizeof(newStudent.email), stdin);
            removeNewline(newStudent.email);

            printf("Password: ");
            fgets(newStudent.password, sizeof(newStudent.password), stdin);
            removeNewline(newStudent.password);

            students[tail++] = newStudent;
            printf("Signup successful!\n");
        }

        /* LOGIN */
        else if (strcmp(command, "login") == 0) {
            char email[50], password[21];
            int found = 0;

            printf("Email: ");
            fgets(email, sizeof(email), stdin);
            removeNewline(email);

            printf("Password: ");
            fgets(password, sizeof(password), stdin);
            removeNewline(password);

            for (int i = 0; i < tail; i++) {
                if (strcmp(email, students[i].email) == 0 &&
                    strcmp(password, students[i].password) == 0) {
                    currentUser = i;
                    found = 1;
                    printf("Welcome %s!\n", students[i].name);
                    break;
                }
            }

            if (!found) {
                printf("Invalid credentials!\n");
            }
        }

        /* ADD TASK */
        else if (strcmp(command, "add") == 0) {
            if (currentUser == -1) {
                printf("Please login first!\n");
                continue;
            }

            if (students[currentUser].currentTaskIndex >= MAX_TASKS) {
                printf("Task limit reached!\n");
                continue;
            }

            printf("Enter task: ");
            fgets(
                students[currentUser]
                    .tasks[students[currentUser].currentTaskIndex],
                100,
                stdin
            );

            students[currentUser].currentTaskIndex++;
            printf("Task added!\n");
        }

        /* SHOW TASKS */
        else if (strcmp(command, "list") == 0) {
            if (currentUser == -1) {
                printf("Please login first!\n");
                continue;
            }

            for (int i = 0; i < students[currentUser].currentTaskIndex; i++) {
                printf("%d. %s", i + 1, students[currentUser].tasks[i]);
            }
        }

        /* EXIT */
        else if (strcmp(command, "exit") == 0) {
            printf("Bye Bye!\n");
            break;
        }

        else {
            printf("Unrecognised command!\n");
        }
    }

    return 0;
}
