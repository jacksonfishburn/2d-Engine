#pragma once

#include <unordered_map>
#include <typeindex>
#include <cassert>

#include "components/Transform.h"
#include "components/Sprite.h"


class Entity
{
public:

	template<typename T>
	void addComponent(T* component)
	{
		assert(component != nullptr && "Component pointer must not be null");
		assert(components.find(typeid(T)) == components.end() && "Component of this type already exists");

		// Key: type id
		// Value: Pointer of type Component, which really points to a derived Component but doesn't know it
		// Polymorphism
		components[typeid(T)] = std::unique_ptr<Component>(component);
	}


	template<typename T>
	T* getComponent()
	{
		// returns iterator of the pair with key typeid T
		auto comp = components.find(typeid(T));

		assert(comp != components.end() && "Entity has no Component of this type");

		// gets the value as a raw pointer and casts it as the type we want
		return static_cast<T*>(comp->second.get());
	}


	template<typename T>
	bool hasComponent()
	{
		auto comp = components.find(typeid(T));

		if (comp != components.end()) return true;
		return false;

	}

private:

	std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

};
