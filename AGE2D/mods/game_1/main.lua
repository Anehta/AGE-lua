package.path = APath("../libs/?.lua");
require("AVector2D");
Anehta(package.path);
v = AVector2D:new(640/2,480);
Anehta("--Vector2D--",v.x,v.y,"---");
ASetDebugEditSize(v.x,v.y);

sprite=ASpriteCreate();
texture=ATextureCreate(APath("/resource/123.jpg"));
ASpriteBindTexture(sprite,texture);
MiaoPaSi("GMP435S");
text=ATextCreate(24,100,100,APath("/resource/font/simplified_chs.ttf"));
audio=AAudioCreate(APath("/resource/music/earth.mp3"));
AAudioPlay(audio);
a=function (a,b,c)
end;
a(3,2,1);

function __on_render()
	ASpriteRender(sprite);
	ASpriteSetPos(sprite,ASpriteGetX(sprite)+0.5,ASpriteGetY(sprite)+0.5);
	ATextDraw(text,100,100,"hello world");
	return 1;
end