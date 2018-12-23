# Microsoft Developer Studio Project File - Name="graphics_prj" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=graphics_prj - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "graphics_prj.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "graphics_prj.mak" CFG="graphics_prj - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "graphics_prj - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "graphics_prj - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "graphics_prj - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "graphics_prj - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "graphics_prj - Win32 Release"
# Name "graphics_prj - Win32 Debug"
# Begin Group "CMUgraphicsLib"

# PROP Default_Filter ""
# Begin Group "JPEG"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jcomapi.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jconfig.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jcparam.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdapimin.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdapistd.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdatasrc.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdcoefct.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdcolor.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdct.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jddctmgr.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdhuff.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdhuff.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdinput.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdmainct.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdmarker.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdmaster.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdmerge.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdphuff.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdpostct.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdsample.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jdtrans.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jerror.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jerror.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jidctflt.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jidctfst.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jidctint.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jidctred.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jinclude.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jmemmgr.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jmemnobs.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jmemsys.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jmorecfg.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jpegint.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jpeglib.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jquant1.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jquant2.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jutils.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpeg\jversion.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\CMUgraphicsLib\auxil.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\auxil.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\CMUgraphics.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\CMUgraphics.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\colors.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\error.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\image.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\image.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpegload.c
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\jpegload.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\keyqueue.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\keyqueue.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\mousequeue.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\mousequeue.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\version.h
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\windowinput.cpp
# End Source File
# Begin Source File

SOURCE=.\CMUgraphicsLib\windowinput.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\demo.cpp
# End Source File
# End Target
# End Project
