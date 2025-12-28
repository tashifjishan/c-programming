# SPACE COMPLEXITY

- What is Space Complexity?

Space Complexity is the amount of extra memory an algorithm uses while it runs.

- 👉 It includes:

    - Variables
    - Arrays
    - Recursion stack
    - Temporary data structures

- ❌ It does not include input size storage (in most exam definitions).


- Types of Space Used

# 1️⃣ Constant Space – O(1)

- Memory used does not depend on input size.

- Example:

```c
int sum(int a, int b) {
    int c = a + b;
    return c;
}
```


- 📌 Uses fixed variables → O(1)

# 2️⃣ Linear Space – O(n)

- Memory increases linearly with input size.

Example:

- int arr[n];
- 📌 If n doubles, memory doubles → O(n)

# 3️⃣ Quadratic Space – O(n²)

- Memory grows as n × n.

- Example:

int matrix[n][n];


📌 Used in adjacency matrix of graphs → O(n²)

- Space Complexity in Recursion

Example:
```c
void fun(int n) {
    if(n == 0) return;
    fun(n - 1);
}
```


- 📌 Each recursive call uses stack space
- 📌 Total calls = n
- 👉 Space Complexity = O(n)

- Iterative vs Recursive Space
Approach	            Space

Iterative loop	        O(1)
Recursive call	        O(n)

# In-place Algorithms
- Algorithms that use no extra space (or constant space).

Example:

- Bubble Sort
- Selection Sort

- 📌 Space Complexity = O(1)

