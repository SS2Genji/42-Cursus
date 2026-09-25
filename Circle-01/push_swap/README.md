*This project has been created as part of the 42 curriculum by ahsimsek.*

# push_swap

## Description
**push_swap** is an algorithmic project in the 42 curriculum designed to deepen understanding of sorting algorithms, data structures, and computational complexity. The objective is to sort a given set of integer values on a stack using a secondary helper stack and a strictly limited set of stack manipulation instructions, minimizing the total number of operations performed.

The project requires handling two stacks named **a** and **b**:
- Stack **a** initially contains a random list of unorganized, non-duplicate negative and/or positive integers.
- Stack **b** is initially empty.
- The goal is to sort the numbers into stack **a** in ascending order.

---

## Instructions

### Compilation
The project includes a standard `Makefile` with `-Wall -Wextra -Werror` compiler flags. To build the executable:

```bash
make
```

This compiles the source code, links the internal `libft` library, and produces the `push_swap` binary at the root of the project.

Other available Makefile rules:
- `make clean`: Deletes compiled object files (`.o`).
- `make fclean`: Removes object files and the `push_swap` binary.
- `make re`: Rebuilds the entire project from scratch.

### Execution
Run `push_swap` by passing integer values as individual command-line arguments or as a formatted quoted string:

```bash
./push_swap 2 1 3 6 5 8
```

Or with a single string argument:

```bash
./push_swap "2 1 3 6 5 8"
```

To verify correctness using the 42 `checker` binary:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

If the numbers are sorted and no errors occurred, the checker outputs `OK`.

### Benchmark Mode
The program includes an internal benchmarking feature (`--bench`) that outputs detailed operation breakdown metrics and complexity statistics:

```bash
./push_swap --bench 4 67 3 87 23
```

### Available Operations

| Operation | Command | Description |
| :---: | :--- :| :--- |
| **Swap** | `sa` | Swaps the first two elements at the top of stack **a**. Does nothing if there is only one or no elements. |
| | `sb` | Swaps the first two elements at the top of stack **b**. Does nothing if there is only one or no elements. |
| | `ss` | Executes `sa` and `sb` simultaneously. |
| **Push** | `pa` | Takes the first element at the top of stack **b** and puts it at the top of stack **a**. Does nothing if **b** is empty. |
| | `pb` | Takes the first element at the top of stack **a** and puts it at the top of stack **b**. Does nothing if **a** is empty. |
| **Rotate** | `ra` | Shifts up all elements of stack **a** by 1. The first element becomes the last one. |
| | `rb` | Shifts up all elements of stack **b** by 1. The first element becomes the last one. |
| | `rr` | Executes `ra` and `rb` simultaneously. |
| **Reverse Rotate** | `rra` | Shifts down all elements of stack **a** by 1. The last element becomes the first one. |
| | `rrb` | Shifts down all elements of stack **b** by 1. The last element becomes the first one. |
| | `rrr` | Executes `rra` and `rrb` simultaneously. |

---

## Algorithm and Data Structure

### 1. Data Structure: Singly-Linked Stack with Indexing
Each node in the stack (`t_stack`) stores:
- `value`: The raw integer value parsed from input.
- `index`: The zero-indexed relative rank (`0` to `size - 1`) of the element among all values.
- `next`: Pointer to the next stack node.

Normalizing raw integer values into consecutive zero-based ranks via `assign_index()` allows sorting logic to operate independently of value scale, negative numbers, or non-uniform intervals.

### 2. Multi-Strategy Sorting Engine
The sort dispatcher chooses the most optimal strategy based on the number of elements and stack entropy:

1. **Tiny Inputs (N <= 3):**
   - For 2 elements: A single `sa` if unordered.
   - For 3 elements: `sort_three()` resolves all 5 possible unsorted permutations in at most 2 operations using state evaluations.
2. **Small Inputs (N <= 5):**
   - `sort_five()` finds the minimum elements in stack **a**, pushes them to stack **b**, sorts the remaining 3 elements using `sort_three()`, and pushes the minimums back.
3. **Medium Inputs (5 < N <= 100):**
   - `medium_sort()` leverages an adaptive chunking / square-root partition mechanism (`ft_isqrt`), pushing elements into stack **b** in windows based on their indices and pulling them back in descending order.
4. **Large Inputs (N > 100):**
   - `radix_sort()` implements an optimized Least Significant Bit (LSD) **Bitwise Radix Sort**. Because every value has been normalized into `[0, N - 1]`, the algorithm processes each bit position from bit `0` up to `log2(N)`:
     - If the current bit of the top element's index is `0`, it pushes the node to stack **b** (`pb`).
     - If the current bit is `1`, it rotates stack **a** (`ra`).
     - After partitioning the stack for that bit, all elements are pushed back from **b** to **a** (`pa`).
   - Time complexity: O(k * N) where k is the number of bits.

---

## Resources

### Classic References
- **Sorting and Searching**: Knuth, Donald E. *The Art of Computer Programming, Volume 3*.
- **Bitwise Radix Sort**: Algorithm design for integer key sorting using binary representations.
- **Linux Manual Pages**: `man 3 malloc`, `man 3 free`, `man 2 write`.

### AI Usage
- **Conceptual Clarification:** AI tools were consulted during the design phase to analyze time-complexity trade-offs between Chunk Sort and Bitwise Radix Sort for arbitrary stack constraints.
- **Code & Implementation:** All parsing validation, linked stack management, operations, and sorting routines were written, optimized, and tested independently by the author to ensure 100% 42 Norminette compliance and zero memory leaks.

---

*This README was written with the assistance of AI.*
