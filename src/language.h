#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QObject>
#include <QtWidgets>

struct Lang
{
  QString name;
  QString shortName;
  QString url;
};

class Language : public QObject
{
public:
    explicit Language(QObject *parent = nullptr);
    static QList<Lang> languages;
    static QString getUrl(QString name);
    static QString getFileName(QString name);
    static QString getShortName(QString name);
    static bool isDownloaded(QString name);

private:
};

#endif // LANGUAGE_H