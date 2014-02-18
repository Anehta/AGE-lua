sprite=ASpriteCreate();
texture=ATextureCreate(":/image/menu_choose.png");
ASpriteBindTexture(sprite,texture);
tzw("我了个草",true,nil);
function __on_render()
ASpriteRender(sprite);
	return 1
end