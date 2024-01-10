
// Labs6SenteDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLabs6SenteDlg
class CLabs6SenteDlg : public CDialogEx
{
// Создание
public:
	CLabs6SenteDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LABS6SENTE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	int nIndex;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnAddToListbox();
	afx_msg void OnClickedDeleteSelected();
	afx_msg void OnClickedExtractSelected();
	afx_msg void OnClickedPushBack();
	afx_msg void OnClickedSearchButton();
	afx_msg void OnClickedClear();
};
