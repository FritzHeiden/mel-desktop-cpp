#ifndef NAVIGATION_BAR
#define NAVIGATION_BAR

#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/box.h"
#include "gtkmm/window.h"

class NavigationBar : public Gtk::Box {
public:
  NavigationBar(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window);
};

#endif