#include "globals.h"
#include "lib/core/ntconf.h"
#include "lib/core/ntlibc.h"
#include "usrcmd_arduboy.h"
#include "globals.h"

Arduboy arduboy;

static int16_t pen_x = 0;
static int16_t pen_y = 0;
static uint8_t pen_c = WHITE;
static uint8_t tsize = 1;
static uint8_t bmp_x = 0;
static uint8_t bmp_y = 0;
static uint8_t bmp_w = 128;
static uint8_t bmp_h = 64;
static uint8_t bmp_cur_x = bmp_x;
static uint8_t bmp_cur_y = bmp_y;

int usrcmd_print(int argc, char **argv) {
  G_TXT_CURSOR(pen_x, pen_y);
  G_PRINT(argv[1]);
  for (char i = 2 ; i < argc ; i++) {
    G_PRINT(" ");
    G_PRINT(argv[i]);
  }
  pen_y += LINE_HEIGHT * tsize;
  return 0;
}

int usrcmd_clear(int argc, char **argv) {
  pen_x = 0;
  pen_y = 0;
  tsize = 1;
  G_TXT_SIZE(tsize);
  pen_c = WHITE;
  bmp_x = 0;
  bmp_y = 0;
  bmp_w = 128;
  bmp_h = 64;
  bmp_cur_x = bmp_x;
  bmp_cur_y = bmp_y;
  G_CLEAR();
  return 0;
}

int usrcmd_circle(int argc, char **argv) {
  if (argc != 4) {
    Serial.println(F("circle x y r"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t r = ntlibc_atoi(argv[3]);
  DRAW_CIRCLE(x, y, r, pen_c);
  return 0;
}

int usrcmd_fcircle(int argc, char **argv) {
  if (argc != 4) {
    Serial.println(F("circle x y r"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t r = ntlibc_atoi(argv[3]);
  FILL_CIRCLE(x, y, r, pen_c);
  return 0;
}

int usrcmd_line(int argc, char **argv) {
  if (argc != 5) {
    Serial.println(F("line x1 y1 x2 y2"));
    return 0;
  }
  uint8_t x0 = ntlibc_atoi(argv[1]);
  uint8_t y0 = ntlibc_atoi(argv[2]);
  uint8_t x1 = ntlibc_atoi(argv[3]);
  uint8_t y1 = ntlibc_atoi(argv[4]);
  DRAW_LINE(x0, y0, x1, y1, pen_c);
  pen_x = x1;
  pen_y = y1;
  return 0;
}

int usrcmd_rect(int argc, char **argv) {
  if (argc != 5) {
    Serial.println(F("rect x y w h"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t w = ntlibc_atoi(argv[3]);
  uint8_t h = ntlibc_atoi(argv[4]);
  DRAW_RECT(x, y, w, h, pen_c);
  return 0;
}

int usrcmd_frect(int argc, char **argv) {
  if (argc != 5) {
    Serial.println(F("frect x y w h"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t w = ntlibc_atoi(argv[3]);
  uint8_t h = ntlibc_atoi(argv[4]);
  FILL_RECT(x, y, w, h, pen_c);
  return 0;
}

int usrcmd_rrect(int argc, char **argv) {
  if (argc != 6) {
    Serial.println(F("rrect x y w h r"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t w = ntlibc_atoi(argv[3]);
  uint8_t h = ntlibc_atoi(argv[4]);
  uint8_t r = ntlibc_atoi(argv[5]);
  DRAW_RRECT(x, y, w, h, r, pen_c);
  return 0;
}

int usrcmd_frrect(int argc, char **argv) {
  if (argc != 6) {
    Serial.println(F("frrect x y w h r"));
    return 0;
  }
  uint8_t x = ntlibc_atoi(argv[1]);
  uint8_t y = ntlibc_atoi(argv[2]);
  uint8_t w = ntlibc_atoi(argv[3]);
  uint8_t h = ntlibc_atoi(argv[4]);
  uint8_t r = ntlibc_atoi(argv[5]);
  FILL_RRECT(x, y, w, h, r, pen_c);
  return 0;
}

int usrcmd_tri(int argc, char **argv) {
  if (argc != 7) {
    Serial.println(F("frrect x y w h r"));
    return 0;
  }
  uint8_t x0 = ntlibc_atoi(argv[1]);
  uint8_t y0 = ntlibc_atoi(argv[2]);
  uint8_t x1 = ntlibc_atoi(argv[3]);
  uint8_t y1 = ntlibc_atoi(argv[4]);
  uint8_t x2 = ntlibc_atoi(argv[5]);
  uint8_t y2 = ntlibc_atoi(argv[6]);
  DRAW_TRI(x0, y0, x1, y1, x2, y2, pen_c);
  return 0;
}

int usrcmd_ftri(int argc, char **argv) {
  if (argc != 7) {
    Serial.println(F("frrect x y w h r"));
    return 0;
  }
  uint8_t x0 = ntlibc_atoi(argv[1]);
  uint8_t y0 = ntlibc_atoi(argv[2]);
  uint8_t x1 = ntlibc_atoi(argv[3]);
  uint8_t y1 = ntlibc_atoi(argv[4]);
  uint8_t x2 = ntlibc_atoi(argv[5]);
  uint8_t y2 = ntlibc_atoi(argv[6]);
  FILL_TRI(x0, y0, x1, y1, x2, y2, pen_c);
  return 0;
}

int usrcmd_moveto(int argc, char **argv) {
  if (argc != 3) {
    Serial.println(F("moveto x y"));
    return 0;
  }
  pen_x = ntlibc_atoi(argv[1]);
  pen_y = ntlibc_atoi(argv[2]);
  G_TXT_CURSOR(pen_x, pen_y);
  Serial.print(F("pen x:"));
  Serial.print(pen_x, DEC);
  Serial.print(F(" y:"));
  Serial.println(pen_y, DEC);
  return 0;
}

int usrcmd_tsize(int argc, char **argv) {
  switch (argc) {
    case 2:
      tsize = ntlibc_atoi(argv[1]);
      if (tsize == 0) tsize = 1;
      G_TXT_SIZE(tsize);
    case 1:
      Serial.print(F("Text size:"));
      Serial.println(tsize, DEC);
      break;
    default:
      Serial.println(F("tsize number (1 is default)"));
  }
  return 0;
}

int usrcmd_lineto(int argc, char **argv) {
  if (argc != 3) {
    Serial.println(F("lineto x y"));
    return 0;
  }
  uint8_t x0 = ntlibc_atoi(argv[1]);
  uint8_t y0 = ntlibc_atoi(argv[2]);
  DRAW_LINE(pen_x, pen_y, x0, y0, pen_c);
  pen_x = x0;
  pen_y = y0;
  return 0;
}

int usrcmd_color(int argc, char **argv) {
  if (argc != 2) {
    Serial.println(F("color c (0=black, 1=white)"));
    return 0;
  }
  pen_c = ntlibc_atoi(argv[1]);
  Serial.print(F("color:"));
  Serial.println(pen_c, DEC);
  return 0;
}

int usrcmd_keystat(int argc, char **argv) {
  if (argc != 1) {
    Serial.println(F("keystatus requires no parameter"));
    return 0;
  }
  Serial.print(F("A:"));
  Serial.print((KEY_PRESSED(A_BUTTON) ? "1" : "0"));
  Serial.print(F(" B:"));
  Serial.print((KEY_PRESSED(B_BUTTON) ? "1" : "0"));
  Serial.print(F(" L:"));
  Serial.print((KEY_PRESSED(LEFT_BUTTON) ? "1" : "0"));
  Serial.print(F(" R:"));
  Serial.print((KEY_PRESSED(RIGHT_BUTTON) ? "1" : "0"));
  Serial.print(F(" U:"));
  Serial.print((KEY_PRESSED(UP_BUTTON) ? "1" : "0"));
  Serial.print(F(" D:"));
  Serial.print((KEY_PRESSED(DOWN_BUTTON) ? "1" : "0"));
  Serial.print(F("\r\n"));
  return 0;
}

int usrcmd_tone(int argc, char **argv) {
  if (argc != 3) {
    Serial.println(F("tone frequency duration"));
    return 0;
  }
  uint16_t f = ntlibc_atoi(argv[1]);
  uint16_t d = ntlibc_atoi(argv[2]);
  TONE(f, d);
  return 0;
}

int usrcmd_pixels(int argc, char **argv) {
  for (uint8_t i = 1; i < argc; i++) {
    int8_t x = pen_x;
    while (*argv[i] != 0)
      if (*(argv[i]++) == '0') {
        DRAW_PIXEL(x++, pen_y, BLACK);
      } else {
        DRAW_PIXEL(x++, pen_y, WHITE);
      }
    pen_y++;
  }
  return 0;
}

void drawBitmap_sram(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color)
{
  unsigned char *sBuffer = arduboy.getBuffer();
  
  if (x+w < 0 || x > WIDTH-1 || y+h < 0 || y > HEIGHT-1)
    return;

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  int rows = h/8;
  if (h%8!=0) rows++;
  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT/8)-1) break;
    if (bRow > -2) {
      for (int iCol = 0; iCol<w; iCol++) {
        if (iCol + x > (WIDTH-1)) break;
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            if      (color == WHITE) sBuffer[ (bRow*WIDTH) + x + iCol ] |= *(bitmap+(a*w)+iCol) << yOffset;
            else if (color == BLACK) sBuffer[ (bRow*WIDTH) + x + iCol ] &= ~(*(bitmap+(a*w)+iCol) << yOffset);
            else                     sBuffer[ (bRow*WIDTH) + x + iCol ] ^= *(bitmap+(a*w)+iCol) << yOffset;
          }
          if (yOffset && bRow<(HEIGHT/8)-1 && bRow > -2) {
            if      (color == WHITE) sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] |= *(bitmap+(a*w)+iCol) >> (8-yOffset);
            else if (color == BLACK) sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] &= ~(*(bitmap+(a*w)+iCol) >> (8-yOffset));
            else                     sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] ^= *(bitmap+(a*w)+iCol) >> (8-yOffset);
          }
        }
      }
    }
  }
}

int usrcmd_bitmap(int argc, char **argv) {
  if (argc == 1) {
    Serial.print(bmp_x, DEC);Serial.print(' ');
    Serial.print(bmp_y, DEC);Serial.print(' ');
    Serial.print(bmp_w, DEC);Serial.print(' ');
    Serial.println(bmp_h, DEC);
  } else if (argc != 5) {
    Serial.println(F("bitmap x y w h"));
    return 0;
  }
  bmp_x = ntlibc_atoi(argv[1]);
  bmp_y = ntlibc_atoi(argv[2]);
  bmp_w = ntlibc_atoi(argv[3]);
  bmp_h = ntlibc_atoi(argv[4]);
  bmp_cur_x = bmp_x;
  bmp_cur_y = bmp_y;
  return 0;
}

uint8_t hex2num(char c) {
  if ((c >= '0') && (c <= '9')) {
    return c - '0';
  } else if ((c >= 'A') && (c <= 'F')) {
    return c - 'A' + 10;
  } else
    return 0;
}

int usrcmd_x(int argc, char **argv) {
  if (argc != 2) {
    Serial.println(F(".x hexstring"));
    return 0;
  }

  static uint8_t buf[NTCONF_EDITOR_MAXLEN / 2];
  uint8_t idx;
  uint8_t c;
  for(idx = 0 ; ((c = *argv[1]) != 0) && (idx < NTCONF_EDITOR_MAXLEN) ; argv[1]++) {
    if (c == ',') continue;
    c = ntlibc_toupper(c);
    if (idx % 2) {
      buf[idx / 2] |= hex2num(c);
    } else {
      buf[idx / 2] = (hex2num(c) << 4);
    }
    idx++;
  }
    
  uint8_t right = bmp_cur_x + idx / 2;
  uint8_t left = bmp_cur_x;
  idx = 0;
  while(left < right) {
    uint8_t w = min(right - left, bmp_x + bmp_w - bmp_cur_x);
    uint8_t h = min(8, bmp_y + bmp_h - bmp_cur_y);
//    Serial.print(bmp_cur_x, DEC); Serial.print(" ");
//    Serial.print(bmp_cur_y, DEC); Serial.print(" ");
//    Serial.print(w, DEC); Serial.print(" ");
//    Serial.print(h, DEC); Serial.print(" ");
//    Serial.print(left, DEC); Serial.print(" ");
//    Serial.print(right, DEC); Serial.println(" ");
    drawBitmap_sram(bmp_cur_x, bmp_cur_y, &buf[idx], w, h, pen_c);
    left += w;
    idx += w;
    bmp_cur_x += w;
    if (bmp_cur_x >= bmp_x + bmp_w) {
      bmp_cur_x = bmp_x;
      bmp_cur_y += h;
      if (bmp_cur_y >= bmp_y + bmp_h) {
        bmp_cur_y = bmp_y;
      }
    }
  }
  return 0;
}



