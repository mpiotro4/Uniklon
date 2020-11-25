//
// Created by kddny on 20.11.2020.
//

#include "ProfileDialog.h"

ProfileDialog::ProfileDialog()
        : wxFrame(nullptr, wxID_ANY, "Uniklon", wxPoint(30,30), wxSize(400,200) ) {
    SetSizer(getFirstSizer());
}

wxSizer* ProfileDialog::getFirstSizer(){
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *st1 = new wxStaticText(this, wxID_ANY, wxT("Wprowadź nazwe:"));
    wxTextCtrl *tc = new wxTextCtrl(this, wxID_ANY);
    hbox1->Add(st1, 0, wxRIGHT, 8);
    hbox1->Add(tc, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    vbox->Add(-1,10);

    wxRadioButton *rb1 = new wxRadioButton(this, wxID_ANY,wxT("Lokalnie"), wxPoint(15, 55));
    wxRadioButton *rb2 = new wxRadioButton(this, wxID_ANY,wxT("SSH"), wxPoint(15, 80));
    vbox->Add(rb1);
    vbox->Add(rb2);

    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxButton *btn1 = new wxButton(this, 1, wxT("Dalej"));
    wxButton *btn2 = new wxButton(this, 2, wxT("Anuluj"));
    hbox2->Add(btn2, 0, wxLEFT | wxBOTTOM , 5);
    hbox2->Add(btn1, 0);
    vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT, 10);

    Center();

    Connect(1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ProfileDialog::NextButtonClicked));
    Connect(2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ProfileDialog::closeClicked));

    return vbox;
}

wxSizer* ProfileDialog::getNextSizer(){
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *st1 = new wxStaticText(this, wxID_ANY, wxT("Sciezka do pierwszego katalogu:"));
    wxTextCtrl *tc1 = new wxTextCtrl(this, wxID_ANY);
    hbox1->Add(st1, 0, wxRIGHT, 8);
    hbox1->Add(tc1, 1);
    vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *st2 = new wxStaticText(this, wxID_ANY, wxT("Sciezka do drugiego katalogu:"));
    wxTextCtrl *tc2 = new wxTextCtrl(this, wxID_ANY);
    hbox2->Add(st2, 0,wxRIGHT, 8);
    hbox2->Add(tc2,1);
    vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    vbox->Add(-1,10);

    wxButton *btn1 = new wxButton(this, 5, wxT("Zatwierdz"));
    vbox->Add(btn1,0,wxCENTER | wxBottom,10);


    Connect(5, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ProfileDialog::ConfrimClicked));

    return vbox;
}

void ProfileDialog::NextButtonClicked(wxCommandEvent &event) {
    this->GetSizer()->Clear(true);
    this->SetSizer(getNextSizer(), true);
    Center();
    wxSize size = GetSize();
    SetSize(1000,1000);
    SetSize(size);
}

void ProfileDialog::ConfrimClicked(wxCommandEvent &event) {

    this->Close(true);
}

void ProfileDialog::closeClicked(wxCommandEvent &event){
    this->Close(true);
}