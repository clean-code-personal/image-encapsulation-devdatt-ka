#pragma once
#include <cstdint>
#include <utility>
class Image {
public:
	Image(uint16_t rows, uint16_t columns);
	~Image();
	bool IsValid();
	std::pair<uint16_t, uint16_t> GetImageDimensions();
	uint8_t* AccessPixels();
private:
	const uint16_t m_rows;
	const uint16_t m_columns;
	uint8_t* m_pixels; // max 1k x 1k image
	
};
