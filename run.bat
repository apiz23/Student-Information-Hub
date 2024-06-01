@echo off
gcc -o app index.c authenticate.c student.c course.c

if %errorlevel% neq 0 (
    echo Compilation failed!
    exit /b %errorlevel%
)

.\app