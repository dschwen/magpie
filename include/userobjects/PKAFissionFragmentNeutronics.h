#ifndef PKAFISSIONFRAGMENTNEUTRONICS_H
#define PKAFISSIONFRAGMENTNEUTRONICS_H

#include "PKAGeneratorBase.h"
#include "PKAGeneratorNeutronicsBase.h"
#include "DiscreteFissionPKAPDF.h"

class PKAFissionFragmentNeutronics;

template<>
InputParameters validParams<PKAFissionFragmentNeutronics>();

class PKAFissionFragmentNeutronics : public PKAGeneratorNeutronicsBase
{
public:
  PKAFissionFragmentNeutronics(const InputParameters & parameters);

  ~PKAFissionFragmentNeutronics();

  virtual void appendPKAs(std::vector<MyTRIM_NS::IonBase> & ion_list, Real dt, Real vol, const MyTRIMRasterizer::AveragedData &) const;

  virtual void setPDF(Real magnitude, const std::vector<unsigned int> & ZAID, const std::vector<Real> & energies, const MultiIndex<Real> & probabilities);

protected:
  /**
  / Given the magnitude, ZAIDs, energies, and probabilities passed from MAMMOTH,
  / the cdf will be precomputed for each fission fragment and energy. These cdfs
  / will be sampled to determine the initial state of the ions passed to MyTRIM
  **/
  DiscreteFissionPKAPDF _pdf;
};

#endif //PKAFISSIONFRAGMENTNEUTRONICS_H