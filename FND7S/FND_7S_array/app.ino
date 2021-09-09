int fnd_a = 7;
unsigned char table[10][8] = {
    {0, 0, 1, 1, 1, 1, 1, 1}, //0
    {0, 0, 0, 0, 0, 1, 1, 0}, //1
    {0, 1, 0, 1, 1, 0, 1, 1}, //2
    {0, 1, 0, 0, 1, 1, 1, 1}, //3
    {0, 1, 1, 0, 0, 1, 1, 0}, //4
    {0, 1, 1, 0, 1, 1, 0, 1}, //5
    {0, 1, 1, 1, 1, 1, 0, 1}, //6
    {0, 0, 0, 0, 0, 1, 1, 1}, //7
    {0, 1, 1, 1, 1, 1, 1, 1}, //8
    {0, 1, 1, 0, 1, 1, 1, 1}  //9
};
void setup()
{
  // int i;
  for (size_t i = fnd_a; i < fnd_a + 7; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  // int i, j;
  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 7; j++)
      digitalWrite(fnd_a + j, table[i][7 - j]);
    delay(500);
  }
}