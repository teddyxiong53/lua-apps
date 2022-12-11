-- meta class
Shape = {area = 0}

-- base class method new
function Shape:new(o, side)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    side = side or 0
    self.area = side *side
    return o
end

function Shape:printArea()
    print('area is', self.area)
end
-- 测试 Shape
local s = Shape:new(nil, 10)
s:printArea()

-- 下面让Square继承Shape类。
Square = Shape:new()
function Square:new(o, side)
    o = o or Shape:new(o, side)
    setmetatable(o, self)
    self.__index = self
    return o
end

function Square:printArea()
    print('square area is', self.area)
end
sq = Square:new(nil, 20)
sq:printArea()

Rectangle = Shape:new()

function Rectangle:new(o, length, breadth)
    o = o or Shape:new(o)
    setmetatable(o, self)
    self.__index = self
    self.area = length * breadth
    return o
end

function Rectangle:printArea()
    print('rect area is ', self.area)
end
r = Rectangle:new(nil, 3,4)
r:printArea()

