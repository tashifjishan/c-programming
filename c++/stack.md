# 1. What is stack?

- stack is a container adapter in C++ STL
- Follows LIFO principle → Last In, First Out
- Insertion and deletion happen only at the top

# Declaration

```cpp
stack<int> st;
```

# Methods:
push, pop, top, size and empty

```c

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

```