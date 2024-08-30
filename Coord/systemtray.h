/*
 * 系统托盘
*/

#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include<QSystemTrayIcon>
#include<QAction>
#include<QApplication>
#include<QMenu>
#include<QWidget>
#include<QObject>

class SystemTray: public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTray(QWidget *parent = 0);
    ~SystemTray();

    void addAction();
    void createAction();
    void MatchText();

public:
    QAction *getShowWidget() const;
    QAction *getMinWidget() const;
    QAction *getAboutSoftWare() const;

signals:
    void showMainWindow();
    void showAboutUs();

private slots:
    void aboutSlot();

private:
    QMenu *myMenu = nullptr;
    QAction* showWidget = nullptr;
    QAction* minWidget = nullptr;
    QAction* aboutSoftWare = nullptr;
    QAction* exitSoftWare = nullptr;
};

#endif // SYSTEMTRAY_H
