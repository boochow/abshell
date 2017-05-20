# abshell
## Description
Abshell is a command shell for Arduboy.
You can send commands from PC to Arduboy via USB-serial port.

No programming skills needed to draw graphics on Arduboy screen !

The core of shell interpreter uses Shinichiro Nakamura's [NT-shell](http://www.cubeatsystems.com/ntshell/index.html).

Any VT100 compatible serial port terminal softwares ([PuTTY](http://www.putty.org/), etc.) can be used with abshell.

## Commands
### syntax
command arg1 arg2 arg3 ...
### graphics commands
circle, fcircle, line, lineto, rect, frect, rrect, frrect, tri, ftri
### text commands
print, tsize
### bitmap commands
pixels, bitmap, .x
### other graphics-related commands
moveto, color, clear
### miscellaneous
keystat, tone, help, info

## example

print hello,world!

tsize 2

print Arduboy

rect 0 32 20 20

fcircle 40 41 10


moveto 64 40

lineto 84 40

lineto 67 51

lineto 74 32

lineto 81 51

lineto 64 40


moveto 100 40

pixels 00100000100 00010001000 00111111100

pixels 01101110110 11111111111 10111111101

pixels 10100000101 00011011000 

tone 440 500


clear

bitmap 52 20 24 24

.x 8080808888888888888c8c8880ffff81

.x 8082849c98c0c080000000f8f80800fe

.x fe222030200f7ff08000000000000000

.x 20e0607f7f30301f1f08080404000001

.x 070e1c7870e0fe60
