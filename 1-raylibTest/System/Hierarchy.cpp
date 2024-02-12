#ifndef HierarchyClass
#define HierarchyClass 1

#include <vector>
#include "GameObject.cpp"

class Hierarchy {
public:
	std::vector<GameObject*> hierarchy;

	void AddGameObject(GameObject *GO) {
		GO->GameObjectID = this->hierarchy.size();
		this->hierarchy.push_back(GO);
	}

	void RemoveGameObject(int ID) {
		int deleteID = -1;
		for (int c = 0; c < this->hierarchy.size(); c++) {
			if (this->hierarchy[c]->GameObjectID == ID)
				deleteID = ID;
		}

		if (deleteID >= this->hierarchy.size())
			return;

		this->hierarchy.erase(this->hierarchy.begin() + deleteID);
	}
};

#endif
