#ifndef MAIN_APP_H_
#define MAIN_APP_H_


#include <wx/wx.h>

class MainApp : public wxApp  // MainApp class for the application
{
public:
    // Note no constructor?

    virtual bool OnInit();
};

// This is a macro, it expands to 
/* 
extern MainApp& wxGetApp();
*/

DECLARE_APP(MainApp)

#endif