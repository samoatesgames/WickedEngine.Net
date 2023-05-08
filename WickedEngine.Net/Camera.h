#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class Camera
	{
	private:
		wi::scene::CameraComponent& m_camera;

	public:
		Camera(wi::scene::CameraComponent& camera);
		~Camera();

		void SetPositionAndLookAt(System::Numerics::Vector3^ position, System::Numerics::Vector3^ target);
	};
}