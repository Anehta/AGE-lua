require("class");
require("AVector4D");

ASprite = class();

function ASprite:ctor(x)
	-- 构造函数
	self.textureID = x;
	self.x = 0;
	self.y = 0;
	self.color = AVector4D:new(255,255,255,255);
	self.pivot = AVector2D:new(0,0);
end

