# Questions

## What's `stdint.h`?

'stdint.h' is a library.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To store integers of 8, 32, 32, and 16 bits, respectively.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 Byte, 4 bytes, 4 bytes, 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the bitmap file; `biSize` is the size of the bitmap info header.

## What does it mean if `biHeight` is negative?

If `biHeight` is negative, the image reads from top to bottom.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` specifies the BMP's bits per pixel.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The user misspells or mistypes the file name and the file entered does not exist

## Why is the third argument to `fread` always `1` in our code?

The number of blocks is one

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

Padding = 3

## What does `fseek` do?

It positions the cursor in the file to a given location.

## What is `SEEK_CUR`?

The position from which the fseek starts seeking.

## Whodunit?

Professor Plum.
