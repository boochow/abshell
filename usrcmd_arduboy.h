#ifndef _USRCMD_ARDUBOY_H
#define _USRCMD_ARDUBOY_H

#define MAX_CMD_LEN 16

const char cmd_10[] PROGMEM = "print";
const char desc_10[] PROGMEM = "print string at the pen position";
int usrcmd_print(int argc, char **argv);

const char cmd_11[] PROGMEM = "clear";
const char desc_11[] PROGMEM = "clear display";
int usrcmd_clear(int argc, char **argv);

const char cmd_12[] PROGMEM = "circle";
const char desc_12[] PROGMEM = "draw a circle";
int usrcmd_circle(int argc, char **argv);

const char cmd_13[] PROGMEM = "fcircle";
const char desc_13[] PROGMEM = "draw a filled circle";
int usrcmd_fcircle(int argc, char **argv);

const char cmd_14[] PROGMEM = "line";
const char desc_14[] PROGMEM = "draw a line";
int usrcmd_line(int argc, char **argv);

const char cmd_15[] PROGMEM = "rect";
const char desc_15[] PROGMEM = "draw a rectangle";
int usrcmd_rect(int argc, char **argv);

const char cmd_16[] PROGMEM = "frect";
const char desc_16[] PROGMEM = "draw a filled rectangle";
int usrcmd_frect(int argc, char **argv);

const char cmd_17[] PROGMEM = "rrect";
const char desc_17[] PROGMEM = "draw a rounded rectangle";
int usrcmd_rrect(int argc, char **argv);

const char cmd_18[] PROGMEM = "frrect";
const char desc_18[] PROGMEM = "draw a filled rounded rectangle";
int usrcmd_frrect(int argc, char **argv);

const char cmd_19[] PROGMEM = "tri";
const char desc_19[] PROGMEM = "draw a triangle";
int usrcmd_tri(int argc, char **argv);

const char cmd_20[] PROGMEM = "ftri";
const char desc_20[] PROGMEM = "draw a filled triangle";
int usrcmd_ftri(int argc, char **argv);

const char cmd_21[] PROGMEM = "moveto";
const char desc_21[] PROGMEM = "set the pen location";
int usrcmd_moveto(int argc, char **argv);

const char cmd_22[] PROGMEM = "tsize";
const char desc_22[] PROGMEM = "set text size scale factor";
int usrcmd_tsize(int argc, char **argv);

const char cmd_23[] PROGMEM = "lineto";
const char desc_23[] PROGMEM = "draw a line from the pen position";
int usrcmd_lineto(int argc, char **argv);

const char cmd_24[] PROGMEM = "color";
const char desc_24[] PROGMEM = "set pen color";
int usrcmd_color(int argc, char **argv);

const char cmd_25[] PROGMEM = "keystat";
const char desc_25[] PROGMEM = "read the status of buttons";
int usrcmd_keystat(int argc, char **argv);

const char cmd_26[] PROGMEM = "pixels";
const char desc_26[] PROGMEM = "set pixels on horizontal line";
int usrcmd_pixels(int argc, char **argv);

const char cmd_30[] PROGMEM = "tone";
const char desc_30[] PROGMEM = "play a beep tone";
int usrcmd_tone(int argc, char **argv);

const char cmd_40[] PROGMEM = "bitmap";
const char desc_40[] PROGMEM = "set bitmap destination area";
int usrcmd_bitmap(int argc, char **argv);

const char cmd_41[] PROGMEM = ".x";
const char desc_41[] PROGMEM = "send raw data in hex string";
int usrcmd_x(int argc, char **argv);

#endif
