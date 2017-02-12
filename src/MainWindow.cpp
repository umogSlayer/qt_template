#include "MainWindow.h"

#include "ui_MainWindow.h"

namespace template_app
{

MainWindow::MainWindow()
{
	ui_ = QSharedPointer<Ui::MainWindow>::create();
	ui_->setupUi(this);
	connect(
		ui_->action_quit,
		&QAction::triggered,
		[] {
			QApplication::quit();
		});
}

}