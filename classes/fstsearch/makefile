## dLabPro class CFstsearch (fstsearch)
## - Makefile
##
## AUTHOR : frank.duckhorn
## PACKAGE: dLabPro/classes
##
## This file was generated by dcg. DO NOT MODIFY! Modify fstsearch.def instead.
## 
## Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
## - Chair of System Theory and Speech Technology, TU Dresden
## - Chair of Communications Engineering, BTU Cottbus
## 
## This file is part of dLabPro.
## 
## dLabPro is free software: you can redistribute it and/or modify it under the
## terms of the GNU Lesser General Public License as published by the Free
## Software Foundation, either version 3 of the License, or (at your option)
## any later version.
## 
## dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
## WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
## FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
## details.
## 
## You should have received a copy of the GNU Lesser General Public License
## along with dLabPro. If not, see <http://www.gnu.org/licenses/>.

## Common settings
ifdef (${CGENPATH})
  CGEN = ${CGENPATH}/dcg
else
  CGEN = dcg
endif

vpath %.h ../../include ../../include/automatic
INCL = -I ../../include -I ../../include/automatic 

## Compiler specific settings
ifeq (${DLABPRO_USE_MSVC},1)
  ## - MSVC
  CC       = CL
  CFLAGS   = -nologo -Od -Gm -EHsc -RTC1 -Wp64 -ZI -TP -D_DEBUG -D_DLP_CPP  ${DLABPRO_MSVC_FLAGS_DEBUG}
  CCoO     = -Fo
  AR       = LIB
  ARFLAGS  = -nologo
  ARoO     = -OUT:
  OEXT     = obj
  LEXT     = lib
  TOOLBOX  = MSVC
else
  ifeq (${DLABPRO_USE_MSVC},2)
    ## - MSVC 6.0 - 32-Bit C/C++-Compiler for x86
    CC       = CL
    CFLAGS   = -nologo -Od -Gm -EHsc -RTC1 -ZI -TP -D_DEBUG -D_DLP_CPP  ${DLABPRO_MSVC_FLAGS_DEBUG}
    CCoO     = -Fo
    AR       = LIB
    ARFLAGS  = -nologo
    ARoO     = -OUT:
    OEXT     = obj
    LEXT     = lib
    TOOLBOX  = MSVC6
  else
    ## - GCC
    CC       = gcc
    CFLAGS   = -g -D_DEBUG -Wall -ansi -x c++ -D_DLP_CPP  ${DLABPRO_GCC_CFLAGS_DEBUG}
    CCoO     = -o
    AR       = ar
    ARFLAGS  = rvs
    ARoO     =
    OEXT     = o
    LEXT     = a
    TOOLBOX  = GCC
  endif
endif

## Configuration - DEBUG_CPP (default)
OBJ_PATH = ../../obj.debug.${MACHINE}
LIB_PATH = ../../lib.debug.${MACHINE}

ifeq ($(MAKECMDGOALS),)
  MAKECMDGOALS = DEBUG_CPP
endif

## Configuration - DEBUG_C
ifeq ($(MAKECMDGOALS),DEBUG_C)
  OBJ_PATH = ../../obj.debug.${MACHINE}
  LIB_PATH = ../../lib.debug.${MACHINE}
  ifeq (${DLABPRO_USE_MSVC},1)
    CFLAGS = -nologo -Od -Gm -EHsc -RTC1 -Wp64 -ZI -TC -D_DEBUG -D_DLP_C -D_DLP_C  ${DLABPRO_MSVC_FLAGS_DEBUG}
  else
    ifeq (${DLABPRO_USE_MSVC},2)
      ## - MSVC 6.0 - 32-Bit C/C++-Compiler for x86
      CFLAGS = -nologo -Od -Gm -EHsc -RTC1 -ZI -TC -D_DEBUG -D_DLP_C -D_DLP_C  ${DLABPRO_MSVC_FLAGS_DEBUG}
    else
      CFLAGS = -g -D_DEBUG -Wall -ansi -x c -D_DLP_C  ${DLABPRO_GCC_CFLAGS_DEBUG}
    endif
  endif
endif

## Configuration - RELEASE_CPP
ifeq ($(MAKECMDGOALS),RELEASE_CPP)
  OBJ_PATH = ../../obj.release.${MACHINE}
  LIB_PATH = ../../lib.release.${MACHINE}
  ifeq (${DLABPRO_USE_MSVC},1)
    CFLAGS  = -nologo -O2 -GL -D_RELEASE -EHsc -W3 -Wp64 -TP -D_CRT_SECURE_NO_WARNINGS -D_DLP_CPP  ${DLABPRO_MSVC_FLAGS_RELEASE}
    ARFLAGS = -nologo -LTCG
  else
    ifeq (${DLABPRO_USE_MSVC},2)
      ## - MSVC 6.0 - 32-Bit C/C++-Compiler for x86
      CFLAGS  = -nologo -O2 -D_RELEASE -EHsc -W3 -TP -D_CRT_SECURE_NO_WARNINGS -D_DLP_CPP  ${DLABPRO_MSVC_FLAGS_RELEASE}
    else
      CFLAGS  = -O2 -D_RELEASE -Wall -ansi -x c++ -D_DLP_CPP  ${DLABPRO_GCC_CFLAGS_RELEASE}
    endif
  endif
endif

## Configuration - RELEASE_C
ifeq ($(MAKECMDGOALS),RELEASE_C)
  OBJ_PATH = ../../obj.release.${MACHINE}
  LIB_PATH = ../../lib.release.${MACHINE}
  ifeq (${DLABPRO_USE_MSVC},1)
    CFLAGS  = -nologo -O2 -GL -D_RELEASE -EHsc -W3 -Wp64 -TC -D_CRT_SECURE_NO_WARNINGS -D_DLP_C  ${DLABPRO_MSVC_FLAGS_RELEASE}
    ARFLAGS = -nologo -LTCG
  else
    ifeq (${DLABPRO_USE_MSVC},2)
      ## - MSVC 6.0 - 32-Bit C/C++-Compiler for x86
      CFLAGS  = -nologo -O2 -D_RELEASE -EHsc -W3 -TC -D_CRT_SECURE_NO_WARNINGS -D_DLP_C  ${DLABPRO_MSVC_FLAGS_RELEASE}
    else
      CFLAGS  = -O2 -D_RELEASE -Wall -ansi -x c -D_DLP_C  ${DLABPRO_GCC_CFLAGS_RELEASE}
    endif
  endif
endif

## Configuration - clean_release
ifeq ($(MAKECMDGOALS),clean_release)
  OBJ_PATH = ../../obj.release.${MACHINE}
  LIB_PATH = ../../lib.release.${MACHINE}
endif

## Target settings
MANFILE        = ../../manual/automatic/fstsearch.html
LIBRARY        = $(LIB_PATH)/fstsearch.$(LEXT)
SHARED_LIBRARY = libfstsearch.so
OBJECTS        = $(OBJ_PATH)/fstsearch.$(OEXT) \
                  $(OBJ_PATH)/fsts_glob.$(OEXT) \
                  $(OBJ_PATH)/fsts_cfg.$(OEXT) \
                  $(OBJ_PATH)/fsts_fst.$(OEXT) \
                  $(OBJ_PATH)/fsts_mem.$(OEXT) \
                  $(OBJ_PATH)/fsts_w.$(OEXT) \
                  $(OBJ_PATH)/fsts_bt.$(OEXT) \
                  $(OBJ_PATH)/fsts_lat.$(OEXT) \
                  $(OBJ_PATH)/fsts_h.$(OEXT) \
                  $(OBJ_PATH)/fsts_as.$(OEXT) \
                  $(OBJ_PATH)/fsts_as_ls.$(OEXT) \
                  $(OBJ_PATH)/fsts_as_q.$(OEXT) \
                  $(OBJ_PATH)/fsts_as_s.$(OEXT) \
                  $(OBJ_PATH)/fsts_sdp.$(OEXT) \
                  $(OBJ_PATH)/fsts_sdp_imp.$(OEXT) \
                  $(OBJ_PATH)/fsts_tp.$(OEXT) \
                  $(OBJ_PATH)/fsts_tp_s.$(OEXT) \
                  $(OBJ_PATH)/fsts_tp_hist.$(OEXT) \
                  $(OBJ_PATH)/fsts_tp_ls.$(OEXT)
CDEPS          = 
DEPS           = fstsearch.def

## Rules 
DEBUG_CPP  : ECHOCNF MKDIR $(LIBRARY)
DEBUG_C    : ECHOCNF MKDIR $(LIBRARY)
RELEASE_CPP: ECHOCNF MKDIR $(LIBRARY)
RELEASE_C  : ECHOCNF MKDIR $(LIBRARY)
SHARED     : ECHOCNF MKDIR $(SHARED_LIBRARY) LDCONF

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $(ARoO)$(LIBRARY) $(OBJECTS)

$(SHARED_LIBRARY): $(OBJECTS)
	$(CC) -shared -Wl,-soname,$(SHARED_LIBRARY).0 $(OBJECTS) \
          -o $(LIB_PATH)/$(SHARED_LIBRARY).0.0

$(OBJ_PATH)/fstsearch.$(OEXT): fstsearch.c dlp_fstsearch.h dlp_object.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fstsearch.$(OEXT) fstsearch.c

dlp_fstsearch.h: $(DEPS) $(CDEPS)
	@-$(CGEN) fstsearch.def

fstsearch.c: $(DEPS) $(CDEPS)
	@-$(CGEN) fstsearch.def

##{{CGEN_COMPILE
$(OBJ_PATH)/fsts_glob.$(OEXT): fsts_glob.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_glob.$(OEXT) fsts_glob.c

$(OBJ_PATH)/fsts_cfg.$(OEXT): fsts_cfg.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_cfg.$(OEXT) fsts_cfg.c

$(OBJ_PATH)/fsts_fst.$(OEXT): fsts_fst.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_fst.$(OEXT) fsts_fst.c

$(OBJ_PATH)/fsts_mem.$(OEXT): fsts_mem.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_mem.$(OEXT) fsts_mem.c

$(OBJ_PATH)/fsts_w.$(OEXT): fsts_w.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_w.$(OEXT) fsts_w.c

$(OBJ_PATH)/fsts_bt.$(OEXT): fsts_bt.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_bt.$(OEXT) fsts_bt.c

$(OBJ_PATH)/fsts_lat.$(OEXT): fsts_lat.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_lat.$(OEXT) fsts_lat.c

$(OBJ_PATH)/fsts_h.$(OEXT): fsts_h.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_h.$(OEXT) fsts_h.c

$(OBJ_PATH)/fsts_as.$(OEXT): fsts_as.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_as.$(OEXT) fsts_as.c

$(OBJ_PATH)/fsts_as_ls.$(OEXT): fsts_as_ls.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_as_ls.$(OEXT) fsts_as_ls.c

$(OBJ_PATH)/fsts_as_q.$(OEXT): fsts_as_q.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_as_q.$(OEXT) fsts_as_q.c

$(OBJ_PATH)/fsts_as_s.$(OEXT): fsts_as_s.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_as_s.$(OEXT) fsts_as_s.c

$(OBJ_PATH)/fsts_sdp.$(OEXT): fsts_sdp.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_sdp.$(OEXT) fsts_sdp.c

$(OBJ_PATH)/fsts_sdp_imp.$(OEXT): fsts_sdp_imp.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_sdp_imp.$(OEXT) fsts_sdp_imp.c

$(OBJ_PATH)/fsts_tp.$(OEXT): fsts_tp.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_tp.$(OEXT) fsts_tp.c

$(OBJ_PATH)/fsts_tp_s.$(OEXT): fsts_tp_s.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_tp_s.$(OEXT) fsts_tp_s.c

$(OBJ_PATH)/fsts_tp_hist.$(OEXT): fsts_tp_hist.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_tp_hist.$(OEXT) fsts_tp_hist.c

$(OBJ_PATH)/fsts_tp_ls.$(OEXT): fsts_tp_ls.c dlp_fstsearch.h
	$(CC) -c $(CFLAGS) $(INCL) $(CCoO)$(OBJ_PATH)/fsts_tp_ls.$(OEXT) fsts_tp_ls.c

##}}CGEN_COMPILE

## Additional rules
.PHONY: ECHOCNF MKDIR LDCONF clean clean_debug clean_release

# Echo current configuration
ECHOCNF:
	@echo
	@echo '// ----- Make ($(TOOLBOX)): dLabPro class CFstsearch (fstsearch) -- $(MAKECMDGOALS) -----'

# Create target directory
MKDIR:
	@-test -w $(OBJ_PATH) || mkdir $(OBJ_PATH)
	@-test -w $(LIB_PATH) || mkdir $(LIB_PATH)

# Create links to shared lib
LDCONF:
	@-cd $(LIB_PATH) && ln -sf $(SHARED_LIBRARY).0.0 $(SHARED_LIBRARY).0 \
          && ln -sf $(SHARED_LIBRARY).0 $(SHARED_LIBRARY)

clean:  clean_debug

clean_debug:
	@echo '// ----- Make ($(TOOLBOX)): dLabPro class CFstsearch (fstsearch) -- cleaning DEBUG -----'
	-rm -f $(OBJECTS) $(LIBRARY)
	-rm -f vc80.?db
	-touch -c -r fstsearch.def -d yesterday fstsearch.c

clean_release:
	@echo '// ----- Make ($(TOOLBOX)): dLabPro class CFstsearch (fstsearch) -- cleaning RELEASE -----'
	-rm -f $(OBJECTS) $(LIBRARY)
	-rm -f vc80.?db
	-touch -c -r fstsearch.def -d yesterday fstsearch.c

## EOF 
