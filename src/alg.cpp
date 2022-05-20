// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  uint64_t i;
  double x = 1;
  for (i = 1; i <= n; i++)
  x *= value;
  return x;
}
uint64_t fact(uint16_t n) {
  if (n < 0)
  return 0;
  if (n == 0)
  return 1;
  else
  return n * fact(n - 1);
}
double calcItem(double x, uint16_t n) {
  double val = 0;
  val = pown(x, n) / fact(n);
  return val;
}
double expn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i <= count; i++) {
  e += calcItem(x, i);
  }
  return e;
}
double sinn(double x, uint16_t count) {
  double sn = x;
  double val = 0;
  if (count == 1) {
  return sn;
  }
  for (uint16_t i = 2; i <= count ; i ++) {
  val = (pown(-1, i - 1) * calcItem(x, 2 * i - 1));
  sn += val;
  }
  return sn;
}
double cosn(double x, uint16_t count) {
  double cs = 1;
  double val = 0;
  if (count == 1) {
  return cs;
  }
  for (uint16_t i = 2; i <= count; i ++) {
  val = pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  cs += val;
  }
  return cs;
}
