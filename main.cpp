#include <iostream>
#include <wx/wx.h>
#include <gtest/gtest.h>
#include "GUI classes/StartFrame.h"
#include "classes/Application.h"

/// Inicjuje bibliotekę graficzną
class MainpApp : public wxApp{
    /// Wywyoływana w momencie uruchomienia aplikacji. Wyświetla startowe okno programu.
    bool OnInit(){

        //Próba wyświetlenia w konsoli podstawowych metod
        Profile* prof1 = new Profile(nullptr, nullptr,"___TEST PROFILE___");
        prof1->addDirectories("/Users/raftry/Desktop/[ZPR]/testFolder1", "/Users/raftry/Desktop/[ZPR]/testFolder2",1,2);
        prof1->summary();

        delete prof1;

        wxPoint pos;
        start_frame_ = new StartFrame(pos);
        start_frame_->Show(true);
        return true;
    }
    StartFrame* start_frame_;
};

wxIMPLEMENT_APP(MainpApp);
