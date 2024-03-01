#include <stdio.h>
#include <windows.h>
#include <Wincrypt.h>
#include <stdio.h>
#pragma comment(lib, "advapi32.lib")

int main()
{
    DWORD dwIndex = 3;
    DWORD dwFlags = 0;
    DWORD pdwProvType;
    DWORD cbProvName = 100; // Пример размера буфера для имени провайдера
    LPSTR szProvName = (LPSTR)malloc(cbProvName * sizeof(CHAR)); // Выделяем память для имени провайдера
    
    int a = CryptEnumProvidersA(dwIndex, NULL, dwFlags, &pdwProvType, szProvName, &cbProvName);

    if (a)
    {
        printf("Provider Type: %d\n", pdwProvType);
        printf("Provider Name: %s\n", szProvName);
    }
    else
    {
        printf("Error %d\n", GetLastError());
    }

    free(szProvName); // Освобождаем память после использования

    return 0;
}