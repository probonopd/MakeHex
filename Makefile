all: encodeir

MakeHex: MakeHex.cpp IRP.cpp
	g++ -o MakeHex $?

encodeir: EncodeIR.cpp IRP.cpp
	g++ -o encodeir $?
