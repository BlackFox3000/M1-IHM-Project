#include <QtWidgets>

#include "window.h"

enum { absoluteFileNameRole = Qt::UserRole + 1 };

static inline QString fileNameOfItem(const QTableWidgetItem *item)
{
    return item->data(absoluteFileNameRole).toString();
}

static inline void openFile(const QString &fileName)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

Window::Window(QWidget *parent, QTreeView *treeView)
    : QWidget(parent)
{
    this->treeView = treeView;

    setWindowTitle(tr("Ajouter des fichiers"));
    QPushButton *browseButton = new QPushButton(tr("&Parcourir..."), this);
    connect(browseButton, &QAbstractButton::clicked, this, &Window::browse);
    findButton = new QPushButton(tr("&Ajouter"), this);
    connect(findButton, &QAbstractButton::clicked, this, &Window::getTree);

    fileComboBox = createComboBox(tr("*"));
    connect(fileComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &Window::animateFindClick);
    textComboBox = createComboBox();
    connect(textComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &Window::animateFindClick);
    directoryComboBox = createComboBox(QDir::toNativeSeparators(QDir::currentPath()));
    connect(directoryComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &Window::animateFindClick);

    filesFoundLabel = new QLabel;

    createFilesTable();

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(new QLabel(tr("Répertoir:")), 2, 0);
    mainLayout->addWidget(directoryComboBox, 2, 1);
    mainLayout->addWidget(browseButton, 2, 2);
    mainLayout->addWidget(filesTable, 3, 0, 1, 3);
    mainLayout->addWidget(filesFoundLabel, 4, 0, 1, 2);
    mainLayout->addWidget(findButton, 4, 2);

    connect(new QShortcut(QKeySequence::Quit, this), &QShortcut::activated,
        qApp, &QApplication::quit);
}

void Window::browse()
{
    QString directory = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("AJouter des fichiers"), directoryComboBox->currentText()));

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
        find();
    }
}

static void updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1)
        comboBox->addItem(comboBox->currentText());
}

void Window::find()
{
    filesTable->setRowCount(0);

    QString fileName = fileComboBox->currentText();
    QString text = textComboBox->currentText();
    QString path = QDir::cleanPath(directoryComboBox->currentText());
    currentDir = QDir(path);

    updateComboBox(fileComboBox);
    updateComboBox(textComboBox);
    updateComboBox(directoryComboBox);

    QStringList filter;
    if (!fileName.isEmpty())
        filter << fileName;
    QDirIterator it(path, filter, QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QStringList files;
    while (it.hasNext())
        files << it.next();
    if (!text.isEmpty())
        files = findFiles(files, text);
    files.sort();
    showFiles(files);
}

void Window::getTree()
{
    tre
}

void Window::animateFindClick()
{
    findButton->animateClick();
}

QStringList Window::findFiles(const QStringList &files, const QString &text)
{
    QProgressDialog progressDialog(this);
    progressDialog.setCancelButtonText(tr("&Annuler"));
    progressDialog.setRange(0, files.size());
    progressDialog.setWindowTitle(tr("Ajouter des fichiers"));

    QMimeDatabase mimeDatabase;
    QStringList foundFiles;

    for (int i = 0; i < files.size(); ++i) {
        progressDialog.setValue(i);
        progressDialog.setLabelText(tr("Recherche des fichiers : %1 sur %n...", 0, files.size()).arg(i));
        QCoreApplication::processEvents();

        if (progressDialog.wasCanceled())
            break;

        const QString fileName = files.at(i);
        const QMimeType mimeType = mimeDatabase.mimeTypeForFile(fileName);
        if (mimeType.isValid() && !mimeType.inherits(QStringLiteral("text/plain"))) {
            qWarning() << "Ne recherche pas les fichiers binaires " << QDir::toNativeSeparators(fileName);
            continue;
        }
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            QString line;
            QTextStream in(&file);
            while (!in.atEnd()) {
                if (progressDialog.wasCanceled())
                    break;
                line = in.readLine();
                if (line.contains(text, Qt::CaseInsensitive)) {
                    foundFiles << files[i];
                    break;
                }
            }
        }
    }
    return foundFiles;
}

void Window::showFiles(const QStringList &paths)
{
    for (const QString &filePath : paths) {
        const QString toolTip = QDir::toNativeSeparators(filePath);
        const QString relativePath = QDir::toNativeSeparators(currentDir.relativeFilePath(filePath));
        const qint64 size = QFileInfo(filePath).size();

        QTableWidgetItem *sizeItem = new QTableWidgetItem(QLocale().formattedDataSize(size));
        sizeItem->setData(absoluteFileNameRole, QVariant(filePath));
        sizeItem->setToolTip(toolTip);
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *fileNameItem = new QTableWidgetItem(relativePath);
        fileNameItem->setData(absoluteFileNameRole, QVariant(filePath));
        fileNameItem->setToolTip(toolTip);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);

        if(QString::compare(sizeItem->text().split(" ")[0],"0") != 0){
            //qDebug() <<"test : " << sizeItem->text();
            int row = filesTable->rowCount();
            filesTable->insertRow(row);
            filesTable->setItem(row, 0, fileNameItem);
            filesTable->setItem(row, 1, sizeItem);
        }
    }
    filesFoundLabel->setText(tr("%n Fichier(s) trouvé (CLiquez deux fois sur un fichier pour l'ouvrir)", 0, paths.size()));
    filesFoundLabel->setWordWrap(true);
}

QComboBox *Window::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

void Window::createFilesTable()
{
    filesTable = new QTableWidget(0, 2);
    filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList labels;
    labels << tr("Nom de fichier") << tr("Taille");
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    filesTable->verticalHeader()->hide();
    filesTable->setShowGrid(false);
    filesTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(filesTable, &QTableWidget::customContextMenuRequested,this, &Window::contextMenu);
    connect(filesTable, &QTableWidget::cellActivated,this, &Window::openFileOfItem);
}


void Window::openFileOfItem(int row, int /* column */)
{
    const QTableWidgetItem *item = filesTable->item(row, 0);
    openFile(fileNameOfItem(item));
}


void Window::contextMenu(const QPoint &pos)
{
    const QTableWidgetItem *item = filesTable->itemAt(pos);
    if (!item)
        return;
    QMenu menu;
#ifndef QT_NO_CLIPBOARD
    QAction *copyAction = menu.addAction("Copier le nom");
#endif
    QAction *openAction = menu.addAction("Ouvrir");
    QAction *action = menu.exec(filesTable->mapToGlobal(pos));
    if (!action)
        return;
    const QString fileName = fileNameOfItem(item);
    if (action == openAction)
        openFile(fileName);
#ifndef QT_NO_CLIPBOARD
    else if (action == copyAction)
        QGuiApplication::clipboard()->setText(QDir::toNativeSeparators(fileName));
#endif
}
