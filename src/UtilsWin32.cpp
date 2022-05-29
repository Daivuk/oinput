#include <Windows.h>
#include "Utils.h"

namespace oinput
{
	int showMessageBox (
		char const * const aTitle , /* NULL or "" */
		char const * const aMessage , /* NULL or ""  may contain \n and \t */
		char const * const aDialogType , /* "ok" "okcancel" "yesno" "yesnocancel" */
		char const * const aIconType , /* "info" "warning" "error" "question" */
		int const aDefaultButton ) /* 0 for cancel/no , 1 for ok/yes , 2 for no in yesnocancel */
	{
		int lBoxReturnValue;
		UINT aCode ;
	
		if ( aIconType && ! strcmp( "warning" , aIconType ) )
		{
			aCode = MB_ICONWARNING ;
		}
		else if ( aIconType && ! strcmp("error", aIconType))
		{
			aCode = MB_ICONERROR ;
		}
		else if ( aIconType && ! strcmp("question", aIconType))
		{
			aCode = MB_ICONQUESTION ;
		}
		else
		{
			aCode = MB_ICONINFORMATION ;
		}

		if ( aDialogType && ! strcmp( "okcancel" , aDialogType ) )
		{
			aCode += MB_OKCANCEL ;
			if ( ! aDefaultButton )
			{
				aCode += MB_DEFBUTTON2 ;
			}
		}
		else if ( aDialogType && ! strcmp( "yesno" , aDialogType ) )
		{
			aCode += MB_YESNO ;
			if ( ! aDefaultButton )
			{
				aCode += MB_DEFBUTTON2 ;
			}
		}
		else if (aDialogType && !strcmp("yesnocancel", aDialogType))
		{
			aCode += MB_YESNOCANCEL;
			if (!aDefaultButton)
			{
				aCode += MB_DEFBUTTON3;
			}
			else if (aDefaultButton == 2)
			{
				aCode += MB_DEFBUTTON2;
			}
		}
		else
		{
			aCode += MB_OK ;
		}

		lBoxReturnValue = MessageBoxA(NULL, aMessage, aTitle, aCode);

		if (((aDialogType && !strcmp("yesnocancel", aDialogType))
			&& (lBoxReturnValue == IDNO)))
		{
			return 2;
		}

		if ( ( ( aDialogType
			&& strcmp("yesnocancel", aDialogType)
			&& strcmp("okcancel", aDialogType)
			&& strcmp("yesno", aDialogType)))
			|| (lBoxReturnValue == IDOK)
			|| (lBoxReturnValue == IDYES) )
		{
			return 1 ;
		}
		else
		{
			return 0 ;
		}
	}
}
