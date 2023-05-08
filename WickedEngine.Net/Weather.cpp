#include "pch.h"

#include "Weather.h"
#include "NumericsHelper.h"

WickedEngineNet::Weather::Weather(wi::scene::WeatherComponent& weather)
	: m_weather(weather)
{
}

WickedEngineNet::Weather::~Weather()
{
}

void WickedEngineNet::Weather::SetHorizon(System::Numerics::Vector3^ horizon)
{
	NumericsHelper::Vector3ToXMFloat3(horizon, m_weather.horizon);
}

void WickedEngineNet::Weather::SetZenith(System::Numerics::Vector3^ zenith)
{
	NumericsHelper::Vector3ToXMFloat3(zenith, m_weather.zenith);
}

void WickedEngineNet::Weather::SetAmbient(System::Numerics::Vector3^ ambient)
{
	NumericsHelper::Vector3ToXMFloat3(ambient, m_weather.ambient);
}
