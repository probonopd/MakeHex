// There seems to be a memory leak.
// Tested with https://github.com/esp8266/Arduino
// FIXME: Contributions welcome!

#include "irp.h"
#include <math.h>

IRP Irp;

char irp[1024 * 2] = "";
int sss, rrr;
float seq[1024];

struct protdef {
  const char *prot;
  const char *def;
};

// TODO: Parse this from a string in IRP notation sent via Serial or WiFi instead
// http://www.hifi-remote.com/wiki/index.php?title=IRP_Notation
// IRP notation: {38.4k,564}<1,-1|1,-3>(8,-8,D:8,S:8,F:8,~F8,1,^108m,(8,-8,D:1,1,^108m)*)
struct protdef protdefs[] = {
  { "NECx1",
    "Protocol=NECx1\n"
    "Frequency=38000\n"
    "Time Base=564\n"
    "One=1,-3\n"
    "Zero=1,-1\n"
    "Prefix=8,-8\n"
    "Suffix=1,-78\n"
    "R-Suffix=~D:1,1,-170\n"
    "Form=*,D:8,S:8,F:8,~F:8,_;*,_\n"
  },
};

void setup() {
  Serial.begin(115200);
}

void loop() {

  Irp.m_value['D' - 'A'] = 0;
  Irp.m_value['S' - 'A'] = 1;
  Irp.m_value['F' - 'A'] = 191;
  Irp.m_value['N' - 'A'] = -1;

  strcat(irp, protdefs[0].def);

  Irp.readIrpString(irp);

  Irp.generate(&sss, &rrr, seq);

  for (int i = 0; i < 2 * (sss + rrr); i++)
  {
    Serial.print(round(seq[i]));
    Serial.print(" ");
  }
  Serial.println("");

  for (int i = 0; i < 2 * (sss + rrr); i++)
  {
    if (i%2 == 0)
      Serial.print("+");
    else
      Serial.print("-");
    Serial.print(round(seq[i]));
    Serial.print(" ");
  }
  Serial.println("");

  Serial.println("");
  Serial.print("ESP.getFreeHeap() = ");
  Serial.println (ESP.getFreeHeap());

}
