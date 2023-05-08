#pragma once

#include <WickedEngine/WickedEngine.h>

namespace WickedEngineNet
{
	public ref class NumericsHelper
	{
	public:
		static System::Numerics::Vector3^ XMVectorToVector3(XMVECTOR input)
		{
			return gcnew System::Numerics::Vector3(
				XMVectorGetX(input),
				XMVectorGetY(input),
				XMVectorGetZ(input)
			);
		}
	};
}