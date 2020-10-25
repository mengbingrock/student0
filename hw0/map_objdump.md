
map:     file format elf32-i386
map
architecture: i386, flags 0x00000150:
HAS_SYMS, DYNAMIC, D_PAGED
start address 0x00000470

Program Header:
    PHDR off    0x00000034 vaddr 0x00000034 paddr 0x00000034 align 2**2
         filesz 0x00000120 memsz 0x00000120 flags r--
  INTERP off    0x00000154 vaddr 0x00000154 paddr 0x00000154 align 2**0
         filesz 0x00000013 memsz 0x00000013 flags r--
    LOAD off    0x00000000 vaddr 0x00000000 paddr 0x00000000 align 2**12
         filesz 0x000009e4 memsz 0x000009e4 flags r-x
    LOAD off    0x00000ed0 vaddr 0x00001ed0 paddr 0x00001ed0 align 2**12
         filesz 0x0000013c memsz 0x00000144 flags rw-
 DYNAMIC off    0x00000ed8 vaddr 0x00001ed8 paddr 0x00001ed8 align 2**2
         filesz 0x000000f8 memsz 0x000000f8 flags rw-
    NOTE off    0x00000168 vaddr 0x00000168 paddr 0x00000168 align 2**2
         filesz 0x00000044 memsz 0x00000044 flags r--
EH_FRAME off    0x0000085c vaddr 0x0000085c paddr 0x0000085c align 2**2
         filesz 0x0000004c memsz 0x0000004c flags r--
   STACK off    0x00000000 vaddr 0x00000000 paddr 0x00000000 align 2**4
         filesz 0x00000000 memsz 0x00000000 flags rw-
   RELRO off    0x00000ed0 vaddr 0x00001ed0 paddr 0x00001ed0 align 2**0
         filesz 0x00000130 memsz 0x00000130 flags r--

Dynamic Section:
  NEEDED               libc.so.6
  INIT                 0x000003e0
  FINI                 0x000007c4
  INIT_ARRAY           0x00001ed0
  INIT_ARRAYSZ         0x00000004
  FINI_ARRAY           0x00001ed4
  FINI_ARRAYSZ         0x00000004
  GNU_HASH             0x000001ac
  STRTAB               0x0000026c
  SYMTAB               0x000001cc
  STRSZ                0x000000bf
  SYMENT               0x00000010
  DEBUG                0x00000000
  PLTGOT               0x00001fd0
  PLTRELSZ             0x00000020
  PLTREL               0x00000011
  JMPREL               0x000003c0
  REL                  0x00000380
  RELSZ                0x00000040
  RELENT               0x00000008
  FLAGS                0x00000008
  FLAGS_1              0x08000001
  VERNEED              0x00000340
  VERNEEDNUM           0x00000001
  VERSYM               0x0000032c
  RELCOUNT             0x00000004

Version References:
  required from libc.so.6:
    0x09691f73 0x00 04 GLIBC_2.1.3
    0x0d696914 0x00 03 GLIBC_2.4
    0x0d696910 0x00 02 GLIBC_2.0

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .interp       00000013  00000154  00000154  00000154  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.ABI-tag 00000020  00000168  00000168  00000168  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .note.gnu.build-id 00000024  00000188  00000188  00000188  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .gnu.hash     00000020  000001ac  000001ac  000001ac  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .dynsym       000000a0  000001cc  000001cc  000001cc  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .dynstr       000000bf  0000026c  0000026c  0000026c  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .gnu.version  00000014  0000032c  0000032c  0000032c  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .gnu.version_r 00000040  00000340  00000340  00000340  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .rel.dyn      00000040  00000380  00000380  00000380  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .rel.plt      00000020  000003c0  000003c0  000003c0  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 10 .init         00000023  000003e0  000003e0  000003e0  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 11 .plt          00000050  00000410  00000410  00000410  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .plt.got      00000010  00000460  00000460  00000460  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .text         00000354  00000470  00000470  00000470  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 14 .fini         00000014  000007c4  000007c4  000007c4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 15 .rodata       00000084  000007d8  000007d8  000007d8  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 16 .eh_frame_hdr 0000004c  0000085c  0000085c  0000085c  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 17 .eh_frame     0000013c  000008a8  000008a8  000008a8  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 18 .init_array   00000004  00001ed0  00001ed0  00000ed0  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 19 .fini_array   00000004  00001ed4  00001ed4  00000ed4  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 20 .dynamic      000000f8  00001ed8  00001ed8  00000ed8  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 21 .got          00000030  00001fd0  00001fd0  00000fd0  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 22 .data         0000000c  00002000  00002000  00001000  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 23 .bss          00000008  0000200c  0000200c  0000100c  2**2
                  ALLOC
 24 .comment      00000029  00000000  00000000  0000100c  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
00000154 l    d  .interp	00000000              .interp
00000168 l    d  .note.ABI-tag	00000000              .note.ABI-tag
00000188 l    d  .note.gnu.build-id	00000000              .note.gnu.build-id
000001ac l    d  .gnu.hash	00000000              .gnu.hash
000001cc l    d  .dynsym	00000000              .dynsym
0000026c l    d  .dynstr	00000000              .dynstr
0000032c l    d  .gnu.version	00000000              .gnu.version
00000340 l    d  .gnu.version_r	00000000              .gnu.version_r
00000380 l    d  .rel.dyn	00000000              .rel.dyn
000003c0 l    d  .rel.plt	00000000              .rel.plt
000003e0 l    d  .init	00000000              .init
00000410 l    d  .plt	00000000              .plt
00000460 l    d  .plt.got	00000000              .plt.got
00000470 l    d  .text	00000000              .text
000007c4 l    d  .fini	00000000              .fini
000007d8 l    d  .rodata	00000000              .rodata
0000085c l    d  .eh_frame_hdr	00000000              .eh_frame_hdr
000008a8 l    d  .eh_frame	00000000              .eh_frame
00001ed0 l    d  .init_array	00000000              .init_array
00001ed4 l    d  .fini_array	00000000              .fini_array
00001ed8 l    d  .dynamic	00000000              .dynamic
00001fd0 l    d  .got	00000000              .got
00002000 l    d  .data	00000000              .data
0000200c l    d  .bss	00000000              .bss
00000000 l    d  .comment	00000000              .comment
00000000 l    df *ABS*	00000000              crtstuff.c
000004c0 l     F .text	00000000              deregister_tm_clones
00000500 l     F .text	00000000              register_tm_clones
00000550 l     F .text	00000000              __do_global_dtors_aux
0000200c l     O .bss	00000001              completed.7283
00001ed4 l     O .fini_array	00000000              __do_global_dtors_aux_fini_array_entry
000005a0 l     F .text	00000000              frame_dummy
00001ed0 l     O .init_array	00000000              __frame_dummy_init_array_entry
00000000 l    df *ABS*	00000000              map.c
00000000 l    df *ABS*	00000000              recurse.c
00000000 l    df *ABS*	00000000              crtstuff.c
000009e0 l     O .eh_frame	00000000              __FRAME_END__
00000000 l    df *ABS*	00000000              
00001ed4 l       .init_array	00000000              __init_array_end
00001ed8 l     O .dynamic	00000000              _DYNAMIC
00001ed0 l       .init_array	00000000              __init_array_start
0000085c l       .eh_frame_hdr	00000000              __GNU_EH_FRAME_HDR
00001fd0 l     O .got	00000000              _GLOBAL_OFFSET_TABLE_
000007a0 g     F .text	00000002              __libc_csu_fini
00000000  w      *UND*	00000000              _ITM_deregisterTMCloneTable
000004b0 g     F .text	00000004              .hidden __x86.get_pc_thunk.bx
00002000  w      .data	00000000              data_start
00000000       F *UND*	00000000              printf@@GLIBC_2.0
0000200c g       .data	00000000              _edata
000007c4 g     F .fini	00000000              _fini
00000000       F *UND*	00000000              __stack_chk_fail@@GLIBC_2.4
000006bc g     F .text	00000073              recur
000005a9 g     F .text	00000000              .hidden __x86.get_pc_thunk.dx
00000000  w    F *UND*	00000000              __cxa_finalize@@GLIBC_2.1.3
00002008 g     O .data	00000004              stuff
00000000       F *UND*	00000000              malloc@@GLIBC_2.0
00002000 g       .data	00000000              __data_start
00000000  w      *UND*	00000000              __gmon_start__
00002004 g     O .data	00000000              .hidden __dso_handle
000007dc g     O .rodata	00000004              _IO_stdin_used
00000000       F *UND*	00000000              __libc_start_main@@GLIBC_2.0
00000740 g     F .text	0000005d              __libc_csu_init
00002010 g     O .bss	00000004              foo
00002014 g       .bss	00000000              _end
00000470 g     F .text	00000000              _start
000007d8 g     O .rodata	00000004              _fp_hw
0000200c g       .bss	00000000              __bss_start
000005ad g     F .text	0000010f              main
0000072f g     F .text	00000000              .hidden __x86.get_pc_thunk.ax
000007b0 g     F .text	00000014              .hidden __stack_chk_fail_local
0000200c g     O .data	00000000              .hidden __TMC_END__
00000000  w      *UND*	00000000              _ITM_registerTMCloneTable
000003e0 g     F .init	00000000              _init



Disassembly of section .init:

000003e0 <_init>:
 3e0:	53                   	push   %ebx
 3e1:	83 ec 08             	sub    $0x8,%esp
 3e4:	e8 c7 00 00 00       	call   4b0 <__x86.get_pc_thunk.bx>
 3e9:	81 c3 e7 1b 00 00    	add    $0x1be7,%ebx
 3ef:	8b 83 24 00 00 00    	mov    0x24(%ebx),%eax
 3f5:	85 c0                	test   %eax,%eax
 3f7:	74 05                	je     3fe <_init+0x1e>
 3f9:	e8 6a 00 00 00       	call   468 <__gmon_start__@plt>
 3fe:	83 c4 08             	add    $0x8,%esp
 401:	5b                   	pop    %ebx
 402:	c3                   	ret    

Disassembly of section .plt:

00000410 <.plt>:
 410:	ff b3 04 00 00 00    	pushl  0x4(%ebx)
 416:	ff a3 08 00 00 00    	jmp    *0x8(%ebx)
 41c:	00 00                	add    %al,(%eax)
	...

00000420 <printf@plt>:
 420:	ff a3 0c 00 00 00    	jmp    *0xc(%ebx)
 426:	68 00 00 00 00       	push   $0x0
 42b:	e9 e0 ff ff ff       	jmp    410 <.plt>

00000430 <__stack_chk_fail@plt>:
 430:	ff a3 10 00 00 00    	jmp    *0x10(%ebx)
 436:	68 08 00 00 00       	push   $0x8
 43b:	e9 d0 ff ff ff       	jmp    410 <.plt>

00000440 <malloc@plt>:
 440:	ff a3 14 00 00 00    	jmp    *0x14(%ebx)
 446:	68 10 00 00 00       	push   $0x10
 44b:	e9 c0 ff ff ff       	jmp    410 <.plt>

00000450 <__libc_start_main@plt>:
 450:	ff a3 18 00 00 00    	jmp    *0x18(%ebx)
 456:	68 18 00 00 00       	push   $0x18
 45b:	e9 b0 ff ff ff       	jmp    410 <.plt>

Disassembly of section .plt.got:

00000460 <__cxa_finalize@plt>:
 460:	ff a3 20 00 00 00    	jmp    *0x20(%ebx)
 466:	66 90                	xchg   %ax,%ax

00000468 <__gmon_start__@plt>:
 468:	ff a3 24 00 00 00    	jmp    *0x24(%ebx)
 46e:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000470 <_start>:
 470:	31 ed                	xor    %ebp,%ebp
 472:	5e                   	pop    %esi
 473:	89 e1                	mov    %esp,%ecx
 475:	83 e4 f0             	and    $0xfffffff0,%esp
 478:	50                   	push   %eax
 479:	54                   	push   %esp
 47a:	52                   	push   %edx
 47b:	e8 22 00 00 00       	call   4a2 <_start+0x32>
 480:	81 c3 50 1b 00 00    	add    $0x1b50,%ebx
 486:	8d 83 d0 e7 ff ff    	lea    -0x1830(%ebx),%eax
 48c:	50                   	push   %eax
 48d:	8d 83 70 e7 ff ff    	lea    -0x1890(%ebx),%eax
 493:	50                   	push   %eax
 494:	51                   	push   %ecx
 495:	56                   	push   %esi
 496:	ff b3 28 00 00 00    	pushl  0x28(%ebx)
 49c:	e8 af ff ff ff       	call   450 <__libc_start_main@plt>
 4a1:	f4                   	hlt    
 4a2:	8b 1c 24             	mov    (%esp),%ebx
 4a5:	c3                   	ret    
 4a6:	66 90                	xchg   %ax,%ax
 4a8:	66 90                	xchg   %ax,%ax
 4aa:	66 90                	xchg   %ax,%ax
 4ac:	66 90                	xchg   %ax,%ax
 4ae:	66 90                	xchg   %ax,%ax

000004b0 <__x86.get_pc_thunk.bx>:
 4b0:	8b 1c 24             	mov    (%esp),%ebx
 4b3:	c3                   	ret    
 4b4:	66 90                	xchg   %ax,%ax
 4b6:	66 90                	xchg   %ax,%ax
 4b8:	66 90                	xchg   %ax,%ax
 4ba:	66 90                	xchg   %ax,%ax
 4bc:	66 90                	xchg   %ax,%ax
 4be:	66 90                	xchg   %ax,%ax

000004c0 <deregister_tm_clones>:
 4c0:	e8 e4 00 00 00       	call   5a9 <__x86.get_pc_thunk.dx>
 4c5:	81 c2 0b 1b 00 00    	add    $0x1b0b,%edx
 4cb:	8d 8a 3c 00 00 00    	lea    0x3c(%edx),%ecx
 4d1:	8d 82 3c 00 00 00    	lea    0x3c(%edx),%eax
 4d7:	39 c8                	cmp    %ecx,%eax
 4d9:	74 1d                	je     4f8 <deregister_tm_clones+0x38>
 4db:	8b 82 1c 00 00 00    	mov    0x1c(%edx),%eax
 4e1:	85 c0                	test   %eax,%eax
 4e3:	74 13                	je     4f8 <deregister_tm_clones+0x38>
 4e5:	55                   	push   %ebp
 4e6:	89 e5                	mov    %esp,%ebp
 4e8:	83 ec 14             	sub    $0x14,%esp
 4eb:	51                   	push   %ecx
 4ec:	ff d0                	call   *%eax
 4ee:	83 c4 10             	add    $0x10,%esp
 4f1:	c9                   	leave  
 4f2:	c3                   	ret    
 4f3:	90                   	nop
 4f4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 4f8:	f3 c3                	repz ret 
 4fa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

00000500 <register_tm_clones>:
 500:	e8 a4 00 00 00       	call   5a9 <__x86.get_pc_thunk.dx>
 505:	81 c2 cb 1a 00 00    	add    $0x1acb,%edx
 50b:	55                   	push   %ebp
 50c:	8d 8a 3c 00 00 00    	lea    0x3c(%edx),%ecx
 512:	8d 82 3c 00 00 00    	lea    0x3c(%edx),%eax
 518:	29 c8                	sub    %ecx,%eax
 51a:	89 e5                	mov    %esp,%ebp
 51c:	53                   	push   %ebx
 51d:	c1 f8 02             	sar    $0x2,%eax
 520:	89 c3                	mov    %eax,%ebx
 522:	83 ec 04             	sub    $0x4,%esp
 525:	c1 eb 1f             	shr    $0x1f,%ebx
 528:	01 d8                	add    %ebx,%eax
 52a:	d1 f8                	sar    %eax
 52c:	74 14                	je     542 <register_tm_clones+0x42>
 52e:	8b 92 2c 00 00 00    	mov    0x2c(%edx),%edx
 534:	85 d2                	test   %edx,%edx
 536:	74 0a                	je     542 <register_tm_clones+0x42>
 538:	83 ec 08             	sub    $0x8,%esp
 53b:	50                   	push   %eax
 53c:	51                   	push   %ecx
 53d:	ff d2                	call   *%edx
 53f:	83 c4 10             	add    $0x10,%esp
 542:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 545:	c9                   	leave  
 546:	c3                   	ret    
 547:	89 f6                	mov    %esi,%esi
 549:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00000550 <__do_global_dtors_aux>:
 550:	55                   	push   %ebp
 551:	89 e5                	mov    %esp,%ebp
 553:	53                   	push   %ebx
 554:	e8 57 ff ff ff       	call   4b0 <__x86.get_pc_thunk.bx>
 559:	81 c3 77 1a 00 00    	add    $0x1a77,%ebx
 55f:	83 ec 04             	sub    $0x4,%esp
 562:	80 bb 3c 00 00 00 00 	cmpb   $0x0,0x3c(%ebx)
 569:	75 27                	jne    592 <__do_global_dtors_aux+0x42>
 56b:	8b 83 20 00 00 00    	mov    0x20(%ebx),%eax
 571:	85 c0                	test   %eax,%eax
 573:	74 11                	je     586 <__do_global_dtors_aux+0x36>
 575:	83 ec 0c             	sub    $0xc,%esp
 578:	ff b3 34 00 00 00    	pushl  0x34(%ebx)
 57e:	e8 dd fe ff ff       	call   460 <__cxa_finalize@plt>
 583:	83 c4 10             	add    $0x10,%esp
 586:	e8 35 ff ff ff       	call   4c0 <deregister_tm_clones>
 58b:	c6 83 3c 00 00 00 01 	movb   $0x1,0x3c(%ebx)
 592:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 595:	c9                   	leave  
 596:	c3                   	ret    
 597:	89 f6                	mov    %esi,%esi
 599:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

000005a0 <frame_dummy>:
 5a0:	55                   	push   %ebp
 5a1:	89 e5                	mov    %esp,%ebp
 5a3:	5d                   	pop    %ebp
 5a4:	e9 57 ff ff ff       	jmp    500 <register_tm_clones>

000005a9 <__x86.get_pc_thunk.dx>:
 5a9:	8b 14 24             	mov    (%esp),%edx
 5ac:	c3                   	ret    

000005ad <main>:
 5ad:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 5b1:	83 e4 f0             	and    $0xfffffff0,%esp
 5b4:	ff 71 fc             	pushl  -0x4(%ecx)
 5b7:	55                   	push   %ebp
 5b8:	89 e5                	mov    %esp,%ebp
 5ba:	53                   	push   %ebx
 5bb:	51                   	push   %ecx
 5bc:	83 ec 20             	sub    $0x20,%esp
 5bf:	e8 ec fe ff ff       	call   4b0 <__x86.get_pc_thunk.bx>
 5c4:	81 c3 0c 1a 00 00    	add    $0x1a0c,%ebx
 5ca:	89 c8                	mov    %ecx,%eax
 5cc:	8b 40 04             	mov    0x4(%eax),%eax
 5cf:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 5d2:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 5d8:	89 45 f4             	mov    %eax,-0xc(%ebp)
 5db:	31 c0                	xor    %eax,%eax
 5dd:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%ebp)
 5e4:	83 ec 0c             	sub    $0xc,%esp
 5e7:	6a 64                	push   $0x64
 5e9:	e8 52 fe ff ff       	call   440 <malloc@plt>
 5ee:	83 c4 10             	add    $0x10,%esp
 5f1:	89 45 ec             	mov    %eax,-0x14(%ebp)
 5f4:	83 ec 0c             	sub    $0xc,%esp
 5f7:	6a 64                	push   $0x64
 5f9:	e8 42 fe ff ff       	call   440 <malloc@plt>
 5fe:	83 c4 10             	add    $0x10,%esp
 601:	89 45 f0             	mov    %eax,-0x10(%ebp)
 604:	83 ec 08             	sub    $0x8,%esp
 607:	8d 83 dd e5 ff ff    	lea    -0x1a23(%ebx),%eax
 60d:	50                   	push   %eax
 60e:	8d 83 10 e8 ff ff    	lea    -0x17f0(%ebx),%eax
 614:	50                   	push   %eax
 615:	e8 06 fe ff ff       	call   420 <printf@plt>
 61a:	83 c4 10             	add    $0x10,%esp
 61d:	83 ec 08             	sub    $0x8,%esp
 620:	8d 83 ec e6 ff ff    	lea    -0x1914(%ebx),%eax
 626:	50                   	push   %eax
 627:	8d 83 1c e8 ff ff    	lea    -0x17e4(%ebx),%eax
 62d:	50                   	push   %eax
 62e:	e8 ed fd ff ff       	call   420 <printf@plt>
 633:	83 c4 10             	add    $0x10,%esp
 636:	83 ec 08             	sub    $0x8,%esp
 639:	8d 45 e8             	lea    -0x18(%ebp),%eax
 63c:	50                   	push   %eax
 63d:	8d 83 28 e8 ff ff    	lea    -0x17d8(%ebx),%eax
 643:	50                   	push   %eax
 644:	e8 d7 fd ff ff       	call   420 <printf@plt>
 649:	83 c4 10             	add    $0x10,%esp
 64c:	83 ec 08             	sub    $0x8,%esp
 64f:	8d 83 40 00 00 00    	lea    0x40(%ebx),%eax
 655:	50                   	push   %eax
 656:	8d 83 39 e8 ff ff    	lea    -0x17c7(%ebx),%eax
 65c:	50                   	push   %eax
 65d:	e8 be fd ff ff       	call   420 <printf@plt>
 662:	83 c4 10             	add    $0x10,%esp
 665:	83 ec 08             	sub    $0x8,%esp
 668:	ff 75 ec             	pushl  -0x14(%ebp)
 66b:	8d 83 49 e8 ff ff    	lea    -0x17b7(%ebx),%eax
 671:	50                   	push   %eax
 672:	e8 a9 fd ff ff       	call   420 <printf@plt>
 677:	83 c4 10             	add    $0x10,%esp
 67a:	83 ec 08             	sub    $0x8,%esp
 67d:	ff 75 f0             	pushl  -0x10(%ebp)
 680:	8d 83 5d e8 ff ff    	lea    -0x17a3(%ebx),%eax
 686:	50                   	push   %eax
 687:	e8 94 fd ff ff       	call   420 <printf@plt>
 68c:	83 c4 10             	add    $0x10,%esp
 68f:	83 ec 0c             	sub    $0xc,%esp
 692:	6a 03                	push   $0x3
 694:	e8 23 00 00 00       	call   6bc <recur>
 699:	83 c4 10             	add    $0x10,%esp
 69c:	b8 00 00 00 00       	mov    $0x0,%eax
 6a1:	8b 55 f4             	mov    -0xc(%ebp),%edx
 6a4:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 6ab:	74 05                	je     6b2 <main+0x105>
 6ad:	e8 fe 00 00 00       	call   7b0 <__stack_chk_fail_local>
 6b2:	8d 65 f8             	lea    -0x8(%ebp),%esp
 6b5:	59                   	pop    %ecx
 6b6:	5b                   	pop    %ebx
 6b7:	5d                   	pop    %ebp
 6b8:	8d 61 fc             	lea    -0x4(%ecx),%esp
 6bb:	c3                   	ret    

000006bc <recur>:
 6bc:	55                   	push   %ebp
 6bd:	89 e5                	mov    %esp,%ebp
 6bf:	53                   	push   %ebx
 6c0:	83 ec 14             	sub    $0x14,%esp
 6c3:	e8 67 00 00 00       	call   72f <__x86.get_pc_thunk.ax>
 6c8:	05 08 19 00 00       	add    $0x1908,%eax
 6cd:	65 8b 0d 14 00 00 00 	mov    %gs:0x14,%ecx
 6d4:	89 4d f4             	mov    %ecx,-0xc(%ebp)
 6d7:	31 c9                	xor    %ecx,%ecx
 6d9:	8b 55 08             	mov    0x8(%ebp),%edx
 6dc:	89 55 f0             	mov    %edx,-0x10(%ebp)
 6df:	83 ec 04             	sub    $0x4,%esp
 6e2:	8d 55 f0             	lea    -0x10(%ebp),%edx
 6e5:	52                   	push   %edx
 6e6:	ff 75 08             	pushl  0x8(%ebp)
 6e9:	8d 90 72 e8 ff ff    	lea    -0x178e(%eax),%edx
 6ef:	52                   	push   %edx
 6f0:	89 c3                	mov    %eax,%ebx
 6f2:	e8 29 fd ff ff       	call   420 <printf@plt>
 6f7:	83 c4 10             	add    $0x10,%esp
 6fa:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 6fe:	7e 14                	jle    714 <recur+0x58>
 700:	8b 45 08             	mov    0x8(%ebp),%eax
 703:	83 e8 01             	sub    $0x1,%eax
 706:	83 ec 0c             	sub    $0xc,%esp
 709:	50                   	push   %eax
 70a:	e8 ad ff ff ff       	call   6bc <recur>
 70f:	83 c4 10             	add    $0x10,%esp
 712:	eb 05                	jmp    719 <recur+0x5d>
 714:	b8 00 00 00 00       	mov    $0x0,%eax
 719:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 71c:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 723:	74 05                	je     72a <recur+0x6e>
 725:	e8 86 00 00 00       	call   7b0 <__stack_chk_fail_local>
 72a:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 72d:	c9                   	leave  
 72e:	c3                   	ret    

0000072f <__x86.get_pc_thunk.ax>:
 72f:	8b 04 24             	mov    (%esp),%eax
 732:	c3                   	ret    
 733:	66 90                	xchg   %ax,%ax
 735:	66 90                	xchg   %ax,%ax
 737:	66 90                	xchg   %ax,%ax
 739:	66 90                	xchg   %ax,%ax
 73b:	66 90                	xchg   %ax,%ax
 73d:	66 90                	xchg   %ax,%ax
 73f:	90                   	nop

00000740 <__libc_csu_init>:
 740:	55                   	push   %ebp
 741:	57                   	push   %edi
 742:	56                   	push   %esi
 743:	53                   	push   %ebx
 744:	e8 67 fd ff ff       	call   4b0 <__x86.get_pc_thunk.bx>
 749:	81 c3 87 18 00 00    	add    $0x1887,%ebx
 74f:	83 ec 0c             	sub    $0xc,%esp
 752:	8b 6c 24 28          	mov    0x28(%esp),%ebp
 756:	8d b3 04 ff ff ff    	lea    -0xfc(%ebx),%esi
 75c:	e8 7f fc ff ff       	call   3e0 <_init>
 761:	8d 83 00 ff ff ff    	lea    -0x100(%ebx),%eax
 767:	29 c6                	sub    %eax,%esi
 769:	c1 fe 02             	sar    $0x2,%esi
 76c:	85 f6                	test   %esi,%esi
 76e:	74 25                	je     795 <__libc_csu_init+0x55>
 770:	31 ff                	xor    %edi,%edi
 772:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 778:	83 ec 04             	sub    $0x4,%esp
 77b:	55                   	push   %ebp
 77c:	ff 74 24 2c          	pushl  0x2c(%esp)
 780:	ff 74 24 2c          	pushl  0x2c(%esp)
 784:	ff 94 bb 00 ff ff ff 	call   *-0x100(%ebx,%edi,4)
 78b:	83 c7 01             	add    $0x1,%edi
 78e:	83 c4 10             	add    $0x10,%esp
 791:	39 fe                	cmp    %edi,%esi
 793:	75 e3                	jne    778 <__libc_csu_init+0x38>
 795:	83 c4 0c             	add    $0xc,%esp
 798:	5b                   	pop    %ebx
 799:	5e                   	pop    %esi
 79a:	5f                   	pop    %edi
 79b:	5d                   	pop    %ebp
 79c:	c3                   	ret    
 79d:	8d 76 00             	lea    0x0(%esi),%esi

000007a0 <__libc_csu_fini>:
 7a0:	f3 c3                	repz ret 
 7a2:	66 90                	xchg   %ax,%ax
 7a4:	66 90                	xchg   %ax,%ax
 7a6:	66 90                	xchg   %ax,%ax
 7a8:	66 90                	xchg   %ax,%ax
 7aa:	66 90                	xchg   %ax,%ax
 7ac:	66 90                	xchg   %ax,%ax
 7ae:	66 90                	xchg   %ax,%ax

000007b0 <__stack_chk_fail_local>:
 7b0:	53                   	push   %ebx
 7b1:	e8 fa fc ff ff       	call   4b0 <__x86.get_pc_thunk.bx>
 7b6:	81 c3 1a 18 00 00    	add    $0x181a,%ebx
 7bc:	83 ec 08             	sub    $0x8,%esp
 7bf:	e8 6c fc ff ff       	call   430 <__stack_chk_fail@plt>

Disassembly of section .fini:

000007c4 <_fini>:
 7c4:	53                   	push   %ebx
 7c5:	83 ec 08             	sub    $0x8,%esp
 7c8:	e8 e3 fc ff ff       	call   4b0 <__x86.get_pc_thunk.bx>
 7cd:	81 c3 03 18 00 00    	add    $0x1803,%ebx
 7d3:	83 c4 08             	add    $0x8,%esp
 7d6:	5b                   	pop    %ebx
 7d7:	c3                   	ret    
