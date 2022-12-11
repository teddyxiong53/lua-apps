--[[
    这个写法，感觉跟C语言的队列写法没有区别。

]]
local LinkQue = {}

function LinkQue:new(o)
    local o = o or {}
    setmetatable(o, self)
    self.__index = self
    o.size = 0
    o.head = {}
    o.tail = {}
    -- 头节点和尾节点一定是有的。插入就是放在尾部节点的前面。
    o.head.__prev = nil
    o.head.__next = o.tail
    o.tail.__next = nil
    o.tail.__prev = o.head
    return o
end

function LinkQue:Push(node)
    if node.__owner then
        return
    end
    -- 插到尾结点的前面
    self.tail.__prev.__next = node
    node.__prev = self.tail.__prev
    self.tail.__prev = node
    node.__next = self.tail
    node.__owner = self
    self.size = self.size + 1
end

-- 拿到最前面的节点
function LinkQue:Front()
    if self.size > 0 then
        return self.head.__next
    else
        return nil
    end
end

-- 移除指定的节点
function LinkQue:Remove(node)
    if node.__owner == self and self.size > 0 then
        node.__prev.__next = node.__next
        node.__next.__prev = node.__prev
        node.__next = nil
        node.__prev = nil
        node.__owner = nil
        self.size = self.size - 1
        return true
    end
    return false
end

-- 从队列的前面拿出来。
function LinkQue:Pop()
    if self.size > 0 then
        local node = self.head.__next
        self.Remove(node)
        return node
    else
        return nil
    end
end

-- 判断队列是否为空
function LinkQue:IsEmpty()
    return self.size == 0
end

-- 拿到队列的长度
function LinkQue:Len()
    return self.size
end

-- 输出对象
return {
    New = function () return LinkQue:new() end
}