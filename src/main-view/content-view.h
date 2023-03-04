#ifndef CONTENT_VIEW
#define CONTENT_VIEW

#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/box.h"
class ContentView : public Gtk::Box {
public:
  ContentView(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window);
};

#endif