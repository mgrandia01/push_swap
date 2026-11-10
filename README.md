# 🔀 push_swap

> A highly optimized integer sorting algorithm built in C, utilizing two stacks (`a` and `b`) and a restricted set of instructions, powered by a bitwise Radix Sort implementation.

## 📖 Overview

`push_swap` is a fundamental algorithm and data structure project designed to calculate and display the minimal sequence of stack operations required to sort a set of integer values. Given a random stack of unique integers in Stack A, the program outputs standard POSIX stack manipulation instructions to arrange the numbers in ascending order using Stack B as an auxiliary buffer.

## ⚙️ Technical Constraints & Architecture

- **Language:** C (compiled with `gcc -Wall -Wextra -Werror`).
- **Memory & Resource Safety:** Zero memory leaks, dangling pointers, or unhandled exceptions. Input arrays, node structures, and dynamic stack pointers are cleanly deallocated upon exit (audited via Valgrind).
- **Error Handling:** Explicit validation for non-numeric inputs, values exceeding standard `INT_MAX`/`INT_MIN` boundaries, and duplicate numbers. Outputs `Error\n` on standard error (`stderr`) for any invalid configuration.
- **Standards:** 100% compliant with 42's **Norminette** coding standard.

---

## 🛠️ Stack Operations (Instruction Set)

The algorithm is strictly constrained to the following 11 operations:

| Instruction | Code | Description |
| :--- | :--- | :--- |
| **Swap A** | `sa` | Swap the first 2 elements at the top of stack `a`. |
| **Swap B** | `sb` | Swap the first 2 elements at the top of stack `b`. |
| **Swap Both** | `ss` | `sa` and `sb` simultaneously. |
| **Push A** | `pa` | Take the top element of `b` and put it at the top of `a`. |
| **Push B** | `pb` | Take the top element of `a` and put it at the top of `b`. |
| **Rotate A** | `ra` | Shift up all elements of stack `a` by 1. First element becomes the last. |
| **Rotate B** | `rb` | Shift up all elements of stack `b` by 1. First element becomes the last. |
| **Rotate Both**| `rr` | `ra` and `rb` simultaneously. |
| **Rev Rotate A**| `rra` | Shift down all elements of stack `a` by 1. Last element becomes the first. |
| **Rev Rotate B**| `rrb` | Shift down all elements of stack `b` by 1. Last element becomes the first. |
| **Rev Rotate Both**| `rrr` | `rra` and `rrb` simultaneously. |

---

## 🧮 Algorithmic Strategy: Bitwise Radix Sort

To achieve deterministic performance across large datasets ($N = 100$ and $N = 500$), the algorithm employs a **Least Significant Bit (LSD) Radix Sort** combined with index rank normalization.

### 1. Index Normalization (Coordinate Compression)
Before sorting, raw input values (which can include negative numbers or large values up to `INT_MAX`) are mapped to their sorted index ranks ($0$ to $N - 1$).
- **Example:** `[-50, 1000, 0]` $\rightarrow$ mapped to `[0, 2, 1]`.
- **Benefit:** Guarantees all numbers are non-negative contiguous integers, optimizing the number of binary bit columns required for sorting ($\lceil \log_2 N \rceil$ iterations).

### 2. Bitwise Pass Execution
For each bit position $i$ (from bit $0$ up to max bit count):
1. Iterate through all $N$ elements currently in Stack A.
2. If the $i$-th bit of the top element is `0`, push it to Stack B (`pb`).
3. If the $i$-th bit is `1`, rotate Stack A (`ra`) to preserve its position.
4. Once Stack A is scanned, push all elements back from Stack B to Stack A (`pa`).
5. Repeat for bit $i + 1$.

### 3. Small Sets Optimization ($N \le 5$)
Radix sort is bypassed for small datasets in favor of hardcoded algorithmic logic to minimize operation count:
- **$N = 2$ or $3$:** Simple single/double-operation permutation checks (`sa`, `rra`, `ra`).
- **$N = 4$ or $5$:** Pushes the smallest values to Stack B (`pb`), sorts the remaining 3 elements in Stack A, and pushes back (`pa`).

---

## 🛠️ Quickstart & Compilation

### Build Commands

```bash
# Clone the repository
git clone [https://github.com/your-username/push_swap.git](https://github.com/your-username/push_swap.git)
cd push_swap

# Compile the push_swap binary
make

# Clean object files
make clean

# Clean object files and binary
make fclean

# Recompile project
make re

# Pass raw integer list as command-line arguments
./push_swap 4 67 3 1 23

# Pass string of integers
./push_swap "4 67 3 1 23"

# Verify operation count and correctness using the 42 checker binary
ARG="4 67 3 1 23"; ./push_swap $ARG \vert{} ./checker$ARG
