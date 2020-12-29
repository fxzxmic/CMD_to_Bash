#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  //Get program path information
  char path_buffer[_MAX_PATH];
  char drive[_MAX_DRIVE];
  char dir[_MAX_DIR];
  char fname[_MAX_FNAME];
  char ext[_MAX_EXT];
  _splitpath(argv[0], drive, dir, fname, ext);
  //Splice command
  char ch[100] = "bash.exe -c \"";
  strcat_s(ch, sizeof(ch), fname);
  int count;
  for (count = 1; count < argc; ++count) {
    char ch0[100] = " ";
    strcat_s(ch0, sizeof(ch0), argv[count]);
    strcat_s(ch, sizeof(ch), ch0);
  }
  strcat_s(ch, sizeof(ch), "\"");
  //Forward command
  system(ch);
  
  return 0;
}
