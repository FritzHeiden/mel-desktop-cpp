#include "content-view.h"
#include "gtkmm/enums.h"
#include "navigation-bar.h"

ContentView::ContentView(Glib::RefPtr<Gtk::Application> app,
                         Gtk::Window *window) {
  set_orientation(Gtk::Orientation::VERTICAL);

  NavigationBar *navigationBar{new NavigationBar(app, window)};
  append(*navigationBar);
}