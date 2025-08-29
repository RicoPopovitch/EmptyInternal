#include "engine.h"
#include <iostream>
#include <psapi.h>

void GetProcInfo(ProcessInfo& info) {
    info.pid = GetCurrentProcessId();
    info.handle = GetCurrentProcess();

    char buf[MAX_PATH] = {0};
    GetModuleFileNameA(NULL, buf, MAX_PATH);
    info.name = buf;

    info.hwnd = GetForegroundWindow();

    HMODULE hMod = GetModuleHandleA(NULL);
    info.baseAddress = reinterpret_cast<uintptr_t>(hMod);

    MODULEINFO modInfo = {0};
    if (GetModuleInformation(info.handle, hMod, &modInfo, sizeof(modInfo))) {
        info.moduleSize = modInfo.SizeOfImage;
    } else {
        info.moduleSize = 0;
    }

    std::cout << "PID: " << info.pid << std::endl;
    std::cout << "Handle: " << info.handle << std::endl;
    std::cout << "Name: " << info.name << std::endl;
    std::cout << "Base: " << std::hex << info.baseAddress << std::dec << std::endl;
    std::cout << "Size: " << info.moduleSize << std::endl;
}