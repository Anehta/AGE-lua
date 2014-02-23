require("class");
require("AVector4D");

ASprite = class();

function ASprite:ctor(p_textureid)
	-- 构造函数
	self.texturePoint = p_textureid;
	self.point = ASpriteCreate();
	self.x = 0;
	self.y = 0;
	self.width = 0;
	self.height = 0;
	self.color = AVector4D:new(255,255,255,255);
	self.pivot = AVector2D:new(0,0);
	self.type = "ASprite";
	self.life = true;
	ASpriteBindTexture(self.point,p_textureid);
	Anehta("bind");
end

function ASprite:setSize(width,height)
	ASpriteSetSize(width,height);
end

function ASprite:setColor(r,g,b,a)
	color.x = r;
	color.y = g;
	color.z = b;
	color.w = a;
	ASpriteColor(r,g,b,a);
end

function ASprite:destroy()
	self.life = false;
end

function ASprite:action()
	
end

--成员变量全开放的，下面的东西没必要写
--[[
function ASprite:setColorV(vector)
	self.color = a;
end

function ASprite:setColor(r,g,b,a)
	slef.color = AVector4D:new(r,g,b,a);
end

function ASprite:setPivotV(vector)
	slef.pivot = AVector2D:new(vector.x,vector.y);
end

function ASprite:setPivot(x,y)
	self.pivot = AVector2D:new(x,y);
end

function ASprite:setX(x)
	self.x = x;
	ASpriteSetPos(self.x,self.y);
end

function ASprite:setY(y)
	self.y = y;
	ASpriteSetPos(self.x,self.y);
end

function ASprite:setPos(a)
	self.x,self.y = a.x,a.y;
	ASpriteSetPos(self.x,self.y);
end
]]