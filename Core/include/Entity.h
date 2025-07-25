#pragma once

#include <unordered_map>
#include <typeindex>
#include <cassert>

#include "Transform.h"
#include "Sprite.h"



class Entity
{
public:

	template<typename T>
	void addComponent(T* component)
	{
		assert(component != nullptr && "Component pointer must not be null");
		assert(components.find(typeid(T)) == components.end() && "Component of this type already exists");

		components[typeid(T)] = std::unique_ptr<Component>(component);
	}


	template<typename T>
	T* getComponent()
	{
		// iterates though map to find key which == typeid(T)
		auto it = components.find(typeid(T));

		assert(it != components.end() && "Entity has no Component of this type");

		return static_cast<T*>(it->second.get());
	}


private:

	std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

};


