#pragma once

using namespace System;

#include <WickedEngine/WickedEngine.h>
#include "InfoDisplayEnum.h"

namespace WickedEngineNet {
	public ref class WickedEngineNet
	{
	private:
		wi::Application* m_application = { nullptr };
		wi::RenderPath3D* m_renderPath = { nullptr };

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
	};
}
