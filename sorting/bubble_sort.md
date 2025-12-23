# What is Bubble Sort? 

Bubble Sort is a simple sorting algorithm where:

- Adjacent elements are compared and swapped if they are in the wrong order.

After each pass:

- The largest element “bubbles up” to the end of the array.


# 2️⃣ Basic idea 

- Compare first two elements
- Swap if needed
- Move one step forward
- Repeat till end
- Do multiple passes until sorted


# 4️⃣ Number of passes 

If array size is n:

- Outer loop runs n−1 times
- After each pass, one element is fixed at the end
## Why n−1?
- Because after fixing n−1 elements, the last one is automatically sorted.



```c

 for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

```


