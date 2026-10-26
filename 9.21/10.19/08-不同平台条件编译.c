#ifdef _WIN32
#include <windows.h>

void show_message()
{
    MessageBox(0, "Hello from Windows!", "Test", MB_OK);
}

#elif defined(__linux__)
#include <stdio.h>

void show_message()
{
    printf("Hello from Linux!\n");
}

#else
#error "Unsupported platform"
#endif

int main()
{
    show_message();
    return 0;
}