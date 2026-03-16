#include "MainFrame.h"

void MainFrame::setupMenu()
{
	// file menu
	wxMenu* fileMenu = new wxMenu();

	fileMenu->Append(wxID_OPEN, "&Open");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Exit");

	//help menu
	wxMenu* helpMenu = new wxMenu();

	helpMenu->Append(wxID_ABOUT, "&About");
	helpMenu->Append(wxID_HELP, "Wh&y");

	//attach file and help menu to the menu bar
	wxMenuBar* mainMenu = new wxMenuBar();
	mainMenu->Append(fileMenu, "&File");
	mainMenu->Append(helpMenu, "&Help");

	SetMenuBar(mainMenu);

	// setup events
	fileMenu->Bind(wxEVT_MENU, &MainFrame::OnOpen, this, wxID_OPEN);
	helpMenu->Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	helpMenu->Bind(wxEVT_MENU, &MainFrame::OnWhy, this, wxID_HELP);
}

void MainFrame::controlsExample()
{
	setupMenu();

	mainPanel = new wxPanel(this, wxID_ANY);

	//adding buttons
	bigRedButton = new wxButton(mainPanel, wxID_ANY, "Go on, give us a click, you know you wanna...", wxPoint(50, 50), wxSize(500, 250));
	wxLogDebug("Big Red Button");

	smallBlueButton = new wxButton(mainPanel, wxID_ANY, "I don't even CARE if you click me. Whatever.", wxPoint(400, 400), wxSize(600, 50));
	wxLogDebug("Small Blue Button");

	bigRedButton->Bind(wxEVT_BUTTON, &MainFrame::OnBRBClick, this);
	smallBlueButton->Bind(wxEVT_BUTTON, &MainFrame::OnSBBClick, this);

	//adding sliders
	slider = new wxSlider(mainPanel, wxID_ANY, 0, 0, 100, wxPoint(200, 400), wxSize(50, 200), wxSL_VERTICAL | wxSL_AUTOTICKS | wxSL_MIN_MAX_LABELS);

	slider->Bind(wxEVT_SCROLL_THUMBTRACK, &MainFrame::OnSliderChange, this);
	slider->Bind(wxEVT_SCROLL_CHANGED, &MainFrame::OnSliderChange, this);

	//add text box
	textField = new wxTextCtrl(mainPanel, wxID_ANY, "Type your screed in here.", wxPoint(700, 50), wxDefaultSize, wxTE_PROCESS_ENTER);

	textField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnTextEnter, this);
}

void MainFrame::sizerExample()
{
	setupMenu();

	mainPanel = new wxPanel(this, wxID_ANY);

	hSizer = new wxBoxSizer(wxHORIZONTAL);

	//adding buttons
	button1 = new wxButton(mainPanel, wxID_ANY, "Click me", wxDefaultPosition, wxDefaultSize);
	wxLogDebug("Button 1");

	button2 = new wxButton(mainPanel, wxID_ANY, "Do not click", wxDefaultPosition, wxDefaultSize);
	wxLogDebug("Button 2");

	//adding sliders
	slider = new wxSlider(mainPanel, wxID_ANY, 0, 0, 100, wxPoint(200, 400), wxSize(50, 200), wxSL_VERTICAL | wxSL_AUTOTICKS | wxSL_MIN_MAX_LABELS);

	//add text box
	textField = new wxTextCtrl(mainPanel, wxID_ANY, "Type your screed in here.", wxPoint(700, 50), wxDefaultSize, wxTE_PROCESS_ENTER);

	//bindings
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnClick1, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnClick2, this);

	slider->Bind(wxEVT_SCROLL_THUMBTRACK, &MainFrame::OnSliderChange, this);
	slider->Bind(wxEVT_SCROLL_CHANGED, &MainFrame::OnSliderChange, this);

	textField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnTextEnter, this);

	//sizer parameters
	hSizer->Add(button1, 0, wxALIGN_CENTER | wxALL, 10);
	hSizer->Add(button2, 0, wxALIGN_CENTER | wxALL, 10);
	hSizer->Add(slider, 0, wxALIGN_CENTER | wxALL, 10);
	hSizer->Add(textField, 0, wxALIGN_CENTER | wxALL, 10);

	mainPanel->SetSizer(hSizer);
}

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

	//controlsExample();
	sizerExample();
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

void MainFrame::OnBRBClick(wxCommandEvent& event)
{
	wxLogDebug("OnBRBClick");

	wxMessageBox("You clicked the big red button! Congratulations, you have no self control.", "Button Clicked", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnSBBClick(wxCommandEvent& event)
{
	wxLogDebug("OnSBBClick");
	wxMessageBox("You clicked the small blue button! It was being coy about it, but it really likes the interaction.", "Button Clicked", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnClick1(wxCommandEvent& event)
{
	wxLogDebug("OnClick1");
	wxMessageBox("You clicked the first button! Good job.", "Button Clicked", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnClick2(wxCommandEvent& event)
{
	wxLogDebug("OnClick2");
	wxMessageBox("You clicked the second button! Bad job.", "Button Clicked", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnSliderChange(wxScrollEvent& event)
{
	wxLogDebug("Slider value - %d", event.GetInt());

	wxPoint pos;
	bigRedButton->GetPosition(&pos.x, &pos.y);

	const float pi = 3.141593;
	float theta = float(event.GetInt()) / 100.0f * (2.0f * pi);

	float cx = 400.0f;
	float cy = 400.0f;
	float radius = 200.0f;

	float newX = cx + radius * cos(theta);
	float newY = cy + radius * sin(theta);

	pos.x = int(newX);
	pos.y = int(newY);

	bigRedButton->SetPosition(pos);
}

void MainFrame::OnTextEnter(wxCommandEvent& event)
{
	wxLogDebug("Text Entered - %s", event.GetString());
	smallBlueButton->SetLabel(event.GetString());
}