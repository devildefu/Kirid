#include "Modules/vga.h"
#include "Modules/keyboard.h"

//VGAScreen screen;

void kmain(void) {
	clear();
	//screen.a = 'A';
	color(0x37);
	puts("Hello!");
	putchar(getchar());
	//putchar(screen.a);	
	return;
}
