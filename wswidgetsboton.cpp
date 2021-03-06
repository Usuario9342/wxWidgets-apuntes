#include <wx/wx.h>

const int ID_PLUS = 101;
//defino un id personalizado para el segundo boton.

/*

la idea de este codigo es hacer una ventana que contenga dos botones simples.
uno de los botones sale de la aplicacion (como aparecen en los tutoriales)
El otro boton cambia el color de el fondo de la ventana (lo hice para practicar);

*/




class Button : public wxFrame
{
public:
    Button(const wxString& title);
    void OnButtonClick(wxCommandEvent& event);
    void OnQuit(wxCommandEvent & event);
};

class MyApp : public wxApp{
  public:
    virtual bool OnInit();
};

//implemetacion de button hereda los metodos de wxframe


Button::Button(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 150)){
  
  
  
  //creamos el objeto panel en memoria         
  wxPanel *panel = new wxPanel(this, wxID_ANY);
    //creamos el objeto boton en memoria y lo asignamos al panel
  wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(30, 20));
  wxButton *button2 = new wxButton(panel, ID_PLUS, wxT("color"), wxPoint(30, 60));

      //wxpoint con esto disponemos en que parte de la ventana va el boton
      //wxt es el label del boton
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Button::OnQuit));
  Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Button::OnButtonClick));
  //conectamos el boton y el metodo onclic
  
  //button->SetFocus();
  //con esto conectamos el teclado y el boton, si apretamos enter el boton se activa
  
  Centre();
  //centramos la ventana
}

void Button::OnQuit(wxCommandEvent & WXUNUSED(event)){
    //el metodo onQuit cierra la app invocando el metodo close.
    Close(true);
}

bool MyApp::OnInit(){

    //con esto creamos la ventana en memoria
    Button *btnapp = new Button(wxT("Button"));
    btnapp->Show(true);

    return true;
}

void Button::OnButtonClick(wxCommandEvent& WXUNUSED(event)){
    
    static bool click;
    wxButton* botonColor;
	botonColor = (wxButton*)this->FindWindowById(wxID_EXIT);
/*
Aqui algo interesante, para seleccionar un control(en este caso un boton) dentro del arbol de la app
tenemos tres metodos, pero el que usé es buscarlo por el ID.
primero hago un puntero del tipo del control que busco(boton) y luego busco la ID en el objeto raiz
"el que señala el puntero this" y lo casteo (wxLOQUESEA*)
*/

//este bloque te codigo lo que hace es cambiar ternariamente el color cuando se clickea un boton

    if(click){
        click = false;
        //luego uso mi puntero para acceder a los metodos que heredó en este caso SetBackgroundColour
        //y le cargo el color.	    
        botonColor->SetBackgroundColour(wxColour(*wxLIGHT_GREY));   
        this->SetBackgroundColour(*wxBLUE);
        this->SetForegroundColour(*wxRED);
    }else{
        click = true;
        botonColor->SetBackgroundColour(wxColour(*wxYELLOW));
        this->SetBackgroundColour(*wxRED);
        this->SetForegroundColour(*wxBLUE);
    }
    
}

IMPLEMENT_APP(MyApp);