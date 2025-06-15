# Homework (code)

1. The variable `x` is the same initialised value in both parent and child.
   Modifications to `x` are local to the specific process, without `volatile`.

2. It seems like a parent and child can share an existing file descriptor
   allocated before the call to fork. Opening a file with the `"w"` flag set,
   to override the contents, results in both the parent and child writing
   content. If there were no sharing, and they had to reopen the file
   descriptor, one of their changes would have been overwritten. Using `"a"`
   to append seems to work as expected, and updates are not in any guaranteed
   order, but they append nicely to the existing file.

3. One could use `sleep` to wait a sufficient amount of time on the parent for
   all the instructions to have run on the child. `wait` seems like the better
   option. Had to explicitly declare `void wait(void);` at the top of my `main`
   function for `gcc` to be happy, which is interesting since that's not true
   of `fork`. Oh, it's because `wait` is defined in `<sys/wait.h>`.

4. `execl`, `execlp`, `execle` (`l` suffix) use variable-length arguments to
   specify command-line arguments to the new program. The `v` suffix uses a
   vector (array) to indicate the arguments. The `e` suffix provides the option
   to pass in additions to the environment (the rest use the external variable
   `environ` to determine the new environment). The `p` suffix search the
   `PATH` for the executable, like a shell would. `execvpe` specifically uses
   the `PATH` from the caller's environment, rather than the one provided in
   `envp`.

5. `wait` and `waitpid` return the process ID. This can be inspected on some
   environments with various macros (e.g. `WIFEXITED(pid)` to check if the
   child exited normally).

6. `waitpid` would be useful when managing multiple child processes
   independently.

7. Trying to print after closing `STDOUT_FILENO` does not output anything. The
   parent is still able to write to output normally, but the child's output
   goes nowhere.

8. `p8.c`, followed example from `pipe(7)` manpage.

