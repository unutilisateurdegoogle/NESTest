
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// main function, run after console reset
void main(void) {

  // set palette colors
  pal_col(0,0x02);	// set screen to dark blue
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x30);	// white
  pal_col(4,0x40);

  // write text to name table
  vram_adr(NTADR_A(6,12));		// set address
  vram_write("Dev Start : 31/03/22", 21);	// write bytes to video RAM
vram_adr(NTADR_A(8,9));		// set address
  vram_write("NES TEST PROGRAM", 16);
  vram_adr(NTADR_A(1,1));
  


  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1) ;
}
