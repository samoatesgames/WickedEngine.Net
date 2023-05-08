#include "pch.h"

#include "Camera.h"

WickedEngineNet::Camera::Camera(wi::scene::CameraComponent& camera)
	: m_camera(camera)
{
}

WickedEngineNet::Camera::~Camera()
{
}

void WickedEngineNet::Camera::SetPositionAndLookAt(System::Numerics::Vector3^ position, System::Numerics::Vector3^ target)
{
	XMVECTOR eye = { position->X, position->Y, position->Z };
	XMVECTOR lookat = { target->X - position->X, target->Y - position->Y, target->Z - position->Z };
	XMVECTOR up = { 0, 1, 0 };

	lookat = XMVector3Normalize(lookat);
	auto lookatMatrix = XMMatrixLookAtLH(eye, lookat, up);

	XMStoreFloat4x4(&m_camera.View, lookatMatrix);
	XMStoreFloat3x3(&m_camera.rotationMatrix, XMMatrixInverse(nullptr, lookatMatrix));
	XMStoreFloat3(&m_camera.Eye, eye);
	XMStoreFloat3(&m_camera.At, lookat);
	XMStoreFloat3(&m_camera.Up, up);
}
