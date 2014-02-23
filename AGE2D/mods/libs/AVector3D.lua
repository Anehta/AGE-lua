require("class");

AVector3D = class();

function AVector3D:ctor(x,y,z)
	-- 构造函数
	self.x = x;
	self.y = y;
	self.z = z;
	self.type = "AVector3D";
end
