#include "gtkmm/application.h"
#include "gtkmm/box.h"
#include "gtkmm/widget.h"
#ifndef MAIN_VIEW
#define MAIN_VIEW

class MainView : public Gtk::Box {
public:
  MainView(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window);
};

#endif