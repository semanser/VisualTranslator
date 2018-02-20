#include "language.h"

Language::Language(QObject *parent) : QObject(parent)
{

}

Lang Language::find(QString name) {
    foreach (Lang language, Language::languages) {
        if (language.name == name) return language;
    }

    // return the default language (English) with id 1
    return Language::languages[1];
}

QString Language::getUrl(QString name)
{
    return Language::find(name).url;
}

QString Language::getFileName(QString name)
{
    return Language::find(name).shortName + ".traineddata";
}

QString Language::getShortName(QString name)
{
    return Language::find(name).shortName;
}

QString Language::getGoogleName(QString name)
{
    return Language::find(name).googleName;
}

bool Language::isDownloaded(QString name)
{
    QDir tessdataFolder(qApp->applicationDirPath() + "/tessdata");
    QStringList tessFiles = tessdataFolder.entryList();

    return tessFiles.contains(Language::getShortName(name) + ".traineddata");
}

QList<Lang> Language::languages = QList<Lang>(
    {
        {
            "Arabic",
            "ara",
            "ar",
            "https://dl.dropboxusercontent.com/s/7qujorvi4op3tej/ara.traineddata"
        },
        {
            "English",
            "eng",
            "en",
            "https://dl.dropboxusercontent.com/s/r5qmsfonx7mluc4/eng.traineddata"
        },
        {
            "French",
            "fra",
            "fr",
            "https://dl.dropboxusercontent.com/s/ak8pnk2eup3w6e7/fra.traineddata"
        },
        {
            "German",
            "deu",
            "de",
            "https://dl.dropboxusercontent.com/s/l3083m8285ouhtr/deu.traineddata"
        },
        {
            "Italian",
            "ita",
            "it",
            "https://dl.dropboxusercontent.com/s/opr15y55o01cm4b/ita.traineddata"
        },
        {
            "Japanese",
            "jpn",
            "ja",
            "https://dl.dropboxusercontent.com/s/orsqcy09ohnd8ry/jpn.traineddata"
        },
        {
            "Korean",
            "kor",
            "ko",
            "https://dl.dropboxusercontent.com/s/rkg0vev3jzcgdur/kor.traineddata"
        },
        {
            "Portuguese",
            "por",
            "pt",
            "https://dl.dropboxusercontent.com/s/tmoion1c26qbx6b/por.traineddata"
        },
        {
            "Russian",
            "rus",
            "ru",
            "https://dl.dropboxusercontent.com/s/tmoion1c26qbx6b/rus.traineddata"
        },
        {
            "Spanish",
            "spa",
            "es",
            "https://dl.dropboxusercontent.com/s/pba3sen7o8e3nhf/spa.traineddata"
        },
        {
            "Ukrainian",
            "ukr",
            "uk",
            "https://dl.dropboxusercontent.com/s/17at42rlq50cy1z/ukr.traineddata"
        },
    }
);
