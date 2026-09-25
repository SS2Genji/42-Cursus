*This project has been created as part of the 42 curriculum by ahsimsek.*

# get_next_line

## Description
The **get_next_line** project is a fundamental systems programming assignment in the 42 curriculum. The objective is to implement a function in C that reads a text file line by line from a file descriptor (`fd`), returning one line per call until reaching the end of the file (EOF).

The prototype of the function is:
```c
char	*get_next_line(int fd);
```

### Key Behaviors:
- Each call to `get_next_line()` returns the next line from the file associated with `fd`, ending with a newline character (`\n`) unless EOF is reached on a line without a trailing newline.
- When there is nothing left to read or if an error occurs (such as an invalid file descriptor), the function returns `NULL`.
- The buffer size used for `read()` system calls is dynamically configured at compile time via the `-D BUFFER_SIZE=n` flag.
- The function works seamlessly both on regular files and standard input (`stdin`, `fd = 0`).

---

## Instructions

### Compilation
The project is designed to be compiled directly with your source files or tests. You can specify any positive integer for `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

If no `BUFFER_SIZE` flag is passed, `get_next_line.h` provides a default fallback of `42`.

### Example Usage
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

### Bonus Compilation (Multiple File Descriptors)
The bonus part manages multiple file descriptors simultaneously using a single static pointer array (`static char *mem_char[OPEN_MAX]`):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus
```

---

## Algorithm and Data Structure

### 1. Data Structure: Static Pointer (`static char *mem_char`)
The fundamental challenge of reading line-by-line using fixed-size blocks (`BUFFER_SIZE`) is that the `read()` syscall does not stop at newline boundaries. A single read may swallow:
- Multiple newlines,
- A newline followed by characters belonging to the next line.

Because standard local variables on the call stack are deallocated when `get_next_line()` returns, a **static local variable** stored in the **BSS/Data Segment** is used. Its lifetime persists for the entire execution of the process, allowing leftover bytes from previous reads to be preserved across subsequent function calls.

### 2. The Three-Phase Pipeline Algorithm
The implementation is decomposed into three distinct, single-responsibility phases:

1. **Accumulation (`read_fd`):**
   - Continuously calls `read(fd, buffer, BUFFER_SIZE)` in a loop until either a newline (`\n`) is present in the accumulated string or EOF (`read() == 0`) is encountered.
   - Appends newly read chunks using a custom `ft_strjoin` that automatically frees previous allocations to prevent memory leaks.
2. **Extraction (`extract_str`):**
   - Scans the accumulated string up to the first `\n` character.
   - Allocates exact memory for the line (including `\n` and `\0`) and returns it to the caller.
3. **Trimming & Cleanup (`clean_left_str`):**
   - Extracts whatever characters remain after the `\n` delimiter and stores them back into the static pointer for the next call.
   - Frees the old accumulated string. If no characters remain, it frees the pointer and sets it to `NULL` to ensure zero residual heap memory.

---

## Resources

### Classic References
- **`read(2)`**: Linux Programmer's Manual (`man 2 read`).
- **`open(2)`**: Linux Programmer's Manual (`man 2 open`).
- **POSIX.1-2017**: Standard for Information Technology — Portable Operating System Interface.

### AI Usage
- **Conceptual Clarification:** AI tools were used during early research to explore the mechanics of the Linux kernel open file table, file descriptor offsets, and the memory layout differences between Stack, Heap, and BSS segments.
- **Code & Implementation:** All source code, memory allocation patterns, string utility functions, and leak prevention routines were written, debugged, and verified independently by the author to ensure 100% 42 Norminette compliance and zero Valgrind leaks.

---

*This README was written with the assistance of AI.*
