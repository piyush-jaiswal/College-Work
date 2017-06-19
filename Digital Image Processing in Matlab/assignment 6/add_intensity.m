function m = add_intensity(m)

[row, column] = size(m);

for r = 1:row
    for c = 1:column
        m(row,column) = mod(m(row, column) + 120, 255);
    end
end
end