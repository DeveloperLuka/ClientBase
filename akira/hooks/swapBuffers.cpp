#include <sdk/includes.h>
#include "../akira.h"
#include <gl/GL.h>

std::once_flag flag;

HWND window;

int __stdcall akira::hooks::swapBuffersHook(HDC hdc) 
{
	HWND mcWindow = FindWindow(L"LWJGL", nullptr);
	RECT windowRect;
	GetWindowRect(mcWindow, &windowRect);

	std::call_once(flag, [&]() {
		window = FindWindow(L"LWJGL", nullptr);
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(mcWindow);
		ImGui_ImplOpenGL2_Init();
		return akira::hooks::oswapBuffers;
	});

	HWND _new = FindWindow(L"LWJGL", nullptr);

	if (window != _new)
	{
		window = _new;
		ImGui::GetOverlayDrawList()->Clear();
		ImGui::GetOverlayDrawList()->ClearFreeMemory();
		ImGui_ImplOpenGL2_Shutdown();
		ImGui_ImplWin32_Shutdown();

		ImGui_ImplWin32_Init(window);
		ImGui_ImplOpenGL2_Init();

		SetWindowLongPtrA(window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::wndproc));
	}

	for (module* m : akira::instance->moduleMngr->getModules())
	{
		if (m->isEnabled() && m->isRenderModule())
		{
			ImGui_ImplOpenGL2_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			m->onRender();

			ImGui::Render();
			glViewport(0, 0, windowRect.right, windowRect.top);
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		}
	}

	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;

	return akira::hooks::oswapBuffers(hdc);
}