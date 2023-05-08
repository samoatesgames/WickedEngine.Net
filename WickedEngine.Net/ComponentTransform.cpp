#include "pch.h"

#include "NumericsHelper.h"
#include "ComponentTransform.h"

WickedEngineNet::ComponentTransform::ComponentTransform(wi::scene::TransformComponent& transform)
	: m_transform(transform)
{
}

WickedEngineNet::ComponentTransform::~ComponentTransform()
{
}

void WickedEngineNet::ComponentTransform::SetTranslation(System::Numerics::Vector3^ position)
{
	XMFLOAT3 xmPosition;
	NumericsHelper::Vector3ToXMFloat3(position, xmPosition);

	m_transform.SetDirty();
	m_transform.translation_local = xmPosition;
}

void WickedEngineNet::ComponentTransform::SetRotation(System::Numerics::Vector3^ rotation)
{
    float yaw = wi::math::DegreesToRadians(rotation->Y);
    float pitch = wi::math::DegreesToRadians(rotation->X);
    float roll = wi::math::DegreesToRadians(rotation->Z);
    float rollOver2 = roll * 0.5f;

    float sinRollOver2 = (float)System::Math::Sin((double)rollOver2);
    float cosRollOver2 = (float)System::Math::Cos((double)rollOver2);
    float pitchOver2 = pitch * 0.5f;
    float sinPitchOver2 = (float)System::Math::Sin((double)pitchOver2);
    float cosPitchOver2 = (float)System::Math::Cos((double)pitchOver2);
    float yawOver2 = yaw * 0.5f;
    float sinYawOver2 = (float)System::Math::Sin((double)yawOver2);
    float cosYawOver2 = (float)System::Math::Cos((double)yawOver2);

    XMFLOAT4 xmRotation;
    xmRotation.w = cosYawOver2 * cosPitchOver2 * cosRollOver2 + sinYawOver2 * sinPitchOver2 * sinRollOver2;
    xmRotation.x = cosYawOver2 * sinPitchOver2 * cosRollOver2 + sinYawOver2 * cosPitchOver2 * sinRollOver2;
    xmRotation.y = sinYawOver2 * cosPitchOver2 * cosRollOver2 - cosYawOver2 * sinPitchOver2 * sinRollOver2;
    xmRotation.z = cosYawOver2 * cosPitchOver2 * sinRollOver2 - sinYawOver2 * sinPitchOver2 * cosRollOver2;

    m_transform.SetDirty();
	m_transform.rotation_local = xmRotation;
}

void WickedEngineNet::ComponentTransform::SetScale(System::Numerics::Vector3^ scale)
{
	XMFLOAT3 xmScale;
	NumericsHelper::Vector3ToXMFloat3(scale, xmScale);

	m_transform.SetDirty();
	m_transform.scale_local = xmScale;
}
