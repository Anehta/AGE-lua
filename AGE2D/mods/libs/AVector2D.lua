require("class");

AVector2D = class();

function AVector2D:ctor(x,y)
	self.x = x;
	self.y = y;
	self.type = "AVector2D";
end

function AVector2D:getX()
	return self.x;
end

function AVector2D:getY()
	return self.y;
end