#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    //Get program path information
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath_s(argv[0], drive, sizeof(drive), dir, sizeof(dir), fname, sizeof(fname), ext, sizeof(ext));
    //Splice command
    string ch_body = "";
    ch_body = fname;

    int count = 1;
    long length = 0;
    for (count; count < argc; ++count) {
        string ch_tmp = " ";
        ch_tmp += argv[count];
        ch_body += ch_tmp;
    }

    string ch_head = "bash.exe -c \"";
    string ch_tail = "\"";
    string ch = "";
    ch += ch_head;
    ch += ch_body;
    ch += ch_tail;
    //Forward command
    const char* ch_out;
    ch_out = ch.c_str();
    system(ch_out);

    return 0;
}
