# 1. What is deque?

- deque stands for Double Ended Queue
- Allows fast insertion and deletion at both front and back
- Dynamic size (can grow or shrink)

2. Key Characteristics

- Elements are stored in non-contiguous memory
- Supports random access like arrays (dq[i])

# Insertion:

![alt text](image-13.png)

# Deletion:

![alt text](image-14.png)

# Access:

![alt text](image-15.png)

# Size & Empty

![alt text](image-16.png)

# Iteration

```c

for(auto it = dq.begin(); it != dq.end(); it++)
    cout << *it << " ";

```