# 🚨 Exception Handling in C++ — CRASH COURSE

1️⃣ What is an Exception?

- An exception is a runtime error that disrupts the normal flow of a program.

Examples:

- Division by zero
- Invalid array index
- File not found
- Memory allocation failure

👉 Without exception handling → program crashes abruptly.



# 4️⃣ Basic Syntax (MUST KNOW)

```cpp
try {
    // risky code
    if (b == 0)
        throw "Division by zero";
    cout << a / b;
}
catch (const char* msg) {
    cout << "Error: " << msg;
}

```


# 5️⃣ Multiple catch Blocks

```cpp
try {
    int x;
    cin >> x;

    if (x < 0)
        throw x;
    if (x == 0)
        throw "Zero not allowed";
}
catch (int n) {
    cout << "Negative number: " << n;
}
catch (const char* msg) {
    cout << msg;
}
```

## 🔹 Order matters — specific first, generic last.

# 6️⃣ Catch-All Handler (...)

```cpp
try {
    throw 3.14;
}
catch (...) {
    cout << "Unknown exception";
}
```

Used when:

- You don’t know exception type
- Final safety net

# 7️⃣ Standard Exception Classes (VERY IMPORTANT)

- Located in <exception> & <stdexcept>

Common Ones:

std::runtime_error	        Runtime problems
std::logic_error        	Logical mistakes
std::out_of_range	        Index error
std::invalid_argument	    Bad argument
std::bad_alloc	            Memory failure


Example:

```cpp
#include <stdexcept>

try {
    throw std::out_of_range("Index out of range");
}
catch (const std::exception& e) {
    cout << e.what();
}
```

- 🔹 what() returns error message.


# 🔟 Exception in Functions

- Throwing from function:

```cpp
int divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Divide by zero");
    return a / b;
}

Handling:
try {
    divide(10, 0);
}
catch (const std::exception& e) {
    cout << e.what();
}
```

# 1️⃣1️⃣ noexcept Keyword (INTERVIEW FAVORITE)

```cpp
void func() noexcept {
    // guarantees no exception
}
```


- If exception occurs → std::terminate() is called
- Used in destructors, move constructors
