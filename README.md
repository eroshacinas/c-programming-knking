# c-programming-knking
repo of codes I replicated from K. N. King's C Programming A Modern Approach


## Compiling C Files

### Basic Compilation

The most basic way to compile a C file is:
```bash
gcc filename.c
```
This creates an executable named `a.out` (or `a.exe` on Windows).

### Specifying Output File Name

To specify a custom name for the executable:
```bash
gcc -o program_name filename.c
```

### Recommended Compilation with Warnings

It's highly recommended to enable compiler warnings to catch potential issues:
```bash
gcc -o program_name filename.c -Wall -Wextra
```

### Common GCC Compiler Options

- `-Wall`: Enable most warning messages
- `-Wextra`: Enable extra warning messages
- `-std=c99`: Use C99 standard (or `-std=c11` for C11)
- `-g`: Include debugging information

### Complete Example Commands

For development (with debugging and all warnings):
```bash
gcc -o program filename.c -Wall -Wextra -g -std=c99
```

### Compiling Multiple Files

If your program consists of multiple C files:
```bash
gcc -o program file1.c file2.c file3.c -Wall -Wextra
```
