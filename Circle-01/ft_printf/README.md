*This project has been created as part of the 42 curriculum by ahsimsek.*

# ft_printf

## Description
The **ft_printf** project is a custom implementation of the standard C library function `printf()` from `libc`. The main objective is to understand the mechanics of variadic functions in C (`<stdarg.h>`) and recreate a robust formatted output printing library without relying on the buffer management of the original `printf`.

The library compiles into `libftprintf.a` and supports the following mandatory conversion specifiers:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string of characters (or `(null)` if pointer is `NULL`). |
| `%p` | Prints a `void *` pointer argument in hexadecimal format with `0x` prefix (or `(nil)` on Linux if `NULL`). |
| `%d` | Prints a signed decimal (base 10) integer. |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a hexadecimal (base 16) number using lowercase letters (`0123456789abcdef`). |
| `%X` | Prints a hexadecimal (base 16) number using uppercase letters (`0123456789ABCDEF`). |
| `%%` | Prints a literal percent sign. |

The function returns the total number of characters printed to standard output (`stdout`), or a negative value if an output error occurs.

---

## Instructions

### Compilation
The project uses a standard `Makefile` with `-Wall -Wextra -Werror` flags. To build the static library:

```bash
make
```

This generates `libftprintf.a` at the root of the repository using the `ar` command (`ar rcs`).

Other available rules:
- `make clean`: Removes object files (`.o`).
- `make fclean`: Removes object files and the generated library `libftprintf.a`.
- `make re`: Rebuilds the entire library from scratch.

### Usage in a C Project
Include the header file `ft_printf.h` in your source code and link against `libftprintf.a`:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello, %s! Number: %d, Hex: %x, Pointer: %p\n",
			"42", 42, 255, &count);
	ft_printf("Total printed: %d characters\n", count);
	return (0);
}
```

Compile with:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program
```

---

## Algorithm and Data Structure

### 1. Data Structure: Variadic Arguments (`va_list`)
In standard C, functions with a variable number of arguments rely on the `<stdarg.h>` macro definitions:
- `va_list`: A type representing the current argument pointer on the call stack.
- `va_start(args, format)`: Initializes the `va_list` pointer to the first optional argument following the named parameter `format`.
- `va_arg(args, type)`: Retrieves the next argument from the stack, casting it to the specified `type` and advancing the pointer.
- `va_end(args)`: Cleans up the `va_list` state.

Because the arguments passed to `ft_printf` are pushed onto the stack according to the ABI calling convention, `va_list` is the standard, zero-overhead mechanism to iterate through parameters of heterogeneous types (`int`, `char *`, `void *`, `unsigned int`).

### 2. Algorithm & Dispatch Strategy
The algorithm processes the format string in a linear, single-pass scan:
1. **Scanning:** A loop iterates over `format[i]` until the null terminator (`\0`) is reached.
2. **Literal Characters:** Normal characters are directly written to `stdout` (`write(1, &format[i], 1)`), and the printed character counter is incremented.
3. **Specifier Interception:** When a `%` character is detected:
   - The scanner checks the following character `format[i + 1]`.
   - A dispatcher function matches the conversion character (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) and calls the corresponding helper function (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putunsigned`, `ft_puthex`, `ft_putptr`).
   - The helper function fetches the corresponding argument via `va_arg` and prints it using recursive base conversion or direct writing, returning the count of printed characters.
4. **Counter Accumulation:** The return value accumulates every successfully written byte. If any write operation fails, error tracking propagates upwards.
5. **Clean Exit:** Once parsing completes, `va_end` is invoked, and the total character count is returned.

---

## Resources

### Classic References
- **`printf(3)`**: Linux Programmer's Manual (`man 3 printf`).
- **`stdarg(3)`**: Variable argument lists documentation (`man 3 stdarg`).

### AI Usage
- **Conceptual Clarification:** AI tools were consulted during early research to understand variadic stack frame mechanisms and clarify standard libc edge-case behaviors (such as `(nil)` representation on Linux).
- **Code & Implementation:** All source code, conversion helpers, parsing logic, and Makefile configurations were independently implemented, structured, and validated by the student to guarantee strict 42 Norminette compliance and zero memory leaks.
- **This README was written with the assistance of AI.**
