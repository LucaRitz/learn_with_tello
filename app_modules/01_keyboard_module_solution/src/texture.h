#pragma once
#include <glad\glad.h>
#include "image.h"

class Texture {

public:
	unsigned int ID;

	static inline Texture of() {
		return Texture{};
	}

	inline Texture() {
		glGenTextures(1, &ID);
	}

	inline Texture& activeTexture(unsigned int nr) {
		glActiveTexture(GL_TEXTURE0 + nr);
		return *this;
	}

	inline Texture& bind() {
		glBindTexture(GL_TEXTURE_2D, ID);
		return *this;
	}

	inline Texture& image(const Image& image) {
		int format = image.channels == 4 ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, format, GL_UNSIGNED_BYTE, image.data);
		return *this;
	}

	inline Texture& generateMipmap() {
		glGenerateMipmap(GL_TEXTURE_2D);
		return *this;
	}

	inline Texture& wrap(int textureWrapS, int textureWrapT) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrapT);
		return *this;
	}

	inline Texture& filter(int minifying, int magnifying) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minifying);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magnifying);
		return *this;
	}

};