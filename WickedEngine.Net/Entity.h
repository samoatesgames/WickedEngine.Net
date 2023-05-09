#pragma once

#include <WickedEngine/WickedEngine.h>

#include "Bounds.h"
#include "ComponentTransform.h"
#include "ComponentLight.h"

namespace WickedEngineNet
{
	public ref class Entity
	{
	private:
		wi::ecs::Entity m_entityId { wi::ecs::INVALID_ENTITY };
		Bounds^ m_bounds { nullptr };

	public:
		Entity(wi::ecs::Entity entityId);
		Entity(wi::ecs::Entity entityId, Bounds^ bounds);
		~Entity();

		ComponentTransform^ GetTransform();
		ComponentLight^ GetLight();
		Bounds^ GetBounds();
	};
}