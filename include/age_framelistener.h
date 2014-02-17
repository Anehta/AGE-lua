#ifndef AFRAMELISTENER_H
#define AFRAMELISTENER_H


namespace AGE2D {
class AFrameListener
{
public:
	 AFrameListener();
	virtual void beforeFrameRender();
	virtual void afterFrameRender();
};

}

#endif // AFRAMELISTENER_H
