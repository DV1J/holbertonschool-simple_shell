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


