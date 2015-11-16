#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofTexture.h"
#include "ofxOpenCv.h"
#include "cv.h"
#include "ofxVideoRecorder.h"
class ofApp : public ofBaseApp{

	public:
	
	
public:
	
	//----------------------------------------
	/* standard openFrameworks app stuff */
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	// New for OF0.9:
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//----------------------------------------
	/* Panoramic unwarp stuff */
	
	ofVideoPlayer player;
	ofxXmlSettings XML;

	int	currentCodecId;
	string outputFileName;
	char *handyString;
	
	void computePanoramaProperties();
	void computeInversePolarTransform();
	
	void drawTexturedCylinder();
	void drawPlayer();
	void drawUnwarpedVideo();
	
	bool testMouseInPlayer();
	bool bMousePressed;
	bool bMousePressedInPlayer;
	bool bMousepressedInUnwarped;
	bool bAngularOffsetChanged;
	bool bPlayerPaused;
	bool bCenterChanged;
	bool bSavingOutVideo;
	bool bSaveAudioToo;
	int  nWrittenFrames;
	int  codecQuality;
	
	ofImage unwarpedImage;
	ofxCvColorImage	warpedImageOpenCV;
	ofxCvColorImage unwarpedImageOpenCV;
	ofxCvFloatImage srcxArrayOpenCV;
	ofxCvFloatImage srcyArrayOpenCV;
    
    ofxVideoRecorder recorder;
	
	unsigned char *warpedPixels;
	unsigned char *unwarpedPixels;
	
	int   warpedW;
	int   warpedH;
	float unwarpedW;
	float unwarpedH;
	float warpedCx;
	float warpedCy;
	float savedWarpedCx;
	float savedWarpedCy;
	float savedAngularOffset;
	float angularOffset;
	
	float maxR;
	float minR;
	float maxR_factor;
	float minR_factor;
	int   interpMethod;
	float playerScaleFactor;
	
	unsigned char *blackColor;
	CvScalar	blackOpenCV;
	IplImage	*warpedIplImage;
	IplImage	*unwarpedIplImage;
	
	float *xocvdata;
	float *yocvdata;
	
	float yWarpA; // for parabolic fit for Y unwarping
	float yWarpB;
	float yWarpC;
	
	//-----------------------------------
	/* For the texture-mapped cylinder */
	ofTexture unwarpedTexture;
	int   cylinderRes;
	float *cylinderX;
	float *cylinderY;
	float cylinderWedgeAngle;
	float blurredMouseX;
	float blurredMouseY;

		
};
