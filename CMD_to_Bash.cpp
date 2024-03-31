#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath_s(argv[0], drive, _countof(drive), dir, _countof(dir), fname, _countof(fname), ext, _countof(ext));

	string ch = "bash.exe -c \"\\\"\"";
	ch += fname;
	for (int i = 1; i < argc; ++i) {
		ch += " ";
		ch += argv[i];
	}
	ch += "\\\"\"\"";

	DWORD dwExitCode;
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	CreateProcess(NULL, (LPSTR)ch.c_str(), NULL, NULL, true, 0, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &dwExitCode);
	CloseHandle(pi.hProcess);

	return dwExitCode;
}
