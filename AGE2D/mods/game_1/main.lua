package.path = APath("../libs/?.lua");
require("AFuck");
require("AVector2D");
require("ASprite");
require("AVector3D");
require("AScene");
require("ASprite");
require("ALayer");

text=ATextCreate(24,100,100,APath("/resource/font/simplified_chs.ttf")); 	--��������

texture = ATextureCreate(APath("/resource/123.jpg"));
texture2 = ATextureCreate(APath("/resource/image/menu_earth.png"));

layer = ALayer.new();		--�ǵ�һ��Ҫ��Alayer.new������Alayer:new��
sprite = ASprite.new(texture);--ͬ��
sprite2 = ASprite.new(texture2);--ͬ��
scene = AScene.new();

sprite2.action = function ()
	-- body
	sprite2.x = sprite2.y-1;
	sprite2.y = sprite2.y-1;
end

layer.action = function ()	--��дlayer��action�����൱��c++�е���д�麯��,�����ô��ǲ��ü̳У�ֱ�Ӹı���ŵ����þͿ����ˡ�
	sprite.x = sprite.x+1;	
	sprite.y = sprite.x+1;
end


layer:addChild(sprite);
layer:addChild(sprite2);
scene:addChild(layer);

scene:active();
