// PcMonitorConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>

std::string GetMemoryPercentage();

int main()
{
    std::cout << "Memory Percentage: " + GetMemoryPercentage() + "%" << std::endl;
}

std::string GetMemoryPercentage()
{
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG memoryPercentage = memInfo.dwMemoryLoad;

    return std::to_string(memoryPercentage);
}