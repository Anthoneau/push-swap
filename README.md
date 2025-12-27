# push_swap

`push_swap` is a 42 School algorithmic project whose goal is to **sort a stack of integers using a limited set of operations**, while producing the smallest possible number of moves.

The challenge is not only to sort correctly, but to do so **efficiently**, by designing and implementing a performant sorting strategy under strict constraints.

---

## Project Overview

The program receives a list of integers as arguments and must sort them in ascending order using two stacks:

- **Stack A**: initially contains all numbers
- **Stack B**: auxiliary stack, initially empty

Only a predefined set of operations is allowed (push, swap, rotate, reverse rotate), and the program must output the list of operations used to sort the stack.

---

## Constraints & Goals

- No direct access to array sorting functions
- Only stack-based operations are allowed
- The output must be optimized for **minimum number of moves**
- Memory usage and execution time must remain reasonable

This project is a strong exercise in **algorithm design, optimization, and data manipulation**.

---

## Algorithmic Strategy

### Modified Quick Sort Approach

The core of my solution is based on a **heavily modified quick sort strategy**, adapted to work within the constraints of stack operations.

Unlike a classic quick sort on arrays, this implementation:
- Works entirely with stacks
- Uses rotations instead of direct indexing
- Carefully minimizes unnecessary operations

---

### High-Level Algorithm

1. **Pivot Selection**
   - A pivot value is selected (usually the median of the current subset).
   - Elements are compared against the pivot.

2. **Partitioning**
   - Values lower or equal to the pivot are pushed to **stack B**.
   - Higher values remain in **stack A**, using rotations to preserve order.

3. **Recursive Reduction**
   - The same logic is applied recursively on smaller subsets.
   - The problem size decreases progressively.

4. **Reintegration**
   - Values stored in stack B are pushed back into stack A.
   - Rotations are optimized to place values directly in correct positions.

This approach preserves the spirit of quick sort while remaining compatible with the project’s strict operation rules.

---

## Small Stack Optimization

For very small input sizes (≤ 5 elements), dedicated optimized routines are used instead of the main algorithm.

These specialized cases:
- Avoid unnecessary partitioning
- Use minimal hardcoded logic
- Greatly reduce the total number of moves

This ensures optimal behavior for edge cases.

---

## Performance Results

Average number of operations achieved:

- **100 numbers**: ~**660 moves**
- **500 numbers**: ~**5000 moves**

These results comfortably meet the project requirements and demonstrate a strong balance between simplicity and efficiency.

---

## What This Project Demonstrates

- Advanced understanding of sorting algorithms
- Ability to adapt classic algorithms to constrained environments
- Optimization mindset (move count matters)
- Clean separation between algorithm logic and stack operations
- Strong problem-solving and debugging skills

---

## Usage

```bash
make
./push_swap 3 2 1 5 4
```

The program outputs the list of operations required to sort the input.

---

## Author

**Anthony Goldberg** ***agoldber***

42 student – core curriculum completed
