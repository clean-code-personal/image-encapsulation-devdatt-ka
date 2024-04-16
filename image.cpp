
#include <iostream>
#include "image.h" 

Image::Image(uint16_t rows, uint16_t columns) : m_columns(columns), m_rows(rows)
{
    if (rows > 1024 || columns > 1024)
        m_pixels = nullptr;
    else
        m_pixels = new uint8_t[columns * rows];
 }

Image::~Image()
{
    std::cout << "freeing pixel memory.\n";
    delete[] m_pixels;
}

bool Image::IsValid()
{
    return m_pixels != nullptr;
}
std::pair<uint16_t, uint16_t> Image::GetImageDimensions()
{
    return std::make_pair(m_columns, m_rows);
}

uint8_t* Image::AccessPixels()
{
    return m_pixels;
}