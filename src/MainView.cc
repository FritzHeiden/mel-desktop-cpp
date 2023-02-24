#include "MainView.h"
#include "glibmm/refptr.h"
#include "gtkmm/application.h"
#include "gtkmm/box.h"
#include "gtkmm/button.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/window.h"
#include <iostream>

void on_click(Gtk::Window *window) {
  std::cout << "click" << std::endl;
  window->destroy();
}

MainView::MainView(Glib::RefPtr<Gtk::Application> app, Gtk::Window *window) {
  set_orientation(Gtk::Orientation::VERTICAL);
  set_spacing(10);

  auto label = new Gtk::Label("Click the button to close the window!", false);
  append(*label);

  auto button = new Gtk::Button("Click Me!", false);
  button->signal_clicked().connect(
      sigc::bind(sigc::ptr_fun(&on_click), window));
  append(*button);
}