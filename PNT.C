/**************************************************************************
 *  File name  :  pnt.c
 *
 *  Description:  This module contains the code for the main client
 *                window painting.
 *
 *                This source file contains the following functions:
 *
 *                MainPaint(hwnd)
 *
 *  Concepts   :  window painting
 *
 *  API's      :  WinBeginPaint
 *                WinFillRect
 *                WinEndPaint
 *
 *  Required
 *    Files    :  OS2.H, MAIN.H, XTRN.H
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

#define  INCL_WINSYS

#include <os2.h>
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
 *  Name       : MainPaint(hwnd)
 *
 *  Description: Paints the main client window.
 *
 *  Concepts:  Routine is called whenever the client window
 *             procedure receives a WM_PAINT message
 *
 *             - begins painting by calling WinBeginPaint
 *                 and retrieving the HPS for the window
 *             - performs any painting desired
 *             - ends painting by calling WinEndPaint
 *
 *  API's      :  WinBeginPaint
 *                WinFillRect
 *                WinEndPaint
 *
 *  Parameters :  hwnd     = window handle
 *
 *  Return     :  [none]
 *
 *************************************************************************/
VOID MainPaint(HWND hwnd)
{
   RECTL rclUpdate;
   RECTL rcl;
   HPS hps;
/* Query new size and position of frame window */
   WinQueryWindowRect(hwnd, &rcl);
/* Reset position and size of List Box child   */
   WinSetWindowPos(hwndList,
      HWND_TOP,
      rcl.xLeft +3 ,
      rcl.yBottom +4 ,
      rcl.xRight +2 ,
      rcl.yTop +3 ,
      SWP_MOVE | SWP_SIZE);
/* Repaint */
   hps = WinBeginPaint(hwnd, NULLHANDLE, &rclUpdate);

   WinEndPaint(hps);
}   /* End of MainPaint   */
/***************************  End of pnt.c  ****************************/
