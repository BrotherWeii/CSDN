#pragma once
#include "URLModel.h"


namespace DownLoader{

	/*@class
	*******************************************************************
	模块:  WinHttp
	文件:  CrackURL.h
	功能:  Parse URL
	作者:  Aijiawei 2021/04/22
	*******************************************************************/
	class CCrackURL
	{
	private:
		CCrackURL();
		CCrackURL(CCrackURL&){};
		CCrackURL& operator=(CCrackURL&){};
		~CCrackURL();

	public:
		static CCrackURL* GetInstance();
		
	public:
		unsigned long CrackURL(const wchar_t* strURL);
		CURLModel* GetModel();

	private:
		unsigned long OnCrackURL(const wchar_t* strURL);

	private:
		static CCrackURL* m_pInstance;

	private:
		wstring    m_strURL;    //URL
		CURLModel* m_pURLModel; //URL Model
	};
}