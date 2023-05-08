#pragma once

#include <WickedEngine/WickedEngine.h>

#include "ComponentTransform.h"

namespace WickedEngineNet
{
	public ref class Entity
	{
	private:
		wi::ecs::Entity m_entityId;

	public:
		Entity(wi::ecs::Entity entityId);
		~Entity();

		ComponentTransform^ GetTransform();
	};
}