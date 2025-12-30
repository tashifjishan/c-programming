# std::multimap in C++



- std::multimap is an associative container from the C++ Standard Library.
- It stores elements as key–value pairs.
- Duplicate keys are allowed (this is the main difference from map).
- Elements are stored in sorted order by key (by default, ascending).



Header file:
```c
#include <map>
```

Syntax:

```c
std::multimap<Key, Value> mp;
```
2. Key Characteristics

- Keys are immutable (cannot be changed after insertion).
- Automatically sorted by key.
- Allows multiple values for the same key.


# 3. Commonly Used Methods
```c
1. insert()

Adds a key–value pair.

mp.insert({key, value});


Example:

multimap<int, string> mp;
mp.insert({1, "Apple"});
mp.insert({1, "Banana"});
mp.insert({2, "Orange"});

2. find()

Returns an iterator to the first occurrence of the key.

auto it = mp.find(key);


Example:

auto it = mp.find(1);
if (it != mp.end())
    cout << it->second;

3. count()

Returns the number of elements with a given key.

int c = mp.count(key);


Example:

cout << mp.count(1);   // Output: 2

4. erase()

Removes elements.

mp.erase(key);        // removes all elements with that key
mp.erase(iterator);  // removes element at iterator


Example:

mp.erase(1);  // removes all entries with key 1

5. size()

Returns number of elements.

mp.size();

6. empty()

Checks if multimap is empty.

mp.empty();

7. clear()

Removes all elements.

mp.clear();

4. Traversing a multimap
for (auto it = mp.begin(); it != mp.end(); it++)
{
    cout << it->first << " " << it->second << endl;
}
```
# 5. Complete Example Program

```c
#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<int, string> mp;

    mp.insert({1, "Apple"});
    mp.insert({1, "Banana"});
    mp.insert({2, "Orange"});
    mp.insert({3, "Mango"});

    cout << "All elements:\n";
    for (auto it : mp)
        cout << it.first << " -> " << it.second << endl;

    cout << "\nValues with key 1:\n";
    auto range = mp.equal_range(1);
    for (auto it = range.first; it != range.second; it++)
        cout << it->second << endl;

    return 0;
}

```
