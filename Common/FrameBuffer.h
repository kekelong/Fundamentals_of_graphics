#pragma once
#include <fstream>
#include"core.h"
//Ò»ÕÅÆÁÄ»

#define BACKGROUND_WHILE Color{255,255,255}
#define BACKGROUND_BLACK Color{255,255,255}


class FrameBuffer {

public:
    FrameBuffer(const uint32_t width = 700, const uint32_t height = 700)
        :width(width), height(height)
    {
        frame_buffer.resize(width * height);
    }

    void init(Color background = BACKGROUND_BLACK);

    void set_pixel(uint32_t index, Color color);
    void set_pixel(uint32_t x, uint32_t y, Color color);

    void Render();

    uint32_t get_index(uint32_t x, uint32_t y);

    std::vector<Color>& frame_buffer() { return frame_buffer; }

private:
    std::vector<Color> frame_buffer {};
    uint32_t width;
    uint32_t height;

};