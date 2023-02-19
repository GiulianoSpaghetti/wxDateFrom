/***************************************************************
 * Name:      wxDateCalcMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Giulio Sorrentino (gsorre84@gmail.com)
 * Created:   2022-12-14
 * Copyright: Giulio Sorrentino (https://numerone.altervista.org)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxDateFromMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(wxDateFromFrame, wxFrame)
    EVT_CLOSE(wxDateFromFrame::OnClose)
    EVT_MENU(idMenuQuit, wxDateFromFrame::OnQuit)
    EVT_MENU(idMenuAbout, wxDateFromFrame::OnAbout)
    EVT_BUTTON(ID_BUTTON_OK, wxDateFromFrame::OnOk)
    EVT_PAINT(wxDateFromFrame::OnPaint)
END_EVENT_TABLE()

wxDateFromFrame::wxDateFromFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title, wxDefaultPosition, wxSize(300,400))
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR
    config=new wxConfig("wxDateFrom");
    wxString nome;
    int giorno, mese;
    int anno;
    if (!config->Read("name", &nome))
        nome="";
    if (!config->Read("day", &giorno))
        giorno=25;
    if (!config->Read("month", &mese))
        mese=11;
    if (!config->Read("year", &anno))
        anno=2022;
    this->nome=new wxTextCtrl(this, wxID_ANY, nome);
    data=wxDateTime(giorno, static_cast<wxDateTime::Month>(mese), anno);
    wxBoxSizer *vbox=new wxBoxSizer(wxVERTICAL);
    vbox->Add(new wxStaticText(this, wxID_ANY, _("Insert the name: ")), 0, wxALL, 4);
    vbox->Add(this->nome, 0, wxALL, 4);
    calendar=new wxCalendarCtrl(this, wxID_ANY);
    calendar->SetDate(data);
    vbox->Add(new wxStaticText(this, wxID_ANY, _("Insert the date: ")), 0, wxALL, 4);
    vbox->Add(calendar, 0, wxALL, 4);
    calcola=new wxButton(this, ID_BUTTON_OK, _("Calculate"));
    wxString s=wxFileName::GetPathSeparator();
    img=new wxImage(wxGetHomeDir()+s+_("Images")+s+wxT("background.jpg"));
    vbox->Add(calcola, 0, wxALL, 4);
    SetSizer(vbox);
    Layout();
    //Fit();

}


void wxDateFromFrame::salvaData() {
    config->Write("day", data.GetDay());
    config->Write("month", static_cast<unsigned short>(data.GetMonth()));
    config->Write("year", static_cast<int>(data.GetYear()));
}

wxDateFromFrame::~wxDateFromFrame()
{
    salvaData();
    delete config;
    delete img;
}

void wxDateFromFrame::OnClose(wxCloseEvent &event)
{
    Destroy();

}

void wxDateFromFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wxDateFromFrame::OnAbout(wxCommandEvent &event)
{
	wxAboutDialogInfo info;
	info.AddDeveloper("Giulio Sorrentino <gsorre84@gmail.com>");
        info.SetCopyright("(c) 2023 Giulio Sorrentino some right reserved");
	info.SetLicense("GPL v3 o (a tua discrezione) qualsiasi versione successiva.");
        info.SetName("wxDateFrom");
        info.SetVersion("0.2");
        info.SetWebSite("https://github.com/numerunix/wxdatefrom");
    wxArrayString traduttori = wxArrayString();
    traduttori.Add("Giulio Sorrentino <gsorre84@gmail.com>");
    info.SetDescription(_("A simple program for calculating how mutch time passed from a given date."));
    info.SetTranslators(traduttori);
    #ifndef _WIN32
        info.SetIcon(wxIcon(background_xpm));
    #endif
    wxAboutBox(info);
}

void wxDateFromFrame::OnOk(wxCommandEvent &evt) {
    data=calendar->GetDate();
    wxDateTime t1=wxDateTime::Now();
    wxTimeSpan ts=t1.Subtract(data);
    if (ts.GetValue()<0) {
        wxNotificationMessage *msg = new wxNotificationMessage(_("Error"), _("Invalid lvalue"), this);
        msg->Show();
        delete msg;
        msg = NULL;
    }
    wxString giorni, ore, minuti;
    giorni.Printf("%d", ts.GetDays());
    ore.Printf("%d", ts.GetHours()%24);
    minuti.Printf("%d", ts.GetMinutes()%60);
    wxNotificationMessage *msg = new wxNotificationMessage(_("Information"), _("You met ")+nome->GetValue()+wxT(" ")+giorni+_(" days, ")+ore+_(" hours and ")+minuti+_(" minutes ago."), this);
    msg->Show();
    delete msg;

}


void wxDateFromFrame::OnPaint(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    wxCoord width, height;
   if (img->IsOk()) {
        wxImage img1=wxImage(*img);
        GetClientSize(&width, &height);
        img1.Rescale(width, height);
        dc.DrawBitmap(wxBitmap(img1), 0,0);
   }
}
