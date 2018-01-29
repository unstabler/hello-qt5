#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void onMessageChanged();
        void onPushButtonClicked();

    private:
        Ui::MainWindow *ui;

        void initialize();
        void makeAMess();

};

#endif // MAINWINDOW_HPP
