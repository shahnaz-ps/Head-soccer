#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <cmath>
#include<fstream>

//shahnazPourbarghi-400100876
//kimiaRamezan-400101283

using namespace std;
void text(SDL_Renderer *renderer,int x,int y,const char * text,int font_size,int R,int G,int B, int A);void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );

int main( int argc, char * argv[] )
{

    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;

    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    SDL_Init( SDL_flags );

    SDL_CreateWindowAndRenderer( 1200, 700, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Clear the window with a black background
   // SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_Texture *goal1img;
    SDL_Texture *goal2img;

    goal1img = IMG_LoadTexture(m_renderer, "goal1.png");
    goal2img = IMG_LoadTexture(m_renderer, "goal2.png");

    SDL_Rect goal1,goal2;

    goal1.x=80,goal1.y=280,goal1.w=200,goal1.h=200;
    goal2.x=920,goal2.y=280,goal2.w=200,goal2.h=200;///x 950 bod


    SDL_RenderPresent( m_renderer );
    SDL_Event *e = new SDL_Event();
    double xmouse,ymouse;
    string name1="";
    string name2="";

    bool menu=true;
    bool type1=false, type2=false;
    bool quit1=false, quit2=false;
    bool capslock=false;
    bool setting=false;
    bool league=false;
    bool ball2=false, ball3=false, ball1=false;
    bool play=false;
    bool celebration=false;
    bool winner=false;
    bool run1=false, jump1=false;
    bool run2=false, jump2=false;
    double xplayer1=200, yplayer1=350, xplayer2=900, yplayer2=345;
    int xball=580, yball=220 , vxball=-5, vyball=5;
    int i=0;
    double vxplayer1=6, vxplayer2=6;
    int signvx1=1, signvx2=-1;
    double cntjump1=0, cntjump2=0;
    double cnttriplecone1=0, cnttriplecone2=0;
    double cntpunch1=0, cntpunch2=0;
    bool triplecone1=false, triplecone2=false;
    bool punch1=false, punch2=false;
    bool shoot1=false, shoot2=false;
    int cases=0;
    int signvxball=1;
    int ytemp;
    double zarib=1.7 , acceleration =30 , velocity=-200 , t=0;
    bool reflect1=false, reflect2=false;
    bool invisible=false;
    double cntinvisible=0;
    bool start=true;
    int powers1=rand()%4;
    int powers2=rand()%4;
    int rand1, rand2;
    int goalplayer1=0, goalplayer2=0;


    const Uint8* state = SDL_GetKeyboardState(NULL);


    while(true){

    while(menu){
                texture(m_renderer,0,0,"menu1.jpeg",1200,700);
                texture(m_renderer,530,500,"startbutton1.png",100,100);
                rect(m_renderer,150,100,300,100,255,255,255,1);
                rect(m_renderer,830,100,300,100,255,255,255,1);
                texture(m_renderer,100,500,"settingicon2.png",100,100);
                texture(m_renderer,900,500,"league.png",100,100);


                SDL_PollEvent(e);
                if(e->type == SDL_MOUSEBUTTONDOWN ){
                 xmouse=e->motion.x;
                 ymouse=e->motion.y;
                  if( xmouse>=150&&xmouse<=450&&ymouse>=100&&ymouse<=200&& !type1)
                    {
                        type1=true;
                    }
                    if( xmouse>=830&&xmouse<=1030&&ymouse>=100&&ymouse<=200&& !type2)
                    {
                        type2=true;
                    }
                    if( xmouse>=530&&xmouse<=630&&ymouse>=500&&ymouse<=600)
                    {
                    play=true;
                    menu=false;
                    }
                }

                if(type2&&!quit2)
                {
                    char ch='0';
                    if(e->type==SDL_KEYUP)
                    {
                        if(e->key.keysym.sym==SDLK_CAPSLOCK)
                        {
                            if(!capslock)
                                capslock=true;
                            else if(capslock)
                                capslock=false;
                        }
                        else if(e->key.keysym.sym==SDLK_BACKSPACE)
                           name2=name2.substr(0,name2.length()-1);
                        else if(e->key.keysym.sym==SDLK_RETURN)
                            quit2=true;
                        else
                            ch=e->key.keysym.sym;
                        if((ch>='A' &&ch<='Z')||(ch>='a'&&ch<='z'))
                        {
                            if(capslock)
                                name2+=ch+'A'-'a';
                            else
                                name2+=ch;
                        }

                    }
                }

                if(name2.length()!=0)
                {
                text(m_renderer,850,130,name2.c_str(),48,0,0,0,255);

                }
                if(!type2)
                text(m_renderer,850,130,"PLAYER2",48,0,0,0,255);

                if(type1&&!quit1)
                {
                    char ch='0';
                    if(e->type==SDL_KEYUP)
                    {
                        if(e->key.keysym.sym==SDLK_CAPSLOCK)
                        {
                            if(!capslock)
                                capslock=true;
                            else if(capslock)
                                capslock=false;
                        }
                        else if(e->key.keysym.sym==SDLK_BACKSPACE)
                           name1=name1.substr(0,name1.length()-1);
                        else if(e->key.keysym.sym==SDLK_RETURN)
                            quit1=true;
                        else
                            ch=e->key.keysym.sym;
                        if((ch>='A' &&ch<='Z')||(ch>='a'&&ch<='z'))
                        {
                            if(capslock)
                                name1+=ch+'A'-'a';
                            else
                                name1+=ch;
                        }
                    }
                }

                if(name1.length()!=0)
                {
                text(m_renderer,170,130,name1.c_str(),48,0,0,0,255);

                }
                if(!type1)
                text(m_renderer,170,130,"PLAYER1",48,0,0,0,255);


                  if( xmouse>=100&&xmouse<=200&&ymouse>=500&&ymouse<=600)
                    {
                        setting=true;
                        while(setting)
                        {
                            texture(m_renderer,0,0,"backgroundsetting.jpg",1200,700);
                            //texture(m_renderer,900,100,"sound-on.jpg",80,80);
                            //texture(m_renderer,1000,100,"sound-off.jpg",80,80);
                            texture(m_renderer,50,600,"backbutton1.png",150,80);
                            text(m_renderer,100,50,"CHOOSE YOUR BAll",48,127,200,230,255);
                            texture(m_renderer,100,150,"ball1.png",100,100);
                            texture(m_renderer,100,300,"ball2.png",100,100);
                            texture(m_renderer,100,450,"ball3.png",100,100);
                            xmouse=e->motion.x;
                            ymouse=e->motion.y;
                            SDL_PollEvent(e);
                            if(e->type == SDL_MOUSEBUTTONDOWN ){

                            if( xmouse>=100&&xmouse<=200&&ymouse>=150&&ymouse<=250)
                            {
                                ball1=true;
                                ball2=false;
                                ball3=false;
                            }
                            if( xmouse>=100&&xmouse<=200&&ymouse>=300&&ymouse<=400)
                            {
                                ball2=true;
                                ball1=false;
                                ball3=false;
                            }
                             if( xmouse>=100&&xmouse<=200&&ymouse>=450&&ymouse<=550)
                            {
                                ball3=true;
                                ball2=false;
                                ball1=false;
                            }

                            if( xmouse>=50&&xmouse<=200&&ymouse>=600&&ymouse<=680)
                            {
                                setting=false;
                            }
                            }
                            if(ball1) text(m_renderer,250,150,"BAll 1 IS CHOSEN!",24,255,0,0,255);
                            if(ball2)text(m_renderer,250,300,"BAll 2 IS CHOSEN!",24,255,0,0,255);
                            if(ball3)text(m_renderer,250,450,"BAll 3 IS CHOSEN!",24,255,0,0,255);


                             SDL_RenderPresent( m_renderer );
                             SDL_Delay(10);
                             SDL_RenderClear( m_renderer );

                        }
                    }
                    if( xmouse>=900&&xmouse<=1000&&ymouse>=500&&ymouse<=600)
                    {
                        league=true;
                        while(league)
                        {
                            texture(m_renderer,0,0,"backgroundleague.jpg",1200,700);
                            texture(m_renderer,50,600,"backbutton1.png",150,80);
                            text(m_renderer,100,50,"PLAYER1",48,175,200,230,255);
                            text(m_renderer,800,50,"PLAYER2",48,175,200,230,255);
                           // cout<<"1";
                            string namewin1[1000];int n=0;int yaval=100;
                            ifstream in;
                            in.open("myPlayer1.txt");
                            //cout<<"1";
                            while(!in.eof())
                            {
                            in>>namewin1[n];
                            text(m_renderer,100,yaval,namewin1[n].c_str(),24,175,200,230,255);
                            n++;
                            yaval+=50;
                            }
                            //cout<<"2";

                            string namewin2[10];
                            ifstream inn;int r=0;int ydovom=100;
                            inn.open("myPlayer2.txt");
                            while(!inn.eof())
                            {
                            inn>>namewin2[r];
                            text(m_renderer,800,ydovom,namewin2[r].c_str(),24,175,200,230,255);
                            r++;
                            ydovom+=50;
                            }
                            //cout<<"3";


                            xmouse=e->motion.x;
                            ymouse=e->motion.y;
                            SDL_PollEvent(e);
                            if(e->type == SDL_MOUSEBUTTONDOWN ){
                            if( xmouse>=50&&xmouse<=200&&ymouse>=600&&ymouse<=680)
                            {
                                league=false;
                            }
                            }
                             SDL_RenderPresent( m_renderer );
                             SDL_Delay(10);
                             SDL_RenderClear( m_renderer );
                        }
                    }

                 e->type=NULL;
                 e->key.keysym.sym==NULL;

                        SDL_RenderPresent( m_renderer );
                        SDL_Delay(10);
                        SDL_RenderClear( m_renderer );

            }

    while(play){
            window_color(m_renderer,0,0,0);
            texture(m_renderer,0,100,"back4.jpg",1200,700);
            rect(m_renderer,110,100,300,70,255,255,255,1);
            rect(m_renderer,830,100,300,70,255,255,255,1);
            text(m_renderer,850,110,name2.c_str(),48,0,0,0,255);
            text(m_renderer,130,110,name1.c_str(),48,0,0,0,255);

            SDL_RenderCopy(m_renderer, goal1img, NULL, &goal1);
            SDL_RenderCopy(m_renderer, goal2img, NULL, &goal2);

     SDL_PollEvent(e);
        state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_S])
        {
            if(yball-yplayer1<=60)
                shoot1=false;
            if(yball-yplayer1>60)
                shoot1=true;
        }
        if (state[SDL_SCANCODE_LEFT])
        {
            signvx2=-1;
            if(abs(xplayer1-xplayer2)<=85 && !punch1)
            {
                if(xplayer2>xplayer1)
                {
                    xplayer1-=5;
                    xplayer2+=5;
                }
                else if(xplayer1>=xplayer2)
                {
                     xplayer1+=5;
                     xplayer2-=5;
                }
            }
            if(xplayer2>190 && !punch1)
            {
                run2=true;
                xplayer2-=5;
            }
        }
         if (state[SDL_SCANCODE_A])
        {
            if(abs(xplayer1-xplayer2)<=85 && !punch2)
            {
                if(xplayer2>xplayer1)
                {
                    xplayer1-=5;
                    xplayer2+=5;
                }
                else if(xplayer1>=xplayer2)
                {
                    xplayer1+=5;
                     xplayer2-=5;
                }
            }
            if(xplayer1>190 && !punch2)
            {
                 run1=true;
                xplayer1-=5;
            }
            signvx1=-1;
        }
        if (state[SDL_SCANCODE_D])
        {
            if(abs(xplayer1-xplayer2)<=85 && !punch2)
            {
                if(xplayer2>xplayer1)
                {
                     xplayer1-=5;
                    xplayer2+=5;
                }
                else if(xplayer1>=xplayer2)
                {
                    xplayer1+=5;
                    xplayer2-=5;
                }
            }
            if(xplayer1<960 && !punch2)
            {
                run1=true;
                xplayer1+=5;
            }
            signvx1=1;
        }
         if(state[SDL_SCANCODE_UP])
        {
            if(xplayer2>190 && xplayer2<960)
                jump2=true;
            else
            jump2=false;
        }
        if (state[SDL_SCANCODE_RIGHT])
        {
             if(abs(xplayer1-xplayer2)<=85 && !punch1)
            {
                if(xplayer2>xplayer1)
                {
                     xplayer1-=5;
                     xplayer2+=5;
                }
                else if(xplayer1>=xplayer2)
                {
                    xplayer1+=5;
                    xplayer2-=5;
                }
            }
            if(xplayer2<960 && !punch1)
            {
                run2=true;
                xplayer2+=5;
            }
            signvx2=1;
        }
        if(state[SDL_SCANCODE_P])
        {
            if(powers2==0)
                triplecone2=true;

            else if(powers2==2)
                if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch2=true;

            else if(powers2==1)
                invisible=true;

            else if(powers2==3)///thief
            {
                rand2=rand()%3;
            if(rand2==0)
                triplecone2=true;

            else if(rand2==2)
                if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch2=true;

            else if(rand2==1)
                invisible=true;
            }
        }
        if(state[SDL_SCANCODE_DOWN])
        {
            if(yball-yplayer2<=60)
                shoot2=false;
            if(yball-yplayer2>60)
                shoot2=true;
        }
        if (state[SDL_SCANCODE_W])
        {

            if(xplayer1>190 && xplayer1<960)
                jump1=true;
            else
                jump1=false;

        }
        if(state[SDL_SCANCODE_Q])
        {
            if(powers1==0)
                triplecone1=true;

            else if(powers1==2)
                if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch1=true;

            else if(powers1==1)
                invisible=true;

            else if(powers1==3)
            {
                rand1=rand()%3;
            if(rand1==0)
                triplecone1=true;

            else if(rand1==2)
                if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch1=true;

            else if(rand1==1)
                invisible=true;
            }
        }
        if(state[SDL_SCANCODE_O])
        {
            triplecone2=true;
        }
        if(state[SDL_SCANCODE_I])
        {
            invisible=true;
        }
        if(state[SDL_SCANCODE_U])
        {
            if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch2=true;
        }
        if(state[SDL_SCANCODE_E])
        {
            triplecone1=true;
        }
        if(state[SDL_SCANCODE_R])
        {
            invisible=true;
        }
        if(state[SDL_SCANCODE_T])
        {
            if(xplayer2-xplayer1<90 && xplayer2>xplayer1)
                    punch1=true;
        }




        if(!invisible)
            {
                if(ball2)
                texture(m_renderer,xball,yball,"ball2.png",40,40);
                else if(ball3)
                texture(m_renderer,xball,yball,"ball3.png",40,40);
                else
                texture(m_renderer,xball,yball,"ball1.png",40,40);
            }
        else
        {
            cntinvisible+=0.05;
            if(cntinvisible>=1.6)
            {
                cntinvisible=0;
                invisible=false;
            }
        }


            if(goalplayer1==0)
                texture(m_renderer,500,100,"zero.png",85,125);
            else if(goalplayer1==1)
                texture(m_renderer,500,100,"one.png",85,125);
            else if(goalplayer1==2)
                texture(m_renderer,500,100,"two.png",85,125);
            else if(goalplayer1==3)
                texture(m_renderer,500,100,"three.png",85,125);
            else if(goalplayer1==4)
                texture(m_renderer,500,100,"four.png",85,125);
            else if(goalplayer1==5)
                texture(m_renderer,500,100,"five.png",85,125);

            if(goalplayer2==0)
                texture(m_renderer,620,100,"zero.png",85,125);
            else if(goalplayer2==1)
                texture(m_renderer,620,100,"one.png",85,125);
            else if(goalplayer2==2)
                texture(m_renderer,620,100,"two.png",85,125);
            else if(goalplayer2==3)
                texture(m_renderer,620,100,"three.png",85,125);
            else if(goalplayer2==4)
                texture(m_renderer,620,100,"four.png",85,125);
            else if(goalplayer2==5)
                texture(m_renderer,620,100,"five.png",85,125);



        if(!jump2&&!run2 && !punch1&&!triplecone2)
           {
            texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
           }
        else if(!jump2&&!run2 && !punch1&&triplecone2)
        {
            texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
            texture(m_renderer,xplayer2+20,yplayer2,"head_two1.png",100,100);
            texture(m_renderer,xplayer2+40,yplayer2,"head_two1.png",100,100);
        }

        if(!jump1 &&!run1 && !punch2&&!triplecone1)
        {
            texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
        }
        else if(!jump1 &&!run1 && !punch2&&triplecone1)
        {
            texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
            texture(m_renderer,xplayer1-20,yplayer1,"head_one1.png",100,100);
            texture(m_renderer,xplayer1-40,yplayer1,"head_one1.png",100,100);
        }



        if(!punch2)
        {
            if( run1&& i%2==1 && !triplecone1)
            {
                texture(m_renderer,xplayer1,yplayer1,"head_one2.png",100,100);
            }
            else if( run1&& i%2==1 && triplecone1)
            {
                texture(m_renderer,xplayer1,yplayer1,"head_one2.png",100,100);
                texture(m_renderer,xplayer1-20,yplayer1,"head_one2.png",100,100);
                texture(m_renderer,xplayer1-40,yplayer1,"head_one2.png",100,100);
            }
            else if(run1&& i%2==0 && !triplecone1)
            {
                texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
            }
            else if(run1&& i%2==0 && triplecone1)
            {
                texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
                texture(m_renderer,xplayer1-20,yplayer1,"head_one1.png",100,100);
                texture(m_renderer,xplayer1-40,yplayer1,"head_one1.png",100,100);

            }

            if(jump1)
            {
                yplayer1=((25*cntjump1*cntjump1)-(100*cntjump1))+350;
                if(triplecone1)
                {
                    texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
                    texture(m_renderer,xplayer1-20,yplayer1,"head_one1.png",100,100);
                    texture(m_renderer,xplayer1-40,yplayer1,"head_one1.png",100,100);
                }
                else
                    texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
                xplayer1=2*(vxplayer1*signvx1)+xplayer1;
                if(cntjump1<3)
                {
                    if(xplayer1>900||xplayer1<250)
                    {
                    yplayer1=350;
                    jump1=false;
                    }
                }
                else if(cntjump1>=3)
                {
                    if( xplayer1>965 ||xplayer1<250 )
                    {
                    yplayer1=350;
                    jump1=false;
                    }
                }
                cntjump1+=0.25;
            }

            if(cntjump1>=4)
            {
                cntjump1=0;
                yplayer1=350;
                jump1=false;
            }

        }
        else if(punch2)
        {
            yplayer1=340;
                texture(m_renderer,xplayer1,yplayer1,"head_one1.png",100,100);
                texture(m_renderer,xplayer1+13,yplayer1-40,"questionmark1.png",40,40);
            cntpunch2+=0.2;
            yplayer1=350;
        }
        if(cntpunch2>=16)
            {
                cntpunch2=0;
                punch2=false;
            }

        if(!punch1)
        {
            if( run2&&i%2==1 &&!triplecone2 )
                {
                texture(m_renderer,xplayer2,yplayer2,"head_two2.png",100,100);
                }
            else if( run2&&i%2==1 &&triplecone2 )
            {
                texture(m_renderer,xplayer2,yplayer2,"head_two2.png",100,100);
                texture(m_renderer,xplayer2+20,yplayer2,"head_two2.png",100,100);
                texture(m_renderer,xplayer2+40,yplayer2,"head_two2.png",100,100);
            }
            else if(run2&&i%2==0 && !triplecone2)
                {
                texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
                }
            else if(run2&&i%2==0 && triplecone2)
            {
                texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
                texture(m_renderer,xplayer2+20,yplayer2,"head_two1.png",100,100);
                texture(m_renderer,xplayer2+40,yplayer2,"head_two1.png",100,100);
            }

            if(jump2)
            {
                yplayer2=((25*cntjump2*cntjump2)-(100*cntjump2))+345;
                if(triplecone2)
                {
                    texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
                    texture(m_renderer,xplayer2+20,yplayer2,"head_two1.png",100,100);
                    texture(m_renderer,xplayer2+40,yplayer2,"head_two1.png",100,100);
                }
                else
                    texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
                xplayer2=2.2*(vxplayer2*signvx2)+xplayer2;
                if(xplayer2<250 || xplayer2>965)
                {
                    if(cntjump2<3)
                        yplayer2=345;
                    else if(cntjump2>=3)
                        yplayer2=350;

                    jump2=false;
                }
                cntjump2+=0.25;
            }

            if(cntjump2>=4)
            {
                yplayer2=345;
                cntjump2=0;
                jump2=false;
            }
        }
        else if(punch1)
        {
            yplayer2=345;
                texture(m_renderer,xplayer2,yplayer2,"head_two1.png",100,100);
                texture(m_renderer,xplayer2+17,yplayer2-40,"questionmark1.png",40,40);

            cntpunch1+=0.2;
        }
        if(cntpunch1>=16)
            {
                cntpunch1=0;
                punch1=false;
            }

            if(triplecone2)
            {
                cnttriplecone2+=0.2;
                if(cnttriplecone2>=30)
                {
                cnttriplecone2=0;
                triplecone2=false;
                }
            }

            if(triplecone1)
            {
                cnttriplecone1+=0.2;
                if(cnttriplecone1>=30)
                {
                cnttriplecone1=0;
                triplecone1=false;
                }
            }


        if(xball-xplayer1<=80 && xball-xplayer1>=50)
        {
            if(shoot1)
            {
                if(!run1 && !jump1 && yball>=yplayer1+70 && yball<=yplayer1+120)
                    cases=2;
                else
                    cases=3;
                reflect1=true;
                signvxball=1;
                ytemp=yball;
            }
        }
        if(xball-xplayer2<=43 && xplayer2-xball>=20)
         {
            if(shoot2)
            {
                if(!run2 && !jump2 && yball>=yplayer2+70 && yball<=yplayer2+120)
                    cases=2;
                else
                    cases=3;
                reflect2=true;
                signvxball=-1;
                ytemp=yball;
            }
         }
        if(!reflect1 && !shoot1 && yball<=yplayer1+80 && yball>yplayer1  )
        {

               if(triplecone1 && xball-xplayer1<=75 && xball-xplayer1>=-30)
               {
                if(cases!=0)
                    {
                    if(jump1)
                        xball=xplayer1+90;

                      if(!jump1)
                        xball=xplayer1+80;
                    signvxball*=-1;

                    }
                else
                    xball+=5;
               }

                if(!triplecone1 && xball-xplayer1<=73 && xball-xplayer1>=20)
               {
                if(cases!=0)
                    {

                    if(jump1)
                        xball=xplayer1+90;
                      if(!jump1)
                        xball=xplayer1+80;
                        signvxball*=-1;

                    }
                else
                    xball+=5;
               }
        }
         if(!reflect2 && !shoot2 && yball<=yplayer2+110 && yball>yplayer2 )
        {
            if(triplecone2 && xplayer2-xball<=30 && xplayer2-xball>=-110)
               {
                if(cases!=0)
                    {
                      if (!jump2)
                        xball=xplayer2-40;

                      if(jump2)
                        xball=xplayer2-50;

                        signvxball*=-1;

                    }

                else
                    xball-=5;
               }
                if(!triplecone2 && xplayer2-xball<=30 && xplayer2-xball>=-10 )
               {
                    {

                      if(!jump2)
                        xball=xplayer2-35;
                      if(jump2)
                        xball=xplayer2-50;

                        signvxball*=-1;

                    }
               }
        }
        if(yball-yplayer2>80 && yball-yplayer2<90 && cases==0)
         {
            if( xplayer2-xball<40 && xplayer2-xball>=-120&&triplecone2 )
                xball=xplayer1-5;
            if(xplayer2-xball<40 && xplayer2-xball>=-80&&!triplecone2 )
                xball=xplayer2-5;

        }
        if(yball-yplayer1>80 && yball-yplayer1<90 && cases==0)
         {
            if( xball-xplayer1>80 && xball>xplayer1-40&&triplecone1 )
                xball=xplayer1+5;
            if(xball-xplayer1<85 && xball>=xplayer1&&!triplecone1 )
                xball=xplayer1+5;

        }
        if(!reflect2 && yball<=yplayer2+125 && yball>yplayer1+111)
        {
                signvxball=-1;
                reflect2=true;
                ytemp=yball;
            if( xball>xplayer2 && xball-xplayer2<125&&triplecone2)
                cases=1;
            if ( xball>xplayer2 && xball-xplayer2<80&&!triplecone2 )
                if(yball!=430)
                    cases=1;

        }

        if(!reflect1 && yball<=yplayer1+125 && yball>yplayer1+111)
        {

                signvxball=1;
                reflect1=true;
                 ytemp=yball;
            if(xplayer1>xball && xplayer1-xball<125&&triplecone1 )
                cases=1;
            if ( xplayer1>xball && xplayer1-xball<80&&!triplecone1)
                if(yball<=340)
                cases=1;

        }

        if(cases==3)   //baraye 45e player1&2
        {
            if(zarib>=0.4)
            {
                velocity+=acceleration*t;
                xball+=10*signvxball;
                yball=(0.5*acceleration*t*t+velocity*t)*(zarib*1.8)+ytemp;

                if (yball>=420)
                {

                    yball=420;
                    velocity=-200+(10*t);
                    t=0;
                    zarib*=0.8;
                }
            }
        t+=0.05;
        }

        if(cases==2)   //bara 15 player1&2
        {
            if(zarib>=0.4)
            {
                xball+=8*signvxball;
                yball=(0.5*acceleration*t*t+velocity*t)*(zarib*0.6)+ytemp;
                velocity+=acceleration*t;
                if (yball>=420)
                {
                    velocity=-200+(10*t);
                    t=0;
                    zarib*=0.8;
                    yball=420;
                }
            }
        t+=0.05;
        }

        if(cases==1)    //bara -45e player1&2
        {
            if(zarib>=0.4)
            {
                xball+=10*signvxball;
                yball=(-1*(0.5*acceleration*t*t+velocity*t)*(zarib*1.8))+ytemp;
                velocity+=acceleration*t;
                if (yball>=420)
                {
                    velocity=-200+(10*t);
                    yball=420;
                    t=0;
                    zarib*=0.8;
                }
            }
        t+=0.05;
        }


        if((xball>=80 && xball<=210)||(xball>=970 && xball<=1080))
            {
                if(yball>320 && yball<480)
                {
                celebration=true;
                yball=420;
                cases=0;

                }
                else if(yball<=320 && yball>=480)
                    signvxball*=-1;
            }

            if(t>=3 || zarib<=0.4)
            {
                zarib=1.7;
                velocity=-200;
                cases=0;
                t=0;
            }


            if(xplayer2-xball>25)
                reflect2=false;

            if(xball-xplayer1>100 || (xplayer2-xplayer1<100))
                reflect1=false;


            if(celebration)
            {
                int i;
                    for(i=1 ; i<=16; i++)
                {
                string celebrate="celeb";
                celebrate+=to_string(i);
                celebrate+=".jpg";
                SDL_Delay(100);
                texture(m_renderer,0,0,celebrate,1200,280);

                SDL_RenderPresent( m_renderer );
                }

                if(i>=16)
                {
                    if(xball>=970 && xball<=1080)
                        goalplayer1++;
                    if(xball>=80 && xball<=210)
                        goalplayer2++;
                    celebration=false;
                    i=1;
                    xplayer1=400; xplayer2=750;
                    xball=590; yball=220;
                    start=true;
                }
            }
            if(start)
            {
            yball+=15;
            if(yball>=420)
            {
                start=false;
                yball=420;
            }
            }



            SDL_RenderPresent(m_renderer);
            SDL_Delay(15);
            SDL_RenderClear( m_renderer );
            run2=false;
            run1=false;
            shoot2=false;
            shoot1=false;

            i%=2;
            i++;

        if( (goalplayer1==4 && goalplayer2==4)||(goalplayer1==5) || (goalplayer2==5))
        {
            winner=true;
            play=false;
        }


}


        if(goalplayer1==5)
        {
            texture(m_renderer,300,200,"head_one1.png",200,200);
            text(m_renderer,600,400,"winner:",48,0,0,0,255);
            text(m_renderer,800,400,name1.c_str(),48,0,0,0,255);
            int t=0;
            if(t==0)
            {
            string player1=name1.c_str();
            player1+=":won";
            player1+="(goals=";
            player1+=to_string(goalplayer1);
            player1+=")";
            ofstream out;
            out.open("myPlayer1.txt",ios::app);
            out<<endl;
            out<<player1;


            string player2=name2.c_str();
            player2+=":lost";
            player2+="(goals=";
            player2+=to_string(goalplayer2);
            player2+=")";
            ofstream out2;
            out2.open("myPlayer2.txt",ios::app);
            out2<<endl;
            out2<<player2;
            t++;
            }


        }
        else if(goalplayer2==5)
        {
            texture(m_renderer,890,200,"head_two1.png",200,200);
            text(m_renderer,300,400,"winner:",48,0,0,0,255);
            text(m_renderer,500,400,name2.c_str(),48,0,0,0,255);
            int w=0;
            if(w==0)
            {
            string player1=name1.c_str();
            player1+=":lost";
            player1+="(goals=";
            player1+=to_string(goalplayer1);
            player1+=")";
            ofstream out;
            out.open("myPlayer1.txt",ios::app);
            out<<endl;
            out<<player1;

            string player2=name2.c_str();
            player2+=":won";
            player2+="(goals=";
            player2+=to_string(goalplayer2);
            player2+=")";
            ofstream out2;
            out2.open("myPlayer2.txt",ios::app);
            out2<<endl;
            out2<<player2;
            w++;
            }

        }
        else if(goalplayer1==4 && goalplayer2==4)
        {
            texture(m_renderer,300,200,"head_one1.png",200,200);
            texture(m_renderer,890,200,"head_two1.png",200,200);
            text(m_renderer,400,200,"no winner, no loser",48,0,0,0,255);
            int u=0;
            if(u==0)
            {
            string player1=name1.c_str();
            player1+=":tie";
            player1+="(goals=";
            player1+=to_string(goalplayer1);
            player1+=")";
            ofstream out;
            out.open("myPlayer1.txt",ios::app);
            out<<endl;
            out<<player1;

            string player2=name2.c_str();
            player2+=":tie";
            player2+="(goals=";
            player2+=to_string(goalplayer2);
            player2+=")";
            ofstream out2;
            out2.open("myPlayer2.txt",ios::app);;
            out2<<endl;
            out2<<player2;
            u++;
            }

        }

    while(winner){
        texture(m_renderer,0,0,"backgroundsetting.jpg",1200,700);

        if(goalplayer1==5)
        {
            texture(m_renderer,300,300,"head_one1.png",200,200);
            text(m_renderer,600,400,"winner:",48,0,0,0,255);
            text(m_renderer,800,400,name1.c_str(),48,0,0,0,255);


        }
        else if(goalplayer2==5)
        {
            texture(m_renderer,890,300,"head_two1.png",200,200);
            text(m_renderer,300,400,"winner:",48,0,0,0,255);
            text(m_renderer,500,400,name2.c_str(),48,0,0,0,255);
        }
        else if(goalplayer1==4 && goalplayer2==4)
        {
            texture(m_renderer,300,300,"head_one1.png",200,200);
            texture(m_renderer,890,300,"head_two1.png",200,200);
            text(m_renderer,400,200,"no winner, no loser",48,0,0,0,255);

        }


        SDL_RenderPresent( m_renderer );
        SDL_Delay(10);
        SDL_RenderClear( m_renderer );

    }



    SDL_RenderPresent(m_renderer);
    SDL_Delay(10);
    SDL_RenderClear(m_renderer);
    }

    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;
}
void text(SDL_Renderer *renderer,int x,int y,const char * text,int font_size,int R,int G,int B, int A)
{
    TTF_Init();
SDL_Color text_color = { R, G, B, A};
const char * Font ="font2.ttf";
    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    double angle = 0.0;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(Font, font_size );

    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont,text, text_color );

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
    SDL_FreeSurface( textSurface );
    SDL_Rect renderQuad = { x , y , mWidth, mHeight };
    SDL_RenderCopyEx( renderer, mTexture, clip, &renderQuad, angle, center, flip );
    SDL_DestroyTexture( mTexture );
    //SDL_RenderPresent( renderer );

}
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian)
{

    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;

    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
    //SDL_RenderPresent(Renderer);
}
void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{

    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );

    SDL_RenderClear( Renderer );



    // Show the window

  //SDL_RenderPresent( Renderer );



}
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
            SDL_DestroyTexture(myTexture);
}
