/**************************************************************************
 *  File name  :  dlg.c
 *
 *  Description:  This module contains the Dialog Procedures for the user
 *                defined dialogs as well as any support code they need.
 *
 *                This source file contains the following functions:
 *
 *                ProductInfoDlgProc(hwnd, msg, mp1, mp2)
 *                SetSysMenu(hDlg)
 *
 *  Concepts   :  dialog box
 *
 *  API's      :  WinDismissDlg
 *                WinDefDlgProc
 *                WinWindowFromID
 *                WinSendMsg
 *
 *  Required
 *    Files    :  OS2.H, STRING.H, MAIN.H, DLG.H, XTRN.H
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

#define  INCL_WINMENUS
#define  INCL_WINFRAMEMGR
#include <os2.h>
#include <string.h>
#include "main.h"
#include "dlg.h"
#include "xtrn.h"

/*
 *  Global variables
 */

/*
 *  Entry point declarations
 */

MRESULT EXPENTRY ProductInfoDlgProc(HWND hwnd, USHORT msg,
                                  MPARAM mp1, MPARAM mp2);
VOID SetSysMenu( HWND hDlg );

/**************************************************************************
 *
 *  Name       : ProductInfoDlgProc(hwnd, msg, mp1, mp2)
 *
 *  Description: Processes all messages sent to the Product information
 *               dialog
 *
 *  Concepts:  The Product information dialog has only a button control,
 *             so this routine processes only WM_COMMAND messages.  Any
 *             WM_COMMAND posted must have come from the OK
 *             button, so we dismiss the dialog upon receiving it.
 *
 *  API's      :  WinDismissDlg
 *                WinDefDlgProc
 *
 *  Parameters :  hwnd     = window handle
 *                msg      = message i.d.
 *                mp1      = first message parameter
 *                mp2      = second message parameter
 *
 *  Return     :  dependent on message sent
 *
 *  Comments   :  This dialog is the Code Information submenu item
 *                from the Help menu bar item
 *************************************************************************/
MRESULT EXPENTRY ProductInfoDlgProc(
                         HWND hwnd,      /* handle of window */
                         USHORT msg,     /* id of message */
                         MPARAM mp1,     /* first message parameter */
                         MPARAM mp2)     /* second message parameter */
{
   switch(msg)
   {
      case WM_INITDLG:
         SetSysMenu(hwnd);       /* system menu for this dialog  */
         return MRFROMSHORT(FALSE);

      case WM_COMMAND:
           /* no matter what the command, close the dialog */
         WinDismissDlg(hwnd, TRUE);
         break;

      default:
         return(WinDefDlgProc(hwnd, msg, mp1, mp2));
         break;
   }
   return (MRESULT)NULL;
}   /*  End of ProductInfoDlgProc   */


/**************************************************************************
 *
 *  Name       : SetSysMenu(hDlg)
 *
 *  Description: Sets only the Move and Close items of the system menu
 *
 *  Concepts:  Any dialog box is free to call this routine, to edit
 *             which menu items will appear on its System Menu pulldown.
 *
 *  API's      :  WinWindowFromID
 *                WinSendMsg
 *
 *  Parameters :  hDlg     = window handle of the dialog
 *
 *  Return     :  [none]
 *
 *  Comments   :  In this sample, this procedure gets invoked when
 *                the "Code Information" menu item is selected off of
 *                the HELP Menu Bar.  It modifies the system menu by
 *                eliminating one or more items from the system menu.
 *
 *************************************************************************/

VOID SetSysMenu(HWND hDlg)
{
    HWND     hSysMenu;
    MENUITEM Mi;
    ULONG    Pos;
    MRESULT  Id;
    SHORT    cItems;

    /******************************************************************/
    /*  We only want Move and Close in the system menu.               */
    /******************************************************************/

    /*  Obtain the handle of the system menu within the dialog        */
    hSysMenu = WinWindowFromID(hDlg, FID_SYSMENU);

    /*  Build a list of submenu items from the system menu            */
    /*  A pointer will be established to Mi.hwndSubMenu               */
    WinSendMsg( hSysMenu, MM_QUERYITEM,
                MPFROM2SHORT(SC_SYSMENU, FALSE), MPFROMP((PCH) & Mi));
    Pos = 0L;   /* Initialize the menu item position to the top       */
    /*  Obtain a count of items in the menu                           */
    cItems = (SHORT)WinSendMsg( Mi.hwndSubMenu, MM_QUERYITEMCOUNT,
                                (MPARAM)NULL, (MPARAM)NULL);
    while (cItems--)  /* loop through the list items */
    {   /* Using the current position in the list, obtain its menu id */
        Id = WinSendMsg( Mi.hwndSubMenu, MM_ITEMIDFROMPOSITION,
                         MPFROMLONG(Pos), (MPARAM)NULL);

        /* We want to delete all submenu items except Move and Close  */
        /* The following case statement will pass these items and by  */
        /* default delete the rest.  Note, normally we would use      */
        /* MM_REMOVEITEM rather than MM_DELETEITEM so that we could   */
        /* add the menu item back later.  The MM_DELETEITEM prevents  */
        /* us from doing this without recreating the dialog.          */
        switch (SHORT1FROMMR(Id))
        {
        case SC_MOVE:
            Pos++;  /* Don't delete that one. */
            break;
        case SC_CLOSE:
            Pos++;  /* Don't delete that one. */
            break;
        default:
            WinSendMsg( Mi.hwndSubMenu, MM_DELETEITEM,
                        MPFROM2SHORT((USHORT)Id, TRUE), (MPARAM)NULL);
        }
    }
}   /*  End of SetSysMenu  */
/***************************  End of dlg.c  ****************************/
