#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

struct Vector {
  long x;
  long y;
};

#define INIT_VEC(x, y) ((struct Vector){ x, y })

struct Vector add_vec(const struct Vector*, const struct Vector*);
struct Vector add_scalar_vec(const struct Vector*, long);

bool vec_eq(const struct Vector*, const struct Vector*);

struct Vector mult_scalar_vec(const struct Vector*, long);

long vec_to_index(const struct Vector*, long);

#endif
