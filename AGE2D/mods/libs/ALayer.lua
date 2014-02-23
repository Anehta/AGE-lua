require("class");

ALayer = class();

function ALayer:ctor()
	-- body
	self.spriteTable = {};
	self.type = "ALayer";
end

function ALayer:addChild(a)
	if a.type == "ASprite" then
		table.insert(self.spriteTable,a);
	else 
		Anehta("error argument in ALayer:addChild(layer)");
	end
end

function ALayer:render()
	for key,value in ipairs(self.spriteTable) do
		value:action();
		ASpriteSetPos(value.point,value.x,value.y);
		ASpriteRender(value.point);
	end
end




