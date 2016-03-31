#pragma once
/* the model class loads and translate the code from Assimp 
the represents a model in its entirety.
*/
//#include <vector>
#include "shader.h"
#include "mesh.h"
#include <assimp/scene.h>
#include <assimp\Importer.hpp>
#include <assimp/postprocess.h>


class Model
{
public:
	/*  Model Data */
	//std::vector<Texture> mTexturesLoaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	std::vector<Mesh> mMeshes;
	std::string mDirectory;
	bool mGammaCorrection;

	/*  Functions   */
	// Constructor, expects a filepath to a 3D model.
	Model(std::string const & path, bool gamma = false);
	// Draws the model
	void draw();

private:
	/*  Functions   */
	// Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
};
