# Simple Arithmetic Expression Parser & Assembly Generator

This project is a small C program that:
1. Tokenizes arithmetic expressions (`+` and `-`).
2. Parses them to compute the result.
3. Generates simple pseudo-assembly instructions for the expression.

---

## ✨ Features
- Supports integer addition (`+`) and subtraction (`-`).
- Tokenizes input into structured `Token` objects.
- Validates the expression before parsing.
- Outputs both the **calculated result** and **assembly-like instructions**.

---

## 🛠️ How It Works
1. **Tokenization**  
   The `tokenize` function scans the input string and converts it into a list of tokens:
   - `TOKEN_NUMBER` → numeric values  
   - `TOKEN_PLUS` → plus sign  
   - `TOKEN_MINUS` → minus sign  
   - `TOKEN_END` → marks the end of tokens  

2. **Parsing**  
   The `parse` function validates token order and calculates the result step by step.  
   For example:  
 - Input: 5 + 4 - 3
 - Output: 6


3. **Assembly Generation**  
The `generate_assembly` function prints pseudo-assembly instructions:
- LOAD 5
- ADD 4
- SUB 3


# 🚀 Future Improvements

- Add support for multiplication and division.

- Handle parentheses (( )).

- Improve error messages.

- Optimize token allocation.
