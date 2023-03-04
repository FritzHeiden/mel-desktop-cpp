#ifndef SIDE_BAR
#define SIDE_BAR

#include "gtkmm/application.h"
#include "gtkmm/box.h"
class SideBar : public Gtk::Box {
public:
  SideBar(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window);
};

#endif