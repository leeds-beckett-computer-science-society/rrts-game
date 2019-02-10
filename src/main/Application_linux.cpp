#ifdef __linux__
#include <Application.h>

void Application::parseArgs(int argc, char* argv[]) {
    MainWindow = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
}

void Application::Initialize() {
    window = new Gtk::Window;
    window->set_default_size(200, 200);
}

int Application::Start() {
    return MainWindow->run(*window);
}

#endif