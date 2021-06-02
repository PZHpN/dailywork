#include <Windows.h>  
#include <iostream>  
#include <cstdio>  


using namespace std;

int main()
{
	
	UINT uFormat;
	char szFormatName[80];
	LPCSTR lpFormatName;
	UINT fuFlags;
	UINT idMenuItem;
	

	if (!OpenClipboard(0))
		return 0;
	
	uFormat = EnumClipboardFormats(0);

	while (uFormat)
	{
		// Call an application-defined function to get the name 
		// of the clipboard format. 

		//lpFormatName = GetPredefinedClipboardFormatName(uFormat);

		// For registered formats, get the registered name. 

		//if (lpFormatName == NULL)
		//{

		//	// Note that, if the format name is larger than the
		//	// buffer, it is truncated. 
		//	if (GetClipboardFormatName(uFormat, szFormatName,
		//		sizeof(szFormatName)))
		//		lpFormatName = szFormatName;
		//	else
		//		lpFormatName = "(unknown)";
		//}

		if (GetClipboardFormatName(uFormat, szFormatName,
			sizeof(szFormatName)))
			lpFormatName = szFormatName;
		else
			lpFormatName = "(unknown)";

		cout << lpFormatName << endl;

		// Add a menu item for the format. For displayable 
		// formats, use the format ID for the menu ID. 
		

		uFormat = EnumClipboardFormats(uFormat);
	}
	CloseClipboard();
	getchar();

	return 0;
}