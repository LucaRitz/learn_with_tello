#pragma once
#include <glad/glad.h>
#include <engine/types.h>

enum class AttributeType : unsigned short {
	// TODO: keep or remove?
	/*
	BOOL,
	INT,
	UINT,
	FLOAT,
	DOUBLE,
	VECTOR_3,
	VECTOR_4,
	MATRIX_3,
	MATRIX_4,
	// Note: there are more types, add them as needed
	*/
	BYTE,
	UBYTE,
	SHORT,
	USHORT,
	INT,
	UINT,
	HALF_FLOAT,
	FLOAT,
	DOUBLE,
	FIXED
};

enum class Normalization : unsigned byte {
	ON,
	OFF
};

struct Attribute {
public:
	static Attribute of(unsigned short count, AttributeType type, Normalization normalization);
	const AttributeType type;
	const size_t typeSize;
	const unsigned short count;
	const Normalization normalization;
private:
	Attribute(unsigned short count, AttributeType type, Normalization normalization);
};

class VertexBuffer {
public:

	static VertexBuffer* of(size_t size, void* data);

	void reset(size_t size, void* data);
	void bind();

private:
	unsigned int id;

	VertexBuffer(size_t size, void* data);
};