#include <fstream>
#include <vector>

struct Resource {
    uint32_t id;
    uint32_t type;
    uint32_t length;
    uint32_t checksum;
    uint32_t encryption;
    std::vector<char> data;
};

struct MKRF {
    char signature[4];
    uint32_t fileLength;
    uint32_t resourceCount;
    uint32_t headerLength;
    uint32_t minMemory;
    uint32_t maxMemory;
    uint32_t checksum;
    uint32_t firstResourceAddress;
    uint32_t overlayNumber;
    uint32_t compression;
    std::vector<Resource> resources;
};

MKRF readMKRF(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    MKRF mkrf;
    file.read(mkrf.signature, 4);
    file.read(reinterpret_cast<char*>(&mkrf.fileLength), sizeof(mkrf.fileLength));
    for (uint32_t i = 0; i < mkrf.resourceCount; ++i) {
        Resource resource;
        file.read(reinterpret_cast<char*>(&resource.id), sizeof(resource.id));
        file.read(reinterpret_cast<char*>(&resource.type), sizeof(resource.type));
        file.read(reinterpret_cast<char*>(&resource.length), sizeof(resource.length));
        file.read(reinterpret_cast<char*>(&resource.checksum), sizeof(resource.checksum));
        file.read(reinterpret_cast<char*>(&resource.encryption), sizeof(resource.encryption));
        resource.data.resize(resource.length);
        file.read(resource.data.data(), resource.length);
        mkrf.resources.push_back(resource);
    }
    return mkrf;
}

void writeMKRF(const std::string& filename, const MKRF& mkrf) {
    std::ofstream file(filename, std::ios::binary);
    file.write(mkrf.signature, 4);
    file.write(reinterpret_cast<const char*>(&mkrf.fileLength), sizeof(mkrf.fileLength));
    for (const auto& resource : mkrf.resources) {
        file.write(reinterpret_cast<const char*>(&resource.id), sizeof(resource.id));
        file.write(reinterpret_cast<const char*>(&resource.type), sizeof(resource.type));
        file.write(reinterpret_cast<const char*>(&resource.length), sizeof(resource.length));
        file.write(reinterpret_cast<const char*>(&resource.checksum), sizeof(resource.checksum));
        file.write(reinterpret_cast<const char*>(&resource.encryption), sizeof(resource.encryption));
        file.write(resource.data.data(), resource.length);
    }
}
