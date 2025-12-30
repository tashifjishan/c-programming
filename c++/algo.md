# 1. search()

Purpose

Searches for a sub-sequence inside another sequence.

Syntax
```c

search(first1, last1, first2, last2);
```

- Key Points

    -   Finds the first occurrence of a sequence
    -   Returns iterator to the start of the found sequence
    -   Returns end() if not found

Example
```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4};

    auto it = search(v1.begin(), v1.end(), v2.begin(), v2.end());

    if (it != v1.end())
        cout << "Subsequence found";
    else
        cout << "Not found";

    return 0;
}

```

# 2. merge()

Purpose

Merges two sorted ranges into a single sorted range.

Syntax
```c
merge(first1, last1, first2, last2, result_begin);
```

- Key Points

    - Both input ranges must be sorted
    - Result is stored in a third container
    - Does not remove duplicates

Example
```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    vector<int> c(6);

    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    for (int x : c)
        cout << x << " ";

    return 0;
}
```


# 3. for_each()
Purpose

Applies a function to each element in a range.

Syntax

```c
for_each(begin, end, function);
```

## Key Points

- Does not change container size
- Can modify elements (if passed by reference)
```c

Example
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int x)
{
    cout << x << " ";
}

int main()
{
    vector<int> v = {1, 2, 3, 4};

    for_each(v.begin(), v.end(), print);

    return 0;
}
```


# 4. transform()
Purpose

Applies a function to elements and stores the result in another container.

Syntax (Unary Operation)
```c
transform(begin, end, result_begin, function);
```
## Key Points

- Result stored in a separate container
- Can also work on two input ranges
- Does not change original container unless used in-place

Example

```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int square(int x)
{
    return x * x;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> result(4);

    transform(v.begin(), v.end(), result.begin(), square);

    for (int x : result)
        cout << x << " ";

    return 0;
}
```