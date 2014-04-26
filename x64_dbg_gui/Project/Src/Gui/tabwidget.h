#ifndef __MHTABWIDGET_H__
#define __MHTABWIDGET_H__

// Qt includes
#include <QWidget>
#include <QTabWidget>
#include <QMainWindow>

// Qt forward class definitions
class MHTabBar;

//////////////////////////////////////////////////////////////////////////////
// Summary:
//    MHTabWidget implements the a Tab Widget with detach and attach
//    functionality.
//////////////////////////////////////////////////////////////////////////////
class MHTabWidget: public QTabWidget
{
    Q_OBJECT

public:
    MHTabWidget(QWidget *parent);
    virtual ~MHTabWidget(void);

public slots:
    int count() const;
    QWidget *widget(int index) const;

    // Move Tab
    void MoveTab(int fromIndex, int toIndex);

    // Detach Tab
    void DetachTab(int index, QPoint&);

    // Attach Tab
    void AttachTab(QWidget *parent);

public Q_SLOTS:
    void setCurrentIndex(int index);
    void setCurrentWidget(QWidget *widget);

protected:

private:
    MHTabBar* m_tabBar;

    QList<QWidget*> m_Windows;
};

//////////////////////////////////////////////////////////////////////////////
// Summary:
//    MHDetachedWindow implements the WindowContainer for the Detached Widget
//
// Conditions:
//    Header : MHTabWidget.h
//////////////////////////////////////////////////////////////////////////////
class MHDetachedWindow : public QMainWindow
{
    Q_OBJECT
public:
    MHDetachedWindow(QWidget *parent = 0);
    ~MHDetachedWindow(void);

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void OnClose (QWidget* widget);
};

#endif // __MHTABWIDGET_H__
