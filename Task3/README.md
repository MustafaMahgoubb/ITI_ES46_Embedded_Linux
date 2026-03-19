Create u-boot image like Task2 
select the right defconfig for raspi (rpi_3_b_plus_defconfig)
apply CROSS_COMPILE and build it






Create SD_Partition like Task1 and mount it

copy raspi boot files to boot partition

bootcode.bin, start.elf, config.txt, U-Boot.bin, board.dtb


***Bare-Metal Programming : Loading and Running a Custom Binary from U-Boot***

Writing a complete 64-bit AArch64 bare-metal application from scratch that blinks an LED connected to a GPIO pin on the Raspberry Pi 3B+

Steps:-
To write a bare-metal application:
1. Set up Compiler for CROSS_COMPILE AArch64
2. No need for System Calls, Libraries, or OS Services -stdnolib -nolibc -nostartfiles -nodefaultlibs
3. Linker Script to define memory layout and entry point
4. Startup Code to initialize the hardware and jump to main function
5. Main Function to configure GPIO and toggle the LED
6. Build the application using the cross-compiler