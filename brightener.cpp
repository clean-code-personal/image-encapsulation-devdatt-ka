#include "brightener.h"
#include <memory>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage) : m_inputImage(inputImage) {
}


int ImageBrightener::BrightenWholeImage() {
	// For brightening, we add a certain grayscale (25) to every pixel.
	// While brightening, some pixels may cross the max brightness. They are
	// called 'attenuated' pixels
	int attenuatedPixelCount = 0;
	auto [rows, columns] = m_inputImage->GetImageDimensions();
	auto pixels = m_inputImage->AccessPixels();
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			if (pixels[x * columns + y] > (255 - 25)) {
				++attenuatedPixelCount;
				pixels[x * columns + y] = 255;
			}
			else {
				int pixelIndex = x * columns + y;
				pixels[pixelIndex] += 25;
			}
		}
	}
	return attenuatedPixelCount;
}
