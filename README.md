# Dead by Daylight FPS Unlocker

## The issue
It's common knowledge that DayByDaylight despite its popularity doesn't offer any advanced graphical settings. Amongst these, undeniably the most missed  is option to unlock your FPS above 60. There is no simple way to do this in-game. 
## The solution
It can be done, however, by changing a few values in the game's files. This program is the simplest way to do so. Just fire it up, select your platform of choice, and enjoy your smooth experience.
## Safety
What we're doing here is neither a hack nor an exploit. You will not get banned for this.
## How to run
Simply download the .exe file from `Releases` tab and open it.
______________________________
## How to build
You can modify this program to your liking. This might come in handy in the future, as the game is constantly evolving. This being said, I'm not a DBD player, so I won't notice those changes.  
After modyfying the code, you can build it using `g++` into .exe file:
```bash
x86_64-w64-mingw32-g++ main.cpp Editor.cpp -static -static-libgcc -static-libstdc++ -o dbd_fps_unlocker.exe
```
The `-static -static-libgcc -static-libstdc++` flags are required to link the DLL files statically into your executable file. This means that the code from the DLL file will be embedded into your program, and you will not need to distribute it separately.

