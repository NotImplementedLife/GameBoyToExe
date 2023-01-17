#include "resources.h"
#include <QDir.h>

namespace Resources
{
    void unpack_text(const char* buffer, const char* folder, const char* filename)
    {
        if(!QDir("~bgptmp").exists())
        {
            QDir().mkdir("~bgptmp");
        }
        QDir path("~bgptmp");
        if(strlen(folder)!=0)
            path.mkdir(folder);
        path.cd(folder);
        QString fpath = path.absoluteFilePath(filename);
        QFile file(fpath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream<<buffer;
            file.close();
            //qDebug() << "Writing finished";
        }
    }

    void unpack_binary(const char* buffer, int length, const char* folder, const char* filename)
    {
        if(!QDir("~bgptmp").exists())
        {
            QDir().mkdir("~bgptmp");
        }
        QDir path("~bgptmp");
        if(strlen(folder)!=0)
            path.mkdir(folder);
        path.cd(folder);
        QString fpath = path.absoluteFilePath(filename);
        QFile file(fpath);
        if(file.open(QIODevice::WriteOnly))
        {
            QByteArray data(buffer, length);
            file.write(data);
            file.close();
        }
    }
}
