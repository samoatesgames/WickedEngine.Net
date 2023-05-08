#pragma once

using namespace System;

#include <WickedEngine/WickedEngine.h>

#include "Camera.h"
#include "InfoDisplayEnum.h"
#include "RenderPath.h"

namespace WickedEngineNet 
{
	public ref class WickedEngineNet
	{
	private:
		wi::Application* m_application = { nullptr };
		RenderPath^ m_renderPath = { nullptr };
		Camera^ m_camera = { nullptr };

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

		// Getters
		RenderPath^ GetRenderPath() { return m_renderPath; }
		Camera^ GetCamera() { return m_camera; }
	};
}
