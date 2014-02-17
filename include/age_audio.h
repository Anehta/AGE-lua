#ifndef AGE_AUDIO_H
#define AGE_AUDIO_H
#include <QString>
#include <QtMultimedia/qmediaplayer.h>
#include <QtMultimedia/qmediaplaylist.h>
#include <QDir>
#include "age_regexp.h"
namespace AGE2D{
class AAudio
{
protected:
    QFile f;
    QMediaPlayer * music;
    QMediaPlaylist *medialist;
    QString objName;
    QString audName;
    ARegExp *abcd;
    bool loopORnot;
    int Volume;
    int mods;

public:
    AAudio(QString audName);
    AAudio(QString audName,int mods);
    void audio();
    void play();
    void stop();
    void pause();
    ~AAudio();
    QMediaPlayer *getMusic() const;
    void setMusic(QMediaPlayer *value);
    QMediaPlaylist *getMedialist() const;
    void setMedialist(QMediaPlaylist *value);
    QString getObjName() const;
    void setObjName(const QString &value);
    QString getAudName() const;
    void setAudName(const QString &value);
    bool getLoopORnot() const;
    void setLoopORnot(bool value);
    int getVolume() const;
    void setVolume(int value);
    int getMods() const;
    void setMods(int value);
};
}

#endif // AGE_AUDIO_H
