@echo off

IF NOT EXIST ..\dist mkdir ..\dist
pushd ..\dist

set windows_kits="C:\Program Files (x86)\Windows Kits"

set visual_studio="C:\Program Files\Microsoft Visual Studio"

cl /nologo /ZI /c /IC:\qt5-build\qtbase\include /IC:\qt5-build\qtbase\include\QtWidgets\ /IC:\Users\ander\projects\hello-qt\Qt\5.15.2\msvc2019_64\include\ /I%windows_kits%\10\Include\10.0.22621.0\shared /I%windows_kits%\10\Include\10.0.22621.0\um /I%visual_studio%\2022\Community\VC\Tools\MSVC\14.37.32822\include\ /I%windows_kits%\10\Include\10.0.22621.0\ucrt ..\src\hello-qt.cpp
echo "error level %errorlevel%"

if NOT %errorlevel% == 0 (
    pushd ..\
    exit
)
echo "compilation DONE"
echo "----------------"

link /DEBUG /NOLOGO hello-qt.obj /LIBPATH:"C:\qt5-build\qtbase\lib" /LIBPATH:"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\lib\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64" /OUT:".\hello-qt.exe" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" Qt5Widgets.lib

if NOT %errorlevel% == 0 (
    pushd ..\
    exit
)
echo "linking DONE"
echo "----------------"

popd