#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class Weather
	{
	private:
		wi::scene::WeatherComponent& m_weather;

	public:
		Weather(wi::scene::WeatherComponent& weather);
		~Weather();

		void SetHorizon(System::Numerics::Vector3^ horizon);
		void SetZenith(System::Numerics::Vector3^ zenith);
		void SetAmbient(System::Numerics::Vector3^ ambient);
	};	   
}		   