// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"

#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")

#include <helper/SAdapterBase.h>

class CTestAdapter : public SAdapterBase
{
public:
    virtual int getCount()
    {
        return 50000;
    }   

    virtual SWindow * getView(int position, SWindow * convertView, SWindow * parent)
    {
        if(convertView==NULL)
        {
            pugi::xml_document xmlDoc;
            if(LOADXML(xmlDoc,L"item_lv",L"layout"))
            {
                parent->CreateChildren(xmlDoc.root());
                parent->UpdateChildrenPosition();
                convertView=parent->GetWindow(GSW_FIRSTCHILD);       
            }
        }
        SAnimateImgWnd *pAni = convertView->FindChildByName2<SAnimateImgWnd>(L"ani_test");
        
        SButton *pBtn = convertView->FindChildByName2<SButton>(L"btn_test");
        pBtn->SetWindowText(SStringW().Format(L"button %d",position));
        pBtn->SetUserData(position);
        pBtn->GetEventSet()->subscribeEvent(EVT_CMD,Subscriber(&CTestAdapter::OnButtonClick,this));
        return convertView;
    }
    
    bool OnButtonClick(EventArgs *pEvt)
    {
        SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
        int iItem = pBtn->GetUserData();
        SMessageBox(NULL,SStringT().Format(_T("button of %d item was clicked"),iItem),_T("haha"),MB_OK);
        return true;
    }
};

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// 		MARGINS mar = {5,5,30,5};
	// 		DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	m_lstView = FindChildByName2<SListView>("lv_test");
	CTestAdapter *pAdapter = new CTestAdapter;
	m_lstView->SetAdapter(pAdapter);
	pAdapter->Release();
	return 0;
}


//TODO:消息映射
void CMainDlg::OnClose()
{
	PostMessage(WM_QUIT);
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

