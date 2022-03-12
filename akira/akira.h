#include <sdk/includes.h>
#include "module/Module.h"
#include "module/ModuleManager.h"

namespace akira
{
	class c_akira
	{
	private:
		JNIEnv* env;
		JavaVM* vm;

		jmethodID findclass;
		jobject cloassloader;

		
	public:
		bool attach();

		void hook();

		void run();
		
		void unload();

		const auto getEnv() { return env; }
		const auto getJavaVM() { return vm; }

		class std::unique_ptr<moduleManager, std::default_delete<moduleManager>> moduleMngr;
	};

	namespace hooks
	{
		using swapBuffersFunction = int(__stdcall*)(HDC);

		inline swapBuffersFunction oswapBuffers = nullptr;

		int __stdcall swapBuffersHook(HDC);

		inline WNDPROC originalWndproc = nullptr;

		long __stdcall wndproc(const HWND hwnd, unsigned int usermsg, uintptr_t wparam, long lparam);
	}

	extern std::unique_ptr<c_akira> instance;
}