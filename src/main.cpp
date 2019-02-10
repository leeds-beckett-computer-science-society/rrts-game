#include <iostream>
#include <Application.h>
#include <gtkmm-3.0/gtkmm.h>

int main(int argc, char* argv[])
{
    Application app;
    app.parseArgs(argc, argv);
    app.Initialize();
    return app.Start();
}