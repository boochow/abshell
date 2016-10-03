#include "ntshell.h"
#include "ntopt.h"
#include "ntlibc.h"

#define INITCODE    (0x4367)
#define SERIAL_READ(HANDLE, BUF, CNT)   ((HANDLE)->func_read(BUF, CNT, (HANDLE)->extobj))

void ntshell_execute_arduino(ntshell_t *p)
{
  if (p->initcode != INITCODE) {
    return;
  }

  unsigned char ch;
  SERIAL_READ(p, (char *)&ch, sizeof(ch));
  vtrecv_execute(&(p->vtrecv), &ch, sizeof(ch));
}

