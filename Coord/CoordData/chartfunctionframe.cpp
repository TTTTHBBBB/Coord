#include "chartfunctionframe.h"
#include "ui_chartfunctionframe.h"

ChartFunctionFrame::ChartFunctionFrame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChartFunctionFrame)
{
    ui->setupUi(this);
    this->framInit();
}

void ChartFunctionFrame::framInit()
{
    this->setStyleSheet("QFrame{background-color:rgb(35,36,39);}");
    ui->frame_title->setStyleSheet("QFrame{background-color:rgb(44,45,48);}");
    ui->label->setStyleSheet("QLabel{color:white;}");

    ui->Coordlabel->setPixmap(QPixmap(":/images/png/coord.svg"));
    ui->Coordlabel->setScaledContents(true);
    ui->btnzoom->setParams(0, 4, QColor(255, 255, 255));
    this->MatcText();

    connect(ui->btnbroken, &QPushButton::clicked, this, &ChartFunctionFrame::Slot_broken);
    connect(ui->btncolumn, &QPushButton::clicked, this, &ChartFunctionFrame::Slot_column);
    connect(ui->btncurved, &QPushButton::clicked, this, &ChartFunctionFrame::Slot_curved);
}

void ChartFunctionFrame::Slot_broken()
{
    emit Signal_broken();
}

void ChartFunctionFrame::Slot_column()
{
    emit Signal_column();
}

void ChartFunctionFrame::Slot_curved()
{
    emit Signal_curved();
}

void ChartFunctionFrame::MatcText()
{
   ui->btnzoom->MatchText(tr("zoom"));
   ui->btnbroken->MatchText(tr("broken_line"));
   ui->btncolumn->MatchText(tr("columnar"));
   ui->btncurved->MatchText(tr("curved_line"));
   ui->label->setText(tr("Graphic_management"));
   ui->btnscatter->MatchText(tr("scatter"));
   ui->btnheat->MatchText(tr("heat_map"));
   ui->btnmotion->MatchText(tr("motion_picture"));
}


