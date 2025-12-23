Binary Search idea (simple words)

- Find middle element
- Compare with key
- If key < middle → search left half
- If key > middle → search right half

```c

int low = 0, high = n - 1;
    int found = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

```

# Note:

low + (high - low) / 2 is used to avoid integer overflow, while (low + high) / 2 can overflow.

## Explanation:

Suppose the maximum value an integer variable can store is 10.
If low = 2 and high = 10, then low + high = 12.
Since 12 exceeds the maximum limit, it cannot be stored correctly in an integer variable.
This causes integer overflow, leading to an incorrect or unpredictable result, and therefore the calculated mid may be wrong.