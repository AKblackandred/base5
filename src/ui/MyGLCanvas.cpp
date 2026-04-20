
#include "MyGLCanvas.h"
#include <wx/wx.h>
#include "opengl/PrincipleAxesModel.h"
#include "opengl/ArcballCamera.h"

using namespace glm;

// simple "scene" - should be in a class of it's own :)
static PrincipleAxesModel* pa = nullptr;
static ArcballCamera* mainCamera = nullptr;


MyGLCanvas::MyGLCanvas(wxWindow* parent, int id, const wxGLAttributes& canvasAttrs, const wxGLContextAttrs& contextAttrs, wxPoint position, wxSize size) : wxGLCanvas(parent, canvasAttrs, id, position, size)
{
    // Create context using contextAttrs
    gl_context = new wxGLContext(this, nullptr, &contextAttrs);

    // Validate context before proceeding - if no context exists we can't do anything
    // else with OpenGL
    if (!gl_context->IsOK())
    {

        wxMessageBox("This sample needs an OpenGL 4.6 capable driver.",
            "OpenGL version error", wxOK | wxICON_INFORMATION, this);
        delete gl_context;
        gl_context = nullptr;
    }
    else
    {
        // First call SetCurrent or GL initialization will fail
        // Makeing a context 'current' means all subsequent operations are performed
        // on that context.
        SetCurrent(*gl_context);

        // Initialize GLEW.
        GLenum initStatus = glewInit();

        if (initStatus != GLEW_OK)
        {

            wxMessageBox("GLEW could not be initialised", "GLEW Error", wxOK | wxICON_INFORMATION, this);
            delete gl_context;
            gl_context = nullptr;
        }
        else
        {
            SetCurrent(*gl_context);

            // Report OpenGL version for info
            wxLogDebug("OpenGL version: %s", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
            wxLogDebug("OpenGL vendor: %s", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));


            // Setup event handling for canvas
            Bind(wxEVT_PAINT, &MyGLCanvas::OnPaint, this);
            Bind(wxEVT_SIZE, &MyGLCanvas::OnSize, this);

            Bind(wxEVT_LEFT_DOWN, &MyGLCanvas::OnMouseDown, this);
            Bind(wxEVT_LEFT_UP, &MyGLCanvas::OnMouseUp, this);
            Bind(wxEVT_MOTION, &MyGLCanvas::OnMouseMove, this);
			Bind(wxEVT_MOUSEWHEEL, &MyGLCanvas::OnMouseWheel, this);

            // Setup (simple) scene

            float viewportAspect = 1.0f; // default aspect - will be updated when resize event fires (see below)
            mainCamera = new ArcballCamera(0.0f, 0.0f, 15.0f, 55.0f, viewportAspect, 0.1f, 1000.0f);

            pa = new PrincipleAxesModel();

            // Setup completed successfully
            is_gl_initialised = true;
        }
    }
}

// Mouse tracking for when view / camera is being "dragged"
static bool isMouseDown = false;
static wxPoint lastMousePos;

void MyGLCanvas::OnMouseDown(wxMouseEvent& event)
{
    isMouseDown = true;

    lastMousePos = event.GetPosition();
    CaptureMouse(); // keep getting mouse events even when mouse leaves window
}

void MyGLCanvas::OnMouseUp(wxMouseEvent& event)
{
    if (HasCapture())
    {
        ReleaseMouse(); // don't need mouse events any more
    }

    isMouseDown = false;
}

void MyGLCanvas::OnMouseMove(wxMouseEvent& event)
{
    if (event.Dragging() && isMouseDown==true)
    {
        wxPoint currentPos = event.GetPosition();
        wxPoint delta = currentPos - lastMousePos;

        // Update camera
        if (mainCamera)
            mainCamera->rotateCamera((float)-delta.y, (float)-delta.x);

        lastMousePos = currentPos;
        
        // redraw the scene
        Refresh();
    }
}


void MyGLCanvas::OnMouseWheel(wxMouseEvent& event)
{
    int rotation = event.GetWheelRotation();
	//int delta = event.GetWheelDelta();
    //wxLogDebug("Mouse wheel: rotation=%d, delta=%d", rotation, delta);

    if (rotation < 0)
    {
        //zoom in
        mainCamera->scaleRadius(0.9f);
    }
    else if (rotation > 0)
    {
        //zoom out
		mainCamera->scaleRadius(1.1f);
	}

    // redraw the scene
    Refresh();
}

void MyGLCanvas::OnPaint(wxPaintEvent& event)
{
    renderScene();
}

void MyGLCanvas::renderScene()
{
    // If OpenGL hasn't been initialised then exit the function
    if (!is_gl_initialised)
        return;

    // Get the device context object and set current context
    SetCurrent(*gl_context);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Get view-projection transform as a GUMatrix4
    glm::mat4 viewMatrix = mainCamera->viewTransform();
    glm::mat4 projectionMatrix = mainCamera->projectionTransform();
    glm::mat4 T = projectionMatrix * viewMatrix;

    if (pa)
        pa->render(T);

    // Once drawing done present back buffer to the display
    SwapBuffers();
}

void MyGLCanvas::OnSize(wxSizeEvent& event)
{
    // When resizing the window we change the viewport (area of the window we draw into) as well
    // ** When using cameras, we need to change the projection matrix too.
    if (is_gl_initialised)
    {
        auto viewPortSize = event.GetSize() * GetContentScaleFactor();
        glViewport(0, 0, viewPortSize.x, viewPortSize.y);

        if (mainCamera)
        {
            mainCamera->setAspectRatio(float(viewPortSize.x) / float(viewPortSize.y));
        }
    }

    // Propagate size event up hierarchy as window etc. will need to process it
    event.Skip();
}

void MyGLCanvas::updateState(float timeDelta)
{
    // Animation etc. goes here
    if (is_gl_initialised)
    {
        static float theta = 0.0f;

        vec3 pos = pa->getPosition();
        pos.y = sinf(theta) * 2.0f;
		pa->setPosition(pos);

		theta += radians(45.0f) * timeDelta;

        // Redraw
        renderScene();
    }
}
