/**
   @file usrcmd.c
   @author CuBeatSystems
   @author Shinichiro Nakamura
   @copyright
   ===============================================================
   Natural Tiny Shell (NT-Shell) Version 0.3.1
   ===============================================================
   Copyright (c) 2010-2016 Shinichiro Nakamura

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without
   restriction, including without limitation the rights to use,
   copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following
   conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
   OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ntopt.h"
#include "ntlibc.h"
#include <Arduino.h>
#include <avr/pgmspace.h>
#include "version.h"
#include "usrcmd_arduboy.h"

#define uart_puts Serial.print

void pgm_print(const char *p) {
  char c;
  while ((c = pgm_read_byte(p++)) != 0)
    Serial.write(c);
}

typedef int (*USRCMDFUNC)(int argc, char **argv);

static int usrcmd_ntopt_callback(int argc, char **argv, void *extobj);
static int usrcmd_help(int argc, char **argv);
static int usrcmd_info(int argc, char **argv);

const char cmd_0[] PROGMEM = "help";
const char desc_0[] PROGMEM = "show help";
const char cmd_1[] PROGMEM = "info";
const char desc_1[] PROGMEM = "show info";

typedef struct {
  PROGMEM const char *cmd;
  PROGMEM const char *desc;
  USRCMDFUNC func;
} cmd_table_t;

static const cmd_table_t cmdlist[] PROGMEM = {
  { cmd_0, desc_0, usrcmd_help },
  { cmd_1, desc_1, usrcmd_info },
  { cmd_10, desc_10, usrcmd_print },
  { cmd_11, desc_11, usrcmd_clear },
  { cmd_12, desc_12, usrcmd_circle },
  { cmd_13, desc_13, usrcmd_fcircle },
  { cmd_14, desc_14, usrcmd_line },
  { cmd_15, desc_15, usrcmd_rect },
  { cmd_16, desc_16, usrcmd_frect },
  { cmd_17, desc_17, usrcmd_rrect },
  { cmd_18, desc_18, usrcmd_frrect },
  { cmd_19, desc_19, usrcmd_tri },
  { cmd_20, desc_20, usrcmd_ftri },
  { cmd_21, desc_21, usrcmd_moveto },
  { cmd_22, desc_22, usrcmd_tsize },
  { cmd_23, desc_23, usrcmd_lineto },
  { cmd_24, desc_24, usrcmd_color },
  { cmd_25, desc_25, usrcmd_keystat },
  { cmd_26, desc_26, usrcmd_pixels },
  { cmd_30, desc_30, usrcmd_tone },
  { cmd_40, desc_40, usrcmd_bitmap },
  { cmd_41, desc_41, usrcmd_x },
};

int usrcmd_execute(const char *text)
{
  return ntopt_parse(text, usrcmd_ntopt_callback, 0);
}

static int usrcmd_ntopt_callback(int argc, char **argv, void *extobj)
{
  if (argc == 0) {
    return 0;
  }
  cmd_table_t *p;
  char cmd[MAX_CMD_LEN];
  p = (cmd_table_t *) &cmdlist[0];
  for (int i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++) {
    char *pcmd = pgm_read_word(&((*p).cmd));
    USRCMDFUNC pfunc = pgm_read_word(&((*p).func));
    strcpy_P(cmd, pcmd);
    if (ntlibc_strcmp((const char *)argv[0], cmd) == 0) {
      return (*pfunc)(argc, argv);
    }
    p++;
  }
  uart_puts(F("Unknown command\r\n"));
  Serial.flush();
  return 0;
}

static int usrcmd_help(int argc, char **argv)
{
  const cmd_table_t *p = &cmdlist[0];
  for (int i = 0; i < sizeof(cmdlist) / sizeof(cmdlist[0]); i++) {
    char *pcmd = pgm_read_word(&((*p).cmd));
    char *pdesc = pgm_read_word(&((*p).desc));
    pgm_print(pcmd);
    uart_puts("\t:");
    pgm_print(pdesc);
    uart_puts("\r\n");
    p++;
  }
  Serial.flush();
  return 0;
}

static int usrcmd_info(int argc, char **argv)
{
  if (argc != 2) {
    uart_puts(F("info sys\r\n"));
    uart_puts(F("info ver\r\n"));
    return 0;
  }
  if (ntlibc_strcmp(argv[1], "sys") == 0) {
    uart_puts(SYSINFOSTR);
    return 0;
  }
  if (ntlibc_strcmp(argv[1], "ver") == 0) {
    uart_puts(VERSIONSTR);
    return 0;
  }
  uart_puts(F("Unknown sub command found\r\n"));
  return -1;
}


