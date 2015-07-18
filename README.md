# MakeHex
**MakeHex** by John Fine. This program reads a .IRP file and creates a .HEX file containing the Pronto hex sequences for the IR commands specified by that .IRP file. See the readme file for more information.

Now also contains **EncodeIR**: This program takes device, subdevice, and function and outputs timing information in raw format.

```
$ ./encodeir NECx1 0 191 1
4512 4512 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 1692 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 564 1692 564 1692 564 1692 564 1692 564 1692 564 1692 564 1692 564 43992 4512 4512 564 1692 564 95880
```

## License

From the ReadMe for MakeHex version 4.12:

Copyright 2005 John S. Fine

You may use, copy, modify and/or distribute this program for private or
commercial use provided that: 1) You do not hold me responsible for any damage or negative consequences
resulting from those activities. 2) You include this copyright notice and disclaimer in any copy of any part
or all of this program. I do not provide any warranty of the correctness, safety, or suitibility of
this program for any purpose. If you do not agree to these conditions, you have no permission to use, copy,
modify or distribute this program.
