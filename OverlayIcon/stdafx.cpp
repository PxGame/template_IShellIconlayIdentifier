// stdafx.cpp : 只包括标准包含文件的源文件
// OverlayIcon.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

void log(char *p)
{
	FILE * pfile = NULL;
	::fopen_s(&pfile, "C:\\log_atl.txt", "ab+");
	if (pfile != NULL)
	{
		::fprintf(pfile, "%s\r\n", p);
		::fclose(pfile);
	}
}
