#pragma once
#include "URLModel.h"

namespace DownLoader
{
	CURLModel::CURLModel()
	{
		Init();
	}

	CURLModel::~CURLModel()
	{
		
	}

	void CURLModel::Init()
	{
		m_strURL        = L"";
		m_strScheme     = L"";
		m_nSchemeType   = 0;
		m_strHostName   = L"";
		m_nPort         = 0;    
		m_strUserName   = L"";
		m_strPassword   = L"";
		m_strURLPath    = L"";
		m_strExtraInfo  = L"";
	}

	void CURLModel::Reset()
	{
		Init();
	}

	void CURLModel::Release()
	{
		delete this;
	}

	wstring CURLModel::GetSchemeName()
	{
		return m_strScheme;
	}

	void CURLModel::SetSchemeName(const wchar_t* strSchemeName)
	{
		if (strSchemeName)
			m_strScheme = strSchemeName;	
	}

	int CURLModel::GetSchemeType()
	{
		return m_nSchemeType;
	}

	void CURLModel::SetSchemeType(int nSchemeType)
	{
		m_nSchemeType = nSchemeType;
	}

	wstring CURLModel::GetHostName()
	{
		return m_strHostName;
	}

	void CURLModel::SetHostName(const wchar_t* strHostName)
	{
		if (strHostName)
			m_strHostName = strHostName;
	}

	int CURLModel::GetPortNum()
	{
		return m_nPort;
	}

	void CURLModel::SetPortNum(int nPort)
	{
		m_nPort = nPort;
	}

	wstring CURLModel::GetUserName()
	{
		return m_strUserName;
	}

	void CURLModel::SetUserName(const wchar_t* strUserName)
	{
		if (strUserName)
			m_strUserName = strUserName;
	}

	wstring CURLModel::GetPassword()
	{
		return m_strUserName;
	}

	void CURLModel::SetPassword(const wchar_t* strPassword)
	{
		if (strPassword)
			m_strPassword = strPassword;
	}

	wstring CURLModel::GetUrlPath()
	{
		return m_strURLPath;
	}

	void CURLModel::SetUrlPath(const wchar_t* strUrlPath)
	{
		if (strUrlPath)
			m_strURLPath = strUrlPath;
	}

	wstring CURLModel::GetExtraInfo()
	{
		return m_strExtraInfo;
	}

	void CURLModel::SetExtraInfo(const wchar_t* strExtraInfo)
	{
		if (strExtraInfo)
			m_strExtraInfo = strExtraInfo;
	}

}