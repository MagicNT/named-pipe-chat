# Named Pipe Client/Server Chat Program


## What's a Named Pipe?
- A named pipe, also called FIFO, is a method among many for Inte-Process Communication (IPC), which is based on the pipe concept from Unix.  While a traditional pipe is *unnamed* and can last only as long as the process, a named pipe can last as long as the system is up, no matter the process life time. 

- A named pipe usually appears as a file to which processes attach for IPC. Specifically, a FIFO file is utilized (i.e., this file is created on the filesystem using mkfifo() in C), which is a special type of local storage file that allows >= 2 processes to communicate with each other by R/W to this file.


## What's this program about?
- This program is a chat application where two clients (can be many more), representing processes, communicate to each other through a server by sending messages using a named pipe FIFO file. 


## How to run/use this program?
1. In a terminal, within a working directory where the C source code files are, compile these files into binaries by executing the following command line (make sure you have GCC installed): `make all`. Three binary files (i.e., client_1, client_2 and server) should appear in your working directory
3. In a terminal window, run the *server* binary by executing the following command line: `./server` then run the two other binaries similarily by running each of them within different terminal windows by executing the following command lines respectively: `./client_1` and `./client_2`

![demo](https://user-images.githubusercontent.com/86275885/122862408-123df880-d2ef-11eb-8730-c2c7ac654c0a.png)

