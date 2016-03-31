#pragma once
#include <vector>
#include "../maths/maths.h"
#include "shader.h"
#include <assimp\types.h>


struct Vertex
{
	Vec3 position;
	Vec3 normal;
	Vec3 texCoords;
};


class Mesh {
public:
	/*  Mesh Data  */
	std::vector<Vertex> mVertices;
	std::vector<GLuint> mIndices;
	GLuint mVAO, mVBO, mEBO;

	/*  Functions  */
	// Constructor
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	// Render the mesh
	void draw();

private:

	/*  Functions    */
	// Initializes all the buffer objects/arrays
	void setupMesh();
};
