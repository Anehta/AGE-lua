#ifndef AGE_REGEXP_H
#define AGE_REGEXP_H
#include <QRegExp>
#include <QString>
namespace AGE2D{
class ARegExp
{
protected:
    QString pattern;
    QString str;

public:
    ARegExp(QString pattern,QString str);
    QString getexitstr();

    QString getPattern() const;
    void setPattern(const QString &value);
    QString getStr() const;
    void setStr(const QString &value);
};
}

#endif // AGE_REGEXP_H
