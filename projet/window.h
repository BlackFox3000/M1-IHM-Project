#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDir>
#include<QTreeView>
#include <QDialog>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;


class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);

private slots:
    void browse();
    void find();
    void getTree();
    void animateFindClick();
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
    QPushButton *findButton;
    QTableWidget *filesTable;

    QDir currentDir;
};

#endif // WINDOW_H