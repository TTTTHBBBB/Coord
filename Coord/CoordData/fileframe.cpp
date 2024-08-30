#include <QFileDialog>
#include <QDir>
#include <QPainter>
#include <QFileInfo>
#include <QDirIterator>

#include "fileframe.h"
#include "ui_fileframe.h"


FileFrame::FileFrame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileFrame)
{
    ui->setupUi(this);
    this->frmaInit();
}

void FileFrame::frmaInit()
{
    this->MatcText();
    this->setStyleSheet("QFrame{background-color:rgb(35,36,39);}");
    ui->frametitle->setStyleSheet("QFrame{background-color:rgb(44,45,48);}");
    ui->labelTitle->setStyleSheet("QLabel{color:white;}");
    CoordRoot = new CoordTreeNode();

    connect(ui->pushButtonOpen,&QPushButton::clicked, this, &FileFrame::slot_FileOpen);
    connect(ui->frameobject, &CoordTreeWidget::signal_Filecreate, this, &FileFrame::slot_Filecreate);
    connect(ui->pushButtonExpor,&QPushButton::clicked, this, &FileFrame::slot_FileExpor);
}

void FileFrame::slot_FileExpor()
{
    if(fileName.isEmpty())
    {
        emit signal_FlickWindow(tr("File_open_failure"),FLICKTYPE::FAILD);
        return;
    }
    emit signal_FileExpor(fileName);
}

void FileFrame::slot_Filecreate(const CoordTreeNode &node)
{
    emit signal_Filecreate(node);
}

CoordTreeNode* FileFrame::FileRead(const QString& filepath)
{
    QDir dir(filepath);
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    // QStringList nameFilters;
    // nameFilters << "*.xls" << "*.xlsx";
    // dir.setNameFilters(nameFilters);
    QFileInfoList entries = dir.entryInfoList();

    QFileInfo fileInnfo(filepath);
    CoordTreeNode* rote = new CoordTreeNode();
    rote->filePath = filepath;
    rote->filename = fileInnfo.fileName();
    rote->isFile = FILETYPE::COORDROTE;

    for (const QFileInfo &entry : entries) {
        if (entry.isDir())
        {//文件夹
            CoordTreeNode* childDir = FileRead(entry.absoluteFilePath());
            childDir->isFile = FILETYPE::COORDFILE;
            rote->addChild(childDir);
        }
        else if(entry.isFile())
        {
            CoordTreeNode* childDir = new CoordTreeNode();
            childDir->filePath = entry.absoluteFilePath();
            childDir->filename = entry.fileName();
            childDir->isFile = FILETYPE::COORDTEXT;
            rote->addChild(childDir);
        }
    }
    return rote;
}

void FileFrame::slot_FileOpen()
{
    fileName = QFileDialog::getExistingDirectory(this,"Coord Select","",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(fileName.isEmpty())
    {
        emit signal_FlickWindow(tr("File_open_failure"),FLICKTYPE::FAILD);
        return;
    }
    CoordRoot = FileRead(fileName);
    ui->frameobject->ClearTree();
    ui->frameobject->ReadTreeNode(*CoordRoot);
}

void FileFrame::MatcText()
{
    ui->labelTitle->setText(tr("file_object"));
    ui->pushButtonOpen->MatchText(tr("open_file"));
    ui->pushButtonExpor->MatchText(tr("expor_file"));
}

bool FileFrame::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type())
    {
        case QEvent::MouseButtonDblClick:
        {
            break;
        }
        case QEvent::MouseButtonPress:
        {
            break;
        }
        default:
            break;
        }
    return QObject::eventFilter(watched, event);
}

void FileFrame::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&painter,this);
}

FileFrame::~FileFrame()
{
    delete ui;
}
