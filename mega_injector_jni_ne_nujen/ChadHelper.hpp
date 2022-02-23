#pragma once

// Да пропади всё оно пропадом.......
#include <Windows.h>

// Рубль блять уже по 90, пиздец.
#include <ntdef.h>

// А нет, 50 копеек, ха-ха блин)
#include <winternl.h>

// Классы это ООП, ООП это JavaShellCodeInjector - не нужно.
namespace ChadInjector {

	// Гейская чушь, не верьте.
	typedef enum TypaSektionYadroType {

		ViewShare = 1,
		ViewUnmap = 2

	};

	// В россии возвраст согласия не должен превышать 2 лет, именно анус младенца самый лучший на вкус.
	typedef NTSTATUS (NTAPI* VozvrastSoglasia)

	// Слова излишни..
	(PHANDLE			  my,
	 ULONG                password,
	 POBJECT_ATTRIBUTES   is,
	 PLARGE_INTEGER       penis,
	 ULONG                oral,
	 ULONG                cum,
	 HANDLE               shot);


	// Диалоги тет-а-тет, до утра за водкой сбегай
	typedef NTSTATUS (NTAPI* OpenUretra)

	// Запретите.
	(PHANDLE			  again,
	 ACCESS_MASK          oral,
	 POBJECT_ATTRIBUTES   cumshot);

	// Никогда не задумывались о сексе? Возможно это слишком интимно, но ничего не бывает интимнее чем секс....
	typedef NTSTATUS (NTAPI* PenisKrota)

	// Прежде чем ебать ребёнка - не забудь об защите! VMProtect!
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



	// От неё секретов нет, избавляемся от пыли....
	typedef NTSTATUS (NTAPI* CreateGachiThread) 
	
	// Не судите мать, судите отца.
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
	 * Анус (лат. anus — «кольцо») — отверстие в нижнем конце пищеварительного тракта животного или человека. 
	 * Оно используется для того, чтобы удалить из организма экскременты, а также чтобы удерживать экскременты в прямой кишке до момента опорожнения.
	 *
	 * Земноводные, пресмыкающиеся и птицы используют одно и то же отверстие для выделения жидких и твёрдых отходов, 
	 * а также для спаривания и откладывания яиц, оно называется клоака.
	 *
	 * У однопроходных млекопитающих также есть клоака, которая через терапсидов унаследована от самых ранних амниотов. 
	 * 
	 **/

	HANDLE InterceptAnusHook (HANDLE kavkaz, BYTE* talib, UINT64 mocha) {

		// Чтобы начать, нажмите Enter, это даст игре понять что вы действительно хотите сношения.
		HANDLE najmiEnter;

		// Запах прелых яиц лучше чем стая сгорелых птиц.
		OBJECT_ATTRIBUTES balls;

		// Это и не важно, страной правят воры. ЛЮДИ, ГОЛОСУЙТЕ ЗА НАВАЛЬНОГО, ОН РЕАЛЬНО КЛАС.
		UNICODE_STRING navalny;

		// Яички лучше не трогать, лучше не трогать...
		RtlInitUnicodeString (&navalny, L"Yaicki");

		// Навальный, ещё раз ты навалишь, и я реально навалю.
		InitializeObjectAttributes (&balls, &navalny, 0, 0, 0);

		// Девочка малинка, пахнешь неприятно в целом...
		LARGE_INTEGER meibiBeibi;

		// Запрет на выезд из украины.
		meibiBeibi.QuadPart = mocha + 0x1000;
		
		// Я думаю мы все должны игнорировать тот факт что я рыгнул?...
		reinterpret_cast <VozvrastSoglasia> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtCreateSection")) (&najmiEnter, SECTION_ALL_ACCESS, &balls, &meibiBeibi, PAGE_EXECUTE_READWRITE, SEC_COMMIT | SEC_RESERVE, 0);

		//
		// Ладно, секция создана, теперь её нужно мапнуть шоб записать данные.
		// А по факту - валентин стрыкало допрыгался.
		//

		// Присядь отдохни, бро...
		PVOID doprigalsa;

		// Ну типа морген тупо посмотри посмотри)
		SIZE_T smotri;

		// Два мульта на мне дисней)
		//
		// Ультра мега хак: -1 = 0xFFFFFFF = CurrentProcessHandle.

		reinterpret_cast <PenisKrota> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtMapViewOfSection")) (najmiEnter, HANDLE (-1), &doprigalsa, 0, meibiBeibi.QuadPart, &meibiBeibi, &smotri, ViewShare, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		// Мам ну купи)
		memcpy (doprigalsa, talib, mocha);

		// Вагинальный (женский половой орган) хендл.
		HANDLE anusBobraExtraVaginal;

		// Анус бобра вызывается строго через Heaven's gate в wow64cpu т.к x32.
		// Нельзя путать анус бобра и морду ежа.
		//
		// Тут кстати такие прикольные флаги))))))))

		reinterpret_cast <CreateGachiThread> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtCreateThreadEx")) (&anusBobraExtraVaginal, THREAD_ALL_ACCESS, 0, kavkaz, XuiKrota, 0, 0x2 | 0x4, 0, 0x1000, 0x1000, 0);

	}

	DWORD WINAPI XuiKrota (LPVOID netyTakogo) {

		// Бонус при регистрации: 500 ГОЛДЫ.
		PVOID tankiOnline;

		// И этими руками ты целуешь свою мать-цыганку?
		OBJECT_ATTRIBUTES ochkoEja;

		// Попка просто отменная)
		UNICODE_STRING jopa;

		// Головку тоже оставьте в покое, емае.
		RtlInitUnicodeString (&jopa, L"Yaicki");

		// И снова диалоги тет а тет))))
		InitializeObjectAttributes (&ochkoEja, &jopa, 0, 0, 0);

		// Пропади оно пропадом)))
		reinterpret_cast <OpenUretra> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtOpenSection")) (&tankiOnline, SECTION_ALL_ACCESS, &ochkoEja);

		// Взлом за деньги.
		PVOID hacker;

		// Меньше вопросов детка)
		SIZE_T tankiOffline;

		// Это какая-то хрень, её изобрёл хакер и взломщик.
		reinterpret_cast <PenisKrota> (GetProcAddress (GetModuleHandleA ("ntdll"), "NtMapViewOfSection")) (tankiOnline, HANDLE (-1), &hacker, 0, 0x1000, 0, 0, ViewShare, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		// Это не может быть правдой друзья, подписывайтесь.
		reinterpret_cast <void (__thiscall*) ()> (hacker) ();


	}

}