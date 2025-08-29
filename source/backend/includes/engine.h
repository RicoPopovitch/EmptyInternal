#pragma once
#include <windows.h>
#include <string>

struct ProcessInfo {
    DWORD pid;
    HANDLE handle;
    std::string name;
    HWND hwnd;
    uintptr_t baseAddress;
    size_t moduleSize;
};

void GetProcInfo(ProcessInfo& info);