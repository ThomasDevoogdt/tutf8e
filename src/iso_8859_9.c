#include <stddef.h>  /* size_t */
#include <stdint.h>  /* uint16_t */

int encode_iso_8859_9_utf8(char *dest, size_t size, const char *src)
{
  unsigned char *o = (unsigned char *) dest;
  unsigned char *end = dest + size;
  for (const unsigned char *i = (unsigned char *) src; *i; ++i) {
    if (*i<=127) {
      if (end-o < 1) return -2;
      *o++ = *i;
      continue;
    }
    if (*i<128) return -1;
    if (*i==128) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0080>>6);
      *o++ = 0x80 | (0x0080&0x3f);
      continue;
    }
    if (*i<129) return -1;
    if (*i<=207) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<208) return -1;
    if (*i==208) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011e>>6);
      *o++ = 0x80 | (0x011e&0x3f);
      continue;
    }
    if (*i<209) return -1;
    if (*i<=220) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<221) return -1;
    if (*i==221) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0130>>6);
      *o++ = 0x80 | (0x0130&0x3f);
      continue;
    }
    if (*i<222) return -1;
    if (*i==222) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015e>>6);
      *o++ = 0x80 | (0x015e&0x3f);
      continue;
    }
    if (*i<223) return -1;
    if (*i<=239) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<240) return -1;
    if (*i==240) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x011f>>6);
      *o++ = 0x80 | (0x011f&0x3f);
      continue;
    }
    if (*i<241) return -1;
    if (*i<=252) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (*i>>6);
      *o++ = 0x80 | (*i&0x3f);
      continue;
    }
    if (*i<253) return -1;
    if (*i==253) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x0131>>6);
      *o++ = 0x80 | (0x0131&0x3f);
      continue;
    }
    if (*i<254) return -1;
    if (*i==254) {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x015f>>6);
      *o++ = 0x80 | (0x015f&0x3f);
      continue;
    }
    if (*i<255) return -1;
    /* if (*i<=255) */ {
      if (end-o < 2) return -2;
      *o++ = 0xc0 | (0x00ff>>6);
      *o++ = 0x80 | (0x00ff&0x3f);
      continue;
    }
    return -1;
  }
  if (end-o < 1) return -2;
  *o++ = 0;
  return 0;
}