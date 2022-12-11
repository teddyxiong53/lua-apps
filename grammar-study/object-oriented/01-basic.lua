-- 元类
Rectangle = {area =0 , length = 0, breadth = 0} -- breadth是宽度的意思
-- 派生类的方法 new
function Rectangle:new(o, length, breadth)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    self.length = length or 0
    self.breadth = breadth or 0
    self.area = length * breadth
    return o
end
-- 派生类的方法printArea
function Rectangle:printArea()
    print('are is ', self.area)
end

r = Rectangle:new(nil, 10,20)
-- 属性用点号。
print(r.length)
-- 方法用冒号。
r:printArea()
