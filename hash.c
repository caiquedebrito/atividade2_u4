#include "hash.h"

unsigned long hash(unsigned char *str) {
  unsigned long hash_code = 5381;
  int c;

  while ((c = *str++)) {
    hash_code = ((hash_code << 5) + hash_code) + c;
  }

  return hash_code;
}