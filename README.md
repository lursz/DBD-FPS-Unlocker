# Dead by Daylight FPS Unlocker
## The issue
## The solution
## How to run
______________________________
## How to compile
```bash
x86_64-w64-mingw32-g++ main.cpp Editor.cpp -static -static-libgcc -static-libstdc++ -o dbd.exe
```

You can link the DLL file statically into your executable file. This means that the code from the DLL file will be embedded into your program, and you will not need to distribute it separately. To do this, you need to use the linker options -static, -static-libgcc, and -static-libstdc++ when compiling your program2. For example:
x86_64-w64-mingw32-g++ main.cpp -static -static-libgcc -static-libstdc++ -o main.exe

This will create a standalone executable file that does not depend on any external DLL files.