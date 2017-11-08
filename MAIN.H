/**************************************************************************
 *  File name  :  main.h
 *
 *  Description:  This header file contains the application wide
 *                constants and structure definitions.
 *
 *  Concepts   :  [none]
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

#define IDR_MAIN       1      /* resource identifier */

/*
 *  Standard Dialog box ids
 */

#define MSGBOXID        1001
#define OBJECTID        1002

/*
 *  Menu item ids
 */
#define IDM_CTRL                            3000
#define IDM_STARTDATA                       3100
#define IDM_LASTPMERR                       3200

#define IDM_START                           4000
#define IDM_TERMIN8                         5000

#define IDM_HELP                            9000
#define IDM_HELPUSINGHELP                   9100
#define IDM_HELPGENERAL                     9200
#define IDM_HELPKEYS                        9300
#define IDM_HELPINDEX                       9400
#define IDM_HELPTUTORIAL                    9500
#define IDM_HELPPRODUCTINFO                 9600

/*
 *  Dialog item ids
 */
#define ID_OK               1
#define ID_CANCEL           2

/*  Other Controls                  */
#define WINDOW_LISTBOX                      1000
/*
 *  Stringtable ids
 */
#define IDS_FILEOPENEXT             1
#define IDS_APPNAME                 2
#define IDS_HELPLIBRARYNAME         3
#define IDS_OPEN                    4
#define IDS_HELPWINDOWTITLE         5
#define IDS_SAVE                    6
#define IDS_UNTITLED                7
#define IDS_TITLEBARSEPARATOR       8
#define IDS_OBJECTCLASS             9

/*
 *  Messagetable ids
 */
#define IDMSG_INITFAILED                1
#define IDMSG_MAINWINCREATEFAILED       2
#define IDMSG_CANNOTOPENINPUTFILE       3
#define IDMSG_CANNOTOPENOUTPUTFILE      4
#define IDMSG_CANNOTRUNCOLOR            8
#define IDMSG_CANNOTGETHPS              9
#define IDMSG_HELPLOADERROR            10
#define IDMSG_CANNOTLOADSTRING         11
#define IDMSG_CANNOTOPENPRINTER        12
#define IDMSG_HELPDISPLAYERROR         13
#define IDMSG_CANNOTLOADEXITLIST       14
#define IDMSG_PRINTINITFAILED          15
#define IDMSG_OVERWRITEFILE            16
#define IDMSG_PRINTERROR               17
#define IDMSG_UNDOFAILED               18
#define IDMSG_CANNOTGETFILEINFO        19
#define IDMSG_CANNOTALLOCATEMEMORY     20
#define IDMSG_CANNOTREADFILE           21
#define IDMSG_CANNOTWRITETOFILE        22
#define IDMSG_CANNOTLOADFONTS          23
#define IDMSG_CANNOTGETPAGEINFO        24
#define IDMSG_YOURTUTORIAL             25

/*
 *  Other constants
 */
#define MESSAGELEN          50    /* maximum length for messages */
#define TITLESEPARATORLEN   4
#define ID_ICON1            999

/* return values for initialization routines */
#define RETURN_SUCCESS      0   /* successful return in DosExit */
#define RETURN_ERROR        1   /* error return in DosExit */
#define BEEP_WARN_FREQ      60  /* frequency of warning beep */
#define BEEP_WARN_DUR      100  /* duration of warning beep */

/***************************  End of main.h  ****************************/
