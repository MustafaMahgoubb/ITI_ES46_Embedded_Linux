/* Linker script for a bare-metal application */
/* Define Entry Point to the Reset Handler */
ENTRY(_start)

/* Define memory regions */

SECTIONS
{
    . = 0x80000; /*The Address you will load the application at*/ 
    __start = .; /* Define the start of the text section */
    .text : {
        *(.text) /* Include all .text sections from the input files */
    }
    .rodata : {
        *(.rodata) /* Include all .rodata sections from the input files */
    }
    .data : {
        *(.data) /* Include all .data sections from the input files */
    }
    __bss_start = .; /* Define the start of the bss section */
    .bss : {
        *(.bss) /* Include all .bss sections from the input files */
    }
    __bss_end = .; /* Define the end of the bss section */
    __end = .; /* Define the end of the entire program */

}