package.path = APath("../libs/?.lua");
require("AFuck");
require("AVector2D");
require("ASprite");
require("AVector3D");
require("AScene");
require("ASprite");
require("ALayer");

text=ATextCreate(24,100,100,APath("/resource/font/simplified_chs.ttf")); 	--创建字体

texture = ATextureCreate(APath("/resource/123.jpg"));
texture2 = ATextureCreate(APath("/resource/image/menu_earth.png"));

layer = ALayer.new();		--记得一定要是Alayer.new而不是Alayer:new，
sprite = ASprite.new(texture);--同上
sprite2 = ASprite.new(texture2);--同上
scene = AScene.new();

sprite2.action = function ()
	-- body
	sprite2.x = sprite2.y-1;
	sprite2.y = sprite2.y-1;
end

layer.action = function ()	--重写layer的action函数相当于c++中的重写虚函数,不过好处是不用继承，直接改变符号的引用就可以了。
	sprite.x = sprite.x+1;	
	sprite.y = sprite.x+1;
end


layer:addChild(sprite);
layer:addChild(sprite2);
scene:addChild(layer);

scene:active();
