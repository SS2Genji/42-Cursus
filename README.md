*This project has been created as part of the 42 curriculum by ahsimsek.*

# 42 Cursus - Common Core

Collection of my 42 School Common Core projects, algorithms, and system programming implementations.

---

## Overview

This repository contains the projects developed as part of the **42 Network (Common Core)** curriculum. All projects are implemented in **C**, adhering strictly to the **42 Norm** (Norminette: 25 lines max per function, 5 functions max per file, strict variable declarations, zero memory leaks, and forbidden standard library functions).

---

## Cursus Roadmap & Projects

| Circle | Project | Description | Status | Language |
| :---: | :--- | :--- | :---: | :---: |
| **Circle 00** | [**Libft**](./Circle-00/Libft) | Re-implementation of essential standard C library functions & linked list utilities | `Completed` | `C` |
| **Circle 01** | [**ft_printf**](./Circle-01/ft_printf) | Custom implementation of `printf` with variadic arguments (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) | `Completed` | `C` |
| **Circle 01** | [**get_next_line**](./Circle-01/get_next_line) | Efficient function reading a single line ending with newline from a file descriptor using static buffer | `Completed` | `C` |
| **Circle 01** | [**push_swap**](./Circle-01/push_swap) | Optimized sorting algorithm sorting stack data using two stacks and a restricted set of instructions | `Completed` | `C` |

---

## Norminette & Coding Standards

All C source code in this repository strictly adheres to **42 Norminette** guidelines:
* Max **25 lines** per function.
* Max **5 functions** per `.c` file.
* Strict variable declarations at the start of functions.
* No `for`, `do ... while`, `switch`, `goto`, or ternary operators nesting.
* Compiled with mandatory flags: `-Wall -Wextra -Werror`.
* Zero memory leaks (verified using `valgrind`).

---

## Building & Usage

Each project contains its own self-contained `Makefile` with standard 42 rules (`all`, `clean`, `fclean`, `re`).

```bash
# Clone the repository
git clone https://github.com/SS2Genji/42-Cursus.git
cd 42-Cursus

# Build Libft
cd Circle-00/Libft && make

# Build ft_printf
cd ../../Circle-01/ft_printf && make

# Build get_next_line (header and utility functions)
cd ../../Circle-01/get_next_line

# Build push_swap
cd ../../Circle-01/push_swap && make
```
