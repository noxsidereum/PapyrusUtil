#include "Offsets.h"

// N.B. The IDs below were used in the official v4.3 mod, which
// supported SKSE2.1.5 / Skyrim 1.6.353. My reading of 
// https://www.nexusmods.com/skyrimspecialedition/mods/32444?tab=posts
// is that the IDs for all 1.6.x version remain the same (they *were* 
// broken between 1.5.97 to 1.6.x). So as long as you are using
// the All In One (Anniversary Edition) of the Address Library,
// which contains versionlib-1-6-659-0.bin (GOG), looking up
// these hardcoded address IDs below should still give us the correct
// offsets from the module base addresses.
//                                            - noxsidereum, nov 2022

// ---------------------------------------------------
// Offsets used by MiscUtil.cpp:
// ---------------------------------------------------
// ToggleFreeCamera(PlayerCamera *, bool stopTime)
//   where PlayerCamera is defined in skse64/GameCamera.h
unsigned long long Offset_ToggleFreeCam = 0;        // 50809

// ---------------------------------------------------
// Offsets used by PackageData.cpp:
// ---------------------------------------------------
// Packages::IsValidPackage(TESPackage *PackageID, Actor *ActorID)
unsigned long long Offset_IsValidPackage = 0;       // 29619

// TESPackage *PackageStartOrig(void *pthis, Actor *actor)
unsigned long long Offset_PackageStartOrig = 0;     // 12057

// UInt64 PackageEndOrig(void *pthis, void *arg1, Actor *actor, int PackID)
unsigned long long Offset_PackageEndOrig = 0;       // 69166

// Used by InitPlugin()
// While the offsets returned by FindOffsetByID(37398) and
// FindOffsetByID(53984) should still be valid for the GOG
// version, it's not necessarily true that the increments
// +0x47 and +0x103 are. Let's just hope that hasn't
// changed between 1.6.353 and 1.6.659...
unsigned long long Offset_PackageStart_Enter = 0;   // 37398 + 0x47
unsigned long long Offset_PackageEnd_Enter = 0;     // 53984 + 0x103


namespace Plugin {


	bool InitializeOffsets()
	{
		// This function is based on the sample code in the "How to Use" section at 
        // https://www.nexusmods.com/skyrimspecialedition/mods/32444
		VersionDb db;

		// Load database with current executable version.
		if (!db.Load())
		{
			_FATALERROR("Failed to load version database for current executable!");
			return false;
		}
		else
		{
			_MESSAGE("Loaded database for %s version %s.", 
				     db.GetModuleName().c_str(), db.GetLoadedVersionString().c_str());
		}

		if (!db.FindOffsetById(50809, Offset_ToggleFreeCam))
		{
			_FATALERROR("Failed to find version database address for ToggleFreeCam!");
			return false;
		}

		if (!db.FindOffsetById(29619, Offset_IsValidPackage))
		{
			_FATALERROR("Failed to find version database address for IsValidPackage!");
			return false;
		}

		if (!db.FindOffsetById(12057, Offset_PackageStartOrig))
		{
			_FATALERROR("Failed to find version database address for PackageStartOrig!");
			return false;
		}

		if (!db.FindOffsetById(69166, Offset_PackageEndOrig))
		{
			_FATALERROR("Failed to find version database address for PackageEndOrig!");
			return false;
		}

		if (!db.FindOffsetById(37398, Offset_PackageStart_Enter))
		{
			_FATALERROR("Failed to find version database address for PackageStartEnter!");
			return false;
		}
		Offset_PackageStart_Enter += 0x47;

		if (!db.FindOffsetById(53984, Offset_PackageEnd_Enter))
		{
			_FATALERROR("Failed to find version database address for PackageEndEnter!");
			return false;
		}
		Offset_PackageEnd_Enter += 0x103;


		return true;
	}

	// DEBUGGING FUNCTIONS
	// Based on the sample code in the "How to Use" section at 
	// https://www.nexusmods.com/skyrimspecialedition/mods/32444
	bool DumpSpecificVersion()
	{	
		VersionDb db;

		// Try to load database of version 1.6.659.0 regardless of running executable version.
		if (!db.Load(1, 6, 659, 0))
		{
			_FATALERROR("Failed to load database for 1.6.659.0!");
			return false;
		}

		// Write out a file called offsets-1.6.659.0.txt where each line is the ID and offset.
		// This file will be saved in the main Skyrim folder.
		db.Dump("offsets-1.6.659.0.txt");
		_MESSAGE("Dumped offsets for 1.6.659.0");
		return true;
	}
}