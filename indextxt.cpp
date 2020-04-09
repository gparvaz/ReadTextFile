#include "indextxt.h"
#include "ui_indextxt.h"
#include <QFileDialog>
#include <QSettings>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>
#include <QtNetwork>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QLCDNumber>
#include <QCryptographicHash>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>

QString IndexTXT::Read_list_from_Text(QString Filename)
{
    QFile file(Filename);
    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            line.append(stream.readLine()+"\n");
        }
    }
    file.close();
    return line;
}

void IndexTXT::write_list_to_txt(QString filename,QString content)
{
    QFile file(filename);

    if ( file.open(QIODevice::WriteOnly) )
    {
        QTextStream stream(&file);
        stream <<content<<endl;

    }
}




IndexTXT::IndexTXT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IndexTXT)
{
    ui->setupUi(this);
}

IndexTXT::~IndexTXT()
{
    delete ui;
}

void IndexTXT::on_toolButton_selct_txt_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"),
                                                    "../list/",
                                                    tr("txt files (*.txt*)"));
    ui->lineEdit_selct_txt->setText(fileName);
}

void IndexTXT::on_pushButton_selct_txt_clicked()
{


    QStringList fir=  {"q", "w","e","r"} ;
    QStringList sec=  {"q", "a","s","d","t"} ;


    QMap<QString,int> countOfStrings_test;
    QStringList listOfStrings_test=fir;
    listOfStrings_test.append(sec);

    for(int i=0;i<listOfStrings_test.count();i++)
    {
        countOfStrings_test[listOfStrings_test[i]]++;
    }
    qDebug()<< listOfStrings_test;
    qDebug() << countOfStrings_test;



    for (int p=1;p <= countOfStrings_test.count();p++)
    {
        qDebug() << countOfStrings_test[listOfStrings_test[p]];

    }





    QString Filename=ui->lineEdit_selct_txt->text();
    QString All_line= Read_list_from_Text(Filename);
    QStringList strlistfiles= All_line.split("\n");
    QStringList list_of_all_word;
    QStringList list_of_all_word_unique;


    for (int i=0;i<strlistfiles.size()-1;i++)
    {
        QString line_by_line = strlistfiles[i];
        list_of_all_word << line_by_line.split(" ");
    }
    list_of_all_word_unique=list_of_all_word;
    list_of_all_word_unique.removeDuplicates();
    QString All_words_to_show_in_textbox=list_of_all_word.join(",");
    All_words_to_show_in_textbox.replace(",","\n");
    ui->textEdit_list_all_words->setPlainText(All_words_to_show_in_textbox);
    //
    QString All_Unique_words_to_show_in_textbox=list_of_all_word_unique.join(",");
    All_Unique_words_to_show_in_textbox.replace(",","\n");
    ui->textEdit_list_all_unique->setPlainText(All_Unique_words_to_show_in_textbox);

    QMap<QString,int> countOfStrings;
    for(int i=0;i<list_of_all_word.count();i++)
    {
        countOfStrings[list_of_all_word[i]]++;
    }
    //qDebug() << countOfStrings;
    ui->tableWidget_word_repeats->setRowCount(countOfStrings.count()+1);
    ui->tableWidget_word_repeats->setColumnCount(2);
    ui->tableWidget_word_repeats->setHorizontalHeaderItem(0, new QTableWidgetItem("Words"));
    ui->tableWidget_word_repeats->setHorizontalHeaderItem(1, new QTableWidgetItem("Counts"));

    for (int p=1;p <= countOfStrings.count();p++)
    {
        QTableWidgetItem *newItem_col1 = new QTableWidgetItem(tr("%1").arg(list_of_all_word_unique[p]));
        QTableWidgetItem *newItem_col2 = new QTableWidgetItem(tr("%1").arg(countOfStrings[list_of_all_word_unique[p]]));

        ui->tableWidget_word_repeats->setItem(p-1,0,newItem_col1);
        ui->tableWidget_word_repeats->setItem(p-1,1,newItem_col2);
    }
}

void IndexTXT::on_actionSelext_database_triggered()
{

}
