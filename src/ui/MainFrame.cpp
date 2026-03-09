#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
: wxFrame((wxFrame *) NULL, -1, title, pos, size) 
{
	// normally we would initialize objects such as buttons and textboxes here 

#ifdef _DEBUG

	logger = new wxLogWindow(this, "Debug", true, true);
	wxLog::SetActiveTarget(logger);

#endif

	// test message
	wxLogDebug("Hello, wxWidgets! I am in your walls, eating your forgotten cheese!");

	// setup menu

	// file menu
	wxMenu* fileMenu = new wxMenu();

	fileMenu->Append(wxID_OPEN, "&Open");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Exit");

	wxMenu* helpMenu = new wxMenu();

	helpMenu->Append(wxID_ABOUT, "&About");
	helpMenu->Append(wxID_HELP, "Wh&y");

	wxMenuBar* mainMenu = new wxMenuBar();
	mainMenu->Append(fileMenu, "&File");
	mainMenu->Append(helpMenu, "&Help");

	SetMenuBar(mainMenu);

	// setup events
	fileMenu->Bind(wxEVT_MENU, &MainFrame::OnOpen, this, wxID_OPEN);
	helpMenu->Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	helpMenu->Bind(wxEVT_MENU, &MainFrame::OnWhy, this, wxID_HELP);

}

void MainFrame::OnOpen(wxCommandEvent& event) 
{
	wxLogDebug("Open Option Pressed");

	wxFileDialog openDialog(this, "Open Scene File", "", "", "*.scene", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	auto result = openDialog.ShowModal();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxLogDebug("About Option Pressed");
	
	wxMessageBox("GherkinHammer SceneFileLoader v1.1, © Gherkin Hammer Studios 2026.", "About SceneFileLoader", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnWhy(wxCommandEvent& event)
{
	wxLogDebug("Why");

	wxMessageBox("Why", "Why", wxOK | wxICON_INFORMATION);
}
