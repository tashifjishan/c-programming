# 1. find()

Purpose

Searches for a specific value in a range and returns an iterator to the first occurrence.
```c
Syntax
find(start_iterator, end_iterator, value);
```
# Key Points

- Returns iterator to the element if found
- Returns end() if not found


# Example
```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40};

    auto it = find(v.begin(), v.end(), 30);

    if (it != v.end())
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}
```


# 2. count()
Purpose

Counts how many times a value appears in a given range.

Syntax
```c
count(start_iterator, end_iterator, value);
```

## Key Points

- Returns an integer count
- Works with duplicate elements



Example
```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 2, 2, 4};

    int c = count(v.begin(), v.end(), 2);

    cout << "Count of 2 = " << c;

    return 0;
}
```

# 3. sort()

Purpose

Sorts elements in ascending order by default.

Syntax
```c
sort(start_iterator, end_iterator);
```

## Key Points
- Works only with random-access iterators

- Can be used with:
    -   array
    -   vector
    -   deque

# ❌ Does NOT work with list, map, set


```c
Example
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {40, 10, 30, 20};

    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";

    return 0;
}
```

- Sort in descending order:
```c
sort(v.begin(), v.end(), greater<int>());
```

- custom function



A custom function (also called a comparison function) defines how two elements are compared.

Syntax

    -   sort(begin, end, compareFunction);
    -   The comparison function must:

    -   Take two parameters
        - Return true if the first element should come before the second

```c

bool cmp(int a, int b)
{
    return a > b;   // descending order
}

int main()
{
    vector<int> v = {5, 1, 4, 2};

    sort(v.begin(), v.end(), cmp);

    for (int x : v)
        cout << x << " ";

    return 0;
}

```