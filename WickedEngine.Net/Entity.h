#pragma once

#include <WickedEngine/WickedEngine.h>

#include "Bounds.h"
#include "ComponentTransform.h"

namespace WickedEngineNet
{
	public ref class Entity
	{
	private:
		wi::ecs::Entity m_entityId;
		Bounds^ m_bounds;

	public:
		Entity(wi::ecs::Entity entityId);
		Entity(wi::ecs::Entity entityId, Bounds^ bounds);
		~Entity();

		ComponentTransform^ GetTransform();
		Bounds^ GetBounds();
	};
}