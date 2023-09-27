# GameBoyToExe

I was once asked to make this program which embeds the same javascript Game Boy emulator used by GBStudio into a Windows executable for sharing Game Boy releases without requiring the user to have an emulator. The resulting executable package & dependencies eats quite a lot of storage which makes it impractical for a large number of ROMs, but I'll leave it as it is because who knows who might find it of some use one day. 

This tool is no longer actively maintained. Feel free to fork it if you think the effort pays off.

The project is split into two parts:

- GBP, which is the actual Gameboy Player written in Qt. It uses a QWebEngine to render a HTML page containing the GameBoy emulator.
- GB2EXE, the tool that's used to inject the Game Boy ROM into GBP at a hardcoded offset. I think a part of the code is missing from here for some reason, I'll upload it if I ever find it.
