AVector2D ={x=0,y=0};
AVector2D.__index=AVector2D;
function AVector2D:new(x,y)
        local self = {} ;
        setmetatable(self, Class)
        self.x = x 
        self.y = y
        return self
end

a=AVector2D:new(3,4);
b=AVector2D:new(5,6);

print(a.x);
print(b.y);