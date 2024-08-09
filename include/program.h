#pragma once
#include <cstdint>

class program {
private:
    void loadModel();
    void createRenderer();
    void openScreen(uint32_t width, uint32_t height);
    void start();

public:
    program();
    int32_t run();
    int32_t exit();
    ~program();
};