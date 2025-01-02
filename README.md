# push_swap

**push_swap** is a sorting algorithm challenge aimed at creating an efficient solution to sort a stack of integers using a minimal set of predefined operations. The goal is to sort stack a in ascending order, adhering to strict rules and constraints. 

---

## Rules

- **Stacks**:
  - Two stacks: `a` (initially contains unique integers) and `b` (initially empty).

- **Objective**:
  - Sort integers in `stack a` in ascending order using the fewest operations.

- **Allowed Operations**:
  - **Swap**: `sa`, `sb`, `ss`  
  - **Push**: `pa`, `pb`  
  - **Rotate**: `ra`, `rb`, `rr`  
  - **Reverse Rotate**: `rra`, `rrb`, `rrr`

---

## Program Details

- **Input**: A list of integers passed as arguments.  
- **Output**: A sequence of operations to sort `stack a`. Each operation is printed on a new line.


---

## Example

### Input:
Stack `a`: `[2, 1, 3, 6, 5, 8]`  
Stack `b`: `[]`

### Operations:
1. `sa`: `[1, 2, 3, 6, 5, 8]`
2. `pb pb pb`: `a: [6, 5, 8]`, `b: [3, 2, 1]`
3. `pa pa pa`: `a: [1, 2, 3, 5, 6, 8]`, `b: []`


