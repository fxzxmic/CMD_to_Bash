# CMD_to_Bash
Relay CMD command to Bash
## How it Work
It gets its own program name and running parameters to splice into `bash.exe -c "<Program Name> <Running Parameters>"`, and create a `bash.exe` process with this command.
## How to Use
Download the Source file([CMD_to_Bash.cpp](https://github.com/fxzxmic/CMD_to_Bash/blob/main/CMD_to_Bash.cpp)) and compile it or download the Pre-built Executable file from [release](https://github.com/fxzxmic/CMD_to_Bash/releases/latest), rename the executable file to any bash command you want to use, such as `ssh.exe`, `openssl.exe`, and execute it in CMD, just as you would in a bash environment.
## Other Contents
Since my knowledge of C/C++ language is very poor, you are welcome to PR and continuously optimize this project. Thank you very much for your contribution.
