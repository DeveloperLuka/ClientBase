#include <sdk/includes.h>
#include <akira/akira.h>

void akiraThread()
{
#if DEBUG
    AllocConsole();
    SetConsoleCtrlHandler(NULL, true);
    FILE* fIn;
    FILE* fOut;
    freopen_s(&fIn, "conin$", "r", stdin);
    freopen_s(&fOut, "conout$", "w", stdout);
    freopen_s(&fOut, "conout$", "w", stderr);

    Sleep(6000);
#endif

    akira::instance = std::make_unique<akira::c_akira>();

    if (!akira::instance->attach())
    {
        std::exit(1);
    }

    akira::instance->run();

    Sleep(5);

    akira::instance->unload();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call != DLL_PROCESS_ATTACH)
        return FALSE;

    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)akiraThread, 0, 0, 0);

    return TRUE;
}

