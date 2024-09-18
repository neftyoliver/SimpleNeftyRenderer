#pragma once

#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

typedef struct Vertex {
    float x, y, z;
} Vertex;

typedef struct Face {
    uint32_t
} Face;

namespace simple_obj {
    class Model {



    public:
        explicit Model(const std::string& fileName) {
            std::ifstream file;
            uint64_t file_size = 0;

            auto rawData = std::vector<std::string>();

            file.open(fileName.c_str());

            assert(file.is_open());

            while(!file.eof()) {
                auto rawSingleLine = std::string();
                std::getline(file, rawSingleLine);
                rawData.push_back(rawSingleLine);
                file_size += 1;
            }

            file.close();

            //meshData = std::make_unique<Mesh>(Mesh(file_size));

            for(auto lineFromData : rawData) {
                switch (lineFromData.begin()) {
                    case 'v': break;
                    default: break;
                }
            }
        }
    };

}
