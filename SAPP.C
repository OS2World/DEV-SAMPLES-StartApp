/**************************************************************************
 *  File name  :  sapp.c
 *
 *  Description:
 *
 *  Concepts   :  start applications from PM program
 *
 *  API's      :  WinStartApp
 *
 *  Required
 *    Files    :  OS2.H, MAIN.H, XTRN.H
 *
 *  (c) Copyright IBM Corp. 1998  All rights reserved.
 *
 *  These sample programs are owned by International Business Machines
 *  Corporation or one of its subsidiaries ("IBM") and are copyrighted and
 *  licensed, not sold.
 *
 *  You may copy, modify, and distribute these sample programs in any
 *  form without payment to IBM, for any purpose including developing,
 *  using, marketing or distributing programs that include or are
 *  derivative works of the sample programs.
 *
 *  The sample programs are provided to you on an "AS IS" basis, without
 *  warranty of any kind.  IBM HEREBY EXPRESSLY DISCLAIMS ALL WARRANTIES,
 *  EITHER EXPRESS OR IMPLIED, INCLUDING , BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *  Some jurisdictions do not allow for the exclusion or limitation of
 *  implied warranties, so the above limitations or exclusions may not
 *  apply to you.  IBM shall not be liable for any damages you suffer
 *  as a result of using, modifying or distributing the sample programs
 *  or their derivatives.
 *************************************************************************/
/*
 *  Include files, macros, defined constants, and externs
 */
#define INCL_DOSSESMGR
#define INCL_DOSPROCESS
#define INCL_PM
#define INCL_WIN
#include <os2.h>
#include "main.h"
#include "xtrn.h"
#include <stdio.h>
#include <string.h>

/*
 *  Global variables
 */
CHAR         szMsg[100];         /* Message                                  */
PROGDETAILS  pDetails;           /* Program Details Structure                */
HAPP         happ;               /* handle of the app/session started        */

/* CAUTION, a happ is returned for the VDM session instantiated. It may not
   be indicative of the application being started.  Thus, when terminating
   via WinTerminate(HAPP), this terminates the session and all applications
   within that session.  It is recommended to always start a PRIVATE VDM
   rather than a common/public VDM

   The following variables will be used to set up the environment and identify
   the application, its parameters and other specific settings we may want to
   initialize.

   It is important to understand that these settings can only be initialized
   for sessions that are started and not for those already started; for example,
   public sessions. If you are starting an application targeted for a common session,
   these settings will not take affect if a common session is currently running.

   The actual settings in the pszEnvironment variable must be separated by a "\0",
   and the last setting in the string must be terminated by "\0\0".

   For example, the following assignment to pszEnvironment will force the DOS_FILES
   setting to 40 and to load kernel modules above the 1MB memory address:

           pszEnvironment = "DOS_FILES=40\0DOS_HIGH=1\0";

   Note that the second "\0" at the end of the string is automatically added by the
   fact that the variable is defined as a string.

   Also note that the DOS_HIGH setting is set as "1" rather than "ON". This scheme
   is used for all DOS settings whose values are indicated as "ON/OFF" in the
   DOS and Win-OS/2 settings notebook pages -- ON = 1 and OFF = 0.
*/

ULONG     User_Progc            = PROG_31_STDSEAMLESSVDM;/* 15                */
ULONG     User_fbVisible        = SHE_VISIBLE;           /* show window       */
PSZ       User_pszTitle         = "MyApp";               /* For task list     */
PSZ       User_pszExecutable    = "NOTEPAD.EXE";         /* executable        */
PSZ       User_pszParameters    = "MyNewFil.txt";        /* command line parm */
         /* applicaton assumes that Warp is installed on the C drive/partition*/
PSZ       User_pszStartupDir    = "C:\\os2\\mdos\\winos2";
         /* do not specify icon for dos/winos2 applications                   */
PSZ       User_pszIcon          = NULL;
         /* we can set dos settings here                                      */
PSZ       User_pszEnvironment   = "DOS_FILES=40\0DOS_HIGH=1\0";
ULONG     User_swpInitial_fl    = SWP_ACTIVATE;
LONG      User_swpInitial_cx    = 0;                       /* width of window */
LONG      User_swpInitial_cy    = 0;                      /* height of window */
LONG      User_swpInitial_y     = 0;                  /* lower edge of window */
LONG      User_swpInitial_x     = 0;                   /* left edge of window */
HWND      User_swpInitial_hwndInsertBehind = HWND_TOP;
ULONG     User_swpInitial_ulReserved1      = 0;
ULONG     User_swpInitial_ulReserved2      = 0;

/**************************************************************************
 *
 *  Name       : StrApp(mp2)
 *
 *  Description: Processes selection of the Start App menu item of the
 *               Control pulldown
 *
 *  Concepts:  called whenever Start App from the Control menu is selected
 *
 *  API's      :  WinStartApp
 *
 *  Parameters :  mp2      = second message parameter
 *
 *  Return     :  [none]
 *
 *************************************************************************/
VOID StrApp(MPARAM mp2) {

ERRORID          errorCode;    /* holds WinGetLastError value            */

/* Initialize the program details structure */
  pDetails.Length          = sizeof(PROGDETAILS);
  pDetails.progt.progc     = User_Progc;
  pDetails.progt.fbVisible = User_fbVisible;
  pDetails.pszTitle        = User_pszTitle;
  pDetails.pszExecutable   = User_pszExecutable;
  pDetails.pszParameters   = User_pszParameters;
  pDetails.pszStartupDir   = User_pszStartupDir;
  pDetails.pszIcon         = User_pszIcon;
  pDetails.pszEnvironment  = User_pszEnvironment;
  pDetails.swpInitial.fl   = User_swpInitial_fl;
  pDetails.swpInitial.cy   = User_swpInitial_cy;
  pDetails.swpInitial.cx   = User_swpInitial_cx;
  pDetails.swpInitial.y    = User_swpInitial_y;
  pDetails.swpInitial.x    = User_swpInitial_x;
  pDetails.swpInitial.hwndInsertBehind = User_swpInitial_hwndInsertBehind;
  pDetails.swpInitial.hwnd             = hwndMain; /* Main window handle external variable */
  pDetails.swpInitial.ulReserved1      = User_swpInitial_ulReserved1;
  pDetails.swpInitial.ulReserved2      = User_swpInitial_ulReserved2;

/* Reset application last error code */
  errorCode = WinGetLastError (hwndMain);

  sprintf(szMsg,"Starting the Applicaton Via WinStartApp API");
  WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);

  sprintf(szMsg," Category: %u", User_Progc);
  WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);

  sprintf(szMsg," Executable: %s", User_pszExecutable);
  WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);

  sprintf(szMsg," Parameters: %s", User_pszParameters);
  WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);

  sprintf(szMsg," Startup Directory: %s", User_pszStartupDir);
  WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);

  happ = WinStartApp(hwndMain,&pDetails,"",NULL,SAF_INSTALLEDCMDLINE | SAF_STARTCHILDAPP);
  /* A successful return places the application's handle in happ.
     Otherwise happ is equal to zero */

  if(happ) {  /* SUCCESSFUL */
    sprintf (szMsg," -> Application handle (HAPP) is %u.", happ);
    WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);
    fStarted=TRUE;          /* Sets the started flag for menu controls */
    }
   else {     /* FAILURE */
    sprintf (szMsg," -> ERROR Application did not start successfully");
    WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);
    errorCode = WinGetLastError (hwndMain);
    sprintf (szMsg," - > WinGetLastError was %x.", errorCode);
    WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);
    }

return;
  mp2;   /* This is referenced to avoid unresolved variable warnings */
}   /* End of StrApp   */
/**************************************************************************
 *
 *  Name       : StopApp(mp2)
 *
 *  Description: Processes selection of the Terminate menu item of the
 *               Control pulldown
 *
 *  Concepts:  called whenever Terminate from the Control menu is selected
 *
 *  API's      :  WinTerminateApp
 *
 *  Parameters :  mp2      = second message parameter
 *
 *  Return     :  [none]
 *
 *************************************************************************/
VOID StopApp(MPARAM mp2) {

BOOL             Brc = FALSE;
ERRORID          errorCode;
   /* Reset PM last error */
   errorCode = WinGetLastError (hwndMain);
/*
 The application to be terminated must have been started using the
 WinStartApp function with the SAF_STARTCHILDAPP option specified.

 The WinTerminateApp function must be called from the same process as the
 WinStartApp function.
*/

   Brc = WinTerminateApp(happ);  /* now terminate */

   if(!Brc) {
    sprintf (szMsg," -> ERROR Application did not terminate");
    WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);
    errorCode = WinGetLastError (hwndMain);
    sprintf (szMsg," - > WinGetLastError was %x.", errorCode);
    WinSendMsg(hwndList, LM_INSERTITEM,
             MPFROMSHORT(LIT_END),
             szMsg);
    }
   else  {
           fStarted=FALSE;
         }
return;
}
/***************************  End of sapp.c  ****************************/

