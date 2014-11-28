#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <Qt5Sparql/QSparqlConnection>


// local includes
#include "model/albumsmodel.h"

class MainController : public QObject
{
    Q_OBJECT

    enum LastFMDownloadSizes {
        LASTFM_SMALL,
        LASTFM_MEDIUM,
        LASTFM_LARGE,
        LASTFM_EXTRALARGE,
        LASTFM_MEGA
    };


public:
    explicit MainController(QObject *parent = 0);
    MainController(QQuickView *viewer,QObject *parent = 0);

signals:
    // local cover database stuff
    void newDownloadSize(QString);
    void newDownloadEnabled(bool);

public slots:
    // request slos
    void requestAlbums();
    void requestArtists();
    void requestPlaylists();
    void requestFolder(QString path);

    void albumsReady();
    void artistsReady();
    void playlistsReady();
    void folderReady();

private:
    QString getLastFMArtSize(int index);

    // SparQL
    QSparqlConnection *mSparQLConnection;

    AlbumsModel *mAlbumsModel;


    // Qml stuff
    QQuickView *mQuickView;

    void readSettings();
    void connectModelSignals();
    void connectQMLSignals();

    // GUI Settings
    int mDownloadEnabled;
    int mDownloadSize;
    int mAlbumViewSetting;
    int mArtistViewSetting;
    int mListImageSize;
    int mSectionsInSearch;
    int mSectionsInPlaylist;
    int mCoverInNowPlaying;

};

#endif // MAINCONTROLLER_H