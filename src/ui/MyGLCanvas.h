#pragma once

#include <GL/glew.h>
#include <wx/glcanvas.h>
#include <glm/glm.hpp>

class MyGLCanvas : public wxGLCanvas {

private:

    // pointer to rendering context - needed for OpenGL!
    wxGLContext* gl_context{ nullptr };

    // flags to set when setup complete
    bool is_gl_initialised{ false };
    

public: // Public interface

    MyGLCanvas(wxWindow* parent, int id, const wxGLAttributes& canvasAttrs, const wxGLContextAttrs& contextAttrs, wxPoint position, wxSize size);

    // Event handling
    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
	void OnMouseWheel(wxMouseEvent& event);
    void updateState(float timeDelta);
    void renderScene();
};