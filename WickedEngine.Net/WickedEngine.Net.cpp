#include "pch.h"

#include "WickedEngine.Net.h"
#include "utilities/ModelImporter.h"

WickedEngineNet::WickedEngineNet::WickedEngineNet()
{
	m_application = new wi::Application();
	m_application->infoDisplay.watermark = false;

	m_renderPath = gcnew RenderPath();

	auto& globalScene = wi::scene::GetScene();
	m_camera = gcnew Camera(wi::scene::GetCamera());
	m_weather = gcnew Weather(globalScene.weather);
}

void WickedEngineNet::WickedEngineNet::SetShaderPath(String^ shaderPath)
{
	wi::renderer::SetShaderSourcePath(msclr::interop::marshal_as<std::string>(shaderPath));
}

void WickedEngineNet::WickedEngineNet::SetWindow(IntPtr windowHandle)
{
	HWND hwnd = ((HWND)windowHandle.ToPointer());
	m_application->SetWindow(hwnd);

	if (m_application->GetActivePath() == nullptr)
	{
		m_application->ActivatePath(m_renderPath->Native());
	}
}

void WickedEngineNet::WickedEngineNet::OnWindowResize()
{
	m_application->SetWindow(m_application->window);
}

void WickedEngineNet::WickedEngineNet::SetInfoDisplay(InfoDisplay flag, bool value)
{
	switch (flag)
	{
	case InfoDisplay::Active:
		m_application->infoDisplay.active = value;
		break;
	case InfoDisplay::Watermark:
		m_application->infoDisplay.watermark = value;
		break;
	case InfoDisplay::FpsInfo:
		m_application->infoDisplay.fpsinfo = value;
		break;
	case InfoDisplay::DeviceName:
		m_application->infoDisplay.device_name = value;
		break;
	case InfoDisplay::Resolution:
		m_application->infoDisplay.resolution = value;
		break;
	case InfoDisplay::LogicalSize:
		m_application->infoDisplay.logical_size = value;
		break;
	case InfoDisplay::ColorSpace:
		m_application->infoDisplay.colorspace = value;
		break;
	case InfoDisplay::HeapAllocationCounter:
		m_application->infoDisplay.heap_allocation_counter = value;
		break;
	case InfoDisplay::PipelineCount:
		m_application->infoDisplay.pipeline_count = value;
		break;
	case InfoDisplay::VramUsage:
		m_application->infoDisplay.vram_usage = value;
		break;
	case InfoDisplay::ColorGradingHelper:
		m_application->infoDisplay.colorgrading_helper = value;
		break;
	}
}

bool WickedEngineNet::WickedEngineNet::TryLoadGLTF(String^ filePath, Entity^% rootEntity)
{
	if (!System::IO::File::Exists(filePath))
	{
		return false;
	}

	// Load our model into a new scene
	wi::scene::Scene scene;
	ImportModel_GLTF(msclr::interop::marshal_as<std::string>(filePath), scene);

	// Grab the root entity
	auto bounds = gcnew Bounds(scene.bounds);
	rootEntity = gcnew Entity(scene.transforms.GetEntityArray()[0], bounds);

	// Merge our loaded model with the global scene
	auto& globalScene = wi::scene::GetScene();
	globalScene.Merge(scene);

	return true;
}

WickedEngineNet::Entity^ WickedEngineNet::WickedEngineNet::CreateLight()
{
	auto& globalScene = wi::scene::GetScene();
	auto name = "light_" + globalScene.lights.GetCount();

	auto entity = globalScene.Entity_CreateLight(
		msclr::interop::marshal_as<std::string>(name)
	);

	return gcnew Entity(entity);
}

void WickedEngineNet::WickedEngineNet::DestroyEntity(Entity^% entity)
{
	delete entity;
	entity = nullptr;
}

void WickedEngineNet::WickedEngineNet::Run()
{
	m_application->Run();
}

void WickedEngineNet::WickedEngineNet::Shutdown()
{
	delete m_renderPath;
	m_renderPath = nullptr;

	delete m_application;
	m_application = nullptr;
}
