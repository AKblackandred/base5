#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

#include <wx/wx.h>

class MainFrame: public wxFrame // MainFrame is the class for our window, 
{ 
#ifdef _DEBUG

	wxLog* logger = nullptr;

#endif

	wxPanel* mainPanel = nullptr;
	wxBoxSizer* hSizer = nullptr;
	wxBoxSizer* cSizer = nullptr;
	wxButton* bigRedButton = nullptr;
	wxButton* smallBlueButton = nullptr;
	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;
	wxButton* tempButton = nullptr;
	wxSlider* slider = nullptr;
	wxTextCtrl* textField = nullptr;
	wxTextCtrl* tempField = nullptr;

private:
	void setupMenu();
	void controlsExample();
	void sizerExample();
	void tempSizer();

	// open event handler
	void OnOpen(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnWhy(wxCommandEvent& event);
	void OnBRBClick(wxCommandEvent& event);
	void OnSBBClick(wxCommandEvent& event);
	void OnClick1(wxCommandEvent& event);
	void OnClick2(wxCommandEvent& event);
	void OnTempConvert(wxCommandEvent& event);
	void OnSliderChange(wxScrollEvent& event);
	void OnTextEnter(wxCommandEvent& event);
	void OnTempEnter(wxCommandEvent& event);

	// It contains the window and all objects in it 
public: 
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
}; 

#endif