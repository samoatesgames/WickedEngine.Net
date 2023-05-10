#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public enum class LightType
	{
		Directional,
		Point,
		Spot
	};

	public ref class ComponentLight
	{
	private:
		wi::scene::LightComponent& m_light;

	public:
		ComponentLight(wi::scene::LightComponent& light);
		~ComponentLight();

		void SetCastShadow(bool enable);
		void SetIntensity(float intensity);
		void SetColor(System::Numerics::Vector3^ color);
	};
}
