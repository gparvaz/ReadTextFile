#ifndef INDEXTXT_H
#define INDEXTXT_H

#include <QMainWindow>

namespace Ui {
class IndexTXT;
}

class IndexTXT : public QMainWindow
{
    Q_OBJECT

public:
    explicit IndexTXT(QWidget *parent = nullptr);
    ~IndexTXT();

private slots:
    void on_toolButton_selct_txt_clicked();

    void on_pushButton_selct_txt_clicked();



    void on_actionSelext_database_triggered();

private:
    Ui::IndexTXT *ui;
    QString Read_list_from_Text(QString Filename);
    void write_list_to_txt(QString filename,QString content);
};

#endif // INDEXTXT_H
