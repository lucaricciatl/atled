#ifdef _WIN32
#include "screenshot_util.hpp"
#include <iostream>
#include <windows.h>

// Helper function to save an HBITMAP as a BMP file.
bool SaveBMP(const char* filename, HBITMAP hBitmap, HDC hdc) {
    BITMAP bmp;
    if (!GetObject(hBitmap, sizeof(BITMAP), &bmp)) {
        std::cerr << "GetObject failed." << std::endl;
        return false;
    }

    BITMAPINFOHEADER bi;
    ZeroMemory(&bi, sizeof(bi));
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = bmp.bmWidth;
    bi.biHeight = bmp.bmHeight;
    bi.biPlanes = 1;
    bi.biBitCount = 32;  // Request 32-bit
    bi.biCompression = BI_RGB;
    // Calculate the size of the image data
    int lineBytes = ((bmp.bmWidth * bi.biBitCount + 31) / 32) * 4;
    DWORD bmpSize = lineBytes * bmp.bmHeight;
    // Allocate buffer for the bitmap data
    char* lpBits = new char[bmpSize];
    if (!lpBits) {
        std::cerr << "Memory allocation failed for bitmap data." << std::endl;
        return false;
    }
    BITMAPINFO biInfo;
    biInfo.bmiHeader = bi;
    // Get the bits from the bitmap
    if (!GetDIBits(hdc, hBitmap, 0, bmp.bmHeight, lpBits, &biInfo, DIB_RGB_COLORS)) {
        std::cerr << "GetDIBits failed." << std::endl;
        delete[] lpBits;
        return false;
    }
    // Create a file to save the bitmap
    HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create file for writing." << std::endl;
        delete[] lpBits;
        return false;
    }
    BITMAPFILEHEADER bmfh;
    bmfh.bfType = 0x4D42;  // 'BM'
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + bmpSize;
    bmfh.bfReserved1 = 0;
    bmfh.bfReserved2 = 0;
    DWORD written = 0;
    if (!WriteFile(hFile, &bmfh, sizeof(bmfh), &written, NULL)) {
        std::cerr << "Failed to write file header." << std::endl;
        CloseHandle(hFile);
        delete[] lpBits;
        return false;
    }
    if (!WriteFile(hFile, &bi, sizeof(bi), &written, NULL)) {
        std::cerr << "Failed to write info header." << std::endl;
        CloseHandle(hFile);
        delete[] lpBits;
        return false;
    }
    if (!WriteFile(hFile, lpBits, bmpSize, &written, NULL)) {
        std::cerr << "Failed to write bitmap data." << std::endl;
        CloseHandle(hFile);
        delete[] lpBits;
        return false;
    }
    CloseHandle(hFile);
    delete[] lpBits;
    return true;
}

void WinScreenshot(const char* filename) {
    // Windows implementation using Win32 GDI
    // Get the desktop window and its device context.
    HWND hwndDesktop = GetDesktopWindow();
    HDC hdcScreen = GetDC(hwndDesktop);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    // Get the dimensions of the desktop.
    RECT rc;
    GetClientRect(hwndDesktop, &rc);
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;
    // Create a compatible bitmap.
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, width, height);
    if (!hBitmap) {
        std::cerr << "Failed to create compatible bitmap." << std::endl;
        ReleaseDC(hwndDesktop, hdcScreen);
        DeleteDC(hdcMem);
        return;
    }
    // Select the bitmap into the memory DC.
    HGDIOBJ old_obj = SelectObject(hdcMem, hBitmap);
    // Capture the screen
    if (!BitBlt(hdcMem, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY)) {
        std::cerr << "BitBlt failed." << std::endl;
    } else {
        // Now save the bitmap to file
        if (SaveBMP(filename, hBitmap, hdcScreen))
            std::cout << "Screenshot captured and saved successfully (Windows) with filename: " << filename
                      << std::endl;
        else
            std::cerr << "Failed to save screenshot as BMP." << std::endl;
    }
    // Cleanup
    SelectObject(hdcMem, old_obj);
    DeleteObject(hBitmap);
    DeleteDC(hdcMem);
    ReleaseDC(hwndDesktop, hdcScreen);
}
#endif