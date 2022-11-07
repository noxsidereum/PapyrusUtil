# PapyrusUtil SE 4.3 GOG Edition

My fork of eeveelo's PapyrusUtil 4.3 code, with a few simple changes to get it working with the current Skyrim GOG edition (GOG branch of SKSE 2.2.3 / Skyrim game version 1.6.659)

Depends on:
  * Boost 1.80.0 (https://www.boost.org/users/history/version_1_80_0.html)
  * JsonCPP (https://github.com/open-source-parsers/jsoncpp) [but you don't need to download it]
  * SKSE 2.2.3 GOG edition (https://github.com/ianpatt/skse64/tree/gog)
  * Ian's common classes used by script extenders (https://github.com/ianpatt/common)

(you don't need to download JsonCPP or include as an external dependency, because eeveelo has already included amalgamated JsonCPP files in their packaged source - refer jsoncpp.cpp, json/json-forwards.h and json/json.h)

Assumes path structures as follows (if you have different paths, change the *.vcprojx file):

- C:\plugin_src\
   - common [Common script extender classes]
     - IArchive.h, etc.
   - PapyrusUtil [This source repo]
     - ActorUtil.cpp, etc.
   - skse64-gog [SKSE 2.2.3 GOG branch]
     - CMakelists.txt, README.md, etc. and subdirectories skse64, skse64_common, etc.

- D:\boost_1_80_0 [Boost installation]

(yeah yeah these are pretty arbitrary, would be better to define relative paths)

You'll need to compile Boost libraries so you get the "stage\lib" subfolder with the required *.lib files (see their website for instructions), the SKSE GOG branch and the common script extender classes, before you compile this PapyrusUtil code.

I was also having some issues with the location of the "common" folder. Fixed those by adjusting all the relevant paths in skse64-gog to refer to, e.g.,

    ..\..\common\common_vc14.vcxproj

rather than

    ..\..\common\common\common_vc14.vcxproj

This hack has not been extensively tested, but the plugin does load with my Skyrim GOG edition and seems to be working correctly with my (large, based on Lexy's guide) mod list.

noxsidereum @ 7 Nov 2022

P.S. I may or may not tinker with this code further, depending upon inclination, available time, and whether or not my mod list continues to work properly with it. Hopefully it won't be long before the official 4.4 GOG edition of PapyrusUtil comes out, making this redundant, another reason why I'm not putting much effort in.

------------------------------------
Eeveelo's original README follows:
--------------------------------

This is the SE version of the source code.

Depends on Boost, Jsoncpp, and the latest version of SKSE64.

Note: I'm not a C++ programmer. This was mainly all written after Googling basics and then applying the results here as necessary.
I also haven't very reliably kept up my local repo of it for the past 6-ish years. This was basically just a quick open source where I added every file I thought maybe relevant to the repo and pushed it. There is almost certainly old and unused files here. Sorry.

Will try to clean this up and push a LE branch later(tm).
