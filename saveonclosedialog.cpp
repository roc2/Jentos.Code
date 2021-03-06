#include "saveonclosedialog.h"
#include "ui_saveonclosedialog.h"
#include <QDebug>

SaveOnCloseDialog::SaveOnCloseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveOnCloseDialog)
{
    ui->setupUi(this);
}

SaveOnCloseDialog::~SaveOnCloseDialog()
{
    delete ui;
}

void SaveOnCloseDialog::fillList(QStringList &lst)
{
    list.clear();
    list.append(lst);
    ui->listWidget->addItems(list);
    int count = list.size();
    for (int k = 0; k < count; ++k) {
        QListWidgetItem *item = ui->listWidget->item(k);
        item->setCheckState(Qt::Checked);
    }
}

void SaveOnCloseDialog::on_pushButtonSave_clicked()
{
    int count = ui->listWidget->count();
    for (int k = 0; k < count; ++k) {
        QListWidgetItem *item = ui->listWidget->item(k);
        if (item->checkState() != Qt::Checked) {
            list.removeOne(item->text());
        }
    }
    setResult(1);
    hide();
}

void SaveOnCloseDialog::on_pushButtonDiscard_clicked()
{
    setResult(-1);
    hide();
}

void SaveOnCloseDialog::on_pushButtonCancel_clicked()
{
    setResult(0);
    hide();
}
