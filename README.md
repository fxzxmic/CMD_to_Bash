# CMD_to_Bash
Forward CMD command to bash  
## How it Work
It gets its own program name and running parameters to splice into `bash.exe -c "<Program Name> <Running parameters>"`, and forwards the command to bash for execution.
## How to Use
Download the Source file([main.c](https://github.com/fxzxmic/CMD_to_Bash/blob/main/main.c)) and compile it or download the Pre-built Executable file from [release](https://github.com/fxzxmic/CMD_to_Bash/releases), rename the executable file to any bash command you want to use, such as `ssh.exe`, `openssl.exe`, and execute it in CMD, just as you would in a bash environment.  
## Other Contents
Since my knowledge of C language is very poor, you are welcome to PR and continuously optimize this project. Thank you very much for your contribution.
