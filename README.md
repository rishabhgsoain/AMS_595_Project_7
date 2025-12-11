**Description:**  
This project contains solutions to Homework 7, which covers conditional statements, vectors, loops, recursion/iteration, and user-defined functions in C++.

The program is divided into clearly labeled sections (`Question 1`, `Question 2`, … `Question 5`), and each function is documented with human-friendly explanations.

---

##  How to Compile and Run

Make sure you have a C++ compiler installed (e.g., `g++`).

### **To compile:**
```bash
g++ assignment7.cpp -o assignment7
To run the program:
bash
Copy code
./assignment7
The program prints each question header and then displays the output for that section.

 Summary of Implemented Questions
Question 1 — Switch Statement
Reads an integer n from the user and uses a switch statement to print:

"Negative One"

"Zero"

"Positive One"

"Other Value"

This section directly mirrors the MATLAB switch logic provided in the assignment.

Question 2 — Printing a Vector
Implements:

cpp
Copy code
void print_vector(vector<int> v)
This function prints all elements of a vector on one line.
A vector {10, 12, 14, 16, 18} is created and displayed.

Question 3 — Fibonacci Values ≤ 4,000,000
Generates and prints all Fibonacci numbers starting from 1 and 2 that do not exceed 4,000,000.

Uses a while loop, as required.

Question 4.1 — Checking if a Number is Prime
Implements:

cpp
Copy code
bool isprime(int n)
The function counts the number of divisors of n.
If the divisor count is exactly 2, the number is prime.

A test function prints:

scss
Copy code
isprime(2)
isprime(10)
isprime(17)
Question 4.2 — Factorization
Implements:

cpp
Copy code
vector<int> factorize(int n)
This returns all factors of n by iterating from 1 to √n and collecting factor pairs.

A test prints factors for:

2

72

196

Question 4.3 — Prime Factorization
Implements:

cpp
Copy code
vector<int> prime_factorize(int n)
This extracts:

All factors of 2

All odd prime factors

Any remaining prime > 1

It correctly produces repeated prime factors (e.g., 72 → 2 2 2 3 3).

Question 5 — Pascal’s Triangle
Implements:

cpp
Copy code
void print_pascals(int n)
This prints the first n rows of Pascal’s Triangle using iteration (no combinatorics, no recursion required).
The user enters the number of rows.

 File Structure
mathematica
assignment7.cpp     → Full commented C++ program
README.md            → This file
report.pdf           → 1–2 page assignment report (if included)
✔ Additional Notes
The code includes large, clear comments explaining how each function works.

All test cases match the examples provided in the assignment PDF.

No external libraries (other than <vector> and <iostream>) are used.

The Pascal’s Triangle implementation avoids combinatorial formulas as required.

