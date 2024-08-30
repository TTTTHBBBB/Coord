/*
 * 文件管理平台
*/
#ifndef FILEFRAME_H
#define FILEFRAME_H

#include <QWidget>
#include <QFrame>
#include <QMap>

#include "globaldef.hpp"
#include "CoordData/coordtreenode.h"

namespace Ui {
class FileFrame;
}

class FileFrame : public QWidget
{
    Q_OBJECT

public:
    explicit FileFrame(QWidget *parent = nullptr);
    ~FileFrame();

    void frmaInit();
    void MatcText();
    CoordTreeNode* FileRead(const QString& path);

private slots:
    void slot_FileOpen();
    void slot_FileExpor();
    void slot_Filecreate(const CoordTreeNode &node);

signals:
    void signal_FlickWindow(const QString str, const FLICKTYPE type);
    void signal_Filecreate(const CoordTreeNode &node);
    void signal_FileExpor(const QString &path);

private:
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void paintEvent(QPaintEvent *);

private:
    CoordTreeNode * CoordRoot = nullptr;
    QString fileName = "";

private:
    Ui::FileFrame *ui;
};

#endif // FILEFRAME_H
