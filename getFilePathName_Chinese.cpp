#include <windows.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(){

	/*char str[1024];
	memset(str, 0, 1024);
	
	WCHAR file[100];
	wmemset(file, 0, 1024);

	::OpenClipboard(0);
	int filename_id = 0;
	if (!filename_id) filename_id = RegisterClipboardFormat("FileName");

	if (IsClipboardFormatAvailable(filename_id)){

		
		/*HANDLE hClipMemory = ::GetClipboardData(filename_id);// 获取剪贴板数据句柄
		DWORD dwLength = GlobalSize(hClipMemory); // 返回指定内存区域的当前大小
		printf("size:%d\n", dwLength);
		LPWSTR lpClipMemory = (LPWSTR)GlobalLock(hClipMemory); // 锁定内存
		memcpy(str, lpClipMemory, dwLength);

		HANDLE hData = ::GetClipboardData(filename_id);
		char * pszText = static_cast<char*>(GlobalLock(hData));
		GlobalUnlock(hData);

	}
	printf("%s\n", str);
	
	::CloseClipboard();*/




	OpenClipboard(nullptr);
	//UINT clipboarFormat = RegisterClipboardFormat(L"FileName");
	UINT clipboarFormat = RegisterClipboardFormatW(L"FileNameW");
	HANDLE hData = GetClipboardData(clipboarFormat);
	//DWORD dwLength = GlobalSize(hData);

	LPWSTR lpClipMemory = (LPWSTR)GlobalLock(hData);

	WCHAR str[1024];
	wcscpy(str, lpClipMemory);

	//char * pszText = static_cast<char*>(GlobalLock(hData));
	GlobalUnlock(hData);
	CloseClipboard();

	
	

	system("pause");



}




/*
	//HWND hWnd = GetSafeHwnd(); // 获取安全窗口句柄
	//::OpenClipboard(hWnd); // 打开剪贴板
	::OpenClipboard(0);
	HANDLE hClipMemory = ::GetClipboardData(CF_TEXT);// 获取剪贴板数据句柄
	DWORD dwLength = GlobalSize(hClipMemory); // 返回指定内存区域的当前大小
	LPBYTE lpClipMemory = (LPBYTE)GlobalLock(hClipMemory); // 锁定内存
	//char str[1024];
	//memcpy(str, lpClipMemory, 1024);
	printf("%d\n", strlen((const char *)lpClipMemory));
	printf("%s\n", lpClipMemory);
	GlobalUnlock(hClipMemory); // 内存解锁
	::CloseClipboard(); // 关闭剪贴板
*/

//::OpenClipboard(0);
//if (IsClipboardFormatAvailable(CF_UNICODETEXT))
//{
//	//取出数据  
//	HGLOBAL hg = GetClipboardData(CF_UNICODETEXT);
//	DWORD dwLength = GlobalSize(hg);
//	//锁定内存块  
//	LPWSTR wstr = (LPWSTR)GlobalLock(hg);
//
//	//printf("%d\n", strlen((const char *)wstr));
//	printf("%s\n", wstr);
//
//	WCHAR str[1024];
//	wmemcpy(str, wstr, dwLength);
//	str[dwLength] = 0;
//
//	GlobalUnlock(hg);
//
//	wprintf(L"%s\n", str);
//}
//CloseClipboard();

