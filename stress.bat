@echo off
g++ -std=c++17 -o main.exe main.cpp
g++ -std=c++17 -o main__Good.exe main__Good.cpp
g++ -std=c++17 -o main__Generator.exe main__Generator.cpp
for /l %%x in (1, 1, 100) do (
    main__Generator > inputf.in
    main < inputf.in > test.out 
    main__Good < inputf.in > outputf.out
    fc outputf.out test.out > diagnostics || exit /b
    echo Test #%%x :CORRECT!
)
echo all tests passed
pause
