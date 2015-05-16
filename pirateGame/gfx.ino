
void drawBitmapMask(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int src_x, int src_y, const uint8_t *bitmap, const uint8_t *mask)
{
	uint8_t w = pgm_read_byte(bitmap);
	//uint8_t h = pgm_read_byte(bitmap + 1);
	bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
        mask = mask+2;

    int i, j, byteWidth = (w + 7) >> 3;
    
    for (int dy = 0, j = src_y; dy < dst_h; dy++, j++)
    {
      for (int dx = 0, i = src_x; dx < dst_w; dx++, i++)
      {
        if (pgm_read_byte(mask + (j * byteWidth + i / 8)) & (B10000000 >> (i % 8)))
        {
          if (pgm_read_byte(bitmap + (j * byteWidth + i / 8)) & (B10000000 >> (i % 8)))
          {
             gb.display.setColor(BLACK);
          }
          else {
                gb.display.setColor(WHITE);
          }
          gb.display.drawPixel(dst_x + dx, dst_y + dy);
        }
          
      }
    }
  gb.display.setColor(BLACK);

}
 
void drawBitmapMask(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int8_t src_x, int8_t src_y, const uint8_t *bitmap, const uint8_t *mask,uint8_t rotation, uint8_t flip)
{
	if((rotation == NOROT) && (flip == NOFLIP)){
		drawBitmapMask(dst_x,dst_y,dst_w,dst_h,src_x,src_y,bitmap,mask); //use the faster algorithm
		return;
	}
	uint8_t w = pgm_read_byte(bitmap);
	//uint8_t h = pgm_read_byte(bitmap + 1);
	bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
        mask = mask +2;
    int8_t i, j, //coordinates in the raw bitmap
            k, l, //coordinates in the rotated/flipped bitmap
            byteWidth = (w + 7) >> 3;

    rotation %= 4;

 
      for (int dy = 0, j = src_y; dy < dst_h; dy++, j++)
      {
        for (int dx = 0, i = src_x; dx < dst_w; dx++, i++)
        {
             if (pgm_read_byte(mask + (j * byteWidth + i / 8)) & (B10000000 >> (i % 8))){
              if (pgm_read_byte(bitmap + (j * byteWidth + i / 8)) & (B10000000 >> (i % 8))){
                gb.display.setColor(BLACK);
              }
              else {
                   gb.display.setColor(WHITE);
               }
                switch (rotation) {
                    case NOROT: //no rotation
                        k = dx;
                        l = dy;
                        break;
                    case ROTCCW: //90° counter-clockwise
                        k = dy;
                        l = dst_w - dx - 1;
                        break;
                    case ROT180: //180°
                        k = dst_w - dx - 1;
                        l = dst_h - dy - 1;
                        break;
                    case ROTCW: //90° clockwise
                        k = dst_w - dy - 1;
                        l = dx;
                        break;
                }
                if (flip) {
                    flip %= 4;
                    if (flip & B00000001) { //horizontal flip
                        k = dst_w - k;
                    }
                    if (flip & B00000010) { //vertical flip
                        l = dst_h - l;
                    }
                }
                k += dst_x; //place the bitmap on the screen
                l += dst_y;
                gb.display.drawPixel(k, l);
                Serial.print(k);
                Serial.print(" <-k l-> ");
                Serial.println(l);                
            }
        }
    }
  gb.display.setColor(BLACK);
}


void drawBitmapCustom(byte state,byte sprite, byte dst_x, byte dst_y,uint8_t rotation, uint8_t flip,byte numP)
{  
  
    byte src_x = 0;
    byte src_y = 0;
    byte dst_w = 0;
    byte dst_h = 0;
  if(numP == 0){
    src_x = pgm_read_byte(&player1_sprites[((state*2) + sprite)][0]);
    src_y = pgm_read_byte(&player1_sprites[((state*2) + sprite)][1]);
    dst_w = pgm_read_byte(&player1_sprites[((state*2) + sprite)][2]);
    dst_h = pgm_read_byte(&player1_sprites[((state*2) + sprite)][3]);
  }
  else {
    src_x = pgm_read_byte(&player2_sprites[((state*2) + sprite)][0]);
    src_y = pgm_read_byte(&player2_sprites[((state*2) + sprite)][1]);
    dst_w = pgm_read_byte(&player2_sprites[((state*2) + sprite)][2]);
    dst_h = pgm_read_byte(&player2_sprites[((state*2) + sprite)][3]);
   }

// Serial.println(((play->currentCharater*2) +play->currentSprite));
 drawBitmapMask(dst_x, dst_y, dst_w, dst_h, src_x, src_y, getSpriteSheetPlayer(1,false), getSpriteSheetPlayer(1,true), rotation, flip);
}

