What memory address does argv store?

(gdb) print argv
$48 = (char **) 0x7fffffffe4c8


Describe what’s located at that memory address. (What does argv point to?)
(gdb) print argv[0]
$50 = 0x7fffffffe701 "/home/vagrant/code/personal/hw0/map"
(gdb) print argv[1]
$51 = 0x7fffffffe725 "5"


What is the memory address of the recur function?
$52 = {int (int)} 0x5555555547f3 <recur>
callq  0x5555555547f3 <recur>

=> 0x55555555483b <recur+72>:   callq  0x5555555547f3 <recur>
(gdb) info registers
rax            0x1      1
rbx            0x0      0
rcx            0x0      0
rdx            0x0      0
rsi            0x555555756340   93824994337600
rdi            0x1      1
rbp            0x7fffffffe360   0x7fffffffe360
rsp            0x7fffffffe340   0x7fffffffe340
rsp            0x7fffffffe340   0x7fffffffe340
r8             0x0      0
r9             0x0      0
r10            0x0      0
r11            0x246    582
r12            0x5555555545f0   93824992232944
r13            0x7fffffffe4b0   140737488348336
r14            0x0      0
r15            0x0      0
rip            0x55555555483b   0x55555555483b <recur+72>
eflags         0x202    [ IF ]
cs             0x33     51
ss             0x2b     43
ds             0x0      0
es             0x0      0
fs             0x0      0
gs             0x0      0


Now print out the current call stack.

(gdb) backtrace
#0  recur (i=1) at recurse.c:8
#1  0x0000555555554840 in recur (i=2) at recurse.c:9
#2  0x0000555555554840 in recur (i=3) at recurse.c:9
#3  0x00005555555547d8 in main (argc=2, argv=0x7fffffffe4b8) at map.c:28


(gdb) backtrace
#0  recur (i=0) at recurse.c:8
#1  0x0000555555554840 in recur (i=1) at recurse.c:9
#2  0x0000555555554840 in recur (i=2) at recurse.c:9
#3  0x0000555555554840 in recur (i=3) at recurse.c:9
#4  0x00005555555547d8 in main (argc=2, argv=0x7fffffffe4b8) at map.c:28

Which instructions correspond to the return 0 in C?

=> 0x555555554842 <recur+79>:   mov    $0x0,%eax
   0x555555554847 <recur+84>:   mov    -0x8(%rbp),%rcx
   0x55555555484b <recur+88>:   xor    %fs:0x28,%rcx
   0x555555554854 <recur+97>:   je     0x55555555485b <recur+104>
   0x555555554856 <recur+99>:   callq  0x5555555545b0 <__stack_chk_fail@plt>

