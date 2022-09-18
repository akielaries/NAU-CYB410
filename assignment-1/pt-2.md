Although not the most dentrimental part of the source code, in a 
repo containing the Zeus source code this block minimally shows 
the entry point to the windows core API was created and giving 
root permission

void WINAPI entryPoint(void)
{
  Mem::init();
  Console::init();  
  Crypt::init();
  Core::init();
  
  CUI_DEFAULT_COMMANDLINE_HELPER;

  Core::uninit();
  Crypt::uninit();
  Console::uninit();
  Mem::uninit();
  
  CWA(kernel32, ExitProcess)(coreData.exitCode);
}


A similar version of this code I ran on my machine running linux, 
was able to give me root permissions as a regular user. 
See here (maybe it works for you):

int getuid(){
    return 0;
}
int geteuid(){
    return 0;
}
int getgid(){
    return 0;
}
int getegid(){
    return 0;
}


