///*
//* Copyright: Shenzhen Tian Microelectronics
//* File name: TM1637
//* Current Version: 1.0
//* SCM Model: AT89S52
//* Development Environment: Keil uVision3
//* Crystal earthquake frequency: 11.0592M
//* Program features: the TM1637 all filled with all the display data register address
//  0xff, and open the display, and then read the key value.
//*/
//
//   // Define port
//   sbit clk = P1 ^ 2;
//   sbit dio = P1 ^ 1;
//
///// =======================================
//void Delay_us (unsigned int i) // n us delay
//{
//   for (; i> 0; i--)
//_  nop_ ();
//}
///// ======================================
//void I2CStart (void) // 1637 start
//{
//   clk = 1;
//   dio = 1;
//   Delay_us (2);
//   dio = 0;
//}
///// =============================================
//void I2Cask (void) // 1637 Answer
//{
//   clk = 0;
//   Delay_us (5); // After the falling edge of the eighth clock delay 5us, ACK signals the beginning of judgment
//   while (dio);
//   clk = 1;
//   Delay_us (2);
//   clk = 0;
//}
///// ========================================
//void I2CStop (void) // 1637 Stop
//{
//   clk = 0;
//   Delay_us (2);
//   dio = 0;
//   Delay_us (2);
//   clk = 1;
//   Delay_us (2);
//   dio = 1;
//}
///// =========================================
//void I2CWrByte (unsigned char oneByte) // write a byte
//{
//   unsigned char i;
//   for (i = 0; i <8; i + +)
//   {
//      Clk = 0;
//      if (oneByte & 0x01) // low front
//      {dio = 1;}
//      else {dio = 0;}
//      Delay_us (3);
//      oneByte = oneByte >> 1;
//      clk = 1;
//      Delay_us (3);
//   }
//}
///// ----------------------------------------------- -
//unsigned char ScanKey(void) // read buttons \
//{
//   unsigned char rekey, rkey, i;
//   I2CStart ();
//   I2CWrByte(0x42); // read command buttons
//   I2Cask ();
//   dio = 1; // read keys before data lines pulled
//   for (i = 0; i <8; i + +) // start reading from the low
//   {
//      Clk = 0;
//      rekey = rekey >> 1;
//      Delay_us(30);
//      clk=1;
//      if(dio)
//      {
//          rekey=rekey|0x80;
//      }
//      else
//      {
//          rekey=rekey|0x00;
//      }
//      Delay_us(30);
//   }
//   I2Cask();
//   I2CStop();
//   return (rekey);
//}
//
//void SmgDisplay(void) // Write display register
//{
//   unsigned char i;
//   I2CStart();
//   I2CWrByte(0x40); //40H address is automatically incremented by 1 mode, 44H fixed address mode
//   I2Cask();
//   I2CStop();
//   I2CStart();
//   I2CWrByte(0xc0); // Set the first address
//   I2Cask();
//   for(i=0;i<6;i++) // Addresses from Canada, do not always write address
//   {
//      I2CWrByte(0xff); // Send data
//      I2Cask();
//      }
//    I2CStop();
//      I2CStart();
//   I2CWrByte(0x8f); // Open display, maximum brightness
//   I2Cask();
//   I2CStop();
//}
/////==============================================
//void init() // Initialization routine
//{
//   // Initialization slightly
//}
/////==============================================
//void main(void)
//{
//    unsigned char keydate;
//    init()； // Initialization
//    SmgDisplay(); // Write register and open display
//    while(1)
//    {
//       keydate=Scankey(); // Read key value, the key value is not read out for treatment.
//    }
//}
////===========end==================================
