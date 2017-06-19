function m = convert_to_binary(m)

[row, column] = size(m);
for c = 1:column
    for r = 1:row
        
        if m(r,c) <= 35
            m(r,c) = 0;
        else
            m(r,c) = 255;
        end
    end
end
