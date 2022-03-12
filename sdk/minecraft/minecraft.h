#pragma once

#include <sdk/includes.h>

namespace sdk
{
	class c_minecraft
	{
	private:
	public:
		jclass klass();
		jobject getMinecraft();
		jobject getPlayer();
		jobject getWorld();
	};

	extern std::unique_ptr<c_minecraft> instance;
}