@echo off

IF NOT EXIST ..\dist mkdir ..\dist
pushd ..\dist

cl /nologo /ZI /c /I "C:\Users\ander\projects\hello-qt\Qt\5.15.2\msvc2019_64\include\QtWidgets" /I "C:\Users\ander\projects\hello-qt\Qt\5.15.2\msvc2019_64\include" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um" /I "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\include" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt" ..\src\hello-qt.cpp
echo "error level %errorlevel%"

if NOT %errorlevel% == 0 (
    pushd ..\
    exit
)
echo "compilation DONE"
echo "----------------"

link /DEBUG /NOLOGO hello-qt.obj /LIBPATH:"C:\Users\ander\projects\hello-qt\Qt\5.15.2\msvc2019_64\lib" /LIBPATH:"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\lib\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64" /OUT:".\hello-qt.exe" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" QT5Widgets.lib

if NOT %errorlevel% == 0 (
    pushd ..\
    exit
)
echo "linking DONE"
echo "----------------"

popd