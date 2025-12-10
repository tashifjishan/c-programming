
- 1. toupper
```c
toupper('a'); // 'A'
```
Converts a lowercase letter to uppercase.
Leaves other characters unchanged.

- 2. tolower
```c
tolower('Z'); // 'z'
```
Converts an uppercase letter to lowercase.
Other characters unchanged.

- 3. isupper
```c
isupper('A'); // non-zero (true)
isupper('a'); // 0 (false)
```

Checks if a character is uppercase.


- 4. islower
```c
islower('a'); // non-zero (true)
islower('A'); // 0 (false)
```

Checks if a character is lowercase.

- 5. isalpha
```c
isalpha('A'); // true
isalpha('z'); // true
isalpha('1'); // false
```

Checks if character is a letter (A-Z or a-z).

- 6. isdigit
```c
isdigit('5'); // true
isdigit('a'); // false
```

Checks if character is a digit (0-9).

- 7. isalnum
```c
isalnum('A'); // true
isalnum('1'); // true
isalnum('@'); // false
```

Checks if character is letter or digit.

- 8. isspace
```c
isspace(' ');  // true
isspace('\n'); // true
isspace('\t'); // true
isspace('a');  // false
```

Checks for whitespace characters (space, tab, newline, vertical tab, form feed, carriage return).

```c
9. ispunct
ispunct('.');  // true
ispunct('!');  // true
ispunct('a');  // false
```

Checks for punctuation characters (like !@#$%^&*()).
