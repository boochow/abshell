# abshell
##Description
Abshell is a command shell for Arduboy and is based on [NT-shell](http://www.cubeatsystems.com/ntshell/index.html).

You can send commands from PC to Arduboy via USB-serial port to draw graphics on Arduboy screen.

Any VT100 compatible serial port terminal softwares (PuTTY, etc.) can be used with abshell.

##Commands
###syntax
command arg1 arg2 arg3 ...
###graphics commands
circle, fcircle, line, lineto, rect, frect, rrect, frrect, tri, ftri
###text commands
print, tsize
###bitmap commands
pixels
###other graphics-related commands
moveto, color, clear
###miscellaneous
keystat, tone, help, info

##example

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
