#include "pch.h"

#include "Entity.h"

WickedEngineNet::Entity::Entity(wi::ecs::Entity entityId)
	: Entity(entityId, nullptr)
{
}

WickedEngineNet::Entity::Entity(wi::ecs::Entity entityId, Bounds^ bounds)
	: m_entityId(entityId)
	, m_bounds(bounds)
{
}

WickedEngineNet::Entity::~Entity()
{
	delete m_bounds;
	m_bounds = nullptr;
}

WickedEngineNet::ComponentTransform^ WickedEngineNet::Entity::GetTransform()
{
	auto& globalScene = wi::scene::GetScene();
	auto* transform = globalScene.transforms.GetComponent(m_entityId);
	return gcnew ComponentTransform(*transform);
}

WickedEngineNet::Bounds^ WickedEngineNet::Entity::GetBounds()
{
	return m_bounds;
}
