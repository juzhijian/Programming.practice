﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSettings>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QFileDialog>
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buttonGroup->setId(ui->radioButton,0);//设置ID
    ui->buttonGroup->setId(ui->radioButton_2,1);
    ui->buttonGroup->setId(ui->radioButton_3,2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//等级函数仿官方版
QString function_level_normal(int a)
{
    long L_num1 = 10;
    QString level = "ExperiencePointsForLevel[0]=10";
    for(int i=1;i<a;i++)
    {
        L_num1 = L_num1+5*(i+1);
        level = level + ",ExperiencePointsForLevel[" + QString::number(i) + "]=" + QString::number(L_num1);
    }
    return level;
}

//等级函数自定义版
QString function_level_custom(int a,long L_num1,int b)
{
    QString level = "ExperiencePointsForLevel[0]=10";
    for(int i=1;i<a;i++)
    {

        L_num1 = b*(L_num1+5*i)/100;
        level = level + ",ExperiencePointsForLevel[" + QString::number(i) + "]=" + QString::number(L_num1);
    }
    return level;
}

//等级函数成神版
QString function_level_god(int a)
{
    QString level = "ExperiencePointsForLevel[0]=10";
    int i;
    for(i=1;i<a;i++)
    {
        level = level + ",ExperiencePointsForLevel[" + QString::number(i) + "]=10";
    }
    return level;
}

//研究点数生成
QString function_Research(int a,int b)
{
    QString Research = "OverridePlayerLevelEngramPoints="+QString::number(b)+"\n";
    int i;
    for (i = 1; i < a; i++)
    {
        Research += "OverridePlayerLevelEngramPoints=" + QString::number(b) + "\n";
    }
    return Research;
}

//生成文件
void MainWindow::on_pushButton_clicked()
{
    //文件生成
    QString sh="[/script/shootergame.shootergamemode]\n";

    //玩家等级与研究点数
    int num1,num2,num3;
    num1 = ui->lineEdit_15->text().toInt();
    num2 = ui->lineEdit_16->text().toInt();
    //恐龙等级
    num3 = ui->lineEdit_57->text().toInt();
    //经验设置
    quint16 pd = ui->buttonGroup->checkedId();
    QString player_leve_generate,dinosaur_level_generate;

    long L_num1,L_num2;//经验
    L_num1 = ui->lineEdit->text().toLong();
    L_num2 = ui->lineEdit_2->text().toLong();

    int num4,num5;//经验系数
    num4 = ui->lineEdit_20->text().toInt();
    num5 = ui->lineEdit_19->text().toInt();

    if(pd==0)//仿官方
    {
        player_leve_generate = function_level_normal(num1);
        dinosaur_level_generate = function_level_normal(num3);
    }
    if(pd==1)//自定义
    {
        player_leve_generate = function_level_custom(num1,L_num1,num4);
        dinosaur_level_generate = function_level_custom(num3,L_num2,num5);
    }
    if(pd==2)//成神
    {
        player_leve_generate = function_level_god(num1);
        dinosaur_level_generate = function_level_god(num3);
    }
    //等级设置
    QString player_levle,dinosaur_level;//玩家 恐龙
    player_levle="LevelExperienceRampOverrides=(" + player_leve_generate + ")\n";
    dinosaur_level="LevelExperienceRampOverrides=(" + dinosaur_level_generate + ")\n";

    //玩家倍数生成
    QString player=
            "PerLevelStatsMultiplier_Player[0]=" + QString::number(ui->lineEdit_3->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_Player[1]=" + QString::number(ui->lineEdit_10->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_Player[2]=" + QString::number(ui->lineEdit_4->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_Player[3]=" + QString::number(ui->lineEdit_13->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_Player[4]=" + QString::number(ui->lineEdit_5->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_Player[5]=" + QString::number(ui->lineEdit_11->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[6]=" + QString::number(ui->lineEdit_6->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[7]=" + QString::number(ui->lineEdit_14->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[8]=" + QString::number(ui->lineEdit_7->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[9]=" + QString::number(ui->lineEdit_12->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[10]=" + QString::number(ui->lineEdit_8->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_Player[11]=" + QString::number(ui->lineEdit_9->text().toInt()) + "\n";
    //恐龙倍数
    QString DinoTamed=
            "PerLevelStatsMultiplier_DinoTamed[0]=" + QString::number(ui->lineEdit_46->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoTamed[1]=" + QString::number(ui->lineEdit_47->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoTamed[2]=" + QString::number(ui->lineEdit_48->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoTamed[3]=" + QString::number(ui->lineEdit_45->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoTamed[4]=" + QString::number(ui->lineEdit_50->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoTamed[5]=" + QString::number(ui->lineEdit_49->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoTamed[6]=" + QString::number(ui->lineEdit_51->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoTamed[7]=" + QString::number(ui->lineEdit_52->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoTamed[8]=" + QString::number(ui->lineEdit_53->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoTamed[9]=" + QString::number(ui->lineEdit_55->text().toInt()) + "\n";
    //野生恐龙倍数
    QString DinoWild=
            "PerLevelStatsMultiplier_DinoWild[0]=" + QString::number(ui->lineEdit_59->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoWild[1]=" + QString::number(ui->lineEdit_60->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoWild[2]=" + QString::number(ui->lineEdit_61->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoWild[3]=" + QString::number(ui->lineEdit_58->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoWild[4]=" + QString::number(ui->lineEdit_63->text().toInt()) + "\n"+
            "PerLevelStatsMultiplier_DinoWild[5]=" + QString::number(ui->lineEdit_62->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoWild[6]=" + QString::number(ui->lineEdit_64->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoWild[7]=" + QString::number(ui->lineEdit_65->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoWild[8]=" + QString::number(ui->lineEdit_66->text().toInt()) + "\n" +
            "PerLevelStatsMultiplier_DinoWild[9]=" + QString::number(ui->lineEdit_68->text().toInt()) + "\n";

    //ui->textBrowser->setText(QString::number(aaaa));
    ui->textBrowser->setText(sh+player+DinoTamed+DinoWild+player_levle+dinosaur_level+function_Research(num1,num2));


    //导出INI文件

    QString path = QFileDialog::getSaveFileName(this, tr("Open ini"), "Game", tr("ini Files (*.ini)"));

    if(!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QStringLiteral("不能创建文件\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << ui->textBrowser->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::information(this, QString::fromLocal8Bit("警告"), QStringLiteral("您没有保存文件！"));
    }


}

void MainWindow::on_radioButton_3_clicked()
{

    ui->textBrowser->setText(QStringLiteral("您选择了成神版!"));

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->textBrowser->setText(QStringLiteral("您选择了自定义版!!"));
}

void MainWindow::on_radioButton_clicked()
{
    ui->textBrowser->setText(QStringLiteral("您选择了仿官方版!!"));
}
