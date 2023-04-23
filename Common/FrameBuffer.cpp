#include "FrameBuffer.h"

void FrameBuffer::init(Color background = BACKGROUND_BLACK)
{
	std::fill(frame_buffer.begin(), frame_buffer.end(), background);
}

void FrameBuffer::set_pixel(uint32_t index, Color color)
{
	try
	{
		frame_buffer.at(index) = color;
	}
	catch (const std::exception&)
	{
		
	}
}

void FrameBuffer::set_pixel(uint32_t x, uint32_t y, Color color)
{
	set_pixel(get_index(x,y), color);
}

void FrameBuffer::Render(const char* filename)
{
	std::ofstream ofs(filename, std::ios::out | std::ios::binary);

	ofs << "P6\n" << width << " " << height << "\n255\n";

	for (uint32_t i = 0; i < height * width; ++i) {
		byte r = frame_buf[i].R;
		byte g = frame_buf[i].G;
		byte b = frame_buf[i].B;
		ofs << r << g << b;
	}
	ofs.close();
}

uint32_t FrameBuffer::get_index(uint32_t x, uint32_t y)
{
	return (height - y - 1) * width + x;
}
