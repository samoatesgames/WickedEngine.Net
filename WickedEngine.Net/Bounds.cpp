#include "pch.h"

#include "Bounds.h"
#include "NumericsHelper.h"

WickedEngineNet::Bounds::Bounds(wi::primitive::AABB bounds)
{
	m_bounds = new wi::primitive::AABB(bounds);
}

WickedEngineNet::Bounds::~Bounds()
{
	delete m_bounds;
	m_bounds = nullptr;
}

System::Numerics::Vector3^ WickedEngineNet::Bounds::GetMin()
{
	return NumericsHelper::XMFloatToVector3(m_bounds->getMin());
}

System::Numerics::Vector3^ WickedEngineNet::Bounds::GetMax()
{
	return NumericsHelper::XMFloatToVector3(m_bounds->getMax());
}

System::Numerics::Vector3^ WickedEngineNet::Bounds::GetCenter()
{
	return NumericsHelper::XMFloatToVector3(m_bounds->getCenter());
}

float WickedEngineNet::Bounds::GetRadius()
{
	return m_bounds->getRadius();
}
