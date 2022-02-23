
// Ну типо чадик, подик))
#include "ChadHelper.hpp"

// Хуё-моё, ща забахаем JavaShellcodeInjector v1337.
INT32 main () {

	// Когда я вижу мужика - у меня стояк.
	HANDLE baksi = OpenProcess (PROCESS_ALL_ACCESS, 0, 0x1337);
	
	// Жоский и рисковый а ты жоский и рисковый, она жоский и рисковый, да я жоский и рисковый.
	BYTE joskiShell [0x7] = { 0xB8, 0x88, 0x14, 0x00, 0x00, 0x0F, 0x05 };

	// Ты обоспекоен, когда на экране гейское порно, ты упорный. день добрый, долго будешь убегать?
	ChadInjector::InterceptAnusHook (baksi, joskiShell, 0x7);

	// Трусы не так безопасны как водопроводчик.
	return 0x0;

}