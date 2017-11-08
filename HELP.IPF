.*==============================================================*\
.*                                                              *
.* Help.ipf - Information Tag Language file for the Help menu   *
.*              help panels.                                    *
.*  Copyright 1991,1998 IBM Corporation                         *
.*                                                              *
.*==============================================================*/

.*--------------------------------------------------------------*\
.*  Main Help menu                                              *
.*      res = PANEL_HELP                                        *
.*--------------------------------------------------------------*/
:h1 res=2910 name=PANEL_HELP.Help Menu
:i1 id=Help.Help Menu
:p.Insert standard Help menu text here.

.*--------------------------------------------------------------*\
.*  Help menu Help Index command help panel                     *
.*      res = PANEL_HELPINDEX                                   *
.*--------------------------------------------------------------*/
:h1 res=2920 name=PANEL_HELPINDEX.Index
:i2 refid=Help.Index
:p.No help index currently exists.

.*--------------------------------------------------------------*\
.*  Help menu General help help panel                           *
.*      res = PANEL_HELPGENERAL                                 *
.*--------------------------------------------------------------*/
:h1 res=2930 name=PANEL_HELPGENERAL.General help
:i2 refid=Help.General
:p.This is a sample application used to demonstrate the ability
to start a WINOS2 session from a PM application using the
WinStartApp PM API.
:note.This screen will usually be handled by the default.

.*--------------------------------------------------------------*\
.*  Help menu Using help help panel                             *
.*      res = PANEL_HELPUSINGHELP                               *
.*--------------------------------------------------------------*/
:h1 res=2940 name=PANEL_HELPUSINGHELP.Using Help
:i2 refid=Help.Using
:p.This sample uses the standard IPF dialog facilities for
help resources.

.*--------------------------------------------------------------*\
.*  Help menu Keys Help help panel                              *
.*      res = PANEL_HELPKEYS                                    *
.*--------------------------------------------------------------*/
:h1 res=2950 name=PANEL_HELPKEYS.Keys
:i2 refid=Help.Keys
:p.Only one accelerator key has been defined in the sample
application.  It is the ALT-DELETE key which will terminate
the started application/session.  It is equivalent to selecting
the Terminate submenu item from the Control menu item

.*--------------------------------------------------------------*\
.*  Help menu Tutorial help panel                               *
.*      res = PANEL_HELPTUTORIAL                                *
.*--------------------------------------------------------------*/
:h1 res=2960 name=PANEL_HELPTUTORIAL.Tutorial
:i2 refid=Help.Tutorial
:p.No tutorial is available with this sample application.

.*--------------------------------------------------------------*\
.*  Help menu Product information help panel                    *
.*      res = PANEL_HELPPRODUCTINFO                             *
.*--------------------------------------------------------------*/
:h1 res=2970 name=PANEL_HELPPRODUCTINFO.Product information
:i2 refid=Help.Product information
:p.Place information for the Product information menu item here.

