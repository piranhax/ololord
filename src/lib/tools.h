#ifndef TOOLS_H
#define TOOLS_H

class QLocale;
class QStringList;

namespace cppcms
{

class application;

namespace json
{

class value;

}

namespace http
{

class request;

}

}

namespace std
{

class locale;

}

#include "global.h"

#include <BCoreApplication>

#include <QByteArray>
#include <QDateTime>
#include <QList>
#include <QMap>
#include <QString>

#include <list>
#include <string>

namespace Tools
{

struct File
{
    QByteArray data;
    QString fileName;
    QString formFieldName;
    QString mimeType;
};

typedef QList<File> FileList;

struct Post
{
    QString email;
    FileList files;
    QString name;
    QByteArray password;
    QString subject;
    QString text;
};

enum MaxInfo
{
    MaxEmailFieldLength = 1,
    MaxNameFieldLength,
    MaxSubjectFieldLength,
    MaxTextFieldLength,
    MaxPasswordFieldLength,
    MaxFileCount,
    MaxFileSize,
    MaxLastPosts
};

typedef QMap<QString, QString> PostParameters;

OLOLORD_EXPORT QStringList acceptedExternalBoards();
OLOLORD_EXPORT bool captchaEnabled(const QString &boardName);
OLOLORD_EXPORT QString cityName(const QString &ip);
OLOLORD_EXPORT QString cityName(const cppcms::http::request &req);
OLOLORD_EXPORT QString cookieValue(const cppcms::http::request &req, const QString &name);
OLOLORD_EXPORT QString countryCode(const QString &ip);
OLOLORD_EXPORT QString countryCode(const cppcms::http::request &req);
OLOLORD_EXPORT QString countryName(const QString &countryCode);
OLOLORD_EXPORT QDateTime dateTime(const QDateTime &dt, const cppcms::http::request &req);
OLOLORD_EXPORT QString flagName(const QString &countryCode);
OLOLORD_EXPORT QLocale fromStd(const std::locale &l);
OLOLORD_EXPORT QString fromStd(const std::string &s);
OLOLORD_EXPORT QStringList fromStd(const std::list<std::string> &sl);
OLOLORD_EXPORT QByteArray hashpass(const cppcms::http::request &req);
OLOLORD_EXPORT QString hashpassString(const cppcms::http::request &req);
OLOLORD_EXPORT int ipBanLevel(const QString &ip);
OLOLORD_EXPORT int ipBanLevel(const cppcms::http::request &req);
OLOLORD_EXPORT QDateTime localDateTime(const QDateTime &dt, int offsetMinutes = -1000);
OLOLORD_EXPORT QLocale locale(const cppcms::http::request &req,
                              const QLocale &defaultLocale = BCoreApplication::locale());
OLOLORD_EXPORT void log(const cppcms::application &app, const QString &what);
OLOLORD_EXPORT void log(const cppcms::http::request &req, const QString &what);
OLOLORD_EXPORT unsigned int maxInfo(MaxInfo m, const QString &boardName = QString());
OLOLORD_EXPORT QString mimeType(const QByteArray &data, bool *ok = 0);
OLOLORD_EXPORT QStringList news(const QLocale &l);
OLOLORD_EXPORT FileList postFiles(const cppcms::http::request &request);
OLOLORD_EXPORT PostParameters postParameters(const cppcms::http::request &request);
OLOLORD_EXPORT cppcms::json::value readJsonValue(const QString &fileName, bool *ok = 0);
OLOLORD_EXPORT void resetLoggingSkipIps();
OLOLORD_EXPORT QStringList rules(const QString &prefix, const QLocale &l);
OLOLORD_EXPORT QString storagePath();
OLOLORD_EXPORT QStringList supportedCodeLanguages();
OLOLORD_EXPORT int timeZoneMinutesOffset(const cppcms::http::request &req);
OLOLORD_EXPORT QByteArray toHashpass(const QString &s, bool *ok = 0);
OLOLORD_EXPORT Post toPost(const PostParameters &params, const FileList &files);
OLOLORD_EXPORT Post toPost(const cppcms::http::request &req);
OLOLORD_EXPORT std::locale toStd(const QLocale &l);
OLOLORD_EXPORT std::string toStd(const QString &s);
OLOLORD_EXPORT std::list<std::string> toStd(const QStringList &sl);
OLOLORD_EXPORT QString toString(const QByteArray &hp, bool *ok = 0);
OLOLORD_EXPORT QString userIp(const cppcms::http::request &req);

}

#endif // TOOLS_H
