#include "../include/age_audio.h"
namespace AGE2D{
AAudio::AAudio(QString audName)
{
    music = new QMediaPlayer;
    medialist=new QMediaPlaylist;
    this->loopORnot = false;
    this->Volume = 50;
    this->mods = 0;
    this->audName = audName;
    audio();
}
AAudio::AAudio(QString audName,int mods)
{
    music = new QMediaPlayer;
    medialist=new QMediaPlaylist;
    this->loopORnot = false;
    this->Volume = 50;
    this->mods = mods;
    this->audName = audName;
    audio();
}

void AAudio::audio()
{
    if(mods == 0)
    {

        QString pattern("(.*)/(.*.(mp3|mp4|ogg|flac|wav|ape|vqf|aac|mid|md|asf|m4a|aac|wma))");
        QFile f(this->audName);
        abcd = new ARegExp(pattern,audName);
        audName =abcd->getexitstr();
        delete abcd;
        f.copy(QDir::currentPath()+"/"+this->audName);
        this->medialist->addMedia(QUrl::fromLocalFile(QDir::currentPath()+"/"+this->audName));
    }
    else
    {
        this->medialist->addMedia(QUrl(this->audName));
    }
    this->music->setPlaylist(medialist);
    this->medialist->setCurrentIndex(1);
    this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

void AAudio::play()
{
    music->play();
}

void AAudio::stop()
{
    music->stop();
}

void AAudio::pause()
{
    music->pause();
}


AAudio::~AAudio()
{
    delete this->music;
    delete this->medialist;
}

QMediaPlayer *AAudio::getMusic() const
{
    return music;
}

void AAudio::setMusic(QMediaPlayer *value)
{
    music = value;
}

QMediaPlaylist *AAudio::getMedialist() const
{
    return medialist;
}

void AAudio::setMedialist(QMediaPlaylist *value)
{
    medialist = value;
}

QString AAudio::getObjName() const
{
    return objName;
}

void AAudio::setObjName(const QString &value)
{
    objName = value;
}

QString AAudio::getAudName() const
{
    return audName;
}

void AAudio::setAudName(const QString &value)
{
    audName = value;
}

bool AAudio::getLoopORnot() const
{
    return loopORnot;
}

void AAudio::setLoopORnot(bool value)
{
    loopORnot = value;
    if(this->loopORnot == true)
        this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    else this->medialist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

int AAudio::getVolume() const
{
    return Volume;
}

void AAudio::setVolume(int value)
{
    Volume = value;
    this->music->setVolume(this->Volume);
}

int AAudio::getMods() const
{
    return mods;
}

void AAudio::setMods(int value)
{
    mods = value;
}
}
