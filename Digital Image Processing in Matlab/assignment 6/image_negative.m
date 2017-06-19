function m = image_negative(m)

[row, column] = size(m);

for r = 1:row
    for c = 1:column
        m(r,c) = 255 - m(r,c);
    end
end
end
