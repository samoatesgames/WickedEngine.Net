#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class ComponentTransform
	{
	private:
		wi::scene::TransformComponent& m_transform;

	public:
		ComponentTransform(wi::scene::TransformComponent& transform);
		~ComponentTransform();

		void SetTranslation(System::Numerics::Vector3^ position);
		void SetRotation(System::Numerics::Vector3^ rotation);
		void SetScale(System::Numerics::Vector3^ scale);
	};
}
