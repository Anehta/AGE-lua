sprite=ASpriteCreate();
texture=ATextureCreate(APath("AGE2D/resource/123.jpg"));
ASpriteBindTexture(sprite,texture);
MiaoPaSi("GMP435S");
function __on_render()
ASpriteRender(sprite);
	return 1;
end
