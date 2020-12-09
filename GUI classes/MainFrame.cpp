//
// Created by kddny on 21.11.2020.
//

#include "MainFrame.h"
#include "StartFrame.h"

using namespace std;

MainFrame::MainFrame(wxPoint pos, int index)
        : profile_(Application::getProfiles().at(index)) ,wxFrame(nullptr, wxID_ANY, "Uniklon", pos, wxSize(800,600) ) {
    profile_->summary();
    profile_->printTree1();
    profile_->printTree2();

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxMenuBar *menuBar = new wxMenuBar;
    wxMenu *file = new wxMenu;
    wxMenu *help = new wxMenu;
    file->Append(1, wxT("&Zmień Profil"));
    file->Append(wxID_ANY,wxT("&Skanuj"));
    file->Append(wxID_ANY,wxT("&Synchronizuj"));
    file->Append(wxID_ANY,wxT("&Zmień kierunek"));
    file->Append(wxID_ANY, wxT("&Wyjście"));
    help->Append(wxID_ANY,wxT("&O Programie"));
    menuBar->Append(file, wxT("&Synchronizacja"));
    menuBar->Append(help,wxT("&Pomoc"));
    SetMenuBar(menuBar);

    vbox->Add(-1,10);

    wxBoxSizer *mainHbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *vbox1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *vbox2 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *vbox3 = new wxBoxSizer(wxVERTICAL);
    wxStaticText *st1 = new wxStaticText(this, wxID_ANY, wxT("Pierwszy katalog"));
    wxStaticText *st2 = new wxStaticText(this, wxID_ANY, wxT("Akcja"));
    wxStaticText *st3 = new wxStaticText(this, wxID_ANY, wxT("Drugi katalog"));
    lb1_ = new wxListBox(this, wxID_ANY);
    lb2_ = new wxListBox(this, wxID_ANY);
    wxListBox *lb3 = new wxListBox(this, wxID_ANY);
    vbox1->Add(st1);
    vbox1->Add(lb1_, 1, wxEXPAND, 10);
    vbox2->Add(st2);
    vbox2->Add(lb2_, 1, wxEXPAND, 10);
    vbox3->Add(st3);
    vbox3->Add(lb3,1,wxEXPAND,10);
    mainHbox->Add(vbox1,0, wxLEFT | wxBOTTOM | wxEXPAND, 10);
    mainHbox->Add(vbox2,0, wxLEFT | wxBOTTOM | wxEXPAND, 10);
    mainHbox->Add(vbox3,0, wxLEFT | wxBOTTOM | wxEXPAND, 10);

    vbox->Add(mainHbox,1,wxTOP | wxLEFT , 10);
    this->SetSizer(vbox);

    Centre();

    updateLb();

    Connect(1, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::changeProfileClicked));
}

void MainFrame::changeProfileClicked(wxCommandEvent &event){
    this->Close(true);
    wxPoint pos = this->GetPosition();
    StartFrame *startFrame = new StartFrame(pos);
    startFrame->Show(true);
}

void MainFrame::updateLb() {
    lb1_->Clear();
    lb2_->Clear();
}

