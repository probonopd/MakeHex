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

#include "stdafx.h"
#include "irp.h"

int main(int argc, char** argv)
{

	if (argc != 5)
	{
		printf("Usage: encodeir <irpfile> <device> <subdevice> <function>\n");
		return -1;
	}

	// Arguments
	char *irpfile = argv[1];
	int device = atoi(argv[2]);
	int subdevice = atoi(argv[3]);
	int obc = atoi(argv[4]);

	// Parse IRP file
	FILE *InFile = fopen(irpfile, "r");
	if (!InFile)
	{
		printf("Unable to open \"%s\"\n", irpfile);
		return -1;
	}
	IRP Irp;
	if (! Irp.readIrpFile(InFile) )
	{
		printf("IRP file \"%s\" not processed\n", irpfile);
		return -1;
	}
	fclose(InFile);

	// Encode
	int s, r;
	float seq[1024], p;
	Irp.m_value['D' - 'A'] = device;
	Irp.m_value['S' - 'A'] = subdevice;
	Irp.m_value['F' - 'A'] = obc;
	Irp.m_value['N' - 'A'] = -1;
	Irp.generate(&s, &r, seq);

	// Output
	p = 1000000. / Irp.m_frequency;
	for (int i = 0; i < 2 *(s + r); i++)
		printf ("%s%g", i?" ":"", seq[i]);
	printf ("\n");
	
	return 0;
}
