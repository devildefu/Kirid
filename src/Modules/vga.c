#include "vga.h"
#include "definitions.h"
#include "io.h"

char* vga_buffer = (char*)0xb8000;
 
void clear() {
	unsigned short j = 0;
 
	while(j < 80 * 25 * 2) {
		vga_buffer[j] = ' ';
		vga_buffer[j+1] = 0x07;
		j += 2;
	}
}
 
void putchar(char character) {
	unsigned short i = curr.curr_pos;
	while(vga_buffer[i]!=' ') {
		i += 2;
	}
	vga_buffer[i] = character;
	uint16_t* color = (uint16_t*)0x1001;
	vga_buffer[i+1] = *color;
}

void puts(const char* string) {
	unsigned short i = 0;
 
	while(string[i] != '\0') {
		putchar(string[i]);
		i += 1;
 	}
}

void color(uint16_t color) {
	uint16_t* colptr = (uint16_t*)0x1001;
	*colptr = color;
}

void gotoxy(int x, int y) {
	curr.curr_pos = x+y*80;
	
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char)(curr.curr_pos&0xFF));
}
