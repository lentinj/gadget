#include "variableinfoptrvector.h"
#include "gadget.h"

#ifndef INLINE_VECTORS
#include "variableinfoptrvector.icc"
#endif

VariableInfoptrvector::VariableInfoptrvector(int sz) {
  size = (sz > 0 ? sz : 0);
  if (size > 0)
    v = new VariableInfo*[size];
  else
    v = 0;
}

VariableInfoptrvector::VariableInfoptrvector(int sz, VariableInfo* value) {
  size = (sz > 0 ? sz : 0);
  int i;
  if (size > 0) {
    v = new VariableInfo*[size];
    for (i = 0; i < size; i++)
      v[i] = value;
  } else
    v = 0;
}

VariableInfoptrvector::VariableInfoptrvector(const VariableInfoptrvector& initial) {
  size = initial.size;
  int i;
  if (size > 0) {
    v = new VariableInfo*[size];
    for (i = 0; i < size; i++)
      v[i] = initial.v[i];
  } else
    v = 0;
}

//The function resize add addsize elements to a VariableInfoptrvector and fills it vith value.
void VariableInfoptrvector::resize(int addsize, VariableInfo* value) {
  int oldsize = size;
  this->resize(addsize);
  int i;
  if (addsize > 0)
    for (i = oldsize; i < size; i++)
      v[i] = value;
}

void VariableInfoptrvector::resize(int addsize) {
  int i;
  if (v == 0) {
    size = addsize;
    v = new VariableInfo*[size];
  } else if (addsize > 0) {
    VariableInfo** vnew = new VariableInfo*[addsize + size];
    for (i = 0; i < size; i++)
      vnew[i] = v[i];
    delete[] v;
    v = vnew;
    size += addsize;
  }
}

void VariableInfoptrvector::Delete(int pos) {
  assert(size > 0);
  assert(0 <= pos && pos < size);
  VariableInfo** vnew = new VariableInfo*[size - 1];
  int i;
  for (i = 0; i < pos; i++)
    vnew[i] = v[i];
  for (i = pos; i < size - 1; i++)
    vnew[i] = v[i + 1];
  delete[] v;
  v = vnew;
  size--;
}
