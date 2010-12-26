#ifndef _LAMBDA_H_
#define _LAMBDA_H_

#define lambda(ret, body) ({ ret __fn__ body __fn__; })

#define apply(f, ...) (f(__VA_ARGS__))

#define chain(f, g, ...) (f(g(__VA_ARGS__)))

#define map(source, target, size, f) do {                             \
  for (int __i = 0; __i < size; __i++) target[__i] = f(source[__i]);  \
} while (0)

#define foldl(source, e, size, f) do {                                \
  for (int __i = 0; __i < size; __i++) e = f(e, source[__i]);         \
} while (0)

#define foldr(source, e, size, f) do {                                \
  for (int __i = size - 1; __i >= 0; __i--) e = f(e, source[__i]);    \
} while (0)

#define forall(source, size, f) do {                                  \
  for (int __i = 0; __i < size; __i++) f(source[__i]);                \
} while (0)

#define select(source, target, size, f) do {                          \
  for (int __i = 0, __j = 0; __i < size; __i++)                       \
    if (0 != f(source[__i])) target[__j++] = source[__i];             \
} while (0)

#endif