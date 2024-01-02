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
//  14-22          |  9             |  Checksum (CRC32)
//  23-32          |  10            |  Number of resources
//  33-42          |  10            |  Total size of all resources (in bytes)
//  43-52          |  10            |  Reserved for future use
//  53-64          |  12            |  End-of-file marker
//  65+            |  Variable      |  Resource files
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
//  273+           |  Min of 1 byte |  Resource data
//  Last 12        |  12            |  End-of-resource marker
////////////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <vector>

struct Resource {
};

struct MKRF {
};

MKRF readMKRF(const std::string& filename) {
    MKRF mkrf;
    return mkrf;
}

void writeMKRF(const std::string& filename, const MKRF& mkrf) {
}
