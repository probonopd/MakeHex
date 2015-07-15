all: encodeir makehex

clean:
	rm *.o makehex encodeir

makehex:
	g++ -c MakeHex.cpp
	g++ -c IRP.cpp
	g++ -omakehex MakeHex.o IRP.o
	strip makehex

encodeir:
	g++ -c EncodeIR.cpp
	g++ -c IRP.cpp
	g++ -oencodeir EncodeIR.o IRP.o
	strip encodeir
