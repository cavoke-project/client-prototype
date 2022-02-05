#include <QFileDialog>
#include "cavokeclientview.h"
#include "ui_cavokeclientview.h"

CavokeClientView::CavokeClientView(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CavokeClientView) {
    ui->setupUi(this);
}

CavokeClientView::~CavokeClientView() {
    delete ui;
}

void CavokeClientView::on_selectAppPathButton_clicked() {
    QString appPathName = QFileDialog::getOpenFileName(this, tr("Open App"), QDir::currentPath(),
                                                       tr("QML App (*.qml)"));
    if (!appPathName.isNull()) {
        ui->appPathInput->setText(appPathName);
    }
}

void CavokeClientView::on_runButton_clicked() {
    QString curAppPath = ui->appPathInput->text();
    if (!curAppPath.isNull()) {
        emit startGame(curAppPath);
    }
}
