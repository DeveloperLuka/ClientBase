#include <sdk/includes.h>

#include "../akira.h"

long __stdcall akira::hooks::wndproc(const HWND hwnd, unsigned int usermsg, uintptr_t wparam, long lparam)
{
	if (WM_KEYDOWN == usermsg)	
	{ 
		std::cout << wparam << "\n";
		for (module* m : akira::instance->moduleMngr->getModules())
		{
			if (m->getKey() == wparam)
			{
				m->toggle();
			}
		}
	}

	return CallWindowProcA(hooks::originalWndproc, hwnd, usermsg, wparam, lparam);
}