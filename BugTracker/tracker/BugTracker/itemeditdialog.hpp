#ifndef ITEMEDITDIALOG_HPP
#define ITEMEDITDIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <memory>
#include <unordered_map>
#include <set>
#include <QDebug>

#include <vector>

namespace Ui {
class ItemEditDialog;
}

class ItemEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ItemEditDialog(QWidget *parent = 0, std::vector<QString> bug_values = std::vector<QString>());

    ~ItemEditDialog();

    std::unique_ptr< std::vector<QLineEdit*> > line_edits_ptr_; // holds the lineEdits so we can access them, note that we do not need deleting the parent does it
    QStringList return_strings(const std::unordered_map<std::string, int>& state_names,
                               const std::set< int>& enum_cols); // gets the strings from the lineEdits

private:
    Ui::ItemEditDialog *ui;

};

#endif // ITEMEDITDIALOG_HPP
