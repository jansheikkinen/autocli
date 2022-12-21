#ifndef VECTOR_H
#define VECTOR_H


struct Vector {
  long x;
  long y;
};

struct Vector add_vec(const struct Vector*, const struct Vector*);
struct Vector add_scalar_vec(const struct Vector*, long);

struct Vector mult_scalar_vec(const struct Vector*, long);

long vec_to_index(const struct Vector*, long);

#endif
