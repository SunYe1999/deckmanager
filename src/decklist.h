#ifndef DECKLIST_H
#define DECKLIST_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QString>
#include <QPair>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDesktopServices>
#include <QInputDialog>
#include <QCheckBox>
#include <QMenu>
#include "remote.h"

class DeckList : public QListWidget
{
    Q_OBJECT
public:
    DeckList(QWidget *parent = 0);
    ~DeckList();
    void contextMenuEvent(QContextMenuEvent *);
signals:
    void selectDeck(QString, QString);
    void deckType(QString);
public slots:
    void setList(Type::DeckL);
private slots:
    void onItemChanged();
    void onItem(QListWidgetItem *);
    void openURL(QListWidgetItem*);
    void same();
private:
    QMenu *popup;
    QListWidgetItem *menuItem;
};

class DeckListView : public QWidget
{
    Q_OBJECT
public:
    DeckListView(QWidget *parent = 0);

signals:
    void selectDeck(QString, QString);
public slots:
    void setList(Type::DeckL);
    void getList()
    {
        pageEdit->setText(QString::number(page));
        remote.getList(page);
    }

private slots:
    void nextPage();
    void prevPage();
    void goPage();
private:
    DeckList *decklist;
    Remote remote;
    int page;
    QLineEdit *pageEdit;
    int lastConfig;
    int lastPage;
};

#endif // DECKLIST_H
