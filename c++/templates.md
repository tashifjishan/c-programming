# 🔷 TEMPLATES IN C++

- Templates enable generic programming — write code once, use it for any data type.

## 1️⃣ Why Templates?

- Without templates:

int add(int a, int b);
float add(float a, float b);
double add(double a, double b);


- With templates:

template <typename T>
T add(T a, T b) {
    return a + b;
}


✔ Less code
✔ Type-safe
✔ Compile-time polymorphism

# 🔹 FUNCTION TEMPLATES

2️⃣ Function Template – Syntax

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

Usage:
```cpp
cout << add(3, 4);        // int
cout << add(2.5, 3.1);   // double
```

💡 Compiler generates separate functions for each type.

# 3️⃣ Multiple Template Parameters

```cpp
template <typename T, typename U>
void print(T a, U b) {
    cout << a << " " << b;
}
```

# 4️⃣ Template Argument Deduction

- Compiler deduces type automatically:

add(10, 20);        // T = int
add(2.3, 4.5);      // T = double


- Explicit specification:

add<int>(3, 5);

# 5️⃣ Function Template Overloading

```cpp
template <typename T>
T max(T a, T b);

int max(int a, int b); // preferred for int
```

- ✔ Non-template function gets priority.

# 6️⃣ Function Template Specialization

- Used when generic logic fails.

```cpp
template <>
const char* max<const char*>(const char* a, const char* b) {
    return strcmp(a, b) > 0 ? a : b;
}

```

# 7️⃣ Function Template with References
```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

# 🔷 CLASS TEMPLATES

- 9️⃣ Class Template – Syntax

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() { return value; }
};

```


Usage:

```cpp
Box<int> b1(10);
Box<string> b2("Hello");
```

🔟 Multiple Type Parameters

```cpp
template <typename T, typename U>
class Pair {
public:
    T first;
    U second;
};
```

# 1️⃣1️⃣ Class Template Member Function Definition (Outside Class)

```cpp
template <typename T>
class Test {
public:
    void show();
};

template <typename T>
void Test<T>::show() {
    cout << "Hello";
}

```


## ❗ <T> is mandatory.



