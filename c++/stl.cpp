1️⃣ vector – Dynamic Array
🔹 What is a Vector?

Dynamic array (resizable)

Stored in contiguous memory

Fast random access

🔹 Why vector over array?
Array	Vector
Fixed size	Dynamic size
No built-in functions	Rich methods
Manual memory	Automatic
🔹 Declaration
vector<int> v;
vector<int> v(5);        // size 5
vector<int> v(5, 10);    // 5 elements of value 10

🔹 Important Methods
Capacity
v.size();        // number of elements
v.capacity();    // allocated memory
v.empty();       // true/false
v.resize(n);
v.reserve(n);
v.clear();

Access
v[i];
v.at(i);         // bounds checking
v.front();
v.back();

Modifiers
v.push_back(x);
v.pop_back();
v.insert(pos, x);
v.erase(pos);
v.erase(start, end);

Iterators
v.begin();
v.end();
v.rbegin();
v.rend();

🔹 Time Complexity
Operation	Complexity
Access	O(1)
Insert at end	O(1)*
Insert/Delete middle	O(n)
2️⃣ list – Doubly Linked List
🔹 What is a List?

Non-contiguous memory

Implemented as doubly linked list

Fast insertion & deletion anywhere

🔹 Why list over vector?

Frequent insert/delete in middle

No shifting of elements

🔹 Declaration
list<int> l;
list<int> l(5, 100);

🔹 Important Methods
Capacity
l.size();
l.empty();
l.clear();

Access
l.front();
l.back();

Modifiers
l.push_back(x);
l.push_front(x);
l.pop_back();
l.pop_front();
l.insert(pos, x);
l.erase(pos);

Special List Operations
l.remove(x);          // remove all x
l.sort();
l.reverse();
l.unique();           // remove duplicates (consecutive)
l.merge(l2);          // merge sorted lists

🔹 Time Complexity
Operation	Complexity
Insert/Delete	O(1)
Access	O(n)
3️⃣ deque – Double Ended Queue
🔹 What is Deque?

Insert/Delete from both ends

Hybrid of vector + list

Not fully contiguous

🔹 Declaration
deque<int> d;

🔹 Important Methods
Capacity
d.size();
d.empty();
d.clear();

Access
d[i];
d.at(i);
d.front();
d.back();

Modifiers
d.push_back(x);
d.push_front(x);
d.pop_back();
d.pop_front();
d.insert(pos, x);
d.erase(pos);

🔹 Time Complexity
Operation	Complexity
Front/Back insert/delete	O(1)
Random access	O(1)
4️⃣ stack – Container Adapter (LIFO)
🔹 What is Stack?

LIFO (Last In First Out)

No iterators

Built on deque (default)

🔹 Declaration
stack<int> s;

🔹 Important Methods
s.push(x);
s.pop();
s.top();
s.size();
s.empty();


🚫 No insert, erase, traverse

🔹 Stack Use-Cases

Recursion

Expression evaluation

Undo/Redo

Backtracking

📊 Comparison Table
Feature	Vector	List	Deque	Stack
Memory	Contiguous	Non-contiguous	Partial	Adapter
Access	Fast	Slow	Fast	Top only
Insert middle	Slow	Fast	Medium	❌
Iterators	✔	✔	✔	❌
🎯 Interview / Teaching Tips

✔ Prefer vector by default
✔ Use list when frequent middle insert/delete
✔ Use deque when both ends needed
✔ Use stack for LIFO logic

If you want next:

Full C++ programs using all containers

STL vs custom DS comparison

Common interview questions on STL

How STL internally works (for advanced students)

Just tell me 👌