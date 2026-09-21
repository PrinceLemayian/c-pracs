/*
 * Aliasing and related C concepts.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aliasing: two pointers alias when they point at the same object.
 * A write through one is immediately visible through the other. */
static void section1_basic_aliasing(void) {
  puts("\n-- Section 1: Basic Pointer Aliasing --");

  int x = 10;
  int *p = &x;
  int *q = &x; /* p and q alias the same object x */

  printf("  x=%d  *p=%d  *q=%d\n", x, *p, *q);

  *p = 42;
  printf("  After *p = 42:\n");
  printf("  x=%d  *p=%d  *q=%d\n", x, *p, *q);

  int arr[3] = {1, 2, 3};
  int *first = &arr[0];
  int *second = &arr[1];

  *first = 99; /* distinct elements do not alias */
  printf("  arr[0]=%d arr[1]=%d  (second untouched: %d)\n", arr[0], arr[1],
         *second);
}

/* restrict (C99) promises the compiler that pointers do not alias within
 * this scope, so it may cache a loaded value in a register instead of
 * reloading it. Breaking the promise is undefined behaviour. */
static void scale_array(float *arr, const float *scale, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] *= *scale; /* *scale re-read each iteration (compiler is cautious) */
  }
}

static void scale_array_restrict(float *restrict arr,
                                 const float *restrict scale, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] *= *scale; /* *scale may be hoisted out of the loop */
  }
}

static void section2_restrict(void) {
  puts("\n-- Section 2: restrict Keyword --");

  float data[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  float factor = 2.0f;

  scale_array(data, &factor, 4);
  printf("  After scale_array x2:          [%.1f %.1f %.1f %.1f]\n", data[0],
         data[1], data[2], data[3]);

  scale_array_restrict(data, &factor, 4);
  printf("  After scale_array_restrict x2: [%.1f %.1f %.1f %.1f]\n", data[0],
         data[1], data[2], data[3]);

  /* When the scale pointer aliases the array, the result is not a clean x2:
   * arr2[0] *= arr2[0] changes the value everyone else reads. */
  float arr2[4] = {1.0f, 2.0f, 3.0f, 4.0f};
  scale_array(arr2, &arr2[0], 4);
  printf("  Aliased scale (arr2[0] is scale): [%.1f %.1f %.1f %.1f]\n", arr2[0],
         arr2[1], arr2[2], arr2[3]);
}

/* Strict aliasing rule (C11 6.5p7): an object must be accessed only through
 * an lvalue of a compatible type (or a char type). This lets the compiler
 * assume, e.g., a float* and an int* never point at the same memory.
 * Type punning must therefore go through memcpy or a union, never a cast. */
union FloatBits {
  float f;
  uint32_t u;
};

static uint32_t float_to_bits_memcpy(float f) {
  uint32_t bits;
  memcpy(&bits, &f, sizeof bits); /* byte copy: always well-defined */
  return bits;
}

static uint32_t float_to_bits_union(float f) {
  union FloatBits fb = {.f = f}; /* union punning: well-defined in C */
  return fb.u;
}

/* Fast inverse square root (Quake III). The original *(long*)&y cast broke
 * strict aliasing; memcpy does the same bit manipulation without UB. */
static float fast_inv_sqrt(float number) {
  const float threehalfs = 1.5f;
  float y = number;
  float x2 = y * 0.5f;

  uint32_t i;
  memcpy(&i, &y, sizeof i);
  i = 0x5f3759df - (i >> 1);
  memcpy(&y, &i, sizeof y);

  y = y * (threehalfs - (x2 * y * y)); /* one Newton-Raphson step */
  return y;
}

static void section3_strict_aliasing(void) {
  puts("\n-- Section 3: Strict Aliasing Rule & Type Punning --");

  float pi = 3.14159265f;

  uint32_t bits_m = float_to_bits_memcpy(pi);
  uint32_t bits_u = float_to_bits_union(pi);
  printf("  float %.8f\n", pi);
  printf("  bit pattern via memcpy: 0x%08X\n", bits_m);
  printf("  bit pattern via union:  0x%08X\n", bits_u);

  /* Decode the IEEE-754 fields from the raw bits. */
  int sign = (bits_m >> 31) & 0x1;
  int exponent = ((bits_m >> 23) & 0xFF) - 127;
  uint32_t mantissa = bits_m & 0x7FFFFF;
  printf("  IEEE-754: sign=%d  exponent=%d  mantissa=0x%06X\n", sign, exponent,
         mantissa);

  float n = 4.0f;
  printf("  fast_inv_sqrt(%.1f) ~ %.6f  (true: %.6f)\n", n, fast_inv_sqrt(n),
         1.0f / 2.0f);
}

/* Exception to strict aliasing: any object may be accessed through a
 * (unsigned) char pointer. This is what makes serialisation, hashing, and
 * byte inspection legal. */
static void section4_char_aliasing(void) {
  puts("\n-- Section 4: char* Can Alias Anything --");

  uint32_t value = 0xDEADBEEF;
  unsigned char *bytes = (unsigned char *)&value;

  printf("  uint32_t 0x%08X as bytes (little-endian first):\n  ", value);
  for (size_t i = 0; i < sizeof value; i++) {
    printf("  [%zu]=0x%02X", i, bytes[i]);
  }
  putchar('\n');

  /* Endianness: inspect the first byte of a known 16-bit value. */
  uint16_t probe = 0x0102;
  unsigned char lo = *(unsigned char *)&probe;
  printf("  Endianness: %s-endian (low byte of 0x0102 is 0x%02X)\n",
         lo == 0x02 ? "little" : "big", lo);
}

/* volatile tells the compiler a value may change by means it cannot see
 * (hardware register, signal handler). Every access must hit real memory:
 * no caching, no eliding. It is not a threading/synchronisation primitive. */
static volatile uint8_t STATUS_REG = 0;

static void section5_volatile(void) {
  puts("\n-- Section 5: volatile --");

  STATUS_REG = 0x01;
  printf("  STATUS_REG after write 0x01: 0x%02X\n", STATUS_REG);
  STATUS_REG |= 0x02;
  printf("  STATUS_REG after OR  0x02: 0x%02X\n", STATUS_REG);
  STATUS_REG &= ~0x01u;
  printf("  STATUS_REG after CLEAR 0x01: 0x%02X\n", STATUS_REG);

  int dummy = 0;
  for (int i = 0; i < 1000000; i++)
    dummy++; /* optimiser may delete this loop entirely */
  (void)dummy;

  volatile int busy = 0;
  for (int i = 0; i < 10; i++)
    busy++; /* volatile: loop cannot be optimised away */
  printf("  volatile busy-loop ended at: %d\n", busy);
}

/* memcpy requires non-overlapping regions; memmove handles overlap by
 * choosing a safe copy direction. Use memmove when regions might overlap. */
static void print_arr(const char *label, const int *a, int n) {
  printf("  %s: [", label);
  for (int i = 0; i < n; i++)
    printf("%d%s", a[i], i < n - 1 ? " " : "");
  puts("]");
}

static void section6_overlap(void) {
  puts("\n-- Section 6: Overlapping Memory (memcpy vs memmove) --");

  int src[6] = {1, 2, 3, 4, 5, 6};
  print_arr("original", src, 6);

  int mv[6];
  memcpy(mv, src, sizeof src);
  memmove(&mv[1], &mv[0], 3 * sizeof(int)); /* correct on overlap */
  print_arr("memmove(&mv[1], &mv[0], 3 ints)", mv, 6);

  int mc[6];
  memcpy(mc, src, sizeof src);
  memcpy(&mc[1], &mc[0], 3 * sizeof(int)); /* overlap: undefined behaviour */
  print_arr("memcpy (&mc[1], &mc[0], 3 ints) [UB]", mc, 6);
}

/* Pointer provenance: the optimiser tracks which object a pointer came from.
 * Two pointers with the same numeric address but different origins may not be
 * treated as aliases. Reconstructing a pointer from an integer loses that
 * provenance, so it must never be used to sidestep aliasing rules. */
static void section7_provenance(void) {
  puts("\n-- Section 7: Pointer Provenance --");

  int a = 1, b = 2;

  uintptr_t addr_b = (uintptr_t)&b;
  int *p = (int *)addr_b; /* holds &b's address but may have lost provenance */

  printf("  &a=%p  &b=%p  p=%p\n", (void *)&a, (void *)&b, (void *)p);
  printf("  *p (via integer round-trip) = %d\n", *p);

  *p = 99; /* compiler may not see this as writing to b */
  printf("  After *p=99:  b=%d  *p=%d\n", b, *p);
}

int main(void) {
  section1_basic_aliasing();
  section2_restrict();
  section3_strict_aliasing();
  section4_char_aliasing();
  section5_volatile();
  section6_overlap();
  section7_provenance();
  return 0;
}
