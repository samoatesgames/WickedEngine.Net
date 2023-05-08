#include "pch.h"

#include "Entity.h"

WickedEngineNet::Entity::Entity(wi::ecs::Entity entityId)
	: m_entityId(entityId)
{
}

WickedEngineNet::Entity::~Entity()
{
}

WickedEngineNet::ComponentTransform^ WickedEngineNet::Entity::GetTransform()
{
	auto& globalScene = wi::scene::GetScene();
	auto* transform = globalScene.transforms.GetComponent(m_entityId);
	return gcnew ComponentTransform(*transform);
}
