#include <sdk/includes.h>
#include "../akira.h"
#include <gl/GL.h>

std::once_flag flag;

int __stdcall akira::hooks::swapBuffersHook(HDC hdc) 
{
	HWND mcWindow = FindWindow(L"LWJGL", nullptr);
	RECT windowRect;
	GetWindowRect(mcWindow, &windowRect);

	std::call_once(flag, [&]() {
			ImGui::CreateContext();
			ImGui_ImplWin32_Init(mcWindow);
			ImGui_ImplOpenGL2_Init();
			return akira::hooks::oswapBuffers;
	});

	for (module* m : akira::instance->moduleMngr->getModules())
	{
		if (m->isEnabled())
		{
			ImGuiIO& io = ImGui::GetIO();
			io.MouseDrawCursor = true;

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