Although not the most dentrimental part of the source code, in a 
repo containing the Zeus source code this block minimally shows 
the entry point to the windows core API was created and giving 
root permission

```
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
```

A similar version of this code I ran on my machine running linux, 
was able to give me root permissions as a regular user. 
See here (maybe it works for you):

```
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

```

The bot has went thru many stages and versions with earlier versions 
of the bug had executable files hardcoded to one of these files
```
ntos.exe
oembios.exe
twext.exe
```
date being stored in the folowing dirs 
```
System>\wsnpoem 
System>\sysproc64
System>\twain_32
```
the next iteration and stored files in a single directory later found 
by security researchers, with another version storing executables in 
randomly named folders in app data.

The bot executes in the following stages

- Builder
This malware comes in a kit usable by regular users with no technical 
knowledge, meaning the "owner" must deploy their own executables to who
they wish to infect. This is done easily by using the builder in the tool
kit. Each build will be unique to the infectee, due to some cryptographic 
implementations, there are uniquie keys generated for the configuration file
embedded into the built .exe. 

- Configuration
Seperate from the build stage, contains the address to where the sniffed data
is sent to in a series of blocks enables customization and hardcoding settings
into the final binary. The config includes these sections: 
```
StaticConfig 
DynamicConfig
KeyLogger
WebFilters
WebDataFilters
WebFakes
```
Static and Dynamic Config both are dealing with the hardcoding of settings
that eventually get executed at runtime. Here the questions of what is the
target and destination get answered. In addition to the 

Example of the config.txt file used to initate
seen here: https://github.com/touyachrist/evo-zeus/blob/master/output/builder/config.txt






