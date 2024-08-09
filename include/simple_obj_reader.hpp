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

typedef struct Mesh {
    std::unique_ptr<Vertex[]> vertexes;

    explicit Mesh(size_t vertexCount) {
        vertexes = std::make_unique<Vertex[]>(vertexCount);
    }
} Mesh;

namespace simple_obj {
    class Model {
        std::unique_ptr<Mesh> meshData;

    public:
        explicit Model(const std::string& fileName) {

            std::ifstream file;
            uint64_t xyz = 0; // x:0, y:1, z:2
            uint64_t file_size = 0;

            auto rawData = std::vector<std::string>();
            auto rawSingleLine = std::string();

            float element_value = 0.0F;

            file.open(fileName.c_str());

            assert(file.is_open());

            while(!file.eof()) {
                std::getline(file, rawSingleLine);
                rawData.push_back(rawSingleLine);
                file_size += 1;
            }

            file.close();

            meshData = std::make_unique<Mesh>(file_size);


            uint32_t currentLine = 0;
            uint32_t curser = 0;
            uint32_t selection_start = 0;

            for(auto dataSingleLine : rawData) {

                bool selection = false;

                if(dataSingleLine.at(0) == 'v') {
                    curser += 2;
                    selection = true;

                }
                else if(dataSingleLine.at(0) == '#') {
                    continue;
                }

                char8_t crt = dataSingleLine.at(curser);

                xyz = 0;
                while (xyz < 3) {

                    while (selection) {


                        if(std::isdigit(crt) || crt == '-' || crt == '.') {
                            curser += 1;
                            crt = dataSingleLine.at(curser);
                            continue;
                        }

                        if (crt == ' ') {
                            auto str = dataSingleLine.substr(selection_start, curser - 1);
                            if(str.back() == ' ') {
                                str.pop_back();
                                curser += 1;
                            }

                            element_value = std::stof(str);
                            selection_start = curser;
                        }

                        if(xyz == 2) {
                            selection = false;
                        }

                        switch (xyz) {
                            case 0: meshData->vertexes[currentLine].x = element_value; break;
                            case 1: meshData->vertexes[currentLine].y = element_value; break;
                            case 2: meshData->vertexes[currentLine].z = element_value; break;
                            default: ;
                        }
                        xyz += 1;
                    }
                    selection_start = curser;
                    crt = dataSingleLine.at(curser);
                }
                currentLine += 1;

            }
        }
    };

}
