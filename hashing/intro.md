# 1. What is Hashing?

Hashing is a technique used to store and retrieve data efficiently using a key.

- Key idea

We use a hash function to convert a key into an index of an array called a hash table.

This allows average O(1) time for insertion, search, and deletion.

- Example

If table size = 10
Hash function:

h(key) = key % 10

Key 25 → index 5

# 2. Hash Table (Data Structure)

A hash table is:

- An array of fixed size
- Each index is called a slot
- Stores keys (or key–value pairs)

int hashTable[SIZE];

# 3. Hash Function

A hash function:
- Maps keys to indices
- Should be fast
- Should distribute keys uniformly

## Common hash function

h(key) = key % table_size

# 4. Collision (Very Important Concept)

- A collision occurs when:
- Two different keys produce the same hash index

- Example:

```bash
Table size = 10
Keys: 15, 25

15 % 10 = 5
25 % 10 = 5  ← collision
```

Since one slot can’t hold two keys, we need collision resolution techniques.

# 5. Collision Resolution Techniques

We will focus on Open Addressing, where:

- All keys are stored inside the hash table itself

## Types:

- Linear Probing
- Quadratic Probing
- Double Hashing

# 6. Linear Probing
Concept

If a collision occurs:

- Check the next slot until an empty slot is found.

- Formula
h(key, i) = (h(key) + i) % table_size


where i = 0, 1, 2, 3...

Example

Table size = 10
Insert keys: 23, 43, 13

23 % 10 = 3 → place at index 3
43 % 10 = 3 → collision → try 4 → place at 4
13 % 10 = 3 → collision → try 4 (occupied)
                          try 5 → place at 5

C-style logic
```c
index = key % SIZE;
while (hashTable[index] != EMPTY) {
    index = (index + 1) % SIZE;
}
hashTable[index] = key;
```2

Advantages

- ✔ Simple
- ✔ Easy to implement


# 7. Quadratic Probing

Concept

Instead of checking next slot linearly, we jump quadratically.

Formula
h(key, i) = (h(key) + i²) % table_size

Example
Initial index = 3
Try: 3 + 1² = 4
Try: 3 + 2² = 7
Try: 3 + 3² = 12 % 10 = 2

C-style logic
```c
index = key % SIZE;
for (i = 1; i < SIZE; i++) {
    newIndex = (index + i*i) % SIZE;
    if (hashTable[newIndex] == EMPTY) {
        hashTable[newIndex] = key;
        break;
    }
}
```

# 8. Double Hashing

Concept

- Uses two hash functions:
- First decides the starting index
- Second decides the jump size

- Formula
h(key, i) = (h1(key) + i * h2(key)) % table_size

Example hash functions
h1(key) = key % table_size
h2(key) = 1 + (key % (table_size - 1))

Example
key = 23, table_size = 10
h1 = 23 % 10 = 3
h2 = 1 + (23 % 9) = 6

Indexes checked:
3
(3 + 6) % 10 = 9
(3 + 12) % 10 = 5

C-style logic
```c
index = h1(key);
step = h2(key);

while (hashTable[index] != EMPTY) {
    index = (index + step) % SIZE;
}
hashTable[index] = key;

```

size = 10
[_, _, _, {key: 13, value: 169}=>{key:3, value: 9}, {key: 14, value: 196}, _, _, _, _, _]

key = 13, value 169
hash = 13%10 = 3


key = 14, value = 196
hash = 14%10 = 4

key = 3, value = 9
hash = 3%10= 3

Queries:

value of key 3

3%10 = 3

value of key 13
13%10 =3 


value of key 14
