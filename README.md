## simple POSIX/Unix shell (similar to bash)

**Author:** Shivakumar Nyamagoud (snyamago@gmu.edu)

**This is a simple implementation of `$bash`. After launching `./shell`, the new program operates similarly to bash. In this project, all possible error conditions are handled.**

**How to Build**

To build bash use build.sh script which runs the make clean and make all
```bash
    ./build.sh 
```
**How to Run**
```shell
    ./shell 
```
**How it Works**
After launching the `./shell`, the actual bash or terminal creates a new process, which is a simple bash `$`. Now, the simple bash waits for input commands from the user. Once the user enters the command as a character array (string), it is parsed and divided into command line arguments, which form an array of strings. After considering the first string as the command, binary, or process to execute, the simple bash `$` calls the `fork()` system call to create a new process with its address space. With the user command arguments, the `execvp()` system call is invoked, replacing the child's address space with the new process and its address space. The parent process then waits for the child to execute and return the `SIGCHLD` signal before continuing, and it waits for further user commands.

```shell
shivakumarnyamagouda@Shivakumars-MBP bash % ./shell 
*********************************************
**  This is simple Unix shell(bash)        **
**  Plase read README.md for instructions  **
*********************************************
$ 
$
```
**Hanlding Signal**
I have handled the signals as following
| Signal  | Number |
| ------- | ------ |
| SIGHUP  | 1      |
| SIGINT  | 2      |
| SIGSTOP | 17     |
| SIGCHLD | 20     |

**Usage**
1. "exit" terminates the simple bash.
2. Crtl^C is hadled
3. upon valid command with invalid argument bash printf the error with number and terminataing child
4. upon invald command execvp() returns -1 and child process terminated

**Test Case Results**
[I tested these in MacBook shell environment, so File system is not silimar to linux]
1.  
```shell
$ cd /System
$ ls
Applications    Developer       DriverKit       Library         Volumes         iOSSupport
$ 
$ 
```
2. 
```shell
$ /bin/ls -l
total 0
drwxr-xr-x   40 root  wheel  1280 Jan 11 05:26 Applications
drwxr-xr-x@   2 root  wheel    64 Jan 11 05:26 Developer
drwxr-xr-x    5 root  wheel   160 Jan 11 05:26 DriverKit
drwxr-xr-x  142 root  wheel  4544 Jan 11 05:26 Library
drwxr-xr-x   14 root  wheel   448 Jan 11 05:26 Volumes
drwxr-xr-x    6 root  wheel   192 Jan 11 05:26 iOSSupport
$ 
```
3. 
```shell
$ /bin/echo extra     spaces     will      be      removed
extra spaces will be removed
$ 
```
4. 
```shell
$ echo "but    not is they're    in quotes"
"but    not is they're    in quotes"
$ 
```
5. 
```shell
$ cd /Users/shivakumarnyamagouda/Desktop/bash
$ pwd
/Users/shivakumarnyamagouda/Desktop/bash
$ cd ..
$ pwd
/Users/shivakumarnyamagouda/Desktop
$ 
```
6. 
```shell
$ false
error: false failed with code 256
$ 
```
7. 
```shell
$ /bin/sh -c 'exit 7'
7': -c: line 0: unexpected EOF while looking for matching `''
7': -c: line 1: syntax error: unexpected end of file
error: /bin/sh failed with code 512
$ 
```
8. 
```shell
$ 
$ exit
shivakumarnyamagouda@Shivakumars-MBP bash % 
```
**Conclusion:**
The Simple bash supports most of the features from original shell. runs without any error as handled the all signals and other error check conditions. please suggest is there any improvise i need to do, i am happy to do it.

## Thank you
