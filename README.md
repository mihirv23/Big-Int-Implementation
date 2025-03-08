# 1024-bit Unsigned Integer Arithmetic

## Overview
This program implements addition, subtraction, and multiplication for 1024-bit unsigned integers on a 64-bit system using C. The standard integer data types in C are insufficient for handling such large numbers, so the program represents numbers as strings and performs arithmetic operations digit-by-digit.

## Features
- **Addition:** Adds two 1024-bit unsigned integers.
- **Subtraction:** Computes the difference between two 1024-bit unsigned integers, ensuring non-negative results.
- **Multiplication:** Computes the product of two 1024-bit unsigned integers using schoolbook multiplication.
- **Overflow Handling:** Checks for overflow conditions during operations.

## Compilation and Execution
### Compilation
Use a C compiler such as `gcc` to compile the program:
```bash
gcc -o big_math big_math.c
```

### Execution
Run the compiled program:
```bash
./big_math
```

### Input Format
- The program accepts two numbers as input, represented as strings of up to 309 characters (digits only).
- Any number exceeding 309 digits triggers an overflow condition.

## Implementation Details
### Important Concepts Used
1. **String-Based Arithmetic:**
   - Numbers are stored as character arrays to handle large values.
   - Arithmetic operations are performed digit-wise.

2. **Reversal Method:**
   - Reverses strings before performing operations for easier right-to-left processing.

3. **Carry/Borrow Mechanism:**
   - Used in addition and subtraction to handle digit-wise operations.

4. **Multiplication Using Shift and Add:**
   - Implements schoolbook multiplication with appropriate zero-padding.

5. **Overflow Handling:**
   - Compares results against a predefined threshold to detect overflows.
   - Uses a file (`string_input.txt`) to store threshold values.

## Code Structure
### `reverse()`
- Reverses a string in-place.

### `add()`
- Performs digit-wise addition of two numbers.
- Handles carry propagation.

### `subtract()`
- Implements digit-wise subtraction.
- Ensures that results are non-negative.

### `multiply()`
- Uses repeated addition and shift method to compute multiplication.
- Stores intermediate results and accumulates them.

### `OverFlowCheck()`
- Reads a predefined threshold from `string_input.txt`.
- Compares the result against this threshold to detect overflows.

### `main()`
- Reads input numbers from the user.
- Calls the appropriate arithmetic functions.
- Prints the results or handles overflow conditions.

## Example Usage
### Input
```
Input the first number:
123456789123456789123456789
Input the second number:
987654321987654321987654321
```
### Output
```
Multiplication result is 121932631356500531591068431581285008748302990
```

## Future Improvements
- Implement division and modulus operations.
- Optimize multiplication using Karatsuba's algorithm.
- Improve overflow handling by dynamically allocating memory.

## License
This project is open-source and free to use.


