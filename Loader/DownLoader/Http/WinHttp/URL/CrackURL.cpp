#pragma once
#include "CrackURL.h"
#include "../../Common/ErrorCode.h"


namespace DownLoader{

	CCrackURL* CCrackURL::m_pInstance = nullptr;

	CCrackURL* CCrackURL::GetInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_pInstance = new CCrackURL();
		}

		return m_pInstance;
	}

	CCrackURL::CCrackURL()
	{
		m_strURL = L"";
		m_pURLModel = nullptr;
	}

	CCrackURL::~CCrackURL()
	{
		if (m_pURLModel)
			m_pURLModel->Release();
	}

	unsigned long CCrackURL::CrackURL( const wchar_t* strURL)
	{
		// aviod the parameter is null
		if (nullptr == strURL)
		{
			return ERROR_PARAMS_IS_NULL;
		}

		// avoid crackering the same url
		if (0 != wcscmp(strURL,m_strURL.c_str()))
		{
			if (FAIL == OnCrackURL(strURL))
			{
				return ERROR_URL_IS_INVALID;
			}
		}

		return SUCCESS;
	}

	CURLModel * CCrackURL::GetModel()
	{
		return m_pURLModel;
	}

	unsigned long CCrackURL::OnCrackURL( const wchar_t* strURL )
	{
		unsigned long   dwResult = FAIL;
		URL_COMPONENTS  url_component = {0};

		url_component.dwStructSize = sizeof(url_component);
		url_component.dwExtraInfoLength = (DWORD)-1;	
		url_component.dwHostNameLength  = (DWORD)-1;
		url_component.dwUserNameLength  = (DWORD)-1;
		url_component.dwPasswordLength  = (DWORD)-1;
		url_component.dwSchemeLength    = (DWORD)-1;
		url_component.dwUrlPathLength   = (DWORD)-1;

		if (::WinHttpCrackUrl(strURL,(DWORD)wcslen(strURL),0,&url_component))
		{
			// if model is null, new it, otherwise reset it
			if (nullptr == m_pURLModel)
				m_pURLModel = new CURLModel();
			else
				m_pURLModel->Reset();

			// fill model
			if (m_pURLModel)
			{
				m_pURLModel->SetSchemeName(url_component.lpszScheme);
				m_pURLModel->SetSchemeType(url_component.nScheme);
				m_pURLModel->SetHostName(url_component.lpszHostName);
				m_pURLModel->SetPortNum(url_component.nPort);
				m_pURLModel->SetUserName(url_component.lpszUserName);
				m_pURLModel->SetPassword(url_component.lpszPassword);
				m_pURLModel->SetUrlPath(url_component.lpszUrlPath);
				m_pURLModel->SetExtraInfo(url_component.lpszExtraInfo);

				dwResult = SUCCESS;
			}
		}

		return dwResult;
	}

};
