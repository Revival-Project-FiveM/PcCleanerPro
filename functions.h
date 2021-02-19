#pragma once
#include <iostream>
#include <Windows.h>

void CleanWinTemp() {
	Sleep(5);
	system("del /s /f /q c:\\windows\\temp\\*.*");
}

void CleanPrefetch() {
	Sleep(5);
	system("del /s /f /q C:\\WINDOWS\\Prefetch");

}

void CleanPrefetch() {
	Sleep(5);
	system("del /s /f /q C:\\WINDOWS\\Prefetch");

}

void CleanAppTemp() {
	Sleep(5);
	system("del /s /f /q %temp%\\*.*");

}

void ClearOther() {
	Sleep(5);
	system("deltree /y c:\\windows\\tempor~1");
	Sleep(10);
	system("deltree /y c:\windows\temp");
	Sleep(10);
	system("deltree /y c:\\windows\\tmp");
	Sleep(10);
	system("deltree /y c:\\windows\\ff*.tmp");
	Sleep(10);
	system("deltree /y c:\\windows\\history");
	Sleep(10);
	system("deltree /y c:\\windows\\history");
}

void ClearCookies() {
	Sleep(5);
	system("deltree /y c:\\windows\\cookies");
}

void ClearWinHistory() {
	Sleep(5);
	system("deltree /y c:\\windows\\history");
}

void ClearBraveTemp() {
	Sleep(5);
	system("del /s /f /q C:\\Users\\%username%\\AppData\\Local\\BraveSoftware\\Brave-Browser\\User Data\\AutofillStates");
	Sleep(10);
	system("del /s /f /q C:\\Users\\%username%\\AppData\\Local\\BraveSoftware\\Brave-Browser\\User Data\\ShaderCache");


}