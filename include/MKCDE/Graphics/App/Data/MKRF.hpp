////////////////////////////////////////////////////////////////////////////////////////
//
//      * MKRF - Mister KygecHik Resource Files *
//
//  -------------------------------------------------
//  The structure of the MKRF file
//  -------------------------------------------------
//  Byte Offset    |  Size (bytes)  |  Description
//  -------------------------------------------------
//  0-3            |  4             |  MKRF signature (4D 4B 52 46)
//  4-11           |  8             |  File version
//  12             |  1             |  Encryption flag (0x00 - no encryption, 0x01 - EAS, etc.)
//  13             |  1             |  Compression flag (0x00 - no compression, 0x01 - deflate, etc.)
//  14-15          |  2             |  Checksum flag (0x00 - CRC32, 0x01 - CRC64, etc.)
//  16-[16+Variable|  Variable      |  Checksum (Size is determined by the Checksum flag)
//  prev-(prev+10) |  10            |  Number of resources
//  prev-(prev+10) |  10            |  Total size of all resources (in bytes)
//  prev-(prev+10) |  10            |  Reserved for future use
//  prev-(prev+12) |  12            |  End-of-file marker
//  prev+          |  Variable      |  Resource files
//
//
//  -------------------------------------------------
//  The structure of the resource file
//  -------------------------------------------------
//  Byte Offset    |  Size (bytes)  |  Description
//  -------------------------------------------------
//  0-255          |  256           |  Resource name
//  256-259        |  4             |  Resource size (in bytes)
//  260            |  1             |  Empty file flag (0x01 if empty, 0x00 otherwise)
//  261-272        |  12            |  Reserved for future use
//  273+           |  Variable      |  Resource data (Min of 1 byte)
//  Last 12        |  12            |  End-of-resource marker
////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <fstream>
#include <vector>

#ifndef MK_MKRF_HPP
#define MK_MKRF_HPP

namespace mk
{
struct Resource
{

};

struct MKRF 
{

};

void readMKRF(const std::string& filename, MKRF& mkrf);

void writeMKRF(const std::string& filename, const MKRF& mkrf);
}

#endif
