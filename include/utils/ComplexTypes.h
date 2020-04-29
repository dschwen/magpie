/**********************************************************************/
/*                     DO NOT MODIFY THIS HEADER                      */
/* MAGPIE - Mesoscale Atomistic Glue Program for Integrated Execution */
/*                                                                    */
/*            Copyright 2017 Battelle Energy Alliance, LLC            */
/*                        ALL RIGHTS RESERVED                         */
/**********************************************************************/

#pragma once

#include <complex>

#include "RankTwoTensor.h"
#include "RankThreeTensor.h"
#include "RankFourTensor.h"

#include "libmesh/vector_value.h"

typedef std::complex<Real> Complex;
typedef VectorValue<Complex> ComplexVectorValue;
typedef RankTwoTensorTempl<Complex> ComplexRankTwoTensor;
typedef RankThreeTensorTempl<Complex> ComplexRankThreeTensor;
typedef RankFourTensorTempl<Complex> ComplexRankFourTensor;

// helper template to select the corresponding complex tensor type
template <typename T>
struct ComplexType;

template <>
struct ComplexType<Real>
{
  using type = Complex;
};

template <>
struct ComplexType<RealVectorValue>
{
  using type = ComplexVectorValue;
};

template <>
struct ComplexType<RankTwoTensor>
{
  using type = ComplexRankTwoTensor;
};

template <>
struct ComplexType<RankThreeTensor>
{
  using type = ComplexRankThreeTensor;
};

template <>
struct ComplexType<RankFourTensor>
{
  using type = ComplexRankFourTensor;
};
