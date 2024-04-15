MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 32K /*Program memory*/
  RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 10K /*stack memory (see device datasheet p. 34)*/
}