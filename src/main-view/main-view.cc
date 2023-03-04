#include "main-view.h"
#include "content-view.h"
#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/box.h"
#include "gtkmm/button.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/widget.h"
#include "gtkmm/window.h"
#include "side-bar.h"
#include <iostream>
#include <vector>

MainView::MainView(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window) {
  set_orientation(Gtk::Orientation::HORIZONTAL);
  set_vexpand(true);
  set_hexpand(true);

  SideBar *sideBar{new SideBar(app, window)};
  append(*sideBar);

  ContentView *contentView{new ContentView(app, window)};
  append(*contentView);
}