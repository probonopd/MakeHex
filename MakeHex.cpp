///////////////////////////////////////////////////////////////////////////////
// MakeHex version 4  Copyright 2004 John S. Fine
//
// You may use, copy, modify and/or distribute this program for private or
// commercial use provided that:
//
// 1)  You do not hold me responsible for any damage or negative consequences
// resulting from those activities.
//
// 2)  You include this copyright notice and disclaimer in any copy of any part
// or all of this program.
//
// I do not provide any warranty of the correctness, safety, or suitibility of
// this program for any purpose.
//
// If you do not agree to these conditions, you have no permission to use, copy,
// modify or distribute this program.
///////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "IRP.h"

int main(int argc, char** argv)
{

	if (argc<2)
	{
usage:
		printf("Usage MakeHex IrpFile {OutFile}\n");
		return -1;
	}

	IRP Irp;
	char* arg1=*(++argv);
	if (arg1[0]=='-' && arg1[2]==0)
	{
		char s = toupper(arg1[1]);
		if (s=='H')
			Irp.m_numberFormat = 1;
		else if (s=='B')
			Irp.m_numberFormat = 2;
		else
			goto usage;
		arg1 = *(++argv);
		if (--argc == 1)
			goto usage;
	}
	if (argc>3)
		goto usage;


	FILE *InFile = fopen(arg1, "r");
	if (!InFile)
	{
		printf("Unable to open \"%s\"\n", arg1);
		return -1;
	}

	if (! Irp.readIrpFile(InFile) )
	{
		printf("IRP file not processed\n");
		return -1;
	}

	char *OutName;
	if (argc==3)
	{
		OutName = argv[1];
	}
	else
	{
		char *tmp = strrchr(arg1, '.');
		if (!tmp)
		{
			tmp = arg1 + strlen(arg1);
		}
		int len = tmp - arg1;
		OutName = new char [len+5];
		memcpy(OutName, arg1, len);
		strcpy(OutName+len, ".hex");
	}

	FILE *OutFile = fopen(OutName, "w");
	if (!OutFile)
	{
		printf("Unable to create \"%s\"\n", OutName);
		return -1;
	}

	Irp.writeHex(OutFile);

	fclose(OutFile);

	return 0;
}
