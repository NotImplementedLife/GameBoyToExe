#include "mainwindow.h"

#include <QApplication>
#include "resources.h"

int main(int argc, char *argv[])
{
    Resources::unpack_text(Resources::index_html, "", "index.html");
    Resources::unpack_text(Resources::style_css, "css", "style.css");
    Resources::unpack_text(Resources::script_js, "js", "script.js");
    Resources::unpack_text(Resources::binjgb_js, "", "binjgb.js");
    Resources::unpack_binary((const char*)Resources::binjgb_wasm, binjgb_wasm_len, "", "binjgb.wasm");
    if(Resources::gb_rom_len!=0x69420AAA)
    {
        Resources::unpack_binary((const char*)Resources::gb_rom, Resources::gb_rom_len, "rom", "game.gb");
    }
    else
    {
        Resources::unpack_text("Invalid ROM", "rom", "game.gb");
    }

    QNetworkProxyFactory::setUseSystemConfiguration(false);
    QApplication app(argc, argv);

    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();

    return app.exec();
}
