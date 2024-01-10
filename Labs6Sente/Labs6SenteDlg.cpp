
// Labs6SenteDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Labs6Sente.h"
#include "Labs6SenteDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CLabs6SenteDlg



CLabs6SenteDlg::CLabs6SenteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LABS6SENTE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLabs6SenteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLabs6SenteDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD_TO_LISTBOX, &CLabs6SenteDlg::OnClickedBtnAddToListbox)
	ON_BN_CLICKED(IDC_DELETE_SELECTED, &CLabs6SenteDlg::OnClickedDeleteSelected)
	ON_BN_CLICKED(IDC_EXTRACT_SELECTED, &CLabs6SenteDlg::OnClickedExtractSelected)
	ON_BN_CLICKED(IDC_PUSH_BACK, &CLabs6SenteDlg::OnClickedPushBack)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CLabs6SenteDlg::OnClickedSearchButton)
	ON_BN_CLICKED(IDC_CLEAR, &CLabs6SenteDlg::OnClickedClear)
END_MESSAGE_MAP()


// Обработчики сообщений CLabs6SenteDlg

BOOL CLabs6SenteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLabs6SenteDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLabs6SenteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLabs6SenteDlg::OnClickedBtnAddToListbox()
{


		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN);
		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX);


		CString strText;
		pEdit->GetWindowText(strText);


		CStringArray arrWords;
		int nPos = 0;
		CString strDelimiter = _T(" ");
		CString strToken = strText.Tokenize(strDelimiter, nPos);
		while (!strToken.IsEmpty())
		{
			arrWords.Add(strToken);
			strToken = strText.Tokenize(strDelimiter, nPos);
		}


		pListBox->ResetContent();

		for (int i = 0; i < arrWords.GetSize(); i++)
		{
			pListBox->AddString(arrWords.GetAt(i));
		}
	
}


void CLabs6SenteDlg::OnClickedDeleteSelected()
{


		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX);


		int nSelectedCount = pListBox->GetSelCount();
		if (nSelectedCount == LB_ERR)
			return;


		CArray<int, int> arrSelectedIndex;
		arrSelectedIndex.SetSize(nSelectedCount);


		pListBox->GetSelItems(nSelectedCount, arrSelectedIndex.GetData());

		for (int i = nSelectedCount - 1; i >= 0; i--)
		{
			pListBox->DeleteString(arrSelectedIndex[i]);
		}
	
}


void CLabs6SenteDlg::OnClickedExtractSelected()
{

	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX);
	CEdit* pEditCell = (CEdit*)GetDlgItem(IDC_EDIT_MAIN);

	nIndex = pListBox->GetCurSel();
	if (nIndex != LB_ERR)
	{
		// Получаем текст выделенной ячейки
		CString strCellText;
		pListBox->GetText(nIndex, strCellText);

		// Устанавливаем текст в Edit
		pEditCell->SetWindowText(strCellText);
	}
}


void CLabs6SenteDlg::OnClickedPushBack()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX);
	CEdit* pEditCell = (CEdit*)GetDlgItem(IDC_EDIT_MAIN);
	CString strModifiedText;
	pEditCell->GetWindowText(strModifiedText);

	if (nIndex != LB_ERR)
	{
		pListBox->DeleteString(nIndex);
		pListBox->InsertString(nIndex, strModifiedText);
	}
}


void CLabs6SenteDlg::OnClickedSearchButton()
{

		CEdit* pEditSearch = (CEdit*)GetDlgItem(IDC_SEARCH_EDIT);
		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX);

		CString strSearchText;
		pEditSearch->GetWindowText(strSearchText);


		pListBox->SetSel(-1, FALSE);

		int nIndex = pListBox->FindStringExact(-1, strSearchText);
		if (nIndex != LB_ERR)
		{
			pListBox->SetSel(nIndex, TRUE);
		}
}



void CLabs6SenteDlg::OnClickedClear()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_MAIN);

	// Устанавливаем пустую строку в качестве текста элемента Edit
	pEdit->SetWindowText(_T(""));
}
