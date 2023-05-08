#pragma once

#include <WickedEngine/WickedEngine.h>
#include "NumericsHelper.h"

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

		System::Numerics::Vector3^ GetPosition() { return NumericsHelper::XMVectorToVector3(m_camera.GetEye()); }
		System::Numerics::Vector3^ GetForward() { return NumericsHelper::XMVectorToVector3(m_camera.GetAt()); }
		System::Numerics::Vector3^ GetUp() { return NumericsHelper::XMVectorToVector3(m_camera.GetUp()); }
		System::Numerics::Vector3^ GetRight() { return NumericsHelper::XMVectorToVector3(m_camera.GetRight()); }
	};
}