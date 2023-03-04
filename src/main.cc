#include "gdkmm/display.h"
#include "glibmm/refptr.h"
#include "gtk/gtkcssprovider.h"
#include "gtkmm/applicationwindow.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include "gtkmm/stylecontext.h"
#include "gtkmm/styleprovider.h"
#include "main-view/main-view.h"
#include "sigc++/functors/ptr_fun.h"
#include <gtkmm/application.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/frame.h>
#include <gtkmm/window.h>
#include <iostream>

class MainWindow : public Gtk::ApplicationWindow {
public:
  MainWindow(Glib::RefPtr<Gtk::Application> app);
};

MainWindow::MainWindow(Glib::RefPtr<Gtk::Application> app)
    : Gtk::ApplicationWindow(app) {
  set_title("Mel Desktop");
  set_default_size(1400, 800);
}

void on_activated(Glib::RefPtr<Gtk::Application> app) {
  std::cout << "activated" << std::endl;
  MainWindow *window{new MainWindow(app)};
  app->add_window(*window);

  MainView *mainView{new MainView(app, window)};
  window->set_child(*mainView);

  window->present();

  auto cssProvider{Gtk::CssProvider::create()};
  cssProvider->load_from_path("./style.css");
  Gtk::StyleContext::add_provider_for_display(
      Gdk::Display::get_default(), cssProvider,
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

int main(int argc, char *argv[]) {
  auto app{Gtk::Application::create("org.gtkmm.examples.base")};

  app->signal_activate().connect(sigc::bind(sigc::ptr_fun(&on_activated), app));

  // return app->make_window_and_run<MainWindow>(argc, argv);
  return app->run(argc, argv);
}