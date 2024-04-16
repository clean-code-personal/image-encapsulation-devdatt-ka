#include <iostream>
#include "brightener.h"
#include "image.h"
int main() {
	auto image = std::make_shared<Image>(512, 512);
	std::cout << "Brightening a 512 x 512 image\n";
	if(image->IsValid())
	{
		ImageBrightener brightener(image);
		int attenuatedCount = brightener.BrightenWholeImage();
		std::cout << "Attenuated " << attenuatedCount << " pixels\n";
		std::cout << "... in an image of: " << 512 << " x " << 512 << "\n";
		return 0;
	}
	else {
		std::cout << "Not a valid image... did nothing\n";
		return 1;
	}
}
