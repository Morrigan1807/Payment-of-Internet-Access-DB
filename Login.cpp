#include "Login.h"

#include <Windows.h>

using namespace PaymentofInternetAccess;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Login());

	return 0;

}