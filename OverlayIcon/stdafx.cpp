// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// OverlayIcon.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

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
