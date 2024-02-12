#ifndef GameObjectClass
#define GameObjectClass 1

#include "Objects.cpp"
#include <string>

class GameObject : public Objects {
public:
	unsigned int GameObjectID;
	std::string GameObjectName;

	GameObject() : GameObjectID(0), GameObjectName("") {}
	GameObject(unsigned int ID, std::string Name) : GameObjectID(ID), GameObjectName(Name) {}

};

#endif
