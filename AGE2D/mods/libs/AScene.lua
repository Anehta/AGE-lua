require("class");

AScene = class();



function AScene:ctor()
	-- body
	self.layerTable = {};
	self.type = "AScene";
end

function AScene:addChild(a)
	if a.type == "ALayer" then
		table.insert(self.layerTable,a);
	else
		Anehta("error argument in AScene:addChild(layer)")
	end
end

function AScene:action()

end

function AScene:render()
	for key,value in pairs(self.layerTable) do
		value:render();
		value:action();
	end
	self.action();
end

__current_scene = AScene:new();

function AScene:active()
	__current_scene = self;
	if __current_scene.type == "AScene" then
		Anehta("object is AScene\n");
	else
		Anehta("this object is not AScene\n");
		Anehta("__current_scene.type == ",__current_scene.type,"\n");
	end
end

function __on_render()
	__current_scene:render();
end