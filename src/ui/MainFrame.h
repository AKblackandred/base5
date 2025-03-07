#ifndef MAIN_FRAME_H_
#define MAIN_FRAME_H_

#include <wx/wx.h>

class MainFrame: public wxFrame // MainFrame is the class for our window, 
{ 
	// It contains the window and all objects in it 
public: 
	MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size); 
}; 

#endif