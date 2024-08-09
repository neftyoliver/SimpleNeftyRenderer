#pragma once

#include <cstdint>

class Program {
    auto loadModel() -> int32_t;
    auto createRenderer() -> int32_t;
    auto openScreen(uint32_t width, uint32_t height) -> void;
    auto start() -> int32_t;

public:
    Program();
    int32_t run();
    int32_t exit();
    ~Program();
};
