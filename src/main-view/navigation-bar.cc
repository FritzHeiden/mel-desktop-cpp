#include "navigation-bar.h"
#include "gtkmm/box.h"
#include "gtkmm/button.h"
#include "gtkmm/enums.h"
#include "gtkmm/searchentry.h"

NavigationBar::NavigationBar(Glib::RefPtr<Gtk::Application> app,
                             Gtk::Window *window) {
  set_orientation(Gtk::Orientation::HORIZONTAL);
  set_margin(20);
  set_homogeneous(true);
  set_hexpand(true);

  Gtk::Box *leftBox{new Gtk::Box()};
  leftBox->set_halign(Gtk::Align::START);
  append(*leftBox);

  Gtk::Button *backButton{new Gtk::Button()};
  backButton->set_label("<");
  leftBox->append(*backButton);

  Gtk::Button *forwardButton{new Gtk::Button()};
  forwardButton->set_label(">");
  leftBox->append(*forwardButton);


  Gtk::Box *rightBox{new Gtk::Box()};
  rightBox->set_halign(Gtk::Align::END);
  append(*rightBox);

  Gtk::SearchEntry *searchEntry{new Gtk::SearchEntry()};
  rightBox->append(*searchEntry);

  Gtk::Button *settingsButton{new Gtk::Button()};
  settingsButton->set_label("s");
  rightBox->append(*settingsButton);
}