function myprint(...)
    for i,v in ipairs{...} do
        print(v)
    end

end
myprint(1,2,3)