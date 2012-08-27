#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
//#include <time.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

  private:
	float brightness_Red;
	float brightness_Blue;
	float brightness_Green;

	bool stage_1;
	bool stage_2;
	bool stage_3;
};

void CatPictureApp::setup()
{
	brightness_Red = 1.0f;
	brightness_Blue = 1.0f;
	brightness_Green = 0.0f;
	stage_1 = true;
	stage_2 = false;
	stage_3 = false;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
	if (stage_1 == true)
		brightness_Red = 0.5;
	if (stage_2 == true)
		brightness_Green = 0.5;
	if (stage_3 == true)
		brightness_Blue = 0.5;
}

void CatPictureApp::update()
{
	if (stage_1 == true)	{
		brightness_Green = brightness_Green + 0.005;
		brightness_Blue = brightness_Blue - 0.005;
		if (brightness_Blue < 0.0f)	{
			brightness_Blue = 0.0;
			brightness_Green = 1.0;
			stage_1 = false;
			stage_2 = true;
		}
	}
	if (stage_2 == true)	{
		brightness_Red = brightness_Red - 0.005;
		brightness_Blue = brightness_Blue + 0.005;
		if (brightness_Blue > 1.0f)	{
			brightness_Blue = 1.0;
			brightness_Red = 0.0;
			stage_2 = false;
			stage_3 = true;
		}
	}
	if (stage_3 == true)	{
		brightness_Red = brightness_Red + 0.005;
		brightness_Green = brightness_Green - 0.005;
		if (brightness_Green < 1.0f)	{
			brightness_Green = 0.0;
			brightness_Red = 1.0;
			stage_3 = false;
			stage_1 = true;
		}
	}
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( brightness_Red, brightness_Green, brightness_Blue ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
