###########################################################################
## Makefile generated for component 'calculate_qtfisher'. 
## 
## Makefile     : calculate_qtfisher_rtw.mk
## Generated on : Fri Nov 15 21:35:42 2024
## Final product: ./calculate_qtfisher.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = calculate_qtfisher
MAKEFILE                  = calculate_qtfisher_rtw.mk
MATLAB_ROOT               = C:/pz/MATLAB
MATLAB_BIN                = C:/pz/MATLAB/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/pz/ƽ̨����_11.4/ƽ̨����_11.15
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = calculate_qtfisher_rtw_comp.rsp
CMD_FILE                  = calculate_qtfisher_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = calculate_qtfisher.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./calculate_qtfisher.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=calculate_qtfisher

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_data.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/rt_nonfinite.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/rtGetNaN.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/rtGetInf.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_initialize.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_terminate.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtsquare.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/metrosquare.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/rand.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/my_error_square.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/find.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/prediction_my_error.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/prediction_POS.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/probability_PIMC.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/run_main.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/minOrMax.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/eml_rand_mt19937ar_stateful.cpp $(START_DIR)/codegen/lib/calculate_qtfisher/eml_rand_mt19937ar.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = calculate_qtfisher_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj calculate_qtfisher_initialize.obj calculate_qtfisher_terminate.obj calculate_qtfisher.obj calculate_qtsquare.obj metrosquare.obj rand.obj my_error_square.obj find.obj prediction_my_error.obj prediction_POS.obj probability_PIMC.obj run_main.obj minOrMax.obj eml_rand_mt19937ar_stateful.obj eml_rand_mt19937ar.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calculate_qtfisher_data.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calculate_qtfisher_initialize.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calculate_qtfisher_terminate.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calculate_qtfisher.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtfisher.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calculate_qtsquare.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/calculate_qtsquare.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


metrosquare.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/metrosquare.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rand.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/rand.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_error_square.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/my_error_square.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


prediction_my_error.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/prediction_my_error.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


prediction_POS.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/prediction_POS.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


probability_PIMC.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/probability_PIMC.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


run_main.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/run_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_rand_mt19937ar_stateful.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/eml_rand_mt19937ar_stateful.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_rand_mt19937ar.obj : $(START_DIR)/codegen/lib/calculate_qtfisher/eml_rand_mt19937ar.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


