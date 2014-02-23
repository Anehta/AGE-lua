require("class");

AVector4D = class();

function AVector4D:ctor(x,y,z,w)
	-- 构造函数
	self.x = x;
	self.y = y;
	self.z = z;
	self.w = w;
end