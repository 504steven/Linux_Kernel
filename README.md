# Linux_Kernel Loadable_Module
## Intro
create 2 Linux Kernel(init and exit functions) to list all processes in a linux system in linear order of process id and DFS order of process family tree.   Use Linux virtural machine from http://os-book.com/  

## Tech:
* C lang; Macro
* Bash cmd:  lsmod;  ps -el;  pstree;  dmesg:show kernel buffer log;  insmod xxx.ko;  rmmod xxx.ko

## List_Head circular doubly linked list
![alt text](https://github.com/504steven/Linux_Kernel_Loadable_Module/blob/master/List_Head%20circular%20doubly%20linked%20list.png)

## Linux Process Family Tree Relation:
![alt text](https://github.com/504steven/Linux_Kernel_Loadable_Module/blob/master/Linux%20process%20family%20tree%20relation_1.png)
![alt text](https://github.com/504steven/Linux_Kernel_Loadable_Module/blob/master/Linux%20process%20family%20tree%20relation_2.png)
