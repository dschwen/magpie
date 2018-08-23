###############################################################################
################################### LAMMPS ####################################
###############################################################################

# run Make.sh to recreate the style_*.h files
OUT := $(shell cd $(LAMMPS_DIR)/src && make yes-GRANULAR && make lmpinstalledpkgs.h && bash ./Make.sh style)

# source files (main stuff and GRANULAR package)
lammps_cppsrcfiles := $(shell find $(LAMMPS_DIR)/src -maxdepth 1 -name "*.cpp" -not -name "main.cpp")

# We need to be careful about the mpi STUBS (not including those for now)
#lammps_csrcfiles   := $(shell find $(LAMMPS_DIR) -name "*.c")

app_HEADERS := $(shell find $(LAMMPS_DIR)/src -maxdepth 1 -name "*.h")

# object files
ADDITIONAL_APP_OBJECTS     += $(patsubst %.cpp, %.$(obj-suffix), $(lammps_cppsrcfiles)) \
                              $(patsubst %.c, %.$(obj-suffix), $(lammps_csrcfiles))

# dependencies (C, C++ files only)
ADDITIONAL_APP_DEPS += $(patsubst %.cpp, %.$(obj-suffix).d, $(lammps_cppsrcfiles)) \
                       $(patsubst %.c, %.$(obj-suffix).d, $(lammps_csrcfiles))
