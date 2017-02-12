#pragma once

#include <QtWidgets/QMainWindow.h>

namespace Ui
{
class MainWindow;
}

namespace template_app
{

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	virtual ~MainWindow() override = default;

private:
	QSharedPointer<Ui::MainWindow> ui_;
};

}