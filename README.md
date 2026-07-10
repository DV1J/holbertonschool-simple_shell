placee holder until we finish coding

## Built-in Commands

### env
Prints the current environment variables.

**Usage:**
```bash
$ env
USER=julien
LANGUAGE=en_US
HOME=/home/julien
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
TERM=xterm-256color
...
```

**Description:**
- Iterates through the `environ` array provided by the operating system
- Prints each environment variable in `NAME=value` format
- Returns 0 on success
- Can be called multiple times without issues

**Implementation:**
- File: `environ.c`
- Function: `int env_builtin(void)`
- Uses external `environ` variable declared in `shell.h`
- No external commands or system calls needed

---

## Process Execution
## exec
Forks a child process and executes a command with its arguments.

**Usage:**

```Bash
$ /bin/ls
file1.c file2.c shell.h
$ /bin/ls -l
total 8
-rw-r--r-- 1 user user 412 Jul 10 14:18 file1.c
-rw-r--r-- 1 user user 284 Jul 10 14:18 shell.h
...
```
**Description:**
-Creates a new child process using fork()
-Replaces the child process image with the specified command using execve()
-Suspends execution of the parent process using wait() until the child terminates
-Returns 0 on success, or appropriate error statuses if fork or execution fails

**Implementation:**
-File: `exec.c`
-Function: `int exec(char *av[])`
-Uses system calls `fork()`, `execve()`, and `wait()`
-Leverages the external environ variable to pass the environment state to the new program
