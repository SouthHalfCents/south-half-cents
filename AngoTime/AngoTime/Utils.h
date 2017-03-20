#pragma once
#include "Database.h"
#include <string>

//工具类
class CUtils
{
public:
	CUtils();
	~CUtils();

	static int TranDayweekToInt(int nDayofWeek, int & nDayValue);			//把dayofweek转为DAY_MONDAY的值

	static	CString 	GetAppDir();								//获得应用程序的当前目录路径
	static	CString 	FileNameFromPath(CString strPath);			//从文件路径提取文件名称

	static	BOOL    	FileExist(LPCTSTR   pszFileName);			//检查文件是否存在
	static	BOOL		IsFileType(LPCTSTR lpsz, LPCTSTR lpszType); //检查文件是否为指定类型（lpszType为后缀名）

	static	std::string	GBK_UTF8(string& strMsg);///< 将GBK字符串转化为UTF8编码
	static	std::string	GBK_UTF8(char* strMsg);
	static	std::string	UTF8_GBK(string& strMsg);///< 将UTF8编码转化为GBK编码
	static	std::string	UTF8_GBK(char* strMsg);
};

