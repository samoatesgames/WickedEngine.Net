#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class ComponentLight
	{
	private:
		wi::scene::LightComponent& m_light;

	public:
		ComponentLight(wi::scene::LightComponent& transform);
		~ComponentLight();
	};
}
