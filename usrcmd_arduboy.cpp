#include "globals.h"
#include "lib/core/ntlibc.h"
#include "usrcmd_arduboy.h"
#include "globals.h"

Arduboy arduboy;

static int16_t pen_x = 0;
static int16_t pen_y = 0;
static uint8_t pen_c = WHITE;
static uint8_t tsize = 1;

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
  Serial.print("pen x:");
  Serial.print(pen_x, DEC);
  Serial.print(" y:");
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
      Serial.print("Text size:");
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
  Serial.print("color:");
  Serial.println(pen_c, DEC);
  return 0;
}

int usrcmd_keystat(int argc, char **argv) {
  if (argc != 1) {
    Serial.println(F("keystatus requires no parameter"));
    return 0;
  }
  Serial.print("A:");
  Serial.print((KEY_PRESSED(A_BUTTON) ? "1" : "0"));
  Serial.print(" B:");
  Serial.print((KEY_PRESSED(B_BUTTON) ? "1" : "0"));
  Serial.print(" L:");
  Serial.print((KEY_PRESSED(LEFT_BUTTON) ? "1" : "0"));
  Serial.print(" R:");
  Serial.print((KEY_PRESSED(RIGHT_BUTTON) ? "1" : "0"));
  Serial.print(" U:");
  Serial.print((KEY_PRESSED(UP_BUTTON) ? "1" : "0"));
  Serial.print(" D:");
  Serial.print((KEY_PRESSED(DOWN_BUTTON) ? "1" : "0"));
  Serial.print("\r\n");
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


