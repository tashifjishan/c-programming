# ✅ static Functions in C

- A function declared with static has internal linkage. This means the function is visible only inside the same .c file.

## Why use it?

- To hide helper/utility functions from other files
- To avoid name conflicts
- To restrict the function's scope to one file only

## Example:
```c
// file1.c
static void helper() {
    printf("This is a static function.\n");
}

void display() {
    helper();  // OK: helper() is available within the same file
}


// If another file tries to call helper(), it won’t work:

// file2.c
extern void helper(); // ❌ Even if declared, it's not accessible
```

# ✅ extern Functions in C

extern means the function is defined in some other file.
By default, all non-static functions have external linkage, so you only need extern when declaring a function that is defined elsewhere.

## Why use it?

- To call a function defined in another .c file
- To let the linker know the function exists in another compilation unit
```c
Example:
// file1.c
void greet() {
    printf("Hello from file1\n");
}

// file2.c
extern void greet();  // Declaration
int main() {
    greet(); // Works, linker finds it in file1.c
}

```


- You can even omit the extern because declaring a function like this implicitly treats it as external:
```c
void greet();  // same meaning as extern void greet();
```

# Compile

```bash
 gcc file2.c file1.c -o main
```