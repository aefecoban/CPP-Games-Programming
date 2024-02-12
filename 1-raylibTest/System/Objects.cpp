#ifndef ObjectsClass
#define ObjectsClass 1

class Objects {

public:

	virtual void Start() = 0;
	virtual void Update(float dTime) = 0;
	virtual void LateUpdate(float dTime) = 0;
	virtual void Draw() = 0;

};

#endif
