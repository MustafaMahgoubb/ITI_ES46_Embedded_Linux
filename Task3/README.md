# Task 3: U-Boot & Bare-Metal Programming on Raspberry Pi 3B+

---

## 1. U-Boot Image Creation

- **Create U-Boot image as in Task 2**
- **Select the correct defconfig for Raspberry Pi 3B+:**
  ```bash
  make rpi_3_b_plus_defconfig
  ```
- **Apply `CROSS_COMPILE` and build:**
  ```bash
  export CROSS_COMPILE=aarch64-rpi3-linux-gnu-
  make
  ```

---

## 2. SD Card Partitioning & Mounting

- **Create SD partitions as in Task 1**
- **Mount the partitions**

---

## 3. Copy Raspberry Pi Boot Files

Copy the following files to the boot partition:

- `bootcode.bin`
- `start.elf`
- `config.txt`
- `U-Boot.bin`
- `board.dtb`

---

## 4. Bare-Metal Programming: Blinking an LED

Write a complete 64-bit AArch64 bare-metal application to blink an LED on the Raspberry Pi 3B+.

### Steps

1. **Set up the cross-compiler for AArch64**
2. **No system calls, libraries, or OS services:**
   - Use: `-nostdlib -nolibc -nostartfiles -nodefaultlibs`
3. **Create a linker script** to define memory layout and entry point
4. **Write startup code** to initialize hardware and jump to `main`
5. **Implement main function** to configure GPIO and toggle the LED
6. **Build the application:**
   ```bash
   aarch64-rpi3-linux-gnu-gcc -T linker.ld -o app.elf start.s main.c -nostdlib -nostartfiles -nodefaultlibs -nolibc
   ```
7. **Create a U-Boot image and copy it to the SD card**
8. **Boot the Raspberry Pi and load the application into RAM:**
   - Using `fatload`:
     ```bash
     fatload mmc 0:1 $kernel_addr_r app.bin
     ```
   - Or using `tftp`:
     ```bash
     tftp $kernel_addr_r app.bin
     ```
9. **Execute the application from U-Boot:**
   ```bash
   go $kernel_addr_r
   ```

> This will run the bare-metal application, and you should see the LED blinking as expected.

---

## Demo


[Watch the Blinking LED Demo](./videos/Blinking_Led.mp4)