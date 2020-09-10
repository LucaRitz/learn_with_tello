#pragma once
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb_image.h>
#include <iostream>

class Image {

public:
	const int width;
	const int height;
	const int channels; // 3=RGB or 4=RGBA
	const unsigned char* data;

	static inline Image of(std::string name) {
	
		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(name.c_str(), &width, &height, &nrChannels, 0);
		if (data == nullptr) {
			std::cerr << "Failed to load image " << name << std::endl;
			exit(-1);
		}
		return Image{ width, height, nrChannels, data };
	}

	Image(int width, int height, int channels, unsigned char* data)
		: width(width), height(height), channels(channels), data(data) {
		
	}

	/*
	Image(std::string name) {

		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;
		unsigned char* data = stbi_load(name.c_str(), &width, &height, &nrChannels, 0);
		if (data == nullptr) {
			std::cerr << "Failed to load image " << name << std::endl;
			exit(-1);
		}
		this->width = width;
		this->height = height;
		this->channels = nrChannels;
		this->data = data;
	};
	*/

	void free() {
		stbi_image_free((void*) data);
	}
};