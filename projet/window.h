#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDir>
#include<QTreeView>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;


class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0,QTreeView *treeView = new QTreeView());
    QTreeView *treeView;

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
