/**********************************************************************/
/*                     DO NOT MODIFY THIS HEADER                      */
/* MAGPIE - Mesoscale Atomistic Glue Program for Integrated Execution */
/*                                                                    */
/*            Copyright 2017 Battelle Energy Alliance, LLC            */
/*                        ALL RIGHTS RESERVED                         */
/**********************************************************************/
#ifdef CUDA_ENABLED

#pragma once

#include "FFTBufferBase.h"
#include "PerfGraphInterface.h"

#include <cufft.h>
#include <cufftw.h>

template <typename T>
class FFTWBufferBase;

/**
 * FFTW specific interleaved data buffer base class
 */
template <typename T>
class CUFFTWBufferBase : public FFTBufferBase<T>
{
public:
  CUFFTWBufferBase(const InputParameters & parameters);
  ~CUFFTWBufferBase();

  // transforms
  void forwardRaw() override;
  void backwardRaw() override;

  // scaling
  Real forwardScale() override { return _scaling; }

protected:
  ///@{ FFTW plans
  fftw_plan _forward_plan;
  fftw_plan _backward_plan;
  ///@}

  ///@{ timers
  PerfID _perf_plan;
  PerfID _perf_fft;
  ///@}

  /// scale factor
  Real _scaling;

  usingFFTBufferBaseMembers;
};

#endif
