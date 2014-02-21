ASetWidgetSize(640,480);
Anehta("hehe");
AGame("game_1");
a = 0;

function fuck(x)
	if x > 10 then 
		return;
	end
	x = x+1;
	Anehta(x);
	fuck(x);
end

hehe = 0;
fuck(hehe);