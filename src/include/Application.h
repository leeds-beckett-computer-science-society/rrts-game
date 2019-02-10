#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotImplementedFunctions"

#ifndef TESTING_APPLICATION_LINUX_H
#define TESTING_APPLICATION_LINUX_H
#include <iostream>
#include <vector>
#include <gtkmm-3.0/gtkmm.h>

class Application {
public:
    void parseArgs(int argc, char* argv[]);
    void Initialize();
    int Start();

private:

    Glib::RefPtr<Gtk::Application> MainWindow;
    Gtk::Window *window;
};

#endif

#pragma clang diagnostic pop