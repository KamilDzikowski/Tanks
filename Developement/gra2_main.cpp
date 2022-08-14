#include <allegro.h>
#include <math.h>
int main()
{
    double pozycja_x,pozycja_y,predkosc,koniec,kat, pozycja_x2,pozycja_y2,predkosc2,kat2;
    double pocisk_x[10],pocisk_y[10],pocisk_kat[10],pocisk_x2[10],pocisk_y2[10],pocisk_kat2[10];
    int strzal[10],strzal2[10];
    int n,x,l,m,y,res,punkty=0,punkty2=0;
	allegro_init();
	set_color_depth(desktop_color_depth());
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 550, 0, 0);
	install_timer();
	install_keyboard();
	install_mouse();
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
    set_volume( 255, 255 );
    SAMPLE * dzwiek = NULL;
    SAMPLE * dzwiek_z = NULL;
    SAMPLE * dzwiek_p = NULL;
    dzwiek = load_sample( "start2.wav" );
    dzwiek_z = load_sample( "zwyciestwo.wav" );
    dzwiek_p = load_sample( "przegrana.wav" );
    SAMPLE * wybuchy = NULL;
    wybuchy = load_sample( "wybuch.wav" );
    BITMAP * obrazek = load_bmp( "czolg.bmp", default_palette );
    BITMAP * logo = load_bmp( "logo.bmp", default_palette );
    BITMAP * obrazek2 = load_bmp( "czolg2.bmp", default_palette );
    BITMAP * wybuch0 = load_bmp( "wybuch0.bmp", default_palette );
    BITMAP * wybuch = load_bmp( "wybuch.bmp", default_palette );
    BITMAP * wybuch2 = load_bmp( "wybuch2.bmp", default_palette );
    BITMAP * wybuch3 = load_bmp( "wybuch3.bmp", default_palette );
    BITMAP * pocisk = load_bmp( "pocisk.bmp", default_palette );
    BITMAP * pocisk2 = load_bmp( "pocisk2.bmp", default_palette );
    BITMAP * zwyciestwo = load_bmp( "zwyciestwo.bmp", default_palette );
    BITMAP * boom = load_bmp( "boom.bmp", default_palette );
    BITMAP * bufor = create_bitmap( 1000, 1000 );
    play_sample( dzwiek, 255, 127, 1500, 0 );
    blit( logo, screen, 0,0, 0,0, logo->w, logo->h);
    rest(1800);                                                                                               
    
    while(!key[KEY_ESC]&&punkty<3&&punkty2<3)
    {
                                             n=0;
                                             x=0;
                                             l=0;
                                             m=0;
                                             y=0;
                                             pozycja_x = 900.0;
                                             pozycja_y = 100.0;
                                             predkosc = 0;
                                             koniec=0;
                                             kat = 0.0;
                                             pozycja_x2 = 100.0;
                                             pozycja_y2 = 400.0;
                                             predkosc2 = 0;
                                             kat2 = 0.0;
    for(int i=0;i<10;i++)
    {
            strzal[i]=0;
            pocisk_x[i]=0;
            pocisk_y[i]=0;
            pocisk_kat[i]=0;
            pocisk_x2[i]=0;
            pocisk_y2[i]=0;
            pocisk_kat2[i]=0;
    }
    clear_to_color( screen, makecol(0,0,0));
    
	while (!key[KEY_ESC]&&koniec!=1) 
    {
          clear_to_color( bufor, makecol(0,0,0));
          rect( bufor, 0, 0, 999, 999, makecol( 255,255,255));
          rect( bufor, 0, 0, 100, 100, makecol( 255,255,255));
          circlefill( bufor, 500, 500, 50, makecol( 255, 255, 255 ) );
          circlefill( bufor, 200, 800, 50, makecol( 255, 255, 255 ) );
          circlefill( bufor, 800, 200, 50, makecol( 255, 255, 255 ) );
          circlefill( bufor, 200, 200, 50, makecol( 255, 255, 255 ) );
          circlefill( bufor, 800, 800, 50, makecol( 255, 255, 255 ) );
          if( key[ KEY_LEFT ] ) kat -= 0.4;
          if( key[ KEY_RIGHT ] ) kat += 0.4;
          if( key[ KEY_UP ] ) predkosc += 0.01;
          if( key[ KEY_DOWN ] ) predkosc -= 0.01;
          if( predkosc > 5 ) predkosc = 5;
          if( predkosc <- 3 ) predkosc =- 3;
          if( key[ KEY_A ] ) kat2 -= 0.4;
          if( key[ KEY_D ] ) kat2 += 0.4;
          if( key[ KEY_W ] ) predkosc2 += 0.01;
          if( key[ KEY_S ] ) predkosc2 -= 0.01;
          if( predkosc2 > 5 ) predkosc2 = 5;
          if( predkosc2 <- 3 ) predkosc2 =- 3;
          predkosc *= 0.99;
          pozycja_x += predkosc * cos(( kat * M_PI )/180.0 );
          pozycja_y += predkosc * sin(( kat * M_PI )/180.0 );
          predkosc2 *= 0.99;
          pozycja_x2 += predkosc2 * cos(( kat2 * M_PI )/180.0 );
          pozycja_y2 += predkosc2 * sin(( kat2 * M_PI )/180.0 );
          if(pozycja_x>960) pozycja_x=960;
          if(pozycja_x<0) pozycja_x=0;
          if(pozycja_y<0) pozycja_y=0;
          if(pozycja_y>960) pozycja_y=960;
          if(pozycja_x2>960) pozycja_x2=960;
          if(pozycja_x2<0) pozycja_x2=0;
          if(pozycja_y2<0) pozycja_y2=0;
          if(pozycja_y2>960) pozycja_y2=960;
          if(pozycja_y<100&&pozycja_x<100) predkosc*=-1;
          if(pozycja_y2<100&&pozycja_x2<100) predkosc2*=-1;
          rotate_sprite(bufor,obrazek,( int ) round( pozycja_x ),( int ) round( pozycja_y ), ftofix(( kat * 255 ) / 360.0 ) );
          rotate_sprite(bufor,obrazek2,( int ) round( pozycja_x2 ),( int ) round( pozycja_y2 ), ftofix(( kat2 * 255 ) / 360.0 ) );
          if(sqrt((pozycja_x2-pozycja_x)*(pozycja_x2-pozycja_x)+(pozycja_y2-pozycja_y)*(pozycja_y2-pozycja_y))<50)
          {
                                                                                                                 predkosc*=-2;
                                                                                                                 predkosc2*=-2;
                                                                                                                 play_sample( dzwiek_p, 255, 127, 1000, 0 );
          }
          if((sqrt((pozycja_x2-475)*(pozycja_x2-475)+(pozycja_y2-485)*(pozycja_y2-485))<70)||(sqrt((pozycja_x2-175)*(pozycja_x2-175)+(pozycja_y2-185)*(pozycja_y2-185))<70)||(sqrt((pozycja_x2-775)*(pozycja_x2-775)+(pozycja_y2-785)*(pozycja_y2-785))<70)||(sqrt((pozycja_x2-175)*(pozycja_x2-175)+(pozycja_y2-785)*(pozycja_y2-785))<70)||(sqrt((pozycja_x2-775)*(pozycja_x2-775)+(pozycja_y2-185)*(pozycja_y2-185))<70))
          {
                                                                                          predkosc2*=-2;
                                                                                          play_sample( dzwiek_p, 255, 127, 1000, 0 );
          }
          if((sqrt((pozycja_x-475)*(pozycja_x-475)+(pozycja_y-485)*(pozycja_y-485))<70)||(sqrt((pozycja_x-175)*(pozycja_x-175)+(pozycja_y-185)*(pozycja_y-185))<70)||(sqrt((pozycja_x-775)*(pozycja_x-775)+(pozycja_y-785)*(pozycja_y-785))<70)||(sqrt((pozycja_x-175)*(pozycja_x-175)+(pozycja_y-785)*(pozycja_y-785))<70)||(sqrt((pozycja_x-775)*(pozycja_x-775)+(pozycja_y-185)*(pozycja_y-185))<70))
          {
                                                                                          predkosc*=-2;
                                                                                          play_sample( dzwiek_p, 255, 127, 1000, 0 );
          } 
           while(key[ KEY_SPACE ] )
           {
                   
                   pocisk_x[n]=pozycja_x+10;
                   pocisk_y[n]=pozycja_y+15;
                   pocisk_kat[n]=kat;
                   strzal[n]=1;
                   if(x==0) n++;
                   x=1;
           } 
           while(key[ KEY_Q ] )
           {
                   
                   pocisk_x2[m]=pozycja_x2+10;
                   pocisk_y2[m]=pozycja_y2+15;
                   pocisk_kat2[m]=kat2;
                   strzal2[m]=1;
                   if(y==0) m++;
                   y=1;
           }
           x=0;
           y=0;
           if(n>=10) n=0;
           if(m>=10) m=0;
           for(int i=0;i<10;i++)
           { 
                   if(strzal[i]==1)
                   {
                                   pocisk_x[i]+=cos(( pocisk_kat[i] * M_PI ) / 180.0 )*2;
                                   pocisk_y[i]+=sin(( pocisk_kat[i] * M_PI ) / 180.0 )*2;  
                                   rotate_sprite(bufor,pocisk, round( pocisk_x[i]+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*3 ),round( pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*3), ftofix(( pocisk_kat[i] * 255 ) / 360.0 ) );                                                                                     
                   }
                   if(strzal2[i]==1)
                   {
                                    pocisk_x2[i]+=cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*2;
                                    pocisk_y2[i]+=sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*2;  
                                    rotate_sprite(bufor,pocisk, round( pocisk_x2[i]+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*3 ),round( pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*3), ftofix(( pocisk_kat2[i] * 255 ) / 360.0 ) );                   
                   }
                   if(sqrt((pocisk_x2[i]-485.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)*(pocisk_x2[i]-485.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-500)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-500))<50) strzal2[i]=0;
                   if(sqrt((pocisk_x2[i]-185.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)*(pocisk_x2[i]-185.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-200)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-200))<50) strzal2[i]=0;
                   if(sqrt((pocisk_x2[i]-785.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)*(pocisk_x2[i]-785.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-800)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-800))<50) strzal2[i]=0;
                   if(sqrt((pocisk_x2[i]-185.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)*(pocisk_x2[i]-185.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-800)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-800))<50) strzal2[i]=0;
                   if(sqrt((pocisk_x2[i]-785.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)*(pocisk_x2[i]-785.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-200)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-200))<50) strzal2[i]=0;
                   if(sqrt((pocisk_x[i]-485.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)*(pocisk_x[i]-485.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-500)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-500))<50) strzal[i]=0;
                   if(sqrt((pocisk_x[i]-185.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)*(pocisk_x[i]-185.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-200)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-200))<50) strzal[i]=0;
                   if(sqrt((pocisk_x[i]-785.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)*(pocisk_x[i]-785.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-800)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-800))<50) strzal[i]=0;
                   if(sqrt((pocisk_x[i]-185.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)*(pocisk_x[i]-185.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-800)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-800))<50) strzal[i]=0;
                   if(sqrt((pocisk_x[i]-785.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)*(pocisk_x[i]-785.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-200)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-200))<50) strzal[i]=0;
                   if(sqrt((pocisk_x2[i]-10.0+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-pozycja_x)*(pocisk_x2[i]-10+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-pozycja_x)+(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-15-pozycja_y)*(pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI ) / 180.0 )*15-15-pozycja_y))<25)
                   {
                                                                                                     rotate_sprite(screen,pocisk2, round( pocisk_x2[i]+cos(( pocisk_kat2[i] * M_PI ) / 180.0 )*3 ),round( pocisk_y2[i]+sin(( pocisk_kat2[i] * M_PI)/180.0)*3),ftofix((pocisk_kat2[i]*255)/360.0));   
                                                                                                     blit( boom, screen, 0,0, 340,450, boom->w, boom->h);
                                                                                                     play_sample( wybuchy, 255, 127, 1000, 0 );
                                                                                                     rotate_sprite(screen,wybuch0,( int ) round( pozycja_x+8 ),( int ) round( pozycja_y+3 ), ftofix(( kat * 255 ) / 360.0 ) );
                                                                                                     rest(300);
                                                                                                     rotate_sprite(screen,wybuch,( int ) round( pozycja_x ),( int ) round( pozycja_y ), ftofix(( kat * 255 ) / 360.0 ) );
                                                                                                     rest(300);
                                                                                                     rotate_sprite(screen,wybuch2,( int ) round( pozycja_x-12 ),( int ) round( pozycja_y-7 ), ftofix(( kat * 255 ) / 360.0 ) );
                                                                                                     rest(300);
                                                                                                     rotate_sprite(screen,wybuch3,( int ) round( pozycja_x-25 ),( int ) round( pozycja_y-15 ), ftofix(( kat * 255 ) / 360.0 ) );
                                                                                                     rest(2000);
                                                                                                     punkty2++;
                                                                                                     koniec=1;
                                                                                                     break;
                   } 
                   if(sqrt((pocisk_x[i]-10.0+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15-pozycja_x2)*(pocisk_x[i]-10+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*15-pozycja_x2)+(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-15-pozycja_y2)*(pocisk_y[i]+sin(( pocisk_kat[i] * M_PI ) / 180.0 )*15-15-pozycja_y2))<25)
                   {
                                                                                                     rotate_sprite(screen,pocisk2, round( pocisk_x[i]+cos(( pocisk_kat[i] * M_PI ) / 180.0 )*3 ),round( pocisk_y[i]+sin(( pocisk_kat[i] * M_PI) / 180.0 )*3), ftofix(( pocisk_kat[i] * 255 ) / 360.0 ) );   
                                                                                                     blit( boom, screen, 0,0, 340,450, boom->w, boom->h);
                                                                                                     play_sample( wybuchy, 255, 127, 1000, 0 );
                                                                                                     rotate_sprite(screen,wybuch0,( int ) round( pozycja_x2+8 ),( int ) round( pozycja_y2+3 ), ftofix(( kat2 * 255 ) / 360.0 ) );
                                                                                                     rest(200);
                                                                                                     rotate_sprite(screen,wybuch,( int ) round( pozycja_x2 ),( int ) round( pozycja_y2 ), ftofix(( kat2 * 255 ) / 360.0 ) );
                                                                                                     rest(200);
                                                                                                     rotate_sprite(screen,wybuch2,( int ) round( pozycja_x2-12 ),( int ) round( pozycja_y2-7 ), ftofix(( kat2 * 255 ) / 360.0 ) );
                                                                                                     rest(200);
                                                                                                     rotate_sprite(screen,wybuch3,( int ) round( pozycja_x2-25 ),( int ) round( pozycja_y2-15 ), ftofix(( kat2 * 255 ) / 360.0 ) );
                                                                                                     rest(2000);
                                                                                                     punkty++;
                                                                                                     koniec=1;
                                                                                                     break;
                   } 
           }
           textprintf(bufor,font,25,40,makecol(255,0,0),"Wynik:",x);
           textprintf_ex(bufor,font, 30, 70, makecol(0,150,0), - 1, "%d", punkty);
           textprintf_ex(bufor,font, 50, 70, makecol(0,120,255), - 1, "%d", punkty2);
           blit( bufor, screen, 0,0, 0,0, 1000, 1000);
    }
}
	clear_keybuf();
	return 0;
}
END_OF_MAIN()
