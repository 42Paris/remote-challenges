#include <stdint.h>
#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b) {
  static const char hextable[] = "0123456789abcdef";
  static const size_t LEN = sizeof("#ffffff");

  /* Assert that the inputs are valid color values */
  if (r >> 8 || g >> 8 || b >> 8) return NULL;

  char *ret = malloc(LEN);
  if (!ret) return NULL;

  /* The returned string starts with '#' and is null-terminated */
  ret[0] = '#';
  ret[LEN - 1] = 0;

  /* Convenient way of making the function parameters iterable */
  const uint8_t colors[] = {r, g, b};

  for (unsigned i = 0; i < sizeof(colors); ++i) {
    /* Get the hex value of each nibbles of the current color and put it in the
     * return value */
    ret[i * 2 + 2] = hextable[colors[i] & 0x0f];
    ret[i * 2 + 1] = hextable[(colors[i] & 0xf0) >> 4];
  }

  return ret;
}
