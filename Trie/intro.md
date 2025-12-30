# 1. What is a Trie?

- Trie is a tree-based data structure used to store strings
- Also called Prefix Tree
- Each node represents a character
- Used mainly for fast searching and prefix matching

Example words stored:
cat, car, care, dog

# 2. Key Characteristics

- Root node is empty
- Each edge represents a character
- Words are formed by paths from root
- A special flag (isEnd) marks the end of a word
- Efficient for prefix queries

# 3. Trie Node Structure 

- Each node typically contains:
    - Array / map of child pointers (size = alphabet size)
    - Boolean flag isEndOfWord

