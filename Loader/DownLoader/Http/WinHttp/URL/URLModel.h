#pragma once
#include <string>
using std::wstring; 

/*URL_COMPONENTS              //URL组成结构体

  DWORD   dwStructSize;       // size of this structure. Used in version check
  LPWSTR  lpszScheme;         // pointer to scheme name
  DWORD   dwSchemeLength;     // length of scheme name
  INTERNET_SCHEME nScheme;    // enumerated scheme type (if known)
  LPWSTR  lpszHostName;       // pointer to host name
  DWORD   dwHostNameLength;   // length of host name
  INTERNET_PORT nPort;        // converted port number
  LPWSTR  lpszUserName;       // pointer to user name
  DWORD   dwUserNameLength;   // length of user name
  LPWSTR  lpszPassword;       // pointer to password
  DWORD   dwPasswordLength;   // length of password
  LPWSTR  lpszUrlPath;        // pointer to URL-path
  DWORD   dwUrlPathLength;    // length of URL-path
  LPWSTR  lpszExtraInfo;      // pointer to extra information (e.g. ?foo or #foo)
  DWORD   dwExtraInfoLength;  // length of extra information
*/

namespace DownLoader {

	/*@class
	*************************************************************************
	模块: WinHttp
	文件: URLModel.h
	功能: URL Model
	作者: Aijiawei  2021/04/19
	************************************************************************/
	class CURLModel
	{
	public:
		CURLModel();
		~CURLModel();

		void Init();
		void Reset();
		void Release();

	public:
		wstring GetSchemeName();
		void SetSchemeName(const wchar_t* strSchemeName);

		int GetSchemeType();
		void SetSchemeType(int nSchemeType);

		wstring GetHostName();
		void SetHostName(const wchar_t* strHostName);

		int GetPortNum();
		void SetPortNum(int nPort);

		wstring GetUserName();
		void SetUserName(const wchar_t* strUserName);

		wstring GetPassword();
		void SetPassword(const wchar_t* strPassword);

		wstring GetUrlPath();
		void SetUrlPath(const wchar_t* strUrlPath);

		wstring GetExtraInfo();
		void SetExtraInfo(const wchar_t* strExtraInfo);

	private:
		wstring m_strURL;			//URL
		wstring m_strScheme;		//Scheme name
		int     m_nSchemeType;	    //Scheme Type（HTTP、HTTPS、FTP、SOCKET）
		wstring m_strHostName;		//Host name 
		int     m_nPort;			//Port name
		wstring m_strUserName;		//User name
		wstring m_strPassword;		//Password
		wstring m_strURLPath;		//URL Path
		wstring m_strExtraInfo;		//extra information
	};
};

