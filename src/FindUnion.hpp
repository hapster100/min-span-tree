#pragma once

#include "FindUnion.hpp"

class UnionFind {
  int _size;
  int* sz;
  int* id;
  int numComponents;
public:
  UnionFind(int size);
  int find(int a);
  bool connected(int a, int b);
  int size();
  int componentSize(int a);
  int components();
  void unify(int a, int b);

};
