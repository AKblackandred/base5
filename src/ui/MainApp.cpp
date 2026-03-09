#include "MainApp.h"
#include "MainFrame.h"

// A macro that tells wxWidgets to create an instance of our application
// - if you check what this expands too, it's essentially a replacement main and constructor. 
IMPLEMENT_APP(MainApp)  
/* Expands to -
int main(int argc, char **argv) 
{ 
    wxDisableAsserts(); 
    wxLog::SetLogLevel(wxLOG_Info); 
    return wxEntry(argc, argv); 
} 

MainApp& wxGetApp() 
{ 
    return *static_cast<MainApp*>(wxApp::GetInstance()); 
} 

wxAppConsole *wxCreateApp() 
{ 
    wxAppConsole::CheckBuildOptions("3" "." "2" " (" "wchar_t" ",compiler with C++ ABI compatible with gcc 4" ",wx containers"  ",compatible with 3.0" ")", "your program"); 
    return new MainApp; 
} 

wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction) wxCreateApp);
*/ 

bool MainApp::OnInit() 
{
	// Create an instance of our frame, or window 
	MainFrame *MainWin = new MainFrame(_("OgreSceneFileLoader"), wxDefaultPosition, wxSize(300, 200));
	MainWin->Show(true); // show the window 
	SetTopWindow(MainWin); // and finally, set it as the main window 
	return true;
} 