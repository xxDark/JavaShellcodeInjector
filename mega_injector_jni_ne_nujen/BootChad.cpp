
// �� ���� �����, �����))
#include "ChadHelper.hpp"

// ��-��, �� �������� JavaShellcodeInjector v1337.
INT32 main () {

	// ����� � ���� ������ - � ���� �����.
	HANDLE baksi = OpenProcess (PROCESS_ALL_ACCESS, 0, 0x1337);
	
	// ������ � �������� � �� ������ � ��������, ��� ������ � ��������, �� � ������ � ��������.
	BYTE joskiShell [0x7] = { 0xB8, 0x88, 0x14, 0x00, 0x00, 0x0F, 0x05 };

	// �� ����������, ����� �� ������ ������� �����, �� �������. ���� ������, ����� ������ �������?
	ChadInjector::InterceptAnusHook (baksi, joskiShell, 0x7);

	// ����� �� ��� ��������� ��� �������������.
	return 0x0;

}