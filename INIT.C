/**************************************************************************
 *  File name  :  init.c
 *
 *  Description:  This module contains the code for application
 *                initialization, as well as the code for exit list
 *                processing
 *
 *                This source file contains the following functions:
 *
 *                Init()
 *                InitMainWindow(hwnd, mp1, mp2)
 *                ExitProc(usTermCode)
 *
 *  Concepts   :  initialization
 *
 *  API's      :  DosExitList
 *                DosExit
 *                WinLoadString
 *                WinRegisterClass
 *                WinIsWindow
 *                WinDestroyWindow
 *                WinDestroyMsgQueue
 *                WinTerminate
 *
 *  Required
 *    Files    :  OS2.H, STRING.H, MAIN.H, XTRN.H
 *
 *  (c) Copyright IBM Corp. 1991, 1998  All rights reserved.
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

#define  INCL_WINWINDOWMGR
#define  INCL_WIN /* Or use INCL_WIN, INCL_PM, Also in COMMON section */
#define  INCL_WINLISTBOXES
#define  INCL_DOSPROCESS

#include <os2.h>
#include <string.h>
#include "main.h"
#include "xtrn.h"

/*
 *  Global variables
 */


/*
 *  Entry point declarations
 */

/**************************************************************************
 *
 *  Name       : Init()
 *
 *  Description:  Performs initialization functions required
 *                before the main window can be created.
 *
 *  Concepts:     Called once before the main window is created.
 *
 *                - Installs the routine ExitProc into the
 *                  DosExitList chain
 *                - registers all window classes
 *                - performs any command line processing
 *
 *  API's      :  DosExitList
 *                DosExit
 *                WinLoadString
 *                WinRegisterClass
 *
 *  Parameters :  [none]
 *
 *  Return     :  TRUE = initialization is successful
 *                FALSE = initialization failed
 *
 *************************************************************************/
BOOL Init(VOID)
{

   /* Add ExitProc to the exit list to handle the exit processing.  If
    * there is an error, then terminate the process since there have
    * not been any resources allocated yet.
    */
   if(DosExitList(EXLST_ADD, (PFNEXITLIST)ExitProc))
   {
      MessageBox(HWND_DESKTOP,
                 IDMSG_CANNOTLOADEXITLIST,
                 MB_OK | MB_ERROR,
                 TRUE);
      DosExit(EXIT_PROCESS, RETURN_ERROR);
   }

   /* load application name from resource file */
   if(!WinLoadString(hab, (HMODULE)0, IDS_APPNAME, MAXNAMEL, szAppName))
      return FALSE;

   /* register the main client window class */
   if(!WinRegisterClass(hab,
                       (PSZ)szAppName,
                       (PFNWP)MainWndProc,
                       CS_SIZEREDRAW | CS_CLIPCHILDREN,
                       0L))
       return FALSE;

    /*
     *      Add any command line processing here.
     */


   return TRUE;
}  /* End of Init   */

/**************************************************************************
 *
 *  Name       : InitMainWindow(hwnd, mp1, mp2)
 *
 *  Description: Performs initialization functions required
 *               when the main window is created.
 *
 *  Concepts:    Called once during the WM_CREATE processing when
 *               the main window is created.
 *
 *  API's      : [none]
 *
 *  Parameters :  hwnd = window handle
 *                mp1  = first message parameter
 *                mp2  = second message parameter
 *
 *  Return     :  value to be returned from the WM_CREATE message:
 *                TRUE =  window creation should stop
 *                FALSE = window creation should continue
 *
 *************************************************************************/
MRESULT InitMainWindow(HWND hwnd, MPARAM mp1, MPARAM mp2)
{

/**
    Reserved for potential future enhancements
**/
   return (MRESULT)FALSE;

   /* This routine currently doesn't use the hwnd, mp1, and mp2 parameters
    *  so they are referenced here to prevent an 'Unreferenced Parameter'
    *  warning at compile time.
    */

   hwnd;
   mp1;
   mp2;
}   /* End of InitMainWindow   */
/**************************************************************************
 *
 *  Name       : ExitProc(usTermCode)
 *
 *  Description: Cleans up certain resources when the application
 *               terminates.
 *
 *  Concepts:    Routine is called by DosExitList when the
 *               application exits.
 *
 *               Global resources, such as the main window and
 *               message queue, are destroyed and any system
 *               resources used are freed.
 *
 *  API's      : WinIsWindow
 *               WinDestroyWindow
 *               WinDestroyMsgQueue
 *               WinTerminate
 *               DosExitList
 *
 *  Parameters :  usTermCode = termination code number
 *
 *  Return    :   Returns EXLST_EXIT to the DosExitList handler
 *
 *************************************************************************/
VOID ExitProc(USHORT usTermCode)
{
    /* destroy the main window if it exists */
   if(WinIsWindow(hab, hwndMainFrame))
      WinDestroyWindow(hwndMainFrame);

   WinDestroyMsgQueue(hmq);

   WinTerminate(hab);

   DosExitList(EXLST_EXIT, (PFNEXITLIST)NULL);    /* termination complete */

    /* This routine currently doesn't use the usTermCode parameter so
     *  it is referenced here to prevent an 'Unreferenced Parameter'
     *  warning at compile time
     */

   usTermCode;
}   /* End of ExitProc    */
/***************************  End of init.c  ***************************/
