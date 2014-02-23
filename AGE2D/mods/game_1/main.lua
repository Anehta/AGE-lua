package.path = APath("../libs/?.lua");
require("AFuck");
require("AVector2D");
require("ASprite");

--[[初始化]]--
Anehta(package.path);
vector = class(AVector2D);

ASetDebugEditSize(640/2,480);
sprite=ASpriteCreate();
texture=ATextureCreate(APath("/resource/123.jpg"));
ASpriteBindTexture(sprite,texture);
-- MiaoPaSi("GMP435S");
text=ATextCreate(24,100,100,APath("/resource/font/simplified_chs.ttf"));
audio=AAudioCreate(APath("/resource/music/earth.mp3"));
-- AAudioPlay(audio);
--[[--------]]

a=function (a,b,c)
end;
a(3,2,1);

fuck = ASprite.new(10);
Anehta("sprite",fuck.textureID);
test_vector2d = AVector2D.new(100,200);
Anehta(test_vector2d:getX());
ffff = 0;
function __on_render()
	ffff = ffff+1;
	ASpriteRender(sprite);
	ASpriteSetPos(sprite,ASpriteGetX(sprite)+0.5,ASpriteGetY(sprite)+0.5);
	ATextDraw(text,100,100);
	ATextDraw(text,ffff,ffff,"fuck you");
	return 1;
end
