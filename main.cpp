#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[]) {
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath_s(argv[0], drive, sizeof(drive), dir, sizeof(dir), fname, sizeof(fname), ext, sizeof(ext));  //Get program path information

    string ch = "bash.exe -c \"";
    ch += fname;
    int count = 1;
    for (count; count < argc; ++count) {
        ch += " ";
        ch += argv[count];
    }
    ch += "\"";  //Splice command

    wstring widstr;
    widstr = wstring(ch.begin(), ch.end());
    LPWSTR sConLin = (LPWSTR)widstr.c_str();  //Convert string to LPWSTR

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    memset(&si, 0, sizeof(si));
    memset(&pi, 0, sizeof(pi));

    CreateProcess(NULL, sConLin, NULL, NULL, false, 0, NULL, NULL, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);  //Create and terminate child process

    return 0;
}
