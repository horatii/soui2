#pragma once

class CMainDlg;

class CUIHander
{
public:
	struct student{
		TCHAR szName[100];
		TCHAR szSex[10];
		int age;
		int score;
	};

	CUIHander(CMainDlg *pMainDlg);
	~CUIHander(void);
	
	bool Evt_Test(SWindow * pSender, LPDUINMHDR pNmhdr);

protected:
	LRESULT OnInitDialog(HWND hWnd, LPARAM lParam);

	void OnDestory();

	void OnAttrReposition();
	void OnRepEditSel();
	void OnIECtrl();
	void OnDuiMenu();
	void OnBtnAniList();

	void OnTimer(UINT_PTR uEventID);

	LRESULT OnEditNotify(LPDUINMHDR pNHdr);

	LRESULT OnComboListSelChanging( LPDUINMHDR pNHdr );

	LRESULT OnComboListSelChanged(LPDUINMHDR pNHdr);

	LRESULT OnComboListItemNotify(LPDUINMHDR pNHdr);

	LRESULT OnListPredraw(LPDUINMHDR pNHdr);

	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

	LRESULT OnListBtnClick(LPDUINMHDR pNHdr);

	void OnBtnInitListClick();

	bool OnListHeaderClick(SWindow * pSender, LPDUINMHDR pNmhdr);
	
	void OnHideTestClick();

	BEGIN_MSG_MAP_EX(CUIHander)
		MSG_SOUI_NOTIFY()
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_DESTROY(OnDestory)
		MSG_WM_COMMAND(OnCommand)
		MSG_WM_TIMER(OnTimer)
	END_MSG_MAP()

	SOUI_NOTIFY_MAP_BEGIN()
		SOUI_NOTIFY_NAME_COMMAND("btn_hidetst",OnHideTestClick)
	SOUI_NOTIFY_MAP_END()	
private:
	CMainDlg * m_pMainDlg; 
};
