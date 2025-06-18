#include <stddef.h>
#include <stdio.h>

void *my_memset(void *s, int c, size_t n) {
  unsigned char *src = s;
   
  while (n--) {
    *src++ = c;  
  }

  return s;
}

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n) {
  unsigned char *d = dest;
  const unsigned char *s = src;
  
  while (n--) {
    *d++ = *s++;
  }

  return dest;
}

void *my_memmove(void *dest, const void *src, size_t n) {
  unsigned char *d = dest;
  const unsigned char *s = src;

  while (n--) {
    *d++ = *s++;
  }

  return dest;
}

int my_strlen(const char *s) {
  int i;

  for (i = 0; *s++ != '\0'; i++);

  return i;
}

char *my_strcpy(char *restrict dst, const char *restrict src) {
  char *p = my_memcpy(dst, src, my_strlen(src));
  *p = '\0';

  return p;
}

int my_strcmp(const char *s1, const char *s2) {
  while (*s1++ == *s2++) {
    if (*s1 == '\0' || *s2 == '\0') {
      break;
    }
  }

  return *s1 - *s2;
}

int main(void) {
  char s1[] = "mateus";
  char s2[] = "mateus";
  char s3[] = { 'm', 'a', 't', 'e', 'u', 's' };
  char s4[] = "Hello";
  char s5[100];

  // strcmp tests
  if (my_strcmp(s1, s2) != 0) {
    puts("test 1 failed\n");
  }
  if (my_strcmp(s1, s3) == 0) {
    puts("test 2 failed\n");
  }

  // strlen tests
  if (my_strlen(s1) != 6) {
    puts("test 3 failed\n");
  }
  if (my_strlen(s4) != 5) {
    puts("test 4 failed\n");
  } 

  // strcpy && memcpy tests
  my_strcpy(s5, "san");
  if (my_strcmp(s5, "san") != 0) {
    puts("test 5 failed!");
  }

  my_memmove(s5, "042", sizeof("042"));
  if (my_strcmp(s5, "042") != 0) {
    puts("test 6 failed");
  }  

  puts("finished tests");
}
