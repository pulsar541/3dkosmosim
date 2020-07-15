#ifndef _building_h_ 
#define _building_h_ 
#include "ufo.h" 
class Tower 
{ 
    public : 
    bool isBuild; 
    double x,y,z; 
    Tower() 
    { 
        isBuild = false; 
    } 
    
    void SetPos(double x,double y,double z) 
    { 
        this -> x = x; 
        this -> y = y; 
        this -> z = z; 
    } 
    
    void Show() 
    { 
        
        if ( isBuild) 
        { 
            glBindTexture(GL_TEXTURE_2D,texture[0]); 
            glPushMatrix(); 
                glColor3f(0.5,0.5,0.5); 
                glTranslated ( x,y,z); 
                glEnable(GL_LIGHTING); 
                glDisable(GL_CULL_FACE); 
                glutSolidCone(2,10,10,10); 
                double c = rasst(x,y,z,mmm[12],mmm[13],mmm[14]); 
                double a = mmm[14] - z; 
                double ugol_1 = ugol(mmm[12],mmm[13],x,y); 
                double ugol_2 = asin(a / c) * _180oP; 
                glRotatef(ugol_1,0,0,1); 
                glRotatef(ugol_2 - 90,0,1,0); 
                glutSolidCone(2,10,10,10); 
            glPopMatrix(); 
        } 
    } 
}; 




int ass[200]=
{
	TYDIRIUM,  50, 
	TIEFIGHTER,30
};

class ZAVOD 
{ 
    public : 
    bool isBuild; 
    double x,y,z; 
    double dx,dy,dz; 
    int counter; 
    int count; 
    DWORD starttime,time; 
 
    bool building; 
    bool borning; 
    int k;
    int k2;
	int numList;
		
    ZAVOD() 
    { 
        RESOURCES = 1000; 
        starttime = timeGetTime(); 
        isBuild = false; 
        counter = 0; 
        building = false; 
        borning = false; 
        k = 2; 
    } 
    
 /*   void SetCount(int count) 
    { 
        building = true; 
		

        this -> count = count; 
        this -> counter = count; 
    } 

*/
    void BeginBuildModel(int numList) 
    { 
        building = true;	
		this->numList=numList;
		
		for(int i=0;i<100 && ass[i]!=numList;i+=2);


		count = ass[i+1];
/*
		switch (numList)
		{
			case TYDIRIUM:		count  = 50; 
				break;
			case TIEFIGHTER:	count  = 30; 
				break;
		
		}
*/


        this -> counter =  this -> count; 
    } 
    

    void Calc() 
    { 
        time = timeGetTime () - starttime; 
        
        if ( time > 100) 
        { 
            starttime += time; 
            
            if ( counter > 0) 
            { 
                counter --; 
                RESOURCES --; 
                
                if ( counter == 1) 
                { 
                    
                    switch ( numList) 
                    { 
                        case TYDIRIUM : 
                        ufo[k] -> Born(TYDIRIUM,true); 
                        ufo[k] -> SetPos(x,y,z); 
                        ufo[k] -> SetDelta(body[1].dx,body[1].dy,body[1].dz);

                        
                        break; 
                        case TIEFIGHTER : 
                        ufo[k] -> Born(TIEFIGHTER,true); 
                        ufo[k] -> SetPos(x,y,z); 
                        ufo[k] -> SetDelta(body[1].dx,body[1].dy,body[1].dz);                     

                        break; 
 
                    }
					k ++; 
                    if ( k > 100) k = 0; 
                    building = false; 
                } 
            } 
        } 
    } 
    
    void SetPos(double x,double y,double z) 
    { 
        this -> x = x; 
        this -> y = y; 
        this -> z = z; 
    } 
    
    void Show() 
    { 
        
        if ( isBuild) 
        { 
			glColor3f(1,1,1); 
            glDisable ( GL_LIGHTING); 

            int twx = GetPos(GETX, x, y, z); 
            int twy = GetPos(GETY, x, y, z); 
			
			if(mapmode)
				fontSmall.glDrawText(SSY,twx, twy ,"База"); 
            
            if ( simple_rasst(x,y,z,mmm[12],mmm[13],mmm[14],20)) 
            { 

                
                if ( ! building) 
                { 
                    font.glDrawText(SSY,twx, twy - 90,"ПОСТРОИТЬ"); 
                    font.glDrawText(SSY,twx, twy - 60,"[1] - Сборщик ресурсов "); 
                    font.glDrawText(SSY,twx, twy - 30,"[2] - Истребитель "); 
                } 

                glColor3f(0,0,1); 
            } 
            else 
            { 
             
                glColor3f(0.5,0.5,0.5); 
            } 
            
            if ( simple_rasst(x,y,z,mmm[12],mmm[13],mmm[14],50) && building) 
            { 
                glColor3f(1,1,1); 
                font.glDrawText(SSY,twx,SSY - twy,"ПОСТРОЙКА"); 
                font.glDrawText(SSY,twx,SSY - twy + 30,"РЕСУРСЫ %d", RESOURCES); 
            } 
            
            if ( building) 
            { 
                glColor3f(1,0,0); 
            } 
			
			
			glEnable ( GL_LIGHTING); 
            ///////////////////////////////// 
            glPushMatrix(); 
                glTranslated ( x,y,z); 
                glEnable(GL_LIGHTING); 
				glEnable(GL_BLEND); 
                glDisable(GL_CULL_FACE); 
                glutSolidTeapot(10); 
            glPopMatrix(); 
        } 
    } 
}
; 
#endif 
 