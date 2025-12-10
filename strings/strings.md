# String Methods:

- strlen

strlen("hello"); // Output: 5


- strcpy
char dest[20];
strcpy(dest, "hello"); // dest = "hello"

-strncpy

char dest[20];
strncpy(dest, "abcdef", 3);
dest[3] = '\0'; // dest = "abc"


- strcmp

strcmp("apple", "apple");   // 0 (equal)
strcmp("apple", "banana");  // negative
strcmp("banana", "apple");  // positive


- strncmp

strncmp("application", "apple", 3); // 0 (compares "app")


- strcat

char s1[20] = "Hello ";
strcat(s1, "World"); // s1 = "Hello World"


- strncat

char s1[20] = "Hi ";
strncat(s1, "there!!!", 5); // s1 = "Hi there"

