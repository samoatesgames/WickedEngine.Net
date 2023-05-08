
#include "RenderPath.h"
#include "pch.h"

#include "RenderPath.h"

WickedEngineNet::RenderPath::RenderPath()
{
	m_renderPath = new wi::RenderPath3D();
}

WickedEngineNet::RenderPath::~RenderPath()
{
	delete m_renderPath;
	m_renderPath = nullptr;
}
