#pragma once
#include "Object.h"

enum class COMPONENT_TYPE : uint8
{
	TRANSFORM,
	MESH_RENDERER,
	CAMERA,
	// ...
	MONO_BEHAVIOUR, //반드시 마지막 순서
	END,
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(COMPONENT_TYPE::END) - 1 //모노비헤이비어 뺀 나머지 컴포넌트 개수
};

class GameObject;
class Transform;

class Component : public Object
{
public:
	Component(COMPONENT_TYPE type);
	virtual ~Component(); //꼭 생성자 버츄얼로.

public:
	virtual void Awake() { } 
	virtual void Start() { } 
	virtual void Update() { } 
	virtual void LateUpdate() { } 
	virtual void FinalUpdate() { }

public:
	COMPONENT_TYPE GetType() { return _type; }
	bool IsValid() { return _gameObject.expired() == false; }

	shared_ptr<GameObject> GetGameObject();
	shared_ptr<Transform> GetTransform();

private:
	friend class GameObject; //game object한테만 접근권한 열어주는.
	void SetGameObject(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }

protected:
	COMPONENT_TYPE _type;
	weak_ptr<GameObject> _gameObject;
};

