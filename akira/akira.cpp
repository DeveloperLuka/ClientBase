#include <sdk/minecraft/minecraft.h>
#include "akira.h"

bool akira::c_akira::attach()
{
	HMODULE jvm = GetModuleHandleA("jvm.dll");

	using t_createdvms = jint(__stdcall*)(JavaVM**, jsize, jsize*);

	FARPROC processAddress = GetProcAddress(reinterpret_cast<HMODULE>(jvm), "JNI_GetCreatedJavaVMs");
	t_createdvms created_java_vms = reinterpret_cast<t_createdvms>(processAddress);

	auto ret = created_java_vms(&vm, 1, nullptr);

	if (ret != JNI_OK)
		return false;

	ret = vm->AttachCurrentThread(reinterpret_cast<void**>(&env), nullptr);

	if (ret != JNI_OK)
		return false;

	hook();

	return true;
}

void akira::c_akira::hook()
{
	MH_Initialize();

	auto swapBuffersPointer = GetProcAddress(GetModuleHandleA("Gdi32.dll"), "SwapBuffers");

	MH_CreateHook(swapBuffersPointer, hooks::swapBuffersHook, reinterpret_cast<void**>(&hooks::oswapBuffers));
	MH_EnableHook(MH_ALL_HOOKS);

	hooks::originalWndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(FindWindow(L"LWJGL", nullptr), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::wndproc)));
}

void akira::c_akira::run()
{
	sdk::instance = std::make_unique<sdk::c_minecraft>();
	moduleMngr = std::make_unique<moduleManager>();

	while (true)
	{
		for (module* m : moduleMngr->getModules())
		{
			if (m->isEnabled())
				m->onTick();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void akira::c_akira::unload()
{
	getJavaVM()->DetachCurrentThread();

	ImGui_ImplOpenGL2_Shutdown();
	ImGui::DestroyContext();
	ImGui_ImplWin32_Shutdown();

	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	SetWindowLongPtrA(FindWindow(L"LWJGL", nullptr), GWLP_WNDPROC, (LONG_PTR)hooks::originalWndproc);
	
	env = nullptr;
	vm = nullptr;
}

std::unique_ptr<akira::c_akira> akira::instance;