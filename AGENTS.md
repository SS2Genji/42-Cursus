# 42-Cursus Repository Guidelines

## README & Documentation Standards
Whenever writing or updating a `README.md` in this repository:
- **Header Format:**
  - Individual 42 projects (`Libft`, `ft_printf`, `get_next_line`, `push_swap`, etc.) must ALWAYS begin with:
    `*This project has been created as part of the 42 curriculum by ahsimsek.*`
    followed immediately by `# <project_name>`
  - Do NOT use HTML badges (`<div align="center">`, shields.io badges), decorative HTML wrappers, or emojis in section titles. Keep headings clean and direct (e.g. `## Overview`, `## Instructions`, `## Algorithm and Data Structure`).
- **Technical Depth & Structure:**
  - `## Description`: Concise overview, problem statement, rules, stack/system concepts.
  - `## Instructions`: `### Compilation` (Makefile rules `all`, `clean`, `fclean`, `re`), `### Execution`, `### Available Operations` (clean markdown tables).
  - `## Algorithm and Data Structure`: Deep mathematical derivations, formulas (e.g. Inversion/Disorder metric `2 * Mistakes / (N * (N - 1))`), data structures, time and space complexity in Big-O notation, Mermaid architecture/flow diagrams, and comprehensive per-algorithm walkthroughs.
  - `## Resources`: `### Classic References`, `### AI Usage`, ending with `*This README was written with the assistance of AI.*`.
- **KaTeX / Math Preview Safety:**
  - NEVER put unescaped underscores `_` inside `\text{...}` in math mode (triggers `KaTeX parse error: '_' allowed only in math mode`).
  - Use backticks for code names, function names, and variable names (e.g. `get_max_bits(N - 1)`, `pos <= size / 2`), and reserve math mode strictly for pure mathematical variables ($N$, $k$, $\mathcal{O}(N \log N)$).

## Repository Constraints
- This repository must remain **STRICTLY PRIVATE** (`isPrivate: true`) at all times unless explicitly instructed by the user.
