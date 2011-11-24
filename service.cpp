#include <windows.h>

SERVICE_STATUS_HANDLE statusHandle;
PROCESS_INFORMATION processInfo;
LPSTR commandLine;

void WINAPI ServiceMain(DWORD argc, LPTSTR* argv);

int main(int argc, char *argv[])
{
    if (argc < 2) return 0;
    commandLine = argv[1];

    // Service entry point
    SERVICE_TABLE_ENTRY table[] = {{"", ServiceMain}, {NULL, NULL}};
    StartServiceCtrlDispatcher(table);
}

void SetStatus(DWORD state)
{
    SERVICE_STATUS status = {SERVICE_WIN32_OWN_PROCESS, state, SERVICE_ACCEPT_STOP, NO_ERROR, 0, 0, 0};

    // Set allowed commands and wait time
    if ((state == SERVICE_START_PENDING) || (state == SERVICE_STOP_PENDING))
    {
        status.dwControlsAccepted = 0;
        status.dwWaitHint = 2000;
    }

    // Set status
    SetServiceStatus(statusHandle, &status);
}

void WINAPI ControlHandler(DWORD control)
{
    if (control == SERVICE_CONTROL_STOP)
    {
        SetStatus(SERVICE_STOP_PENDING);

        TerminateProcess(processInfo.hProcess, 0);
    }
}

void WINAPI ServiceMain(DWORD argc, LPTSTR* argv)
{
    // Register handler
    statusHandle = RegisterServiceCtrlHandler("", ControlHandler);
    if (statusHandle)
    {
        SetStatus(SERVICE_RUNNING);

        STARTUPINFO startupInfo;

        ZeroMemory(&startupInfo, sizeof(startupInfo));
        startupInfo.cb = sizeof(startupInfo);
        ZeroMemory(&processInfo, sizeof(processInfo));

        if (CreateProcess(NULL, commandLine, NULL, NULL, TRUE, 0, NULL, NULL, &startupInfo, &processInfo))
        {
            WaitForSingleObject(processInfo.hProcess, INFINITE);
        }

        SetStatus(SERVICE_STOPPED);
    }
}
