#include "pch.h"

#include "ComponentLight.h"
#include "NumericsHelper.h"

WickedEngineNet::ComponentLight::ComponentLight(wi::scene::LightComponent& light)
    : m_light(light)
{
}

WickedEngineNet::ComponentLight::~ComponentLight()
{
}

void WickedEngineNet::ComponentLight::SetCastShadow(bool enable)
{
    m_light.SetCastShadow(enable);
}

void WickedEngineNet::ComponentLight::SetIntensity(float intensity)
{
    m_light.intensity = intensity;
}

void WickedEngineNet::ComponentLight::SetColor(System::Numerics::Vector3^ color)
{
    NumericsHelper::Vector3ToXMFloat3(color, m_light.color);
}
