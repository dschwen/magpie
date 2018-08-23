###############################################################################
################################### SPPARKS ###################################
###############################################################################

# run Make.sh to recreate the stytle_*.h files
$(shell cd $(SPPARKS_DIR)/src && ./Make.sh style)

# source files
spparks_cppsrcfiles := $(shell find $(SPPARKS_DIR)/src -maxdepth 1 -name "*.cpp" -not -name "main.cpp")

# We need to be careful about the mpi STUBS (not including those for now)
#spparks_csrcfiles   := $(shell find $(SPPARKS_DIR) -name "*.c")

app_HEADERS := $(shell find $(SPPARKS_DIR)/src -maxdepth 1 -name "*.h")

# object files
ADDITIONAL_APP_OBJECTS     += $(patsubst %.cpp, %.$(obj-suffix), $(spparks_cppsrcfiles)) \
                              $(patsubst %.c, %.$(obj-suffix), $(spparks_csrcfiles))

# dependencies (C, C++ files only)
ADDITIONAL_APP_DEPS += $(patsubst %.cpp, %.$(obj-suffix).d, $(spparks_cppsrcfiles)) \
                       $(patsubst %.c, %.$(obj-suffix).d, $(spparks_csrcfiles))
