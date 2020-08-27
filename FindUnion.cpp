#include "FindUnion.hpp"

UnionFind::UnionFind(int size) 
  : numComponents(size), _size(size), sz(new int[size]), id(new int[size]) {
  for(int i = 0; i < size; i++) {
    sz[i] = 1;
    id[i] = i;
  }
}

int UnionFind::find(int a) {
  int root = a;
  while(root != id[root])
    root = id[root];
  
  while(a != root) {
    int next = id[a];
    id[a] = root;
    a = next;
  }

  return root;
}

bool UnionFind::connected(int a, int b) {
  return find(a) == find(b);
}

int UnionFind::size() {
  return _size;
}

int UnionFind::componentSize(int a) {
  return sz[find(a)];
}

int UnionFind::components() {
  return numComponents;
}

void UnionFind::unify(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);
  if(rootA == rootB) return;

  int sizeA = sz[rootA];
  int sizeB = sz[rootB];

  if(sizeA < sizeB) {
    sz[rootB] = sizeA + sizeB;
    id[rootA] = rootB;
  } else {
    sz[rootA] = sizeA + sizeB;
    id[rootB] = rootA;
  }

  numComponents--;
}

