
// Labs6Sente.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLabs6SenteApp:
// Сведения о реализации этого класса: Labs6Sente.cpp
//

class CLabs6SenteApp : public CWinApp
{
public:
	CLabs6SenteApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLabs6SenteApp theApp;
