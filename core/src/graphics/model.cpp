#include "model.h"

Model::Model(std::string const & path, bool gamma)
	:mDirectory(path), mGammaCorrection(gamma)
{
	loadModel(path);
}
void Model::draw()
{
	
	//call draw function for each mesh
	for (GLuint i = 0; i < this->mMeshes.size(); i++)
	{
		this->mMeshes[i].draw();
	}
}
void Model::loadModel(std::string path)
{
	// read the model file using assimp
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	// check for import error
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "Error:: ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	// retrieve the path of the file
	this->mDirectory = path.substr(0, path.find_last_of("/"));
	//process root node recursively
	this->processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	// process each mesh located at the current node
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		// the node object only contains indices to index the actual object in the scene.
		//the scene contains all the data, node is just to key things organized
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->mMeshes.push_back(this->processMesh(mesh, scene));
	}
	// after we've process all the meshes we then recursively process each child
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}

}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	for (GLuint i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		//positions
		vertex.position = Vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
		vertices.push_back(vertex);
	}
	//retrive the vertice indices for each face
	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}
	return Mesh(vertices, indices);
}