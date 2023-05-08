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

		static System::Numerics::Vector3^ XMFloatToVector3(XMFLOAT3 input)
		{
			return gcnew System::Numerics::Vector3(
				input.x,
				input.y,
				input.z
			);
		}

		static void Vector3ToXMFloat3(System::Numerics::Vector3^ input, XMFLOAT3& output)
		{
			output.x = input->X;
			output.y = input->Y;
			output.z = input->Z;
		}
	};
}