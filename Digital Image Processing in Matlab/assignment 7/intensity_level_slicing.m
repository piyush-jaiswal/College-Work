function m = intensity_level_slicing(r1, r2, factor, m)

[row, column] = size(m);

for r = 1 : row
    for c = 1 : column
        if m(r,c) >= r1 && m(r,c) <= r2
            m(r,c) = mod(m(r,c) + factor, 255);
        end
    end
end
end