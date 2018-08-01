## Modern Operating Systems

### Info
```
Hardcover: 1136 pages
Publisher: Pearson; 4 edition (March 20, 2014)
Language: English
Author: Andrew S. Tanenbaum, Herbert Bos
Goodread: https://www.goodreads.com/book/show/18762100-modern-operating-systems-4th-edition
```

![](https://www.docdroid.net/file/view/WExMQdZ/modern-operating-systems-latest-in-line-with-answers.jpg)

### Review
Một cuốn sách nhập môn khá đầy đủ về lý thuyết hệ điều hành. Các khái niệm được giải thích vừa đủ và khá well-done, cuối mỗi chương đều có phần điểm qua 1 số kết quả research, tóm tắt và câu hỏi (tầm khoảng 50-60 câu hỏi mỗi chương, các bạn có thể tự challenge mình bằng cách đọc câu hỏi trước khi dọc nội dung chương :p). Tuy nhiên, cuốn sách chỉ tập trung vào lý thuyết, theo mình nên đọc kết hợp với cuốn Operating Systems: Design and Implementation, với cấu trúc sách gần như tương tự, và tập trung vào cài đặt 1 hệ điều hành cụ thể (Mimix) (source code: https://github.com/gdevic/minix1), hoặc bản mimix 3 mới nhất https://github.com/Stichting-MINIX-Research-Foundation/minix. Nếu bạn ko có thời gian tự cài lại từ đầu, thì có thể đọc hiểu source code, tự build lấy và cài lại từng phần. Do topics cover khá lớn, nên rất khó để tóm tắt nội dung trong vài câu, mình sẽ liệt kê mục lục chi tiết ở dưới.



### Table of contents
- Introduction
  + What is an operating system? (as an extended machine, as a resource manager)
  + History of operating systems (vacuum tubes, transistors and batch systems, ICs and multiprogramming, personal computers, mobile computers)
  + Computer hardware review (processors, memory, disks, I/O devices, buses, booting the computer)
  + The operating system zoo (mainframe, server, multiprocessor, personal handheld, embedded, sensor-node, real-time, smart card)
  + Operating system concepts (processes, address spaces, files, input/output, protection, the shell, ontogeny recapitulates phylogeny)
  + System calls (for process management, for file management, for directory management, misc sys call, windows win32 API)
  + Operating system structure (Monolithic systems, layered systems, microkernels, client-server model, virtual machines, exokernels)
  + The world according to C (the C language, header files, large programming projects, the model of run time)
- Processes and threads
  + Processes (the process model, process creation, process termination, process hierarchies, process states, implementation of processes, modeling multiprogramming)
  + Threads (thread usage, the classical thread model, POSIX threads, implementing threads in user space, implementing threads in the kernel, hybrid implementations, scheduler activations, pop-up threads, making single-threaded code multithreaded)
  + Interprocess communication (race conditions, critical regions, mutual exclusion with busy waiting, sleep and wakeup, semaphores, mutexes, monitors, message passing, barriers, avoiding locks: read-copy-update)
  + Scheduling: Introduction to scheduling, scheduling in batch systems, scheduling in real-time systems, policy versus mechanism, thread scheduling)
  + Classical IPC problems (the dining philosophers problem, the readers and writers problem)
- Memory management
  + No memory abstraction
  + A memory abstraction: address spaces (the notion of an address space, swapping, managing free memory)
  + Virtual memory (paging, page tables, speed up paging, page tables for large memories)
  + Page replacement algorithms (optimal Page replacement algorithm, not recently used alg, first-in, first-out alg, second-chance alg, clock alg, least recently used (LRU) alg, working set alg, WSClock alg)
  + Design issues for paging systems (local versus global allocation policies, load control, page size, separate instruction and data spaces, shared pages, shared libraries, mapped files, cleaning policy, virtual memory interface)
  + Implementation issues (operating system involvement with paging, page fault handling, instruction backup, locking pages in memory, backing store, separation of policy and mechanism)
  + Segmentation (implementation of pure segmentation, segmentation with Paging: MULTICS, segmentation with paging: the intel x86)
- File systems
  + Files (file naming, file structure, file types, file access, file attributes, file operations)
  + Directories (single-level directory systems, hierarchical directory systems, path names, directory operations)
  + File-system implementation (file-system layout, implementing files, implementing directories, shared files, log-structure file system, journaling file system, virtual file systems)
  + File-system management and optimization (disk-space management, file-system backups, file-system consistency, file-system performance, defragmenting disks)
  + Example file systems (the MS-DOS file system, the Unix v7 file system, CD-ROM file systems)
- Input/output
  + Principles of I/O hardware
  + Principles of I/O software
  + I/O software layers
  + Disks
  + Clocks
  + User interfaces: Keyboard, mouse, monitor
  + Thin clients
  + Power management
- Deadlocks
- Virtualization and the cloud
- Multiple processor systems
- Security
- Case study 1: Unix, Linux and Android
- Case study 2: Windows 8
- Operating system design

### References
- https://gitlab.redox-os.org/redox-os/redox -> implement os from scratch using rust
- https://github.com/SamyPesse/How-to-Make-a-Computer-Operating-System - Implement os using c/c++
- https://github.com/s-matyukevich/raspberry-pi-os - Learning operating system development using Linux kernel and Raspberry Pi
- http://greenteapress.com/thinkos/ - Introduction to OS for programmers
