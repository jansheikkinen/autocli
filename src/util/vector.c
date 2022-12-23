// vector.c

#include "vector.h"

struct Vector add_vec(const struct Vector* v1, const struct Vector* v2) {
  return (struct Vector){ v1->x + v2->x, v1->y + v2->y };
}

struct Vector add_scalar_vec(const struct Vector* v, long scalar) {
  return (struct Vector){ v->x + scalar, v->y + scalar };
}


bool vec_eq(const struct Vector* v1, const struct Vector* v2) {
  return (v1->x == v2->x) && (v1->y == v2->y);
}


struct Vector mult_scalar_vec(const struct Vector* v, long scalar) {
  return (struct Vector){ v->x * scalar, v->y * scalar };
}

long vec_to_index(const struct Vector* vec, long width) {
  return (vec->y * width) + vec->x;
}
