#include "MainWindow.h"

#include <QtWidgets/QApplication.h>

#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	int in_argc = 1;
	LPWSTR *in_argv = CommandLineToArgvW(GetCommandLineW(), &in_argc);
	using arg_container = QString;
	std::vector<arg_container> argv_converted;
	argv_converted.reserve(in_argc);
	std::transform(
		in_argv,
		in_argv + in_argc,
		std::back_inserter(argv_converted),
		[](wchar_t * const value) -> arg_container {
			return QString::fromStdWString(std::wstring(value));
		});
	std::string app_executable_arg = argv_converted[0].toStdString();
	app_executable_arg += '\0';
	// Передаём в QApplication только один параметр - это путь до исполняемого файла.
	char *qapp_argv[] = {
		const_cast<char *>(app_executable_arg.data()),
		nullptr,
	};
	int qapp_argc = 1;
#else
// На остальных платформах считаем, что используется кодировка UTF-8
int main(int in_argc, char *in_argv[])
{
	using arg_container = QString;
	std::vector<arg_container> argv_converted;
	argv_converted.reserve(in_argc);
	std::transform(
		in_argv,
		in_argv + in_argc,
		std::back_inserter(argv_converted),
		[](char * const value) -> arg_container {
			return QString::fromUtf8(value);
		});
	std::string app_executable_arg = argv_converted[0].toStdString();
	app_executable_arg += '\0';
	// Передаём в QApplication только один параметр - это путь до исполняемого файла.
	char *qapp_argv[] = {
		const_cast<char *>(app_executable_arg.data()),
		nullptr,
	};
	int qapp_argc = 1;
#endif
	QApplication app(qapp_argc, qapp_argv);

	template_app::MainWindow window;
	window.show();

	return app.exec();
}