#ifndef formatedchatprinter_h
#define formatedchatprinter_h

#include "commentstream.h"
#include "printer.h"
#include "mortpredlength.h"
#include "gadget.h"

class FormatedCHatPrinter;
class TimeClass;
class LengthGroupDivision;
class StockAggregator;
class AreaClass;

class FormatedCHatPrinter : public Printer {
public:
  FormatedCHatPrinter(CommentStream& infile, const AreaClass* const Area, const TimeClass* const TimeInfo);
  virtual ~FormatedCHatPrinter();
  void SetFleet(Fleetptrvector& fleetvec);
  virtual void Print(const TimeClass* const TimeInfo);
protected:
  intvector areas;
  charptrvector areaindex;
  charptrvector fleetnames;
  ofstream outfile;
  Stockptrvector stocks;
  const AreaClass* Area;
  Fleetptrvector fleets;
};

#endif
