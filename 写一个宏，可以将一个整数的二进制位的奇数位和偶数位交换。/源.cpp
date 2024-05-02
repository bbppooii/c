#define _CRT_SECURE_NO_WARNINGS 1
#define SWAP(num) (((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1))
