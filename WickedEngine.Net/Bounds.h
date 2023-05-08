#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class Bounds
	{
	private:
		wi::primitive::AABB* m_bounds;

	public:
		Bounds(wi::primitive::AABB bounds);
		~Bounds();

		System::Numerics::Vector3^ GetMin();
		System::Numerics::Vector3^ GetMax();
		System::Numerics::Vector3^ GetCenter();
		float GetRadius();
	};
}
