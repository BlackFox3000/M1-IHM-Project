#ifndef WINDOWFILES_H
#define WINDOWFILES_H

#include <QWidget>
#include <QDir>
#include<QTreeView>
#include <QDialog>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QDialogButtonBox;


class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    QStringList getFiles();
    QString getFolder();

private slots:
    void browse();
    void find();
    void openFileOfItem(int row, int column);
    void contextMenu(const QPoint &pos);

private:
    QStringList findFiles(const QStringList &files, const QString &text);
    void showFiles(const QStringList &paths);
    QComboBox *createComboBox(const QString &text = QString());
    void createFilesTable();

    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QComboBox *directoryComboBox;
    QLabel *filesFoundLabel;
    QDialogButtonBox *findButton;
    QTableWidget *filesTable;

    QStringList files;
    QString folder;

    QDir currentDir;
};

#endif // WINDOWFILES_H
