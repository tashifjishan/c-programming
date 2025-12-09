
# ✅ 1. What is a Function?

A function is a block of code designed to perform a specific task.
It increases modularity, reusability, and makes code clean & manageable.

# 🧩 2. Types of Functions
## (A) Library Functions
- Predefined in C, part of standard libraries.
 Examples: printf(), scanf(), sqrt(), strlen(), etc.

- (B) User-defined Functions
Created by the programmer.

# 🏗️ 3. Function Syntax

```c
return_type function_name(parameter_list);


Function Definition
return_type function_name(parameter_list) {
    // body
}

Function Call
function_name(arguments);
```
# 🔁 4. Function Categories Based on Parameters & Return

C functions are often categorized as:

- 1️⃣ No arguments, no return value
```c
void greet() {
    printf("Hello");
}
```

- 2️⃣ Arguments, no return value
```c
void square(int x) {
    printf("%d", x*x);
}
```

- 3️⃣ No arguments, return value
```c
int giveNumber() {
    return 5;
}
```

- 4️⃣ Arguments and return value
```c
int add(int a, int b) {
    return a + b;
}
```

# 📌 5. Function Parameters

- Actual Arguments

Values passed during function call.

- Formal Parameters

Variables defined in the function definition.

# 🎯 6. Passing Methods
- ➡️ Pass by Value (Default in C)
```c
// A copy of the value is passed.

// Original value does NOT change.

void change(int x) {
    x = 10;
}
```

- ➡️ Pass by Reference (Using pointers)

```c
//Address is passed.

// Original value changes.

void change(int *x) {
    *x = 10;
}
```

# ⚙️ 7. Scope of Variables
- Local Variables

- - Declared inside a function.

- - Exist only during function execution.

- Global Variables

- - Declared outside all functions.
- - Accessible throughout the program.

- 🌀 8. Recursion

- - A function calling itself.

Example:
```c
int fact(int n) {
    if(n==0) return 1;
    return n * fact(n-1);
}
//⚠️ Must have a base condition to avoid infinite recursion.
```

# Default for local variables.

- static

- - Static local variable retains its value between calls.

- - Static function → accessible only within same file.

- - static void internalFunction() { ... }

- extern

- - Used to access a global variable or function defined in another file.

# 📦 12. Function Returning Multiple Values

- C cannot return multiple values directly → use:

- - Pointers

- - Structures

- - Arrays

- Example with pointers:
```c
void getValues(int *a, int *b) {
    *a = 10;
    *b = 20;
}
```


#  14. Sample Program Combining Everything
```c
💡
#include <stdio.h>

int add(int a, int b);     // declaration

int main() {
    int x = 10, y = 20;
    int result = add(x, y);  // call
    printf("Sum = %d", result);
}

int add(int a, int b) {    // definition
    return a + b;
}
```