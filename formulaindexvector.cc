#include "formulaindexvector.h"
#include "keeper.h"
#include "gadget.h"

void Formulaindexvector::resize(int addsize, int lower, Keeper* keeper) {
  int i;
  if (v == 0) {
    size = addsize;
    minpos = lower;
    v = new Formula[size];
  } else if (addsize > 0) {
    assert(lower <= minpos);
    Formula* vnew = new Formula[size + addsize];
    for (i = 0; i < size; i++)
      v[i].Interchange(vnew[i + minpos - lower], keeper);
    size += addsize;
    delete[] v;
    v = vnew;
    minpos = lower;
  }
}

Formula& Formulaindexvector::operator [] (int pos) {
  assert(minpos <= pos && pos < minpos + size);
  return(v[pos - minpos]);
}

const Formula& Formulaindexvector::operator [] (int pos) const {
  assert(minpos <= pos && pos < minpos + size);
  return(v[pos - minpos]);
}

CommentStream& operator >> (CommentStream& infile, Formulaindexvector& Fvec) {
  if (infile.fail()) {
    infile.makebad();
    return infile;
  }
  int i;
  for (i = Fvec.Mincol(); i < Fvec.Maxcol(); i++) {
    if (!(infile >> Fvec[i])) {
      infile.makebad();
      return infile;
    }
  }
  return infile;
}

void Formulaindexvector::Inform(Keeper* keeper) {
  int i;
  for (i = 0; i < size; i++) {
    ostrstream ostr;
    ostr << minpos + i << ends;
    keeper->AddString(ostr.str());
    v[i].Inform(keeper);
    keeper->ClearLast();
  }
}
