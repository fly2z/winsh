#include "ls.h"

#include <dirent.h>
#include <stdio.h>
#include <tchar.h>
#include <wchar.h>
#include <windows.h>

void ls_command() {
  WIN32_FIND_DATA find_data;
  HANDLE hFind;
  TCHAR search_path[MAX_PATH];

  // Prepare the search path to list all files and directories
  _tcscpy(search_path, _T("*"));

  hFind = FindFirstFile(search_path, &find_data);
  if (hFind == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error opening directory.\n");
    return;
  }

  // Print header
  _tprintf(_T("%-30s %-12s %-20s\n"), _T("Name"), _T("Type"),
           _T("Last Modified"));

  do {
    // Skip . and ..
    if (_tcscmp(find_data.cFileName, _T(".")) == 0 ||
        _tcscmp(find_data.cFileName, _T("..")) == 0)
      continue;

    // Print file/directory name
    _tprintf(_T("%-30s "), find_data.cFileName);

    // Print file type
    if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
      _tprintf(_T("Directory   "));
    else
      _tprintf(_T("File        "));

    // Print last modified time
    FILETIME last_write_time = find_data.ftLastWriteTime;
    SYSTEMTIME sys_time;
    FileTimeToSystemTime(&last_write_time, &sys_time);
    _tprintf(_T("%04d-%02d-%02d %02d:%02d:%02d\n"), sys_time.wYear,
             sys_time.wMonth, sys_time.wDay, sys_time.wHour, sys_time.wMinute,
             sys_time.wSecond);

  } while (FindNextFile(hFind, &find_data) != 0);

  FindClose(hFind);
}