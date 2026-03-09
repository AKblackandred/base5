#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

#include <wx/wx.h>

class MainFrame: public wxFrame // MainFrame is the class for our window, 
{ 
#ifdef _DEBUG

	wxLog* logger = nullptr;

#endif

private:
	// open event handler
	void OnOpen(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnWhy(wxCommandEvent& event);

	// It contains the window and all objects in it 
public: 
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size); 
}; 

#endif