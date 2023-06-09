#pragma once

using namespace System;

#include <WickedEngine/WickedEngine.h>

#include "Camera.h"
#include "Entity.h"
#include "InfoDisplayEnum.h"
#include "RenderPath.h"
#include "Weather.h"

namespace WickedEngineNet 
{
	public ref class WickedEngineNet
	{
	private:
		wi::Application* m_application = { nullptr };
		RenderPath^ m_renderPath = { nullptr };
		Camera^ m_camera = { nullptr };
		Weather^ m_weather = { nullptr };

	public:
		WickedEngineNet();

		// Core
		void Run();
		void Shutdown();

		// Window
		void SetShaderPath(String^ shaderPath);
		void SetWindow(IntPtr windowHandle);
		void OnWindowResize();

		// Misc
		void SetInfoDisplay(InfoDisplay flag, bool value);

		// Entities
		bool TryLoadGLTF(String^ filePath, Entity^% rootEntity);
		Entity^ CreateLight(LightType lightType);
		void DestroyEntity(Entity^% entity);

		// Getters
		bool IsInitialized() { return m_application != nullptr && m_application->GetActivePath() != nullptr; }
		RenderPath^ GetRenderPath() { return m_renderPath; }
		Camera^ GetCamera() { return m_camera; }
		Weather^ GetWeather() { return m_weather; }
	};
}
