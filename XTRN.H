/**************************************************************************
 *  File name  :  xtrn.h
 *
 *  Description:  This header file contains the application-wide function
 *                declarations and global external variables.
 *
 *  Concepts   :  global definition
 *
 *  API's      :  [none]
 *
 *  Required
 *    Files    :  [none]
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
 *  Global variables
 */
extern HWND hwndMainFrame;
extern HWND hwndMain;
extern HWND hwndList;
extern HAB hab;
extern HMQ hmq;
extern HDC hdcMain;
extern CHAR szAppName[];
extern CHAR szUntitled[];
extern BOOL fPrintEnabled;
extern BOOL fHelpEnabled;
extern BOOL fStarted;

/*
 *  Entry point declarations
 */

/* from main.c */
int              main(VOID);
MRESULT EXPENTRY MainWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
ULONG            MessageBox(HWND hwndOwner, ULONG idMsg, ULONG fsStyle, BOOL fBeep);
VOID             MainCommand(MPARAM mp1, MPARAM mp2);

/* from init.c */
BOOL             Init(VOID);
MRESULT          InitMainWindow(HWND hwnd, MPARAM mp1, MPARAM mp2);
VOID             ExitProc(USHORT usTermCode);


/* from sapp.c */
VOID             StrApp(MPARAM mp2);
VOID             StopApp(MPARAM mp2);

/* from user.c */
VOID             UserCommand(MPARAM mp1, MPARAM mp2);
MRESULT          UserWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
VOID             InitMenu(MPARAM mp1, MPARAM mp2);
VOID             EnableMenuItem(HWND hwndMenu, USHORT idItem, BOOL fEnable);

/* from pnt.c */
VOID             MainPaint(HWND hwnd);

/* from help.c */
VOID             InitHelp(VOID);
VOID             HelpIndex(VOID);
VOID             HelpGeneral(VOID);
VOID             HelpUsingHelp(VOID);
VOID             HelpKeys(VOID);
VOID             HelpTutorial(VOID);
VOID             HelpProductInfo(VOID);
VOID             DisplayHelpPanel(ULONG idPanel);
VOID             DestroyHelpInstance(VOID);

/***************************  End of xtrn.h  ****************************/
