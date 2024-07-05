# Console Code Page Example

This project demonstrates setting the console code page to 437 using the Windows Console API.

## Prerequisites

- Windows operating system
- Windows SDK (which includes `Windows.h` and other necessary headers)

### Installing the Windows SDK

If you do not have the Windows SDK installed, you can download and install it from [Microsoft's official site](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/).

## Building

Use a C compiler like `gcc` or MSVC to compile the code. Make sure your compiler can find the Windows SDK headers and libraries.

### Example with GCC:

```sh
gcc main.c -o console_example -lUser32
