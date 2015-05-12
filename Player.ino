

void updPlayer(Figther * player,Figther * other);
void drwPlayer(Figther * player);
void movePlayer(Figther * player);
void movePlayerSlave();
boolean playerIsAttack(Figther player);
void gestionAttack(Figther * pAttack, Figther * pDef);
boolean addToCombo(Figther *player, byte moveTouch);
void playerFall(byte chance,Figther *pDef);

boolean stopGame=false;

void initPlayer()
{
  initPlayer(true);
}

void initPlayer(boolean isStartGame)
{
  Player1.currentState = 0;
  Player1.currentSprite = 0;
  Player1.posX = 8;
  Player1.posY = 47;
  Player1.vx = 0;
  Player1.vy = 0;
  Player1.life = 100;
  Player1.oldLife = 100;
  Player1.cadance = 3;
  Player1.damage = 5;
  Player1.dir = NOFLIP;
  Player1.timeAttack = TIME_ATTACK;
  Player1.isJump = false;
  
  Player2.currentState = 0;
  Player2.currentSprite = 0;
  Player2.posX = 78;
  Player2.posY = 47;
  Player2.vx = 0;
  Player2.vy = 0;
  Player2.life = 100;
  Player2.oldLife = 100;
  Player2.cadance = 2;
  Player2.damage = 5;
  Player2.dir = FLIPH;
  Player2.timeAttack = TIME_ATTACK;
  Player2.isJump = false;
  
  if(isStartGame)
  {  
    Player1.cptVictory = 0;
    Player2.cptVictory = 0;
  }
  stopGame = true;
  
  //for slave 
  bt_up = false;
  bt_down = false;
  bt_left = false;
  bt_right = false;
  bt_a = false;
  bt_b = false;
}

void updatePlayer()
{
   
   switch(stateFight)
  {
    case 0 :
       //3, 2, 1 Fight! 

    break;
    case 1 :
       //Fight
       if(stateGame != 2)
        {
          movePlayer(&Player1);
        }
    break;
    case 2 :
       //Figther KO 
    case 3 :
       //Time UP 
       if(stopGame)
       {
         if(Player1.life != Player2.life)
         {
           if(Player1.life>Player2.life)
           {
             Player1.cptVictory++;
           }
           else
           {
             Player2.cptVictory++;
           }
         }
         stopGame=false;
       } 
       
      
    break;
    case 4 : 
    //end Player KO screen
      if(Player1.cptVictory == 3 || Player2.cptVictory == 3 ) 
      {
        if(stateGame == 2)
        {
          Player1.cptVictory = 0;
          Player2.cptVictory = 0;
          restartCombat();
        }
        else 
        {
          stateGame = 4;
        }
      }
      else 
      {
         restartCombat();
      }
    break;
  }
  
  updPlayer(&Player1,&Player2);
  updPlayer(&Player2,&Player1);
  
  //update dir player 
  if(Player1.posX<Player2.posX)
  {
    Player1.dir = NOFLIP;
    Player2.dir = FLIPH;
  }
  else 
  {
    Player1.dir = FLIPH;
    Player2.dir = NOFLIP;
  }
  
  if(playerIsAttack(Player1))
  {
    gestionAttack(&Player1,&Player2);
    
  }
  if(playerIsAttack(Player2)) 
  {
    gestionAttack(&Player2,&Player1);
  }
}

void gestionAttack(Figther * pAttack, Figther * pDef)
{
  return;
  /*
    // IDL : 0 ,run : 1, kick : 2, punchLeft : 3, punchRight : 4,  duck1 : 5, duck1Kick : 6,jump1 : 7,jumpKick1 : 8 , dead1 : 9
    byte damage = 0;
    if(pAttack->currentState == 3 || pAttack->currentState == 4)
    { 
      //4 px dist touch
      if(gb.collideRectRect(pAttack->posX - 4, pAttack->posY - 14, 14, 3, pDef->posX, (pDef->posY - pDef->height), 6, pDef->height))
      {
         damage = 5;
      }
    }
    else if(pAttack->currentState == 2 || pAttack->currentState == 8)
    {
      byte offsetY = 12;
      if(pAttack->isJump)
      {
        offsetY = 0;
      }
      //6 px dist touch
      if(gb.collideRectRect(pAttack->posX - 6, pAttack->posY - offsetY, 18, 3, pDef->posX, (pDef->posY - pDef->height), 6, pDef->height))
      {
        damage = 8;
        pAttack->timeAttack--;
        if(pAttack->currentState == 8)
        {
          playerFall(2,pDef);
        }
      }
    }
    else if(pAttack->currentState == 6)
    {
      if(gb.collideRectRect(pAttack->posX - 6, pAttack->posY - 3, 18, 3, pDef->posX, (pDef->posY - pDef->height), 6, pDef->height))
      {
        damage = 3;
        playerFall(2,pDef);
      }
    }
    
    
    if(damage)
    {
      if(pDef->isDef>0)
      {
         pAttack->timeNextAttack += 10;
        damage = damage/2;
      }
      
      pDef->life -= damage;
      if(pDef->life <0)
      {
        pDef->life = 0;
        playsoundfx(2,0);
      }
      //gestion des colisions
      if(pDef->dir == NOFLIP)
      {
        //Pdef a gauche 
        if(pDef->life > 0)
        {
          pDef->vx = -SPEED_RUN;
        }
        else 
        {
          pDef->vx = -SPEED_RUN*6;
          pDef->vy = -SPEED_RUN*6;
        }
      }
      else 
      {
        //Pdef a droite 
        if(pDef->life > 0)
        {
          pDef->vx = SPEED_RUN;
        }
        else 
        {
          pDef->vx = SPEED_RUN*6;
          pDef->vy = -SPEED_RUN*6;
        }
      }
    }*/
}

void playerFall(byte chance,Figther *pDef)
{
  if(random(0,chance) == 0)
  {
    pDef->currentState = 9;
    pDef->timeFall = TIME_FALL;
  }
}

void drawPlayer()
{
  drwPlayer(&Player1);
  drwPlayer(&Player2);
  //  gb.display.print(Player1.currentState);
  
  byte nbBarre = lifeTopixel(Player1.life);
  for(byte i = 0;i<nbBarre ;i++)
  {
    //vie P1
    gb.display.drawLine(5 +(i*2), 1 ,5 +(i*2) , 4);
  }
  
  nbBarre = lifeTopixel(Player1.life);
  for(byte i = 0;i<nbBarre ;i++)
  {
    //vie P1
    gb.display.drawLine(78 -(i*2), 1 ,78 -(i*2) , 4);
  }
  
  
  /*
  for(byte i=0;i<Player1.cptVictory;i++)
  {
    //2 - 7 - 12
    gb.display.fillRect((i*5 + 2) , 8, 2 , 2);
  }
  
  for(byte i=0;i<Player2.cptVictory;i++)
  {
    //2 - 7 - 12
    gb.display.fillRect(80 - (i*5) , 8, 2 , 2);
  }*/
}

byte lifeTopixel(byte life)
{
  return (life/6);
}

void drwPlayer(Figther * player)
{
  /* if(player->ayouken.timeLive > 0)
  {
    gb.display.drawBitmap(player->ayouken.posX,player->ayouken.posY,(player->ayouken.timeLive>(TIME_LIVE_AYOUKEN/3))? player->ayouken.sprites.sprite1 : player->ayouken.sprites.sprite2,0,player->ayouken.dir );
  }*/
  byte dst_w = pgm_read_byte(&player_sprites[((player->currentState*2) + player->currentSprite)][2]);
  byte dst_h = pgm_read_byte(&player_sprites[((player->currentState*2) + player->currentSprite)][3]);
  
  drawBitmapCustom(player,
  ((player->dir == NOFLIP)? player->posX : (player->posX - dst_w)) ,
  (player->posY - dst_h) , 
  SpritesP1,
  SpritesP1Mask,
  0,
  player->dir);
}

#define SEUIL_MIN_MOVE 0.1
void updPlayer(Figther * player,Figther * other)
{
  if(gb.frameCount%player->cadance == 0)
  {
    player->currentSprite++;
    player->currentSprite = player->currentSprite%NB_SPRITE_STATE;
  }
  
  if(player->timeNextAttack>0)
  {
    player->timeNextAttack--;
  }
  if(player->timeFall>0)
  {
    player->timeFall--;
  }
  
  /*if(player->ayouken.timeLive > 0)
  {
    (&player->ayouken)->posX += (player->ayouken.dir == NOFLIP)? VITT_AYOUKEN : -VITT_AYOUKEN;
    (&player->ayouken)->timeLive--;
  }*/
  if(player->timeAttack>0)
  {
    player->timeAttack--;
  }
  
  if(player->isDef>0)
  {
    player->isDef--;
  }
  
  if(player->life>0)
  {
    if(player->timeAttack==0 && player->currentState != 0 && player->currentState != 5  && player->currentState != 9 && player->timeFall ==0)
    {
      // IDL : 0 ,run : 1, jump : 2, punchLeft : 3
      if(player->currentState == 6)
        player->currentState = 5;
      else if(player->isJump)
        player->currentState = 7;
      else if(player->vx<SEUIL_MIN_MOVE && player->vx>-SEUIL_MIN_MOVE)
        player->currentState = 0;
      else 
        player->currentState = 1;
      
    }
  }
  else 
  {
    player->currentState = 9;
  }
  
  byte play_w = pgm_read_byte(&player_sprites[((player->currentState*2) + player->currentSprite)][2]);
  byte play_h = pgm_read_byte(&player_sprites[((player->currentState*2) + player->currentSprite)][3]);
  
  byte other_w = pgm_read_byte(&player_sprites[((other->currentState*2) + other->currentSprite)][2]);
  byte other_h = pgm_read_byte(&player_sprites[((other->currentState*2) + other->currentSprite)][3]);
  
  
  if( ((player->vx>0 && player->dir == NOFLIP) || (player->vx<0 && player->dir != NOFLIP))  && gb.collideRectRect(player->posX, (player->posY - play_h), play_w, play_h, other->posX, (other->posY - other_h), other_w, other_h))
  {
    player->vx = 0;
  }
  
  if(!player->isJump)
  {
    if(player->vx!=0)
    {
      player->posX += player->vx;
      player->vx = player->vx*0.4;//on ralentie rapidement
    }
    else if(player->vx<SEUIL_MIN_MOVE && player->vx>-SEUIL_MIN_MOVE)
    {
      player->vx = 0;
    }
  }
  else 
  {
    if(player->vy<-1.2)
    {
      player->vy *= 0.9;
      player->posY += player->vy;
    }
    else
    {
      if(player->vy<0) player->vy = -player->vy;
      player->vy *= 1.3;
      player->posY += player->vy;
    }
    player->posX += player->vx;
    player->vx = player->vx*0.9;//on ralentie rapidement
    
    if(player->posY>= GROUND_Y)
    {      
      player->posY = GROUND_Y;
      player->isJump = false;
      player->vy = 0;
      player->vx = 0;
      player->timeAttack = 0;
    }
  }
  
  if(player->posX<0)
  {
    player->posX = 0;
  }
  else if((player->posX) >84)
  {
    player->posX = 84;
  }
}



void movePlayerSlave()
{
   if(gb.buttons.repeat(BTN_RIGHT, 1))
  {
    bt_right = true;
  }
  else if(gb.buttons.repeat(BTN_LEFT, 1))
  {
    bt_left = true;
  }
  if(gb.buttons.pressed(BTN_UP))
  {
    bt_up = true;
  }
  else if(gb.buttons.repeat(BTN_DOWN, 1))
  {
    bt_down = true;
  }
  
  if(gb.buttons.pressed(BTN_A))
  {
    playsoundfx(1,0);
     bt_a = true;
  }
  else if(gb.buttons.pressed(BTN_B))
  {
    playsoundfx(0,0);
    bt_b = true;
  }
}

void movePlayer(Figther * player)
{
  if(gb.buttons.repeat(BTN_RIGHT, 1))
  {
    rightFigther(player);
  }
  else if(gb.buttons.repeat(BTN_LEFT, 1))
  {
    leftFigther(player);
  }
  if(gb.buttons.pressed(BTN_UP))
  {
    highFigther(player);
  }
  else if(gb.buttons.repeat(BTN_DOWN, 1))
  {
    bottomFigther(player);
  }
  
  if(gb.buttons.pressed(BTN_A))
  {
    punchFigther(player);
  }
  else if(gb.buttons.pressed(BTN_B))
  {
    kickFigther(player);
  }
}

void moveIAPlayer(Figther * player,Figther * human)
{
  //return;
  if(stateFight == 1)
  {
    
    byte rdm1 = random(0,100);
    if(rdm1 <40)
    {
      rightFigther(player);
    }
    else if(rdm1 <50)
    {
       leftFigther(player);
    }
    
    return;
    
    
    byte isFireBall = 0;
    byte isCrunch = 0;
    byte fuiteStrategique = 0;
    byte dist = abs(player->posX - human->posX);
    
    //Brain storming
    if(human->currentState == 5 || human->currentState == 6 || human->currentState == 9)
    {
      isCrunch = 5;
    }
    int8_t diffLife = player->life - human->life;
    /*if(human->ayouken.timeLive>0)
    {
      isFireBall = 5;
    }*/
    if(isCrunch>0 && diffLife>0)
    {
      fuiteStrategique = 10;
    }
    
    byte rdm = random(0,100);
    
    //Attack ?
    if(rdm <=(20 - isCrunch + diffLife - dist))
    {
      punchFigther(player);
    }
    else if(rdm >65 && rdm <90 - dist +diffculty)
    {
      kickFigther(player);
    }
    else if(rdm >45 && rdm <(48 + isCrunch + fuiteStrategique - diffLife + isFireBall))
    {
      bottomFigther(player);
      if(player->dir == NOFLIP) rightFigther(player);
      else leftFigther(player);
      punchFigther(player);
    }
    
    //Move
    if(rdm >(95-fuiteStrategique+diffLife -diffculty ))
    {
      //backward
      if(player->dir != NOFLIP) rightFigther(player);
      else leftFigther(player);
    }
    else if(rdm <=(40+isCrunch+diffLife-fuiteStrategique+diffculty))
    {
      if(player->dir == NOFLIP) rightFigther(player);
      else leftFigther(player);
    }
    if(rdm >19 && rdm <25 + isFireBall)
    {
      highFigther(player);
    }
    else if(rdm >(39-isCrunch+diffLife) && rdm <45+isCrunch)
    {
      bottomFigther(player);
    }
  }
}

// IDL : 0 ,run : 1, jump : 3, punchLeft : 4
void leftFigther(Figther * player)
{
  if(player->life==0)
    return;
  //if(addToCombo(player,((player->dir == NOFLIP)? 4 : 3)))
    //return;
  if(!player->isJump)
  {
    
    if(player->dir == NOFLIP)
    {
      //recule
      player->isDef = TIME_DEF;
      
      if(player->timeNextAttack>0)
        return;
      player->vx =  -SPEED_RUN/2;
    }
    else 
    {
      
      if(player->timeNextAttack>0)
        return;
      //avance
      player->vx =  -SPEED_RUN;
    }
  
    if(!playerIsAttack(*player)) player->currentState = 1;
  }
  else 
  {
    
    if(player->timeNextAttack>0)
      return;
    if(player->vx>-SPEED_RUN) player->vx -= 0.1;
  }
  
}

// IDL : 0 ,run : 1, jump : 3, punchLeft : 4
void rightFigther(Figther * player)
{
  if(player->life==0)
    return;
  //if(addToCombo(player,((player->dir == NOFLIP)? 3 : 4)))
    //return;
  if(!player->isJump)
  {
    if(player->dir == FLIPH)
    {
      //recule
      player->isDef = TIME_DEF;
      
      if(player->timeNextAttack>0)
        return;
      player->vx =  SPEED_RUN/2;
    }
    else 
    {
      if(player->timeNextAttack>0)
        return;
      //avance
      player->vx =  SPEED_RUN;
    }
    if(!playerIsAttack(*player))player->currentState = 1;
  }
  else 
  {
      if(player->timeNextAttack>0)
        return;
    if(player->vx<SPEED_RUN) player->vx += 0.1;
  }
}

void highFigther(Figther * player)
{
  if(player->timeNextAttack>0)
    return;
  if(player->life==0)
    return;
  if(addToCombo(player,1))
    return;
 if(!player->isJump)
 {
    player->currentState = 2;
    player->isJump = true;
    player->vy = -SPEED_RUN;
 }
}

void bottomFigther(Figther * player)
{
  return;
  if(player->life==0)
    return;
  if(player->timeNextAttack>0)
    return;
  if(addToCombo(player,2))
    return;
  player->currentState = 5;
}

// IDL : 0 ,run : 1, jump : 2, punchLeft : 3
void punchFigther(Figther * player)
{
  if(player->life==0)
    return;
  if(player->timeNextAttack>0)
    return;
  playsoundfx(1,0);
 
 if(!player->isJump)
  {
    player->currentState = 3;
    player->timeAttack = TIME_ATTACK;
  }

  player->timeNextAttack = TIME_ATTACK+1; // puch are fast 
}

void kickFigther(Figther * player)
{
  return;
  if(player->life==0)
    return;
  if(player->timeNextAttack>0)
    return;
  playsoundfx(0,0);
  if(addToCombo(player,6))
    return;
  if(player->currentState == 5)
 {
   player->currentState = 6;
   player->timeAttack = TIME_ATTACK;
 }
 else  if(!player->isJump)
 {
  player->timeAttack = TIME_ATTACK;
  player->currentState = 2;
 }
 else 
 {
    player->timeAttack = TIME_ATTACK*4;
  player->currentState = 2;
 }
  player->timeNextAttack = TIME_ATTACK+3; // Kick are slow 
}


boolean playerIsAttack(Figther player)
{
  return (player.timeAttack>0);
}

boolean addToCombo(Figther *player, byte moveTouch) // moveTouch : 1=>up, 2=>down, 3=>forward, 4=>backward, 5=>A, 6=>B
{
  if(player->combo[0] == moveTouch)
    return false;
  for(byte i=(NB_MOVE_SAVE-1);i>0;i--)
  {
    player->combo[i] = player->combo[i-1];
  }
  player->combo[0] = moveTouch;
  
  /*
  if(player->combo[0] == 5 && player->combo[1] == 3 && player->combo[2] == 2 )
  {
    //gb.popup(F("AYOUKEN"),5);
    //test combo et fire ball
    player->currentState = 10;
    (&player->ayouken)->posX = player->posX;
    (&player->ayouken)->posY = (player->posY - 8);
    (&player->ayouken)->dir = player->dir;
    player->timeNextAttack = TIME_ATTACK+5; //fire ball are very slow
    return true;
  }*/
  
  return false;
}

const uint8_t soundfx[3][8] = {
    {0,22,54,1,7,0,7,10}, // coup de pied {1,14,25,6,1,4,1,12}
    {0,22,48,1,7,5,7,10}, // coup de poing{1,42,31,2,1,3,1,22}
    {0,24,55,1,0,0,7,7} //mort selon jerom
};

void playsoundfx(uint8_t fxno, uint8_t channel) {
    gb.sound.command(0,soundfx[fxno][6],0,channel);
    // set volume
    gb.sound.command(1,soundfx[fxno][0],0,channel);
    // set waveform
    gb.sound.command(2,soundfx[fxno][5],-soundfx[fxno][4],channel);
    // set volume slide
    gb.sound.command(3,soundfx[fxno][3],soundfx[fxno][2]-58,channel);
    // set pitch slide
    gb.sound.playNote(soundfx[fxno][1],soundfx[fxno][7],channel);
    // play note
}



/*
void drawBitmap(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int8_t src_x, int8_t src_y, const uint8_t *bitmap) {
  int8_t src_w = pgm_read_byte(bitmap);
  //int8_t src_h = pgm_read_byte(bitmap + 1);
  bitmap += 2;
  int8_t byteWidth = (src_w + 7) / 8;
  for (int8_t dy = 0, j = src_y; dy < dst_h; dy++, j++)
    for (int8_t dx = 0, i = src_x; dx < dst_w; dx++, i++)
    {
      if (pgm_read_byte(bitmap + (j * byteWidth + i / 8)) & (B10000000 >> (i % 8)))
        gb.display.drawPixel(dst_x + dx, dst_y + dy);
    }
}*/

void drawBitmapMask(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int src_x, int src_y, const uint8_t *bitmap, const uint8_t *mask)
{
	uint8_t w = pgm_read_byte(bitmap);
	//uint8_t h = pgm_read_byte(bitmap + 1);
	bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
        mask = mask+2;

    int i, j, byteNum, bitNum, byteWidth = (w + 7) >> 3;
    
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
	uint8_t h = pgm_read_byte(bitmap + 1);
	bitmap = bitmap + 2; //add an offset to the pointer to start after the width and height
        mask = mask +2;
    int8_t i, j, //coordinates in the raw bitmap
            k, l, //coordinates in the rotated/flipped bitmap
            byteNum, bitNum, byteWidth = (w + 7) >> 3;

    rotation %= 4;

 
      for (int dy = 0, j = src_y; dy < dst_h; dy++, j++)
      {
        byteNum = i / 8;
        bitNum = i % 8;
        for (int dx = 0, i = src_x; dx < dst_w; dx++, i++)
        {
            if (pgm_read_byte(mask + j * byteWidth + byteNum) & (B10000000 >> bitNum)) {
              if (pgm_read_byte(bitmap + j * byteWidth + byteNum) & (B10000000 >> bitNum)) {
                     gb.display.setColor(BLACK);
              }
              else {
                   gb.display.setColor(WHITE);
               }
                switch (rotation) {
                    case NOROT: //no rotation
                        k = i;
                        l = j;
                        break;
                    case ROTCCW: //90° counter-clockwise
                        k = j;
                        l = w - i - 1;
                        break;
                    case ROT180: //180°
                        k = w - i - 1;
                        l = h - j - 1;
                        break;
                    case ROTCW: //90° clockwise
                        k = h - j - 1;
                        l = i;
                        break;
                }
                if (flip) {
                    flip %= 4;
                    if (flip & B00000001) { //horizontal flip
                        k = w - k;
                    }
                    if (flip & B00000010) { //vertical flip
                        l = h - l;
                    }
                }
                k += dst_x; //place the bitmap on the screen
                l += dst_y;
                gb.display.drawPixel(k, l);
            }
        }
    }
  gb.display.setColor(BLACK);
}


void drawBitmapCustom(Figther * play, byte dst_x, byte dst_y, const uint8_t *bitmap, const uint8_t *mask,uint8_t rotation, uint8_t flip)
{  
  //TODO mettre le currentState
  byte src_x = pgm_read_byte(&player_sprites[((play->currentState*2) + play->currentSprite)][0]);
  byte src_y = pgm_read_byte(&player_sprites[((play->currentState*2) + play->currentSprite)][1]);
  byte dst_w = pgm_read_byte(&player_sprites[((play->currentState*2) + play->currentSprite)][2]);
  byte dst_h = pgm_read_byte(&player_sprites[((play->currentState*2) + play->currentSprite)][3]);

// Serial.println(((play->currentCharater*2) +play->currentSprite));
 drawBitmapMask(dst_x, dst_y, dst_w, dst_h, src_x, src_y, bitmap, mask, rotation, flip);
}
