#include "itemeditdialog.hpp"
#include "ui_itemeditdialog.h"

ItemEditDialog::ItemEditDialog(QWidget *parent, std::vector<QString> bug_values) :
    QDialog(parent),
    ui(new Ui::ItemEditDialog)
{
    ui->setupUi(this);

    // we make as many line edits as we have columns
    line_edits_ptr_ = std::make_unique<std::vector<QLineEdit*> >();
    for(size_t i = 1; i < bug_values.size(); i++)
    {
        line_edits_ptr_->push_back(new QLineEdit(bug_values[i],this));
    }

    // Then add them into the GUI
    for(auto it : *line_edits_ptr_)
    {
        ui->lay_Main->addWidget(it);
    }

}

QStringList ItemEditDialog::return_strings()
{
    QStringList ret;
    for(auto it : *line_edits_ptr_)
    {
        ret.push_back(it->text());
    }

    return ret;
}

ItemEditDialog::~ItemEditDialog()
{
    delete ui;
}
