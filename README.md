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

circle 64 32 20

print Hello,world!

pixels 010 101 111 101

tone 440 500
