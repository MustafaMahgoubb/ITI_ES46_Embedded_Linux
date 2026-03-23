.section .text
.global _start

_start:
    // Disable interrupts
    msr daifset, #0xf

    // Set up stack pointer (below our code)
    ldr x0, =_start
    mov sp, x0

    // Clear BSS
    ldr x0, =__bss_start
    ldr x1, =__bss_end
    mov x2, #0
1:
    cmp x0, x1
    beq 2f
    str x2, [x0], #8
    b 1b
2:

    // Jump to main
    bl main

_return:
    wfe
    b _return
    