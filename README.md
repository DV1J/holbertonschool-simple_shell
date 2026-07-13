# Simple Shell

A UNIX command line interpreter written in C that mimics the behavior of the standard shell.

## Overview

This project implements a simple shell that:
- Displays a prompt and waits for user input
- Executes commands with arguments
- Searches the PATH environment variable for executables
- Implements built-in commands (env, exit)
- Handles end-of-file condition (Ctrl+D)

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty coding style compliance

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -I. -o hsh
```

## Usage

```bash
./hsh
$ command [arguments]
$ env
$ exit
```

## Features

### PATH Handling
- Searches through PATH environment variable for commands
- Supports both absolute paths (`/bin/ls`) and relative paths (`ls`)
- Does NOT fork if command is not found
- Displays "not found" error message

### Command Execution
- Forks child process using `fork()`
- Replaces child process image using `execve()`
- Waits for child process completion using `wait()`
- Passes environment to child process

### Built-in Commands

#### env
Prints the current environment variables in `NAME=value` format.

**Usage:**
```bash
$ env
USER=julien
HOME=/home/julien
PATH=/usr/bin:/bin:...
TERM=xterm-256color
```

**Implementation:**
- File: `environ.c`
- Function: `int env_builtin(void)`

#### exit
Exits the shell.

**Usage:**
```bash
$ exit
```

**Implementation:**
- File: `exit.c`
- Function: `int exit_builtin(void)`

## Project Files

| File | Purpose |
|------|---------|
| `main.c` | Main shell loop, prompt display, command routing |
| `environ.c` | Implementation of env built-in command |
| `exit.c` | Implementation of exit built-in command |
| `exec.c` | Process forking and command execution (execve) |
| `getline.c` | User input reading |
| `token.c` | Command line parsing and tokenization |
| `path.c` | PATH searching and executable location |
| `shell.h` | Header file with function prototypes and includes |

## Examples

### Basic Command Execution
```bash
$ ls
file1.c  file2.c  shell.h
```

### Absolute Path
```bash
$ /bin/ls
file1.c  file2.c  shell.h
```

### Command with Arguments
```bash
$ ls -l /tmp
total 20
-rw------- 1 user user 0 Dec 5 12:09 file.txt
```

### Environment Variables
```bash
$ env
USER=username
HOME=/home/username
...
```

### Exit Shell
```bash
$ exit
user@machine:~$
```

## Error Handling

- Non-existent commands: `./hsh: 1: command: not found`
- Command execution failures: Appropriate error message and exit status
- Fork failures: Error message displayed, shell continues
- End of file (Ctrl+D): Shell exits cleanly

## Process Architecture

1. Display prompt (`$ `)
2. Read user input with `get_line()`
3. Parse input with `token()`
4. Check for built-in commands (env, exit)
5. Search PATH with `get_path()`
6. If found: `fork()` → `execve()` → `wait()`
7. If not found: Display error, return to prompt

## Betty Style Compliance

All code follows Betty style guidelines:
- Maximum 80 characters per line
- Proper function documentation
- No global variables (except extern environ)
- Consistent indentation and formatting

## Limitations

This shell does NOT implement:
- Pipes (`|`)
- Redirections (`>`, `<`, `>>`)
- Special characters (`"`, `'`, ``` `, `\`, `*`, `&`, `#`)
- Command history
- Tab completion
- Cursor movement

## Future Enhancements

- Implement pipe functionality
- Add input/output redirection
- Create additional built-ins (cd, pwd, etc.)
- Add command history and tab completion
- Support for semicolons and logical operators

## Authors

See AUTHORS.md for a list of contributors.
