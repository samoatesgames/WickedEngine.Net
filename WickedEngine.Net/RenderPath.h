#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet 
{
	public ref class RenderPath
	{
	private:
		wi::RenderPath3D* m_renderPath = { nullptr };

	public:
		RenderPath();
		~RenderPath();

		// Internal use only.
		wi::RenderPath3D* Native() { return m_renderPath; }

		void SetHelperGridEnabled(bool enabled) { wi::renderer::SetToDrawGridHelper(enabled); }
		void SetTemporalAAEnabled(bool enabled) { wi::renderer::SetTemporalAAEnabled(enabled); }

		void SetSSREnabled(bool enabled) { m_renderPath->setSSREnabled(enabled); }

	};
}