// PcMonitorConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <ctime> 

std::string GetMemoryPercentage();
void PrintToConsole();

auto lastSentTime = std::chrono::system_clock::now();

int main()
{
    lastSentTime = std::chrono::system_clock::now();
    
    while (1) {
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - lastSentTime) >= std::chrono::seconds(1))
        {
            PrintToConsole(); 
            lastSentTime = std::chrono::system_clock::now(); 
        }
    }
}

void PrintToConsole()
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