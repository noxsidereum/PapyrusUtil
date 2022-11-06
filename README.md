# PapyrusUtil SE 4.3 GOG Edition

My fork of eeveelo's PapyrusUtil 4.3 code, with a few simple changes to get it working with the current Skyrim GOG edition (GOG branch of SKSE 2.2.3 / Skyrim game version 1.6.659)

Depends on:
  * Boost 1.80.0 (https://www.boost.org/users/history/version_1_80_0.html)
  * JsonCPP 1.9.5 (https://github.com/open-source-parsers/jsoncpp/releases/tag/1.9.5)
  * SKSE 2.2.3 GOG edition (https://github.com/ianpatt/skse64/tree/gog)
  * Ian's common classes used by script extenders (https://github.com/ianpatt/common)

Assumes path structures (if you have different paths, change the *.vcprojx file):
  * Boost at D:\boost_1_80_0
  * JsonCPP at C:\plugin_src\jsoncpp-1.9.5
  * SKSE GOG branch at C:\plugin_src\skse64-gog
  * Common script extender classes at C:\plugin_src\common

In summary, excluding Boost location mentioned above, we assume file structure of:

C:\plugin_src
   - common
     - IArchive.h, etc.
   - jsoncpp-1.9.5
     - amalgamate.py, etc.
   - PapyrusUtil
     - ActorUtil.cpp, etc.
   - skse64-gog
     - CMakelists.txt, README.md, etc. and subdirectories skse64, skse64_common, etc.

You'll need to compile Boost libraries so you get the "stage\lib" subfolder with the required *.lib files (see their website for instructions), the SKSE GOG branch and the common script extender classes, before you compile this PapyrusUtil code.

I was also having some issues with the location of the "common" folder. Fixed those by adjusting all the relevant paths in skse64-gog to refer to, e.g. "..\..\common\common_vc14.vcxproj" rather than "..\..\common\common\common_vc14.vcxproj".

noxsidereum @ 6 Nov 2022

------------------------------------
Eeveelo's original README follows:
--------------------------------

This is the SE version of the source code.

Depends on Boost, Jsoncpp, and the latest version of SKSE64.

Note: I'm not a C++ programmer. This was mainly all written after Googling basics and then applying the results here as necessary.
I also haven't very reliably kept up my local repo of it for the past 6-ish years. This was basically just a quick open source where I added every file I thought maybe relevant to the repo and pushed it. There is almost certainly old and unused files here. Sorry.

Will try to clean this up and push a LE branch later(tm).
