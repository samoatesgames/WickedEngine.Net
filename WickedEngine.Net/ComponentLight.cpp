#include "pch.h"

#include "ComponentLight.h"

WickedEngineNet::ComponentLight::ComponentLight(wi::scene::LightComponent& light)
    : m_light(light)
{
    m_light.SetType(wi::scene::LightComponent::DIRECTIONAL);
    m_light.SetCastShadow(true);
    m_light.intensity = 10.0f;
}

WickedEngineNet::ComponentLight::~ComponentLight()
{
}
