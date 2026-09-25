<div align="center">

#  Ecole 42 - Common Core Cursus

<p align="center">
  <img src="https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white" alt="42" />
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Norminette-v3%20Passing-brightgreen?style=for-the-badge" alt="Norminette" />
  <img src="https://img.shields.io/badge/OS-Linux%20%2F%20Arch-1793D1?style=for-the-badge&logo=arch-linux&logoColor=white" alt="Linux" />
</p>

<p align="center">
  Collection of my 42 School Common Core projects, algorithms, and system programming implementations.
</p>

</div>

---

## 📌 Overview

This repository contains the projects developed as part of the **42 Network (Common Core)** curriculum. All projects are implemented in **C**, adhering strictly to the **42 Norm** (Norminette: 25 lines max per function, 5 functions max per file, strict variable declarations, zero memory leaks, and forbidden standard library functions).

---

## 🧭 Cursus Roadmap & Projects

| Circle | Project | Description | Status | Language |
| :---: | :--- | :--- | :---: | :---: |
| **Circle 00** | [**Libft**](./Circle-00/Libft) | Re-implementation of essential standard C library functions & linked list utilities | `Completed` | `C` |
| **Circle 01** | [**ft_printf**](./Circle-01/ft_printf) | Custom implementation of `printf` with variadic arguments (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) | `Completed` | `C` |
| **Circle 01** | [**get_next_line**](./Circle-01/get_next_line) | Efficient function reading a single line ending with newline from a file descriptor using static buffer | `Completed` | `C` |
| **Circle 02** | [**push_swap**](./Circle-02/push_swap) | Optimized sorting algorithm sorting stack data using two stacks and a restricted set of instructions | `Completed` | `C` |
| **Circle 02** | *pipex / fract-ol* | UNIX pipeline simulation or fractal graphics engine (MiniLibX) | `In Progress` | `C` |
| **Circle 03** | *minishell* | Minimal UNIX command-line shell with pipes, redirects, and built-ins | `Upcoming` | `C` |
| **Circle 03** | *philosophers* | Concurrency, POSIX threads, mutexes, and the Dining Philosophers synchronization problem | `Upcoming` | `C` |

---

## 🛠️ Norminette & Coding Standards

All C source code in this repository strictly adheres to **42 Norminette** guidelines:
* Max **25 lines** per function.
* Max **5 functions** per `.c` file.
* Strict variable declarations at the start of functions.
* No `for`, `do ... while`, `switch`, `goto`, or ternary operators nesting.
* Compiled with mandatory flags: `-Wall -Wextra -Werror`.
* Zero memory leaks (verified using `valgrind`).

---

## 🚀 Building & Usage

Each project contains its own self-contained `Makefile` with standard 42 rules (`all`, `clean`, `fclean`, `re`).

```bash
# Clone the repository
git clone https://github.com/SS2Genji/42-Cursus.git
cd 42-Cursus

# Build Libft
cd Circle-00/Libft && make

# Build ft_printf
cd ../../Circle-01/ft_printf && make

# Build push_swap
cd ../../Circle-02/push_swap && make
```

---

<div align="center">
  <sub>Developed with ❤️ by <a href="https://github.com/SS2Genji">@SS2Genji</a></sub>
</div>
