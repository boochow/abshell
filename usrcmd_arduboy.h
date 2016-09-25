#ifndef _USRCMD_ARDUBOY_H
#define _USRCMD_ARDUBOY_H

const char desc_10[] PROGMEM = "print string at the pen position";
int usrcmd_print(int argc, char **argv);

const char desc_11[] PROGMEM = "clear display";
int usrcmd_clear(int argc, char **argv);

const char desc_12[] PROGMEM = "draw a circle";
int usrcmd_circle(int argc, char **argv);

const char desc_13[] PROGMEM = "draw a filled circle";
int usrcmd_fcircle(int argc, char **argv);

const char desc_14[] PROGMEM = "draw a line";
int usrcmd_line(int argc, char **argv);

const char desc_15[] PROGMEM = "draw a rectangle";
int usrcmd_rect(int argc, char **argv);

const char desc_16[] PROGMEM = "draw a filled rectangle";
int usrcmd_frect(int argc, char **argv);

const char desc_17[] PROGMEM = "draw a rounded rectangle";
int usrcmd_rrect(int argc, char **argv);

const char desc_18[] PROGMEM = "draw a filled rounded rectangle";
int usrcmd_frrect(int argc, char **argv);

const char desc_19[] PROGMEM = "draw a triangle";
int usrcmd_tri(int argc, char **argv);

const char desc_20[] PROGMEM = "draw a filled triangle";
int usrcmd_ftri(int argc, char **argv);

const char desc_21[] PROGMEM = "move the pen to (x, y)";
int usrcmd_moveto(int argc, char **argv);

const char desc_22[] PROGMEM = "set text size scale factor";
int usrcmd_tsize(int argc, char **argv);

const char desc_23[] PROGMEM = "draw a line from the pen position";
int usrcmd_lineto(int argc, char **argv);

const char desc_24[] PROGMEM = "set pen color";
int usrcmd_color(int argc, char **argv);

const char desc_25[] PROGMEM = "read button status";
int usrcmd_keystat(int argc, char **argv);

const char desc_30[] PROGMEM = "play a beep tone";
int usrcmd_tone(int argc, char **argv);
#endif
