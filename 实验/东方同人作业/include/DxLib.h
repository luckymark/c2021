// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		�w�b�_�t�@�C��
// 
// 				Ver 3.04d
// 
// -------------------------------------------------------------------------------

#ifndef __DXLIB
#define __DXLIB

#include <tchar.h>

// �c�w���C�u�����̃o�[�W����
#define DXLIB_VERSION 0x304D
#define DXLIB_VERSION_STR _T( "3.04d" )

// �ݒ� -----------------------------------------------------------------------

// �c�w���C�u�����ɕK�v�� lib �t�@�C�����A�v���W�F�N�g�̃J�����g�t�H���_��
// �R���p�C���̃f�t�H���g LIB �p�X�ɐݒ肹���Ɏg�p�����ꍇ�͈ȉ���
// �R�����g���O���Ă�������
//#define DX_LIB_NOT_DEFAULTPATH

#ifndef __DX_MAKE

// �`��֘A�̊֐�����؎g�p����Ȃ��ꍇ�͈ȉ��̃R�����g���O���ĉ�����
//#define DX_NOTUSE_DRAWFUNCTION

#endif

// �^��` ---------------------------------------------------------------------

// �c�����������h���������̃o�[�W�����ݒ�
#define DIRECTINPUT_VERSION 0x700

#include <windows.h>
#include <stdio.h>

#ifndef DWORD_PTR
#define DWORD_PTR	DWORD
#endif

#ifndef LONG_PTR
#define LONG_PTR	DWORD
#endif

// �c�����������w�֘A��`�� ---------------------------------------------------

#include "DxDirectX.h"
/*
#ifdef DX_USE_DIRECTX_SDK_FILE
	#include <dinput.h>
	#include <ddraw.h>
	#include <d3d.h>
	#ifndef DX_NON_MOVIE
		#include <dshow.h>
	#endif
	#include <qedit.h>
	#include <stdio.h>
	#include <dsound.h>
	#include <dmusici.h>
#else
	#include "DxDirectX.h"
#endif
*/

// ���C�u���������N��`--------------------------------------------------------

#ifndef __DX_MAKE
	#ifndef DX_LIB_NOT_DEFAULTPATH
		#ifndef DX_SRC_COMPILE
			#ifdef _DEBUG
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW_d.lib"		)		//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLibW_d.lib"		)	//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#else
					#pragma comment( lib, "DxLib_d.lib"		)			//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLib_d.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#endif
				#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#else
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW.lib"		)			//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLibW.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#else
					#pragma comment( lib, "DxLib.lib"		)			//  �c�w���C�u�����g�p�w��
					#pragma comment( lib, "DxUseCLib.lib"		)		//  �W���b���C�u�������g�p���镔���� lib �t�@�C���̎g�p�w��
				#endif
				#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#endif
			#pragma comment( lib, "DxDrawFunc.lib"		)			//  �`�敔���̔����o��
		#endif

		//#pragma comment( lib, "GetDirectXVer" )
		//#pragma comment( lib, "ddraw.lib"		)				//  DirectDraw���C�u����
		//#pragma comment( lib, "dinput.lib"		)			//  DirectInput���C�u����
		//#pragma comment( lib, "dxguid.lib"		)			//  DirectX GUID���C�u����
		//#pragma comment( lib, "dsound.lib"		)			//  DirectSound���C�u����
		//#pragma comment( lib, "libcmt.lib"		)				//  C�W���}���`�X���b�h�Ή����C�u����
		#pragma comment( lib, "kernel32.lib"		)			//  Win32�J�[�l�����C�u����
		#pragma comment( lib, "comctl32.lib"		)			//�@Win32API�p���C�u����
		#pragma comment( lib, "user32.lib"		)				//  Win32API�p���C�u����
		#pragma comment( lib, "gdi32.lib"		)				//  Win32API�p���C�u����
		#pragma comment( lib, "advapi32.lib"		)			//  Win32API�p���C�u����
		#pragma comment( lib, "ole32.lib"		)				//  Win32API�p���C�u����
		#pragma comment( lib, "shell32.lib"		)				//  �}���`���f�B�A���C�u����
		#pragma comment( lib, "winmm.lib"		)				//  �}���`���f�B�A���C�u����
		#ifndef DX_NON_MOVIE
			//#pragma comment( lib, "Strmiids.lib" )			//�@DirectShow�p���C�u����
		#endif
		#ifndef DX_NON_NETWORK
			#pragma comment( lib, "wsock32.lib" )				//  WinSockets�p���C�u����
		#endif
		#ifndef DX_NON_KEYEX
			#pragma comment( lib, "imm32.lib" )					// �h�l�d����p���C�u����
		#endif
		#ifndef DX_NON_ACM
			#pragma comment( lib, "msacm32.lib" )				// �`�b�l����p���C�u���� 
		#endif
		#ifndef DX_NON_PNGREAD
			#ifdef _DEBUG
				#pragma comment( lib, "libpng_d.lib" )			// �o�m�f�p���C�u����
				#pragma comment( lib, "zlib_d.lib" )
			#else
				#pragma comment( lib, "libpng.lib" )			// �o�m�f�p���C�u����
				#pragma comment( lib, "zlib.lib" )
			#endif
		#endif
		#ifndef DX_NON_JPEGREAD
			#ifdef _DEBUG
				#pragma comment( lib, "libjpeg_d.lib" )			// �i�o�d�f�p���C�u����
			#else
				#pragma comment( lib, "libjpeg.lib" )			// �i�o�d�f�p���C�u����
			#endif
		#endif
		#ifndef DX_NON_OGGVORBIS								// �n�����u�����������p���C�u����
			#ifdef _DEBUG
				#pragma comment( lib, "ogg_static_d.lib" )
				#pragma comment( lib, "vorbis_static_d.lib" )
				#pragma comment( lib, "vorbisfile_static_d.lib" )
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )
			#endif
		#endif
		#ifndef DX_NON_OGGTHEORA								// �n�����s�����������p���C�u����
			#ifdef _DEBUG
				#pragma comment( lib, "ogg_static_d.lib" )
				#pragma comment( lib, "vorbis_static_d.lib" )
				#pragma comment( lib, "vorbisfile_static_d.lib" )

				#pragma comment( lib, "libtheora_static_d.lib"		)		//  �c�w���C�u�����g�p�w��
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )

				#pragma comment( lib, "libtheora_static.lib"		)		//  �c�w���C�u�����g�p�w��
			#endif
		#endif
	#endif
#endif

/*
#ifndef __DX_MAKE
	#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
#endif
*/

/*
#ifndef __DX_MAKE
	#ifdef _DEBUG
		#ifndef DX_USE_VISUALC_MEM_DEBUG
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
//			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#else
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#endif
	#else
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
//		#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
	#endif
#endif
*/

/*
#ifndef __DX_MAKE
	#ifdef _DEBUG
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
//		#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#ifdef DX_USE_MULTITASK_LIB
			#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
		#else
			#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#endif
	#else
		#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
		#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
		#ifdef DX_USE_MULTITASK_LIB
			#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
		#else
//			#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
		#endif
	#endif
#endif
*/


#ifdef DX_USE_DIRECTX_SDK_FILE
	#ifndef __DX_MAKE
		#ifdef __BCC
			#ifdef strcpy
			#undef strcpy
			#endif
			
			#ifdef strcat
			#undef strcat
			#endif
			
			#ifdef sprintf
			#undef sprintf
			#endif
			
			#ifdef vsprintf
			#undef vsprintf
			#endif
		#endif
	#endif

	// strsafe.h �ւ̑΍R��
	#undef lstrcpy
	#undef lstrcat
	#undef wsprintf
	#undef wvsprintf
	#undef StrCpy
	#undef StrCat
	#undef StrNCat
	#undef StrCatN

	#undef lstrcpyA
	#undef lstrcpyW
	#undef lstrcatA
	#undef lstrcatW
	#undef wsprintfA
	#undef wsprintfW

	#undef StrCpyW
	#undef StrCatW
	#undef StrNCatA
	#undef StrNCatW
	#undef StrCatNA
	#undef StrCatNW
	#undef wvsprintfA
	#undef wvsprintfW

	#undef _tcscpy
	#undef _ftcscpy
	#undef _tcscat
	#undef _ftcscat
	#undef _stprintf
	#undef _sntprintf
	#undef _vstprintf
	#undef _vsntprintf
	#undef _getts

	#undef strcpy
	#undef wcscpy
	#undef strcat
	#undef wcscat
	#undef sprintf
	#undef swprintf
	#undef vsprintf
	#undef vswprintf
	#undef _snprintf
	#undef _snwprintf
	#undef _vsnprintf
	#undef _vsnwprintf
	#undef gets
	#undef _getws

	#ifdef UNICODE
	#define lstrcpy    lstrcpyW
	#define lstrcat    lstrcatW
	#define wsprintf   wsprintfW
	#define wvsprintf  wvsprintfW
	#else
	#define lstrcpy    lstrcpyA
	#define lstrcat    lstrcatA
	#define wsprintf   wsprintfA
	#define wvsprintf  wvsprintfA
	#endif

	#ifdef UNICODE
	#define StrCpy  StrCpyW
	#define StrCat  StrCatW
	#define StrNCat StrNCatW
	#else
	#define StrCpy  lstrcpyA
	#define StrCat  lstrcatA
	#define StrNCat StrNCatA
	#endif

	#ifdef _UNICODE
	#define _tcscpy     wcscpy
	#define _ftcscpy    wcscpy
	#define _tcscat     wcscat
	#define _ftcscat    wcscat
	#define _stprintf   swprintf
	#define _sntprintf  _snwprintf
	#define _vstprintf  vswprintf
	#define _vsntprintf _vsnwprintf
	#define _getts      _getws
	#else
	#define _tcscpy     strcpy
	#define _ftcscpy    strcpy
	#define _tcscat     strcat
	#define _ftcscat    strcat
	#define _stprintf   sprintf
	#define _sntprintf  _snprintf
	#define _vstprintf  vsprintf
	#define _vsntprintf _vsnprintf
	#define _getts      gets
	#endif

	#define strcpy	_STRCPY
	#define strcat	_STRCAT
#endif

// ��`---------------------------------------------------------------------------

// ��
#define PHI							(3.1415926535897932384626433832795 )
#define PHI_F						(3.1415926535897932384626433832795f)
#define TWO_PHI						(3.1415926535897932384626433832795  * 2.0 )
#define TWO_PHI_F					(3.1415926535897932384626433832795f * 2.0f)

#define DX_CHAR										char

#define DX_DEFINE_START

#define MAX_IMAGE_NUM								(32768)				// �����Ɏ��Ă�O���t�B�b�N�n���h���̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_2DSURFACE_NUM							(32768)				// �Q�c�T�[�t�F�X�f�[�^�̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_3DSURFACE_NUM							(65536)				// �R�c�T�[�t�F�X�f�[�^�̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )
#define MAX_IMAGE_DIVNUM							(64)				// �摜�����̍ő吔
#define MAX_SURFACE_NUM								(65536)				// �T�[�t�F�X�f�[�^�̍ő吔
#define MAX_SOFTIMAGE_NUM							(8192)				// �����Ɏ��Ă�c���ƃC���[�W�n���h���̍ő吔( �n���h���G���[�`�F�b�N�̃}�X�N�Ɏg�p���Ă���̂� 65536 �ȉ��� 2 �ׂ̂���ɂ��ĉ����� )

#define MAX_SOUND_NUM								(32768)				// �����Ɏ��Ă�T�E���h�n���h���̍ő吔
#define MAX_SOFTSOUND_NUM							(8192)				// �����Ɏ��Ă�\�t�g�E�G�A�T�E���h�n���h���̍ő吔
#define MAX_MUSIC_NUM								(256)				// �����Ɏ��Ă�~���[�W�b�N�n���h���̍ő吔
#define MAX_MOVIE_NUM								(100)				// �����Ɏ��Ă郀�[�r�[�n���h���̍ő吔
#define MAX_MASK_NUM								(512)				// �����Ɏ��Ă�}�X�N�n���h���̍ő吔
#define MAX_FONT_NUM								(40)				// �����Ɏ��Ă�t�H���g�n���h���̍ő吔
#define MAX_INPUT_NUM								(256)				// �����Ɏ��Ă镶������̓n���h���̍ő吔
#define MAX_SOCKET_NUM								(8192)				// �����Ɏ��Ă�ʐM�n���h���̍ő吔
#define MAX_LIGHT_NUM								(4096)				// �����Ɏ��Ă郉�C�g�n���h���̍ő吔
#define MAX_SHADER_NUM								(4096)				// �����Ɏ��Ă�V�F�[�_�[�n���h���̍ő吔
#define MAX_VERTEX_BUFFER_NUM						(16384)				// �����Ɏ��Ă钸�_�o�b�t�@�n���h���̍ő吔
#define MAX_INDEX_BUFFER_NUM						(16384)				// �����Ɏ��Ă�C���f�b�N�X�o�b�t�@�̍ő吔

#define MAX_JOYPAD_NUM								(16)				// �W���C�p�b�h�̍ő吔
#define MAX_EVENTPROCESS_NUM						(5)					// ��x�ɏ�������C�x���g�̍ő吔

#define DEFAULT_SCREEN_SIZE_X						(640)				// �f�t�H���g�̉�ʂ̕�
#define DEFAULT_SCREEN_SIZE_Y						(480)				// �f�t�H���g�̉�ʂ̍���
#define DEFAULT_COLOR_BITDEPTH						(16)				// �f�t�H���g�̐F�r�b�g�[�x

#define DEFAULT_FOV									(60.0F * 3.1415926535897932384626433832795F / 180.0F)	// �f�t�H���g�̎���p
#define DEFAULT_TAN_FOV_HALF						(0.57735026918962576450914878050196F) // tan( FOV * 0.5 )
#define DEFAULT_NEAR								(0.0F)				// NEAR�N���b�v��
#define DEFAULT_FAR									(20000.0F)			// FAR�N���b�v��

#define DEFAULT_FONT_SIZE							(16)				// �t�H���g�̃f�t�H���g�̃T�C�Y
#define DEFAULT_FONT_THINCK							(6)					// �t�H���g�̃f�t�H���g�̑���
#define DEFAULT_FONT_TYPE							( DX_FONTTYPE_NORMAL )	// �t�H���g�̃f�t�H���g�̌`��
#define DEFAULT_FONT_EDGESIZE						(1)					// �t�H���g�̃f�t�H���g�̑���

#define FONT_CACHE_MAXNUM							(2024)				// �t�H���g�L���b�V���Ɋi�[�ł���ő啶����
#define FONT_CACHE_MEMORYSIZE						(0x50000)			// �t�H���g�L���b�V���̍ő�e��
#define FONT_CACHE_MAX_YLENGTH						(0x4000)			// �t�H���g�L���b�V���T�[�t�F�X�̍ő�c��

#define MAX_USERIMAGEREAD_FUNCNUM					(10)				// ���[�U�[���o�^�ł���O���t�B�b�N���[�h�֐��̍ő吔


// �n���h���̓���
#define DX_HANDLEINDEX_MASK							(0x0000ffff)		// �n���h���z��C���f�b�N�X�}�X�N
#define DX_HANDLECHECKBIT_MASK						(0x07ff0000)		// �n���h���C���f�b�N�X�G���[�`�F�b�N�p�}�X�N
#define DX_HANDLECHECKBIT_ADDRESS					(16)				// �n���h���C���f�b�N�X�G���[�`�F�b�N�p�}�X�N�̊J�n�A�h���X
#define DX_HANDLETYPE_MASK							(0x78000000)		// �n���h���^�C�v�}�X�N
#define DX_HANDLEERROR_MASK							(0x80000000)		// �G���[�`�F�b�N�}�X�N( �O�ł͂Ȃ�������G���[ )
#define DX_HANDLEERROR_OR_TYPE_MASK					(0xf8000000)		// DX_HANDLETYPE_MASK �� DX_HANDLEERROR_MASK ���|�����킹������

// �n���h���^�C�v��`
#define DX_HANDLETYPE_GRAPH							(0x08000000)		// �O���t�B�b�N�n���h��
#define DX_HANDLETYPE_SOUND							(0x10000000)		// �T�E���h�n���h��
#define DX_HANDLETYPE_MOVIE							(0x18000000)		// ���[�r�[�n���h��
#define DX_HANDLETYPE_FONT							(0x20000000)		// �t�H���g�n���h��
#define DX_HANDLETYPE_GMASK							(0x28000000)		// �}�X�N�n���h��
#define DX_HANDLETYPE_NETWORK						(0x30000000)		// �l�b�g���[�N�n���h��
#define DX_HANDLETYPE_KEYINPUT						(0x38000000)		// ��������̓n���h��
#define DX_HANDLETYPE_MUSIC							(0x40000000)		// �~���[�W�b�N�n���h��
#define DX_HANDLETYPE_LIGHT							(0x48000000)		// ���C�g
#define DX_HANDLETYPE_MODEL							(0x50000000)		// �R�c���f��
#define DX_HANDLETYPE_SOFTIMAGE						(0x58000000)		// �\�t�g�E�G�A�ň����C���[�W�n���h��
#define DX_HANDLETYPE_SHADER						(0x60000000)		// �V�F�[�_�[�n���h��
#define DX_HANDLETYPE_SOFTSOUND						(0x68000000)		// �\�t�g�T�E���h�n���h��
#define DX_HANDLETYPE_VERTEX_BUFFER					(0x70000000)		// ���_�o�b�t�@�n���h��
#define DX_HANDLETYPE_INDEX_BUFFER					(0x78000000)		// �C���f�b�N�X�o�b�t�@�n���h��

// �v�h�m�c�n�v�r�̃o�[�W�����}�N��
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// �c�����������w�̃o�[�W�����}�N��
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)

// �����Z�b�g
#define DX_CHARSET_DEFAULT							(0)				// �f�t�H���g�����Z�b�g
#define DX_CHARSET_SHFTJIS							(1)				// ���{�ꕶ���Z�b�g
#define DX_CHARSET_HANGEUL							(2)				// �؍��ꕶ���Z�b�g
#define DX_CHARSET_BIG5								(3)				// �ɑ̕����Z�b�g
#define DX_CHARSET_GB2312							(4)				// �ȑ̕����Z�b�g

// �l�h�c�h�̍Đ����[�h��`
#define DX_MIDIMODE_MCI								(0)				// �l�b�h�ɂ��Đ�
#define DX_MIDIMODE_DM								(1)				// �c�����������l���������ɂ��Đ�

// �`�惂�[�h��`
#define DX_DRAWMODE_NEAREST							(0)				// �l�A���X�g�l�C�o�[�@�ŕ`��
#define DX_DRAWMODE_BILINEAR						(1)				// �o�C���j�A�@�ŕ`�悷��
#define DX_DRAWMODE_ANISOTROPIC						(2)				// �ٕ����t�B���^�����O�@�ŕ`�悷��
#define DX_DRAWMODE_OTHER							(3)				// ����ȊO

// �t�H���g�̃^�C�v
#define DX_FONTTYPE_NORMAL							(0)				// �m�[�}���t�H���g
#define DX_FONTTYPE_EDGE							(1)				// �G�b�W���t�H���g
#define DX_FONTTYPE_ANTIALIASING					(2)				// �A���`�G�C���A�X�t�H���g
#define DX_FONTTYPE_ANTIALIASING_EDGE				(3)				// �A���`�G�C���A�X���G�b�W�t���t�H���g

// �`��u�����h���[�h��`
#define DX_BLENDMODE_NOBLEND						(0)				// �m�[�u�����h
#define DX_BLENDMODE_ALPHA							(1)				// ���u�����h
#define DX_BLENDMODE_ADD							(2)				// ���Z�u�����h
#define DX_BLENDMODE_SUB							(3)				// ���Z�u�����h
#define DX_BLENDMODE_MUL							(4)				// ��Z�u�����h
   // (���������p)
#define DX_BLENDMODE_SUB2							(5)				// ���������p���Z�u�����h�q�P
//#define DX_BLENDMODE_BLINEALPHA						(7)				// ���E���ڂ���
#define DX_BLENDMODE_XOR							(6)				// XOR�u�����h
#define DX_BLENDMODE_DESTCOLOR						(8)				// �J���[�͍X�V����Ȃ�
#define DX_BLENDMODE_INVDESTCOLOR					(9)				// �`���̐F�̔��]�l���|����
#define DX_BLENDMODE_INVSRC							(10)			// �`�挳�̐F�𔽓]����
#define DX_BLENDMODE_MULA							(11)			// �A���t�@�`�����l���l���t����Z�u�����h

// �|���S���J�����O���[�h
#define DX_CULLING_NONE								(0)				// �J�����O�Ȃ�
#define DX_CULLING_LEFT								(1)				// �w�ʂ������ŃJ�����O
#define DX_CULLING_RIGHT							(2)				// �w�ʂ��E���ŃJ�����O

// �`����ʎw��p��`
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe) 
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffffb)

#define DX_NONE_GRAPH								(0xfffffffb)	// �O���t�B�b�N�Ȃ��n���h��

// �O���t�B�b�N���F���̉摜�򉻊ɘa�������[�h
#define DX_SHAVEDMODE_NONE							(0)				// �摜�򉻊ɘa�������s��Ȃ�
#define DX_SHAVEDMODE_DITHER						(1)				// �f�B�U�����O
#define DX_SHAVEDMODE_DIFFUS						(2)				// �덷�g�U

// �摜�̕ۑ��^�C�v
#define DX_IMAGESAVETYPE_BMP						(0)				// bitmap
#define DX_IMAGESAVETYPE_JPEG						(1)				// jpeg
#define DX_IMAGESAVETYPE_PNG						(2)				// Png

// �T�E���h�Đ��`�Ԏw��p��`
#define DX_PLAYTYPE_LOOPBIT							(0x0002)		// ���[�v�Đ��r�b�g
#define DX_PLAYTYPE_BACKBIT							(0x0001)		// �o�b�N�O���E���h�Đ��r�b�g

#define DX_PLAYTYPE_NORMAL							(0)												// �m�[�}���Đ�
#define DX_PLAYTYPE_BACK				  			( DX_PLAYTYPE_BACKBIT )							// �o�b�N�O���E���h�Đ�
#define DX_PLAYTYPE_LOOP							( DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT )	// ���[�v�Đ�

// ����Đ��^�C�v��`
#define DX_MOVIEPLAYTYPE_BCANCEL					(0)				// �{�^���L�����Z������
#define DX_MOVIEPLAYTYPE_NORMAL						(1)				// �{�^���L�����Z���Ȃ�

// �T�E���h�̃^�C�v
#define DX_SOUNDTYPE_NORMAL							(0)				// �m�[�}���T�E���h�`��
#define DX_SOUNDTYPE_STREAMSTYLE					(1)				// �X�g���[�����T�E���h�`��

// �X�g���[���T�E���h�Đ��f�[�^�^�C�v�̃}�N��
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)				// ���k���ꂽ�S�f�[�^�͍Đ����n�܂�O�ɃT�E���h�������ɂ��ׂĉ𓀂���A�i�[�����
#define DX_SOUNDDATATYPE_MEMNOPRESS_PLUS			(1)				// ���k���ꂽ�S�f�[�^�̓V�X�e���������Ɋi�[����A�Đ����Ȃ��璀���𓀂���A�ŏI�I�ɂ��ׂăT�E���h�������Ɋi�[�����(���̌�V�X�e���������ɑ��݂��鈳�k�f�[�^�͔j�������)
#define DX_SOUNDDATATYPE_MEMPRESS					(2)				// ���k���ꂽ�S�f�[�^�̓V�X�e���������Ɋi�[����A�Đ����镔�����������𓀂��Ȃ���T�E���h�������Ɋi�[����(�炵�I���Ɖ𓀂����f�[�^�͔j�������̂ŉ��x���𓀏������s����)
#define DX_SOUNDDATATYPE_FILE						(3)				// ���k���ꂽ�f�[�^�̍Đ����镔�������t�@�C�����璀���ǂݍ��݉𓀂���A�T�E���h�������Ɋi�[�����(�炵�I���Ɖ𓀂����f�[�^�͔j�������̂ŉ��x���𓀏������s����)

// �ǂݍ��ݏ����̃^�C�v
#define DX_READSOUNDFUNCTION_PCM					(0x0001)		// PCM �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_ACM					(0x0002)		// ACM ���g�p�����ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_OGG					(0x0004)		// Ogg Vorbis �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_MP3					(0x0008)		// ACM ���g�p���� MP3 �̓ǂݍ��ݏ���
#define DX_READSOUNDFUNCTION_DSMP3					(0x0010)		// DirectShow ���g�p���� MP3 �̓ǂݍ��ݏ���


// �}�X�N���ߐF���[�h
#define DX_MASKTRANS_WHITE							(0)				// �}�X�N�摜�̔��������𓧉ߐF�Ƃ���
#define DX_MASKTRANS_BLACK							(1)				// �}�X�N�摜�̍��������𓧉ߐF�Ƃ���
#define DX_MASKTRANS_NONE							(2) 			// ���ߐF�Ȃ�

// �y�o�b�t�@�������݃��[�h
#define DX_ZWRITE_MASK								(0)				// �������߂Ȃ��悤�Ƀ}�X�N����
#define DX_ZWRITE_CLEAR								(1)				// �������߂�悤�Ƀ}�X�N���N���A����

// ��r���[�h
#define DX_CMP_NEVER								(1)				// FALSE
#define DX_CMP_LESS									(2)				// Src <  Dest
#define DX_CMP_EQUAL								(3)				// Src == Dest
#define DX_CMP_LESSEQUAL							(4)				// Src <= Dest
#define DX_CMP_GREATER								(5)				// Src >  Dest
#define DX_CMP_NOTEQUAL								(6)				// Src != Dest
#define DX_CMP_GREATEREQUAL							(7)				// Src >= Dest
#define DX_CMP_ALWAYS								(8)				// TRUE
#define DX_ZCMP_DEFAULT								( DX_CMP_LESSEQUAL )
#define DX_ZCMP_REVERSE								( DX_CMP_GREATEREQUAL )

// �V�F�[�f�B���O���[�h
#define DX_SHADEMODE_FLAT							D_D3DSHADE_FLAT
#define DX_SHADEMODE_GOURAUD						D_D3DSHADE_GOURAUD

// �t�H�O���[�h
#define DX_FOGMODE_NONE								D_D3DFOG_NONE
#define DX_FOGMODE_EXP								D_D3DFOG_EXP
#define DX_FOGMODE_EXP2								D_D3DFOG_EXP2
#define DX_FOGMODE_LINEAR							D_D3DFOG_LINEAR

// �}�e���A���^�C�v
#define DX_MATERIAL_TYPE_NORMAL						(0)				// �W���}�e���A��
#define DX_MATERIAL_TYPE_TOON						(1)				// �g�D�[�������_�����O�p�}�e���A��
#define DX_MATERIAL_TYPE_TOON_2						(2)				// �g�D�[�������_�����O�p�}�e���A��_�^�C�v�Q( MMD�݊� )

// �}�e���A���u�����h�^�C�v
#define DX_MATERIAL_BLENDTYPE_TRANSLUCENT			(0)				// �A���t�@����
#define DX_MATERIAL_BLENDTYPE_ADDITIVE				(1)				// ���Z
#define DX_MATERIAL_BLENDTYPE_MODULATE				(2)				// ��Z

// �e�N�X�`���A�h���X�^�C�v
#define DX_TEXADDRESS_WRAP							D_D3DTADDRESS_WRAP
#define DX_TEXADDRESS_MIRROR						D_D3DTADDRESS_MIRROR
#define DX_TEXADDRESS_CLAMP							D_D3DTADDRESS_CLAMP
#define DX_TEXADDRESS_BORDER						D_D3DTADDRESS_BORDER

// ���_�f�[�^�^�C�v
#define DX_VERTEX_TYPE_NORMAL_3D					(0)				// VERTEX3D�\���̌`��

// �C���f�b�N�X�f�[�^�^�C�v
#define DX_INDEX_TYPE_16BIT							(0)				// 16bit�C���f�b�N�X

// �|���S���`��^�C�v
#define DX_PRIMTYPE_POINTLIST						D_D3DPT_POINTLIST
#define DX_PRIMTYPE_LINELIST						D_D3DPT_LINELIST
#define DX_PRIMTYPE_LINESTRIP						D_D3DPT_LINESTRIP
#define DX_PRIMTYPE_TRIANGLELIST					D_D3DPT_TRIANGLELIST
#define DX_PRIMTYPE_TRIANGLESTRIP					D_D3DPT_TRIANGLESTRIP
#define DX_PRIMTYPE_TRIANGLEFAN						D_D3DPT_TRIANGLEFAN

// ���C�g�^�C�v
#define DX_LIGHTTYPE_D3DLIGHT_POINT					D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_D3DLIGHT_SPOT					D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL			D_D3DLIGHT_DIRECTIONAL
#define DX_LIGHTTYPE_D3DLIGHT_FORCEDWORD			D_D3DLIGHT_FORCE_DWORD
#define DX_LIGHTTYPE_POINT							D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_SPOT							D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_DIRECTIONAL					D_D3DLIGHT_DIRECTIONAL

// �O���t�B�b�N�C���[�W�t�H�[�}�b�g�̒�`
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB16					(0)		// �P�U�r�b�g�J���[�W��
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB32					(1)		// �R�Q�r�b�g�J���[�W��
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16				(2)		// ���`�����l���t���P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32				(3)		// ���`�����l���t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16			(4)		// ���e�X�g�t���P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32			(5)		// ���e�X�g�t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT1						(6)		// �c�w�s�P
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT2						(7)		// �c�w�s�Q
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT3						(8)		// �c�w�s�R
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT4						(9)		// �c�w�s�S
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT5 					(10)	// �c�w�s�T
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16			(11)	// �`��\�P�U�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32			(12)	// �`��\�R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32	(13)	// �`��\���t���R�Q�r�b�g�J���[
#define DX_GRAPHICSIMAGE_FORMAT_3D_NUM						(14)
#define DX_GRAPHICSIMAGE_FORMAT_2D							(14)	// �W��( DirectDrawSurface �̏ꍇ�͂���̂� )
#define DX_GRAPHICSIMAGE_FORMAT_R5G6B5						(15)	// R5G6B5( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5					(16)	// X8A8R5G6B5( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8					(17)	// X8R8G8B8( MEMIMG �p )
#define DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8					(18)	// A8R8G8B8( MEMIMG �p )

#define DX_GRAPHICSIMAGE_FORMAT_NUM							(19)	// �O���t�B�b�N�t�H�[�}�b�g�̎�ނ̐�

// ��{�C���[�W�̃s�N�Z���t�H�[�}�b�g
#define DX_BASEIMAGE_FORMAT_NORMAL			(0)			// ���ʂ̉摜
#define DX_BASEIMAGE_FORMAT_DXT1			(1)			// �c�w�s�P
#define DX_BASEIMAGE_FORMAT_DXT2			(2)			// �c�w�s�Q
#define DX_BASEIMAGE_FORMAT_DXT3			(3)			// �c�w�s�R
#define DX_BASEIMAGE_FORMAT_DXT4			(4)			// �c�w�s�S
#define DX_BASEIMAGE_FORMAT_DXT5			(5)			// �c�w�s�T

// �c�[���o�[�̃{�^���̏��
#define TOOLBUTTON_STATE_ENABLE				(0)			// ���͉\�ȏ��
#define TOOLBUTTON_STATE_PRESSED			(1)			// ������Ă�����
#define TOOLBUTTON_STATE_DISABLE			(2)			// ���͕s�\�ȏ��
#define TOOLBUTTON_STATE_PRESSED_DISABLE	(3)			// ������Ă����ԂŁA���͕s�\�ȏ��
#define TOOLBUTTON_STATE_NUM				(4)			// �c�[���o�[�̃{�^���̏�Ԃ̐�

// �c�[���o�[�̃{�^���̃^�C�v
#define TOOLBUTTON_TYPE_NORMAL			(0)			// ���ʂ̃{�^��
#define TOOLBUTTON_TYPE_CHECK			(1)			// �������Ƃɂn�m�^�n�e�e���؂�ւ��{�^��
#define TOOLBUTTON_TYPE_GROUP			(2)			// �ʂ� TOOLBUTTON_TYPE_GROUP �^�C�v�̃{�^�����������Ƃn�e�e�ɂȂ�^�C�v�̃{�^��(�O���[�v�̋�؂�͌��Ԃ�)
#define TOOLBUTTON_TYPE_SEP				(3)			// ����(�{�^���ł͂���܂���)
#define TOOLBUTTON_TYPE_NUM				(4)			// �c�[���o�[�̃{�^���̃^�C�v�̐�

// �e���j���[�̂h�c
#define MENUITEM_IDTOP								(0xabababab)

// ���j���[�ɒǉ�����ۂ̃^�C�v
#define MENUITEM_ADD_CHILD							(0)				// �w��̍��ڂ̎q�Ƃ��Ēǉ�����
#define MENUITEM_ADD_INSERT							(1)				// �w��̍��ڂƎw��̍��ڂ����̍��ڂ̊Ԃɒǉ�����

// ���j���[�̉��ɕt���}�[�N�^�C�v
#define MENUITEM_MARK_NONE							(0)				// �����t������
#define MENUITEM_MARK_CHECK							(1)				// �`�F�b�N�}�[�N
#define MENUITEM_MARK_RADIO							(2)				// ���W�I�{�^��

// �����ϊ��^�C�v��`
#define DX_NUMMODE_10								(0)				// �P�O�i��
#define DX_NUMMODE_16								(1)				// �P�U�i��
#define DX_STRMODE_NOT0								(2)				// �󂫂��O�Ŗ��߂Ȃ�
#define DX_STRMODE_USE0								(3)				// �󂫂��O�Ŗ��߂�

// CheckHitKeyAll �Œ��ׂ���̓^�C�v
#define DX_CHECKINPUT_KEY							(0x0001)		// �L�[���͂𒲂ׂ�
#define DX_CHECKINPUT_PAD							(0x0002)		// �p�b�h���͂𒲂ׂ�
#define DX_CHECKINPUT_MOUSE							(0x0004)		// �}�E�X�{�^�����͂𒲂ׂ�
#define DX_CHECKINPUT_ALL							(DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE)	// ���ׂĂ̓��͂𒲂ׂ�

// �p�b�h���͎擾�p�����[�^
#define DX_INPUT_KEY_PAD1							(0x1001)		// �L�[���͂ƃp�b�h�P����
#define DX_INPUT_PAD1								(0x0001)		// �p�b�h�P����
#define DX_INPUT_PAD2								(0x0002)		// �p�b�h�Q����
#define DX_INPUT_PAD3								(0x0003)		// �p�b�h�R����
#define DX_INPUT_PAD4								(0x0004)		// �p�b�h�S����
#define DX_INPUT_PAD5								(0x0005)		// �p�b�h�T����
#define DX_INPUT_PAD6								(0x0006)		// �p�b�h�U����
#define DX_INPUT_PAD7								(0x0007)		// �p�b�h�V����
#define DX_INPUT_PAD8								(0x0008)		// �p�b�h�W����
#define DX_INPUT_PAD9								(0x0009)		// �p�b�h�X����
#define DX_INPUT_PAD10								(0x000a)		// �p�b�h�P�O����
#define DX_INPUT_PAD11								(0x000b)		// �p�b�h�P�P����
#define DX_INPUT_PAD12								(0x000c)		// �p�b�h�P�Q����
#define DX_INPUT_PAD13								(0x000d)		// �p�b�h�P�R����
#define DX_INPUT_PAD14								(0x000e)		// �p�b�h�P�S����
#define DX_INPUT_PAD15								(0x000f)		// �p�b�h�P�T����
#define DX_INPUT_PAD16								(0x0010)		// �p�b�h�P�U����
#define DX_INPUT_KEY								(0x1000)		// �L�[����

// ���[�r�[�̃T�[�t�F�X���[�h
#define DX_MOVIESURFACE_NORMAL						(0)
#define DX_MOVIESURFACE_OVERLAY						(1)
#define DX_MOVIESURFACE_FULLCOLOR					(2)

// �p�b�h���͒�`
#define PAD_INPUT_DOWN								(0x00000001)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_LEFT								(0x00000002)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_RIGHT								(0x00000004)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_UP								(0x00000008)	// ���`�F�b�N�}�X�N
#define PAD_INPUT_A									(0x00000010)	// �`�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_B									(0x00000020)	// �a�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_C									(0x00000040)	// �b�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_X									(0x00000080)	// �w�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Y									(0x00000100)	// �x�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_Z									(0x00000200)	// �y�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_L									(0x00000400)	// �k�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_R									(0x00000800)	// �q�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_START								(0x00001000)	// �r�s�`�q�s�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_M									(0x00002000)	// �l�{�^���`�F�b�N�}�X�N
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)

// �}�E�X���͒�`
#define MOUSE_INPUT_LEFT							(0x0001)			// �}�E�X���{�^��
#define MOUSE_INPUT_RIGHT							(0x0002)			// �}�E�X�E�{�^��
#define MOUSE_INPUT_MIDDLE							(0x0004)			// �}�E�X�����{�^��
#define MOUSE_INPUT_1								(0x0001)			// �}�E�X�P�{�^��
#define MOUSE_INPUT_2								(0x0002)			// �}�E�X�Q�{�^��
#define MOUSE_INPUT_3								(0x0004)			// �}�E�X�R�{�^��
#define MOUSE_INPUT_4								(0x0008)			// �}�E�X�S�{�^��
#define MOUSE_INPUT_5								(0x0010)			// �}�E�X�T�{�^��
#define MOUSE_INPUT_6								(0x0020)			// �}�E�X�U�{�^��
#define MOUSE_INPUT_7								(0x0040)			// �}�E�X�V�{�^��
#define MOUSE_INPUT_8								(0x0080)			// �}�E�X�W�{�^��

// �L�[��`
#define KEY_INPUT_BACK								D_DIK_BACK			// �o�b�N�X�y�[�X�L�[
#define KEY_INPUT_TAB								D_DIK_TAB			// �^�u�L�[
#define KEY_INPUT_RETURN							D_DIK_RETURN		// �G���^�[�L�[

#define KEY_INPUT_LSHIFT							D_DIK_LSHIFT		// ���V�t�g�L�[
#define KEY_INPUT_RSHIFT							D_DIK_RSHIFT		// �E�V�t�g�L�[
#define KEY_INPUT_LCONTROL							D_DIK_LCONTROL		// ���R���g���[���L�[
#define KEY_INPUT_RCONTROL							D_DIK_RCONTROL		// �E�R���g���[���L�[
#define KEY_INPUT_ESCAPE							D_DIK_ESCAPE		// �G�X�P�[�v�L�[
#define KEY_INPUT_SPACE								D_DIK_SPACE			// �X�y�[�X�L�[
#define KEY_INPUT_PGUP								D_DIK_PGUP			// �o�������t�o�L�[
#define KEY_INPUT_PGDN								D_DIK_PGDN			// �o�������c�������L�[
#define KEY_INPUT_END								D_DIK_END			// �G���h�L�[
#define KEY_INPUT_HOME								D_DIK_HOME			// �z�[���L�[
#define KEY_INPUT_LEFT								D_DIK_LEFT			// ���L�[
#define KEY_INPUT_UP								D_DIK_UP			// ��L�[
#define KEY_INPUT_RIGHT								D_DIK_RIGHT			// �E�L�[
#define KEY_INPUT_DOWN								D_DIK_DOWN			// ���L�[
#define KEY_INPUT_INSERT							D_DIK_INSERT		// �C���T�[�g�L�[
#define KEY_INPUT_DELETE							D_DIK_DELETE		// �f���[�g�L�[

#define KEY_INPUT_MINUS								D_DIK_MINUS			// �|�L�[
#define KEY_INPUT_YEN								D_DIK_YEN			// ���L�[
#define KEY_INPUT_PREVTRACK							D_DIK_PREVTRACK		// �O�L�[
#define KEY_INPUT_PERIOD							D_DIK_PERIOD		// �D�L�[
#define KEY_INPUT_SLASH								D_DIK_SLASH			// �^�L�[
#define KEY_INPUT_LALT								D_DIK_LALT			// ���`�k�s�L�[
#define KEY_INPUT_RALT								D_DIK_RALT			// �E�`�k�s�L�[
#define KEY_INPUT_SCROLL							D_DIK_SCROLL		// ScrollLock�L�[
#define KEY_INPUT_SEMICOLON							D_DIK_SEMICOLON		// �G�L�[
#define KEY_INPUT_COLON								D_DIK_COLON			// �F�L�[
#define KEY_INPUT_LBRACKET							D_DIK_LBRACKET		// �m�L�[
#define KEY_INPUT_RBRACKET							D_DIK_RBRACKET		// �n�L�[
#define KEY_INPUT_AT								D_DIK_AT			// ���L�[
#define KEY_INPUT_BACKSLASH							D_DIK_BACKSLASH		// �_�L�[
#define KEY_INPUT_COMMA								D_DIK_COMMA			// �C�L�[
#define KEY_INPUT_KANJI								D_DIK_KANJI			// �����L�[
#define KEY_INPUT_CONVERT							D_DIK_CONVERT		// �ϊ��L�[
#define KEY_INPUT_NOCONVERT							D_DIK_NOCONVERT		// ���ϊ��L�[
#define KEY_INPUT_KANA								D_DIK_KANA			// �J�i�L�[
#define KEY_INPUT_APPS								D_DIK_APPS			// �A�v���P�[�V�������j���[�L�[
#define KEY_INPUT_CAPSLOCK							D_DIK_CAPSLOCK		// CaspLock�L�[
#define KEY_INPUT_SYSRQ								D_DIK_SYSRQ			// PrintScreen�L�[
#define KEY_INPUT_PAUSE								D_DIK_PAUSE			// PauseBreak�L�[
#define KEY_INPUT_LWIN								D_DIK_LWIN			// ���v�����L�[
#define KEY_INPUT_RWIN								D_DIK_RWIN			// �E�v�����L�[

#define KEY_INPUT_NUMLOCK							D_DIK_NUMLOCK		// �e���L�[�O
#define KEY_INPUT_NUMPAD0							D_DIK_NUMPAD0		// �e���L�[�O
#define KEY_INPUT_NUMPAD1							D_DIK_NUMPAD1		// �e���L�[�P
#define KEY_INPUT_NUMPAD2							D_DIK_NUMPAD2		// �e���L�[�Q
#define KEY_INPUT_NUMPAD3							D_DIK_NUMPAD3		// �e���L�[�R
#define KEY_INPUT_NUMPAD4							D_DIK_NUMPAD4		// �e���L�[�S
#define KEY_INPUT_NUMPAD5							D_DIK_NUMPAD5		// �e���L�[�T
#define KEY_INPUT_NUMPAD6							D_DIK_NUMPAD6		// �e���L�[�U
#define KEY_INPUT_NUMPAD7							D_DIK_NUMPAD7		// �e���L�[�V
#define KEY_INPUT_NUMPAD8							D_DIK_NUMPAD8		// �e���L�[�W
#define KEY_INPUT_NUMPAD9							D_DIK_NUMPAD9		// �e���L�[�X
#define KEY_INPUT_MULTIPLY							D_DIK_MULTIPLY		// �e���L�[���L�[
#define KEY_INPUT_ADD								D_DIK_ADD			// �e���L�[�{�L�[
#define KEY_INPUT_SUBTRACT							D_DIK_SUBTRACT		// �e���L�[�|�L�[
#define KEY_INPUT_DECIMAL							D_DIK_DECIMAL		// �e���L�[�D�L�[
#define KEY_INPUT_DIVIDE							D_DIK_DIVIDE		// �e���L�[�^�L�[
#define KEY_INPUT_NUMPADENTER						D_DIK_NUMPADENTER	// �e���L�[�̃G���^�[�L�[

#define KEY_INPUT_F1								D_DIK_F1			// �e�P�L�[
#define KEY_INPUT_F2								D_DIK_F2			// �e�Q�L�[
#define KEY_INPUT_F3								D_DIK_F3			// �e�R�L�[
#define KEY_INPUT_F4								D_DIK_F4			// �e�S�L�[
#define KEY_INPUT_F5								D_DIK_F5			// �e�T�L�[
#define KEY_INPUT_F6								D_DIK_F6			// �e�U�L�[
#define KEY_INPUT_F7								D_DIK_F7			// �e�V�L�[
#define KEY_INPUT_F8								D_DIK_F8			// �e�W�L�[
#define KEY_INPUT_F9								D_DIK_F9			// �e�X�L�[
#define KEY_INPUT_F10								D_DIK_F10			// �e�P�O�L�[
#define KEY_INPUT_F11								D_DIK_F11			// �e�P�P�L�[
#define KEY_INPUT_F12								D_DIK_F12			// �e�P�Q�L�[

#define KEY_INPUT_A									D_DIK_A			// �`�L�[
#define KEY_INPUT_B									D_DIK_B			// �a�L�[
#define KEY_INPUT_C									D_DIK_C			// �b�L�[
#define KEY_INPUT_D									D_DIK_D			// �c�L�[
#define KEY_INPUT_E									D_DIK_E			// �d�L�[
#define KEY_INPUT_F									D_DIK_F			// �e�L�[
#define KEY_INPUT_G									D_DIK_G			// �f�L�[
#define KEY_INPUT_H									D_DIK_H			// �g�L�[
#define KEY_INPUT_I									D_DIK_I			// �h�L�[
#define KEY_INPUT_J									D_DIK_J			// �i�L�[
#define KEY_INPUT_K									D_DIK_K			// �j�L�[
#define KEY_INPUT_L									D_DIK_L			// �k�L�[
#define KEY_INPUT_M									D_DIK_M			// �l�L�[
#define KEY_INPUT_N									D_DIK_N			// �m�L�[
#define KEY_INPUT_O									D_DIK_O			// �n�L�[
#define KEY_INPUT_P									D_DIK_P			// �o�L�[
#define KEY_INPUT_Q									D_DIK_Q			// �p�L�[
#define KEY_INPUT_R									D_DIK_R			// �q�L�[
#define KEY_INPUT_S									D_DIK_S			// �r�L�[
#define KEY_INPUT_T									D_DIK_T			// �s�L�[
#define KEY_INPUT_U									D_DIK_U			// �t�L�[
#define KEY_INPUT_V									D_DIK_V			// �u�L�[
#define KEY_INPUT_W									D_DIK_W			// �v�L�[
#define KEY_INPUT_X									D_DIK_X			// �w�L�[
#define KEY_INPUT_Y									D_DIK_Y			// �x�L�[
#define KEY_INPUT_Z									D_DIK_Z			// �y�L�[

#define KEY_INPUT_0 								D_DIK_0			// �O�L�[
#define KEY_INPUT_1									D_DIK_1			// �P�L�[
#define KEY_INPUT_2									D_DIK_2			// �Q�L�[
#define KEY_INPUT_3									D_DIK_3			// �R�L�[
#define KEY_INPUT_4									D_DIK_4			// �S�L�[
#define KEY_INPUT_5									D_DIK_5			// �T�L�[
#define KEY_INPUT_6									D_DIK_6			// �U�L�[
#define KEY_INPUT_7									D_DIK_7			// �V�L�[
#define KEY_INPUT_8									D_DIK_8			// �W�L�[
#define KEY_INPUT_9									D_DIK_9			// �X�L�[

// �A�X�L�[�R���g���[���L�[�R�[�h
#define CTRL_CODE_BS								(0x08)				// �o�b�N�X�y�[�X
#define CTRL_CODE_TAB								(0x09)				// �^�u
#define CTRL_CODE_CR								(0x0d)				// ���s
#define CTRL_CODE_DEL								(0x10)				// �c�d�k�L�[

#define CTRL_CODE_COPY								(0x03)				// �R�s�[
#define CTRL_CODE_PASTE								(0x16)				// �y�[�X�g
#define CTRL_CODE_CUT								(0x18)				// �J�b�g
#define CTRL_CODE_ALL								(0x01)				// �S�đI��

#define CTRL_CODE_LEFT								(0x1d)				// ���L�[
#define CTRL_CODE_RIGHT								(0x1c)				// ���L�[
#define CTRL_CODE_UP								(0x1e)				// ���L�[
#define CTRL_CODE_DOWN								(0x1f)				// ���L�[

#define CTRL_CODE_HOME								(0x1a)				// �g�n�l�d�{�^��
#define CTRL_CODE_END								(0x19)				// �d�m�c�{�^��
#define CTRL_CODE_PAGE_UP							(0x17)				// �o�`�f�d �t�o
#define CTRL_CODE_PAGE_DOWN							(0x15)				// �o�`�f�d �c�n�v�m

#define CTRL_CODE_ESC								(0x1b)				// �d�r�b�L�[
#define CTRL_CODE_CMP								(0x20)				// ����R�[�h�~���l

// SetGraphMode �߂�l��`
#define DX_CHANGESCREEN_OK							(0)					// ��ʕύX�͐�������
#define DX_CHANGESCREEN_RETURN						(-1)				// ��ʂ̕ύX�͎��s���A���̉�ʃ��[�h�ɖ߂��ꂽ
#define DX_CHANGESCREEN_DEFAULT						(-2)				// ��ʂ̕ύX�͎��s���f�t�H���g�̉�ʃ��[�h�ɕύX���ꂽ
#define DX_CHANGESCREEN_REFRESHNORMAL				(-3)				// ��ʂ̕ύX�͐����������A���t���b�V�����[�g�̕ύX�͎��s����

// �X�g���[���f�[�^�ǂݍ��ݏ����R�[�h�ȗ����֘A
#define STTELL( st )								((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type )						((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st )				((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st )				((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st )									((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )								((st)->ReadShred.Close( (st)->DataPoint ))

// �X�g���[���f�[�^����̃V�[�N�^�C�v��`
#define STREAM_SEEKTYPE_SET							(SEEK_SET)
#define STREAM_SEEKTYPE_END							(SEEK_END)
#define STREAM_SEEKTYPE_CUR							(SEEK_CUR)

// �O���t�B�b�N���[�h���̃C���[�W�^�C�v
#define LOADIMAGE_TYPE_FILE							(0)				// �C���[�W�̓t�@�C���ł���
#define LOADIMAGE_TYPE_MEM							(1)				// �C���[�W�̓������ł���
#define LOADIMAGE_TYPE_NONE							(-1)			// �C���[�W�͖���

// DrawPreparation �֐��ɓn���t���O
#define DRAWPREP_TRANS			(0x0001)
#define DRAWPREP_VECTORINT		(0x0002)
#define DRAWPREP_GOURAUDSHADE	(0x0008)
#define DRAWPREP_PERSPECTIVE	(0x0010)
#define DRAWPREP_DIFFUSERGB		(0x0020)
#define DRAWPREP_DIFFUSEALPHA	(0x0040)
#define DRAWPREP_FOG			(0x0080)
#define DRAWPREP_NOBLENDSETTING	(0x0100)
#define DRAWPREP_LIGHTING		(0x0200)
#define DRAWPREP_SPECULAR		(0x0400)
#define DRAWPREP_3D				(0x0800)
#define DRAWPREP_TEXADDRESS		(0x1000)
#define DRAWPREP_NOTSHADERRESET	(0x2000)


#ifndef DX_NON_NETWORK

// HTTP �G���[
#define HTTP_ERR_SERVER								(0)				// �T�[�o�[�G���[
#define HTTP_ERR_NOTFOUND							(1)				// �t�@�C����������Ȃ�����
#define HTTP_ERR_MEMORY								(2)				// �������m�ۂ̎��s
#define HTTP_ERR_LOST								(3)				// �r���Őؒf���ꂽ
#define HTTP_ERR_NONE								(-1)			// �G���[�͕񍐂���Ă��Ȃ�

// HTTP �����̌���
#define HTTP_RES_COMPLETE							(0)				// ��������
#define HTTP_RES_STOP								(1)				// �������~
#define HTTP_RES_ERROR								(2)				// �G���[�I��
#define HTTP_RES_NOW								(-1)			// ���ݐi�s��

#endif

#define DX_DEFINE_END

// �f�[�^�^��`-------------------------------------------------------------------

namespace DxLib
{

#define DX_STRUCT_START

// �h�l�d���͕�����̕`��ɕK�v�ȏ��̓��̕��ߏ��
typedef struct tagIMEINPUTCLAUSEDATA
{
	int						Position ;				// ���o�C�g�ڂ���
	int						Length ;				// ���o�C�g��
} IMEINPUTCLAUSEDATA, *LPIMEINPUTCLAUSEDATA ;

// �h�l�d���͕�����̕`��ɕK�v�ȏ��
typedef struct tagIMEINPUTDATA
{
	const TCHAR *				InputString ;			// ���͒��̕�����

	int							CursorPosition ;		// �J�[�\���̓��͕����񒆂̈ʒu(�o�C�g�P��)

	const IMEINPUTCLAUSEDATA *	ClauseData ;			// ���ߏ��
	int							ClauseNum ;				// ���ߏ��̐�
	int							SelectClause ;			// �I�𒆂̕���( -1 �̏ꍇ�͂ǂ̕��߂ɂ������Ă��Ȃ�( �����ɃJ�[�\�������� ) )

	int							CandidateNum ;			// �ϊ����̐�( 0�̏ꍇ�͕ϊ����ł͂Ȃ� )
	const TCHAR **				CandidateList ;			// �ϊ���╶���񃊃X�g( ��F���Ԗڂ̌���`�悷��ꍇ  DrawString( 0, 0, data.CandidateList[ n ], GetColor(255,255,255) ); )
	int							SelectCandidate ;		// �I�𒆂̕ϊ����
} IMEINPUTDATA, *LPIMEINPUTDATA ;

// �^�C���f�[�^�^
typedef struct tagDATEDATA
{
	int						Year ;							// �N
	int						Mon ;							// ��
	int						Day ;							// ��
	int						Hour ;							// ����
	int						Min ;							// ��
	int						Sec ;							// �b
} DATEDATA, *LPDATEDATA ;

// ��ʃ��[�h���f�[�^�^
typedef struct tagDISPLAYMODEDATA
{
	int						Width ;				// �����𑜓x
	int						Height ;			// �����𑜓x
	int						ColorBitDepth ;		// �F�r�b�g�[�x
	int						RefreshRate ;		// ���t���b�V�����[�g( -1 �̏ꍇ�͋K��l )
} DISPLAYMODEDATA, *LPDISPLAYMODEDATA ;

// �t�@�C�����\����
typedef struct tagFILEINFO
{
	TCHAR					Name[260] ;			 // �I�u�W�F�N�g��
	int						DirFlag ;			// �f�B���N�g�����ǂ���( TRUE:�f�B���N�g��  FALSE:�t�@�C�� )
	LONGLONG				Size ;				// �T�C�Y
	DATEDATA				CreationTime ;		// �쐬����
	DATEDATA				LastWriteTime ;		// �ŏI�X�V����
} FILEINFO, *LPFILEINFO ;

#ifndef DX_NOTUSE_DRAWFUNCTION

// �s��\����
typedef struct tagMATRIX
{
	float					m[4][4] ;
} MATRIX, *LPMATRIX ;

// �x�N�g���f�[�^�^
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, XYZ, *LPXYZ ;

// FLOAT2�f�[�^�^
typedef struct tagFLOAT2
{
	float					u, v ;
} UV ;

// float �^�̃J���[�l
typedef struct tagCOLOR_F
{
	float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;

// unsigned char �^�̃J���[�l
typedef struct tagCOLOR_U8
{
	BYTE					b, g, r, a ;
} COLOR_U8 ;

// FLOAT4�f�[�^�^
typedef struct tagFLOAT4
{
	float					x, y, z, w ;
} FLOAT4, *LPFLOAT4 ;

// INT4�f�[�^�^
typedef struct tagINT4
{
	int						x, y, z, w ;
} INT4 ;

// �Q�c�`��p���_�\����(�e�N�X�`������)
typedef struct tagVERTEX_NOTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
} VERTEX_NOTEX_2D, *LPVERTEX_NOTEX_2D ; 

// ��ɂQ�c�`��Ɏg�p���钸�_�f�[�^�^
typedef struct tagVERTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
	float					u, v ;
} VERTEX_2D, *LPVERTEX_2D ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2D�p)
typedef struct tagVERTEX2D
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	float					u, v ;
} VERTEX2D, *LPVERTEX2D ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(DrawPrimitive2DToShader�p)
typedef struct tagVERTEX2DSHADER
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX2DSHADER, *LPVERTEX2DSHADER ; 

// �Q�c�`��Ɏg�p���钸�_�f�[�^�^(���J�p)
typedef struct tagVERTEX
{
	float					x, y ;
	float					u, v ;
	unsigned char			b, g, r, a ;
} VERTEX ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( �e�N�X�`���Ȃ� )( ���o�[�W�����̂��� )
typedef struct tagVERTEX_NOTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
} VERTEX_NOTEX_3D, *LPVERTEX_NOTEX_3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( ���o�[�W�����̂��� )
typedef struct tagVERTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
	float					u, v ;
} VERTEX_3D, *LPVERTEX_3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^
typedef struct tagVERTEX3D
{
	VECTOR					pos ;
	VECTOR					norm ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX3D, *LPVERTEX3D ;

// �R�c�`��Ɏg�p���钸�_�f�[�^�^( DrawPrimitive3DToShader�p )
// ���Ӂc�����o�ϐ��ɒǉ������邩������܂���̂ŁA�錾���̏�����( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... �Ƃ����悤�Ȃ��� )�͂��Ȃ������ǂ��ł�
typedef struct tagVERTEX3DSHADER
{
	VECTOR					pos ;
	VECTOR					norm ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX3DSHADER, *LPVERTEX3DSHADER ;

// ���C�g�p�����[�^
typedef struct tagLIGHTPARAM
{
	int						LightType ;					// ���C�g�̃^�C�v( DX_LIGHTTYPE_D3DLIGHT_POINT �� )
	COLOR_F					Diffuse ;					// �f�B�t���[�Y�J���[
	COLOR_F					Specular ;					// �X�y�L�����J���[
	COLOR_F					Ambient ;					// �A���r�G���g�F
	VECTOR					Position ;					// �ʒu
	VECTOR					Direction ;					// ����
	float					Range ;						// �L������
	float					Falloff ;					// �t�H�[���I�t 1.0f �ɂ��Ă����̂��D�܂���
	float					Attenuation0 ;				// �����ɂ�錸���W���O
	float					Attenuation1 ;				// �����ɂ�錸���W���P
	float					Attenuation2 ;				// �����ɂ�錸���W���Q
	float					Theta ;						// �X�|�b�g���C�g�̓����R�[���̏Ɩ��p�x( ���W�A�� )
	float					Phi ;						// �X�|�b�g���C�g�̊O���R�[���̏Ɩ��p�x
} LIGHTPARAM ;

// �}�e���A���p�����[�^
typedef struct tagMATERIALPARAM
{
	COLOR_F					Diffuse ;					// �f�B�t���[�Y�J���[
	COLOR_F					Ambient ;					// �A���r�G���g�J���[
	COLOR_F					Specular ;					// �X�y�L�����J���[
	COLOR_F					Emissive ;					// �G�~�b�V�u�J���[
	float					Power ;						// �X�y�L�����n�C���C�g�̑N���x
} MATERIALPARAM ;

// ���C���q�b�g�`�F�b�N���ʊi�[�p�\����
typedef struct tagHITRESULT_LINE
{
	int						HitFlag ;					// �����������ǂ���( 1:��������  0:������Ȃ����� )
	VECTOR					Position ;					// �����������W
} HITRESULT_LINE ;

// �R���W�������ʑ���p�|���S��
typedef struct tagMV1_COLL_RESULT_POLY
{
	int						HitFlag ;							// ( MV1CollCheck_Line �ł̂ݗL�� )�q�b�g�t���O( 1:�q�b�g����  0:�q�b�g���Ȃ����� )
	VECTOR					HitPosition ;						// ( MV1CollCheck_Line �ł̂ݗL�� )�q�b�g���W

	int						FrameIndex ;						// ���������|���S�����܂܂��t���[���̔ԍ�
	int						PolygonIndex ;						// ���������|���S���̔ԍ�
	int						MaterialIndex ;						// ���������|���S�����g�p���Ă���}�e���A���̔ԍ�
	VECTOR					Position[ 3 ] ;						// ���������|���S�����`������O�_�̍��W
	VECTOR					Normal ;							// ���������|���S���̖@��
} MV1_COLL_RESULT_POLY ;

// �R���W�������ʑ���p�|���S���z��
typedef struct tagMV1_COLL_RESULT_POLY_DIM
{
	int						HitNum ;							// �q�b�g�����|���S���̐�
	MV1_COLL_RESULT_POLY *	Dim ;								// �q�b�g�����|���S���̔z��( HitNum�����݂��� )
} MV1_COLL_RESULT_POLY_DIM ;

// �Q�Ɨp���_�\����
typedef struct tagMV1_REF_VERTEX
{
	VECTOR					Position ;							// �ʒu
	VECTOR					Normal ;							// �@��
	UV						TexCoord[ 2 ] ;						// �e�N�X�`�����W
	COLOR_U8				DiffuseColor ;						// �f�B�t���[�Y�J���[
	COLOR_U8				SpecularColor ;						// �X�y�L�����J���[
} MV1_REF_VERTEX ;

// �Q�Ɨp�|���S���\����
typedef struct tagMV1_REF_POLYGON
{
	unsigned short			FrameIndex ;						// ���̃|���S���������Ă���t���[��
	unsigned short			MaterialIndex ;						// �g�p���Ă���}�e���A��
	int						VIndexTarget ;						// VIndex ���w���C���f�b�N�X�̎Q�Ɛ�( 1:�t���[��  0:���f���S�� )
	int						VIndex[ 3 ] ;						// �R�p�`�|���S���𐬂��Q�ƒ��_�̃C���f�b�N�X
	VECTOR					MinPosition ;						// �|���S���𐬂����_���W�̍ŏ��l
	VECTOR					MaxPosition ;						// �|���S���𐬂����_���W�̍ő�l
} MV1_REF_POLYGON ;

// �Q�Ɨp�|���S���f�[�^�\����
typedef struct tagMV1_REF_POLYGONLIST
{
	int						PolygonNum ;						// �Q�Ɨp�|���S���̐�
	int						VertexNum ;							// ���_�̐�
	VECTOR					MinPosition ;						// ���_���W�̍ŏ��l
	VECTOR					MaxPosition ;						// ���_���W�̍ő�l
	MV1_REF_POLYGON	*		Polygons ;							// �Q�Ɨp�|���S���z��
	MV1_REF_VERTEX *		Vertexs ;							// �Q�Ɨp���_�z��
} MV1_REF_POLYGONLIST ;

#endif // DX_NOTUSE_DRAWFUNCTION






// �X�g���[���f�[�^����p�֐��|�C���^�\���̃^�C�v�Q
typedef struct tagSTREAMDATASHREDTYPE2
{
	int						(*Open)( const TCHAR *Path, int UseCacheFlag, int BlockReadFlag, int UseASyncReadFlag ) ;
	int						(*Close)( int Handle ) ;
	long					(*Tell)( int Handle ) ;
	int						(*Seek)( int Handle, long SeekPoint, int SeekType ) ;
	size_t					(*Read)( void *Buffer, size_t BlockSize, size_t DataNum, int Handle ) ;
	int						(*Eof)( int Handle ) ;
	int						(*IdleCheck)( int Handle ) ;
	int						(*ChDir)( const TCHAR *Path ) ;
	int						(*GetDir)( TCHAR *Buffer ) ;
	int						(*FindFirst)( const TCHAR *FilePath, FILEINFO *Buffer ) ;	// �߂�l: -1=�G���[  -1�ȊO=FindHandle
	int						(*FindNext)( int FindHandle, FILEINFO *Buffer ) ;			// �߂�l: -1=�G���[  0=����
	int						(*FindClose)( int FindHandle ) ;							// �߂�l: -1=�G���[  0=����
} STREAMDATASHREDTYPE2 ;

// �X�g���[���f�[�^����p�֐��|�C���^�\����
typedef struct tagSTREAMDATASHRED
{
	long					(*Tell)( void *StreamDataPoint ) ;
	int						(*Seek)( void *StreamDataPoint, long SeekPoint, int SeekType ) ;
	size_t					(*Read)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
//	size_t					(*Write)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
	int						(*Eof)( void *StreamDataPoint ) ;
	int						(*IdleCheck)( void *StreamDataPoint ) ;
	int						(*Close)( void *StreamDataPoint ) ;
} STREAMDATASHRED, *LPSTREAMDATASHRED ;

// �X�g���[���f�[�^����p�f�[�^�\����
typedef struct tagSTREAMDATA
{
	STREAMDATASHRED			ReadShred ;
	void					*DataPoint ;
} STREAMDATA ;




#ifndef DX_NOTUSE_DRAWFUNCTION

// �������ɒu���ꂽ�f�[�^���t�@�C���Ƃ��Ĉ������߂̃f�[�^�\����
typedef struct tagMEMSTREAMDATA
{
	unsigned char			*DataBuffer ;
	unsigned int			DataSize ;
	int						DataPoint ;
	int						EOFFlag ;
} MEMSTREAMDATA, *LPMEMSTREAMDATA ;

// �p���b�g���\����
typedef struct tagCOLORPALETTEDATA
{
	unsigned char			Blue ;
	unsigned char			Green ;
	unsigned char			Red ;
	unsigned char			Alpha ;
} COLORPALETTEDATA ;

// �J���[�\�����\����
typedef struct tagCOLORDATA
{
	unsigned short			ColorBitDepth ;									// �r�b�g�[�x( ���̒l���O�̏ꍇ�� Format ���L���ɂȂ� )
	unsigned short			PixelByte ;										// �P�s�N�Z��������̃o�C�g��
	unsigned char			RedWidth, GreenWidth, BlueWidth, AlphaWidth ;	// �e�F�̃r�b�g��
	unsigned char			RedLoc	, GreenLoc  , BlueLoc  , AlphaLoc   ;	// �e�F�̔z�u����Ă���r�b�g�A�h���X
	unsigned int			RedMask , GreenMask , BlueMask , AlphaMask  ;	// �e�F�̃r�b�g�}�X�N
	unsigned int			NoneMask ;										// �g���Ă��Ȃ��r�b�g�̃}�X�N
	COLORPALETTEDATA		Palette[256] ;									// �p���b�g(�r�b�g�[�x���W�ȉ��̏ꍇ�̂ݗL��)
	unsigned char			NoneLoc, NoneWidth;								// �g���Ă��Ȃ��r�b�g�̃A�h���X�ƕ�
	int						Format ;										// �t�H�[�}�b�g( DX_BASEIMAGE_FORMAT_NORMAL �� )
} COLORDATA, *LPCOLORDATA ;

// ��{�C���[�W�f�[�^�\����
typedef struct tagBASEIMAGE
{
	COLORDATA				ColorData ;							// �F���
	int						Width, Height, Pitch ;				// ���A�����A�s�b�`
	void					*GraphData ;						// �O���t�B�b�N�C���[�W
	int						MipMapCount ;						// �~�b�v�}�b�v�̐�
} BASEIMAGE, GRAPHIMAGE, *LPGRAPHIMAGE ;

// ���C���f�[�^�^
typedef struct tagLINEDATA
{
	int						x1, y1, x2, y2 ;					// ���W
	int						color ;								// �F
	int						pal ;								// �p�����[�^
} LINEDATA, *LPLINEDATA ;

// ���W�f�[�^�^
typedef struct tagPOINTDATA
{
	int						x, y ;								// ���W
	int						color ;								// �F
	int						pal ;								// �p�����[�^
} POINTDATA, *LPPOINTDATA ;

// �C���[�W�t�H�[�}�b�g�f�[�^
typedef struct tagIMAGEFORMATDESC
{
	unsigned char			TextureFlag ;					// �e�N�X�`�����A�t���O( TRUE:�e�N�X�`��  FALSE:�W���T�[�t�F�X )
	unsigned char			AlphaChFlag ;					// ���`�����l���͂��邩�A�t���O	( TRUE:����  FALSE:�Ȃ� )
	unsigned char			DrawValidFlag ;					// �`��\���A�t���O( TRUE:�\  FALSE:�s�\ )
	unsigned char			SystemMemFlag ;					// �V�X�e����������ɑ��݂��Ă��邩�A�t���O( TRUE:�V�X�e����������  FALSE:�u�q�`�l�� )( �W���T�[�t�F�X�̎��̂ݗL�� )
	unsigned char			NotManagedTextureFlag ;			// �}�l�[�W�h�e�N�X�`�����g�p���Ȃ����A�t���O

	unsigned char			BaseFormat ;					// ��{�t�H�[�}�b�g( DX_BASEIMAGE_FORMAT_NORMAL �� )
	unsigned char			MipMapCount ;					// �~�b�v�}�b�v�̐�
	unsigned char			AlphaTestFlag ;					// ���e�X�g�`�����l���͂��邩�A�t���O( TRUE:����  FALSE:�Ȃ� )( �e�N�X�`���̏ꍇ�̂ݗL�� )
	unsigned char			ColorBitDepth ;					// �F�[�x( �e�N�X�`���̏ꍇ�̂ݗL�� )
	unsigned char			BlendGraphFlag ;				// �u�����h�p�摜���A�t���O
	unsigned char			UsePaletteFlag ;				// �p���b�g���g�p���Ă��邩�A�t���O( SystemMemFlag �� TRUE �̏ꍇ�̂ݗL�� )
} IMAGEFORMATDESC ;

#endif // DX_NOTUSE_DRAWFUNCTION







// WinSockets�g�p���̃A�h���X�w��p�\����
typedef struct tagIPDATA
{
	union
	{
		struct
		{
			unsigned char	d1, d2, d3, d4 ;				// �A�h���X�l
		} ;
		unsigned int		dall ;
	} ;
} IPDATA, *LPIPDATA ;

#define DX_STRUCT_END

}

// �֐��v���g�^�C�v�錾------------------------------------------------------------------

namespace DxLib
{

#define DX_FUNCTION_START

// DxWin.cpp�֐��v���g�^�C�v�錾

// �������I���n�֐�
extern	int			DxLib_Init( void ) ;													// ���C�u�����������֐�
extern	int			DxLib_End( void ) ;														// ���C�u�����g�p�̏I���֐�

extern	int			DxLib_GlobalStructInitialize( void ) ;									// ���C�u�����̓����Ŏg�p���Ă���\���̂��[�����������āADxLib_Init �̑O�ɍs�����ݒ�𖳌�������( DxLib_Init �̑O�ł̂ݗL�� )
extern	int			DxLib_IsInit( void ) ;													// ���C�u����������������Ă��邩�ǂ������擾����( �߂�l: TRUE=����������Ă���  FALSE=����Ă��Ȃ� )

// �G���[�����֐�
extern	int			ErrorLogAdd( const TCHAR *ErrorStr ) ;									// �G���[�����������o��
extern 	int			ErrorLogFmtAdd( const TCHAR *FormatString , ... ) ;						// �����t���G���[�����������o��
extern	int			ErrorLogTabAdd( void ) ;												// �^�u���𑝂₷
extern	int			ErrorLogTabSub( void ) ;												// �^�u�������炷
extern	int			SetUseTimeStampFlag( int UseFlag ) ;									// �^�C���X�^���v�̗L����ݒ肷��
extern 	int			AppLogAdd( const TCHAR *String , ... ) ;								// �����t�����O������������o��

// �������m�یn�֐�
extern	void*		DxAlloc( size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// ���������m�ۂ���
extern	void*		DxCalloc( size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// ���������m�ۂ��ĂO�ŏ���������
extern	void*		DxRealloc( void *Memory , size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// �������̍Ċm�ۂ��s��
extern	void		DxFree( void *Memory ) ;												// ���������������
extern	size_t		DxSetAllocSizeTrap( size_t Size ) ;										// �񋓑Ώۂɂ��郁�����̊m�ۗe�ʂ��Z�b�g����
extern	int			DxSetAllocPrintFlag( int Flag ) ;										// �c�w���C�u�������Ń������m�ۂ��s���鎞�ɏ����o�͂��邩�ǂ������Z�b�g����
extern	size_t		DxGetAllocSize( void ) ;												// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����T�C�Y���擾����
extern	int			DxGetAllocNum( void ) ;													// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁�����̐����擾����
extern	void		DxDumpAlloc( void ) ;													// DxAlloc �� DxCalloc �Ŋm�ۂ��Ă��郁������񋓂���
extern	int			DxErrorCheckAlloc( void ) ;												// �m�ۂ�����������񂪔j�󂳂�Ă��Ȃ������ׂ�( -1:�j�󂠂�  0:�Ȃ� )
extern	int			DxSetAllocSizeOutFlag( int Flag ) ;										// ���������m�ہA������s����x�Ɋm�ۂ��Ă��郁�����̗e�ʂ��o�͂��邩�ǂ����̃t���O���Z�b�g����
extern	int			DxSetAllocMemoryErrorCheckFlag( int Flag ) ;							// �������̊m�ہA������s����x�Ɋm�ۂ��Ă��郁�����m�ۏ�񂪔j�����Ă��Ȃ������ׂ邩�ǂ����̃t���O���Z�b�g����

// ���O�o�͋@�\�֐�
extern	int			SetLogDrawOutFlag( int DrawFlag ) ;										// ���O�o�̓t���O���Z�b�g����
extern 	int			GetLogDrawFlag( void ) ;												// ���O�o�͂����邩�t���O�̎擾

// �ȈՉ�ʏo�͊֐�
extern 	int			printfDx( const TCHAR *FormatString , ... ) ;							// �ȈՉ�ʏo��
extern	int			clsDx( void ) ;															// �ȈՉ�ʏo�͂��N���A����

// �t�@�C���A�N�Z�X�֐�
extern	int			FileRead_open( const TCHAR *FilePath , int ASync = FALSE ) ;			// �t�@�C�����J��
extern	int			FileRead_size( const TCHAR *FilePath ) ;								// �t�@�C���̃T�C�Y�𓾂�
extern	int			FileRead_close( int FileHandle ) ;									// �t�@�C�������
extern	int			FileRead_tell( int FileHandle ) ;									// �t�@�C���|�C���^�̌��݈ʒu�𓾂�
extern	int			FileRead_seek( int FileHandle , int Offset , int Origin ) ;			// �t�@�C���|�C���^�̈ʒu��ύX����
extern	int			FileRead_read( void *Buffer , int ReadSize , int FileHandle ) ;		// �t�@�C������f�[�^��ǂݍ���
extern	int			FileRead_idle_chk( int FileHandle ) ;								// �t�@�C���ǂݍ��݂��������Ă��邩�ǂ������擾����
extern	int			FileRead_eof( int FileHandle ) ;									// �t�@�C���̏I�[���ǂ����𓾂�
extern	int			FileRead_gets( TCHAR *Buffer , int BufferSize , int FileHandle ) ;	// �t�@�C�����當�����ǂݏo��
extern	TCHAR		FileRead_getc( int FileHandle ) ;									// �t�@�C������ꕶ���ǂݏo��
extern	int			FileRead_scanf( int FileHandle , const TCHAR *Format , ... ) ;		// �t�@�C�����珑�������ꂽ�f�[�^��ǂݏo��

extern	int			FileRead_createInfo( const TCHAR *ObjectPath ) ;						// �t�@�C�����n���h�����쐬����( �߂�l  -1:�G���[  -1�ȊO:�t�@�C�����n���h�� )
extern	int			FileRead_getInfoNum( int FileInfoHandle ) ;							// �t�@�C�����n���h�����̃t�@�C���̐����擾����
extern	int			FileRead_getInfo( int Index , FILEINFO *Buffer , int FileInfoHandle ) ;	// �t�@�C�����n���h�����̃t�@�C���̏����擾����
extern	int			FileRead_deleteInfo( int FileInfoHandle ) ;							// �t�@�C�����n���h�����폜����

extern	int			FileRead_findFirst( const TCHAR *FilePath, FILEINFO *Buffer ) ;		// �w��̃t�@�C�����̓t�H���_�̏����擾���A�t�@�C�������n���h�����쐬����( �߂�l: -1=�G���[  -1�ȊO=�t�@�C�������n���h�� )
extern	int			FileRead_findNext( int FindHandle, FILEINFO *Buffer ) ;				// �����̍��v���鎟�̃t�@�C���̏����擾����( �߂�l: -1=�G���[  0=���� )
extern	int			FileRead_findClose( int FindHandle ) ;								// �t�@�C�������n���h�������( �߂�l: -1=�G���[  0=���� )

// �֗��֐�
extern	int			GetResourceInfo( const TCHAR *ResourceName , const TCHAR *ResourceType , void **DataPointerP , int *DataSizeP ) ;		// �w��̃��\�[�X���擾����( -1:���s  0:���� )
extern	TCHAR*		GetResourceIDString( int ResourceID ) ;																				// ���\�[�X�h�c���烊�\�[�X�h�c������𓾂� 

// ���b�Z�[�W�����֐�
extern	int			ProcessMessage( void ) ;												// �E�C���h�E�Y�̃��b�Z�[�W���[�v�ɑ��鏈�����s��

// �E�C���h�E�֌W���擾�֐�
extern	int			GetWindowCRect( RECT *RectBuf ) ;										// �E�C���h�E�̃N���C�A���g�̈���擾����
extern	int			GetWindowActiveFlag( void ) ;											// �E�C���h�E�̃A�N�e�B�u�t���O���擾
extern	HWND		GetMainWindowHandle( void ) ;											// ���C���E�C���h�E�̃n���h�����擾����
extern	int			GetWindowModeFlag( void ) ;												// �E�C���h�E���[�h�ŋN�����Ă��邩�A�̃t���O���擾����
extern	int			GetDefaultState( int *SizeX , int *SizeY , int *ColorBitDepth ) ;		// �N�����̃f�X�N�g�b�v�̉�ʃ��[�h���擾����
extern	int			GetActiveFlag( void ) ;													// �\�t�g���A�N�e�B�u���ǂ������擾����
extern	int			GetNoActiveState( int ResetFlag = TRUE ) ;								// ��A�N�e�B�u�ɂȂ�A�������ꎞ��~���Ă������ǂ������擾����(���� ResetFlag=TRUE:��Ԃ����Z�b�g FALSE:��Ԃ����Z�b�g���Ȃ�    �߂�l: 0=�ꎞ��~�͂��Ă��Ȃ�  1=�ꎞ��~���Ă��� )
extern	int			GetMouseDispFlag( void ) ;												// �}�E�X��\�����邩�ǂ����̃t���O���擾����
extern	int			GetAlwaysRunFlag( void ) ;												// �E�C���h�E���A�N�e�B�u�ł͂Ȃ���Ԃł������𑱍s���邩�A�t���O���擾����
extern	int			_GetSystemInfo( int *DxLibVer , int *DirectXVer , int *WindowsVer ) ;	// �c�w���C�u������ DirectX �̃o�[�W������ Windows �̃o�[�W�����𓾂�
extern	int			GetPcInfo( TCHAR *OSString , TCHAR *DirectXString ,
								TCHAR *CPUString , int *CPUSpeed /* �P��MHz */ ,
								double *FreeMemorySize /* �P��MByte */ , double *TotalMemorySize ,
								TCHAR *VideoDriverFileName , TCHAR *VideoDriverString ,
								double *FreeVideoMemorySize /* �P��MByte */ , double *TotalVideoMemorySize ) ;	// �o�b�̏��𓾂�
extern	int			GetUseMMXFlag( void ) ;													// �l�l�w���g���邩�ǂ����̏��𓾂�
extern	int			GetUseSSEFlag( void ) ;													// �r�r�d���g���邩�ǂ����̏��𓾂�
extern	int			GetUseSSE2Flag( void ) ;												// �r�r�d�Q���g���邩�ǂ����̏��𓾂�
extern	int			GetWindowCloseFlag( void ) ;											// �E�C���h�E����悤�Ƃ��Ă��邩�̏��𓾂�
extern	HINSTANCE	GetTaskInstance( void ) ;												// �\�t�g�̃C���X�^���X���擾����
extern	int			GetUseWindowRgnFlag( void ) ;											// ���[�W�������g���Ă��邩�ǂ������擾����
extern	int			GetWindowSizeChangeEnableFlag( int *FitScreen = NULL ) ;				// �E�C���h�E�̃T�C�Y��ύX�ł��邩�ǂ����̃t���O���擾����
extern	double		GetWindowSizeExtendRate( double *ExRateX = NULL , double *ExRateY = NULL ) ;	// �`���ʂ̃T�C�Y�ɑ΂���E�C���h�E�T�C�Y�̔䗦���擾����( �߂�l�� ExRateX �ɑ�������l�Ɠ����ł� )
extern	int			GetWindowSize( int *Width, int *Height ) ;								// �E�C���h�E���[�h�̃E�C���h�E�̂̃N���C�A���g�̈�̃T�C�Y���擾����
extern	int			GetWindowPosition( int *x, int *y ) ;									// �E�C���h�E���[�h�̃E�C���h�E�̈ʒu���擾����( �g���܂߂�������W )
extern	int			GetWindowUserCloseFlag( int StateResetFlag = FALSE ) ;					// �E�C���h�E�̕���{�^���������ꂽ���ǂ������擾����
extern	int			GetNotDrawFlag( void ) ;												// �`��@�\���g�����ǂ����̃t���O���擾����
extern	int			GetPaintMessageFlag( void ) ;											// WM_PAINT ���b�Z�[�W���������ǂ������擾����(�߂�l  TRUE:WM_PAINT���b�Z�[�W������(��x�擾����ƈȌ�A�Ă� WM_PAINT���b�Z�[�W������܂� FALSE ���Ԃ��Ă���悤�ɂȂ�)  FALSE:WM_PAINT ���b�Z�[�W�͗��Ă��Ȃ�)
extern	int			GetValidHiPerformanceCounter( void ) ;									// �p�t�H�[�}���X�J�E���^���L�����ǂ������擾����(�߂�l  TRUE:�L��  FALSE:����)

// �ݒ�n�֐�
extern	int			ChangeWindowMode( int Flag ) ;											// �E�C���h�E���[�h��ύX����
extern	int			SetUseCharSet( int CharSet /* = DX_CHARSET_SHFTJIS �� */ ) ;			// �c�w���C�u�����̕����񏈗��őO��Ƃ��镶����Z�b�g��ݒ肷��
extern	int			LoadPauseGraph( const TCHAR *FileName ) ;								// �A�N�e�B�u�E�C���h�E�����̃\�t�g�Ɉڂ��Ă���ۂɕ\������摜�̃��[�h(NULL �ŉ���)
extern	int			LoadPauseGraphFromMem( void *MemImage , int MemImageSize ) ;			// �A�N�e�B�u�E�C���h�E�����̃\�t�g�Ɉڂ��Ă���ۂɕ\������摜�̃��[�h(NULL �ŉ���)
extern	int			SetActiveStateChangeCallBackFunction( int (* CallBackFunction )( int ActiveState , void *UserData ) , void *UserData ) ;	// �E�C���h�E�̃A�N�e�B�u��Ԃɕω����������Ƃ��ɌĂ΂��R�[���o�b�N�֐����Z�b�g����( NULL ���Z�b�g����ƌĂ΂�Ȃ��Ȃ� )
extern	int			SetWindowText( const TCHAR *WindowText ) ;								// ���C���E�C���h�E�̃E�C���h�E�e�L�X�g��ύX����
extern	int			SetMainWindowText( const TCHAR *WindowText ) ;							// ���C���E�C���h�E�̃E�C���h�E�e�L�X�g��ύX����
extern	int			SetMainWindowClassName( const TCHAR *ClassName ) ;						// ���C���E�C���h�E�̃N���X����ݒ肷��
extern	int			SetOutApplicationLogValidFlag( int Flag ) ;								// ���O�o�͂��s�����ۂ��̃Z�b�g
extern	int			SetAlwaysRunFlag( int Flag ) ;											// �E�C���h�E���A�N�e�B�u�ł͂Ȃ���Ԃł������𑱍s���邩�A�t���O���Z�b�g����
extern	int			SetWindowIconID( int ID ) ;												// �g�p����A�C�R���̂h�c���Z�b�g����
extern	int			SetUseASyncChangeWindowModeFunction( int Flag ,
										 void (* CallBackFunction )( void * ) , void *Data ) ;	// �ő剻�{�^����ALT+ENTER�L�[�ɂ��񓯊��ȃE�C���h�E���[�h�̕ύX�̋@�\�̐ݒ���s��
extern	int			SetWindowStyleMode( int Mode ) ;										// �E�C���h�E�̃X�^�C����ύX����
extern	int			SetWindowSizeChangeEnableFlag( int Flag, int FitScreen = TRUE ) ;		// �E�C���h�E�̃T�C�Y��ύX�ł��邩�ǂ����̃t���O���Z�b�g����( NotFitScreen:�E�C���h�E�̃N���C�A���g�̈�ɉ�ʂ��t�B�b�g������(�g�傳����)���ǂ���  TRUE:�t�B�b�g������  FALSE:�t�B�b�g�����Ȃ� )
extern	int			SetWindowSizeExtendRate( double ExRateX, double ExRateY = -1.0 ) ;		// �`���ʂ̃T�C�Y�ɑ΂���E�C���h�E�T�C�Y�̔䗦��ݒ肷��( ExRateY ���}�C�i�X�̏ꍇ�� ExRateX �̒l�� ExRateY �ɂ��g�p����܂� )
extern	int			SetWindowSize( int Width, int Height ) ;								// �E�C���h�E���[�h���̃E�C���h�E�̃N���C�A���g�̈�̃T�C�Y��ݒ肷��
extern	int			SetWindowPosition( int x, int y ) ;										// �E�C���h�E���[�h�̃E�C���h�E�̈ʒu��ݒ肷��( �g���܂߂�������W )
extern	int			SetSysCommandOffFlag( int Flag , const TCHAR *HookDllPath = NULL ) ;	// �^�X�N�X�C�b�`��L���ɂ��邩�ǂ�����ݒ肷��
extern	int			SetHookWinProc( WNDPROC WinProc ) ;										// ���b�Z�[�W���t�b�N����E�C���h�E�v���[�W����o�^����
extern	int			SetDoubleStartValidFlag( int Flag ) ;									// �Q�d�N�����������ǂ����̃t���O���Z�b�g����
extern	int			AddMessageTakeOverWindow( HWND Window ) ;								// ���b�Z�[�W�������c�w���C�u�����Ɍ����肵�Ă��炤�E�C���h�E��ǉ�����
extern	int			SubMessageTakeOverWindow( HWND Window ) ;								// ���b�Z�[�W�������c�w���C�u�����Ɍ����肵�Ă��炤�E�C���h�E�����炷

extern	int			SetWindowInitPosition( int x , int y ) ;									// �E�C���h�E�̏����ʒu��ݒ肷��
extern	int			SetNotWinFlag( int Flag ) ;												// �c�w���C�u�����̃E�C���h�E�֘A�̋@�\���g�p���Ȃ��t���O
extern	int			SetNotDrawFlag( int Flag ) ;											// �`��@�\���g�����ǂ����̃t���O���Z�b�g����
extern	int			SetNotSoundFlag( int Flag ) ;											// �T�E���h�@�\���g�����ǂ����̃t���O���Z�b�g����
extern	int			SetNotInputFlag( int Flag ) ;											// ���͏�Ԃ̎擾�@�\���g�����ǂ����̃t���O���Z�b�g����
extern	int			SetDialogBoxHandle( HWND WindowHandle ) ;								// �c�w���C�u�����Ń��b�Z�[�W�������s���_�C�A���O�{�b�N�X��o�^����
extern	int			ChangeStreamFunction( STREAMDATASHREDTYPE2 *StreamThread ) ;			// �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐���ύX����
extern	int			GetStreamFunctionDefault( void ) ;										// �c�w���C�u�����ŃX�g���[���f�[�^�A�N�Z�X�Ɏg�p����֐����f�t�H���g�̂��̂����ׂ�( TRUE:�f�t�H���g  FALSE:�f�t�H���g�ł͂Ȃ� )
extern	int			SetWindowVisibleFlag( int Flag ) ;										// ���C���E�C���h�E��\�����邩�ǂ����̃t���O���Z�b�g����
extern	int			SetWindowUserCloseEnableFlag( int Flag ) ;								// ���C���E�C���h�E�́~�{�^�������������Ƀ��C�u�����������I�ɃE�C���h�E����邩�ǂ����̃t���O���Z�b�g����
extern	int			SetDxLibEndPostQuitMessageFlag( int Flag ) ;							// �c�w���C�u�����I������ PostQuitMessage ���ĂԂ��ǂ����̃t���O���Z�b�g����
extern	int			SetUserWindow( HWND WindowHandle ) ;									// �c�w���C�u�����ŗ��p����E�C���h�E�̃n���h�����Z�b�g����(DxLib_Init �����s����ȑO�ł̂ݗL��)
extern	int			SetUserWindowMessageProcessDXLibFlag( int Flag ) ;						// SetUseWindow �Őݒ肵���E�C���h�E�̃��b�Z�[�W���[�v�������c�w���C�u�����ōs�����ǂ����A�t���O���Z�b�g����
extern	int			SetUseDXArchiveFlag( int Flag ) ;										// �c�w�A�[�J�C�u�t�@�C���̓ǂݍ��݋@�\���g�����ǂ�����ݒ肷��( FALSE:�g�p���Ȃ�  TRUE:�g�p���� )
extern	int			SetDXArchivePriority( int Priority = 0 ) ;								// �c�w�A�[�J�C�u�t�@�C���ƒʏ�̃t�H���_�̂ǂ�������݂����ꍇ�A�ǂ����D�悳���邩��ݒ肷��( 1:�t�H���_��D�� 0:�c�w�A�[�J�C�u�t�@�C����D��(�f�t�H���g) )
extern	int			SetDXArchiveExtension( const TCHAR *Extension = NULL ) ;				// ��������c�w�A�[�J�C�u�t�@�C���̊g���q��ύX����
extern	int			SetDXArchiveKeyString( const TCHAR *KeyString = NULL ) ;				// �c�w�A�[�J�C�u�t�@�C���̌��������ݒ肷��
extern	int			SetUseDateNameLogFile( int Flag ) ;										// ���O�t�@�C�����ɓ��t�����邩�ǂ������Z�b�g����
extern	int			SetBackgroundColor( int Red, int Green, int Blue ) ;					// ���C���E�C���h�E�̃o�b�N�O���E���h�J���[��ݒ肷��
extern	int			SetLogFontSize( int Size ) ;											// printfDx �ŉ�ʂɏo�͂��郍�O�t�H���g�̃T�C�Y��ύX����
extern	int			SetUseFPUPreserveFlag( int Flag ) ;										// FPU�̐��x�𗎂Ƃ��Ȃ��ݒ���g�p���邩�ǂ�����ݒ肷��ADxLib_Init ���Ăяo���O�̂ݗL��( TRUE:�g�p����(���x�������Ȃ�)  FALSE:�g�p���Ȃ�(���x�𗎂Ƃ�(�f�t�H���g) )
extern	int			SetValidMousePointerWindowOutClientAreaMoveFlag( int Flag ) ;			// �}�E�X�|�C���^���E�C���h�E�̃N���C�A���g�G���A�̊O�ɂ����邩�ǂ�����ݒ肷��( TRUE:������( �f�t�H���g�ݒ� )  FALSE:�����Ȃ� )
extern	int			SetUseBackBufferTransColorFlag( int Flag ) ;							// �o�b�N�o�b�t�@�̓��ߐF�̕����𓧉߂����邩�ǂ�����ݒ肷��( TRUE:���߂�����  FALSE:���߂����Ȃ� )
extern	int			SetResourceModule( HMODULE ResourceModule ) ;							// ���\�[�X��ǂݍ��ލۂɎg�p���郂�W���[����ݒ肷��( NULL ���w�肷��Ə�����Ԃɖ߂�܂��A�f�t�H���g�ł� NULL )

// �N���b�v�{�[�h�֌W
extern	int			GetClipboardText( TCHAR *DestBuffer ) ;									// �N���b�v�{�[�h�Ɋi�[����Ă���e�L�X�g�f�[�^��ǂݏo���A-1 �̏ꍇ�̓N���b�v�{�[�h�Ƀe�L�X�g�f�[�^�͖����Ƃ�������( DestBuffer �� NULL ��n���Ɗi�[�ɕK�v�ȃf�[�^�T�C�Y���Ԃ��Ă��� )
extern	int			SetClipboardText( const TCHAR *Text ) ;									// �N���b�v�{�[�h�Ƀe�L�X�g�f�[�^���i�[����

// �h���b�O���h���b�v���ꂽ�t�@�C���֌W
extern	int			SetDragFileValidFlag( int Flag ) ;										// �t�@�C���̃h���b�O���h���b�v�@�\��L���ɂ��邩�ǂ����̃t���O���Z�b�g����
extern	int			DragFileInfoClear( void ) ;												// �h���b�O���h���b�v���ꂽ�t�@�C���̏�������������
extern	int			GetDragFilePath( TCHAR *FilePathBuffer ) ;								// �h���b�O���h���b�v���ꂽ�t�@�C�������擾����( -1:�擾�ł��Ȃ�����  0:�擾�ł��� )
extern	int			GetDragFileNum( void ) ;												// �h���b�O���h���b�v���ꂽ�t�@�C���̐����擾����

// �E�C���h�E�`��̈�ݒ�n�֐�
extern	HRGN		CreateRgnFromGraph( int Width , int Height , void *MaskData , int Pitch , int Byte ) ; // �C�ӂ̃O���t�B�b�N����RGN�n���h�����쐬����
extern	HRGN		CreateRgnFromBaseImage( BASEIMAGE *BaseImage, int TransColorR, int TransColorG, int TransColorB ) ;		// �C�ӂ̊�{�C���[�W�f�[�^�Ɠ��ߐF����RGN�n���h�����쐬����
extern	int			SetWindowRgnGraph( const TCHAR *FileName ) ;							// �C�ӂ̃O���t�B�b�N����q�f�m���Z�b�g����
extern	int			UpdateTransColorWindowRgn( void ) ;										// �`���̉�ʂ̓��ߐF�̕����𓧉߂�����q�f�m���Z�b�g����

// �c�[���o�[�֌W
extern	int			SetupToolBar( const TCHAR *BitmapName , int DivNum , int ResourceID = -1 ) ;				// �c�[���o�[�̏���( NULL ���w�肷��ƃc�[���o�[�������AResourceID �� BitmapName �� NULL �̍ۂɎg�p����� )
extern	int			AddToolBarButton( int Type /* TOOLBUTTON_TYPE_NORMAL �� */ , int State /* TOOLBUTTON_STATE_ENABLE �� */ , int ImageIndex, int ID ) ;		// �c�[���o�[�Ƀ{�^����ǉ�
extern	int			AddToolBarSep( void ) ;												// �c�[���o�[�Ɍ��Ԃ�ǉ�
extern	int			GetToolBarButtonState( int ID ) ;									// �c�[���o�[�̃{�^���̏�Ԃ��擾( TRUE:������Ă��� or �����ꂽ  FALSE:������Ă��Ȃ� )
extern	int			SetToolBarButtonState( int ID , int State ) ;						// �c�[���o�[�̃{�^���̏�Ԃ�ݒ�
extern	int			DeleteAllToolBarButton( void ) ;									// �c�[���o�[�̃{�^����S�č폜

// ���j���[�֌W
extern	int			SetUseMenuFlag( int Flag ) ;												// ���j���[��L���ɂ��邩�ǂ�����ݒ肷��
extern	int			SetUseKeyAccelFlag( int Flag ) ;											// �L�[�{�[�h�A�N�Z�����[�^�[���g�p���邩�ǂ�����ݒ肷��

extern	int			AddKeyAccel( const TCHAR *ItemName , int ItemID , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// �V���[�g�J�b�g�L�[��ǉ�����
extern	int			AddKeyAccel_Name( const TCHAR *ItemName , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// �V���[�g�J�b�g�L�[��ǉ�����
extern	int			AddKeyAccel_ID( int ItemID, int KeyCode, int CtrlFlag, int AltFlag, int ShiftFlag ) ;	// �V���[�g�J�b�g�L�[��ǉ�����
extern	int			ClearKeyAccel( void ) ;														// �V���[�g�J�b�g�L�[�̏�������������

extern	int			AddMenuItem( int AddType /* MENUITEM_ADD_CHILD�� */ , const TCHAR *ItemName, int ItemID,
									int SeparatorFlag, const TCHAR *NewItemName = NULL , int NewItemID = -1 ) ;	// ���j���[�ɍ��ڂ�ǉ�����
extern	int			DeleteMenuItem( const TCHAR *ItemName, int ItemID ) ;						// ���j���[����I�����ڂ��폜����
extern	int			CheckMenuItemSelect( const TCHAR *ItemName, int ItemID ) ;					// ���j���[���I�����ꂽ���ǂ������擾����( 0:�I������Ă��Ȃ�  1:�I�����ꂽ )
extern	int			SetMenuItemEnable( const TCHAR *ItemName, int ItemID, int EnableFlag ) ;		// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��
extern	int			SetMenuItemMark( const TCHAR *ItemName, int ItemID, int Mark ) ;				// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( MENUITEM_MARK_NONE �� )
extern	int			CheckMenuItemSelectAll( void ) ;											// ���j���[�̍��ڂ��ǂꂩ�I�����ꂽ���ǂ������擾����( �߂�l  TRUE:�ǂꂩ�I�����ꂽ  FALSE:�I������Ă��Ȃ� )

extern	int			AddMenuItem_Name( const TCHAR *ParentItemName, const TCHAR *NewItemName ) ;	// ���j���[�ɑI�����ڂ�ǉ�����
extern	int			AddMenuLine_Name( const TCHAR *ParentItemName ) ;							// ���j���[�̃��X�g�ɋ�؂����ǉ�����
extern	int			InsertMenuItem_Name( const TCHAR *ItemName, const TCHAR *NewItemName ) ;		// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊ԂɐV�������ڂ�ǉ�����
extern	int			InsertMenuLine_Name( const TCHAR *ItemName ) ;								// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊Ԃɋ�؂����ǉ�����
extern	int			DeleteMenuItem_Name( const TCHAR *ItemName ) ;								// ���j���[����I�����ڂ��폜����
extern	int			CheckMenuItemSelect_Name( const TCHAR *ItemName ) ;							// ���j���[���I�����ꂽ���ǂ������擾����( 0:�I������Ă��Ȃ�  1:�I�����ꂽ )
extern	int			SetMenuItemEnable_Name( const TCHAR *ItemName, int EnableFlag ) ;			// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��( 1:�I���ł���  0:�I���ł��Ȃ� )
extern	int			SetMenuItemMark_Name( const TCHAR *ItemName, int Mark ) ;					// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( MENUITEM_MARK_NONE �� )

extern	int			AddMenuItem_ID( int ParentItemID, const TCHAR *NewItemName, int NewItemID = -1 ) ;	// ���j���[�ɑI�����ڂ�ǉ�����
extern	int			AddMenuLine_ID( int ParentItemID ) ;										// ���j���[�̃��X�g�ɋ�؂����ǉ�����
extern	int			InsertMenuItem_ID( int ItemID, int NewItemID ) ;							// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊ԂɐV�������ڂ�ǉ�����
extern	int			InsertMenuLine_ID( int ItemID, int NewItemID ) ;							// �w��̍��ڂƁA�w��̍��ڂ̈��̍��ڂƂ̊Ԃɋ�؂����ǉ�����
extern	int			DeleteMenuItem_ID( int ItemID ) ;											// ���j���[����I�����ڂ��폜����
extern	int			CheckMenuItemSelect_ID( int ItemID ) ;										// ���j���[���I�����ꂽ���ǂ������擾����( 0:�I������Ă��Ȃ�  1:�I�����ꂽ )
extern	int			SetMenuItemEnable_ID( int ItemID, int EnableFlag ) ;						// ���j���[�̍��ڂ�I���o���邩�ǂ�����ݒ肷��
extern	int			SetMenuItemMark_ID( int ItemID, int Mark ) ;								// ���j���[�̍��ڂɃ`�F�b�N�}�[�N�⃉�W�I�{�^����\�����邩�ǂ�����ݒ肷��( MENUITEM_MARK_NONE �� )

extern	int			DeleteMenuItemAll( void ) ;													// ���j���[�̑S�Ă̑I�����ڂ��폜����
extern	int			ClearMenuItemSelect( void ) ;												// ���j���[���I�����ꂽ���ǂ����̏���������
extern	int			GetMenuItemID( const TCHAR *ItemName ) ;										// ���j���[�̍��ږ�����h�c���擾����
extern	int			GetMenuItemName( int ItemID, TCHAR *NameBuffer ) ;							// ���j���[�̍��ږ�����h�c���擾����
extern	int 		LoadMenuResource( int MenuResourceID ) ;									// ���j���[�����\�[�X����ǂݍ���
extern	int			SetMenuItemSelectCallBackFunction( void (* CallBackFunction )( const TCHAR *ItemName, int ItemID ) ) ; // ���j���[�̑I�����ڂ��I�����ꂽ�Ƃ��ɌĂ΂��R�[���o�b�N�֐���ݒ肷��

extern	int			SetWindowMenu( int MenuID, int (* MenuProc )( WORD ID ) ) ;				// (�Â��֐�)�E�C���h�E�Ƀ��j���[��ݒ肷��
extern	int			SetDisplayMenuFlag( int Flag ) ;										// ���j���[��\�����邩�ǂ������Z�b�g����
extern	int			GetDisplayMenuFlag( void ) ;											// ���j���[��\�����Ă��邩�ǂ������擾����
extern	int			GetUseMenuFlag( void ) ;												// ���j���[���g�p���Ă��邩�ǂ����𓾂�
extern	int			SetAutoMenuDisplayFlag( int Flag ) ;									// �t���X�N���[�����Ƀ��j���[�������ŕ\���������\���ɂ����肷�邩�ǂ����̃t���O���Z�b�g����

// �}�E�X�֌W�֐�
extern	int			SetMouseDispFlag( int DispFlag ) ;										// �}�E�X�̕\���t���O�̃Z�b�g
extern	int			GetMousePoint( int *XBuf, int *YBuf ) ;									// �}�E�X�̈ʒu���擾����
extern	int			SetMousePoint( int PointX, int PointY ) ;								// �}�E�X�̈ʒu���Z�b�g����
extern	int			GetMouseInput( void ) ;													// �}�E�X�̃{�^���̏�Ԃ𓾂� 
extern	int			GetMouseWheelRotVol( int CounterReset = TRUE ) ;						// �}�E�X�z�C�[���̉�]�ʂ𓾂�
extern	int			GetMouseInputLog( int *Button, int *ClickX, int *ClickY, int LogDelete = TRUE ) ;	// �}�E�X�̃N���b�N�����擾����( �߂�l  -1:���O���������� )

// �E�G�C�g�n�֐�
extern	int			WaitTimer( int WaitTime ) ;												// �w��̎��Ԃ����������Ƃ߂�
extern	int			WaitKey( void ) ;														// �L�[�̓��͑҂�

// �J�E���^�y�ю����擾�n�֐�
extern	int			GetNowCount( int UseRDTSCFlag = FALSE ) ;								// �~���b�P�ʂ̐��x�����J�E���^�̌��ݒl�𓾂�
extern	LONGLONG	GetNowHiPerformanceCount( int UseRDTSCFlag = FALSE ) ;					// GetNowCount�̍����x�o�[�W����
extern	int			GetDateTime( DATEDATA *DateBuf ) ;										// ���ݎ������擾���� 

// �����擾
extern	int			GetRand( int RandMax ) ;												// �������擾����( RandMax : �Ԃ��ė���l�̍ő�l )
extern	int			SRand( int Seed ) ;														// �����̏����l��ݒ肷��

#ifndef DX_NON_NETWORK

// �ʐM�֌W
extern	int			ProcessNetMessage( int RunReleaseProcess = FALSE ) ;					// �ʐM���b�Z�[�W�̏���������֐�

extern	int			GetHostIPbyName( const TCHAR *HostName, IPDATA *IPDataBuf ) ;			// �c�m�r�T�[�o�[���g���ăz�X�g������h�o�A�h���X���擾����
extern 	int			ConnectNetWork( IPDATA IPData, int Port = -1 ) ;						// ���}�V���ɐڑ�����
extern 	int			PreparationListenNetWork( int Port = -1 ) ;								// �ڑ����󂯂����Ԃɂ���
extern 	int			StopListenNetWork( void ) ;												// �ڑ����󂯂���Ԃ̉���
extern 	int			CloseNetWork( int NetHandle ) ;											// �ڑ����I������

extern 	int			GetNetWorkAcceptState( int NetHandle ) ;								// �ڑ���Ԃ��擾����
extern 	int			GetNetWorkDataLength( int NetHandle ) ;									// ��M�f�[�^�̗ʂ𓾂�
extern	int			GetNetWorkSendDataLength( int NetHandle ) ;								// �����M�̃f�[�^�̗ʂ𓾂� 
extern 	int			GetNewAcceptNetWork( void ) ;											// �V���ɐڑ������ʐM����𓾂�
extern 	int			GetLostNetWork( void ) ;												// �ڑ���ؒf���ꂽ�ʐM����𓾂�
extern 	int			GetNetWorkIP( int NetHandle, IPDATA *IpBuf ) ;							// �ڑ���̂h�o�𓾂�
extern	int			GetMyIPAddress( IPDATA *IpBuf ) ;										// �����̂h�o�𓾂�
extern	int			SetConnectTimeOutWait( int Time ) ;										// �ڑ��̃^�C���A�E�g�܂ł̎��Ԃ�ݒ肷��
extern	int			SetUseDXNetWorkProtocol( int Flag ) ;									// �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������Z�b�g����
extern	int			GetUseDXNetWorkProtocol( void ) ; 										// �c�w���C�u�����̒ʐM�`�Ԃ��g�����ǂ������擾����
extern	int			SetUseDXProtocol( int Flag ) ;											// SetUseDXNetWorkProtocol �̕ʖ�
extern	int			GetUseDXProtocol( void ) ; 												// GetUseDXNetWorkProtocol �̕ʖ�
extern	int			SetNetWorkCloseAfterLostFlag( int Flag ) ;								// �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���Z�b�g����
extern	int			GetNetWorkCloseAfterLostFlag( void ) ;									// �ڑ����ؒf���ꂽ����ɐڑ��n���h����������邩�ǂ����̃t���O���擾����
//extern	int			SetProxySetting( int UseFlag, const char *Address, int Port ) ;						// �g�s�s�o�ʐM�Ŏg�p����v���L�V�ݒ���s��
//extern	int			GetProxySetting( int *UseFlagBuffer, char *AddressBuffer, int *PortBuffer ) ;	// �g�s�s�o�ʐM�Ŏg�p����v���L�V�ݒ���擾����
//extern	int			SetIEProxySetting( void ) ;												// �h�d�̃v���L�V�ݒ��K������

extern 	int			NetWorkRecv( int NetHandle, void *Buffer, int Length ) ;				// ��M�����f�[�^��ǂݍ���
extern	int			NetWorkRecvToPeek( int NetHandle, void *Buffer, int Length ) ;			// ��M�����f�[�^��ǂݍ��ށA�ǂݍ��񂾃f�[�^�̓o�b�t�@����폜����Ȃ�
extern	int			NetWorkRecvBufferClear( int NetHandle ) ;								// ��M�����f�[�^���N���A����
extern 	int			NetWorkSend( int NetHandle, void *Buffer, int Length ) ;				// �f�[�^�𑗐M����

extern	int			MakeUDPSocket( int RecvPort = -1 ) ;																	// UDP���g�p�����ʐM���s���\�P�b�g�n���h�����쐬����( RecvPort �� -1 �ɂ���Ƒ��M��p�̃\�P�b�g�n���h���ɂȂ�܂� )
extern	int			DeleteUDPSocket( int NetUDPHandle ) ;																	// UDP���g�p�����ʐM���s���\�P�b�g�n���h�����폜����
extern	int			NetWorkSendUDP( int NetUDPHandle, IPDATA SendIP, int SendPort, void *Buffer, int Length ) ;				// UDP���g�p�����ʐM�Ŏw��̂h�o�Ƀf�[�^�𑗐M����ALength �͍ő�65507�ASendPort �� -1 �ɂ���� MakeUDPSocket �� RecvPort �œn�����|�[�g���g�p����܂�( �߂�l  0�ȏ�;���M�ł����f�[�^�T�C�Y  -1:�G���[  -2:���M�f�[�^���傫������  -3:���M�������ł��Ă��Ȃ�  )
extern	int			NetWorkRecvUDP( int NetUDPHandle, IPDATA *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDP���g�p�����ʐM�Ńf�[�^����M����APeek �� TRUE ��n���Ǝ�M�ɐ������Ă��f�[�^����M�L���[����폜���܂���( �߂�l  0�ȏ�:��M�����f�[�^�̃T�C�Y  -1:�G���[  -2:�o�b�t�@�̃T�C�Y������Ȃ�  -3:��M�f�[�^���Ȃ� )
//extern int		CheckNetWorkSendUDP( int NetUDPHandle ) ;																// UDP���g�p�����ʐM�Ńf�[�^�����M�ł����Ԃ��ǂ����𒲂ׂ�( �߂�l  -1:�G���[  TRUE:���M�\  FALSE:���M�s�\ )
extern	int			CheckNetWorkRecvUDP( int NetUDPHandle ) ;																// UDP���g�p�����ʐM�ŐV���Ȏ�M�f�[�^�����݂��邩�ǂ����𒲂ׂ�( �߂�l  -1:�G���[  TRUE:��M�f�[�^����  FALSE:��M�f�[�^�Ȃ� )

/*	�g�p�s��
extern	int			HTTP_FileDownload( const char *FileURL, const char *SavePath = NULL ,
										 void **SaveBufferP = NULL , int *FileSize = NULL ,
										 char **ParamList = NULL ) ;						// HTTP ���g�p���ăl�b�g���[�N��̃t�@�C�����_�E�����[�h����
extern	int			HTTP_GetFileSize( const char *FileURL ) ;								// HTTP ���g�p���ăl�b�g���[�N��̃t�@�C���̃T�C�Y�𓾂�

extern	int			HTTP_StartFileDownload( const char *FileURL, const char *SavePath, void **SaveBufferP = NULL , char **ParamList = NULL ) ;	// HTTP ���g�p�����l�b�g���[�N��̃t�@�C�����_�E�����[�h���鏈�����J�n����
extern	int			HTTP_StartGetFileSize( const char *FileURL ) ;							// HTTP ���g�p�����l�b�g���[�N��̃t�@�C���̃T�C�Y�𓾂鏈�����J�n����
extern	int			HTTP_Close( int HttpHandle ) ;											// HTTP �̏������I�����A�n���h�����������
extern	int			HTTP_CloseAll( void ) ;													// �S�Ẵn���h���ɑ΂��� HTTP_Close ���s��
extern	int			HTTP_GetState( int HttpHandle ) ;										// HTTP �����̌��݂̏�Ԃ𓾂�( NET_RES_COMPLETE �� )
extern	int			HTTP_GetError( int HttpHandle ) ;										// HTTP �����ŃG���[�����������ꍇ�A�G���[�̓��e�𓾂�( HTTP_ERR_NONE �� )
extern	int			HTTP_GetDownloadFileSize( int HttpHandle ) ;							// HTTP �����őΏۂƂȂ��Ă���t�@�C���̃T�C�Y�𓾂�( �߂�l: -1 = �G���[�E�Ⴕ���͂܂��t�@�C���̃T�C�Y���擾���Ă��Ȃ�  0�ȏ� = �t�@�C���̃T�C�Y )
extern	int			HTTP_GetDownloadedFileSize( int HttpHandle ) ;							// HTTP �����Ŋ��Ƀ_�E�����[�h�����t�@�C���̃T�C�Y���擾����

extern	int			fgetsForNetHandle( int NetHandle, char *strbuffer ) ;					// fgets �̃l�b�g���[�N�n���h����( -1:�擾�ł��� 0:�擾�ł��� )
extern	int			URLAnalys( const char *URL, char *HostBuf = NULL , char *PathBuf = NULL ,
												 char *FileNameBuf = NULL , int *PortBuf = NULL ) ;	// �t�q�k����͂���
extern	int			URLConvert( char *URL, int ParamConvert = TRUE , int NonConvert = FALSE ) ;	// HTTP �ɓn���Ȃ��L�����g��ꂽ�������n����悤�ȕ�����ɕϊ�����( �߂�l: -1 = �G���[  0�ȏ� = �ϊ���̕�����̃T�C�Y )
extern	int			URLParamAnalysis( char **ParamList, char **ParamStringP ) ;				// HTTP �p�p�����[�^���X�g�����̃p�����[�^��������쐬����( �߂�l:  -1 = �G���[  0�ȏ� = �p�����[�^�̕�����̒��� )
*/

#endif


// �����R�[�h�o�b�t�@����֌W
extern	int			StockInputChar( TCHAR CharCode ) ;																												// �o�b�t�@�ɃR�[�h���X�g�b�N����
extern	int			ClearInputCharBuf( void ) ;																														// �����R�[�h�o�b�t�@���N���A����
extern	TCHAR		GetInputChar( int DeleteFlag ) ;																												// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^���當���R�[�h���擾����
extern	TCHAR		GetInputCharWait( int DeleteFlag ) ;																											// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�o�C�g���擾����A�o�b�t�@�ɂȂɂ������R�[�h���Ȃ��ꍇ�̓L�[���������܂ő҂�

extern	int			GetOneChar( TCHAR *CharBuffer, int DeleteFlag ) ;																								// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����
extern	int			GetOneCharWait( TCHAR *CharBuffer, int DeleteFlag ) ;																							// �����R�[�h�o�b�t�@�ɗ��܂����f�[�^����P�������擾����A�o�b�t�@�ɉ��������R�[�h���Ȃ��ꍇ�̓L�[���������܂ő҂�
extern	int			GetCtrlCodeCmp( TCHAR Char ) ;																													// �A�X�L�[�R���g���[���R�[�h�����ׂ�

#ifndef DX_NON_KEYEX

extern	int			DrawIMEInputString( int x, int y, int SelectStringNum ) ;																						// ��ʏ�ɓ��͒��̕������`�悷��
extern	int			SetUseIMEFlag( int UseFlag ) ;																													// �h�l�d���g�p���邩�ǂ������Z�b�g����
extern	int			SetInputStringMaxLengthIMESync( int Flag ) ;																									// �h�l�d�œ��͂ł���ő啶������ MakeKeyInput �̐ݒ�ɍ��킹�邩�ǂ������Z�b�g����( TRUE:���킹��  FALSE:���킹�Ȃ�(�f�t�H���g) )
extern	int			SetIMEInputStringMaxLength( int Length ) ;																										// �h�l�d�ň�x�ɓ��͂ł���ő啶������ݒ肷��( 0:�����Ȃ�  1�ȏ�:�w��̕������Ő��� )

#endif

extern	int			GetStringPoint( const TCHAR *String, int Point ) ;																								// �S�p�����A���p�������藐��钆����w��̕������ł̔��p�������𓾂�
extern	int			GetStringPoint2( const TCHAR *String, int Point ) ;																								// �S�p�����A���p�������藐��钆����w��̕������ł̑S�p�������𓾂�

extern	int			DrawObtainsString( int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;					// �K��̈�Ɏ��߂��������ŕ������`��
extern	int			DrawObtainsBox( int x1, int y1, int x2, int y2, int AddY, int Color, int FillFlag ) ;															// �K��̈�Ɏ��߂��������ŋ�`��`�� 

#ifndef DX_NON_KEYEX

extern	int			InputStringToCustom( int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag ) ;			// ������̓��͎擾

extern	int			KeyInputString( int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// ������̓��͎擾
extern	int			KeyInputSingleCharString( int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;												// ���p������݂̂̓��͎擾
extern	int			KeyInputNumber( int x, int y, int MaxNum, int MinNum, int CancelValidFlag ) ;																	// ���l�̓���

extern	int			GetIMEInputModeStr( TCHAR *GetBuffer ) ;																											// IME�̓��̓��[�h������̎擾
extern	IMEINPUTDATA* GetIMEInputData( void ) ;																														// IME�œ��͒��̕�����̏����擾����
extern	int			SetKeyInputStringColor( ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff ) ;	// InputString�֐��g�p���̕����̊e�F��ύX����
extern	int			SetKeyInputStringFont( int FontHandle ) ;																										// �L�[���͕�����`��֘A�Ŏg�p����t�H���g�̃n���h����ύX����(-1�Ńf�t�H���g�̃t�H���g�n���h��)
extern	int			DrawKeyInputModeString( int x, int y ) ;																										// ���̓��[�h�������`�悷��

extern	int			InitKeyInput( void ) ;																															// �L�[���̓f�[�^������
extern	int			MakeKeyInput( int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag ) ;											// �V�����L�[���̓f�[�^�̍쐬
extern	int			DeleteKeyInput( int InputHandle ) ;																												// �L�[���̓f�[�^�̍폜
extern	int			SetActiveKeyInput( int InputHandle ) ;																											// �w��̃L�[���͂��A�N�e�B�u�ɂ���( -1 ���w�肷��ƃA�N�e�B�u�ȃL�[���̓n���h����������ԂɂȂ�܂� )
extern	int			GetActiveKeyInput( void ) ;																														// ���݃A�N�e�B�u�ɂȂ��Ă���L�[���̓n���h�����擾����
extern	int			CheckKeyInput( int InputHandle ) ;																												// ���͂��I�����Ă��邩�擾����
extern	int			ReStartKeyInput( int InputHandle ) ;																											// ���͂����������L�[���͂��ēx�ҏW��Ԃɖ߂�
extern	int			ProcessActKeyInput( void ) ;																													// �L�[���͏����֐�
extern	int			DrawKeyInputString( int x, int y, int InputHandle ) ;																							// �L�[���͒��f�[�^�̕`��

extern	int			SetKeyInputSelectArea( int SelectStart, int SelectEnd, int InputHandle ) ;																		// �L�[���̓f�[�^�̎w��̗̈��I����Ԃɂ���( SelectStart �� SelectEnd �� -1 ���w�肷��ƑI����Ԃ���������܂� )
extern	int			GetKeyInputSelectArea( int *SelectStart, int *SelectEnd, int InputHandle ) ;																	// �L�[���̓f�[�^�̑I��̈���擾����
extern	int			SetKeyInputDrawStartPos( int DrawStartPos, int InputHandle ) ;																					// �L�[���͂̕`��J�n�����ʒu��ݒ肷��
extern	int			GetKeyInputDrawStartPos( int InputHandle ) ;																									// �L�[���͂̕`��J�n�����ʒu���擾����
extern	int			SetKeyInputCursorBrinkTime( int Time ) ;																										// �L�[���͎��̃J�[�\���̓_�ł��鑁�����Z�b�g����
extern	int			SetKeyInputCursorBrinkFlag( int Flag ) ;																										// �L�[���͎��̃J�[�\����_�ł����邩�ǂ������Z�b�g����
extern	int			SetKeyInputString( const TCHAR *String, int InputHandle ) ;																						// �L�[���̓f�[�^�Ɏw��̕�������Z�b�g����
extern	int			SetKeyInputNumber( int Number, int InputHandle ) ;																								// �L�[���̓f�[�^�Ɏw��̐��l�𕶎��ɒu�������ăZ�b�g����
extern	int			SetKeyInputNumberToFloat( float Number, int InputHandle ) ;																						// �L�[���̓f�[�^�Ɏw��̕��������_�l�𕶎��ɒu�������ăZ�b�g����
extern	int			GetKeyInputString( TCHAR *StrBuffer, int InputHandle ) ;																							// ���̓f�[�^�̕�������擾����
extern	int			GetKeyInputNumber( int InputHandle ) ;																											// ���̓f�[�^�̕�����𐮐��l�Ƃ��Ď擾����
extern	float		GetKeyInputNumberToFloat( int InputHandle ) ;																									// ���̓f�[�^�̕�����𕂓������_�l�Ƃ��Ď擾����
extern	int			SetKeyInputCursorPosition( int Position, int InputHandle ) ;																									// �L�[���͂̌��݂̃J�[�\���ʒu��ݒ肷��
extern	int			GetKeyInputCursorPosition( int InputHandle ) ;																									// �L�[���͂̌��݂̃J�[�\���ʒu���擾����

#endif


// �������ɒu���ꂽ�f�[�^���t�@�C���̃f�[�^�ɗႦ�Ă������߂̊֐�
extern	void*		MemStreamOpen( void *DataBuffer, unsigned int DataSize ) ;
extern	int			MemStreamClose( void *StreamDataPoint ) ;












// DxInput.cpp�֐��v���g�^�C�v�錾

// ���͏�Ԏ擾�֐�
extern	int			CheckHitKey( int KeyCode ) ;											// �L�[�{�[�h�̓��͏�Ԏ擾
extern	int			CheckHitKeyAll( int CheckType = DX_CHECKINPUT_ALL ) ;					// �S�L�[�̉�����Ԃ��擾
extern	int			GetHitKeyStateAll( DX_CHAR *KeyStateBuf ) ;								// ���ׂẴL�[�̉�����Ԃ��擾����
extern	int			SetKeyExclusiveCooperativeLevelFlag( int Flag ) ;						// �L�[�{�[�h�̋������x����r�����x���ɂ��邩�ǂ����̃t���O���Z�b�g����
extern	int			GetJoypadNum( void ) ;													// �W���C�p�b�h���ڑ�����Ă��鐔���擾����
extern	int			GetJoypadInputState( int InputType ) ;									// �W���C�o�b�h�̓��͏�Ԏ擾
extern	int			GetJoypadAnalogInput( int *XBuf, int *YBuf, int InputType ) ;			// �W���C�p�b�h�̃A�i���O�I�ȃX�e�B�b�N���͏��𓾂�
extern	int			GetJoypadAnalogInputRight( int *XBuf, int *YBuf, int InputType ) ;		// �W���C�p�b�h�̃A�i���O�I�ȃX�e�B�b�N���͏��𓾂�(�E�X�e�B�b�N�p)
extern	int			KeyboradBufferProcess( void ) ;											// �L�[�{�[�h�̃o�b�t�@����f�[�^���擾���鏈��
extern	int			GetJoypadGUID( int PadIndex, GUID *GuidBuffer ) ;						// �W���C�p�b�h�̂f�tI�c�𓾂�
extern	int			ConvertKeyCodeToVirtualKey( int KeyCode ) ;								// �c�w���C�u�����̃L�[�R�[�h���� Windows �̉��z�L�[�R�[�h���擾����
extern	int			SetJoypadInputToKeyInput( int InputType, int PadInput, int KeyInput1, int KeyInput2 = -1 , int KeyInput3 = -1 , int KeyInput4 = -1  ) ; // �W���C�p�b�h�̓��͂ɑΉ������L�[�{�[�h�̓��͂�ݒ肷��
extern	int			SetJoypadDeadZone( int InputType, double Zone ) ;						// �W���C�p�b�h�̖����]�[���̐ݒ���s��
extern	int			StartJoypadVibration( int InputType, int Power, int Time ) ;			// �W���C�p�b�h�̐U�����J�n����
extern	int			StopJoypadVibration( int InputType ) ;									// �W���C�p�b�h�̐U�����~����
extern	int			GetJoypadPOVState( int InputType, int POVNumber ) ;						// �W���C�p�b�h�̂o�n�u���͂̏�Ԃ𓾂�( �P�ʂ͊p�x�̂P�O�O�{  ���S�ʒu�ɂ���ꍇ�� -1 ���Ԃ� )
extern	int			GetJoypadName( int InputType, TCHAR *InstanceNameBuffer, TCHAR *ProductNameBuffer ) ;	// �W���C�p�b�h�̃f�o�C�X�o�^���Ɛ��i�o�^�����擾����
extern	int			ReSetupJoypad( void ) ;													// �W���C�p�b�h�̍ăZ�b�g�A�b�v���s��( �V���ɐڑ����ꂽ�W���C�p�b�h������ꍇ�Ɍ��o����� )

extern	int			SetKeyboardNotDirectInputFlag( int Flag ) ;								// �L�[�{�[�h�̓��͏����� DirectInput ���g��Ȃ����A�t���O���Z�b�g����
extern	int			SetUseDirectInputFlag( int Flag ) ;										// ���͏����� DirectInput ���g�p���邩�ǂ����̃t���O���Z�b�g����
extern	int			SetUseJoypadVibrationFlag( int Flag ) ;									// �W���C�p�b�h�̐U���@�\���g�p���邩�ǂ����̃t���O���Z�b�g����








#ifndef DX_NOTUSE_DRAWFUNCTION

// DxDraw.cpp�֐��v���g�^�C�v�錾

// �ݒ�֌W�֐�
extern	int			Set2D3DKyouzonFlag( int Flag ) ;							// �R�c�ƂQ�c�̋��������グ��t���O�̃Z�b�g
extern	int			SetNotUse3DFlag( int Flag ) ;								// �R�c�@�\���g��Ȃ��t���O�̃Z�b�g
extern	int			SetBasicBlendFlag( int Flag ) ;								// �ȗ����u�����h�������s�����ۂ��̃t���O���Z�b�g����
extern	int			SetScreenMemToVramFlag( int Flag ) ;						// ��ʃf�[�^���u�q�`�l�ɒu�����A�t���O
extern	int			SetUseSoftwareRenderModeFlag( int Flag ) ;					// �\�t�g�E�G�A�����_�����O���[�h���g�p���邩�ǂ������Z�b�g����
extern	int			SetUseDirectDrawFlag( int Flag ) ;							// �c�����������c���������g�p���邩�ǂ������Z�b�g����
extern	int			SetUseGDIFlag( int Flag ) ;									// �f�c�h�`���K�v�Ƃ��邩�A��ύX����
extern	int			SetDDrawUseGuid( GUID *Guid ) ;								// �c�����������c���������g�p����f�t�c�h��ݒ肷��
extern	int			SetDisplayRefreshRate( int RefreshRate ) ;					// �t���X�N���[�����̉�ʂ̃��t���b�V�����[�g��ύX����(Windows2000�ȍ~�̂ݗL��)
extern	int			SetMultiThreadFlag( int Flag ) ;							// DirectDraw �� Direct3D �̋������x�����}���`�X���b�h�Ή��ɂ��邩�ǂ������Z�b�g����
extern	int			SetUseDirectDrawDeviceIndex( int Index ) ;					// �g�p���� DirectDraw �f�o�C�X�̃C���f�b�N�X��ݒ肷��
extern	int			SetUseTempFrontScreen( int Flag ) ;							// �ꎞ�ޔ�p�\��ʂ��g�p���邩�ǂ�����ݒ肷��( TRUE:�g�p����  FALSE:�g�p���Ȃ� )

// �c�����������c�������֌W���񋟊֐�
extern	int						GetDrawScreenSize( int *XBuf, int *YBuf ) ;							// �`��T�C�Y���擾����
extern	int						GetScreenBitDepth( void ) ;											// �g�p�F�r�b�g����Ԃ�
extern	int						GetBmpSurf3DRenderingValidState( int BmpIndex ) ;					// �w��̃C���f�b�N�X�̃r�b�g�}�b�v�f�[�^���R�c�f�o�C�X�ɂ��`�悪�\���ǂ������擾����( TRUE:�o����  FALSE:�o���Ȃ� )
extern	void*					GetDrawTargetSurface( void ) ;	/* �߂�l�� IDirectDrawSurface7 * �ɃL���X�g���ĉ����� */		// �`��ΏۂƂȂ��Ă���T�[�t�F�X���擾
extern	void*					GetPrimarySurface( void ) ;		/* �߂�l�� IDirectDrawSurface7 * �ɃL���X�g���ĉ����� */		// �v���C�}���T�[�t�F�X���擾
extern	void*					GetBackSurface( void ) ;		/* �߂�l�� IDirectDrawSurface7 * �ɃL���X�g���ĉ����� */		// �o�b�N�T�[�t�F�X���擾
extern	void*					GetWorkSurface( void ) ;		/* �߂�l�� IDirectDrawSurface7 * �ɃL���X�g���ĉ����� */		// ��Ɨp�T�[�t�F�X���擾
extern	int						GetDesktopDrawCmp( void ) ;											// �f�X�N�g�b�v��ʂւ̕`�悩�̔�����
extern	void*					GetUseDDrawObj( void ) ;		/* �߂�l�� IDirectDraw7 * �ɃL���X�g���ĉ����� */			// ���ݎg�p���Ă���c�����������c�������I�u�W�F�N�g�̃A�h���X���擾����
extern  int						GetUseDirectDrawFlag( void ) ;										// �c�����������c���������g�p���邩�ǂ������擾����
extern	int						GetColorBitDepth( void ) ;											// ��ʂ̐F�r�b�g�[�x�𓾂�
extern	int						GetChangeDisplayFlag( void ) ;										// ��ʃ��[�h���ύX����Ă��邩�ǂ����̃t���O���擾����
extern	COLORDATA*				GetDispColorData( void ) ;											// �f�B�X�v���[�̃J���[�f�[�^�|�C���^�𓾂�
extern	const D_DDPIXELFORMAT*	GetPixelFormat( void ) ;											// �s�N�Z���t�H�[�}�b�g�̎擾
extern	int						GetScreenMemToSystemMemFlag( void ) ;								// ��ʃO���t�B�b�N�f�[�^���V�X�e���������ɑ��݂��邩�t���O�̎擾
extern	const D_DDPIXELFORMAT*	GetOverlayPixelFormat( void ) ;										// �g�p�ł���I�[�o�[���C�̃s�N�Z���t�H�[�}�b�g�𓾂�
extern	D_DDCAPS				GetDirectDrawCaps( void ) ;											// DirectDraw �̏��𓾂�
extern	int						GetVideoMemorySize( int *AllSize, int *FreeSize ) ;					// �r�f�I�������̗e�ʂ𓾂�
extern	int						GetUseGDIFlag( void ) ;												// �f�c�h�`���K�v�Ƃ��邩�ǂ������擾����
extern	int						GetNotDraw3DFlag( void ) ;											// NotDraw3DFlag ���擾����
extern	HDC						GetDrawScreenDC( void ) ;											// �`���ɂȂ��Ă����ʂ̂c�b���擾����
extern	int						ReleaseDrawScreenDC( HDC Dc ) ;										// GetScreenDC �Ŏ擾�����c�b���������
extern	GUID*					GetDirectDrawDeviceGUID( int Number ) ;								// �L���� DirectDraw �f�o�C�X�� GUID ���擾����
extern	int						GetDirectDrawDeviceDescription( int Number, char *StringBuffer ) ;	// �L���� DirectDraw �f�o�C�X�̖��O�𓾂�
extern	int						GetDirectDrawDeviceNum( void ) ;									// �L���� DirectDraw �f�o�C�X�̐����擾����
extern	int						GetUseMEMIMGFlag( void ) ;											// MEMIMG �\���̂��g�p���邩�ǂ������擾����
extern	int						GetVSyncTime( void ) ;												// ���������M�����ɕt�������鎞�Ԃ��~���b�P�ʂŎ擾����
extern	int						GetRefreshRate( void ) ;											// ���݂̉�ʂ̃��t���b�V�����[�g���擾����
extern	int						GetDisplayModeNum( void ) ;											// �ύX�\�ȃf�B�X�v���C���[�h�̐����擾����
extern	DISPLAYMODEDATA			GetDisplayMode( int ModeIndex ) ;									// �ύX�\�ȃf�B�X�v���C���[�h�̏����擾����( ModeIndex �� 0 �` GetDisplayModeNum �̖߂�l-1 )

// �p���b�g����֌W�֐�
extern 	int			SetPalette( int PalIndex, int Red, int Green, int Blue ) ;							// �p���b�g�̃Z�b�g
extern 	int			ReflectionPalette( void ) ;															// �Z�b�g�����p���b�g���n�[�h�E�G�A�ɔ��f������
extern 	int			GetPalette( int PalIndex, int *Red, int *Green, int *Blue ) ;						// �p���b�g�̎擾
extern	int			SetBmpPal( const TCHAR *FileName ) ;													// �a�l�o�t�@�C���̃p���b�g�𔽉f������
extern	int			SetBmpPalPart( const TCHAR *FileName, int StartNum, int GetNum, int SetNum ) ;		// �a�l�o�t�@�C������̃p���b�g�̕����擾
extern	int			GetGraphPalette( int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;	// ��������ɓǂݍ��񂾉摜�̃p���b�g���擾����(�t���J���[�摜�̏ꍇ�͖���)
extern  int			GetGraphOriginalPalette( int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ; // ��������ɓǂݍ��񂾉摜�� SetGraphPalette �ŕύX����O�̃p���b�g���擾����
extern	int			SetGraphPalette( int GrHandle, int ColorIndex, int Color ) ;							// ��������ɓǂݍ��񂾉摜�̃p���b�g��ύX����(�t���J���[�摜�̏ꍇ�͖���)
extern	int			ResetGraphPalette( int GrHandle ) ;													// SetGraphPalette �ŕύX�����p���b�g��S�Č��ɖ߂�

// �ȈՃO���t�B�b�N�֌W�֐�
extern	int			GetPixel( int x, int y ) ;																											// �w����W�̐F���擾����
extern	int			Paint( int x, int y, int FillColor, int BoundaryColor = -1 ) ;																		// �w��_���狫�E�F������Ƃ���܂œh��Ԃ�(���E�F�� -1 �ɂ���Ǝw��_�̐F�̗̈��h��Ԃ�)
extern	int			BltFastOrBitBlt( D_IDirectDrawSurface7 *Dest, D_IDirectDrawSurface7 *Src, int DestX, int DestY, RECT *SrcRect, int BltType = -1 ) ;	// �w��̃T�[�t�F�X����w��̃T�[�t�F�X�փO���t�B�b�N�f�[�^��]������

// �E�G�C�g�֌W�֐�
extern	int			WaitVSync( int SyncNum ) ;																												// ���������M����҂�

// ��ʑ���֌W�֐�
extern	int			ScreenFlip( void ) ;																													// ����ʂƕ\��ʂ���������
extern 	int			ScreenCopy( void ) ;																													// ����ʂ̓��e��\��ʂɕ`�悷��
extern	int			BltBackScreenToWindow( HWND Window, int ClientX, int ClientY ) ;																		// ����ʂ̓��e���w��̃E�C���h�E�ɓ]������
extern	int			BltRectBackScreenToWindow( HWND Window, RECT BackScreenRect, RECT WindowClientRect ) ;													// ����ʂ̎w��̗̈���E�C���h�E�̃N���C�A���g�̈�̎w��̗̈�ɓ]������
extern	int			GraphCopy( RECT *SrcRect, RECT *DestRect, int SrcHandle, int DestHandle = DX_SCREEN_BACK ) ;											// �摜�̓��e���R�s�[����
extern	int			SetGraphMode( int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int RefreshRate = 60 ) ;												// ��ʃ��[�h��ݒ肷��
extern	int			SetGraphDisplayArea( int x1, int y1, int x2, int y2 ) ;																					// ScreenFlip ���ɕ\��ʑS�̂ɓ]�����闠��ʂ̗̈��ݒ肷��( DxLib_Init �̑O�ł̂ݎg�p�\ )
extern	int			SetChangeScreenModeGraphicsSystemResetFlag( int Flag ) ;																				// ��ʃ��[�h�ύX��( �ƃE�C���h�E���[�h�ύX�� )�ɃO���t�B�b�N�X�V�X�e���̐ݒ��O���t�B�b�N�n���h�������Z�b�g���邩�ǂ�����ݒ肷��( TRUE:���Z�b�g����  FALSE:���Z�b�g���Ȃ� )


// �a�l�o�ۑ��֐�
// Jpeg_Quality         = 0:��掿�`100:���掿
// Png_CompressionLevel = 0:�����k�`  9:�ō����k
extern	int			SaveDrawScreen( int x1, int y1, int x2, int y2, const TCHAR *FileName, int SaveType = DX_IMAGESAVETYPE_BMP , int Jpeg_Quality = 80 , int Jpeg_Sample2x1 = TRUE , int Png_CompressionLevel = -1 ) ;		// ���ݕ`��ΏۂɂȂ��Ă����ʂ�ۑ�����
extern	int			SaveDrawScreenToBMP( int x1, int y1, int x2, int y2, const TCHAR *FileName ) ;														// ���ݕ`��ΏۂɂȂ��Ă����ʂ��a�l�o�`���ŕۑ�����
extern	int			SaveDrawScreenToJPEG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int Quality = 80 , int Sample2x1 = TRUE ) ;				// ���ݕ`��ΏۂɂȂ��Ă����ʂ��i�o�d�f�`���ŕۑ����� Quality = �掿�A�l���傫���قǒሳ�k���掿,0�`100 
extern	int			SaveDrawScreenToPNG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int CompressionLevel = -1 ) ;							// ���ݕ`��ΏۂɂȂ��Ă����ʂ��o�m�f�`���ŕۑ����� CompressionLevel = ���k���A�l���傫���قǍ����k�������ׁA�O�͖����k,0�`9









// Dx3D.cpp�֐��v���g�^�C�v�錾

// �ݒ�֌W
extern	D_IDirect3DDevice7* GetUseD3DDevObj( void ) ;																// �g�p���̂c�����������R�c�c�����������I�u�W�F�N�g�𓾂�
extern	int			SetUseDivGraphFlag( int Flag ) ;																// �K�v�Ȃ�O���t�B�b�N�̕������s�����A�t���O�̃Z�b�g
extern	int			SetUseMaxTextureSize( int Size ) ;																// �g�p����e�N�X�`���[�̍ő�T�C�Y���Z�b�g(0�Ńf�t�H���g)
extern	int			SetUseVertexBufferFlag( int Flag ) ;															// ���_�o�b�t�@���g�p���邩�ǂ�����ݒ肷��
//extern int		RenderVertexBuffer( void ) ;																	// ���_�o�b�t�@�ɗ��܂������_�f�[�^��f���o��
//extern VERTEX_2D*	GetVertexBuffer( int VertexNum = 6 , int PrimType = DX_PRIMTYPE_TRIANGLELIST ) ;				// �ǉ����_�o�b�t�@�̒��_�ǉ��A�h���X�𓾂�( �߂�l�̓e�N�X�`���Ȃ��̏ꍇ�� VERTEX_NOTEX_2D �ƂȂ� )
//extern void		_DrawPreparation( int GrHandle = DX_NONE_GRAPH , int ParamFlag = 0 ) ;							// �`�揀�����s��( ParamFlag �� DRAWPREP_TRANS �� )
//extern void		Add4VertexBuffer( void ) ;																		// GetVertexTo3DDevice �ɂ���ĂS���_�ǉ����ꂽ���Ƃ�O��ɒ��_�ǉ��������s��
//extern void		AddVertexBuffer( int VertexNum = 6 ) ;															// GetVertexTo3DDevice �ɂ���Ďw�萔���_���ǉ����ꂽ���Ƃ�O��ɒ��_�ǉ��������s��
//extern void		SetGraphTexture( int GrHandle ) ;																// �c�����������R�c�f�o�C�X�Ƀe�N�X�`�����Z�b�g����
extern	int			SetUseOldDrawModiGraphCodeFlag( int Flag ) ;													// �ȑO�� DrawModiGraph �֐��̃R�[�h���g�p���邩�ǂ����̃t���O���Z�b�g����

// ���̑��⏕�֐�
extern D_DDPIXELFORMAT*	GetTexPixelFormat( int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;	// �s�N�Z���t�H�[�}�b�g�𓾂�
extern COLORDATA*		GetTexColorData( int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;	// �J���[�f�[�^�𓾂�
extern D_DDPIXELFORMAT*	GetTexPixelFormat( IMAGEFORMATDESC *Format ) ;												// �t�H�[�}�b�g�Ɋ�Â����J���[�t�H�[�}�b�g�𓾂�
extern COLORDATA*		GetTexColorData( IMAGEFORMATDESC *Format ) ;												// �t�H�[�}�b�g�Ɋ�Â����J���[�f�[�^�𓾂�
extern D_DDPIXELFORMAT*	GetTexPixelFormat( int FormatIndex ) ;														// �w��̃t�H�[�}�b�g�C���f�b�N�X�̃J���[�t�H�[�}�b�g�𓾂�
extern COLORDATA*		GetTexColorData( int FormatIndex ) ;														// �w��̃t�H�[�}�b�g�C���f�b�N�X�̃J���[�f�[�^�𓾂�
extern D_DDPIXELFORMAT*	GetZBufferPixelFormat( int BitDepth ) ;														// �w��̃r�b�g�[�x�̂y�o�b�t�@�[�̃s�N�Z���t�H�[�}�b�g�𓾂�( ���݂̂Ƃ��� 16 �r�b�g�̂� )








// DxGraphics�֐��v���g�^�C�v�錾

// �O���t�B�b�N����֌W�֐�
extern	int			MakeGraph( int SizeX, int SizeY, int NotUse3DFlag = FALSE ) ;																								// ��̃O���t�B�b�N���쐬
extern	int			MakeScreen( int SizeX, int SizeY ) ;																														// �`��\�ȉ�ʂ��쐬
extern	int			DeleteGraph( int GrHandle, int LogOutFlag = FALSE ) ;																										// �w��̃O���t�B�b�N�n���h�����폜����
extern	int			DeleteSharingGraph( int GrHandle ) ;																														// �w��̃O���t�B�b�N�n���h���ƁA�����O���t�B�b�N�f�[�^����h�����Ă���O���t�B�b�N�n���h��( DerivationGraph �Ŕh�������n���h���ALoadDivGraph �ǂݍ���ō쐬���ꂽ�����̃n���h�� )����x�ɍ폜����
extern	int			GetGraphNum( void ) ;																																		// �L���ȃO���t�B�b�N�̐����擾����
extern	int			SetGraphLostFlag( int GrHandle, int *LostFlag ) ;																											// ������ɗ��Ă�t���O�̃|�C���^���Z�b�g����
extern	int			InitGraph( int LogOutFlag = FALSE ) ;																														// �摜�f�[�^�̏�����

extern	int			BltBmpToGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName, int CopyPointX, int CopyPointY, int GrHandle, int ReverseFlag ) ; // �摜�f�[�^�̓]��
extern	int			BltBmpToDivGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName, int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;	// �����摜�ւ̂a�l�o�̓]��
extern	int			BltBmpOrGraphImageToGraph( COLORDATA *SrcColorData, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										int CopyPointX, int CopyPointY, int GrHandle, int ReverseFlag ) ;																		// �a�l�o �� GraphImage ���摜�ɓ]��
extern	int			BltBmpOrGraphImageToGraph2( COLORDATA *SrcColorData, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										RECT *SrcRect, int DestX, int DestY, int GrHandle, int ReverseFlag ) ;																	// �a�l�o �� GraphImage ���摜�ɓ]��
extern	int			BltBmpOrGraphImageToDivGraph( COLORDATA *SrcColor, HBITMAP Bmp, HBITMAP AlphaMask, const TCHAR *GraphName,
										int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,
										int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;												// �����摜�ւ� �a�l�o �� GraphImage �̓]��

#ifndef DX_NON_MOVIE
extern	int			OpenMovieToOverlay( const TCHAR *FileName ) ;																												// �I�[�o�[���C�T�[�t�F�X���g�p�������[�r�[�t�@�C���̃I�[�v��
extern	int			UpdateMovieToOverlay( int x, int y, int ExRate, int ShowFlag, int MovieHandle ) ;																			// �I�[�o�[���C�T�[�t�F�X���g�p�������[�r�[�̕\���X�e�[�^�X�Z�b�g
extern	int			CloseMovieToOverlay( int MovieHandle ) ;																													// �I�[�o�[���C�T�[�t�F�X���g�p�������[�r�[�t�@�C�������
#endif
extern	int			ReloadFileGraphAll( void ) ;																																// �t�@�C������ǂݍ��񂾉摜�����ēx�ǂݍ���
extern	int			SetGraphTransColor( int GrHandle, int Red, int Green, int Blue ) ;																							// �摜�̓��ߐF��ύX����(�A���t�@�`�����l���g�p���͖���)

extern	int			RestoreGraph( int GrHandle ) ;																																// �摜�f�[�^�̃��X�g�A
extern	int			AllRestoreGraph( void ) ;																																	// ���ׂẲ摜�f�[�^�̃��X�g�A


// �O���t�B�b�N�`��֌W�֐�
extern	int			ClearDrawScreen( RECT *ClearRect = NULL ) ;																											// ��ʂ̏�Ԃ�����������
extern	int			ClearDrawScreenZBuffer( RECT *ClearRect = NULL ) ;																									// ��ʂ̂y�o�b�t�@�̏�Ԃ�����������
extern	int			ClsDrawScreen( void ) ;																																// ��ʂ̏�Ԃ�����������(ClearDrawScreen�̋�����)

extern	int			LoadGraphScreen( int x, int y, const TCHAR *GraphName, int TransFlag ) ;																				// �a�l�o�t�@�C����ǂ݂���ŉ�ʂɕ`�悷��
extern	int			DrawGraph( int x, int y, int GrHandle, int TransFlag ) ;																							// �O���t�B�b�N�̕`��
extern	int			DrawGraphF( float xf, float yf, int GrHandle, int TransFlag ) ;																						// �O���t�B�b�N�̕`��
extern	int			DrawExtendGraph( int x1, int y1, int x2, int y2, int GrHandle, int TransFlag ) ;																	// �O���t�B�b�N�̊g��k���`��
extern	int			DrawExtendGraphF( float x1f, float y1f, float x2f, float y2, int GrHandle, int TransFlag ) ;														// �O���t�B�b�N�̊g��k���`��
extern	int			DrawRotaGraph( int x, int y, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;									// �O���t�B�b�N�̉�]�`��
extern	int			DrawRotaGraphF( float xf, float yf, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;								// �O���t�B�b�N�̉�]�`��
extern	int			DrawRotaGraph2( int x, int y, int cx, int cy, double ExtRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;					// �O���t�B�b�N�̉�]�`��Q
extern	int			DrawRotaGraph2F( float xf, float yf, float cxf, float cyf, double ExtRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;		// �O���t�B�b�N�̉�]�`��Q
extern	int			DrawModiGraph( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int GrHandle, int TransFlag ) ;										// �摜�̎��R�ό`�`��
extern	int			DrawModiGraphF( float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int GrHandle, int TransFlag ) ;						// �摜�̎��R�ό`�`��( float �� )
extern	int			DrawTurnGraph( int x, int y, int GrHandle, int TransFlag ) ;																						// �摜�̍��E���]�`��
extern	int			DrawTurnGraphF( float xf, float yf, int GrHandle, int TransFlag ) ;																					// �摜�̍��E���]�`��
extern	int			DrawChipMap( int Sx, int Sy, int XNum, int YNum, int *MapData, int ChipTypeNum, int MapDataPitch, int *GrHandle, int TransFlag ) ;					// �`�b�v�O���t�B�b�N���g�����}�b�v�`��
extern	int			DrawChipMap( int MapWidth, int MapHeight, int *MapData, int ChipTypeNum, int *ChipGrHandle, int TransFlag,
										int MapDrawPointX, int MapDrawPointY, int MapDrawWidth, int MapDrawHeight, int ScreenX, int ScreenY ) ;							// �`�b�v�O���t�B�b�N���g�����}�b�v�`��
extern	int			DrawTile( int x1, int y1, int x2, int y2, int Tx, int Ty,
								double ExtRate, double Angle, int GrHandle, int TransFlag ) ;																			// �O���t�B�b�N���w��̈�Ƀ^�C����ɕ`�悷��
extern	int			DrawRectGraph( int DestX, int DestY, int SrcX, int SrcY, int Width, int Height, int GraphHandle, int TransFlag, int TurnFlag ) ;					// �O���t�B�b�N�̎w���`�����݂̂�`��
extern	int			DrawRectExtendGraph( int DestX1, int DestY1, int DestX2, int DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight, int GraphHandle, int TransFlag ) ;	// �O���t�B�b�N�̎w���`�����݂̂��g��`��
extern	int			DrawRectRotaGraph( int X, int Y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ; 
extern	int			DrawRectGraphF( float DestX, float DestY, int SrcX, int SrcY, int Width, int Height, int GraphHandle, int TransFlag, int TurnFlag ) ;					// �O���t�B�b�N�̎w���`�����݂̂�`��
extern	int			DrawRectExtendGraphF( float DestX1, float DestY1, float DestX2, float DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight, int GraphHandle, int TransFlag ) ;	// �O���t�B�b�N�̎w���`�����݂̂��g��`��
extern	int			DrawRectRotaGraphF( float X, float Y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ; 
extern	int			DrawBlendGraph( int x, int y, int GrHandle, int TransFlag, int BlendGraph, int BorderParam, int BorderRange ) ;										// �u�����h�摜�ƍ������ĉ摜��`�悷��
extern	int			DrawBlendGraphPos( int x, int y, int GrHandle, int TransFlag, int bx, int by, int BlendGraph, int BorderParam, int BorderRange ) ;					// �u�����h�摜�ƍ������ĉ摜��`�悷��( �u�����h�摜�̋N�_���W���w�肷��� )
extern	int			DrawCircleGauge( int CenterX, int CenterY, double Percent, int GrHandle ) ;																			// �~�O���t�I�ȕ`����s��
extern	int			DrawGraphToZBuffer( int X, int Y, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;															// �y�o�b�t�@�ɑ΂��ĉ摜�̕`����s��
extern	int			DrawTurnGraphToZBuffer( int x, int y, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;														// �y�o�b�t�@�ɑ΂��ĉ摜�̍��E���]�`��
extern	int			DrawExtendGraphToZBuffer( int x1, int y1, int x2, int y2, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �y�o�b�t�@�ɑ΂��ĉ摜�̊g��k���`��
extern	int			DrawRotaGraphToZBuffer( int x, int y, double ExRate, double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int TurnFlag = FALSE  ) ;	// �y�o�b�t�@�ɑ΂��ĉ摜�̉�]�`��
extern	int			DrawModiGraphToZBuffer( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;	// �y�o�b�t�@�ɑ΂��ĉ摜�̎��R�ό`�`��
extern	int			DrawBoxToZBuffer( int x1, int y1, int x2, int y2, int FillFlag, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;											// �y�o�b�t�@�ɑ΂��ċ�`�̕`����s��
extern	int			DrawCircleToZBuffer( int x, int y, int r, int FillFlag, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;													// �y�o�b�t�@�ɑ΂��ĉ~�̕`����s��
extern	int			DrawStringToZBuffer( int x, int y, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;															// �y�o�b�t�@�ɑ΂��ĕ�����̕`��
extern	int			DrawVStringToZBuffer( int x, int y, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;															// �y�o�b�t�@�ɑ΂��ĕ�����̕`��
extern	int			DrawStringToHandleToZBuffer( int x, int y, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int VerticalFlag = FALSE ) ;		// �y�o�b�t�@�ɑ΂��ĕ������`�悷��
extern	int			DrawVStringToHandleToZBuffer( int x, int y, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;									// �y�o�b�t�@�ɑ΂��ĕ������`�悷��
extern	int			DrawFormatStringToZBuffer( int x, int y, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;																			// �y�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawFormatVStringToZBuffer( int x, int y, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;																		// �y�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawFormatStringToHandleToZBuffer( int x, int y, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;													// �y�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawFormatVStringToHandleToZBuffer( int x, int y, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;												// �y�o�b�t�@�ɑ΂��ď����w�蕶�����`�悷��
extern	int			DrawExtendStringToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;													// �y�o�b�t�@�ɑ΂��ĕ�����̊g��`��
extern	int			DrawExtendVStringToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;													// �y�o�b�t�@�ɑ΂��ĕ�����̊g��`��
extern	int			DrawExtendStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ , int VerticalFlag = FALSE ) ;	// �y�o�b�t�@�ɑ΂��ĕ�������g��`�悷��
extern	int			DrawExtendVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */ ) ;							// �y�o�b�t�@�ɑ΂��ĕ�������g��`�悷��
extern	int			DrawExtendFormatStringToZBuffer( int x, int y, double ExRateX, double ExRateY, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;									// �y�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToZBuffer( int x, int y, double ExRateX, double ExRateY, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;									// �y�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;			// �y�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK �� */, const TCHAR *FormatString, ... ) ;			// �y�o�b�t�@�ɑ΂��ď����w�蕶������g��`�悷��
extern	int			DrawPolygonBase( VERTEX *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;									// �Q�c�|���S����`�悷��
extern	int			DrawPolygon( VERTEX *Vertex, int PolygonNum, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;																							// �Q�c�|���S����`�悷��
extern	int			DrawPrimitive2D( VERTEX2D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;														// �Q�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed2D( VERTEX2D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;		// �Q�c�v���~�e�B�u��`�悷��(�C���f�b�N�X)
extern	int			DrawPrimitive3D( VERTEX3D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;														// �R�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed3D( VERTEX3D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;		// �R�c�v���~�e�B�u��`�悷��(�C���f�b�N�X)
extern	int			DrawPrimitive3D_UseVertexBuffer( int VertexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;													// ���_�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive3D_UseVertexBuffer2( int VertexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */, int StartVertex, int UseVertexNum, int GrHandle, int TransFlag ) ;								// ���_�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;						// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST �� */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum, int GrHandle, int TransFlag ) ;						// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPolygon3D( VERTEX3D *Vertex, int PolygonNum, int GrHandle, int TransFlag ) ;																	// �R�c�|���S����`�悷��
extern	int			DrawPolygonIndexed3D( VERTEX3D *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum, int GrHandle, int TransFlag ) ;						// �R�c�|���S����`�悷��(�C���f�b�N�X)
extern	int			DrawPolygon3D_UseVertexBuffer( int VertexBufHandle, int GrHandle, int TransFlag ) ;																	// ���_�o�b�t�@���g�p���ĂR�c�|���S����`�悷��
extern	int			DrawPolygonIndexed3D_UseVertexBuffer( int VertexBufHandle, int IndexBufHandle, int GrHandle, int TransFlag ) ;										// ���_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@���g�p���ĂR�c�|���S����`�悷��
extern	int			DrawPolygon3DBase( VERTEX_3D *Vertex, int VertexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST �� */, int GrHandle, int TransFlag ) ;			// �R�c�|���S����`�悷��( ���o�[�W�����p )
extern	int			DrawPolygon3D( VERTEX_3D *Vertex, int PolygonNum, int GrHandle, int TransFlag ) ;																	// �R�c�|���S����`�悷��( ���o�[�W�����p )
extern	int			DrawGraph3D( float x, float y, float z, int GrHandle, int TransFlag ) ;																				// �O���t�B�b�N�̂R�c�`��
extern	int			DrawExtendGraph3D( float x, float y, float z, double ExRateX, double ExRateY, int GrHandle, int TransFlag ) ;										// �O���t�B�b�N�̊g��R�c�`��
extern	int			DrawRotaGraph3D( float x, float y, float z, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;						// �O���t�B�b�N�̉�]�R�c�`��
extern	int			DrawRota2Graph3D( float x, float y, float z, float cx, float cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;	// �O���t�B�b�N�̉�]�R�c�`��(��]���S�w��^)
extern	int			DrawModiBillboard3D( VECTOR Pos, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, int GrHandle, int TransFlag ) ;	// �O���t�B�b�N�̎��R�ό`�R�c�`��
extern	int			DrawBillboard3D( VECTOR Pos, float cx, float cy, float Size, float Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;						// �R�c��ԏ�ɃO���t�B�b�N��`��
extern	int			FillGraph( int GrHandle, int Red, int Green, int Blue, int Alpha = 255 ) ;																			// �O���t�B�b�N�����̐F�œh��Ԃ�
extern	int			DrawLine( int x1, int y1, int x2, int y2, int Color, int Thickness = 1 ) ;																			// ����`��
extern	int			DrawBox( int x1, int y1, int x2, int y2, int Color, int FillFlag ) ;																				// �l�p�`�̕`��
extern	int			DrawFillBox( int x1, int y1, int x2, int y2, int Color ) ;																							// ���g�̂���l�p��`��
extern	int			DrawLineBox( int x1, int y1, int x2, int y2, int Color ) ;																							// �l�p�`�̕`�� 
extern	int			DrawCircle( int x, int y, int r, int Color, int FillFlag = TRUE ) ;																					// �~��`��
extern	int			DrawOval( int x, int y, int rx, int ry, int Color, int FillFlag ) ;																					// �ȉ~��`��
extern	int			DrawTriangle( int x1, int y1, int x2, int y2, int x3, int y3, int Color, int FillFlag ) ;															// �O�p�`�̕`��
extern	int			DrawQuadrangle( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Color, int FillFlag ) ;											// �l�p�`�̕`��
extern 	int			DrawPixel( int x, int y, int Color ) ;																												// �_��`�悷��
extern 	int			DrawPixelSet( POINTDATA *PointData, int Num ) ;																										// �_�̏W����`��
extern	int			DrawLineSet( LINEDATA *LineData, int Num ) ;																										// ���̏W����`��
extern	int			DrawPixel3D( VECTOR Pos, int Color ) ;																												// �R�c�̓_��`�悷��
extern	int			DrawLine3D( VECTOR Pos1, VECTOR Pos2, int Color ) ;																									// �R�c�̐�����`�悷��
extern	int			DrawTriangle3D( VECTOR Pos1, VECTOR Pos2, VECTOR Pos3, int Color, int FillFlag ) ;																	// �R�c�̎O�p�`��`�悷��
extern	int			DrawCube3D( VECTOR Pos1, VECTOR Pos2, int DifColor, int SpcColor, int FillFlag ) ;																	// �R�c�̗����̂�`�悷��
extern	int			DrawSphere3D( VECTOR CenterPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;													// �R�c�̋��̂�`�悷��
extern	int			DrawCapsule3D( VECTOR Pos1, VECTOR Pos2, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;											// �R�c�̃J�v�Z����`�悷��
extern	int			DrawCone3D( VECTOR TopPos, VECTOR BottomPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;										// �R�c�̉~����`�悷��
extern	int			DrawString( int x, int y, const TCHAR *String, int Color, int EdgeColor = 0 ) ;																		// ������̕`��
extern	int			DrawVString( int x, int y, const TCHAR *String, int Color, int EdgeColor = 0 ) ;																		// ������̕`��
extern	int			DrawStringToHandle( int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;					// �������`�悷��
extern	int			DrawVStringToHandle( int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;												// �������`�悷��
extern	int			DrawFormatString( int x, int y, int Color, const TCHAR *FormatString, ... ) ;																		// �����w�蕶�����`�悷��
extern	int			DrawFormatVString( int x, int y, int Color, const TCHAR *FormatString, ... ) ;																		// �����w�蕶�����`�悷��
extern	int			DrawFormatStringToHandle( int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;												// �����w�蕶�����`�悷��
extern	int			DrawFormatVStringToHandle( int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;												// �����w�蕶�����`�悷��
extern	int			DrawExtendString( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int EdgeColor = 0 ) ;													// ������̊g��`��
extern	int			DrawExtendVString( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int EdgeColor = 0 ) ;													// ������̊g��`��
extern	int			DrawExtendStringToHandle( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;	// ��������g��`�悷��
extern	int			DrawExtendVStringToHandle( int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;							// ��������g��`�悷��
extern	int			DrawExtendFormatString( int x, int y, double ExRateX, double ExRateY, int Color, const TCHAR *FormatString, ... ) ;														// �����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVString( int x, int y, double ExRateX, double ExRateY, int Color, const TCHAR *FormatString, ... ) ;														// �����w�蕶������g��`�悷��
extern	int			DrawExtendFormatStringToHandle( int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;								// �����w�蕶������g��`�悷��
extern	int			DrawExtendFormatVStringToHandle( int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;								// �����w�蕶������g��`�悷��

extern	int			DrawNumberToI( int x, int y, int Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// �����^�̐��l��`�悷��
extern	int			DrawNumberToF( int x, int y, double Num, int Length, int Color, int EdgeColor = 0 ) ;																// ���������_�^�̐��l��`�悷��
extern	int			DrawNumberPlusToI( int x, int y, const TCHAR *NoteString, int Num, int RisesNum, int Color, int EdgeColor = 0 ) ;									// �����^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��
extern 	int			DrawNumberPlusToF( int x, int y, const TCHAR *NoteString, double Num, int Length, int Color, int EdgeColor = 0 ) ;									// ���������_�^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��

extern	int			DrawNumberToIToHandle( int x, int y, int Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;										// �����^�̐��l��`�悷��
extern	int			DrawNumberToFToHandle( int x, int y, double Num, int Length, int Color, int FontHandle, int EdgeColor = 0 ) ;										// ���������_�^�̐��l��`�悷��
extern	int			DrawNumberPlusToIToHandle( int x, int y, const TCHAR *NoteString, int Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;			// �����^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��
extern	int			DrawNumberPlusToFToHandle( int x, int y, const TCHAR *NoteString, double Num, int Length, int Color, int FontHandle, int EdgeColor = 0 ) ;			// ���������_�^�̐��l�Ƃ��̐����̕��������x�ɕ`�悷��

// ���_�o�b�t�@�֌W�֐�
extern	int			CreateVertexBuffer( int VertexNum, int VertexType /* DX_VERTEX_TYPE_NORMAL_3D �� */ ) ;																					// ���_�o�b�t�@���쐬����( -1:�G���[  0�ȏ�:���_�o�b�t�@�n���h�� )
extern	int			DeleteVertexBuffer( int VertexBufHandle ) ;																																// ���_�o�b�t�@���폜����
extern	int			InitVertexBuffer() ;																																					// ���ׂĂ̒��_�o�b�t�@���폜����
extern	int			SetVertexBufferData( int SetIndex, void *VertexData, int VertexNum, int VertexBufHandle ) ;																				// ���_�o�b�t�@�ɒ��_�f�[�^��]������
extern	int			CreateIndexBuffer( int IndexNum, int IndexType /* DX_INDEX_TYPE_16BIT �� */  ) ;																						// �C���f�b�N�X�o�b�t�@���쐬����( -1:�G���[�@0�ȏ�F�C���f�b�N�X�o�b�t�@�n���h�� )
extern	int			DeleteIndexBuffer( int IndexBufHandle ) ;																																// �C���f�b�N�X�o�b�t�@���폜����
extern	int			InitIndexBuffer() ;																																						// ���ׂẴC���f�b�N�X�o�b�t�@���폜����
extern	int			SetIndexBufferData( int SetIndex, void *IndexData, int IndexNum, int IndexBufHandle ) ;																					// �C���f�b�N�X�o�b�t�@�ɃC���f�b�N�X�f�[�^��]������

#ifndef DX_NON_DIRECTX9

// �V�F�[�_�[�֌W�֐�
extern	int			GetValidShaderVersion( void ) ;										// �g�p�ł���V�F�[�_�[�̃o�[�W�������擾����( 0=�g���Ȃ�  200=�V�F�[�_�[���f���Q�D�O���g�p�\  300=�V�F�[�_�[���f���R�D�O���g�p�\ )

extern	int			LoadVertexShader( const TCHAR *FileName ) ;							// ���_�V�F�[�_�[�o�C�i�����t�@�C������ǂݍ��ݒ��_�V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadVertexShaderFromMem( void *ImageAddress, int ImageSize ) ;		// ��������ԏ�ɑ��݂��钸�_�V�F�[�_�[�o�C�i�����璸�_�V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadPixelShader( const TCHAR *FileName ) ;							// �s�N�Z���V�F�[�_�[�o�C�i�����t�@�C������ǂݍ��݃s�N�Z���V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			LoadPixelShaderFromMem( void *ImageAddress, int ImageSize ) ;		// ��������ԏ�ɑ��݂���s�N�Z���V�F�[�_�[�o�C�i������s�N�Z���V�F�[�_�[�n���h�����쐬����( �߂�l -1:�G���[  -1�ȊO:�V�F�[�_�[�n���h�� )
extern	int			DeleteShader( int ShaderHandle ) ;									// �V�F�[�_�[�n���h���̍폜
extern	int			InitShader( void ) ;												// �V�F�[�_�[�n���h����S�č폜����

extern	int			GetConstIndexToShader( const TCHAR *ConstantName, int ShaderHandle ) ;		// �w��̖��O�����萔�̔ԍ����擾����
extern	int			SetVSConstF( int ConstantIndex, FLOAT4 Param ) ;							// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetVSConstFMtx( int ConstantIndex, MATRIX Param ) ;							// ���_�V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��
extern	int			SetVSConstI( int ConstantIndex, INT4 Param ) ;								// ���_�V�F�[�_�[�� int �^�萔��ݒ肷��
extern	int			SetVSConstB( int ConstantIndex, BOOL Param ) ;								// ���_�V�F�[�_�[�� BOOL �^�萔��ݒ肷��
extern	int			SetVSConstFArray( int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;	// ���_�V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstFMtxArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ; // ���_�V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstIArray( int ConstantIndex, INT4 *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� int �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetVSConstBArray( int ConstantIndex, BOOL *ParamArray, int ParamNum ) ;		// ���_�V�F�[�_�[�� BOOL �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )

extern	int			SetPSConstF( int ConstantIndex, FLOAT4 Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��
extern	int			SetPSConstFMtx( int ConstantIndex, MATRIX Param ) ;							// �s�N�Z���V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��
extern	int			SetPSConstI( int ConstantIndex, INT4 Param ) ;								// �s�N�Z���V�F�[�_�[�� int �^�萔��ݒ肷��
extern	int			SetPSConstB( int ConstantIndex, BOOL Param ) ;								// �s�N�Z���V�F�[�_�[�� BOOL �^�萔��ݒ肷��
extern	int			SetPSConstFArray( int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;	// �s�N�Z���V�F�[�_�[�� float �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstFMtxArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ; // �s�N�Z���V�F�[�_�[�� float �^�萔�ɍs���ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstIArray( int ConstantIndex, INT4 *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� int �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )
extern	int			SetPSConstBArray( int ConstantIndex, BOOL *ParamArray, int ParamNum ) ;		// �s�N�Z���V�F�[�_�[�� BOOL �^�萔��ݒ肷��( �z����g���ĘA�ԃC���f�b�N�X�Ɉ�x�ɐݒ� )

//extern int		SetRenderTargetToShader( int TargetIndex, int DrawScreen ) ;		// �V�F�[�_�[�`��ł̕`����ݒ肷��
extern	int			SetUseTextureToShader( int StageIndex, int GraphHandle ) ;			// �V�F�[�_�[�`��Ŏg�p����O���t�B�b�N��ݒ肷��
extern	int			SetUseVertexShader( int ShaderHandle ) ;							// �V�F�[�_�[�`��Ɏg�p���钸�_�V�F�[�_�[��ݒ肷��( -1��n���Ɖ��� )
extern	int			SetUsePixelShader( int ShaderHandle ) ;								// �V�F�[�_�[�`��Ɏg�p����s�N�Z���V�F�[�_�[��ݒ肷��( -1��n���Ɖ��� )

extern	int			DrawPrimitive2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, int PrimitiveType ) ;												// �V�F�[�_�[���g���ĂQ�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitive3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, int PrimitiveType ) ;												// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��
extern	int			DrawPrimitiveIndexed2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType ) ;	// �V�F�[�_�[���g���ĂQ�c�v���~�e�B�u��`�悷��(�C���f�b�N�X)
extern	int			DrawPrimitiveIndexed3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType ) ;	// �V�F�[�_�[���g���ĂR�c�v���~�e�B�u��`�悷��(�C���f�b�N�X)

#endif // DX_NON_DIRECTX9

// �R�c�`��֌W�֐�
//extern void			SetColorVertexState( LPVERTEXDATA Vertex, float x, float y, float z, float rhw, int red, int green, int blue, int alpha, float tu, float tv ) ;	// �R�c���_�f�[�^���Z�b�g����  

// �`��ݒ�֌W�֐�
extern	int			SetDrawMode( int DrawMode ) ;										// �`�惂�[�h���Z�b�g����
extern	int			SetMaxAnisotropy( int MaxAnisotropy ) ;								// �ő�ٕ����̒l���Z�b�g����
extern	int			SetDrawBlendMode( int BlendMode, int BlendParam ) ;					// �`��u�����h���[�h���Z�b�g����
extern	int			SetBlendGraph( int BlendGraph, int BorderParam, int BorderRange ) ;	// �`�揈�����ɕ`�悷��摜�ƃu�����h���郿�`�����l���t���摜���Z�b�g����( BlendGraph �� -1 �Ńu�����h�@�\�𖳌� )
extern	int			SetBlendGraphPosition( int x, int y ) ;								// �u�����h�摜�̋N�_���W���Z�b�g����
extern	int			SetDrawBright( int RedBright, int GreenBright, int BlueBright ) ;	// �`��P�x���Z�b�g
extern	int			SetDrawScreen( int DrawScreen ) ;									// �`����ʂ̃Z�b�g
extern	int			SetDrawArea( int x1, int y1, int x2, int y2 ) ;						// �`��\�̈�̃Z�b�g
extern	int			SetDraw3DScale( float Scale ) ;										// �R�c�`��̃X�P�[�����Z�b�g����
extern	int			SetDrawAreaFull( void ) ;											// �`��\�̈��`��Ώۉ�ʑS�̂ɂ���
extern	int			SetUse3DFlag( int Flag ) ;											// �R�c�@�\���g�����A�̃t���O���Z�b�g
extern	int			SetUseHardwareVertexProcessing( int Flag ) ;						// �n�[�h�E�G�A�̒��_���Z�����@�\���g�p���邩�ǂ�����ݒ肷��
extern	int			SetRestoreShredPoint( void (* ShredPoint )( void ) ) ;				// SetRestoreGraphCallback �̋���
extern	int			SetRestoreGraphCallback( void (* Callback )( void ) ) ;				// �O���t�B�b�N�n���h�������֐��̓o�^
extern	int			RunRestoreShred( void ) ;											// �O���t�B�b�N�����֐��̎��s
extern	int			SetTransformToWorld( MATRIX *Matrix ) ;								// ���[���h�ϊ��p�s����Z�b�g����
extern	int			SetTransformToView( MATRIX *Matrix ) ;								// �r���[�ϊ��p�s����Z�b�g����
extern	int			SetTransformToProjection( MATRIX *Matrix ) ;						// ���e�ϊ��p�s����Z�b�g����
extern	int			SetTransformToViewport( MATRIX *Matrix ) ;							// �r���[�|�[�g�s����Z�b�g����
extern	int			SetUseCullingFlag( int Flag ) ;										// SetUseBackCulling �̋�����
extern	int			SetUseBackCulling( int Flag /* DX_CULLING_LEFT �� */ ) ;			// �|���S���J�����O�̗L���A�������Z�b�g����
extern	int			SetTextureAddressMode( int Mode /* DX_TEXADDRESS_WRAP �� */ , int Stage = -1 ) ;		// �e�N�X�`���A�h���X���[�h��ݒ肷��
extern	int			SetTextureAddressModeUV( int ModeU, int ModeV, int Stage = -1 ) ;	// �e�N�X�`���A�h���X���[�h��ݒ肷��
extern	int			SetTextureAddressTransform( float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// �e�N�X�`�����W�ϊ��p�����[�^���Z�b�g����
extern	int			SetTextureAddressTransformMatrix( MATRIX Matrix ) ;					// �e�N�X�`�����W�ϊ��s����Z�b�g����
extern	int			ResetTextureAddressTransform( void ) ;								// �e�N�X�`�����W�ϊ��p�����[�^�����Z�b�g����
extern	int			SetFogEnable( int Flag ) ;											// �t�H�O��L���ɂ��邩�ǂ�����ݒ肷��( TRUE:�L��  FALSE:���� )
extern	int			SetFogMode( int Mode /* DX_FOGMODE_NONE �� */ ) ;					// �t�H�O���[�h��ݒ肷��
extern	int			SetFogColor( int r, int g, int b ) ;								// �t�H�O�J���[��ύX����
extern	int			SetFogStartEnd( float start, float end ) ;							// �t�H�O���n�܂鋗���ƏI�����鋗����ݒ肷��( 0.0f �` 1.0f )
extern	int			SetFogDensity( float density ) ;									// �t�H�O�̖��x��ݒ肷��( 0.0f �` 1.0f )
extern	int			SetUseSystemMemGraphCreateFlag( int Flag ) ;						// �V�X�e����������ɃO���t�B�b�N���쐬���邩�ǂ����̃t���O���Z�b�g����( TRUE:�V�X�e����������ɍ쐬  FALSE:�u�q�`�l��ɍ쐬 )
extern	int			SetUseVramFlag( int Flag ) ;										// �u�q�`�l���g�p���邩�̃t���O���Z�b�g����
extern	int			RestoreGraphSystem( void ) ;										// �c�w���C�u�����̃O���t�B�b�N�֘A�̕��A�������s��
extern	int			SetAeroDisableFlag( int Flag ) ;									// Vista�ȍ~�� Windows Aero �𖳌��ɂ��邩�ǂ������Z�b�g����ATRUE:�����ɂ���  FALSE:�L���ɂ���( DxLib_Init �̑O�ɌĂԕK�v������܂� )

// �O���t�B�b�N���擾�֌W�֐�

//extern	int			GetGraphHandle( IMAGEDATA *GraphData ) ;													// �����̃O���t�B�b�N�C���f�b�N�X�ԍ����擾����
//extern	IMAGEDATA 	*GetGraphData( int GrHandle ) ;																// �O���t�B�b�N�̃f�[�^���C���f�b�N�X�l������o��

extern	int			GetDrawScreenGraph( int x1, int y1, int x2, int y2, int GrHandle, int UseClientFlag = TRUE ) ;	// �A�N�e�B�u�ɂȂ��Ă����ʂ���w��̈�̃O���t�B�b�N���擾����
extern	DWORD*		GetFullColorImage( int GrHandle ) ;																// �w��̉摜�̂`�q�f�a�W�̃t���J���[�C���[�W���擾����

extern	int			GraphLock( int GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = NULL ) ;	// �O���t�B�b�N�������̈�̃��b�N
extern	int			GraphUnLock( int GrHandle ) ;																	// �O���t�B�b�N�������̈�̃��b�N����

extern	int			SetUseGraphZBuffer( int GrHandle, int UseFlag ) ;												// �O���t�B�b�N�ɂy�o�b�t�@���g�p���邩�ǂ�����ݒ肷��

extern	int			GetGraphSize( int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;									// �O���t�B�b�N�̃T�C�Y�𓾂�
extern	int			GetScreenState( int *SizeX, int *SizeY, int *ColorBitDepth ) ;									// ���݂̉�ʂ̑傫���ƃJ���[�r�b�g���𓾂� 
extern	int			GetUse3DFlag( void ) ;																			// �`��ɂR�c�@�\���g�����t���O���擾
extern	int			GetValidRestoreShredPoint( void ) ;																// �O���t�B�b�N�����֐��̗L�����擾																
extern	int			GetTransformToViewMatrix( MATRIX *MatBuf ) ;													// �r���[�s����擾����
extern	int			GetTransformToWorldMatrix( MATRIX *MatBuf ) ;													// ���[���h�s����擾����
extern	int			GetTransformToProjectionMatrix( MATRIX *MatBuf ) ;												// �ˉe�s����擾����
extern	int			GetTransformPosition( VECTOR *LocalPos, float *x, float *y ) ;									// ���[�J�����W�����ʍ��W���擾����
extern	float		GetBillboardPixelSize( VECTOR WorldPos, float WorldSize ) ;										// ���[���h��ԏ�̃r���{�[�h�̃T�C�Y����X�N���[���ɓ��e�����ꍇ�̃s�N�Z���P�ʂ̃T�C�Y���擾����
extern	VECTOR		ConvWorldPosToScreenPos( VECTOR WorldPos ) ;													// ���[���h���W���X�N���[�����W�ɕϊ�����
extern	VECTOR		ConvScreenPosToWorldPos( VECTOR ScreenPos ) ;													// �X�N���[�����W�����[���h���W�ɕϊ�����
extern	VECTOR		ConvScreenPosToWorldPos_ZLinear( VECTOR ScreenPos ) ;											// �X�N���[�����W�����[���h���W�ɕϊ�����( Z���W�����` )
extern	int			GetUseVramFlag( void ) ;																		// �Q�c�O���t�B�b�N�T�[�t�F�X�쐬���ɃV�X�e���������[���g�p���邩�̃t���O�擾

// �⏕�֌W
extern	int			GetCreateGraphColorData( COLORDATA *ColorData, IMAGEFORMATDESC *Format ) ;									// ���ꂩ��V���ɃO���t�B�b�N���쐬����ꍇ�Ɏg�p����J���[�����擾����

// �摜�쐬�p�֌W
//extern int		SetGraphName( int Handle, const char *GraphName ) ;																																																// ����̃t�@�C������摜��ǂݍ��񂾏ꍇ�̃t�@�C���p�X���Z�b�g����
extern	int			CreateDXGraph( BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int TextureFlag ) ;																																									// GraphImage �f�[�^����T�C�Y������o���A����ɍ������O���t�B�b�N�n���h�����쐬����
//extern int		CreateDXDivGraph( BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag ) ;																							// GraphImage �f�[�^�ɍ������T�C�Y�̕����O���t�B�b�N�n���h�����쐬����
extern	int			DerivationGraph( int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle ) ;																																								// �w��̃O���t�B�b�N�̎w�蕔�������𔲂��o���ĐV���ȃO���t�B�b�N�n���h�����쐬����

#ifndef DX_NON_MOVIE
// ���[�r�[�O���t�B�b�N�֌W�֐�
extern	int			PlayMovie( const TCHAR *FileName, int ExRate, int PlayType ) ;								// ����t�@�C���̍Đ�
extern	int			OpenMovieToGraph( const TCHAR *FileName, int FullColor = TRUE ) ;							// ���[�r�[���J��
extern 	int			PlayMovieToGraph( int GraphHandle, int PlayType = DX_PLAYTYPE_BACK , int SysPlay = 0 ) ;	// ���[�r�[�O���t�B�b�N�Ɋ܂܂�郀�[�r�[�̍Đ����J�n����
extern 	int			PauseMovieToGraph( int GraphHandle, int SysPause = 0 ) ;									// ���[�r�[�O���t�B�b�N�Ɋ܂܂�郀�[�r�[�̍Đ����X�g�b�v����
extern	int			AddMovieFrameToGraph( int GraphHandle, unsigned int FrameNum ) ;							// ���[�r�[�̃t���[����i�߂�A�߂����Ƃ͏o���Ȃ�( ���[�r�[����~��ԂŁA���� Ogg Theora �̂ݗL�� )
extern	int			SeekMovieToGraph( int GraphHandle, int Time ) ;												// ���[�r�[�̍Đ��ʒu��ݒ肷��(�~���b�P��)
extern 	int			GetMovieStateToGraph( int GraphHandle ) ;													// ���[�r�[�̍Đ���Ԃ𓾂�
extern	int			SetMovieVolumeToGraph( int Volume, int GraphHandle ) ;										// ���[�r�[�̃{�����[�����Z�b�g����(0�`10000)
extern	BASEIMAGE*	GetMovieBaseImageToGraph( int GraphHandle ) ;												// ���[�r�[�̊�{�C���[�W�f�[�^���擾����
extern	int			GetMovieTotalFrameToGraph( int GraphHandle ) ;												// ���[�r�[�̑��t���[�����𓾂�( Ogg Theora �ł̂ݗL�� )
extern	int			TellMovieToGraph( int GraphHandle ) ;														// ���[�r�[�̍Đ��ʒu���擾����(�~���b�P��)
extern	int			TellMovieToGraphToFrame( int GraphHandle ) ;												// ���[�r�[�̍Đ��ʒu���擾����(�t���[���P��)
extern	int			SeekMovieToGraphToFrame( int GraphHandle, int Frame ) ;										// ���[�r�[�̍Đ��ʒu��ݒ肷��(�t���[���P��)
extern	LONGLONG	GetOneFrameTimeMovieToGraph( int GraphHandle ) ;											// ���[�r�[�̂P�t���[��������̎��Ԃ𓾂�
extern	int			GetLastUpdateTimeMovieToGraph( int GraphHandle ) ;											// ���[�r�[�̃C���[�W���Ō�ɍX�V�������Ԃ𓾂�(�~���b�P��)

#endif








// DxGraphicsBase.cpp �֐��v���g�^�C�v�錾

// �O���t�B�b�N�n���h���쐬�n
extern	int			LoadBmpToGraph( const TCHAR *GraphName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL ) ;										// �摜��ǂ݂��� 
extern	int			LoadGraph( const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																								// �摜�t�@�C���̃������ւ̓ǂ݂���
extern	int			LoadReverseGraph( const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																						// �摜�t�@�C���̃������ւ̔��]�ǂݍ���
extern	int			LoadDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;						// �摜�̕����ǂ݂���
extern	int			LoadDivBmpToGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag, int ReverseFlag ) ;			// �摜�t�@�C���̕����ǂ݂���
extern	int			LoadReverseDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;				// �摜�̔��]�����ǂ݂���
extern	int			LoadBlendGraph( const TCHAR *FileName ) ;																													// �摜�t�@�C������u�����h�p�摜��ǂݍ���
extern	int			LoadGraphToResource( int ResourceID ) ;																														// ���\�[�X����摜�f�[�^��ǂݍ���
extern	int			LoadDivGraphToResource( int ResourceID, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;											// ���\�[�X����摜�f�[�^�𕪊��ǂݍ��݂���
extern	int			LoadGraphToResource( const TCHAR *ResourceName, const TCHAR *ResourceType ) ;																					// ���\�[�X����摜�f�[�^��ǂݍ���
extern	int			LoadDivGraphToResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;		// ���\�[�X����摜�f�[�^�𕪊��ǂݍ��݂���

extern	int			CreateGraphFromMem( void *MemImage, int MemImageSize, void *AlphaImage = NULL , int AlphaImageSize = 0 , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																						// ��������̃O���t�B�b�N�C���[�W����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromMem( void *MemImage, int MemImageSize, int GrHandle, void *AlphaImage = NULL , int AlphaImageSize = 0 , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																		// ��������̃O���t�B�b�N�C���[�W��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromMem( void *MemImage, int MemImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaImage = NULL , int AlphaImageSize = 0 ) ;				// ��������̃O���t�B�b�N�C���[�W���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromMem( void *MemImage, int MemImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaImage = NULL , int AlphaImageSize = 0 ) ;			// ��������̃O���t�B�b�N�C���[�W��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																				// �r�b�g�}�b�v�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int GrHandle, BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// �r�b�g�}�b�v�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL ) ;		// �r�b�g�}�b�v�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromBmp( BITMAPINFO *BmpInfo, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaInfo = NULL , void *AlphaData = NULL ) ;	// �r�b�g�}�b�v�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateGraphFromGraphImage( BASEIMAGE *Image, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																														// GraphImage�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																								// GraphImage�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromGraphImage( BASEIMAGE *Image, int GrHandle, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																										// GraphImage�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			ReCreateGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int GrHandle, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;																				// GraphImage�f�[�^��������̃O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateDivGraphFromGraphImage( BASEIMAGE *Image, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;												// GraphImage�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			CreateDivGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;						// GraphImage�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *Image, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;											// GraphImage�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *Image, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE , int DataReverseFlag = TRUE ) ;					// GraphImage�f�[�^��������̕����O���t�B�b�N�n���h���Ƀf�[�^��]������
extern	int			CreateGraph( int Width, int Height, int Pitch, void *GraphData, void *AlphaData = NULL , int GrHandle = -1 ) ;																																		// ��������̃O���t�B�b�N�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			CreateDivGraph( int Width, int Height, int Pitch, void *GraphData, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, void *AlphaData = NULL ) ;																					// ��������̃O���t�B�b�N�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraph( int Width, int Height, int Pitch, void *GraphData, int GrHandle, void *AlphaData = NULL ) ;																																			// ��������̃O���t�B�b�N�f�[�^����O���t�B�b�N�n���h�����č쐬����
extern	int			CreateGraphFromSoftImage( int SIHandle ) ;																													// �\�t�g�E�G�A�ň����C���[�W����O���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
extern	int			CreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����( -1:�G���[  -1�ȊO:�O���t�B�b�N�n���h�� )
extern	int			ReCreateGraphFromSoftImage( int SIHandle, int GrHandle ) ;																									// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			ReCreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle ) ;															// �\�t�g�E�G�A�ň����C���[�W��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			CreateDivGraphFromSoftImage( int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;											// �\�t�g�E�G�A�ň����C���[�W���番���O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromBaseImage( BASEIMAGE *BaseImage ) ;																											// ��{�C���[�W�f�[�^����O���t�B�b�N�n���h�����쐬����
extern	int			CreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY ) ;																	// ��{�C���[�W�̎w��̗̈���g���ăO���t�B�b�N�n���h�����쐬����
extern	int			ReCreateGraphFromBaseImage( BASEIMAGE *BaseImage, int GrHandle ) ;																							// ��{�C���[�W�f�[�^��������̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			ReCreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, int GrHandle ) ;													// ��{�C���[�W�̎w��̗̈���g���Ċ����̃O���t�B�b�N�n���h���ɉ摜�f�[�^��]������
extern	int			CreateDivGraphFromBaseImage( BASEIMAGE *BaseImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;									// ��{�C���[�W�f�[�^���番���O���t�B�b�N�n���h�����쐬����
extern	int			ReloadGraph( const TCHAR *FileName, int GrHandle, int ReverseFlag = FALSE ) ;																				// �摜�ւ̉摜�f�[�^�̓ǂݍ���
extern	int			ReloadDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int ReverseFlag = FALSE ) ;						// �摜�ւ̉摜�f�[�^�̕����ǂݍ���
extern	int			ReloadReverseGraph( const TCHAR *FileName, int GrHandle ) ;																									// �摜�ւ̉摜�f�[�^�̓ǂݍ���
extern	int			ReloadReverseDivGraph( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;										// �摜�ւ̉摜�f�[�^�̕����ǂݍ���

// ��{�C���[�W�`��
extern	int			DrawBaseImage( int x, int y, BASEIMAGE *BaseImage ) ;																																															// ��{�C���[�W�f�[�^��`�悷��

// �J�����֌W�֐�
extern	int			SetCameraNearFar( float Near, float Far ) ;																			// �J������ Near�N���b�v�ʂ� Far�N���b�v�ʂ̋�����ݒ肷��
extern	int			SetCameraPositionAndTarget_UpVecY( VECTOR Position, VECTOR Target ) ;												// �J�����̐ݒ������A���_�A�����_�A�A�b�v�x�N�g���͂x����
extern	int			SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR Target, VECTOR Up ) ;									// �J�����̐ݒ������A���_�A�����_�A�A�b�v�x�N�g���w���
extern	int			SetCameraPositionAndAngle( VECTOR Position, float VRotate, float HRotate, float TRotate ) ;							// �J�����̐ݒ������A������]�p�x�A������]�p�x�A�P���]�p�x�A���_�w���
extern	int			SetCameraViewMatrix( MATRIX ViewMatrix ) ;																			// �r���[�s��𒼐ڐݒ肷��
extern	int			SetCameraScreenCenter( float x, float y ) ;																			// ��ʏ�ɂ�����J���������Ă���f���̒��S�̍��W��ݒ肷��

extern	int			SetupCamera_Perspective( float Fov ) ;																				// ���ߖ@�J�������Z�b�g�A�b�v����
extern	int			SetupCamera_Ortho( float Size ) ;																					// ���ˉe�J�������Z�b�g�A�b�v����
extern	int			SetupCamera_ProjectionMatrix( MATRIX ProjectionMatrix ) ;															// �ˉe�s���ݒ肷��
extern	int			SetCameraDotAspect( float DotAspect ) ;																				// �J�����̃h�b�g�A�X�y�N�g���ݒ肷��

extern	float		GetCameraNear( void ) ;																								// �J������ Near �N���b�v�ʂ̋������擾����
extern	float		GetCameraFar( void ) ;																								// �J������ Far �N���b�v�ʂ̋������擾����

extern	VECTOR		GetCameraPosition( void ) ;																							// �J�����̈ʒu���擾����
extern	VECTOR		GetCameraTarget( void ) ;																							// �J�����̒����_���擾����
extern	VECTOR		GetCameraUpVector( void ) ;																							// �J�����̎����ɐ����ȏ�����̃x�N�g���𓾂�
extern	float		GetCameraAngleHRotate( void ) ;																						// �J�����̐��������̌������擾����
extern	float		GetCameraAngleVRotate( void ) ;																						// �J�����̐��������̌������擾����
extern	float		GetCameraAngleTRotate( void ) ;																						// �J�����̌����̔P��p�x���擾����

extern	MATRIX		GetCameraViewMatrix( void ) ;																						// �r���[�s����擾����
extern	float		GetCameraFov( void ) ;																								// �J�����̎���p���擾����
extern	float		GetCameraSize( void ) ;																								// �J�����̎���T�C�Y���擾����
extern	MATRIX		GetCameraProjectionMatrix( void ) ;																					// �ˉe�s����擾����
extern	float		GetCameraDotAspect( void ) ;																						// �J�����̃h�b�g�A�X�y�N�g��𓾂�

// ���C�g�֌W�֐�
extern	int			SetUseLighting( int Flag ) ;																						// ���C�e�B���O�v�Z�@�\���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialUseVertDifColor( int UseFlag ) ;																			// �R�c�}�`�`��̃��C�e�B���O�v�Z�ɒ��_�J���[�̃f�B�t���[�Y�J���[���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialUseVertSpcColor( int UseFlag ) ;																			// �R�c�}�`�`��̃��C�e�B���O�v�Z�ɒ��_�J���[�̃X�y�L�����J���[���g�p���邩�ǂ�����ݒ肷��
extern	int			SetMaterialParam( MATERIALPARAM Material ) ;																		// �R�c�}�`�`��̃��C�e�B���O�v�Z�Ɏg�p����}�e���A���p�����[�^��ݒ肷��
extern	int			SetUseSpecular( int UseFlag ) ;																						// �R�c�}�`�`��ɃX�y�L�������g�p���邩�ǂ�����ݒ肷��
extern	int			SetGlobalAmbientLight( COLOR_F Color ) ;																			// �O���[�o���A���r�G���g���C�g�J���[��ݒ肷��

extern	int			ChangeLightTypeDir( VECTOR Direction ) ;																			// ���C�g�̃^�C�v���f�B���N�V���i�����C�g�ɂ���
extern	int			ChangeLightTypeSpot( VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ���C�g�̃^�C�v���X�|�b�g���C�g�ɂ���
extern	int			ChangeLightTypePoint( VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;					// ���C�g�̃^�C�v���|�C���g���C�g�ɂ���
extern	int			SetLightEnable( int EnableFlag ) ;																					// ���C�g�̗L���A�������Z�b�g����
extern	int			SetLightDifColor( COLOR_F Color ) ;																					// ���C�g�̃f�B�t���[�Y�J���[��ݒ肷��
extern	int			SetLightSpcColor( COLOR_F Color ) ;																					// ���C�g�̃X�y�L�����J���[��ݒ肷��
extern	int			SetLightAmbColor( COLOR_F Color ) ;																					// ���C�g�̃A���r�G���g�J���[��ݒ肷��
extern	int			SetLightDirection( VECTOR Direction ) ;																				// ���C�g�̕�����ݒ肷��
extern	int			SetLightPosition( VECTOR Position ) ;																				// ���C�g�̈ʒu��ݒ肷��
extern	int			SetLightRangeAtten( float Range, float Atten0, float Atten1, float Atten2 ) ;										// ���C�g�̋��������p�����[�^��ݒ肷��( �L�������A���������W���O�A�P�A�Q )
extern	int			SetLightAngle( float OutAngle, float InAngle ) ;																	// ���C�g�̃X�|�b�g���C�g�̃p�����[�^��ݒ肷��( �O���R�[���p�x�A�����R�[���p�x )
extern	int			GetLightType( void ) ;																								// ���C�g�̃^�C�v���擾����( �߂�l�� DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			GetLightEnable( void ) ;																							// ���C�g���ʂ̗L���A�������擾����( TRUE:�L��  FALSE:���� )
extern	COLOR_F		GetLightDifColor( void ) ;																							// ���C�g�̃f�B�t���[�Y�J���[���擾����
extern	COLOR_F		GetLightSpcColor( void ) ;																							// ���C�g�̃X�y�L�����J���[���擾����
extern	COLOR_F		GetLightAmbColor( void ) ;																							// ���C�g�̃A���r�G���g�J���[���擾����
extern	VECTOR		GetLightDirection( void ) ;																							// ���C�g�̕������擾����
extern	VECTOR		GetLightPosition( void ) ;																							// ���C�g�̈ʒu���擾����
extern	int			GetLightRangeAtten( float *Range, float *Atten0, float *Atten1, float *Atten2 )	;									// ���C�g�̋��������p�����[�^���擾����( �L�������A���������W���O�A�P�A�Q )
extern	int			GetLightAngle( float *OutAngle, float *InAngle ) ;																	// ���C�g�̃X�|�b�g���C�g�̃p�����[�^���擾����( �O���R�[���p�x�A�����R�[���p�x )

extern	int			CreateDirLightHandle( VECTOR Direction ) ;																			// �f�B���N�V���i�����C�g�n���h�����쐬����
extern	int			CreateSpotLightHandle( VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// �X�|�b�g���C�g�n���h�����쐬����
extern	int			CreatePointLightHandle( VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;					// �|�C���g���C�g�n���h�����쐬����
extern	int			DeleteLightHandle( int LHandle ) ;																					// ���C�g�n���h�����폜����
extern	int			DeleteLightHandleAll( void ) ;																						// ���C�g�n���h����S�č폜����
extern	int			SetLightTypeHandle( int LHandle, int LightType ) ;																	// ���C�g�n���h���̃��C�g�̃^�C�v��ύX����( DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			SetLightEnableHandle( int LHandle, int EnableFlag ) ;																// ���C�g�n���h���̃��C�g���ʂ̗L���A������ݒ肷��( TRUE:�L��  FALSE:���� )
extern	int			SetLightDifColorHandle( int LHandle, COLOR_F Color ) ;																// ���C�g�n���h���̃��C�g�̃f�B�t���[�Y�J���[��ݒ肷��
extern	int			SetLightSpcColorHandle( int LHandle, COLOR_F Color ) ;																// ���C�g�n���h���̃��C�g�̃X�y�L�����J���[��ݒ肷��
extern	int			SetLightAmbColorHandle( int LHandle, COLOR_F Color ) ;																// ���C�g�n���h���̃��C�g�̃A���r�G���g�J���[��ݒ肷��
extern	int			SetLightDirectionHandle( int LHandle, VECTOR Direction ) ;															// ���C�g�n���h���̃��C�g�̕�����ݒ肷��
extern	int			SetLightPositionHandle( int LHandle, VECTOR Position ) ;															// ���C�g�n���h���̃��C�g�̈ʒu��ݒ肷��
extern	int			SetLightRangeAttenHandle( int LHandle, float Range, float Atten0, float Atten1, float Atten2 ) ;					// ���C�g�n���h���̃��C�g�̋��������p�����[�^��ݒ肷��( �L�������A���������W���O�A�P�A�Q )
extern	int			SetLightAngleHandle( int LHandle, float OutAngle, float InAngle ) ;													// ���C�g�n���h���̃��C�g�̃X�|�b�g���C�g�̃p�����[�^��ݒ肷��( �O���R�[���p�x�A�����R�[���p�x )
extern	int			GetLightTypeHandle( int LHandle ) ;																					// ���C�g�n���h���̃��C�g�̃^�C�v���擾����( �߂�l�� DX_LIGHTTYPE_DIRECTIONAL �� )
extern	int			GetLightEnableHandle( int LHandle ) ;																				// ���C�g�n���h���̃��C�g���ʂ̗L���A�������擾����( TRUE:�L��  FALSE:���� )
extern	COLOR_F		GetLightDifColorHandle( int LHandle ) ;																				// ���C�g�n���h���̃��C�g�̃f�B�t���[�Y�J���[���擾����
extern	COLOR_F		GetLightSpcColorHandle( int LHandle ) ;																				// ���C�g�n���h���̃��C�g�̃X�y�L�����J���[���擾����
extern	COLOR_F		GetLightAmbColorHandle( int LHandle ) ;																				// ���C�g�n���h���̃��C�g�̃A���r�G���g�J���[���擾����
extern	VECTOR		GetLightDirectionHandle( int LHandle ) ;																			// ���C�g�n���h���̃��C�g�̕������擾����
extern	VECTOR		GetLightPositionHandle( int LHandle ) ;																				// ���C�g�n���h���̃��C�g�̈ʒu���擾����
extern	int			GetLightRangeAttenHandle( int LHandle, float *Range, float *Atten0, float *Atten1, float *Atten2 ) ;				// ���C�g�n���h���̃��C�g�̋��������p�����[�^���擾����( �L�������A���������W���O�A�P�A�Q )
extern	int			GetLightAngleHandle( int LHandle, float *OutAngle, float *InAngle ) ;												// ���C�g�n���h���̃��C�g�̃X�|�b�g���C�g�̃p�����[�^���擾����( �O���R�[���p�x�A�����R�[���p�x )

// �O���t�B�b�N�֌W�ݒ�֐�
extern	int			SetGraphColorBitDepth( int ColorBitDepth ) ;						// SetCreateGraphColorBitDepth �̋�����
extern	int			SetCreateGraphColorBitDepth( int BitDepth ) ;						// �쐬����O���t�B�b�N�̐F�[�x��ݒ肷��
extern	int			GetCreateGraphColorBitDepth( void ) ;								// �쐬����O���t�B�b�N�̐F�[�x��ݒ肷��
extern 	int			GetGraphColorBitDepth( void ) ;										// GetCreateGraphColorBitDepth �̋�����
extern	int			SetDrawValidGraphCreateFlag( int Flag ) ;							// �`��\�ȃO���t�B�b�N���쐬���邩�ǂ����̃t���O���Z�b�g����( TRUE:�`��\  FALSE:�`��s�\ )
extern	int			GetDrawValidGraphCreateFlag( void ) ;								// �`��\�ȃO���t�B�b�N���쐬���邩�ǂ����̃t���O���擾����
extern	int			SetLeftUpColorIsTransColorFlag( int Flag ) ;						// �摜����̐F�𓧉ߐF�ɂ��邩�ǂ����̃t���O���Z�b�g����
extern	int			GetUseBlendGraphCreateFlag( void ) ;								// �u�����h�����p�摜���쐬���邩�ǂ����̃t���O���擾����
extern	int			GetUseSystemMemGraphCreateFlag( void ) ;							// �V�X�e����������ɃO���t�B�b�N���쐬���邩�ǂ����̃t���O���擾����( TRUE:�V�X�e����������ɍ쐬  FALSE:�u�q�`�l��ɍ쐬 )
extern	int			SetUseBlendGraphCreateFlag( int Flag ) ;							// �u�����h�����p�摜���쐬���邩�ǂ����̃t���O���Z�b�g����
extern	int			SetUseAlphaTestGraphCreateFlag( int Flag ) ;						// �A���t�@�e�X�g���g�p����O���t�B�b�N���쐬���邩�ǂ����̃t���O���Z�b�g����
extern	int			SetUseAlphaTestFlag( int Flag ) ;									// SetUseAlphaTestGraphCreateFlag �̋�����
extern	int			SetUseNoBlendModeParam( int Flag ) ;								// SetDrawBlendMode �֐��̑������� DX_BLENDMODE_NOBLEND ���������ۂɁA�f�t�H���g�ł͑������͓����łQ�T�T���w�肵�����ƂɂȂ邪�A���̎����Q�T�T�������Ȃ����ǂ�����ݒ肷��( TRUE:���Ȃ�(�������̒l���g�p�����)   FALSE:����(�������̒l�͖�������� 255 ����Ɏg�p�����)(�f�t�H���g) )���`�����l���t���摜�ɑ΂��ĕ`����s���ꍇ�݈̂Ӗ�������֐�
extern	int			SetDrawValidFlagOf3DGraph( int Flag ) ;								// SetDrawValidGraphCreateFlag �̋�����
extern	int			GetUseAlphaTestFlag( void ) ;										// GetUseAlphaTestGraphCreateFlag �̋�����
extern	int			GetUseAlphaTestGraphCreateFlag( void ) ;							// �A���t�@�e�X�g���g�p����O���t�B�b�N���쐬���邩�ǂ����̃t���O���擾����
extern	int			SetDrawValidAlphaChannelGraphCreateFlag( int Flag ) ;				// �`��\�ȃ��`�����l���t���摜���쐬���邩�ǂ����̃t���O���Z�b�g����,SetDrawValidGraphCreateFlag �֐��ŕ`��\�摜���쐬����悤�ɐݒ肳��Ă��Ȃ��ƌ��ʂ��Ȃ�( TRUE:���`�����l���t�� FALSE:���`�����l���Ȃ� )
extern	int			SetUseZBufferFlag( int Flag ) ;										// �y�o�b�t�@��L���ɂ��邩�A�t���O���Z�b�g����( �Q�c�ƂR�c�`��ɉe�� )
extern	int			SetWriteZBufferFlag( int Flag ) ;									// �y�o�b�t�@�ɏ������݂��s�����A�t���O���Z�b�g����( �Q�c�ƂR�c�`��ɉe�� )
extern	int			SetZBufferCmpType( int CmpType /* DX_CMP_NEVER �� */ ) ;			// �y�l�̔�r���[�h���Z�b�g����( �Q�c�ƂR�c�`��ɉe�� )
extern	int			SetZBias( int Bias ) ;												// �y�o�C�A�X���Z�b�g����( �Q�c�ƂR�c�`��ɉe�� )
extern	int			SetUseZBuffer3D( int Flag ) ;										// �y�o�b�t�@��L���ɂ��邩�A�t���O���Z�b�g����( �R�c�}�`�`��݂̂ɉe�� )
extern	int			SetWriteZBuffer3D( int Flag ) ;										// �y�o�b�t�@�ɏ������݂��s�����A�t���O���Z�b�g����( �R�c�}�`�`��݂̂ɉe�� )
extern	int			SetZBufferCmpType3D( int CmpType /* DX_CMP_NEVER �� */ ) ;			// �y�l�̔�r���[�h���Z�b�g����( �R�c�}�`�`��݂̂ɉe�� )
extern	int			SetZBias3D( int Bias ) ;											// �y�o�C�A�X���Z�b�g����( �R�c�}�`�`��݂̂ɉe�� )
extern	int			SetDrawZ( float Z ) ;												// �Q�c�`�掞�ɂy�o�b�t�@�ɏ������ނy�l��ύX����
extern	int			SetUseTransColor( int Flag ) ;										// ���ߐF�@�\���g�p���邩�ǂ�����ݒ肷��
extern	int			SetUseTransColorGraphCreateFlag( int Flag ) ;						// ���ߐF�@�\���g�p���邱�Ƃ�O��Ƃ����摜�̓ǂݍ��ݏ������s�����ǂ�����ݒ肷��( TRUE �ɂ���� SetDrawMode( DX_DRAWMODE_BILINEAR ); ��������Ԃ� DrawGraphF ���̕��������_�^���W���󂯎��֐��ŏ����_�ȉ��̒l���w�肵���ꍇ�ɔ�������`�挋�ʂ̕s���R���ɘa������ʂ����� ( �f�t�H���g�� FALSE ) )
extern 	int			SetUseAlphaChannelGraphCreateFlag( int Flag ) ;						// ���`�����l���t���O���t�B�b�N���쐬���邩�ǂ����̃t���O���Z�b�g����( TRUE:���`�����l���t��   FALSE:���`�����l������ )
extern 	int			SetUseGraphAlphaChannel( int Flag ) ;								// SetUseAlphaChannelGraphCreateFlag �̋�����
extern 	int			GetUseAlphaChannelGraphCreateFlag( void ) ;							// ���`�����l���t���O���t�B�b�N���쐬���邩�ǂ����̃t���O���擾����( TRUE:���`�����l���t��   FALSE:���`�����l������ )
extern 	int			GetUseGraphAlphaChannel( void ) ;									// GetUseAlphaChannelGraphCreateFlag �̋�����
extern	int			SetUseNotManageTextureFlag( int Flag ) ;							// ��Ǘ��e�N�X�`�����g�p���邩�A�̃t���O���Z�b�g( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
extern	int			SetTransColor( int Red, int Green, int Blue ) ;						// �O���t�B�b�N�ɐݒ肷�铧�ߐF���Z�b�g����
extern	int			GetTransColor( int *Red, int *Green, int *Blue ) ;					// ���ߐF�𓾂�
extern	int			GetDrawArea( RECT *Rect ) ;											// �`��\�̈�𓾂�
extern	int			GetUseNotManageTextureFlag( void ) ;								// ��Ǘ��e�N�X�`�����g�p���邩�A�̃t���O���擾����( TRUE:�g�p����  FALSE:�g�p���Ȃ� )
extern	int			SetUseBasicGraphDraw3DDeviceMethodFlag( int Flag ) ;				// �P���}�`�̕`��ɂR�c�f�o�C�X�̋@�\���g�p���邩�ǂ����̃t���O���Z�b�g����
extern	int			SetWindowDrawRect( RECT *DrawRect ) ;								// �ʏ�g�p���Ȃ�
extern	int			GetDrawBlendMode( int *BlendMode, int *BlendParam ) ;				// �`��u�����h���[�h���擾����
extern	int			GetDrawMode( void ) ;												// �`�惂�[�h���擾����
extern	int			GetDrawBright( int *Red, int *Green, int *Blue ) ;					// �`��P�x���擾����
extern	int			GetActiveGraph( void ) ;											// �A�N�e�B�u�ɂȂ��Ă���O���t�B�b�N�̃n���h���𓾂�
extern	int			GetTexFormatIndex( IMAGEFORMATDESC *Format ) ;						// �e�N�X�`���t�H�[�}�b�g�̃C���f�b�N�X�𓾂�
extern	int			SetWaitVSyncFlag( int Flag ) ;										// �u�r�x�m�b�҂������邩�̃t���O�Z�b�g
extern	int			GetWaitVSyncFlag( void ) ;											// �u�r�x�m�b�҂�������ݒ�ɂȂ��Ă��邩�ǂ������擾����
extern	int			ColorKaiseki( void *PixelData, COLORDATA* ColorData ) ;				// �F�r�b�g�����
extern	int			SetDefTransformMatrix( void ) ;										// �f�t�H���g�̕ϊ��s����Z�b�g����
extern	int			CreatePixelFormat( D_DDPIXELFORMAT *PixelFormatBuf, int ColorBitDepth,
										 DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;		// DDPIXELFORMAT�f�[�^���쐬����
extern	int			SetEmulation320x240( int Flag ) ;									// �U�S�O���S�W�O�̉�ʂłR�Q�O���Q�S�O�̉�ʉ𑜓x�ɂ��邩�ǂ����̃t���O���Z�b�g����A�U�S�O���S�W�O�ȊO�̉𑜓x�ł͖���( TRUE:�L��  FALSE:���� )








// DxMask.cpp �֐��v���g�^�C�v�錾

#ifndef DX_NON_MASK

// �}�X�N�֌W 
extern	int			CreateMaskScreen( void ) ;																				// �}�X�N�X�N���[�����쐬����
extern	int			DeleteMaskScreen( void ) ;																				// �}�X�N�X�N���[�����폜����
extern	void*		GetMaskSurface( void ) ; /* �߂�l�� IDirectDrawSurface7 * �ɃL���X�g���ĉ����� */						// �}�X�N�T�[�t�F�X���擾����
//extern	MEMIMG*	GetMaskMemImg( void ) ;																				// �}�X�N�T�[�t�F�X�̑���� MEMIMG ���擾����
extern	int			DrawMaskToDirectData( int x, int y, int Width, int Height, void *MaskData , int TransMode ) ;			// �}�X�N�̃f�[�^�𒼐ڃZ�b�g
extern	int			DrawFillMaskToDirectData( int x1, int y1, int x2, int y2,  int Width, int Height, void *MaskData ) ;	// �}�X�N�̃f�[�^�𒼐ڃ}�X�N��ʑS�̂ɕ`�悷��

extern	int			SetUseMaskScreenFlag( int ValidFlag ) ;																	// �}�X�N�g�p���[�h��ύX
extern	int			GetUseMaskScreenFlag( void ) ;																			// �}�X�N�g�p���[�h�̎擾
extern	int			FillMaskScreen( int Flag ) ;																			// �}�X�N�X�N���[�����w��̐F�œh��Ԃ�

extern	int			InitMask( void ) ;																						// �}�X�N�f�[�^������������
extern	int			MakeMask( int Width, int Height ) ;																		// �}�X�N�f�[�^�̒ǉ�
extern	int			GetMaskSize( int *WidthBuf, int *HeightBuf, int MaskHandle ) ;											// �}�X�N�̑傫���𓾂� 
extern	int			SetDataToMask( int Width, int Height, void *MaskData, int MaskHandle ) ;								// �}�X�N�̃f�[�^���}�X�N�ɓ]������
extern	int			DeleteMask( int MaskHandle ) ;																			// �}�X�N�f�[�^���폜
extern	int			BmpBltToMask( HBITMAP Bmp, int BmpPointX, int BmpPointY, int MaskHandle ) ;								// �}�X�N�f�[�^�ɂa�l�o�f�[�^���}�X�N�f�[�^�ƌ����Ăē]��
extern	int			LoadMask( const TCHAR *FileName ) ;																		// �}�X�N�f�[�^�����[�h����
extern	int			LoadDivMask( const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;	// �}�X�N���摜���番���ǂ݂���
extern	int			DrawMask( int x, int y, int MaskHandle, int TransMode ) ;												// �}�X�N���Z�b�g����
extern	int			DrawFormatStringMask( int x, int y, int Flag, const TCHAR *FormatString, ... ) ;							// �����w�肠��̕�������}�X�N�X�N���[���ɕ`�悷��
extern	int			DrawFormatStringMaskToHandle( int x, int y, int Flag, int FontHandle, const TCHAR *FormatString, ... ) ;	// �����w�肠��̕�������}�X�N�X�N���[���ɕ`�悷��(�t�H���g�n���h���w���)( SetFontCacheToTextureFlag( FALSE ) ; �ɂ��č쐬�����t�H���g�n���h���̂ݎg�p�\ )
extern	int			DrawStringMask( int x, int y, int Flag, const TCHAR *String ) ;											// ��������}�X�N�X�N���[���ɕ`�悷��
extern	int			DrawStringMaskToHandle( int x, int y, int Flag, int FontHandle, const TCHAR *String ) ;					// ��������}�X�N�X�N���[���ɕ`�悷��(�t�H���g�n���h���w���)( SetFontCacheToTextureFlag( FALSE ) ; �ɂ��č쐬�����t�H���g�n���h���̂ݎg�p�\ )
extern	int			DrawFillMask( int x1, int y1, int x2, int y2, int MaskHandle ) ;										// �w��̃}�X�N����ʂ����ς��ɓW�J����	
extern	int			SetMaskTransColor( int ColorCode ) ;																	// ( Ver3.0 �ȍ~�ł͖��� ) �}�X�N�Ɏg�����ߐF�̃Z�b�g
extern	int			SetMaskReverseEffectFlag( int ReverseFlag ) ;															// �}�X�N�̐��l�ɑ΂�����ʂ��t�]������

extern 	int			GetMaskScreenData( int x1, int y1, int x2, int y2, int MaskHandle ) ;									// �}�X�N��ʏ�̕`���Ԃ��擾����
extern	int			GetMaskUseFlag( void ) ;																				// �}�X�N�X�N���[�����g�p�����t���O�̎擾

#endif










// DxMovie.cpp �֐��v���g�^�C�v�錾
extern	int			SetMovieRightImageAlphaFlag( int Flag ) ;							// ����t�@�C���̉E�������A���t�@���Ƃ��Ĉ������ǂ������Z�b�g����( TRUE:�A���t�@���Ƃ��Ĉ��� )













// DxFont.cpp �֐��v���g�^�C�v�錾

// �t�H���g�A������`��֌W�֐�
extern	int			EnumFontName( TCHAR *NameBuffer, int NameBufferNum, int JapanOnlyFlag = TRUE ) ;								// �g�p�\�ȃt�H���g�̖��O�����ׂė񋓂���( NameBuffer �� 64�o�C�g��؂�Ŗ��O���i�[����܂� )
extern	int			EnumFontNameEx( TCHAR *NameBuffer, int NameBufferNum, int CharSet = -1 /* DX_CHARSET_DEFAULT �� */ ) ;		// �g�p�\�ȃt�H���g�̖��O�����ׂė񋓂���( NameBuffer �� 64�o�C�g��؂�Ŗ��O���i�[����܂� )
extern	int			InitFontToHandle( void ) ;																					// �t�H���g�̃X�e�[�^�X���f�t�H���g�ɖ߂�
extern	int			CreateFontToHandle( const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE , int DataIndex = -1 , int ID = -1 ) ;			// �V�����t�H���g�f�[�^���쐬
extern	int			SetFontSpaceToHandle( int Point, int FontHandle ) ;															// ���Ԃ�ύX����
extern	int			SetDefaultFontState( const TCHAR *FontName, int Size, int Thick ) ;											// �f�t�H���g�t�H���g�̃X�e�[�^�X���ꊇ�ݒ肷��
extern	int			DeleteFontToHandle( int FontHandle ) ;																		// �t�H���g�L���b�V���̐�����I������
extern	int			SetFontLostFlag( int FontHandle, int *LostFlag ) ;															// ������� TRUE �ɂ���t���O�ւ̃|�C���^��ݒ肷��
extern	int			SetFontSize( int FontSize ) ;																				// �`�悷��t�H���g�̃T�C�Y���Z�b�g����
extern	int			SetFontThickness( int ThickPal ) ;																			// �t�H���g�̑������Z�b�g
extern	int			SetFontSpace( int Point ) ;																					// ���Ԃ�ύX����
extern	int			SetFontCacheToTextureFlag( int Flag ) ;																		// �t�H���g�̃L���b�V���Ƀe�N�X�`�����g�p���邩�A�t���O���Z�b�g����
extern	int			SetFontChacheToTextureFlag( int Flag ) ;																	// �t�H���g�̃L���b�V���Ƀe�N�X�`�����g�p���邩�A�t���O���Z�b�g����(�뎚��)
extern	int			SetFontCacheCharNum( int CharNum ) ;																		// �t�H���g�L���b�V���ŃL���b�V���ł��镶�������w�肷��
extern	int			ChangeFont( const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_SHFTJIS �� */ ) ;							// �t�H���g��ύX
extern	int			ChangeFontType( int FontType ) ;																			// �t�H���g�^�C�v�̕ύX
// FontCacheStringDraw �� DrawString ���g���Ă�������
extern	int			FontCacheStringDrawToHandle( int x, int y, const TCHAR *StrData, int Color, int EdgeColor,
													BASEIMAGE *DestImage, RECT *ClipRect /* NULL �� */ , int FontHandle,
													int VerticalFlag = FALSE , SIZE *DrawSizeP = NULL ) ;
extern	int			FontBaseImageBlt( 
						int x, int y, const TCHAR *StrData,
						BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,
						int VerticalFlag = FALSE ) ;																			// ��{�C���[�W�ɕ�����C���[�W��]������
extern	int			FontBaseImageBltToHandle( 
						int x, int y, const TCHAR *StrData,
						BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,
						int FontHandle, int VerticalFlag = FALSE ) ;															// ��{�C���[�W�ɕ�����C���[�W��]������

extern	int			GetFontMaxWidth( void ) ;																					// �����̍ő啝�𓾂�
extern	int			GetFontMaxWidthToHandle( int FontHandle ) ;																	// �����̍ő啝�𓾂�
extern	int			GetFontCharInfo( int FontHandle, const TCHAR *Char, int *DrawX, int *DrawY, int *NextCharX, int *SizeX, int *SizeY ) ;		// �w��̕����̕`������擾����
extern	int			GetDrawStringWidth( const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;							// ������̕��𓾂�
extern	int			GetDrawFormatStringWidth( const TCHAR *FormatString, ... ) ;													// �����t��������̕`�敝�𓾂�
extern	int			GetDrawStringWidthToHandle( const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// ������̕��𓾂�
extern	int			GetDrawFormatStringWidthToHandle( int FontHandle, const TCHAR *FormatString, ... ) ;							// �����t��������̕`�敝�𓾂�
extern	int			GetDrawExtendStringWidth( double ExRateX, const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;							// ������̕��𓾂�
extern	int			GetDrawExtendFormatStringWidth( double ExRateX, const TCHAR *FormatString, ... ) ;												// �����t��������̕`�敝�𓾂�
extern	int			GetDrawExtendStringWidthToHandle( double ExRateX, const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// ������̕��𓾂�
extern	int			GetDrawExtendFormatStringWidthToHandle( double ExRateX, int FontHandle, const TCHAR *FormatString, ... ) ;						// �����t��������̕`�敝�𓾂�
extern	int			GetFontStateToHandle( TCHAR *FontName, int *Size, int *Thick, int FontHandle) ;								// �t�H���g�̏��𓾂�
extern	int			GetDefaultFontHandle( void ) ;																				// �f�t�H���g�̃t�H���g�̃n���h���𓾂�
extern	int			GetFontChacheToTextureFlag( void ) ;																		// �t�H���g�Ƀe�N�X�`���L���b�V�����g�p���邩�ǂ������擾����(�뎚��)
extern	int			GetFontCacheToTextureFlag( void ) ;																			// �t�H���g�Ƀe�N�X�`���L���b�V�����g�p���邩�ǂ������擾����
extern	int			CheckFontChacheToTextureFlag( int FontHandle ) ;															// �w��̃t�H���g���e�N�X�`���L���b�V�����g�p���Ă��邩�ǂ����𓾂�(�뎚��)
extern	int			CheckFontCacheToTextureFlag( int FontHandle ) ;																// �w��̃t�H���g���e�N�X�`���L���b�V�����g�p���Ă��邩�ǂ����𓾂�
//extern	LPFONTMANAGE GetFontManageDataToHandle( int FontHandle ) ;																// �t�H���g�Ǘ��f�[�^�̎擾
extern	int			CheckFontHandleValid( int FontHandle ) ;																	// �w��̃t�H���g�n���h�����L�����ۂ����ׂ�
extern	int			MultiByteCharCheck( const char *Buf, int CharSet /* DX_CHARSET_SHFTJIS */ ) ;									// �Q�o�C�g���������ׂ�( TRUE:�Q�o�C�g����  FALSE:�P�o�C�g���� )
extern	int			GetFontCacheCharNum( void ) ;																				// �t�H���g�L���b�V���ŃL���b�V���ł��镶�������擾����( �߂�l  0:�f�t�H���g  1�ȏ�:�w�蕶���� )
extern	int			GetFontSize( void ) ;																						// �t�H���g�̃T�C�Y�𓾂�
extern	int			GetFontSizeToHandle( int FontHandle ) ;																		// �t�H���g�̃T�C�Y�𓾂�









// DxMath.cpp �֐��v���g�^�C�v�錾

// ���Z���C�u����
extern	int			CreateIdentityMatrix( MATRIX *Out ) ;														// �P�ʍs����쐬����
extern	int			CreateLookAtMatrix( MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;					// �r���[�s����쐬����
extern	int			CreateLookAtMatrix2( MATRIX *Out, VECTOR *Eye, double XZAngle, double Oira ) ;				// �r���[�s����쐬����
extern	int			CreateLookAtMatrixRH( MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;					// �r���[�s����쐬����(�E����W�n�p)
extern	int			CreateMultiplyMatrix( MATRIX *Out, MATRIX *In1, MATRIX *In2 ) ;								// �s��̐ς����߂�
extern	int			CreatePerspectiveFovMatrix( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;	// �ˉe�s����쐬����
extern	int			CreatePerspectiveFovMatrixRH( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;	// �ˉe�s����쐬����(�E����W�n�p)
extern	int			CreateOrthoMatrix( MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;	// ���ˉe�s����쐬����
extern	int			CreateOrthoMatrixRH( MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;	// ���ˉe�s����쐬����(�E����W�n�p)
extern	int			CreateScalingMatrix( MATRIX *Out, float sx, float sy, float sz ) ;							// �X�P�[�����O�s����쐬����
extern	int			CreateRotationXMatrix( MATRIX *Out, float Angle ) ;											// �w���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateRotationYMatrix( MATRIX *Out, float Angle ) ;											// �x���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateRotationZMatrix( MATRIX *Out, float Angle ) ;											// �y���𒆐S�Ƃ�����]�s����쐬����
extern	int			CreateTranslationMatrix( MATRIX *Out, float x, float y, float z ) ;							// ���s�ړ��s����쐬����
extern	int			CreateTransposeMatrix( MATRIX *Out, MATRIX *In ) ;											// �]�u�s����쐬����
extern	int			CreateInverseMatrix( MATRIX *Out, MATRIX *In ) ;											// �t�s����쐬����
extern	int			CreateViewportMatrix( MATRIX *Out, float CenterX, float CenterY, float Width, float Height ) ; // �r���[�|�[�g�s����쐬����
extern	int			CreateRotationXYZMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �w����]���x����]���y����]�����������s����쐬����
extern	int			CreateRotationXZYMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �w����]���y����]���x����]�����������s����쐬����
extern	int			CreateRotationYXZMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �x����]���w����]���y����]�����������s����쐬����
extern	int			CreateRotationYZXMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �x����]���y����]���w����]�����������s����쐬����
extern	int			CreateRotationZXYMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �y����]���w����]���x����]�����������s����쐬����
extern	int			CreateRotationZYXMatrix( MATRIX *Out, float XRot, float YRot, float ZRot ) ;				// �y����]���x����]���w����]�����������s����쐬����
extern	int			GetMatrixXYZRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�w�x�y����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixXZYRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�w�y�x����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixYXZRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�x�w�y����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixYZXRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�x�y�w����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixZXYRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�y�w�x����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			GetMatrixZYXRotation( MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;		// �s�񂩂�y�x�w����]�̒l���擾����( �߂�l�@-1:�W���o�����b�N����  0:���� )
extern	int			VectorNormalize( VECTOR *Out, VECTOR *In ) ;												// �x�N�g���𐳋K������
extern	int			VectorScale( VECTOR *Out, VECTOR *In, float Scale ) ;										// �x�N�g�����X�J���[�{����
extern	int			VectorMultiply( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// �x�N�g���̊|���Z������
extern	int			VectorSub( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;										// Out = In1 - In2 �̃x�N�g���v�Z������ 
extern	int			VectorAdd( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;										// Out = In1 + In2 �̃x�N�g���v�Z������ 
extern	int			VectorOuterProduct( VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;								// In1��In2�̊O�ς��v�Z����
extern	float		VectorInnerProduct( VECTOR *In1, VECTOR *In2 ) ;											// In1��In2�̓��ς��v�Z����
extern	int			VectorRotationX( VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂w�������ɂ�����]���s��
extern	int			VectorRotationY( VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂x�������ɂ�����]���s��
extern	int			VectorRotationZ( VECTOR *Out, VECTOR *In, double Angle ) ;									// �x�N�g���̂y�������ɂ�����]���s��
extern	int			VectorTransform( VECTOR *Out, VECTOR *InVec, MATRIX *InMatrix ) ;							// �x�N�g���s���4x4�����s�����Z����( w �� 1 �Ɖ��� )
extern	int			VectorTransform4( VECTOR *Out, float *V4Out, VECTOR *InVec, float *V4In, MATRIX *InMatrix ) ; // �x�N�g���s���4x4�����s�����Z����( w �̗v�f��n�� )

extern	void		TriangleBarycenter( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR Position, float *u, float *v, float *w ) ;	// �w��̍��W����O�p�`�̏d�S�����߂�

extern	float		Segment_Segment_MinLength( VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;								// ��̐����̍ŋߓ_�Ԃ̋����𓾂�
extern	float		Segment_Segment_MinLength_Square( VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// ��̐����̍ŋߓ_�Ԃ̋����̓��𓾂�
extern	float		Segment_Triangle_MinLength( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;			// �����ƎO�p�`�̍ŋߓ_�Ԃ̋����𓾂� 
extern	float		Segment_Triangle_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// �����ƎO�p�`�̍ŋߓ_�Ԃ̋����̓��𓾂� 
extern	float		Segment_Point_MinLength( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;															// �����Ɠ_�̈�ԋ߂������𓾂�
extern	float		Segment_Point_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;														// �����Ɠ_�̈�ԋ߂������̓��𓾂�
extern	float		Triangle_Point_MinLength( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;									// �O�p�`�Ɠ_�̈�ԋ߂������𓾂�
extern	float		Triangle_Point_MinLength_Square( VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;								// �O�p�`�Ɠ_�̈�ԋ߂������̓��𓾂�

extern	HITRESULT_LINE HitCheck_Line_Triangle( VECTOR LinePos1, VECTOR LinePos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;					// �O�p�`�Ɛ��̓����蔻��
extern	int			HitCheck_Triangle_Triangle( VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, 
											    VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;												// �O�p�`�ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Line_Sphere( VECTOR LinePos1, VECTOR LinePos2, VECTOR SphereCenterPos, float SphereR ) ;												// ���Ƌ��̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Sphere_Sphere( VECTOR Sphere1CenterPos, float Sphere1R, VECTOR Sphere2CenterPos, float Sphere2R ) ;									// ���Ƌ��̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Sphere_Triangle( VECTOR SphereCenterPos, float SphereR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;				// ���ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Capsule_Capsule( VECTOR Cap1Pos1, VECTOR Cap1Pos2, float Cap1R, VECTOR Cap2Pos1, VECTOR Cap2Pos2, float Cap2R ) ;						// �J�v�Z�����m�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )
extern	int			HitCheck_Capsule_Triangle( VECTOR CapPos1, VECTOR CapPos2, float CapR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;		// �J�v�Z���ƎO�p�`�̓����蔻��( TRUE:�������Ă���  FALSE:�������Ă��Ȃ� )

// ���̑�
extern	int			RectClipping( RECT *MotoRect, RECT *ClippuRect ) ;											// ��`�̃N���b�s���O
extern	int			RectAdjust( RECT *Rect ) ;																	// ��`�� left �� right ���l���傫���ꍇ�Ȃǂ̌���␳����
extern	int			GetRectSize( RECT *Rect, int *Width, int *Height ) ;										// ��`�̕��ƍ��������߂�

// �\�L�ȗ���
extern	MATRIX		MGetIdent( void ) ;														// �P�ʍs��𓾂�
extern	MATRIX		MMult( MATRIX In1, MATRIX In2 ) ;										// �s��̏�Z���s��
extern	MATRIX		MScale( MATRIX InM, float Scale ) ;										// �s��̃X�P�[�����O���s��
extern	MATRIX		MAdd( MATRIX In1, MATRIX In2 ) ;										// �s��̑����Z���s��
extern	MATRIX		MGetScale( VECTOR Scale ) ;												// �g��s��𓾂�
extern	MATRIX		MGetRotX( float XAxisRotate ) ;											// �w����]�s��𓾂�
extern	MATRIX		MGetRotY( float YAxisRotate ) ;											// �x����]�s��𓾂�
extern	MATRIX		MGetRotZ( float ZAxisRotate ) ;											// �y����]�s��𓾂�
extern	MATRIX		MGetRotAxis( VECTOR RotateAxis, float Rotate ) ;						// �w�莲�Ŏw��p�x��]����s��𓾂�
extern	MATRIX		MGetRotVec2( VECTOR In1, VECTOR In2 ) ;									// In1 �̌������� In2 �̌����֕ϊ������]�s��𓾂�( In2 �� In1 ���^�t�̃x�N�g���̏ꍇ�͉�]���͕s�� )
extern	MATRIX		MGetTranslate( VECTOR Trans ) ;											// ���s�ړ��s��𓾂�
extern	MATRIX		MGetAxis1( VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// �w��̂R�����[�J���̃x�N�g������{����̃x�N�g���ɕϊ�����s��𓾂�( x' = XAxis.x * x + YAixs.x * y + ZAxis.z * z + Pos.x   y' = XAxis.y * x + YAixs.y * y + ZAxis.y * z + Pos.y      z' = XAxis.z * x + YAixs.z * y + ZAxis.z * z + Pos.z )
extern	MATRIX		MGetAxis2( VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// ��{����̃x�N�g�����w��̂R����ɓ��e�����x�N�g���ɕϊ�����s��𓾂�( x' = XAxis.x * ( x - Pos.x ) + XAxis.y * ( x - Pos.x ) + XAxis.z * ( x - Pos.x )    y' = YAxis.x * ( x - Pos.x ) + YAxis.y * ( x - Pos.x ) + YAxis.z * ( x - Pos.x )    z' = ZAxis.x * ( x - Pos.x ) + ZAxis.y * ( x - Pos.x ) + ZAxis.z * ( x - Pos.x ) )
extern	MATRIX		MTranspose( MATRIX InM ) ;												// �]�u�s��𓾂�
extern	MATRIX		MInverse( MATRIX InM ) ;												// �t�s��𓾂�
extern  VECTOR		MGetSize( MATRIX InM ) ;												// �g��s��̂w���A�x���A�y���̊g�嗦�𓾂�

// �x�N�g���l�̐���
__inline VECTOR VGet( float x, float y, float z )
{
	VECTOR Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	return Result ;
}

// �x�N�g���̉��Z
__inline VECTOR		VAdd( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	return Result ;
}

// �x�N�g���̌��Z
__inline VECTOR		VSub( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	return Result ;
}

// �x�N�g���̓���
__inline float		VDot( const VECTOR &In1, const VECTOR &In2 )
{
	return In1.x * In2.x + In1.y * In2.y + In1.z * In2.z ;
}

// �x�N�g���̊O��
__inline VECTOR		VCross( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.y * In2.z - In1.z * In2.y ;
	Result.y = In1.z * In2.x - In1.x * In2.z ;
	Result.z = In1.x * In2.y - In1.y * In2.x ;
	return Result ;
}

// �x�N�g���̃X�P�[�����O
__inline VECTOR		VScale( const VECTOR &In, float Scale )
{
	VECTOR Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	return Result ;
}

// �x�N�g���̐��K��
extern VECTOR		VNorm( VECTOR In ) ;

// �x�N�g���̃T�C�Y
extern float		VSize( VECTOR In ) ;

// �x�N�g���̃T�C�Y�̂Q��
__inline float		VSquareSize( const VECTOR &In )
{
	return In.x * In.x + In.y * In.y + In.z * In.z ;
}

// �s����g�������W�ϊ�
__inline VECTOR		VTransform( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] + InM.m[3][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] + InM.m[3][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] + InM.m[3][2] ;
	return Result ;
}

// �s����g�������W�ϊ�( �X�P�[�����O�{��]�����̂� )
__inline VECTOR		VTransformSR( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] ;
	return Result ;
}

// ��̃x�N�g���������p�̃R�T�C���l�𓾂�
extern	float		VCos( VECTOR In1, VECTOR In2 ) ;

// ��̃x�N�g���������p�̊p�x�𓾂�( �P�ʁF���W�A�� )
extern	float		VRad( VECTOR In1, VECTOR In2 ) ;








// DxBaseImage.cpp �֐��v���g�^�C�v�錾

// ��{�C���[�W�f�[�^�̃��[�h�{�c�h�a�֌W
extern	int			CreateGraphImageOrDIBGraph( const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, int ReverseFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ;												// �o�^����Ă���e��O���t�B�b�N���[�_�֐�����A�a�l�o�f�[�^�������� GraphImage�f�[�^���\�z����
extern	int			CreateGraphImageType2( STREAMDATA *Src, BASEIMAGE *Dest ) ;																																														// �ėp�ǂݍ��ݏ����ɂ��O���t�B�b�N�C���[�W�\�z�֐�( 0:����  -1:���s )

extern	int			CreateBmpInfo( BITMAPINFO *BmpInfo, int Width, int Height, int Pitch, void *SrcGrData, void **DestGrData ) ;																																	// �t���J���[�`����BITMAPINFO�\���̂��쐬����
extern	HBITMAP		CreateDIBGraphVer2( const TCHAR *FileName, void *MemImage, int MemImageSize, int ImageType, int ReverseFlag, COLORDATA *SrcColor ) ;																												// �c�h�a�O���t�B�b�N���쐬����(�o�[�W�����Q)
extern	int			CreateDIBGraphVer2_plus_Alpha( const TCHAR *FileName, void *MemImage, int MemImageSize, void *AlphaImage, int AlphaImageSize, int ImageType, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag, COLORDATA *SrcColor ) ;						// �c�h�a�O���t�B�b�N���쐬����
extern	DWORD		GetGraphImageFullColorCode( BASEIMAGE *GraphImage, int x, int y ) ;																																												// BASEIMAGE �\���̂̉摜��񂩂�w��̍��W�̃t���J���[�R�[�h���擾����
extern	int			CreateGraphImage_plus_Alpha( const TCHAR *FileName, void *RgbImage, int RgbImageSize, int RgbImageType,
													void *AlphaImage, int AlphaImageSize, int AlphaImageType,
													BASEIMAGE *RgbGraphImage, BASEIMAGE *AlphaGraphImage, int ReverseFlag ) ;																																	// �e��O���t�B�b�N�f�[�^����O���t�B�b�N�C���[�W�f�[�^�ƃA���t�@�}�b�v�p�C���[�W�f�[�^���\�z����
extern	int			ReverseGraphImage( BASEIMAGE *GraphImage ) ;																																																	// �w��� GraphImage �����E���]����
extern	int			ConvBitmapToGraphImage( BITMAPINFO *BmpInfo, void *GraphData, BASEIMAGE *GraphImage, int CopyFlag ) ;																																			// �a�l�o �� GraphImage �ɕϊ�����( Ret 0:����I��  1:�R�s�[���s����  -1:�G���[ )
extern	int			ConvGraphImageToBitmap( BASEIMAGE *GraphImage, BITMAPINFO *BmpInfo, void **GraphData, int CopyFlag, int FullColorConv = TRUE ) ;																												// GraphImage �� �a�l�o �ɕϊ�����(�A���t�@�f�[�^�͂����Ă����������)( Ret 0:����I��  1:�R�s�[���s����  -1:�G���[ )
extern	HBITMAP		CreateDIBGraph( const TCHAR *FileName, int ReverseFlag, COLORDATA *SrcColor) ;																																									// �c�h�a�O���t�B�b�N���쐬����
extern	HBITMAP		CreateDIBGraphToMem( BITMAPINFO *BmpInfo, void *GraphData, int ReverseFlag, COLORDATA *SrcColor ) ;																																				// �c�h�a�O���t�B�b�N���������C���[�W����쐬����
extern	int			CreateDIBGraph_plus_Alpha( const TCHAR *FileName, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag = FALSE , COLORDATA *SrcColor = NULL ) ;																									// �t�@�C������c�h�a�O���t�B�b�N�ƃ}�X�N�O���t�B�b�N���쐬����

//extern int		AddUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ���[�U�[��`�̃O���t�B�b�N���[�h�֐���o�^����
//extern int		AddUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ���[�U�[��`�̃O���t�B�b�N���[�h�֐���o�^����
//extern int		AddUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ���[�U�[��`�̃O���t�B�b�N���[�h�֐�Ver3��o�^����
extern	int			AddUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ���[�U�[��`�̃O���t�B�b�N���[�h�֐�Ver4��o�^����
//extern int		SubUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ���[�U�[��`�̃O���t�B�b�N���[�h�֐���o�^���疕������
//extern int		SubUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ���[�U�[��`�̃O���t�B�b�N���[�h�֐���o�^���疕������
//extern int		SubUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ���[�U�[��`�̃O���t�B�b�N���[�h�֐�Ver3��o�^���疕������
extern	int			SubUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ���[�U�[��`�̃O���t�B�b�N���[�h�֐�Ver4��o�^���疕������

extern	int			SetUseFastLoadFlag( int Flag ) ;																							// �����ǂݍ��݃��[�`�����g�����ۂ��̃t���O���Z�b�g����
extern	int			GetGraphDataShavedMode( void ) ;																							// �O���t�B�b�N���F���̉摜�򉻊ɘa�������[�h�̎擾
extern	int			SetGraphDataShavedMode( int ShavedMode ) ;																					// �O���t�B�b�N���F���̉摜�򉻊ɘa�������[�h�̕ύX

// ��{�C���[�W�f�[�^�@�\���J�p�֐�
extern	int			InitSoftImage( void ) ;																										// �\�t�g�E�G�A�ň����C���[�W��S�ĉ������
extern	int			LoadSoftImage( const TCHAR *FileName ) ;																						// �\�t�g�E�G�A�ň����C���[�W�̓ǂݍ���( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			LoadSoftImageToMem( void *FileImage, int FileImageSize ) ;																	// �\�t�g�E�G�A�ň����C���[�W�̃���������̓ǂݍ���( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			MakeSoftImage( int SizeX, int SizeY ) ;																						// �\�t�g�E�G�A�ň����C���[�W�̍쐬( -1:�G���[  -1�ȊO:�C���[�W�n���h�� )
extern	int			MakeARGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̍쐬( RGBA8 �J���[ )
extern	int			MakeXRGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̍쐬( XRGB8 �J���[ )
extern	int			MakeARGB4ColorSoftImage( int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̍쐬( ARGB4 �J���[ )
extern	int			MakeRGB8ColorSoftImage( int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̍쐬( RGB8 �J���[ )
extern	int			MakePAL8ColorSoftImage( int SizeX, int SizeY ) ;																			// �\�t�g�E�G�A�ň����C���[�W�̍쐬( �p���b�g�Q�T�U�F �J���[ )

extern	int			DeleteSoftImage( int SIHandle ) ;																							// �\�t�g�E�G�A�ň����C���[�W�̉��

extern	int			GetSoftImageSize( int SIHandle, int *Width, int *Height ) ;																	// �\�t�g�E�G�A�ň����C���[�W�̃T�C�Y���擾����
extern	int			CheckPaletteSoftImage( int SIHandle ) ;																						// �\�t�g�E�G�A�ň����C���[�W���p���b�g�摜���ǂ������擾����( TRUE:�p���b�g�摜  FALSE:�p���b�g�摜����Ȃ� )
extern	int			CheckAlphaSoftImage( int SIHandle ) ;																						// �\�t�g�E�G�A�ň����C���[�W�̃t�H�[�}�b�g�Ƀ��v�f�����邩�ǂ������擾����( TRUE:����  FALSE:�Ȃ� )

extern	int			GetDrawScreenSoftImage( int x1, int y1, int x2, int y2, int SIHandle ) ;													// �`��Ώۂ̉�ʂ���w��̈�̃O���t�B�b�N���\�t�g�E�G�A�ň����C���[�W�ɓ]������
extern	int			UpdateLayerdWindowForSoftImage( int SIHandle ) ;																			// �\�t�g�E�G�A�ň����C���[�W���g�p���� UpdateLayerdWindow ���s��( �C���[�W�̓E�C���h�E�̃N���C�A���g�̈�Ɠ����T�C�Y�ł���K�v������܂� )
extern	int			FillSoftImage( int SIHandle, int r, int g, int b, int a ) ;																	// �\�t�g�E�G�A�ň����C���[�W���w��F�œh��Ԃ�(�e�F�v�f�͂O�`�Q�T�T)
extern	int			ClearRectSoftImage( int SIHandle, int x, int y, int w, int h ) ;															// �\�t�g�E�G�A�ň����C���[�W�̎w��̗̈���O�N���A����
extern	int			GetPaletteSoftImage( int SIHandle, int PaletteNo, int *r, int *g, int *b, int *a ) ;										// �\�t�g�E�G�A�ň����C���[�W�̃p���b�g���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			SetPaletteSoftImage( int SIHandle, int PaletteNo, int  r, int  g, int  b, int  a ) ;										// �\�t�g�E�G�A�ň����C���[�W�̃p���b�g���Z�b�g����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			DrawPixelPalCodeSoftImage( int SIHandle, int x, int y, int palNo ) ;														// �\�t�g�E�G�A�ň����C���[�W�̎w����W�Ƀh�b�g��`�悷��(�p���b�g�摜�p�A�L���l�͂O�`�Q�T�T)
extern	int			GetPixelPalCodeSoftImage( int SIHandle, int x, int y ) ;																	// �\�t�g�E�G�A�ň����C���[�W�̎w����W�̐F�R�[�h���擾����(�p���b�g�摜�p�A�߂�l�͂O�`�Q�T�T)
extern	void		*GetImageAddressSoftImage( int SIHandle ) ;																					// �\�t�g�E�G�A�ň����C���[�W�̎��C���[�W���i�[����Ă��郁�����̈�̐擪�A�h���X���擾����
extern	int			DrawPixelSoftImage( int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;											// �\�t�g�E�G�A�ň����C���[�W�̎w����W�Ƀh�b�g��`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			GetPixelSoftImage(  int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;											// �\�t�g�E�G�A�ň����C���[�W�̎w����W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			DrawLineSoftImage(  int SIHandle, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;							// �\�t�g�E�G�A�ň����C���[�W�̎w����W�ɐ���`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			BltSoftImage( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle ) ;	// �\�t�g�E�G�A�ň����C���[�W��ʂ̃C���[�W��ɓ]������
extern	int			BltSoftImageWithTransColor( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Tr, int Tg, int Tb, int Ta ) ;	// �\�t�g�E�G�A�ň����C���[�W�𓧉ߐF�����t���œ]������
extern	int			BltSoftImageWithAlphaBlend( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Opacity = 255 ) ;	// �\�t�g�E�G�A�ň����C���[�W���A���t�@�l�̃u�����h���l��������œ]������( Opacity �͓����x : 0( ���S���� ) �` 255( ���S�s���� ) )( �o�͐悪 ARGB8 �`���ȊO�̏ꍇ�̓G���[�ɂȂ�܂� )

extern	int			BltStringSoftImage( 
						int x, int y, const TCHAR *StrData,
						int DestSIHandle, int DestEdgeSIHandle = -1 ,
						int VerticalFlag = FALSE ) ;																							// �\�t�g�E�G�A�ň����C���[�W�ɕ�����C���[�W��]������
extern	int			BltStringSoftImageToHandle( 
						int x, int y, const TCHAR *StrData,
						int DestSIHandle, int DestEdgeSIHandle /* �����K�v�Ȃ��ꍇ�� -1 */ ,
						int FontHandle, int VerticalFlag = FALSE ) ;																			// �\�t�g�E�G�A�ň����C���[�W�ɕ�����C���[�W��]������( �t�H���g�n���h���g�p�� )

extern	int			DrawSoftImage( int x, int y, int SIHandle ) ;																				// �\�t�g�E�G�A�ň����C���[�W����ʂɕ`�悷��

extern	int			SaveSoftImageToBmp( const TCHAR *FilePath, int SIHandle ) ;																	// �\�t�g�E�G�A�ň����C���[�W���a�l�o�摜�t�@�C���Ƃ��ĕۑ�����
#ifndef DX_NON_PNGREAD
extern	int			SaveSoftImageToPng( const TCHAR *FilePath, int SIHandle, int CompressionLevel ) ;											// �\�t�g�E�G�A�ň����C���[�W���o�m�f�摜�t�@�C���Ƃ��ĕۑ����� CompressionLevel = ���k���A�l���傫���قǍ����k�������ׁA�O�͖����k,0�`9
#endif
#ifndef DX_NON_JPEGREAD
extern	int			SaveSoftImageToJpeg( const TCHAR *FilePath, int SIHandle, int Quality, int Sample2x1 ) ;										// �\�t�g�E�G�A�ň����C���[�W���i�o�d�f�摜�t�@�C���Ƃ��ĕۑ����� Quality = �掿�A�l���傫���قǒሳ�k���掿,0�`100 
#endif

// ��{�C���[�W�f�[�^�\���̊֌W
extern	int			CreateBaseImage(  const TCHAR *FileName, void *FileImage, int FileImageSize, int DataType /*=LOADIMAGE_TYPE_FILE*/ , BASEIMAGE *BaseImage, int ReverseFlag ) ;			// �e��O���t�B�b�N�f�[�^�����{�C���[�W�f�[�^���\�z����
extern	int			CreateGraphImage( const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType, BASEIMAGE *GraphImage, int ReverseFlag ) ;							// CreateBaseImage �̋�����
extern	int			CreateBaseImageToFile( const TCHAR *FileName,               BASEIMAGE *BaseImage, int ReverseFlag = FALSE ) ;														// �摜�t�@�C�������{�C���[�W�f�[�^���\�z����
extern	int			CreateBaseImageToMem(  void *FileImage, int FileImageSize, BASEIMAGE *BaseImage, int ReverseFlag = FALSE ) ;														// ��������ɓW�J���ꂽ�摜�t�@�C�������{�C���[�W�f�[�^���\�z����
extern	int			CreateARGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// �`�q�f�a�W�J���[�̋�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateXRGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// �w�q�f�a�W�J���[�̋�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateRGB8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// �q�f�a�W�J���[�̋�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateARGB4ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// �`�q�f�a�S�J���[�̋�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreatePAL8ColorBaseImage( int SizeX, int SizeY, BASEIMAGE *BaseImage ) ;																							// �p���b�g�W�r�b�g�J���[�̋�̊�{�C���[�W�f�[�^���쐬����
extern	int			CreateColorDataBaseImage( int SizeX, int SizeY, COLORDATA *ColorData, BASEIMAGE *BaseImage ) ;																		// �w��̃J���[�t�H�[�}�b�g�̊k�̊�{�C���[�W�f�[�^���쐬����

extern	int			ReleaseBaseImage(  BASEIMAGE *BaseImage ) ;																															// ��{�C���[�W�f�[�^�̌�n�����s��
extern	int			ReleaseGraphImage( BASEIMAGE *GraphImage ) ;																														// ReleaseBaseImage �̋�����

extern	int			ConvertNormalFormatBaseImage( BASEIMAGE *BaseImage ) ;																												// DX_BASEIMAGE_FORMAT_NORMAL �ȊO�̌`���̃C���[�W�f�[�^�� DX_BASEIMAGE_FORMAT_NORMAL �`���̃C���[�W�ɕϊ�����

extern	int			GetDrawScreenBaseImage( int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage ) ;																					// �`��Ώۂ̉�ʂ���w��̈�̃O���t�B�b�N����{�C���[�W�f�[�^�ɓ]������
extern	int			UpdateLayerdWindowForBaseImage( BASEIMAGE *BaseImage ) ;																											// ��{�C���[�W���g�p���� UpdateLayerdWindow ���s��
extern	int			FillBaseImage( BASEIMAGE *BaseImage, int r, int g, int b, int a ) ;																									// ��{�C���[�W�f�[�^���w��̐F�œh��Ԃ�
extern	int			ClearRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int w, int h ) ;																									// ��{�C���[�W�f�[�^�̎w��̗̈���O�N���A����
extern	int			GetPaletteBaseImage( BASEIMAGE *BaseImage, int PaletteNo, int *r, int *g, int *b, int *a ) ;																		// ��{�C���[�W�f�[�^�̃p���b�g���擾����
extern	int			SetPaletteBaseImage( BASEIMAGE *BaseImage, int PaletteNo, int  r, int  g, int  b, int  a ) ;																		// ��{�C���[�W�f�[�^�̃p���b�g���Z�b�g����
extern	int			SetPixelPalCodeBaseImage( BASEIMAGE *BaseImage, int x, int y, int palNo ) ;																							// ��{�C���[�W�f�[�^�̎w��̍��W�̐F�R�[�h��ύX����(�p���b�g�摜�p)
extern	int			GetPixelPalCodeBaseImage( BASEIMAGE *BaseImage, int x, int y ) ;																									// ��{�C���[�W�f�[�^�̎w��̍��W�̐F�R�[�h���擾����(�p���b�g�摜�p)
extern	int			SetPixelBaseImage( BASEIMAGE *BaseImage, int x, int y, int  r, int  g, int  b, int  a ) ;																			// ��{�C���[�W�f�[�^�̎w��̍��W�̐F��ύX����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			GetPixelBaseImage( BASEIMAGE *BaseImage, int x, int y, int *r, int *g, int *b, int *a ) ;																			// ��{�C���[�W�f�[�^�̎w��̍��W�̐F���擾����(�e�F�v�f�͂O�`�Q�T�T)
extern	int			DrawLineBaseImage( BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;																// ��{�C���[�W�f�[�^�̎w��̍��W�ɐ���`�悷��(�e�F�v�f�͂O�`�Q�T�T)
extern	int			BltBaseImage( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;							// ��{�C���[�W�f�[�^��]������
extern	int			BltBaseImage( int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;																			// ��{�C���[�W�f�[�^��]������
extern	int			BltBaseImageWithTransColor( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Tr, int Tg, int Tb, int Ta ) ;	// ��{�C���[�W�f�[�^�𓧉ߐF�����t���œ]������
extern	int			BltBaseImageWithAlphaBlend( int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Opacity = 255 ) ;	// ��{�C���[�W�f�[�^���A���t�@�l�̃u�����h���l��������œ]������( Opacity �͓����x : 0( ���S���� ) �` 255( ���S�s���� ) )( �o�͐悪 ARGB8 �`���ȊO�̏ꍇ�̓G���[�ɂȂ�܂� )
extern	int			ReverseBaseImageH( BASEIMAGE *BaseImage ) ;																															// ��{�C���[�W�f�[�^�̍��E�𔽓]����
extern	int			ReverseBaseImageV( BASEIMAGE *BaseImage ) ;																															// ��{�C���[�W�f�[�^�̏㉺�𔽓]����
extern	int			ReverseBaseImage( BASEIMAGE *BaseImage ) ;																															// ��{�C���[�W�f�[�^�̏㉺���E�𔽓]����

extern	int			SaveBaseImageToBmp( const TCHAR *FilePath, BASEIMAGE *BaseImage ) ;																										// ��{�摜�f�[�^���a�l�o�摜�Ƃ��ĕۑ�����
#ifndef DX_NON_PNGREAD
extern	int			SaveBaseImageToPng( const TCHAR *FilePath, BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// ��{�摜�f�[�^���o�m�f�摜�Ƃ��ĕۑ�����
#endif
#ifndef DX_NON_JPEGREAD
extern	int			SaveBaseImageToJpeg( const TCHAR *FilePath, BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																			// ��{�摜�f�[�^���i�o�d�f�摜�Ƃ��ĕۑ�����
#endif

// �J���[�}�b�`���O���Ȃ���O���t�B�b�N�f�[�^�ԓ]�����s�� Ver2
extern int			GraphColorMatchBltVer2( void *DestGraphData, int DestPitch, COLORDATA *DestColorData,
											void *SrcGraphData, int SrcPitch, COLORDATA *SrcColorData,
											void *AlphaMask, int AlphaPitch, COLORDATA *AlphaColorData,
											POINT DestPoint, RECT *SrcRect, int ReverseFlag,
											int TransColorAlphaTestFlag, unsigned int TransColor,
											int ImageShavedMode, int AlphaOnlyFlag = FALSE ,
											int RedIsAlphaFlag = FALSE , int TransColorNoMoveFlag = FALSE ,
											int Pal8ColorMatch = FALSE ) ;


// �F���擾�֌W
extern	COLOR_F		GetColorF( float Red, float Green, float Blue, float Alpha ) ;										// �s�������_�^�̃J���[�l���쐬����
extern	COLOR_U8	GetColorU8( int Red, int Green, int Blue, int Alpha ) ;												// �����Ȃ������W�r�b�g�̃J���[�l���쐬����
extern	DWORD		GetColor( int Red, int Green, int Blue ) ;															// �R���F�l���猻�݂̉�ʃ��[�h�ɑΉ������F�f�[�^�l�𓾂�
extern	int			GetColor2( int Color, int *Red, int *Green, int *Blue ) ;											// ��ʃ��[�h�ɑΉ������F�f�[�^�l����X�̂R���F�f�[�^�𔲂��o��
extern	int			GetColor3( COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255 ) ;					// �R���F�l����w��̃s�N�Z���t�H�[�}�b�g�ɑΉ������F�f�[�^�l�𓾂�
extern	int			GetColor4( COLORDATA *DestColorData, COLORDATA* SrcColorData, int SrcColor ) ;						// �Q�̃J���[�t�H�[�}�b�g�Ԃ̃f�[�^�ϊ����s�������𓾂� 
extern	int			GetColor5( COLORDATA *ColorData, int Color, int *Red, int *Green, int *Blue, int *Alpha = NULL ) ;	// �w��J���[�t�H�[�}�b�g�ɑΉ������F�f�[�^�l����X�̂R���F�f�[�^�𔲂��o��
extern	int			CreatePaletteColorData( COLORDATA *ColorDataBuf ) ;													// �p���b�g�J���[�̃J���[�����\�z����
extern	int			CreateXRGB8ColorData( COLORDATA *ColorDataBuf ) ;													// �w�q�f�a�W�J���[�̃J���[�����\�z����
extern	int			CreateARGB8ColorData( COLORDATA *ColorDataBuf ) ;													// �`�q�f�a�W�J���[�̃J���[�����\�z����
extern	int			CreateARGB4ColorData( COLORDATA *ColorDataBuf ) ;													// �`�q�f�a�S�J���[�̃J���[�����\�z����
extern	int			CreateFullColorData( COLORDATA *ColorDataBuf ) ;													// �t���J���[�c�h�a�̃J���[�����\�z����
extern	int			CreateGrayColorData( COLORDATA *ColorDataBuf ) ;													// �O���[�X�P�[���̃J���[�����\�z����
extern	int			CreatePal8ColorData( COLORDATA *ColorDataBuf ) ;													// �p���b�g�Q�T�U�F�̃J���[�����\�z����
extern	int			CreateColorData( COLORDATA *ColorDataBuf, int ColorBitDepth,
									 DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;				// �J���[�f�[�^���쐬����
extern	void		SetColorDataNoneMask( COLORDATA *ColorData ) ;														// NoneMask �ȊO�̗v�f�𖄂߂� COLORDATA �\���̂̏������� NoneMask ���Z�b�g����
extern	int			CmpColorData( COLORDATA *ColorData1, COLORDATA *ColorData2 ) ;										// ��̃J���[�f�[�^�����������ǂ������ׂ�( TRUE:������  FALSE:�������Ȃ� )

#endif // DX_NOTUSE_DRAWFUNCTION












// DxSound.cpp�֐��v���g�^�C�v�錾

// �T�E���h�f�[�^�Ǘ��n�֐�
extern	int			InitSoundMem( int LogOutFlag = FALSE ) ;																// �������ɓǂ݂���WAVE�f�[�^���폜���A����������

extern	int			AddSoundData( int Handle = -1 ) ;																		// �V�����T�E���h�f�[�^�̈���m�ۂ���
extern	int			AddStreamSoundMem( STREAMDATA *Stream, int LoopNum,  int SoundHandle, int StreamDataType, int *CanStreamCloseFlag, int UnionHandle = -1 ) ;	// �X�g���[�����T�E���h�f�[�^�ɃT�E���h�f�[�^��ǉ�����
extern	int			AddStreamSoundMemToMem( void *FileImageBuffer, int ImageSize, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;	// �X�g���[�����T�E���h�f�[�^�ɃT�E���h�f�[�^��ǉ�����
extern	int			AddStreamSoundMemToFile( const TCHAR *WaveFile, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;	// �X�g���[�����T�E���h�f�[�^�ɃT�E���h�f�[�^��ǉ�����
extern	int			SetupStreamSoundMem( int SoundHandle ) ;																// �X�g���[�����T�E���h�f�[�^�̍Đ��������s��
extern	int			PlayStreamSoundMem( int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP , int TopPositionFlag = TRUE ) ;	// �X�g���[�����T�E���h�f�[�^�̍Đ��J�n
extern	int			CheckStreamSoundMem( int SoundHandle ) ;																// �X�g���[�����T�E���h�f�[�^�̍Đ���Ԃ𓾂�
extern	int			StopStreamSoundMem( int SoundHandle ) ;																	// �X�g���[�����T�E���h�f�[�^�̍Đ��I��
extern	int			SetStreamSoundCurrentPosition( int Byte, int SoundHandle ) ;											// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŕύX����(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetStreamSoundCurrentPosition( int SoundHandle ) ;														// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŎ擾����
extern	int			SetStreamSoundCurrentTime( int Time, int SoundHandle ) ;												// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŐݒ肷��(���k�`���̏ꍇ�͐������ݒ肳��Ȃ��ꍇ������)
extern	int			GetStreamSoundCurrentTime( int SoundHandle ) ;															// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŎ擾����(���k�`���̏ꍇ�͐������l���Ԃ��Ă��Ȃ��ꍇ������)
extern	int			ProcessStreamSoundMem( int SoundHandle ) ;																// �X�g���[���T�E���h�̍Đ������֐�
extern	int			ProcessStreamSoundMemAll( void ) ;																		// �L���ȃX�g���[���T�E���h�̂��ׂčĐ������֐��ɂ�����


extern	int			LoadSoundMem2( const TCHAR *WaveName1, const TCHAR *WaveName2 ) ;											// �O�t���ƃ��[�v���ɕ����ꂽ�T�E���h�f�[�^�̍쐬
extern	int			LoadBGM( const TCHAR *WaveName ) ;																		// ��ɂa�f�l��ǂݍ��ނ̂ɓK�����֐�

extern	int			LoadSoundMemBase( const TCHAR *WaveName, int BufferNum, int UnionHandle = -1 ) ;							// �T�E���h�f�[�^��ǉ�����
extern	int			LoadSoundMem( const TCHAR *WaveName, int BufferNum = 3 , int UnionHandle = -1 ) ;						// �T�E���h�f�[�^��ǉ�����
extern	int			LoadSoundMemToBufNumSitei( const TCHAR *WaveName, int BufferNum ) ;										// �����Đ����w��^�T�E���h�ǉ��֐�
extern	int			LoadSoundMemByResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int BufferNum = 1 ) ;		// �T�E���h�����\�[�X����ǂݍ���
extern	int			DuplicateSoundMem( int SrcSoundHandle, int BufferNum = 3 ) ;											// �����T�E���h�f�[�^���g�p����T�E���h�n���h�����쐬����( DX_SOUNDDATATYPE_MEMNOPRESS �^�C�v�̂� )

extern	int			LoadSoundMemByMemImageBase( void *FileImageBuffer, int ImageSize, int BufferNum, int UnionHandle = -1 ) ; // ��������ɓW�J���ꂽ�t�@�C���C���[�W����n���h�����쐬����(�x�[�X�֐�)
extern	int			LoadSoundMemByMemImage( void *FileImageBuffer, int ImageSize, int UnionHandle = -1 ) ;					// ��������ɓW�J���ꂽ�t�@�C���C���[�W����n���h�����쐬����(�o�b�t�@���w�肠��) 
extern	int			LoadSoundMemByMemImage2( void *UData, int UDataSize, WAVEFORMATEX *UFormat, int UHeaderSize ) ;			// ��������ɓW�J���ꂽ�t�@�C���C���[�W����n���h�����쐬����2
extern	int			LoadSoundMemByMemImageToBufNumSitei( void *FileImageBuffer, int ImageSize, int BufferNum ) ;			// ��������ɓW�J���ꂽ�t�@�C���C���[�W����n���h�����쐬����
extern	int			LoadSoundMem2ByMemImage( void *FileImageBuffer1, int ImageSize1, void *FileImageBuffer2, int ImageSize2 ) ;	// ��������ɓW�J���ꂽ�t�@�C���C���[�W����O�t���ƃ��[�v���ɕ����ꂽ�n���h�����쐬����
extern	int			LoadSoundMemFromSoftSound( int SoftSoundHandle, int BufferNum = 3 ) ;									// �\�t�g�E�G�A�Ŕg�`�𐧌䂷��T�E���h�f�[�^����T�E���h�n���h�����쐬����

extern	int			DeleteSoundMem( int SoundHandle, int LogOutFlag = FALSE ) ;												// �������ɓǂݍ���WAVE�f�[�^���폜����

extern	int			PlaySoundMem( int SoundHandle, int PlayType, int TopPositionFlag = TRUE ) ;								// �������ɓǂ݂���WAVE�f�[�^���Đ�����
extern	int			StopSoundMem( int SoundHandle ) ;																		// �������ɓǂݍ���WAVE�f�[�^�̍Đ����~�߂�
extern	int			CheckSoundMem( int SoundHandle ) ;																		// �������ɓǂ݂���WAVE�f�[�^���Đ��������ׂ�
extern	int			SetPanSoundMem( int PanPal, int SoundHandle ) ;															// �������ɓǂ݂���WAVE�f�[�^�̍Đ��Ƀp����ݒ肷��
extern	int			SetVolumeSoundMem( int VolumePal, int SoundHandle ) ;													// �������ɓǂ݂���WAVE�f�[�^�̍Đ��Ƀ{�����[����ݒ肷��( 100����1�f�V�x���P�� )
extern	int			ChangeVolumeSoundMem( int VolumePal, int SoundHandle ) ;												// �������ɓǂ݂���WAVE�f�[�^�̍Đ��Ƀ{�����[����ݒ肷��( �p�[�Z���g�w�� )
extern	int			GetVolumeSoundMem( int SoundHandle ) ;																	// �������ɓǂ݂���WAVE�f�[�^�̍Đ��̃{�����[�����擾����
extern	int			SetFrequencySoundMem( int FrequencyPal, int SoundHandle ) ;												// �������ɓǂݍ���WAVE�f�[�^�̍Đ����g����ݒ肷��
extern	int			GetFrequencySoundMem( int SoundHandle ) ;																// �������ɓǂݍ���WAVE�f�[�^�̍Đ����g�����擾����

extern	int			SetNextPlayPanSoundMem( int PanPal, int SoundHandle ) ;													// �������ɓǂ݂���WAVE�f�[�^�̎��̍Đ��ɂ̂ݎg�p����p����ݒ肷��
extern	int			SetNextPlayVolumeSoundMem( int VolumePal, int SoundHandle ) ;											// �������ɓǂ݂���WAVE�f�[�^�̎��̍Đ��ɂ̂ݎg�p����{�����[����ݒ肷��( 100����1�f�V�x���P�� )
extern	int			ChangeNextPlayVolumeSoundMem( int VolumePal, int SoundHandle ) ;										// �������ɓǂ݂���WAVE�f�[�^�̎��̍Đ��ɂ̂ݎg�p����{�����[����ݒ肷��( �p�[�Z���g�w�� )
extern	int			SetNextPlayFrequencySoundMem( int FrequencyPal, int SoundHandle ) ;										// �������ɓǂݍ���WAVE�f�[�^�̎��̍Đ��ɂ̂ݎg�p����Đ����g����ݒ肷��

extern	int			SetCurrentPositionSoundMem( int SamplePosition, int SoundHandle ) ;										// �T�E���h�n���h���̍Đ��ʒu���T���v���P�ʂŕύX����(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetCurrentPositionSoundMem( int SoundHandle ) ;															// �T�E���h�n���h���̍Đ��ʒu���T���v���P�ʂŎ擾����
extern	int			SetSoundCurrentPosition( int Byte, int SoundHandle ) ;													// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŕύX����(�Đ����~�܂��Ă��鎞�̂ݗL��)
extern	int			GetSoundCurrentPosition( int SoundHandle ) ;															// �T�E���h�n���h���̍Đ��ʒu���o�C�g�P�ʂŎ擾����
extern	int			SetSoundCurrentTime( int Time, int SoundHandle ) ;														// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŐݒ肷��(���k�`���̏ꍇ�͐������ݒ肳��Ȃ��ꍇ������)
extern	int			GetSoundCurrentTime( int SoundHandle ) ;																// �T�E���h�n���h���̍Đ��ʒu���~���b�P�ʂŎ擾����(���k�`���̏ꍇ�͐������l���Ԃ��Ă��Ȃ��ꍇ������)
extern	int			GetSoundTotalSample( int SoundHandle ) ;																// �T�E���h�n���h���̉��̑����Ԃ��擾����(�P�ʂ̓T���v��)
extern	int			GetSoundTotalTime( int SoundHandle ) ;																	// �T�E���h�n���h���̉��̑����Ԃ��擾����(�P�ʂ̓~���b)

extern	int			SetLoopPosSoundMem( int LoopTime, int SoundHandle ) ;													// �T�E���h�n���h���Ƀ��[�v�ʒu��ݒ肷��
extern	int			SetLoopTimePosSoundMem( int LoopTime, int SoundHandle ) ;												// �T�E���h�n���h���Ƀ��[�v�ʒu��ݒ肷��
extern	int			SetLoopSamplePosSoundMem( int LoopSamplePosition, int SoundHandle ) ;									// �T�E���h�n���h���Ƀ��[�v�ʒu��ݒ肷��

extern	int			SetLoopStartTimePosSoundMem( int LoopStartTime, int SoundHandle ) ;										// �T�E���h�n���h���Ƀ��[�v�J�n�ʒu��ݒ肷��
extern	int			SetLoopStartSamplePosSoundMem( int LoopStartSamplePosition, int SoundHandle ) ;							// �T�E���h�n���h���Ƀ��[�v�J�n�ʒu��ݒ肷��

// �ݒ�֌W�֐�
extern	int			SetCreateSoundDataType( int SoundDataType ) ;															// �쐬����T�E���h�̃f�[�^�`����ݒ肷��( DX_SOUNDDATATYPE_MEMNOPRESS �� )
extern	int			GetCreateSoundDataType( void ) ;																		// �쐬����T�E���h�̃f�[�^�`�����擾����( DX_SOUNDDATATYPE_MEMNOPRESS �� )
extern	int			SetDisableReadSoundFunctionMask( int Mask ) ;															// �g�p���Ȃ��T�E���h�f�[�^�ǂݍ��ݏ����̃}�X�N��ݒ肷��( DX_READSOUNDFUNCTION_PCM �� )
extern	int			GetDisableReadSoundFunctionMask( void ) ;																// �g�p���Ȃ��T�E���h�f�[�^�ǂݍ��ݏ����̃}�X�N���擾����( DX_READSOUNDFUNCTION_PCM �� )
extern	int			SetEnableSoundCaptureFlag( int Flag ) ;																	// �T�E���h�L���v�`����O��Ƃ�����������邩�ǂ�����ݒ肷��
extern	int			SetUseSoftwareMixingSoundFlag( int Flag ) ;																// �T�E���h�̏������\�t�g�E�G�A�ōs�����ǂ�����ݒ肷��( TRUE:�\�t�g�E�G�A  FALSE:�n�[�h�E�G�A( �f�t�H���g ) )

// ���擾�n�֐�
extern	void*		GetDSoundObj( void ) ;	/* �߂�l�� IDirectSound * �ɃL���X�g���ĉ����� */								// �c�w���C�u�������g�p���Ă��� DirectSound �I�u�W�F�N�g���擾����

#ifndef DX_NON_BEEP
// BEEP���Đ��p����
extern	int			SetBeepFrequency( int Freq ) ;																			// �r�[�v�����g���ݒ�֐�
extern	int			PlayBeep( void ) ;																						// �r�[�v�����Đ�����
extern	int			StopBeep( void ) ;																						// �r�[�v�����~�߂�
#endif

// ���b�p�[�֐�
extern	int			PlaySoundFile( const TCHAR *FileName, int PlayType ) ;													// WAVE�t�@�C�����Đ�����
extern	int			PlaySound( const TCHAR *FileName, int PlayType ) ;														// PlaySoundFile �̋�����
extern	int			CheckSoundFile( void ) ;																				// WAVE�t�@�C���̍Đ��������ׂ�
extern	int			CheckSound( void ) ;																					// CheckSoundFile �̋�����
extern	int			StopSoundFile( void ) ;																					// WAVE�t�@�C���̍Đ����~�߂�
extern	int			StopSound( void ) ;																						// StopSoundFile �̋�����
extern	int			SetVolumeSoundFile( int VolumePal ) ;																	// WAVE�t�@�C���̉��ʂ��Z�b�g����
extern	int			SetVolumeSound( int VolumePal ) ;																		// SetVolumeSound �̋�����

// �\�t�g�E�G�A����T�E���h�n�֐�
extern	int			InitSoftSound( void ) ;																					// �\�t�g�E�G�A�ň����g�`�f�[�^�����ׂĉ������
extern	int			LoadSoftSound( const TCHAR *FileName ) ;																	// �\�t�g�E�G�A�ň����g�`�f�[�^���t�@�C������쐬����
extern	int			LoadSoftSoundFromMemImage( const void *FileImageBuffer, int FileImageSize ) ;							// �\�t�g�E�G�A�ň����g�`�f�[�^����������ɓW�J���ꂽ�t�@�C���C���[�W����쐬����
extern	int			MakeSoftSound( int UseFormat_SoftSoundHandle, int SampleNum ) ;											// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �t�H�[�}�b�g�͈����̃\�t�g�E�G�A�T�E���h�n���h���Ɠ������̂ɂ��� )
extern	int			MakeSoftSound2Ch16Bit44KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound2Ch16Bit22KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound2Ch8Bit44KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:2 �ʎq���r�b�g��:8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound2Ch8Bit22KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:2 �ʎq���r�b�g��:8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound1Ch16Bit44KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound1Ch16Bit22KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSound1Ch8Bit44KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:1 �ʎq���r�b�g��:8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSound1Ch8Bit22KHz( int SampleNum ) ;															// �\�t�g�E�G�A�ň�����̔g�`�f�[�^���쐬����( �`�����l����:1 �ʎq���r�b�g��:8bit �T���v�����O���g��:22KHz )
extern	int			DeleteSoftSound( int SoftSoundHandle ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^���������
extern	int			SaveSoftSound( int SoftSoundHandle, const TCHAR *FileName ) ;											// �\�t�g�E�G�A�ň����g�`�f�[�^�𖳈��kWav�`���ŕۑ�����
extern	int			GetSoftSoundSampleNum( int SoftSoundHandle ) ;															// �\�t�g�E�G�A�ň����g�`�f�[�^�̃T���v�������擾����
extern	int			GetSoftSoundFormat( int SoftSoundHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;		// �\�t�g�E�G�A�ň����g�`�f�[�^�̃t�H�[�}�b�g���擾����
extern	int			ReadSoftSoundData( int SoftSoundHandle, int SamplePosition, int *Channel1, int *Channel2 ) ;			// �\�t�g�E�G�A�ň����g�`�f�[�^�̃T���v����ǂݎ��
extern	int			WriteSoftSoundData( int SoftSoundHandle, int SamplePosition, int Channel1, int Channel2 ) ;				// �\�t�g�E�G�A�ň����g�`�f�[�^�̃T���v������������
extern	void		*GetSoftSoundDataImage( int SoftSoundHandle ) ;															// �\�t�g�E�G�A�ň����g�`�f�[�^�̔g�`�C���[�W���i�[����Ă��郁�����A�h���X���擾����

extern	int			InitSoftSoundPlayer( void ) ;																			// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�����ׂĉ������
extern	int			MakeSoftSoundPlayer( int UseFormat_SoftSoundHandle ) ;													// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �t�H�[�}�b�g�͈����̃\�t�g�E�G�A�T�E���h�n���h���Ɠ������̂ɂ��� )
extern	int			MakeSoftSoundPlayer2Ch16Bit44KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer2Ch16Bit22KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:2 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit44KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:2 �ʎq���r�b�g��:8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit22KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:2 �ʎq���r�b�g��:8bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit44KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit22KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:1 �ʎq���r�b�g��:16bit �T���v�����O���g��:22KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit44KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:1 �ʎq���r�b�g��:8bit �T���v�����O���g��:44KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit22KHz( void ) ;																// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���쐬����( �`�����l����:1 �ʎq���r�b�g��:8bit �T���v�����O���g��:22KHz )
extern	int			DeleteSoftSoundPlayer( int SSoundPlayerHandle ) ;														// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[���폜����
extern	int			AddDataSoftSoundPlayer( int SSoundPlayerHandle, int SoftSoundHandle, int AddSamplePosition, int AddSampleNum ) ;	// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�ɔg�`�f�[�^��ǉ�����( �t�H�[�}�b�g�������ł͂Ȃ��ꍇ�̓G���[ )
extern	int			AddDirectDataSoftSoundPlayer( int SSoundPlayerHandle, void *SoundData, int AddSampleNum ) ;							// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�Ƀv���C���[���Ή������t�H�[�}�b�g�̐��g�`�f�[�^��ǉ�����
extern	int			AddOneDataSoftSoundPlayer( int SSoundPlayerHandle, int Channel1, int Channel2 ) ;									// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�ɔg�`�f�[�^����ǉ�����
extern	int			GetSoftSoundPlayerFormat( int SSoundPlayerHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;		// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�������f�[�^�t�H�[�}�b�g���擾����
extern	int			StartSoftSoundPlayer( int SSoundPlayerHandle ) ;														// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�̍Đ��������J�n����
extern	int			CheckStartSoftSoundPlayer( int SSoundPlayerHandle ) ;													// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�̍Đ��������J�n����Ă��邩�擾����( TRUE:�J�n���Ă���  FALSE:��~���Ă��� )
extern	int			StopSoftSoundPlayer( int SSoundPlayerHandle ) ;															// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�̍Đ��������~����
extern	int			ResetSoftSoundPlayer( int SSoundPlayerHandle ) ;														// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�̏�Ԃ�������Ԃɖ߂�( �ǉ����ꂽ�g�`�f�[�^�͍폜����A�Đ���Ԃ������ꍇ�͒�~���� )
extern	int			GetStockDataLengthSoftSoundPlayer( int SSoundPlayerHandle ) ;											// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�ɒǉ������g�`�f�[�^�ł܂��Đ��p�T�E���h�o�b�t�@�ɓ]������Ă��Ȃ��g�`�f�[�^�̃T���v�������擾����
extern	int			CheckSoftSoundPlayerNoneData( int SSoundPlayerHandle ) ;												// �\�t�g�E�G�A�ň����g�`�f�[�^�̃v���C���[�ɍĐ��p�T�E���h�o�b�t�@�ɓ]�����Ă��Ȃ��g�`�f�[�^�������A�Đ��p�T�E���h�o�b�t�@�ɂ������f�[�^�ȊO�������ǂ������擾����( TRUE:�����f�[�^�ȊO����  FALSE:�L���f�[�^������ )




// �l�h�c�h����֐�
extern	int			AddMusicData( void ) ;																					// �V�����l�h�c�h�n���h�����擾����
extern	int			DeleteMusicMem( int MusicHandle ) ;																		// �l�h�c�h�n���h�����폜����
extern	int			LoadMusicMem( const TCHAR *FileName ) ;																	// �l�h�c�h�t�@�C����ǂݍ���
extern	int			LoadMusicMemByMemImage( void *FileImageBuffer, int FileImageSize ) ;									// ��������ɓW�J���ꂽ�l�h�c�h�t�@�C����ǂݍ���
extern	int			LoadMusicMemByResource( const TCHAR *ResourceName, const TCHAR *ResourceType ) ;							// ���\�[�X��̂l�h�c�h�t�@�C����ǂݍ���
extern	int			PlayMusicMem( int MusicHandle, int PlayType ) ;															// �ǂݍ��񂾂l�h�c�h�f�[�^�̉��t���J�n����
extern	int			StopMusicMem( int MusicHandle ) ;																		// �l�h�c�h�f�[�^�̉��t���~����
extern	int			CheckMusicMem( int MusicHandle ) ;																		// �l�h�c�h�f�[�^�����t�����ǂ������擾����( TRUE:���t��  FALSE:��~�� )
extern	int			GetMusicMemPosition( int MusicHandle ) ;																// �l�h�c�h�f�[�^�̌��݂̍Đ��ʒu���擾����
extern	int			InitMusicMem( void ) ;																					// �l�h�c�h�f�[�^�n���h�������ׂč폜����
extern	int			ProcessMusicMem( void ) ;																				// �l�h�c�h�f�[�^�̎����I����

extern	int			PlayMusic( const TCHAR *FileName, int PlayType ) ;														// �l�h�c�h�t�@�C�������t����
extern	int			PlayMusicByMemImage( void *FileImageBuffer, int FileImageSize, int PlayType ) ;							// ��������ɓW�J����Ă���l�h�c�h�t�@�C�������t����
extern	int			PlayMusicByResource( const TCHAR *ResourceName, const TCHAR *ResourceType, int PlayType ) ;				// ���\�[�X����l�h�c�h�t�@�C����ǂݍ���ŉ��t����
extern	int			SetVolumeMusic( int Volume ) ;																			// �l�h�c�h�̍Đ����ʂ��Z�b�g����
extern	int			StopMusic( void ) ;																						// �l�h�c�h�t�@�C���̉��t��~
extern	int			CheckMusic( void ) ;																					// �l�h�c�h�t�@�C�������t�����ۂ������擾����
extern	int			GetMusicPosition( void ) ;																				// �l�h�c�h�̌��݂̍Đ��ʒu���擾����

extern	int			SelectMidiMode( int Mode ) ;																			// �l�h�c�h�̍Đ��`�����Z�b�g����











// DxArchive_.cpp �֐� �v���g�^�C�v�錾
extern	int			DXArchivePreLoad( const TCHAR *FilePath , int ASync = FALSE ) ;						// �w��̂c�w�`�t�@�C�����ۂ��ƃ������ɓǂݍ���( �߂�l: -1=�G���[  0=���� )
extern	int			DXArchiveCheckIdle( const TCHAR *FilePath ) ;										// �w��̂c�w�`�t�@�C���̎��O�ǂݍ��݂������������ǂ������擾����( �߂�l�F TRUE=�������� FALSE=�܂� )
extern	int			DXArchiveRelease( const TCHAR *FilePath ) ;											// �w��̂c�w�`�t�@�C��������������������
extern	int			DXArchiveCheckFile( const TCHAR *FilePath, const TCHAR *TargetFilePath ) ;			// �c�w�`�t�@�C���̒��Ɏw��̃t�@�C�������݂��邩�ǂ����𒲂ׂ�ATargetFilePath �͂c�w�`�t�@�C�����J�����g�t�H���_�Ƃ����ꍇ�̃p�X( �߂�l:  -1=�G���[  0:����  1:���� )





















// DxModel.cpp �֐� �v���g�^�C�v�錾

#ifndef DX_NON_MODEL

// ���f���̓ǂݍ��݁E�����֌W
extern	int			MV1LoadModel( const TCHAR *FileName ) ;														// ���f���̓ǂݍ���( -1:�G���[  0�ȏ�:���f���n���h�� )
extern	int			MV1LoadModelFromMem( void *FileImage, int FileSize, int (* FileReadFunc )( const TCHAR *FilePath, void **FileImageAddr, int *FileSize, void *FileReadFuncData ), int (* FileReleaseFunc )( void *MemoryAddr, void *FileReadFuncData ), void *FileReadFuncData = NULL ) ;	// ��������̃��f���t�@�C���C���[�W�ƓƎ��̓ǂݍ��݃��[�`�����g�p���ă��f����ǂݍ���
extern	int			MV1DuplicateModel( int SrcMHandle ) ;														// �w��̃��f���Ɠ������f����{�f�[�^���g�p���ă��f�����쐬����( -1:�G���[  0�ȏ�:���f���n���h�� )

extern	int			MV1DeleteModel( int MHandle ) ;																// ���f�����폜����

extern	int			MV1SetLoadModelReMakeNormal( int Flag ) ;													// ���f����ǂݍ��ލۂɖ@���̍Čv�Z���s�����ǂ�����ݒ肷��( TRUE:�s��  FALSE:�s��Ȃ� )
extern	int			MV1SetLoadModelReMakeNormalSmoothingAngle( float SmoothingAngle = 1.562069f ) ;				// ���f����ǂݍ��ލۂɍs���@��̍Čv�Z�Ŏg�p����X���[�W���O�p�x��ݒ肷��( �P�ʂ̓��W�A�� )
extern	int			MV1SetLoadModelPositionOptimize( int Flag ) ;												// ���f����ǂݍ��ލۂɍ��W�f�[�^�̍œK�����s�����ǂ�����ݒ肷��( TRUE:�s��  FALSE:�s��Ȃ� )

// ���f���`��֌W
extern	int			MV1DrawModel( int MHandle ) ;																// ���f����`�悷��
extern	int			MV1DrawFrame( int MHandle, int FrameIndex ) ;												// ���f���̎w��̃t���[����`�悷��
extern	int			MV1DrawMesh( int MHandle, int MeshIndex ) ;													// ���f���̎w��̃��b�V����`�悷��
extern	int			MV1DrawModelDebug( int MHandle, int Color, int IsNormalLine, float NormalLineLength, int IsPolyLine, int IsCollisionBox ) ;	// ���f���̃f�o�b�O�`��

// ���f����{����֌W
extern	MATRIX		MV1GetLocalWorldMatrix( int MHandle ) ;														// ���f���̃��[�J�����W���烏�[���h���W�ɕϊ�����s��𓾂�
extern	int			MV1SetPosition( int MHandle, VECTOR Position ) ;											// ���f���̍��W���Z�b�g
extern	VECTOR		MV1GetPosition( int MHandle ) ;																// ���f���̍��W���擾
extern	int			MV1SetScale( int MHandle, VECTOR Scale ) ;													// ���f���̊g��l���Z�b�g
extern	VECTOR		MV1GetScale( int MHandle ) ;																// ���f���̊g��l���擾
extern	int			MV1SetRotationXYZ( int MHandle, VECTOR Rotate ) ;											// ���f���̉�]�l���Z�b�g( X����]��Y����]��Z����]���� )
extern	VECTOR		MV1GetRotationXYZ( int MHandle ) ;															// ���f���̉�]�l���擾( X����]��Y����]��Z����]���� )
extern	int			MV1SetRotationZYAxis( int MHandle, VECTOR ZAxisDirection, VECTOR YAxisDirection, float ZAxisTwistRotate ) ;	// ���f���̂y���Ƃx���̌������Z�b�g����
extern	int			MV1SetRotationMatrix( int MHandle, MATRIX Matrix ) ;										// ���f���̉�]�p�s����Z�b�g����
extern	MATRIX		MV1GetRotationMatrix( int MHandle ) ;														// ���f���̉�]�p�s����擾����
extern	int			MV1SetMatrix( int MHandle, MATRIX Matrix ) ;												// ���f���̕ό`�p�s����Z�b�g����
extern	MATRIX		MV1GetMatrix( int MHandle ) ;																// ���f���̕ό`�p�s����擾����
extern	int			MV1SetVisible( int MHandle, int VisibleFlag ) ;												// ���f���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetVisible( int MHandle ) ;																// ���f���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetDifColorScale( int MHandle, COLOR_F Scale ) ;											// ���f���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetDifColorScale( int MHandle ) ;														// ���f���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetSpcColorScale( int MHandle, COLOR_F Scale ) ;											// ���f���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetSpcColorScale( int MHandle ) ;														// ���f���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetEmiColorScale( int MHandle, COLOR_F Scale ) ;											// ���f���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetEmiColorScale( int MHandle ) ;														// ���f���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetAmbColorScale( int MHandle, COLOR_F Scale ) ;											// ���f���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetAmbColorScale( int MHandle ) ;														// ���f���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1GetSemiTransState( int MHandle ) ;														// ���f���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetOpacityRate( int MHandle, float Rate ) ;												// ���f���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetOpacityRate( int MHandle ) ;															// ���f���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetUseZBuffer( int MHandle, int Flag ) ;													// ���f����`�悷��ۂɂy�o�b�t�@���g�p���邩�ǂ�����ݒ肷��
extern	int			MV1SetWriteZBuffer( int MHandle, int Flag ) ;												// ���f����`�悷��ۂɂy�o�b�t�@�ɏ������݂��s�����ǂ�����ݒ肷��
extern	int			MV1SetZBufferCmpType( int MHandle, int CmpType /* DX_CMP_NEVER �� */ ) ;					// ���f���̕`�掞�̂y�l�̔�r���[�h��ݒ肷��
extern	int			MV1SetZBias( int MHandle, int Bias ) ;														// ���f���̕`�掞�̏������ނy�l�̃o�C�A�X��ݒ肷��
extern	int			MV1SetUseVertDifColor( int MHandle, int UseFlag ) ;											// ���f���̊܂܂�郁�b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetUseVertSpcColor( int MHandle, int UseFlag ) ;											// ���f���Ɋ܂܂�郁�b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetSampleFilterMode( int MHandle, int FilterMode ) ;										// ���f���̃e�N�X�`���̃T���v���t�B���^�[���[�h��ύX����( FilterMode �� DX_DRAWMODE_NEAREST �� )
extern	int			MV1SetMaxAnisotropy( int MHandle, int MaxAnisotropy ) ;										// ���f���ٕ̈����t�B���^�����O�̍ő原����ݒ肷��
extern	int			MV1SetWireFrameDrawFlag( int MHandle, int Flag ) ;											// ���f�������C���[�t���[���ŕ`�悷�邩�ǂ�����ݒ肷��

// �A�j���[�V�����֌W
extern	int			MV1AttachAnim( int MHandle, int AnimIndex, int AnimSrcMHandle = -1 , int NameCheck = TRUE ) ;	// �A�j���[�V�������A�^�b�`����( �߂�l  -1:�G���[  0�ȏ�:�A�^�b�`�C���f�b�N�X )
extern	int			MV1DetachAnim( int MHandle, int AttachIndex ) ;												// �A�j���[�V�������f�^�b�`����
extern	int			MV1SetAttachAnimTime( int MHandle, int AttachIndex, float Time ) ;							// �A�^�b�`���Ă���A�j���[�V�����̍Đ����Ԃ�ݒ肷��
extern	float		MV1GetAttachAnimTime( int MHandle, int AttachIndex ) ;										// �A�^�b�`���Ă���A�j���[�V�����̍Đ����Ԃ��擾����
extern	float		MV1GetAttachAnimTotalTime( int MHandle, int AttachIndex ) ;									// �A�^�b�`���Ă���A�j���[�V�����̑����Ԃ𓾂�
extern	int			MV1SetAttachAnimBlendRate( int MHandle, int AttachIndex, float Rate = 1.0f ) ;				// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��
extern	float		MV1GetAttachAnimBlendRate( int MHandle, int AttachIndex ) ;									// �A�^�b�`���Ă���A�j���[�V�����̃u�����h�����擾����
extern	int			MV1SetAttachAnimBlendRateToFrame( int MHandle, int AttachIndex, int FrameIndex, float Rate, int SetChild = TRUE ) ;	// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��( �t���[���P�� )
extern	float		MV1GetAttachAnimBlendRateToFrame( int MHandle, int AttachIndex, int FrameIndex ) ;			// �A�^�b�`���Ă���A�j���[�V�����̃u�����h����ݒ肷��( �t���[���P�� )
extern	int			MV1GetAttachAnim( int MHandle, int AttachIndex ) ;											// �A�^�b�`���Ă���A�j���[�V�����̃A�j���[�V�����C���f�b�N�X���擾����

extern	int			MV1GetAnimNum( int MHandle ) ;																// �A�j���[�V�����̐����擾����
extern	const TCHAR *MV1GetAnimName( int MHandle, int AnimIndex ) ;												// �w��ԍ��̃A�j���[�V���������擾����( NULL:�G���[ )
extern	int			MV1GetAnimIndex( int MHandle, const TCHAR *AnimName ) ;										// �w�薼�̃A�j���[�V�����ԍ����擾����( -1:�G���[ )
extern	float		MV1GetAnimTotalTime( int MHandle, int AnimIndex ) ;											// �w��ԍ��̃A�j���[�V�����̑����Ԃ𓾂�
extern	int			MV1GetAnimTargetFrameNum( int MHandle, int AnimIndex ) ;									// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̐����擾����
extern	const TCHAR *MV1GetAnimTargetFrameName( int MHandle, int AnimIndex, int AnimFrameIndex ) ;				// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̖��O���擾����
extern	int			MV1GetAnimTargetFrame( int MHandle, int AnimIndex, int AnimFrameIndex ) ;					// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���̔ԍ����擾����
extern	int			MV1GetAnimTargetFrameKeySetNum( int MHandle, int AnimIndex, int AnimFrameIndex ) ;			// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���p�̃A�j���[�V�����L�[�Z�b�g�̐����擾����
extern	int			MV1GetAnimTargetFrameKeySet( int MHandle, int AnimIndex, int AnimFrameIndex, int Index ) ;	// �w��̃A�j���[�V�������^�[�Q�b�g�Ƃ���t���[���p�̃A�j���[�V�����L�[�Z�b�g�L�[�Z�b�g�C���f�b�N�X���擾����

extern	int			MV1GetAnimKeySetNum( int MHandle ) ;														// ���f���Ɋ܂܂��A�j���[�V�����L�[�Z�b�g�̑����𓾂�
extern	int			MV1GetAnimKeySetType( int MHandle, int AnimKeySetIndex ) ;									// �w��̃A�j���[�V�����L�[�Z�b�g�̃^�C�v���擾����( MV1_ANIMKEY_TYPE_QUATERNION �� )
extern	int			MV1GetAnimKeySetDataType( int MHandle, int AnimKeySetIndex ) ;								// �w��̃A�j���[�V�����L�[�Z�b�g�̃f�[�^�^�C�v���擾����( MV1_ANIMKEY_DATATYPE_ROTATE �� )
extern	int			MV1GetAnimKeySetTimeType( int MHandle, int AnimKeySetIndex ) ;								// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̎��ԃf�[�^�^�C�v���擾����( MV1_ANIMKEY_TIME_TYPE_ONE �� )
extern	int			MV1GetAnimKeySetDataNum( int MHandle, int AnimKeySetIndex ) ;								// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̐����擾����
extern	float		MV1GetAnimKeyDataTime( int MHandle, int AnimKeySetIndex, int Index ) ;						// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[�̎��Ԃ��擾����
extern	FLOAT4		MV1GetAnimKeyDataToQuaternion( int MHandle, int AnimKeySetIndex, int Index ) ;				// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_QUATERNION �ł͖��������ꍇ�͎��s����
extern	FLOAT4		MV1GetAnimKeyDataToQuaternionFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;		// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_QUATERNION �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	VECTOR		MV1GetAnimKeyDataToVector( int MHandle, int AnimKeySetIndex, int Index ) ;					// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_VECTOR �ł͖��������ꍇ�͎��s����
extern	VECTOR		MV1GetAnimKeyDataToVectorFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_VECTOR �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	MATRIX		MV1GetAnimKeyDataToMatrix( int MHandle, int AnimKeySetIndex, int Index ) ;					// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_MATRIX4X4C �� MV1_ANIMKEY_TYPE_MATRIX3X3 �ł͖��������ꍇ�͎��s����
extern	MATRIX		MV1GetAnimKeyDataToMatrixFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_MATRIX4X4C �� MV1_ANIMKEY_TYPE_MATRIX3X3 �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	float		MV1GetAnimKeyDataToFlat( int MHandle, int AnimKeySetIndex, int Index ) ;					// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_FLAT �ł͖��������ꍇ�͎��s����
extern	float		MV1GetAnimKeyDataToFlatFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_FLAT �ł͖��������ꍇ�͎��s����( ���Ԏw��� )
extern	float		MV1GetAnimKeyDataToLinear( int MHandle, int AnimKeySetIndex, int Index ) ;					// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_LINEAR �ł͖��������ꍇ�͎��s����
extern	float		MV1GetAnimKeyDataToLinearFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;			// �w��̃A�j���[�V�����L�[�Z�b�g�̃L�[���擾����A�L�[�^�C�v�� MV1_ANIMKEY_TYPE_LINEAR �ł͖��������ꍇ�͎��s����( ���Ԏw��� )

// �}�e���A���֌W
extern	int			MV1GetMaterialNum( int MHandle ) ;															// ���f���Ŏg�p���Ă���}�e���A���̐����擾����
extern	const TCHAR *MV1GetMaterialName( int MHandle, int MaterialIndex ) ;										// �w��̃}�e���A���̖��O���擾����
extern	int			MV1SetMaterialType( int MHandle, int MaterialIndex, int Type ) ;							// �w��̃}�e���A���̃^�C�v��ύX����( Type : DX_MATERIAL_TYPE_NORMAL �Ȃ� )
extern	int			MV1GetMaterialType( int MHandle, int MaterialIndex ) ;										// �w��̃}�e���A���̃^�C�v���擾����( �߂�l : DX_MATERIAL_TYPE_NORMAL �Ȃ� )
extern	int			MV1SetMaterialDifColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// �w��̃}�e���A���̃f�B�t���[�Y�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialDifColor( int MHandle, int MaterialIndex ) ;									// �w��̃}�e���A���̃f�B�t���[�Y�J���[���擾����
extern	int			MV1SetMaterialSpcColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// �w��̃}�e���A���̃X�y�L�����J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialSpcColor( int MHandle, int MaterialIndex ) ;									// �w��̃}�e���A���̃X�y�L�����J���[���擾����
extern	int			MV1SetMaterialEmiColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// �w��̃}�e���A���̃G�~�b�V�u�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialEmiColor( int MHandle, int MaterialIndex ) ;									// �w��̃}�e���A���̃G�~�b�V�u�J���[���擾����
extern	int			MV1SetMaterialAmbColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;					// �w��̃}�e���A���̃A���r�G���g�J���[��ݒ肷��
extern	COLOR_F		MV1GetMaterialAmbColor( int MHandle, int MaterialIndex ) ;									// �w��̃}�e���A���̃A���r�G���g�J���[���擾����
extern	int			MV1SetMaterialSpcPower( int MHandle, int MaterialIndex, float Power ) ;						// �w��̃}�e���A���̃X�y�L�����̋�����ݒ肷��
extern	float		MV1GetMaterialSpcPower( int MHandle, int MaterialIndex ) ;									// �w��̃}�e���A���̃X�y�L�����̋������擾����
extern	int			MV1SetMaterialDifMapTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// �w��̃}�e���A���Ńf�B�t���[�Y�}�b�v�Ƃ��Ďg�p����e�N�X�`�����w�肷��
extern	int			MV1GetMaterialDifMapTexture( int MHandle, int MaterialIndex ) ;								// �w��̃}�e���A���Ńf�B�t���[�Y�}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1SetMaterialSpcMapTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// �w��̃}�e���A���ŃX�y�L�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����w�肷��
extern	int			MV1GetMaterialSpcMapTexture( int MHandle, int MaterialIndex ) ;								// �w��̃}�e���A���ŃX�y�L�����}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1GetMaterialNormalMapTexture( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ŗ@���}�b�v�Ƃ��Ďg�p����Ă���e�N�X�`���̃C���f�b�N�X���擾����
extern	int			MV1SetMaterialDifGradTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// �w��̃}�e���A���Ńg�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`����ݒ肷��
extern	int			MV1GetMaterialDifGradTexture( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ńg�D�[�������_�����O�̃f�B�t���[�Y�O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����擾����
extern	int			MV1SetMaterialSpcGradTexture( int MHandle, int MaterialIndex, int TexIndex ) ;				// �w��̃}�e���A���Ńg�D�[�������_�����O�̃X�y�L�����O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`����ݒ肷��
extern	int			MV1GetMaterialSpcGradTexture( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���Ńg�D�[�������_�����O�̃X�y�L�����O���f�[�V�����}�b�v�Ƃ��Ďg�p����e�N�X�`�����擾����
extern	int			MV1SetMaterialDifGradBlendType( int MHandle, int MaterialIndex, int BlendType ) ;			// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����f�B�t���[�Y�O���f�[�V�����}�b�v�ƃf�B�t���[�Y�J���[�̍������@��ݒ肷��( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1GetMaterialDifGradBlendType( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����f�B�t���[�Y�O���f�[�V�����}�b�v�ƃf�B�t���[�Y�J���[�̍������@���擾����( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1SetMaterialSpcGradBlendType( int MHandle, int MaterialIndex, int BlendType ) ;			// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����X�y�L�����O���f�[�V�����}�b�v�ƃX�y�L�����J���[�̍������@��ݒ肷��( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1GetMaterialSpcGradBlendType( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����X�y�L�����O���f�[�V�����}�b�v�ƃX�y�L�����J���[�̍������@���擾����( DX_MATERIAL_BLENDTYPE_ADDITIVE �Ȃ� )
extern	int			MV1SetMaterialOutLineWidth( int MHandle, int MaterialIndex, float Width ) ;					// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̑�����ݒ肷��
extern	float		MV1GetMaterialOutLineWidth( int MHandle, int MaterialIndex ) ;								// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̑������擾����
extern	int			MV1SetMaterialOutLineDotWidth( int MHandle, int MaterialIndex, float Width ) ;				// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̃h�b�g�P�ʂ̑�����ݒ肷��
extern	float		MV1GetMaterialOutLineDotWidth( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̃h�b�g�P�ʂ̑������擾����
extern	int			MV1SetMaterialOutLineColor( int MHandle, int MaterialIndex, COLOR_F Color ) ;				// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̐F��ݒ肷��
extern	COLOR_F		MV1GetMaterialOutLineColor( int MHandle, int MaterialIndex ) ;								// �w��̃}�e���A���̃g�D�[�������_�����O�Ŏg�p����֊s���̐F���擾����
extern	int			MV1SetMaterialDrawBlendMode( int MHandle, int MaterialIndex, int BlendMode ) ;				// �w��̃}�e���A���̕`��u�����h���[�h��ݒ肷��( DX_BLENDMODE_ALPHA �� )
extern	int			MV1GetMaterialDrawBlendMode( int MHandle, int MaterialIndex ) ;								// �w��̃}�e���A���̕`��u�����h���[�h���擾����( DX_BLENDMODE_ALPHA �� )
extern	int			MV1SetMaterialDrawBlendParam( int MHandle, int MaterialIndex, int BlendParam ) ;			// �w��̃}�e���A���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1GetMaterialDrawBlendParam( int MHandle, int MaterialIndex ) ;							// �w��̃}�e���A���̕`��u�����h�p�����[�^��ݒ肷��

// �e�N�X�`���֌W
extern	int			MV1GetTextureNum( int MHandle ) ;															// �e�N�X�`���̐����擾
extern	const TCHAR *MV1GetTextureName( int MHandle, int TexIndex ) ;											// �e�N�X�`���̖��O���擾
extern	int			MV1SetTextureColorFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// �J���[�e�N�X�`���̃t�@�C���p�X��ύX����
extern	const TCHAR *MV1GetTextureColorFilePath( int MHandle, int TexIndex ) ;									// �J���[�e�N�X�`���̃t�@�C���p�X���擾
extern	int			MV1SetTextureAlphaFilePath( int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// �A���t�@�e�N�X�`���̃t�@�C���p�X��ύX����
extern	const TCHAR *MV1GetTextureAlphaFilePath( int MHandle, int TexIndex ) ;									// �A���t�@�e�N�X�`���̃t�@�C���p�X���擾
extern	int			MV1SetTextureGraphHandle( int MHandle, int TexIndex, int GrHandle, int SemiTransFlag ) ;	// �e�N�X�`���Ŏg�p����O���t�B�b�N�n���h����ύX����( GrHandle �� -1 �ɂ���Ɖ��� )
extern	int			MV1GetTextureGraphHandle( int MHandle, int TexIndex ) ;										// �e�N�X�`���̃O���t�B�b�N�n���h�����擾����
extern	int			MV1SetTextureAddressMode( int MHandle, int TexIndex, int AddrUMode, int AddrVMode ) ;		// �e�N�X�`���̃A�h���X���[�h��ݒ肷��( AddUMode �̒l�� DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureAddressModeU( int MHandle, int TexIndex ) ;									// �e�N�X�`���̂t�l�̃A�h���X���[�h���擾����( �߂�l:DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureAddressModeV( int MHandle, int TexIndex ) ;									// �e�N�X�`���̂u�l�̃A�h���X���[�h���擾����( �߂�l:DX_TEXADDRESS_WRAP �� )
extern	int			MV1GetTextureWidth( int MHandle, int TexIndex ) ;											// �e�N�X�`���̕����擾����
extern	int			MV1GetTextureHeight( int MHandle, int TexIndex ) ;											// �e�N�X�`���̍������擾����
extern	int			MV1GetTextureSemiTransState( int MHandle, int TexIndex ) ;									// �e�N�X�`���ɔ������v�f�����邩�ǂ������擾����( �߂�l  TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetTextureBumpImageFlag( int MHandle, int TexIndex, int Flag ) ;							// �e�N�X�`���Ŏg�p���Ă���摜���o���v�}�b�v���ǂ�����ݒ肷��
extern	int			MV1GetTextureBumpImageFlag( int MHandle, int TexIndex ) ;									// �e�N�X�`�����o���v�}�b�v���ǂ������擾����( �߂�l  TRUE:�o���v�}�b�v  FALSE:�Ⴄ )
extern	int			MV1SetTextureBumpImageNextPixelLength( int MHandle, int TexIndex, float Length ) ;			// �o���v�}�b�v�摜�̏ꍇ�ׂ̗̃s�N�Z���Ƃ̋�����ݒ肷��
extern	float		MV1GetTextureBumpImageNextPixelLength( int MHandle, int TexIndex ) ;						// �o���v�}�b�v�摜�̏ꍇ�ׂ̗̃s�N�Z���Ƃ̋������擾����
extern	int			MV1SetTextureSampleFilterMode( int MHandle, int TexIndex, int FilterMode ) ;				// �e�N�X�`���̃t�B���^�����O���[�h��ݒ肷��
extern	int			MV1GetTextureSampleFilterMode( int MHandle, int TexIndex ) ;								// �e�N�X�`���̃t�B���^�����O���[�h���擾����( �߂�l  DX_DRAWMODE_BILINEAR�� )
extern	int			MV1LoadTexture( const TCHAR *FilePath ) ;													// �R�c���f���ɓ\��t����̂Ɍ������摜�̓ǂݍ��ݕ����ŉ摜��ǂݍ���( �߂�l  -1:�G���[  0�ȏ�:�O���t�B�b�N�n���h�� )

// �t���[���֌W
extern	int			MV1GetFrameNum( int MHandle ) ;																// �t���[���̐����擾����
extern	int			MV1SearchFrame( int MHandle, const TCHAR *FrameName ) ;										// �t���[���̖��O���烂�f�����̃t���[���̃t���[���C���f�b�N�X���擾����( ���������ꍇ�͖߂�l��-1 )
extern	int			MV1SearchFrameChild( int MHandle, int FrameIndex = -1 , const TCHAR *ChildName = NULL ) ;	// �t���[���̖��O����w��̃t���[���̎q�t���[���̃t���[���C���f�b�N�X���擾����( ���O�w��� )( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���� ChildIndex �Ŏw�肷�� )( ���������ꍇ�͖߂�l��-1 )
extern	const TCHAR *MV1GetFrameName( int MHandle, int FrameIndex ) ;											// �w��̃t���[���̖��O���擾����( �G���[�̏ꍇ�͖߂�l�� NULL )
extern	int			MV1GetFrameParent( int MHandle, int FrameIndex ) ;											// �w��̃t���[���̐e�t���[���̃C���f�b�N�X�𓾂�( �e�����Ȃ��ꍇ�� -2 ���Ԃ� )
extern	int			MV1GetFrameChildNum( int MHandle, int FrameIndex = -1 ) ;									// �w��̃t���[���̎q�t���[���̐����擾����( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���̐����Ԃ��Ă��� )
extern	int			MV1GetFrameChild( int MHandle, int FrameIndex = -1 , int ChildIndex = 0 ) ;					// �w��̃t���[���̎q�t���[���̃t���[���C���f�b�N�X���擾����( �ԍ��w��� )( FrameIndex �� -1 �ɂ���Ɛe�������Ȃ��t���[���� ChildIndex �Ŏw�肷�� )( �G���[�̏ꍇ�͖߂�l��-1 )
extern	VECTOR		MV1GetFramePosition( int MHandle, int FrameIndex ) ;										// �w��̃t���[���̍��W���擾����
extern	MATRIX		MV1GetFrameBaseLocalMatrix( int MHandle, int FrameIndex ) ;									// �w��̃t���[���̏�����Ԃł̍��W�ϊ��s����擾����
extern	MATRIX		MV1GetFrameLocalMatrix( int MHandle, int FrameIndex ) ;										// �w��̃t���[���̍��W�ϊ��s����擾����
extern	MATRIX		MV1GetFrameLocalWorldMatrix( int MHandle, int FrameIndex ) ;								// �w��̃t���[���̃��[�J�����W���烏�[���h���W�ɕϊ�����s��𓾂�
extern	int			MV1SetFrameUserLocalMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;					// �w��̃t���[���̍��W�ϊ��s���ݒ肷��
extern	int			MV1ResetFrameUserLocalMatrix( int MHandle, int FrameIndex ) ;								// �w��̃t���[���̍��W�ϊ��s����f�t�H���g�ɖ߂�
extern	VECTOR		MV1GetFrameMaxVertexLocalPosition( int MHandle, int FrameIndex ) ;							// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̍ő�l�𓾂�
extern	VECTOR		MV1GetFrameMinVertexLocalPosition( int MHandle, int FrameIndex ) ;							// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̍ŏ��l�𓾂�
extern	VECTOR		MV1GetFrameAvgVertexLocalPosition( int MHandle, int FrameIndex ) ;							// �w��̃t���[���������b�V�����_�̃��[�J�����W�ł̕��ϒl�𓾂�
extern	int			MV1GetFrameTriangleNum( int MHandle, int FrameIndex ) ;										// �w��̃t���[���Ɋ܂܂��|���S���̐����擾����
extern	int			MV1GetFrameMeshNum( int MHandle, int FrameIndex ) ;											// �w��̃t���[���������b�V���̐����擾����
extern	int			MV1GetFrameMesh( int MHandle, int FrameIndex, int Index ) ;									// �w��̃t���[���������b�V���̃��b�V���C���f�b�N�X���擾����
extern	int			MV1SetFrameVisible( int MHandle, int FrameIndex, int VisibleFlag ) ;						// �w��̃t���[���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetFrameVisible( int MHandle, int FrameIndex ) ;											// �w��̃t���[���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetFrameDifColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// �w��̃t���[���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameSpcColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// �w��̃t���[���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameEmiColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// �w��̃t���[���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetFrameAmbColorScale( int MHandle, int FrameIndex, COLOR_F Scale ) ;					// �w��̃t���[���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameDifColorScale( int MHandle, int FrameIndex ) ;									// �w��̃t���[���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameSpcColorScale( int MHandle, int FrameIndex ) ;									// �w��̃t���[���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameEmiColorScale( int MHandle, int FrameIndex ) ;									// �w��̃t���[���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetFrameAmbColorScale( int MHandle, int FrameIndex ) ;									// �w��̃t���[���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1GetFrameSemiTransState( int MHandle, int FrameIndex ) ;									// �w��̃t���[���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetFrameOpacityRate( int MHandle, int FrameIndex, float Rate ) ;							// �w��̃t���[���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetFrameOpacityRate( int MHandle, int FrameIndex ) ;										// �w��̃t���[���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetFrameBaseVisible( int MHandle, int FrameIndex, int VisibleFlag ) ;					// �w��̃t���[���̏����\����Ԃ�ݒ肷��( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetFrameBaseVisible( int MHandle, int FrameIndex ) ;										// �w��̃t���[���̏����\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetFrameTextureAddressTransform( int MHandle, int FrameIndex, float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// �w��̃t���[���̃e�N�X�`�����W�ϊ��p�����[�^��ݒ肷��
extern	int			MV1SetFrameTextureAddressTransformMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;			// �w��̃t���[���̃e�N�X�`�����W�ϊ��s����Z�b�g����
extern	int			MV1ResetFrameTextureAddressTransform( int MHandle, int FrameIndex ) ;							// �w��̃t���[���̃e�N�X�`�����W�ϊ��p�����[�^�����Z�b�g����

// ���b�V���֌W
extern	int			MV1GetMeshNum( int MHandle ) ;																// ���f���Ɋ܂܂�郁�b�V���̐����擾����
extern	int			MV1GetMeshMaterial( int MHandle, int MeshIndex ) ;											// �w�胁�b�V�����g�p���Ă���}�e���A���̃C���f�b�N�X���擾����
extern	int			MV1GetMeshTriangleNum( int MHandle, int MeshIndex ) ;										// �w�胁�b�V���Ɋ܂܂��O�p�`�|���S���̐����擾����
extern	int			MV1SetMeshVisible( int MHandle, int MeshIndex, int VisibleFlag ) ;							// �w�胁�b�V���̕\���A��\����Ԃ�ύX����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetMeshVisible( int MHandle, int MeshIndex ) ;											// �w�胁�b�V���̕\���A��\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetMeshDifColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// �w��̃��b�V���̃f�B�t���[�Y�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshSpcColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// �w��̃��b�V���̃X�y�L�����J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshEmiColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// �w��̃��b�V���̃G�~�b�V�u�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshAmbColorScale( int MHandle, int MeshIndex, COLOR_F Scale ) ;						// �w��̃��b�V���̃A���r�G���g�J���[�̃X�P�[���l��ݒ肷��( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshDifColorScale( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̃f�B�t���[�Y�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshSpcColorScale( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̃X�y�L�����J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshEmiColorScale( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̃G�~�b�V�u�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	COLOR_F		MV1GetMeshAmbColorScale( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̃A���r�G���g�J���[�̃X�P�[���l���擾����( �f�t�H���g�l�� 1.0f )
extern	int			MV1SetMeshOpacityRate( int MHandle, int MeshIndex, float Rate ) ;							// �w��̃��b�V���̕s�����x��ݒ肷��( �s���� 1.0f �` ���� 0.0f )
extern	float		MV1GetMeshOpacityRate( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̕s�����x���擾����( �s���� 1.0f �` ���� 0.0f )
extern	int			MV1SetMeshDrawBlendMode( int MHandle, int MeshIndex, int BlendMode ) ;						// �w��̃��b�V���̕`��u�����h���[�h��ݒ肷��( DX_BLENDMODE_ALPHA �� )
extern	int			MV1SetMeshDrawBlendParam( int MHandle, int MeshIndex, int BlendParam ) ;					// �w��̃��b�V���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1GetMeshDrawBlendMode( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̕`��u�����h���[�h���擾����( DX_BLENDMODE_ALPHA �� )
extern	int			MV1GetMeshDrawBlendParam( int MHandle, int MeshIndex ) ;									// �w��̃��b�V���̕`��u�����h�p�����[�^��ݒ肷��
extern	int			MV1SetMeshBaseVisible( int MHandle, int MeshIndex, int VisibleFlag ) ;						// �w��̃��b�V���̏����\����Ԃ�ݒ肷��( TRUE:�\��  FALSE:��\�� )
extern	int			MV1GetMeshBaseVisible( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̏����\����Ԃ��擾����( TRUE:�\��  FALSE:��\�� )
extern	int			MV1SetMeshBackCulling( int MHandle, int MeshIndex, int CullingFlag ) ;						// �w��̃��b�V���̃o�b�N�J�����O���s�����ǂ�����ݒ肷��( DX_CULLING_LEFT �� )
extern	int			MV1GetMeshBackCulling( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���̃o�b�N�J�����O���s�����ǂ������擾����( DX_CULLING_LEFT �� )
extern	VECTOR		MV1GetMeshMaxPosition( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���Ɋ܂܂��|���S���̍ő働�[�J�����W���擾����
extern	VECTOR		MV1GetMeshMinPosition( int MHandle, int MeshIndex ) ;										// �w��̃��b�V���Ɋ܂܂��|���S���̍ŏ����[�J�����W���擾����
extern	int			MV1GetMeshTListNum( int MHandle, int MeshIndex ) ;											// �w��̃��b�V���Ɋ܂܂��g���C�A���O�����X�g�̐����擾����
extern	int			MV1GetMeshTList( int MHandle, int MeshIndex, int Index ) ;									// �w��̃��b�V���Ɋ܂܂��g���C�A���O�����X�g�̃C���f�b�N�X���擾����
extern	int			MV1GetMeshSemiTransState( int MHandle, int MeshIndex ) ;									// �w��̃��b�V���ɔ������v�f�����邩�ǂ������擾����( �߂�l TRUE:����  FALSE:�Ȃ� )
extern	int			MV1SetMeshUseVertDifColor( int MHandle, int MeshIndex, int UseFlag ) ;						// �w��̃��b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1SetMeshUseVertSpcColor( int MHandle, int MeshIndex, int UseFlag ) ;						// �w��̃��b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ�����ݒ肷��( TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1GetMeshUseVertDifColor( int MHandle, int MeshIndex ) ;									// �w��̃��b�V���̒��_�f�B�t���[�Y�J���[���}�e���A���̃f�B�t���[�Y�J���[�̑���Ɏg�p���邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )
extern	int			MV1GetMeshUseVertSpcColor( int MHandle, int MeshIndex ) ;									// �w��̃��b�V���̒��_�X�y�L�����J���[���}�e���A���̃X�y�L�����J���[�̑���Ɏg�p���邩�ǂ����̐ݒ���擾����( �߂�l  TRUE:�}�e���A���J���[�̑���Ɏg�p����  FALSE:�}�e���A���J���[���g�p���� )

// �g���C�A���O�����X�g�֌W
extern	int			MV1GetTriangleListNum( int MHandle ) ;														// �g���C�A���O�����X�g�̐����擾����
extern	int			MV1GetTriangleListVertexType( int MHandle, int TListIndex ) ;								// �w��̃g���C�A���O�����X�g�̒��_�f�[�^�^�C�v���擾����( MV1_VERTEX_TYPE_NORMAL �� )
extern	int			MV1GetTriangleListPolygonNum( int MHandle, int TListIndex ) ;								// �w��̃g���C�A���O�����X�g�Ɋ܂܂��|���S���̐����擾����
extern	int			MV1GetTriangleListVertexNum( int MHandle, int TListIndex ) ;								// �w��̃g���C�A���O�����X�g�Ɋ܂܂�钸�_�f�[�^�̐����擾����

// �R���W�����֌W
extern	int			MV1SetupCollInfo( int MHandle, int FrameIndex = -1 , int XDivNum = 32 , int YDivNum = 8 , int ZDivNum = 32 ) ;	// �R���W���������\�z����
extern	int			MV1TerminateCollInfo( int MHandle, int FrameIndex = -1 ) ;									// �R���W�������̌�n��
extern	int			MV1RefreshCollInfo( int MHandle, int FrameIndex = -1 ) ;									// �R���W���������X�V����
extern	MV1_COLL_RESULT_POLY     MV1CollCheck_Line( int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ; // ���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_LineDim( int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ; // ���ƃ��f���̓����蔻��( �߂�l�� MV1_COLL_RESULT_POLY_DIM )
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_Sphere( int MHandle, int FrameIndex, VECTOR CenterPos, float r ) ;	// ���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY_DIM MV1CollCheck_Capsule( int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, float r ) ;	// �J�v�Z���ƃ��f���̓����蔻��
extern	MV1_COLL_RESULT_POLY     MV1CollCheck_GetResultPoly( MV1_COLL_RESULT_POLY_DIM ResultPolyDim, int PolyNo ) ;	// �R���W�������ʃ|���S���z�񂩂�w��ԍ��̃|���S�������擾����
extern	int			MV1CollResultPolyDimTerminate( MV1_COLL_RESULT_POLY_DIM ResultPolyDim ) ;					// �R���W�������ʃ|���S���z��̌�n��������

// �Q�Ɨp���b�V���֌W
extern	int			MV1SetupReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;						// �Q�Ɨp���b�V���̃Z�b�g�A�b�v
extern	int			MV1TerminateReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;					// �Q�Ɨp���b�V���̌�n��
extern	int			MV1RefreshReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;					// �Q�Ɨp���b�V���̍X�V
extern	MV1_REF_POLYGONLIST	MV1GetReferenceMesh( int MHandle, int FrameIndex, int IsTransform ) ;				// �Q�Ɨp���b�V�����擾����

#endif

#define DX_FUNCTION_END

}

// �l�[���X�y�[�X DxLib ���g�p���� ------------------------------------------------------
using namespace DxLib ;

// �c�w���C�u���������ł̂ݎg�p����w�b�_�t�@�C���̃C���N���[�h -------------------------

#ifdef __DX_MAKE
	#include "DxStatic.h"
#endif

#endif


