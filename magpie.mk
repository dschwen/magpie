#
# Check the existence of the contrib submodules and build accordingly
#

# first check if LAMMPS is present
LAMMPS_DIR    ?= $(MAGPIE_DIR)/contrib/lammps
ifneq ($(wildcard $(LAMMPS_DIR)/src/Makefile),)
  ADDITIONAL_CPPFLAGS += -DLAMMPS_ENABLED
  app_INCLUDES   += -I $(LAMMPS_DIR)/..
  include $(MAGPIE_DIR)/contrib/lammps.mk
else
  # if not check for SPPARKS (we cannot currently build with both enabled!)
  SPPARKS_DIR    ?= $(MAGPIE_DIR)/contrib/spparks
  ifneq ($(wildcard $(SPPARKS_DIR)/src/Makefile),)
    ADDITIONAL_CPPFLAGS += -DSPPARKS_ENABLED
    app_INCLUDES   += -I $(SPPARKS_DIR)/..
    include $(MAGPIE_DIR)/contrib/spparks.mk
  endif
endif

MYTRIM_DIR    ?= $(MAGPIE_DIR)/contrib/mytrim
ifneq ($(wildcard $(MYTRIM_DIR)/trim.h),)
  ADDITIONAL_CPPFLAGS += -DMYTRIM_ENABLED
  app_INCLUDES   += -I $(MYTRIM_DIR)/..
  include $(MAGPIE_DIR)/contrib/mytrim.mk
endif

include $(MAGPIE_DIR)/contrib/gsl.mk
include $(MAGPIE_DIR)/contrib/fftw3.mk
