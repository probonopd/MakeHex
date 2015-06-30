ReadMe for MakeHex version 4.12  Copyright 2005 John S. Fine

You may use, copy, modify and/or distribute this program for private or
commercial use provided that:

1)  You do not hold me responsible for any damage or negative consequences
resulting from those activities.

2)  You include this copyright notice and disclaimer in any copy of any part
or all of this program.

I do not provide any warranty of the correctness, safety, or suitibility of
this program for any purpose.

If you do not agree to these conditions, you have no permission to use, copy,
modify or distribute this program.
-------------------------------------------------------------------------------

   This program reads a .IRP file and creates a .HEX file containing the Pronto
hex sequences for the IR commands specified by that .IRP file.  To use:

1)  Select the .IRP file that corresponds to the IR protocol you want to use.

2)  Edit that .IRP file with a text editor.  MAKEHEX takes all its input from
the .IRP file including the device number and the range of function numbers.
You should change the "Device=" and "Function=" lines in the .IRP file to
specify the IR commands you want.  You may want to change other values in
the .IRP file.

3)  In command line mode, type:  "MAKEHEX file.irp"
    or in GUI mode, drag the .irp file onto the icon for MakeHex.exe
    Either way, MakeHex will create a new file with the same base name as the
    .irp file and the extension of .hex.  (That new file will replace any
    preexisting file with that name and the extension .hex).

4)  Open the .hex file with a text editor or viewer.

5)  Copy the hex sequences into your .CCF file.

5a)  There is a program named IrPanels avaliable from
http://www.remotecentral.com/cgi-bin/files/rcfiles.cgi?area=pronto&db=other&br=utilities&dv=irprograms&md=ccfpanels&fc=&kw=&st=&dt=&so=&pg=1&file=utilities/irpanels.zip
that can be used to create a new CCF file with all the functions arranged in
panels for easy testing.  After creating a .HEX file, open it with a text editor
such as NotePad.  Use "Edit" "Select All", then "Edit" "Copy" to copy all the
text.  Then start IrPanels and use ^V to paste the text into its window.  Follow
IrPanels documentation for further steps.
--------------------------------------------------------------------------------

Edit existing .IRP files

Device=   Normally, this is set to a single number which is the device code.
          Some protocols (NEC, NEC2, and Panasonic) have an optional second
          number in their device code.  When using a second number you must
          put a single dot between the two numbers.

Function= Normally, this is a pair of numbers with .. between them representing
          a range of functions to be generated in the .hex file.

Define X= A few protocols (Nokia32, Pioneer2, etc.) have extra parts to a
command beyond the device and function numbers.  These may need to be edited to
match related fields in the decoded signal.
--------------------------------------------------------------------------------

Command line options:

  You can use -H or -B as a command line option before the file name, to specify
hex function numbering or both decimal and hex (the default is just decimal).  For
example:

MakeHex -B nec1.irp

will generate nec1.hex with functions labeled in both decimal and hex.

This affects only the label generated above each sample of Pronto Hex.  It doesn not
have any effect on the Pronto Hex itself.  Also, the IrPanels program assumes
decimal function numbering, so you should not use these options to create input for
IrPanels.
--------------------------------------------------------------------------------

Windows Right Click Menu:

  If you use MakeHex a lot, or you want to use the command line options -H or -B
without using a command prompt, you should define MakeHex as an option on the
right click menu for .IRP files:

1) Start in any Window for the Windows Explorer (not Internet Explorer, but the
"explorer" used to look at directories of files).

2) Select "Folder Options" from the "Tools" menu

3) Click on "File Types"

4) Type IRP (you must not pause between the I and the R nor between the R and the P).

5) If it knows about IRP files, it will highlight its entry for IRP files.  Otherwise
it will beep and highlight some other type beginning with I.  (If it highlights a type
beginning with R or P, you paused too long between letters).  If IRP isn't there, press
NEW and then type IRP and press OK.

6) Once the IRP line is selected in the Folder Options window, press the "advanced"
button.

7) In the "Edit File Type" window, you can press "New" to define a new action.

8) Define a name for the action (such as MakeHex or MakeHex-H) in the "Action" field.

9) Define the command for the action in the "Application" field.  The command
requires the full path name of the program, such as C:\IR_PROGRAMS\MAKEHEX.EXE then
a blank then the command line option (-H or -B) if you want one, then another
blank then "%1".  For example, I have an action MakeHex-H with application
C:\IR\MAKEHEX\MAKEHEX.EXE -H "%1"
because my MAKEHEX.EXE is in the MAKEHEX subdirectory of IR.

10) Be sure you also have a command to edit .IRP files, for example my Edit command
is:
C:\WINDOWS\notepad.exe "%1"

Once all that is set up, you can right click on any .IRP file and select the desired
action from the context menu.
--------------------------------------------------------------------------------

Building new .IRP files

Device=
   This can be one value (which is used as D) or two values seperated by '.' (which
   are used as D and S).

Function=
   This can be one value (which is used as F) or two values seperated by '.' (which
   are used as F and N).  In either case it can be a range seperated by '..'
   Function=a         F is a
   Function=a.b       F is a, N is b
   Function=a..b      F from a to b
   Function=a.b..c.d  N from b to d for each possible f from a to c.

Define X=
Default X=
   These act the same in the current version.  Either defines a letter using an
   expression (see below).  D and F cannot be defined this way.  S and N can be
   defined this way and those definitions act only as defaults, which are
   overriden if S or N are specified by the Device or Function line.

   These can be used as in the U= of Tivo-NEC1 to specify extra input beyond
   device and function.  Or they can be used as in the C= of Panasonic to
   compute intermediate results.

   The positions of these lines within the file has no effect on the results.
   You can use a letter before or after defining it.  But for clarity, put
   these lines right after Device or Function when they give extra input and
   put them right before where they are used when they compute intermediate
   results.

Protocol=
   In this version, this is just a comment.

Frequency=
   Sets the modulation frequency.

Timebase=
   Sets the multiple used for any time values that aren't suffixed with 'u' or 'm'.
   This line should come before any lines that use time values.

MessageTime=
   Sets the duration of a frame.  Unlike prior versions of MakeHex, this value
   uses Timebase by default.  If you don't want multiples of Timebase, suffix with
   'u' or 'm'.

FIRSTBIT=MSB
   If this line is present, any conversions of bit fields to signals is done MSB
   first.  Otherwise, those default to LSB first.

ZERO=
ONE=
PREFIX=
SUFFIX=
R-PREFIX=
R-SUFFIX=
    Each of these defines a chunk of signal in the same syntax (see below) that
    Form= defines the whole signal.  However, these can each only refer to letters
    and other chunks that were defined before them, while Form= can refer to
    anything.  Normally these are each just a list of positive and negaitive
    durations.

FORM=
    Defines the overall structure of the signal.
    It is a list of expressions (see below) and the special characters '*' and '_'
    seperated by commas and optionally one semi-colon.
    The semi-colon marks the boundary between the one-time part and the repeat
    part.
    A '*' marks a point at which a prefix is inserted.  An '_' marks a point at
    which a suffix is inserted.
    If MessageTime is specified, every suffix and the end of the whole signal
    (even if it has no suffix) is padded up to MessageTime.

Expressions
    An expression defines either a duration or a bit-field.

    A bit-field is either X:Y or X:Y:Z, where each of X, Y and Z are subexpressions.
    If Y is positive X:Y means the low Y bits of X.
    If Y is negative X:Y means the low abs(Y) bits of X, reversed to the opposite sequence,
    so 4:3 and 1:-3 both are a 3 bit field with a value of 4.
    X:Y:Z means discard the low Z bits of X and take the low abs(Y) bits of what's left
    (reversed if Y is negative).  So 32:3:3 or 8:-3:3 are two more ways to make a 3 bit
    field with a value of 4.  (Z should never be negative).

    Subexpressions within an expression can be bit-fields or simple numbers.  Any whole
    expression that is not identifiable as a bit field will be treated as a duration.
    A duration is multiplied by Timebase unless it is identifiably in units of 'u' or
    'm'.

    You can use () in an expression to make the intent clearer or to override the default
    operator precidence.  For example, A+B:8 means the same as (A+B):8 but the latter is
    much clearer, and if you wanted A+(B:8) you need the ().

    You can use '*', '+', '-', and '^' as infix operators and '-' and '~' as prefix
    operators.


