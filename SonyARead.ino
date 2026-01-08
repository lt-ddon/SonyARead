#define SI_RESET  4
#define SI_CLK    2
#define SI_DATA   3

uint8_t paraCount;
uint8_t dump[64];
uint8_t dumpPrev[64];

bool SIReadDump64(uint8_t ext[], uint8_t reset, uint8_t clk, uint8_t data)
{
  uint8_t x, l;
  if (!SIReset(reset)) return false;
  for (uint8_t i = 0; i < 64; i++) ext[i] = SIReadByte(clk, data);
  return true;
}

uint8_t SIReadByte(uint8_t clk, uint8_t data)
{
  uint8_t x = 0;
  for (uint8_t i = 0; i < 8; i++)
  {
    digitalWrite(clk, HIGH);
    delayMicroseconds(10);
    digitalWrite(clk, LOW);
    delayMicroseconds(10);
    x |= (digitalRead(data) << (7 - i));
  }
  return x;
}

bool SIReset(uint8_t reset)
{
  digitalWrite(reset, HIGH);
  delayMicroseconds(10);
  digitalWrite(reset, LOW);
  delayMicroseconds(10);
  uint8_t x;
  x = SIReadByte(2, 3);
  if (x != 0xff)
  {
    serialPrintHex8(x);
    Serial.println();
    Serial.println("Błąd nagłówka!");
    return false;
  }
  return true;
}

void serialPrintHex8(uint8_t x)
{
  if (x < 0x10) Serial.print("0");
  Serial.print(x, HEX);
}

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);
  paraCount = 0;
  
}

void loop()
{
  if (!SIReadDump64(dump, SI_RESET, SI_CLK, SI_DATA)) return;
  if (!memcmp(dump, dumpPrev, 64)) return;
  memcpy(dumpPrev, dump, 64);

  serialPrintHex8(dump[0]);
  Serial.print("  ");

  for (uint8_t i = 1; i < 32; i++)
  {
    serialPrintHex8(dump[i]);
    Serial.print(" ");
  }
  Serial.print(" ");
  for (uint8_t i = 32; i < 64; i++)
  {
    serialPrintHex8(dump[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(100);
}