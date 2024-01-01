#include <fstream>
#include <vector>

struct ResourceHeader {
    uint32_t id;
    uint32_t type;
    uint32_t length;
    uint32_t checksum;
};

struct MKRFHeader {
    char signature[4];
    uint32_t fileLength;
    uint32_t resourceCount;
    uint32_t headerLength;
    uint32_t minMemory;
    uint32_t maxMemory;
    uint32_t checksum;
    uint32_t firstResourceAddress;
    uint32_t overlayNumber;
    std::vector<ResourceHeader> resources;
};

MKRFHeader readMKRF(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    MKRFHeader header;
    file.read(header.signature, 4);
    file.read(reinterpret_cast<char*>(&header.fileLength), sizeof(header.fileLength));
    return header;
}

void writeMKRF(const std::string& filename, const MKRFHeader& header) {
    std::ofstream file(filename, std::ios::binary);
    file.write(header.signature, 4);
    file.write(reinterpret_cast<const char*>(&header.fileLength), sizeof(header.fileLength));
}
