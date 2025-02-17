#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include "application.h"
#include <QMainWindow>
#include <QX11Info>

#include <xcb/xcb_ewmh.h>

class QSystemTrayIcon;
class QMenu;
class historyWidget;
class QThread;
class MoreSetting;
class wallpaperEnginePlugin;
namespace Ui {
class settingWindow;
}

class settingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit settingWindow(QWidget *parent = nullptr, QMainWindow *mainWindow = nullptr);
    ~settingWindow();

    void readSettings();

    QString getCurrentPath();

    int getCurrentNumber();

    int isAutoStart();


    void setScreenMode(const QString &arg);

    QVector<WId> currentWorkWindow();

    //获取当前工作的窗口wid
    QVector<uint> getCurrentWorkspaceWindows();
    static xcb_atom_t internAtom(xcb_connection_t *connection, const char *name, bool only_if_exists = true);
    QVector<xcb_window_t> getWindows() const;
    qint32 getWorkspaceForWindow(quint32 WId);
    QRect geometry(WId id) const;
    Qt::WindowState getWindowState(WId id);
    void initAtom();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private slots:

    void slotMoreSettingSave();

    void saveSettings();

    void on_pathBtn_clicked();

    void on_setBtn_clicked();

    void on_cancelBtn_clicked();

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

    void on_Slider_valueChanged(int value);

    void on_startBtn_clicked();

    void on_startScreen_clicked();

    void on_autoStart_clicked();

    void on_noAutoStart_clicked();

    void on_autoStartBox_stateChanged(int arg1);

    void pathChanged(const QString &path);
    void on_comboBox_activated(const QString &arg1);

    void on_setManual_clicked();

    void quitApp();

    void on_mainWeb_clicked();

    void on_history_clicked();

    void slotWallPaper(const QString &path);


    void on_giteeWeb_clicked();

    void on_githubWeb_clicked();

    void on_bugBtn_clicked();

    void on_videoBLCombox_activated(const QString &arg1);

    void on_videoBZDY_clicked();

    void on_pathEdit_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);


    void on_moreSettingBtn_clicked();

    void on_pluginBtn_clicked();
public slots:
    void activeWindow();
private:
    Ui::settingWindow *ui;
    QSystemTrayIcon *m_trayIcon{nullptr};
    QMenu *m_traymenu{nullptr};
    QMainWindow *m_parentMainWindow{nullptr};
    int index = 1;

    int m_crrenNumber{0};
    int m_isAutoStart{0};
    QString m_currentMode;
    int m_voiceVolume{0};

    historyWidget *m_history{nullptr};

    wallpaperEnginePlugin *m_wallpaperEnginePlugin{nullptr};

    QString m_videoASpectStr{"默认"};
    double m_videoAspect{1.33};

    QThread *m_x11thread{nullptr};
    bool m_stopx11Thread{false};

    QMenu *m_aboutMenu{nullptr};
    MoreSetting *m_moreSetting{nullptr};


    QVector<WId> m_windowList;

    xcb_ewmh_connection_t m_ewmh_connection;

    QMutex m_mutex;

    QTimer *m_timerSave{nullptr};

};

#endif // SETTINGWINDOW_H
