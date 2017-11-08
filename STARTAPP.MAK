#===================================================================
#
#   StartApp Make file
#
#   (c) Copyright IBM Corp. 1991, 1998  All rights reserved.
#
#   These sample programs are owned by International Business Machines
#   Corporation or one of its subsidiaries ("IBM") and are copyrighted and
#   licensed, not sold.
#
#   You may copy, modify, and distribute these sample programs in any
#   form without payment to IBM, for any purpose including developing,
#   using, marketing or distributing programs that include or are
#   derivative works of the sample programs.
#
#   The sample programs are provided to you on an "AS IS" basis, without
#   warranty of any kind.  IBM HEREBY EXPRESSLY DISCLAIMS ALL WARRANTIES,
#   EITHER EXPRESS OR IMPLIED, INCLUDING , BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#   Some jurisdictions do not allow for the exclusion or limitation of
#   implied warranties, so the above limitations or exclusions may not
#   apply to you.  IBM shall not be liable for any damages you suffer
#   as a result of using, modifying or distributing the sample programs
#   or their derivatives.
#
#
#===================================================================

include startapp.inc

HEADERS = main.h xtrn.h

LIBS    = CPPON30 + os2386
#-------------------------------------------------------------------
#   A list of all of the object files
#-------------------------------------------------------------------
ALL_OBJ1 = main.obj user.obj init.obj pnt.obj dlg.obj help.obj
ALL_OBJ2 = sapp.obj

#-------------------------------------------------------------------
#   A list of all of the Help text files
#-------------------------------------------------------------------
ALL_IPF = startapp.ipf help.ipf
#-------------------------------------------------------------------
#   This section lists all files to be built by the make.  The
#   makefile builds the executible as well as its associated help
#   file.
#-------------------------------------------------------------------
all: startapp.exe startapp.hlp


#-------------------------------------------------------------------
#   This section creates the command file used by the linker.  This
#   command file is recreated automatically every time you change
#   the object file list, linker flags, or library list.
#-------------------------------------------------------------------
startapp.lnk: startapp.mak
    echo $(ALL_OBJ1) +           > startapp.lnk
    echo $(ALL_OBJ2)            >> startapp.lnk
    echo startapp.exe           >> startapp.lnk
    echo startapp.map           >> startapp.lnk
    echo $(LIBS)                >> startapp.lnk
    echo startapp.def           >> startapp.lnk



#===================================================================
#
# Dependencies
#
#   This section lists all object files needed to be built for the
#   application, along with the files it is dependent upon (e.g. its
#   source and any header files).
#
#===================================================================
main.res: main.rc main.ico main.h dlg.h startapp.dlg help.rc help.h
    $(RC) -r main.rc main.res

main.obj: main.c $(HEADERS)

user.obj: user.c $(HEADERS)

init.obj: init.c $(HEADERS)

pnt.obj: pnt.c $(HEADERS)

dlg.obj: dlg.c $(HEADERS)

help.obj: help.c $(HEADERS) help.h

#- thrd.obj: thrd.c $(HEADERS)

sapp.obj: sapp.c $(HEADERS)

#-------------------------------------------------------------------
#   This section creates the help manager file.  The IPF compiler
#   creates a file called main.hlp which is renamed to startapp.hlp.
#-------------------------------------------------------------------
startapp.hlp: $(ALL_IPF)

#-------------------------------------------------------------------
#   This section links the object modules into the finished program
#   using the linker command file created earlier.  At the end, the
#   resource file is bound to the application.
#-------------------------------------------------------------------
startapp.exe: $(ALL_OBJ1) $(ALL_OBJ2) startapp.def startapp.lnk main.res
    $(LINK) @startapp.lnk
    rc -p -x main.res startapp.exe
