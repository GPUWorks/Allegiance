//-----------------------------------------------------------------------------
// File: DXVer.cpp
//
// Desc: Windows code that calls GetDXVersion and displays the results.
//
// (C) Copyright Microsoft Corp.  All rights reserved.
//-----------------------------------------------------------------------------
#include <windows.h>
#include <strsafe.h>
#include <stdio.h>
#pragma warning(disable: 4005 4995)
#include <tchar.h>
#pragma warning(default: 4005 4995)




//-----------------------------------------------------------------------------
// External function-prototypes
//-----------------------------------------------------------------------------
extern HRESULT GetDXVersion( DWORD* pdwDirectXVersion, TCHAR* strDirectXVersion, int cchDirectXVersion );





//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: Entry point to the program. Initializes everything, and pops
//       up a message box with the results of the GetDXVersion call
//-----------------------------------------------------------------------------
int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR strCmdLine, int nCmdShow )
{
    HRESULT hr;
    TCHAR strResult[128];

    DWORD dwDirectXVersion = 0;
    TCHAR strDirectXVersion[10];

    hr = GetDXVersion( &dwDirectXVersion, strDirectXVersion, 10 );
    if( SUCCEEDED(hr) )
    {
        if( dwDirectXVersion > 0 )
            StringCchPrintf( strResult, 128, TEXT("DirectX %s installed"), strDirectXVersion );
        else
            StringCchCopy( strResult, 128, TEXT("DirectX not installed") );
    }
    else
    {
        StringCchPrintf( strResult, 128, TEXT("Unknown version of DirectX installed") );
    }

    MessageBox( NULL, strResult, TEXT("DirectX Version:"), MB_OK | MB_ICONINFORMATION );
    
    return 0;
}


