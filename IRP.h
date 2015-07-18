///////////////////////////////////////////////////////////////////////////////
// MakeHex version 5  Copyright 2004 John S. Fine
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

#if !defined(AFX_IRP_H__8F4DCB1B_52D6_11D4_8388_000000000000__INCLUDED_)
#define AFX_IRP_H__8F4DCB1B_52D6_11D4_8388_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Value
{
    double m_val;
    int m_bits;
};

enum
{
    colon = 1,
    plus = 2,
    times = 3,
    unary = 4,
};

class IRP  
{
public:
	IRP();
	~IRP();
	bool readIrpFile(FILE *InFile);
	bool readIrpString(char *str);
	void writeHex(FILE *OutFile);
	void generate(FILE *OutFile);
	void generate(int *s, int *r, float *out);
	int genHex(char *Pattern);
	void genHex(std::vector<float>& Sequence);
    void genHex(float number);

    void parseVal(Value& result, char*& in, int prec=0);
    void setDigit(int d);

	int value0(char *&eq);
	int value1(char *&eq);
	int value2(char *&eq);

	float m_frequency;
	float m_timeBase;
	float m_messageTime;
    char* m_digits[16];

    char* m_prefix;
	char* m_suffix;
	char* m_rPrefix;
	char* m_rSuffix;
	bool m_msb;
	char *(m_def[26]);
	int m_value[26];
	char *m_form;
	int m_numberFormat;

	int m_device[3];
	int m_function[2];
	int m_functions[4];
	float m_cumulative;
	std::vector<float> m_hex;

	// Helper for reading an Irp file
	bool match(const char *master);
	void Parse(std::vector<float> &result);
	char *copy();
	void getPair(int *result);
	char m_bufr[1000];
	char *m_next;
    unsigned int m_mask[33];
    int m_bitGroup;
    int m_pendingBits;
};

#endif // !defined(AFX_IRP_H__8F4DCB1B_52D6_11D4_8388_000000000000__INCLUDED_)
