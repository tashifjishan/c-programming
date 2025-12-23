# How does it work:

- Suppose, this is the array which needs to be sorted:

{9, 4, 5, 1}

to do this, insertion sort algorithm follows the following steps:

- It stores the element 4, present at the index 1, in a temporary variable.

- Now, it compares the element 9, present at the index 0, with the temporary variable, i.e. 4. Since, 4 is less than 9, shifting is required and hence the the element 9 is shifted one position further. After this step the above array looks like this:

{9, 9, 5, 1}


- Now, since, there are no any element before 9, index 0, It replaces the value 9, present at the index 0, with the value stored in the temporary variable, i.e. 4. After this step the above array looks like this:

{4, 9, 5, 1}

- It stores, now, the element 5, present at the index 2 in the temporary variable.

- It compares the element present at the index 1, i.e. 9, with the value present in the temporary variable, i.e. 5. Since, 5 is less than 9 the value 9 is shifted one position further. After this step the above array looks like this:

{4, 9, 9, 1}

- It compares, now, the element present at the index 0, i.e. 4, with the value stored in the temporary variable, i.e. 5. Since 5 is not less than 4, no shifting is required and hence the element at index 1 is replaced with the temporary variable. After this step the above array looks like this:

{4, 5, 9, 1}

- Now, it stores the element 1, present at the index 3 in the temporary variable.

- It, now compares the element present the index 2, i.e. 9, with the value stored in the temporary variable, i.e. 1. Since, 1 is less than 9, shifting is required and hence the value 9 is moved one position further. After this the above array looks like this:

{4, 5, 9, 9}

- It, now, compares the element present at the index 1, i.e. 5, with the value stored in the temporary variable, i.e. 1. Since, 1 is less than 5, shifting is required and hence the value 5 is moved one position further. After this the above array looks like this:

{4, 5, 5, 9}

- It, now, compares the element present at the index 0, i.e. 4, with the value stored in the temporary variable, i.e. 1. Since, 1 is less than 4, shifting is required and hence the element 4 is shifted one position further. After this step the above array looks like this:

{4, 4, 5, 9}

- Since, index 0 is the last index and it has already done the comparison with the element present at this index in the previous step and has made the required shifting, It, now, replaces the element present at the index 0 with the value of the temporary variable. After this step the above array looks like this:

{1, 4, 5, 9}

Which is the sorted array!


```c
  for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift
            j--;
        }

        arr[j + 1] = key; // insert
    }

```