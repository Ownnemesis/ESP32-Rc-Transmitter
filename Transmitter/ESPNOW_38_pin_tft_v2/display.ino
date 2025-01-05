

void drawinfos(){
//MitteL
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(50,60);
  tft.print("Tx:");
  
  tft.setCursor(50,85);
  tft.print("BAT:3.2V");
  tft.setCursor(50,110);
  tft.print("Model:");
  tft.print(modnum);
  tft.setCursor(50,135);
  tft.print("Truck");
//MitteR
  tft.setCursor(163,60);
  tft.print("Rx: ON");
  tft.setCursor(163,85);
  tft.print("BAT:4.2V");
  tft.setCursor(163,110);
  tft.print("Model:1");
  tft.setCursor(163,135);
  tft.print("Truck");
}


void drawBars(){

int newPercent;
    RawValue = analogRead(32);
    newPercent = int((RawValue/4095.0)* 180.0);
    
    if (newPercent != LastPercent){
      drawBar(newPercent);     
    }

  int newPercent1;
    RawValue1 = analogRead(33);
    newPercent1 = int((RawValue1/4095.0)* 180.0);
    
    if (newPercent1 != LastPercent1){
      drawBar1(newPercent1); 
    }

 int newPercent2;
    RawValue2 = analogRead(34);
    newPercent2 = int((RawValue2/4095.0)* 160.0);
    
    if (newPercent2 != LastPercent2){
      drawBar2(newPercent2); 
    }

    int newPercent3;
    RawValue3 = analogRead(35);
    newPercent3 = int((RawValue3/4095.0)* 160.0);
    
    if (newPercent3 != LastPercent3){
      drawBar3(newPercent3); 
    }


}
//***********************************************************************************************
void drawScale(){  
  //links
  tft.drawFastVLine(10, 5,180, SCALECOLOR ); // Vertical Scale Line  
  tft.drawFastHLine(2, 5, 8, SCALECOLOR); // Major Division
  tft.drawFastHLine(5, 50, 5, SCALECOLOR); // Minor Division
  tft.drawFastHLine(2, 95, 8, SCALECOLOR); // Major Division
  tft.drawFastHLine(5, 140, 5, SCALECOLOR); // Minor Division
  tft.drawFastHLine(2, 185, 8, SCALECOLOR);  // Major Division+
  //rechts
  tft.drawFastVLine(305, 5,180, SCALECOLOR ); // Vertical Scale Line  
  tft.drawFastHLine(305, 5, 8, SCALECOLOR); // Major Division
  tft.drawFastHLine(305, 50, 5, SCALECOLOR); // Minor Division
  tft.drawFastHLine(305, 95, 8, SCALECOLOR); // Major Division
  tft.drawFastHLine(305, 140, 5, SCALECOLOR); // Minor Division
  tft.drawFastHLine(305, 185, 8, SCALECOLOR);  // Major Division+

  //unten recht
  tft.drawFastHLine(1, 198,320, SCALECOLOR );
  tft.drawFastHLine(1, 230,320, SCALECOLOR ); // Vertical Scale Line  
  tft.drawFastVLine(1, 230, 8, SCALECOLOR); // Major Division
  tft.drawFastVLine(85, 230, 5, SCALECOLOR); // Minor Division
  tft.drawFastVLine(160, 230, 8, SCALECOLOR); // Major Division
  tft.drawFastVLine(240, 230, 5, SCALECOLOR); // Minor Division
  tft.drawFastVLine(310, 230, 8, SCALECOLOR);  // Major Division+
  //Oben
  tft.drawFastHLine(50, 50 , 215, TFT_WHITE);
  tft.drawFastVLine(160, 50, 190, SCALECOLOR);
  
}
//***********************************************************************************************
void drawButtonT(){

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);

  tft.setCursor(50,5);
  tft.print("T1");

  if(data.switch1Value == 0){
  tft.fillCircle(60, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(60, 30, 8, TFT_GREEN);
}

  tft.setCursor(76,5);     
  tft.print("T2");

  if(data.switch2Value == 0){
  tft.fillCircle(86, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(86, 30, 8, TFT_GREEN);
} 
  
  tft.setCursor(103,5);
  tft.print("T3");

  if(data.switch3Value == 0){
  tft.fillCircle(113, 31, 8, TFT_RED);
}
else{
  tft.fillCircle(113, 31, 8, TFT_GREEN);
}             
  
  tft.setCursor(132,5);
  tft.print("T4");             
  
  if(data.switch4Value == 0){
  tft.fillCircle(142, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(142, 30, 8, TFT_GREEN);
}
}
//***********************************************************************************************
void drawButtonM(){

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);

  tft.setCursor(162,5);
  tft.print("M1");

  if(data.switch5Value == 0){
  tft.fillCircle(172, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(172, 30, 8, TFT_GREEN);
}

  tft.setCursor(190,5);     
  tft.print("M2");

  if(data.switch6Value == 0){
  tft.fillCircle(200, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(200, 30, 8, TFT_GREEN);
} 
  
  tft.setCursor(219,5);
  tft.print("M3");

  if(data.switch7Value == 0){
  tft.fillCircle(229, 31, 8, TFT_RED);
}
else{
  tft.fillCircle(229, 31, 8, TFT_GREEN);
}             
  
  tft.setCursor(253,5);
  tft.print("M4");             
  
  if(data.switch8Value == 0){
  tft.fillCircle(263, 30, 8, TFT_RED);
}
else{
  tft.fillCircle(263, 30, 8, TFT_GREEN);
}
}

//***********************************************************************************************
void drawBar (int nPer){

  if(nPer < LastPercent){
    tft.fillRect(15, 5 + (180-LastPercent), 30, LastPercent - nPer,  BACKCOLOR);     
  }
  else{
    tft.fillRect(15, 5 + (180-nPer), 30, nPer - LastPercent,  BARCOLOR);
  }    
  LastPercent = nPer;  
  
}

void drawBar1 (int nPer1){

  if(nPer1 < LastPercent1){
    tft.fillRect(270, 5 + (180-LastPercent1), 30, LastPercent1 - nPer1,  BACKCOLOR);     
  }
  else{
    tft.fillRect(270, 5 + (180-nPer1), 30, nPer1 - LastPercent1,  BARCOLOR);
  }    
  LastPercent1 = nPer1;  
  
}
void drawBar2 (int nPer2){

  if(nPer2 < LastPercent2){
    tft.fillRect(5 + (160-LastPercent2), 200 , LastPercent2 - nPer2, 30,  BACKCOLOR);     
  }
  else{
    tft.fillRect(5 + (160-nPer2), 200 , nPer2 - LastPercent2, 30,  BARCOLOR);
  }    
  LastPercent2 = nPer2;  
  
}

void drawBar3 (int nPer3){

  if(nPer3 < LastPercent3){
    tft.fillRect(160 + (160-LastPercent3), 200, LastPercent3 - nPer3, 30,  BACKCOLOR);     
  }
  else{
    tft.fillRect(160 + (160-nPer3), 200, nPer3 - LastPercent3,  30,  BARCOLOR);
  }    
  LastPercent3 = nPer3;  
  
}
//***********************************************************************************************
    
