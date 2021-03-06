{.$DEFINE FMX}                //*** remove the dot as desired ***
{$DEFINE VCL}                //*** remove the dot as desired ***

{$IF CompilerVersion < 23}    //no FMX before XE2
  {$UNDEF FMX}
{$IFEND}

{$IFDEF FMX}
  {$UNDEF VCL}
{$ELSE}
  {$IFDEF MSWINDOWS}
    {$DEFINE VCL}             //if not FMX, assume VCL on Windows
  {$ENDIF}
{$ENDIF}

{$IF CompilerVersion >= 18.5}
  {$DEFINE CanInline}         //inlining record methods is unstable before D2007
{$IFEND}

{$IF CompilerVersion >= 20}
  {$DEFINE DepCom}            //deprecated directive allows comments from D2009
  {$DEFINE HasToString}
{$IFEND}

{$IF CompilerVersion >= 21}
  {$DEFINE NoRecEnumBug}      //QC 72213
  {$DEFINE HasIOUtils}
{$IFEND}

{$IF CompilerVersion >= 22}
  {$DEFINE HasTTimeZone}
  {$DEFINE HasGenerics}
{$IFEND}

{$IF CompilerVersion >= 24}
  {$DEFINE XE3+}
{$IFEND}

{$IF DEFINED(VER240) AND DEFINED(MACOS)}
  {$DEFINE BrokenFMXJpegExport}
{$IFEND}

{$IFOPT Q+}
  {$DEFINE OverflowCheckingOn}
{$ENDIF}

{$IFOPT R-}
  {$DEFINE RangeCheckingOff}
{$ENDIF}