#ifndef MeshManager_hpp
#define MeshManager_hpp
#include<map>
#include<string>
class Mesh;
class VertexArrayObject;



class MeshManager
{
public:
    static MeshManager* getInstance();

    Mesh* createCube();
    Mesh* createSnake();
    Mesh* createGameArea();
private:
    static MeshManager* m_Instance;
    MeshManager();
    std::map<std::string,VertexArrayObject* > m_VaoMap;
};
#endif