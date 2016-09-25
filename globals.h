#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "Arduboy.h"
extern Arduboy arduboy;

#define DRAW_PIXEL(x,y,c)    arduboy.drawPixel((x), (y), (c));
#define GET_PIXEL(x,y)      arduboy.getPixel((x), (y))
#define DRAW_LINE(fx,fy,tx,ty,c) arduboy.drawLine((fx),(fy),(tx),(ty),(c))
#define DRAW_BITMAP(x,y,b,w,h,c) arduboy.drawBitmap((x), (y), (b), (w), (h), (c))
#define DRAW_CIRCLE(x,y,r,c)  arduboy.drawCircle((x), (y), (r), (c))
#define FILL_CIRCLE(x,y,r,c)  arduboy.fillCircle((x), (y), (r), (c))
#define DRAW_RECT(x,y,w,h,c)  arduboy.drawRect((x), (y), (w), (h), (c))
#define FILL_RECT(x,y,w,h,c)  arduboy.fillRect((x), (y), (w), (h), (c))
#define DRAW_RRECT(x,y,w,h,r,c)  arduboy.drawRoundRect((x), (y), (w), (h), (r), (c))
#define FILL_RRECT(x,y,w,h,r,c)  arduboy.fillRoundRect((x), (y), (w), (h), (r), (c))
#define DRAW_TRI(x,y,x1,y1,x2,y2,c)  arduboy.drawTriangle((x), (y), (x1), (y1), (x2), (y2), (c))
#define FILL_TRI(x,y,x1,y1,x2,y2,c)  arduboy.fillTriangle((x), (y), (x1), (y1), (x2), (y2), (c))
#define G_TXT_CURSOR(c,r)   arduboy.setCursor((c),(r))
#define G_PRINT(s)        arduboy.print((s))
#define G_CLEAR()   arduboy.clear()
#define G_FILL(c)   arduboy.fillScreen((c))
#define G_TXT_SIZE(s) arduboy.setTextSize((s))

#define KEY_PRESSED(k)    arduboy.pressed((k))
#define KEY_NOT_PRESSED(k)  arduboy.notPressed((k))

#define TONE(f,d)     arduboy.tunes.tone((f), (d))
#define SOUND_ON      arduboy.audio.on()
#define SOUND_OFF     arduboy.audio.off()

#define SCRN_FPS 60
#define LINE_HEIGHT 8

#endif

